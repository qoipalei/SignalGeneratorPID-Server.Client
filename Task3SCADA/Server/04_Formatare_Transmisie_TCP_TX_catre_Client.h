//######################################################################################
//#####   Functie de Formatare Pachet de date pentru TX-transmisie catre Client  #######
//#####          + Transmisia efectiva catre Client 						############
//######################################################################################
//int CVICALLBACK transmisie_catre_client (int panelHandle, int controlID, int event,
//							void *callbackData, int eventData1, int eventData2)


int transmisie_catre_client ()
{   
	char transmitBuf[512] = {0};
	char buffsend1[512];

//	switch (event)
//		{
//		case EVENT_COMMIT:
			GetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, &server_Refk);
				GetCtrlVal (g_hmainPanel, MAINPNL_TE, &server_Te); 
					GetCtrlVal (g_hmainPanel, MAINPNL_AUTOMAT_MANUAL, &var_A_M);
			
		//Pachetul de date catre Client
		
		
			Fmt (buffsend1, "%s<%f[w10]", var_A_M);
			strcat (buffsend1," ");
			strcpy(transmitBuf,buffsend1);
			
			Fmt (buffsend1, "%s<%f[w10]", server_Te);
			strcat (buffsend1," ");
			strcat(transmitBuf,buffsend1);
			
			Fmt (buffsend1, "%s<%f[w10]", server_Refk);
			strcat (buffsend1," ");
			strcat(transmitBuf,buffsend1);
			
			/* ============= TRANSMITE IESIREA TRADUCTORULUI ============= */

			Fmt (buffsend1, "%s<%f[w10]", yTRk1);
			strcat (buffsend1," ");
			strcat(transmitBuf,buffsend1);
			
			//GetCtrlVal (panelHandle, MAINPNL_STRING, transmitBuf);
			//strcat (transmitBuf, "\n");
			SetCtrlVal (g_hmainPanel, MAINPNL_TRANSMIT, transmitBuf);
			//SetCtrlVal (panelHandle, MAINPNL_STRING, "");
			if (ServerTCPWrite (g_hconversation, transmitBuf, strlen (transmitBuf), 1000) < 0)
				SetCtrlVal (g_hmainPanel, MAINPNL_TRANSMIT,
							"Transmit Error\n");
//			break;
//		}
	return 0;
}
