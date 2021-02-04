/*---------------------------------------------------------------------------*/
/* This is the TCP client's TCP callback.  This function will receive event  */
/* notification, similar to a UI callback, whenever a TCP event occurs.      */
/* We'll respond to the DATAREADY event and read in the available data from  */
/* the server and display it.  We'll also respond to DISCONNECT events, and  */
/* tell the user when the server disconnects us.                             */
/*---------------------------------------------------------------------------*/
//######################################################################################
//#############    Functie de comunicatie pe Intreruperi cu Aplicatia Server ###########
//######################################################################################
int CVICALLBACK ClientTCP_INT_Comunicatie (unsigned handle, int event, int error,
                             void *callbackData)
{
    char receiveBuf[256] = {0};
    ssize_t dataSize         = sizeof (receiveBuf) - 1;

    switch (event)
        {
        case TCP_DATAREADY:
			//***************************aici incepe receptia de la server**********	
			//se primesc informatii de la server pe intrerupere TCP
				receptie_de_la_server(receiveBuf, dataSize );
			///******************END_aici se termina receptia de la server**********
            break;
        case TCP_DISCONNECT:
            MessagePopup ("TCP Client", "Server has closed connection!");
            SetCtrlVal (g_hmainPanel, MAINPNL_CONNECTED, 0);
            g_connected = 0;
            MainPanelCB (0, EVENT_CLOSE, 0, 0, 0);
            break;
    }
    return 0;
}
