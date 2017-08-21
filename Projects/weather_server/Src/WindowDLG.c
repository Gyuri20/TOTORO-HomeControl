/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include <stdint.h>
#include <string.h>
#include "projector_client.h"
#include "ac_client.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x03)
#define ID_BUTTON_0 (GUI_ID_USER + 0x04)
#define ID_BUTTON_1 (GUI_ID_USER + 0x06)
#define ID_BUTTON_2 (GUI_ID_USER + 0x07)
#define ID_TEXT_0 (GUI_ID_USER + 0x08)
#define ID_TEXT_1 (GUI_ID_USER + 0x09)
#define ID_TEXT_2 (GUI_ID_USER + 0x0A)
#define ID_TEXT_3 (GUI_ID_USER + 0x0B)
#define ID_TEXT_4 (GUI_ID_USER + 0x0C)
#define ID_TEXT_5 (GUI_ID_USER + 0x0D)
#define ID_TEXT_6 (GUI_ID_USER + 0x0E)
#define ID_BUTTON_3 (GUI_ID_USER + 0x0F)
#define ID_BUTTON_4 (GUI_ID_USER + 0x10)
#define ID_SPINBOX_0 (GUI_ID_USER + 0x11)
#define ID_BUTTON_5 (GUI_ID_USER + 0x12)


/* Sent value defines */
#define PROJECTOR_UP		1
#define PROJECTOR_STOP		2
#define PROJECTOR_DOWN		3
#define AC_ON				1
#define AC_OFF				0
#define AC_SWING_ON			1
#define AC_SWING_OFF		0
#define AC_MIN_VALUE		16
#define AC_MAX_VALUE		30

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
WM_HWIN main_window;
WM_HWIN hItem;
WM_HWIN swing_button;
WM_HWIN AC_control;
WM_HWIN AC_on_off;

uint8_t ac_state = 0;
uint8_t ac_swing_state = 0;
int ac_temperature;
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 1, 0x0, 0 },
  { BUTTON_CreateIndirect, "UP", ID_BUTTON_0, 400, 27, 50, 50, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "STOP", ID_BUTTON_1, 400, 87, 50, 50, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "DOWN", ID_BUTTON_2, 400, 147, 50, 50, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "HomeControl", ID_TEXT_0, 8, 4, 80, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Temperature (C)", ID_TEXT_1, 110, 5, 86, 22, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Humidity (%)", ID_TEXT_2, 285, 5, 80, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Pressure (Pa)", ID_TEXT_3, 285, 95, 80, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "", ID_TEXT_4, 105, 0, 170, 170, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "", ID_TEXT_5, 280, 0, 85, 85, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "", ID_TEXT_6, 280, 90, 85, 85, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "AC OFF", ID_BUTTON_3, 5, 215, 80, 50, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "No swing", ID_BUTTON_4, 95, 215, 80, 50, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "", ID_SPINBOX_0, 185, 195, 150, 70, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "L", ID_BUTTON_5, 5, 135, 80, 70, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};


/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;

  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Window'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, GUI_MAKE_COLOR(0x00F0000F));
    //
    // Initialization of 'HomeControl'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    //
    // Initialization of 'Temperature (C)'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    //
    // Initialization of 'Humidity (%)'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    //
    // Initialization of 'Pressure (Pa)'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    //
    // Initialization of 'temp_data'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_BOTTOM);
    TEXT_SetFont(hItem, GUI_FONT_D64);
    //
    // Initialization of 'hum_data'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_BOTTOM);
    TEXT_SetFont(hItem, GUI_FONT_24_1);
    //
    // Initialization of 'press_data'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_BOTTOM);
    TEXT_SetFont(hItem, GUI_FONT_24_1);

    // Initialization of 'AC control spinbox'
    //
    AC_control = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_0);
    SPINBOX_SetRange(AC_control, AC_MIN_VALUE, AC_MAX_VALUE);
    SPINBOX_SetValue(AC_control, AC_MIN_VALUE);
    SPINBOX_SetStep(AC_control, 1);
    SPINBOX_SetButtonSize(AC_control, 70);
    SPINBOX_SetFont(AC_control, GUI_FONT_24_1);


    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'UP'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  send_command_to_projector_screen(PROJECTOR_UP);
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'STOP'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  send_command_to_projector_screen(PROJECTOR_STOP);
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by 'DOWN'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  send_command_to_projector_screen(PROJECTOR_DOWN);
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_3: // Notifications sent by 'ON/OFF'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  switch(ac_state) {
    	  case 0:
    		  send_command_to_ac(AC_ON);		//TODO: correct sending
    		  ac_state = 1;
    		  BUTTON_SetText(AC_on_off, "AC is ON");
    		  break;
    	  case 1:
    		  send_command_to_ac(AC_OFF);		//TODO: correct sending
    		  ac_state = 0;
    		  BUTTON_SetText(AC_on_off, "AC is OFF");
    		  break;
    	  }
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_4: // Notifications sent by 'Swing'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  switch(ac_swing_state) {
    	  case 0:
    		  send_command_to_ac(AC_SWING_ON);
    		  ac_swing_state = 1;
    		  BUTTON_SetText(swing_button, "Swinging");
    		  break;
    	  case 1:
    		  send_command_to_ac(AC_SWING_OFF);
    		  ac_swing_state = 0;
    		  BUTTON_SetText(swing_button, "No swing");
    		  break;
    	  }
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;

      case ID_BUTTON_5: // Notifications sent by 'L'
         switch(NCode) {
         case WM_NOTIFICATION_CLICKED:
           // USER START (Optionally insert code for reacting on notification message)

           // USER END
           break;
         case WM_NOTIFICATION_RELEASED:
           // USER START (Optionally insert code for reacting on notification message)
           // USER END
           break;
         // USER START (Optionally insert additional code for further notification handling)
         // USER END
         }
         break;
    case ID_SPINBOX_0: // Notifications sent by 'Spinbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
//    	  ac_temperature = (uint8_t)SPINBOX_GetValue(AC_control);
//    	  uint8_t second_int_to_send = ac_temperature / 10;
//    	  uint8_t first_int_to_send = ac_temperature - second_int_to_send * 10;
//    	  send_command_to_ac(first_int_to_send);		//TODO: correct send!
//    	  send_command_to_ac(second_int_to_send);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/* Update displayed temperature in GUI */
void gui_update_temp(float temp)
{
    WM_HWIN hItem;
    char str[10];
	hItem = WM_GetDialogItem(main_window, ID_TEXT_4);
	sprintf(str, "%.0f", temp);
	TEXT_SetText(hItem, str);
}

/* Update displayed humidity in GUI */
void gui_update_hum(float hum)
{
    WM_HWIN hItem;
    char str[10];
	hItem = WM_GetDialogItem(main_window, ID_TEXT_5);
	sprintf(str, "%.0f", hum);
	TEXT_SetText(hItem, str);
}

/* Update displayed pressure in GUI */
void gui_update_press(float press)
{
    WM_HWIN hItem;
    char str[10];
	hItem = WM_GetDialogItem(main_window, ID_TEXT_6);
	sprintf(str, "%.0f", press);
	TEXT_SetText(hItem, str);
}
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateWindow(void) {
  main_window = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);		//
  return main_window;
}

// USER START (Optionally insert additional public code)
void MainTask(void) {
   CreateWindow() ;
}
// USER END

/*************************** End of file ****************************/
