//######################################################################################
//#####   Functie de Formatare Pachet de date pentru TX-transmisie catre Server  #######
//#####          + Transmisia efectiva catre Server						    ############
//######################################################################################
//int CVICALLBACK transmisie_catre_server (int panelHandle, int controlID, int event,
//                            void *callbackData, int eventData1, int eventData2)



int transmisie_catre_server ()
{
    char    transmitBuf[512] = {0};
	char buffsend1[512]; 
	
	//Pachetul de date catre Server
	Fmt (buffsend1, "%s<%f[w10]", client_Refk);
	strcat (buffsend1," ");
	strcpy(transmitBuf,buffsend1);
			
	Fmt (buffsend1, "%s<%f[w10]", client_Te);
	strcat (buffsend1," ");
	strcat(transmitBuf,buffsend1);
			
	Fmt (buffsend1, "%s<%f[w10]", yPIDk);
	strcat (buffsend1," ");
	strcat(transmitBuf,buffsend1);
	
	//DebugServerSend();
	
	//GetCtrlVal (panelHandle, MAINPNL_STRING, transmitBuf);
	//strcat (transmitBuf, "\n");
	SetCtrlVal (g_hmainPanel, MAINPNL_TRANSMIT, transmitBuf);
	//SetCtrlVal (panelHandle, MAINPNL_STRING, "");

	if (ClientTCPWrite (g_hconversation, transmitBuf, strlen (transmitBuf), 1000) < 0)
        SetCtrlVal (g_hmainPanel, MAINPNL_TRANSMIT,"Transmit Error\n");

    return 0;
}
