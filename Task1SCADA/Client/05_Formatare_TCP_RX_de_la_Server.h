int receptie_de_la_server(char receiveBuf[256],int  dataSize )
{
	if ((dataSize = ClientTCPRead (g_hconversation, receiveBuf,dataSize, 10))< 0)
       { SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, "Receive Error\n"); }
    else
    {
      	receiveBuf[dataSize] = '\0';
		ResetTextBox (g_hmainPanel, MAINPNL_RECEIVE, "");
            SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, receiveBuf);
		//Extragere Date din pachetul receptionat
		//selectare din receivebuf>>valoare data nr 1 
			Scan (&receiveBuf[0], "%s>%f[w10]", &client_Refk);
        //selectare din receivebuf>>valoare data nr 2    	
            Scan (&receiveBuf[11], "%s>%f[w10]", &client_Te);
				
				SetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, client_Refk);  	
				SetCtrlVal (g_hmainPanel, MAINPNL_TE, client_Te); 
			
	}

 
	return 0;
}
