/*########################################################################## */
/*        Variabile globale declaratii prototip functii >>>>SERVER           */
/*########################################################################## */

/*---------------------------------------------------------------------------*/
/* Declaratii prototip functii                                               */
/*---------------------------------------------------------------------------*/

int CVICALLBACK ServerTCP_INT_Comunicatie (unsigned handle, int event, int error, void *callbackData);

static void ReportTCPError (void);
int transmisie_catre_client ();
int animatie_Bazin();

/*---------------------------------------------------------------------------*/
/* Variabile globale                                                         */
/*---------------------------------------------------------------------------*/
static unsigned int g_hconversation = 0;
static int          g_hmainPanel = 0;
static int			g_TCPError = 0;
double server_Te;
double server_Refk;
int ServerPornit = 0;

// Constante utilizate ulterior in cod
const int MANUAL = 1;
const int AUTOMAT = 0;
const int OPRIT = 0;
const int CONECTAT = 1;

// Variabila Automat / Manual Server
double var_A_M;

// perioada esantionare Server
double server_Te;

// Variabila testare conectare Apl. Client
int conectare_Client;

// Functia de transfer
double T1 = 37, T2 = 12, T3 = 3;
double C1, C2, C3; 


// Elementul de executie si traductorul
double Tee1 = 0.24, Tee2 = 0.6, Cee1, Cee2;
double Ttr1 = 0.6, Ctr1;

// intrari
double server_Refk_1, tk=0, tk_1;

// instalatie tehnologica/element de executie/traductor
double yITk1,yITk1_1,yITk2,yITk2_1,yITk3,yITk3_1,uITk1,uITk1_1,uITk2,uITk2_1,uITk3_1,uITk3,uITk,uITk_1;
double yEEk, yEEk_1,uEEk,uEEk_1,uTRk1,uTRk1_1;
double yTRk1= 0, yTRk1_1;

// PID
double epsk, epsk_1 = 0, epsk_2 = 0, yPIDk, yPIDk_1 = 0, yPIDk_2 = 0, a1, a2, b0, b1, b2;
double p0,p1,p2,q0,q1,q2;
double alpha, Kr, Ti, Td;
double Refk, Refk_1, Refk0;
double Kr=5, Ti=0.1, Td=50;