//######################################################################################
//######    Functie de Formatare Pachet de date pt RX-receptie de la Client ############
//######################################################################################
int receptie_de_la_client(char receiveBuf[256],int  dataSize )
{
	if ((dataSize = ServerTCPRead (g_hconversation, receiveBuf,dataSize, 10))< 0)
          { SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, "Receive Error\n"); }
    else
    {
            	receiveBuf[dataSize] = '\0';
					ResetTextBox (g_hmainPanel, MAINPNL_RECEIVE, "");
            	SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, receiveBuf);
			//Extragere Date din pachetul receptionat
			//selectare din receivebuf>>valoare data nr 1 
				Scan (&receiveBuf[0], "%s>%f[w10]", &server_Refk);
            //selectare din receivebuf>>valoare data nr 2    	
                Scan (&receiveBuf[11], "%s>%f[w10]", &server_Te);
				
				
				SetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, server_Refk);  	
				SetCtrlVal (g_hmainPanel, MAINPNL_TE, server_Te); 
	}
return 0;
}
