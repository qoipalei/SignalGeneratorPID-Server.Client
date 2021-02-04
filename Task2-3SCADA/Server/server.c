/*---------------------------------------------------------------------------*/
/* FILE:    server.c                                                         */
/* PURPOSE: This is a skeleton program to demonstrate how you would write a  */
/*          a TCP Server application. This sample registers a server on a    */
/*          speciable port number and waits for connections.  It will allow  */
/*          a connection from one client, and let the user send data back    */
/*          and forth.  For simplicity, the server refuses more than 1       */
/*          simultaneous client connection.                                  */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Include files                                                             */
/*---------------------------------------------------------------------------*/
#include <formatio.h>
#include <cvirte.h>
#include <stdio.h>
#include <stdlib.h>
#include <tcpsupp.h>
#include <string.h>
#include <utility.h>
#include <userint.h>
#include "server.h"
 
/*---------------------------------------------------------------------------*/
/* Macros						                                             */
/*---------------------------------------------------------------------------*/
#define tcpChk(f) if ((g_TCPError=(f)) < 0 ) {ReportTCPError(); goto Done;} else

/*---------------------------------------------------------------------------*/
/* //INCLUDERE BIBLIOTECI DE FUNCTII						                                             */
/*---------------------------------------------------------------------------*/
#include "00_Variabile_Globale_Server.h"	//Functia declarare variabile globale Server
#include "01_Initializare_Aplicatie_Server.h"	// Functia  INITIALIZARE APLICATIE...SERVER  
#include "02_Functii_Utilitare_Server.h"		// Functii UTILITARE: ,...
#include "04_Formatare_Transmisie_TCP_TX_catre_Client.h"// formatare date si transmisie catre Client  
#include "05_formatare_TCP_RX_de_la_client.h"			// formatare date primite de la client     
#include "06_receptie_TCP_INT_de_la_client.h"			// receptie TCP pe intrerupere de la client
#include "07_Elemente_FEEDBACK.h"	//Elemete Feedback: Regulator/Compensator/Instalatie Tehnologica/Traductoare
#include "10_Elemente_Schema_Sinoptica.h"	//Elemete Schema Sinoptica>>>> Animatie......
//#########################################################
//###########      FUNCTIA PRINCIPALA  main     ###########
//#########################################################
int main (int argc, char *argv[])
{
	int      portNum;
	char     tempBuf[256] = {0};
	int		 registered = 0;

	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;
	if ((g_hmainPanel = LoadPanel(0, "server.uir", MAINPNL)) < 0)
		return -1;
	//conectare Client
	 conectare_Client=0;
	//Setare comunicatie client/server
	DisableBreakOnLibraryErrors();
	// Se solicita nr. Portului pentru realizare conexiuni
	PromptPopup ("Port Number?",
				 "Type the port number on which you would like to register "
				 "this server application.\n\n(example: 10000)",
				 tempBuf, 31);
	
	portNum = strlen(tempBuf) == 0? 10000 : atoi (tempBuf);
	
	//Inregistrarea Aplicatiei ca Server-TCP 
	SetWaitCursor (1);
	if (RegisterTCPServer (portNum, ServerTCP_INT_Comunicatie, 0) < 0)
		MessagePopup("TCP Server", "Server registration failed!");
	else
		{
		registered = 1;
		SetWaitCursor (0);
		
		/* We are successfully registered -- gather info */
		SetCtrlVal (g_hmainPanel, MAINPNL_ONLINE, 1);
		if (GetTCPHostAddr (tempBuf, 256) >= 0)
	        SetCtrlVal (g_hmainPanel, MAINPNL_SERVER_IP, tempBuf);
		if (GetTCPHostName (tempBuf, 256) >= 0)
	        SetCtrlVal (g_hmainPanel, MAINPNL_SERVER_NAME, tempBuf);
		SetCtrlAttribute (g_hmainPanel, MAINPNL_STRING, ATTR_DIMMED, 1);
		SetCtrlVal (g_hmainPanel, MAINPNL_CONNECTED, 0); 
		
		/* Display the panel and run the UI */
		DisplayPanel (g_hmainPanel);
		SetActiveCtrl (g_hmainPanel, MAINPNL_STRING);
		RunUserInterface ();
		}
	
	if (registered)
		UnregisterTCPServer (portNum);
		
	/* Free resources and return */
	DiscardPanel (g_hmainPanel);
	CloseCVIRTE ();
	return 0;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$        Functia Timer  Esantionare Server   $$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
int CVICALLBACK esantionare_Server (int panel, int control, int event, void *callbackData, int eventData1, int eventData2) {
	switch (event) {
		case EVENT_TIMER_TICK:
			
			if (var_A_M == MANUAL) { 
				GetCtrlVal (g_hmainPanel, MAINPNL_AUTOMAT_MANUAL, &var_A_M);
				GetCtrlVal (g_hmainPanel, MAINPNL_TE, &server_Te); 
				GetCtrlVal (g_hmainPanel, MAINPNL_REFERINTA, &server_Refk);	
				
				//daca este conectat un client se comunica cu el
				// tesetare client conectat
				
				
				//#############################################################################		
				//Bloc de program pt. Prelucrare PROCES pe manual
				//Aici se poate prelucra raspunsul procesului>>>>RELATIILE iterative
				//@@@@@@@@ Esantionare de la Timer-Server
				//############################################################################		
				
				SeteazaValorileConstantelor(server_Te);
			
				double elementExecutie = ElementDeExecutie();
				double instalatieTehnologica = InstalatieTehnologica(elementExecutie);
				//Traductor(instalatieTehnologica);
				
				PlotLine (g_hmainPanel, MAINPNL_GRAPH, tk_1, server_Refk_1, tk, server_Refk, VAL_GREEN);
				PlotLine (g_hmainPanel, MAINPNL_GRAPH, tk_1, y2k_1, tk, y2k, VAL_YELLOW);
				
				UpdateValues();
				
				//Elemente de schema sinoptica functie utilitara
				animatie_Bazin(instalatieTehnologica); 
				
				if(conectare_Client == CONECTAT)	
					transmisie_catre_client(); 
				
			}
					
			break;
	}
	return 0;
}

int CVICALLBACK ClearCallback (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			ResetPlot();
			break;
	}
	return 0;
}
