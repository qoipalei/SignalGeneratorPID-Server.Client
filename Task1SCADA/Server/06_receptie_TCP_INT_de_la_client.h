/*---------------------------------------------------------------------------*/
/* This is the TCP server's TCP callback.  This function will receive event  */
/* notification, similar to a UI callback, whenever a TCP event occurs.      */
/* We'll respond to CONNECT and DISCONNECT messages and indicate to the user */
/* when a client connects to or disconnects from us.  when we have a client  */
/* connected, we'll respond to the DATAREADY event and read in the available */
/* data from the client and display it.                                      */
/*---------------------------------------------------------------------------*/
//######################################################################################
//#############    Functie de comunicatie pe Intreruperi cu Aplicatia Client ###########
//######################################################################################
int CVICALLBACK ServerTCP_INT_Comunicatie (unsigned handle, int event, int error,
							 void *callbackData)
{
	char receiveBuf[256] = {0};
	ssize_t dataSize        = sizeof (receiveBuf) - 1;
	char addrBuf[31];

	switch (event)
		{
		case TCP_CONNECT:
			if (g_hconversation)
				{
				/* We already have one client, don't accept another... */
				tcpChk (GetTCPPeerAddr (handle, addrBuf, 31));
				sprintf (receiveBuf, "-- Refusing conection request from "
									 "%s --\n", addrBuf); 
				SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, receiveBuf);
				tcpChk (DisconnectTCPClient (handle));
				}
			else
				{
				/* Handle this new client connection */
				g_hconversation = handle;
					SetCtrlVal (g_hmainPanel, MAINPNL_CONNECTED, 1);
				tcpChk (GetTCPPeerAddr (g_hconversation, addrBuf, 31));
					SetCtrlVal (g_hmainPanel, MAINPNL_CLIENT_IP, addrBuf);
				tcpChk (GetTCPPeerName (g_hconversation, receiveBuf, 256));
					SetCtrlVal (g_hmainPanel, MAINPNL_CLIENT_NAME, receiveBuf);
				sprintf (receiveBuf, "-- New connection from %s --\n",
						 addrBuf); 
				SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, receiveBuf);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_STRING, ATTR_DIMMED,
								  0);
				
				/* Set the disconect mode so we do not need to terminate */
				/* connections ourselves. */
				tcpChk (SetTCPDisconnectMode (g_hconversation, 
											  TCP_DISCONNECT_AUTO));
				}
			break;
		case TCP_DATAREADY:
			//***************************aici incepe receptia de la client**********	
			//se primesc informatii de la client pe intrerupere TCP
				receptie_de_la_client(receiveBuf,dataSize);
			///******************END_aici se termina receptia de la client**********
			break;
		case TCP_DISCONNECT:
			if (handle == g_hconversation)
				{
				/* The client we were talking to has disconnected... */
				SetCtrlVal (g_hmainPanel, MAINPNL_CONNECTED, 0);
					g_hconversation = 0;
				SetCtrlVal (g_hmainPanel, MAINPNL_CLIENT_IP, "");
				SetCtrlVal (g_hmainPanel, MAINPNL_CLIENT_NAME, "");
				SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE,
							"-- Client disconnected --\n");
				SetCtrlAttribute (g_hmainPanel, MAINPNL_STRING, ATTR_DIMMED,
								  1);
				
				/* Note that we do not need to do any more because we set the*/
				/* disconnect mode to AUTO. */
				}
			break;
	}
	
Done:    
	return 0;
}
