/*########################################################################## */
/*        Variabile globale declaratii prototip functii >>>>SERVER           */
/*########################################################################## */

/*---------------------------------------------------------------------------*/
/* Declaratii prototip functii                                               */
/*---------------------------------------------------------------------------*/
int CVICALLBACK ServerTCP_INT_Comunicatie (unsigned handle, int event, int error,
							 void *callbackData);

static void ReportTCPError (void);

/*---------------------------------------------------------------------------*/
/* Variabile globale                                                         */
/*---------------------------------------------------------------------------*/
static unsigned int g_hconversation = 0;
static int          g_hmainPanel = 0;
static int			g_TCPError = 0;
double server_Te;
double server_Refk;
//Variabila Automat / Manual Server
int var_A_M;
