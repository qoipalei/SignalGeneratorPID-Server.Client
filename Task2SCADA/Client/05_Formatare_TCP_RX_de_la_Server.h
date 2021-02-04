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
			Scan (&receiveBuf[0], "%s>%f[w10]", &var_A_M);
        //selectare din receivebuf>>valoare data nr 2    	
            Scan (&receiveBuf[11], "%s>%f[w10]", &client_Te);
		//selectare din receivebuf>>valoare data nr 2    	
            Scan (&receiveBuf[22], "%s>%f[w10]", &client_Refk);
		
	
		//Setare si Pornire timer esantionare Server
		if(var_A_M==0)
		{//Regim Automat se porneste Timerul de la aplicatia Client
				//Se Aactiveaza Potentiometru REFERINTA si Te
				SetCtrlAttribute (g_hmainPanel,MAINPNL_REFERINTA, ATTR_DIMMED,0); 
				SetCtrlAttribute (g_hmainPanel,MAINPNL_TE, ATTR_DIMMED,0);
			//Se citeste Valoarea Te
			GetCtrlVal (g_hmainPanel, MAINPNL_TE, &client_Te);
			//Se porneste Timerul la Client
			SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_CLIENT, ATTR_INTERVAL,client_Te);// Seteaza Timer 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_CLIENT, ATTR_ENABLED, 1); 
		}
		else
		{ //Regim Manual 
		//Se Opreste Timerul la Client
				SetCtrlAttribute (g_hmainPanel, MAINPNL_TIMER_CLIENT, ATTR_ENABLED, 0);
				//Dezactiveaza Potentiometru REFERINTA si Te
				SetCtrlAttribute (g_hmainPanel,MAINPNL_REFERINTA, ATTR_DIMMED,1); 
				SetCtrlAttribute (g_hmainPanel,MAINPNL_TE, ATTR_DIMMED,1);
		}
					
				SetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, client_Refk);  	
				SetCtrlVal (g_hmainPanel, MAINPNL_TE, client_Te); 
				SetCtrlVal (g_hmainPanel, MAINPNL_AUTOMAT_MANUAL, var_A_M); 
			
	}

 
	return 0;
}
