/*########################################################################## */
/*        Variabile globale declaratii prototip functii >>>>SERVER           */
/*########################################################################## */

/*---------------------------------------------------------------------------*/
/* Declaratii prototip functii                                               */
/*---------------------------------------------------------------------------*/
int CVICALLBACK ClientTCP_INT_Comunicatie (unsigned handle, int event, int error,
                             void *callbackData);
static void ReportTCPError (void);

/*---------------------------------------------------------------------------*/
/* Variabile globale                                                         */
/*---------------------------------------------------------------------------*/
static unsigned int g_hconversation;
static int      g_hmainPanel;
static int			g_connected = 0;
static int			g_TCPError = 0;

//Variabila Automat / Manual Server
int var_A_M;

double client_Refk;
double client_Te;
