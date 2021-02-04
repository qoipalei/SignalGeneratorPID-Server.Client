/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  MAINPNL                          1       /* callback function: MainPanelCB */
#define  MAINPNL_TRANSMIT                 2       /* control type: textBox, callback function: (none) */
#define  MAINPNL_STRING                   3       /* control type: string, callback function: transmisie_catre_client */
#define  MAINPNL_RECEIVE                  4       /* control type: textBox, callback function: (none) */
#define  MAINPNL_CONNECTED                5       /* control type: LED, callback function: (none) */
#define  MAINPNL_AUTOMAT_MANUAL           6       /* control type: binary, callback function: (none) */
#define  MAINPNL_ONLINE                   7       /* control type: LED, callback function: (none) */
#define  MAINPNL_CLEAR                    8       /* control type: command, callback function: ClearScreenCB */
#define  MAINPNL_CLIENT_NAME              9       /* control type: string, callback function: (none) */
#define  MAINPNL_CLIENT_IP                10      /* control type: string, callback function: (none) */
#define  MAINPNL_SERVER_NAME              11      /* control type: string, callback function: (none) */
#define  MAINPNL_SERVER_IP                12      /* control type: string, callback function: (none) */
#define  MAINPNL_DECORATION               13      /* control type: deco, callback function: (none) */
#define  MAINPNL_TEXTMSG                  14      /* control type: textMsg, callback function: (none) */
#define  MAINPNL_DECORATION_2             15      /* control type: deco, callback function: (none) */
#define  MAINPNL_REFERINTA                16      /* control type: scale, callback function: transmisie_catre_client */
#define  MAINPNL_TE                       17      /* control type: numeric, callback function: transmisie_catre_client */
#define  MAINPNL_COMMANDBUTTON            18      /* control type: command, callback function: Start_Aplicatie */
#define  MAINPNL_QUITBUTTON               19      /* control type: command, callback function: QuitCallback */
#define  MAINPNL_TIMER_SERVER             20      /* control type: timer, callback function: esantionare_Server */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ClearScreenCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK esantionare_Server(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MainPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Start_Aplicatie(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK transmisie_catre_client(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
