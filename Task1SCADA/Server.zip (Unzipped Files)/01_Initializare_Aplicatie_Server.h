//######################################################################################
//#############    BUTON    Start TIMER >>>INITIALIZARE APLICATIE SERVER   #############
//######################################################################################
int CVICALLBACK Start_Aplicatie (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{   double	Te;
	switch (event)
	{
		case EVENT_COMMIT:
			   //Perioada de esantionare setat numai la Server
				Te=0.2;
			
			//Setare si Pornire timer esantionare Server
				SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_SERVER, ATTR_INTERVAL,Te);// Seteaza Timer 
					SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_SERVER, ATTR_ENABLED, 1); 
			break;
	}
	return 0;
}
