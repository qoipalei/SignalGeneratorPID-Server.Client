/*---------------------------------------------------------------------------*/
/*                                                                           */
/* FILE:    client.c                                                         */
/*                                                                           */
/* PURPOSE: This is a skeleton program to demonstrate how you would write a  */
/*          a TCP Client application. This program connects to an established*/
/*          TCP server and communicates via a user interface panel.  This    */
/*          sample only communicates with one server, but illustrates how to */
/*          implement a callback function to respond to TCP events.          */
/*                                                                           */
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
#include "client.h"

/*---------------------------------------------------------------------------*/
/* Macros						                                             */
/*---------------------------------------------------------------------------*/
#define tcpChk(f) if ((g_TCPError=(f)) < 0) {ReportTCPError(); goto Done;} else

/*---------------------------------------------------------------------------*/
/* //INCLUDERE BIBLIOTECI DE FUNCTII						                                             */
/*---------------------------------------------------------------------------*/ 
#include "00_Variabile_Globale_Client.h"	//Functia declarare variabile globale Client    
#include "01_Initializare_Aplicatie_Client.h"
#include "02_Functii_Utilitare_Client.h"
#include "04_Formatare_Transmisie_TCP_TX_catre_server.h" 
#include "05_formatare_TCP_RX_de_la_Server.h"
#include "06_receptie_TCP_INT_de_la_server.h" 
#include "07_Elemente_FEEDBACK.h"

//#########################################################
//###########      FUNCTIA PRINCIPALA  main     ###########
//#########################################################
int main (int argc, char *argv[])
{
    int  portNum;
    char tempBuf[256] = {0};
    char portNumStr[32];
    
    if (InitCVIRTE (0, argv, 0) == 0)
        return -1;
    if ((g_hmainPanel = LoadPanel(0, "client.uir", MAINPNL)) < 0)
        goto Done;
    DisableBreakOnLibraryErrors();
    /* Prompt for the name of the server to connect to */
    PromptPopup ("Server Name?",
                 "Type the name of the machine running the sample server "
                 "application.\n\n(example: abc.xyz.com or xxx.xxx.xxx.xxx)",
                 tempBuf, 255);
    /* Prompt for the port number on the server */
    PromptPopup ("Port Number?",
                 "Type the port number that was set when starting the sample "
                 "server application.\n\n(example: 10000)",
                 portNumStr, 31);
    portNum = atoi (portNumStr);
    /* Attempt to connect to TCP server... */
    SetWaitCursor (1);
    if (ConnectToTCPServer (&g_hconversation, portNum, tempBuf, ClientTCP_INT_Comunicatie, NULL, 5000) < 0)
        MessagePopup("TCP Client", "Connection to server failed !");
    else
        {
        SetWaitCursor (0);
        g_connected = 1;
        
        /* We are successfully connected -- gather info */
        SetCtrlVal (g_hmainPanel, MAINPNL_CONNECTED, 1);
  		if (GetTCPHostAddr (tempBuf, 256) >= 0)
        	SetCtrlVal (g_hmainPanel, MAINPNL_CLIENT_IP, tempBuf);
        if (GetTCPHostName (tempBuf, 256) >= 0)
	        SetCtrlVal (g_hmainPanel, MAINPNL_CLIENT_NAME, tempBuf);
        tcpChk (GetTCPPeerAddr (g_hconversation, tempBuf, 256));
        SetCtrlVal (g_hmainPanel, MAINPNL_SERVER_IP, tempBuf);
        tcpChk (GetTCPPeerName (g_hconversation, tempBuf, 256));
        SetCtrlVal (g_hmainPanel, MAINPNL_SERVER_NAME, tempBuf);
        
        /* display the panel and run the UI */
        DisplayPanel (g_hmainPanel);
        SetActiveCtrl (g_hmainPanel, MAINPNL_STRING);
        RunUserInterface ();
        }
    
Done:
    /* Disconnect from the TCP server */
    if (g_connected)
    	DisconnectFromTCPServer (g_hconversation);

    /* Free resources and return */
    DiscardPanel (g_hmainPanel);
    CloseCVIRTE ();
    return 0;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$        Functia Timer  Esantionare Client   $$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
int CVICALLBACK esantionare_Client (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			if (var_A_M==1)
			{
				//tratare Regim Manual
			}
			else
			{
				//Tratare Regim Automat
			}
			break;
	}
	return 0;
}



