//######################################################################################
//#############    Functie stergerea casetei de mesaje primite de la Server ############
//######################################################################################
int CVICALLBACK ClearScreenCB (int panel, int control, int event,
                               void *callbackData, int eventData1,
                               int eventData2)
{
    if (event == EVENT_COMMIT)
        ResetTextBox (panel, MAINPNL_RECEIVE, "");
    return 0;
}

//######################################################################################
//#############    Functie de oprire Server din Fereastra Windows     ##############
//######################################################################################
int CVICALLBACK MainPanelCB (int panel, int event, void *callbackData,
                             int eventData1, int eventData2)
{
    if (event == EVENT_CLOSE)
        QuitUserInterface (0);
    return 0;
}
//######################################################################################
//#############    Functie de oprire Server din Butonul Stop      ##############
//######################################################################################
int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);  
			break;
	}
	return 0;
}

//######################################################################################
//#############    Functie de tratare mesaj EROARE la pornire Client      ##############
//######################################################################################
static void ReportTCPError(void)
{
	if (g_TCPError < 0)
		{
		char	messageBuffer[1024];
		sprintf(messageBuffer, 
			"TCP library error message: %s\nSystem error message: %s", 
			GetTCPErrorString (g_TCPError), GetTCPSystemErrorString());
		MessagePopup ("Error", messageBuffer);
		g_TCPError = 0;
		}
}
int CVICALLBACK online (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
				// Get the regulator values
				GetCtrlVal(panel, MAINPNL_KR, &Kr);
				GetCtrlVal(panel, MAINPNL_TI, &Ti);
				GetCtrlVal(panel, MAINPNL_TD, &Td);
		alpha = 0.1;
	p0=Kr*((4/(client_Te*client_Te))*(alpha*Td*Ti+Ti*Td) + (2/client_Te)*(Ti+alpha*Td) + 1);
	p1=Kr*(-(8/(client_Te*client_Te))*(alpha* Td*Ti+Td*Ti)+2);
	p2=Kr*((4/(client_Te*client_Te))*(alpha*Td*Ti+Ti*Td) - (2/client_Te)*(Ti+alpha*Td) + 1); 
			
	q0=(4/(client_Te*client_Te))* Ti*alpha*Td + (2/client_Te)*Ti;
	q1=-(8/(client_Te*client_Te))* Ti*alpha*Td;
	q2=(4/(client_Te*client_Te))* Ti*alpha*Td - (2/client_Te)*Ti; 
	
	a1=q1/q0, a2=q2/q0;
	b0=p0/q0, b1=p1/q0, b2=p2/q0; 
	
			break;
	}
	return 0;
}

