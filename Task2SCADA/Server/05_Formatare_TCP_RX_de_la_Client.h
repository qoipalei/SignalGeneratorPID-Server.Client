//######################################################################################
//######    Functie de Formatare Pachet de date pt RX-receptie de la Client ############
//######################################################################################


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
		
		// Selecteaza iesirea din traductor
		//Scan(&receiveBuf[22], "%s>%f[w10]", &yPIDk);
		
		// Seteaza referinta ca fiind iesirea din regulatorul din client, daca acesta este setat pe "Remote" (AUTOMAT)
		

		

		SetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, server_Refk);  	
		SetCtrlVal (g_hmainPanel, MAINPNL_TE, server_Te);
		
		//#############################################################################		
		//Bloc de program pt. Prelucrare PROCES pe automat
		//Aici se poate prelucra raspunsul procesului>>>>RELATIILE iterative
		//@@@@@@@@ Esantionare de la comunicatia pe intreruperi de la Client
		//############################################################################
		

	Constante(server_Te);
		//Implementarea Element de Comparatie
		epsk=server_Refk-yTRk1;
		uEEk=server_Refk;
		//apelare  functia elmenetului de executie
		yEEk=EE();
		//perluare iesire element de executie
		uITk=yEEk;
		//apelare functie instalatietehnologica
		yITk3=InstalatieTehnologica();
		uTRk1=yITk3;
		//apelare functie tradcutor
		yTRk1=Traductor();
	
		// Plot input and output
		// DebugClientSend();
		PlotLine (g_hmainPanel, MAINPNL_GRAPH, tk_1, server_Refk_1, tk, server_Refk, VAL_GREEN);
		PlotLine (g_hmainPanel, MAINPNL_GRAPH, tk_1, yITk3_1, tk, yITk3, VAL_BLUE);
		
		// Transmite valoarea traductorului catre client
		transmisie_catre_client();
		
		// Actualizeaza datele	
 reactualizare();
		
		// Elemente de schema sinoptica
		animatie_Bazin(yITk3); 
	}
return 0;
}
