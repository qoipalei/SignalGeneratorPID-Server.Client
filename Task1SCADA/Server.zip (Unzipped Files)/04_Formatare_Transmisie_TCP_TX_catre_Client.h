//######################################################################################
//#####   Functie de Formatare Pachet de date pentru TX-transmisie catre Client  #######
//#####          + Transmisia efectiva catre Client 						############
//######################################################################################
int CVICALLBACK transmisie_catre_client (int panelHandle, int controlID, int event,
							void *callbackData, int eventData1, int eventData2)
{   
	char transmitBuf[512] = {0};
	char buffsend1[512];

	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, MAINPNL_REFERINTA, &server_Refk);
			GetCtrlVal (panelHandle, MAINPNL_TE, &server_Te); 
			
		//Pachetul de date catre Client
			Fmt (buffsend1, "%s<%f[w10]", server_Refk);
				strcat (buffsend1," ");
					strcpy(transmitBuf,buffsend1);
			Fmt (buffsend1, "%s<%f[w10]", server_Te);
				strcat (buffsend1," ");
					strcat(transmitBuf,buffsend1);
			
			
			//GetCtrlVal (panelHandle, MAINPNL_STRING, transmitBuf);
			//strcat (transmitBuf, "\n");
			SetCtrlVal (panelHandle, MAINPNL_TRANSMIT, transmitBuf);
			//SetCtrlVal (panelHandle, MAINPNL_STRING, "");
			if (ServerTCPWrite (g_hconversation, transmitBuf, strlen (transmitBuf), 1000) < 0)
				SetCtrlVal (panelHandle, MAINPNL_TRANSMIT,
							"Transmit Error\n");
			break;
		}
	return 0;
}
