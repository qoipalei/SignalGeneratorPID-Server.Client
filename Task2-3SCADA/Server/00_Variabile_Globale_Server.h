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
double const constantaT = 22, constantaT1 = 25, constantaT2 = 34;
double C, C1, C2; 
double const FastestTimeSample = constantaT1; // Cea mai rapida constanta a sistemului este T1, 25

// Elementul de executie si traductorul
double T_EE1 = 0.02*FastestTimeSample, T_EE2 = 0.05*FastestTimeSample, C1_EE, C2_EE;
double T1_Tr1 = 0.05*FastestTimeSample, C_Tr1;

// Inputs
double server_Refk_1, tk=0, tk_1;

// Outputs
double y1k, y1k_1, y2k, y2k_1;
double yk_EE, yk_1_EE;
double yk_Tr1 = 0, yk_1_Tr1;

// PID
double epsk, epsk_1 = 0, epsk_2 = 0, yPIDk, yPIDk_1 = 0, yPIDk_2 = 0, a1, a2, b0, b1, b2;
double p0,p1,p2,q0,q1,q2;
double alpha, Kr, Ti, Td;
double Refk, Refk_1, Refk0;
double Kr=5, Ti=0.1, Td=50;