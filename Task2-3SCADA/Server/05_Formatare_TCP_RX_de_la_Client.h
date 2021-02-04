//######################################################################################
//######    Functie de Formatare Pachet de date pt RX-receptie de la Client ############
//######################################################################################

//#include "DebugMethods.h"
#include "07_Elemente_FEEDBACK.h"

int receptie_de_la_client(char receiveBuf[256],int  dataSize )
{
	if ((dataSize = ServerTCPRead (g_hconversation, receiveBuf,dataSize, 10))< 0){ 
		SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, "Receive Error\n"); 
	}
	
    else {
		
    	receiveBuf[dataSize] = '\0';
		ResetTextBox (g_hmainPanel, MAINPNL_RECEIVE, "");
    	SetCtrlVal (g_hmainPanel, MAINPNL_RECEIVE, receiveBuf);
		
		//Extragere Date din pachetul receptionat
		
		
		
		// selectare din receivebuf>>valoare data nr 1 
		Scan (&receiveBuf[0], "%s>%f[w10]", &server_Refk);
		
    	// selectare din receivebuf>>valoare data nr 2    	
	    Scan (&receiveBuf[11], "%s>%f[w10]", &server_Te);
		
		// Selecteaza iesirea din regulator
		Scan(&receiveBuf[22], "%s>%f[w10]", &yPIDk);
		
		// Seteaza referinta ca fiind iesirea din regulatorul din client, daca acesta este setat pe "Remote" (AUTOMAT)
		
		//server_Refk = var_A_M == MANUAL? server_Refk : yPIDk;
		
		//DEBUG
		//server_Refk = server_Refk;
		
		SetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, server_Refk);  	
		SetCtrlVal (g_hmainPanel, MAINPNL_TE, server_Te);
		
		//#############################################################################		
		//Bloc de program pt. Prelucrare PROCES pe automat
		//Aici se poate prelucra raspunsul procesului>>>>RELATIILE iterative
		//@@@@@@@@ Esantionare de la comunicatia pe intreruperi de la Client
		//############################################################################
		
		
		SeteazaValorileConstantelor(server_Te);
		double elementExecutie = ElementDeExecutie();
		double instalatieTehnologica = InstalatieTehnologica(elementExecutie);
		Traductor(instalatieTehnologica);
		
		
		// Plot input and output
		// DebugClientSend();
		PlotLine (g_hmainPanel, MAINPNL_GRAPH, tk_1, server_Refk_1, tk, server_Refk, VAL_GREEN);
		PlotLine (g_hmainPanel, MAINPNL_GRAPH, tk_1, y2k_1, tk, y2k, VAL_YELLOW);
		
		// Transmite valoarea traductorului catre client
		transmisie_catre_client();
		
		// Actualizeaza datele	
		UpdateValues();
		
		// Elemente de schema sinoptica
		animatie_Bazin(server_Refk); 
	}
return 0;
}
