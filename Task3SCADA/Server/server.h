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
#define  MAINPNL_AUTOMAT_MANUAL           6       /* control type: binary, callback function: comutarea_Automat_Manual */
#define  MAINPNL_ONLINE                   7       /* control type: LED, callback function: (none) */
#define  MAINPNL_CLEAR                    8       /* control type: command, callback function: ClearScreenCB */
#define  MAINPNL_CLIENT_NAME              9       /* control type: string, callback function: (none) */
#define  MAINPNL_CLIENT_IP                10      /* control type: string, callback function: (none) */
#define  MAINPNL_SERVER_NAME              11      /* control type: string, callback function: (none) */
#define  MAINPNL_SERVER_IP                12      /* control type: string, callback function: (none) */
#define  MAINPNL_DECORATION               13      /* control type: deco, callback function: (none) */
#define  MAINPNL_TEXTMSG                  14      /* control type: textMsg, callback function: (none) */
#define  MAINPNL_DECORATION_2             15      /* control type: deco, callback function: (none) */
#define  MAINPNL_REFERINTA                16      /* control type: scale, callback function: (none) */
#define  MAINPNL_TE                       17      /* control type: numeric, callback function: (none) */
#define  MAINPNL_START_APLICATIE          18      /* control type: command, callback function: Start_Aplicatie */
#define  MAINPNL_CLEARBUTON               19      /* control type: command, callback function: ClearCallback */
#define  MAINPNL_CLEARBUTTON              20      /* control type: command, callback function: QuitCallback */
#define  MAINPNL_TIMER_SERVER             21      /* control type: timer, callback function: esantionare_Server */
#define  MAINPNL_NUMERICTANK              22      /* control type: scale, callback function: (none) */
#define  MAINPNL_R_INCHIS                 23      /* control type: picture, callback function: (none) */
#define  MAINPNL_R_DESCHIS_2_3            24      /* control type: picture, callback function: (none) */
#define  MAINPNL_R_DESCHIS_1_3            25      /* control type: picture, callback function: (none) */
#define  MAINPNL_R_DESCHIS_1_2            26      /* control type: picture, callback function: (none) */
#define  MAINPNL_R_DESCHIS                27      /* control type: picture, callback function: (none) */
#define  MAINPNL_SPLITTER                 28      /* control type: splitter, callback function: (none) */
#define  MAINPNL_SPLITTER_2               29      /* control type: splitter, callback function: (none) */
#define  MAINPNL_GRAPH                    30      /* control type: graph, callback function: (none) */
#define  MAINPNL_GRAPH_2                  31      /* control type: graph, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ClearCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ClearScreenCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK comutarea_Automat_Manual(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK esantionare_Server(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MainPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Start_Aplicatie(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif