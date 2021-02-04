/*########################################################################## */
/*        Variabile globale declaratii prototip functii >>>>SERVER           */
/*########################################################################## */

/*---------------------------------------------------------------------------*/
/* Declaratii prototip functii                                               */
/*---------------------------------------------------------------------------*/

#pragma once

int CVICALLBACK ClientTCP_INT_Comunicatie (unsigned handle, int event, int error, void *callbackData);
static void ReportTCPError (void);

/*---------------------------------------------------------------------------*/
/* Variabile globale                                                         */
/*---------------------------------------------------------------------------*/
static unsigned int g_hconversation;
static int          g_hmainPanel;
static int			g_connected = 0;
static int			g_TCPError = 0;

//Variabila Automat / Manual Server
double var_A_M;

double client_Refk;
double client_Te;

// PID
double epsk, epsk_1 = 0, epsk_2 = 0, yPIDk, yPIDk_1 = 0, yPIDk_2 = 0, a1, a2, b0, b1, b2;
double p0,p1,p2,q0,q1,q2;
double alpha, Kr, Ti, Td;
double Refk, Refk_1, Refk0;
double Kr, Ti, Td;
double Traductor = 0.f;

// Constante
const int AUTOMAT = 0;
const int INITIAL = 0;
int FirstRun = INITIAL;

// Functie de transfer
double const constantaT = 22, constantaT1 = 25, constantaT2 = 34;
double C, C1, C2;