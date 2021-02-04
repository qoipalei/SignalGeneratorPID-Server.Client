//######################################################################################
//#############    BUTON    Start TIMER >>>INITIALIZARE APLICATIE SERVER   #############
//######################################################################################
int CVICALLBACK Start_Aplicatie (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{   
	switch (event)
	{
		case EVENT_COMMIT:
		   	//Preluare Regim de lucru si Te la Pornirea aplicatiei
			GetCtrlVal (g_hmainPanel, MAINPNL_TE, &server_Te); 
		    GetCtrlVal (g_hmainPanel, MAINPNL_AUTOMAT_MANUAL, &var_A_M); 
			
			//Dezactiveaza Butonul START APLICATIE
			SetCtrlAttribute (g_hmainPanel,MAINPNL_START_APLICATIE, ATTR_DIMMED,1); 
			
			
			//Setare si Pornire timer esantionare Server
			SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_SERVER, ATTR_INTERVAL,server_Te);// Seteaza Timer 
			SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_SERVER, ATTR_ENABLED, 1); 
			
			ServerPornit = 1;
			break;
	}
	return 0;
}
