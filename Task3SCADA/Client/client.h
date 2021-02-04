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
#define  MAINPNL_STRING                   3       /* control type: string, callback function: (none) */
#define  MAINPNL_RECEIVE                  4       /* control type: textBox, callback function: (none) */
#define  MAINPNL_CONNECTED                5       /* control type: LED, callback function: (none) */
#define  MAINPNL_AUTOMAT_MANUAL           6       /* control type: binary, callback function: (none) */
#define  MAINPNL_CLEAR                    7       /* control type: command, callback function: ClearScreenCB */
#define  MAINPNL_CLIENT_NAME              8       /* control type: string, callback function: (none) */
#define  MAINPNL_CLIENT_IP                9       /* control type: string, callback function: (none) */
#define  MAINPNL_SERVER_NAME              10      /* control type: string, callback function: (none) */
#define  MAINPNL_SERVER_IP                11      /* control type: string, callback function: (none) */
#define  MAINPNL_DECORATION               12      /* control type: deco, callback function: (none) */
#define  MAINPNL_TEXTMSG                  13      /* control type: textMsg, callback function: (none) */
#define  MAINPNL_TD                       14      /* control type: numeric, callback function: online */
#define  MAINPNL_KR                       15      /* control type: numeric, callback function: online */
#define  MAINPNL_TI                       16      /* control type: numeric, callback function: online */
#define  MAINPNL_TE                       17      /* control type: numeric, callback function: (none) */
#define  MAINPNL_REFERINTA                18      /* control type: scale, callback function: (none) */
#define  MAINPNL_QUITBUTTON               19      /* control type: command, callback function: QuitCallback */
#define  MAINPNL_TIMER_CLIENT             20      /* control type: timer, callback function: esantionare_Client */
#define  MAINPNL_COMMANDBUTTON            21      /* control type: command, callback function: Start_Aplicatie_Client */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ClearScreenCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK esantionare_Client(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MainPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK online(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Start_Aplicatie_Client(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif