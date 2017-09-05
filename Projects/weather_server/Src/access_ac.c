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
#include <stdio.h>
#include "ac_client.h"
#include "access_ac.h"
#include "cmsis_os.h"
#include "WindowDLG.h"
#include "gui_setup.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0    (GUI_ID_USER + 0x00)
#define ID_TEXT_0    (GUI_ID_USER + 0x08)
#define ID_TEXT_1    (GUI_ID_USER + 0x0A)
#define ID_TEXT_2    (GUI_ID_USER + 0x1C)
#define ID_TEXT_3    (GUI_ID_USER + 0x1D)
#define ID_SPINBOX_0    (GUI_ID_USER + 0x14)
#define ID_BUTTON_0    (GUI_ID_USER + 0x15)
#define ID_BUTTON_1    (GUI_ID_USER + 0x16)
#define ID_BUTTON_2    (GUI_ID_USER + 0x17)
#define ID_TEXT_4 (GUI_ID_USER + 0x0C)
#define ID_TEXT_5 (GUI_ID_USER + 0x0D)
#define ID_TEXT_6 (GUI_ID_USER + 0x0E)
#define ID_TEXT_7 (GUI_ID_USER + 0x1B)
#define ID_TEXT_8 (GUI_ID_USER + 0x1A)




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
WM_HWIN AC_L_control;

uint8_t ac_state_ac = 0;
uint8_t ac_swing_state_ac = 0;
uint8_t ac_lever_state_ac = 0;
int ac_temperature_ac;
uint8_t ac_controls_ac[5] = {6, 1, 0, 3, 0};	//initialization for testing


// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate_ac[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 1, 0x0, 0 },
  { TEXT_CreateIndirect, "HomeControl", ID_TEXT_0, 8, 4, 80, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Temperature (C)", ID_TEXT_1, 110, 5, 86, 22, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Humidity (%)", ID_TEXT_2, 285, 5, 80, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Pressure (Pa)", ID_TEXT_3, 285, 95, 80, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "temp_data", ID_TEXT_4, 105, 0, 170, 170, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "hum_data", ID_TEXT_5, 280, 0, 85, 85, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "press_data", ID_TEXT_6, 280, 90, 85, 85, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "date", ID_TEXT_7, 5, 30, 100, 100, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "time", ID_TEXT_8, 297, 215, 160, 50, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "Spinbox", ID_SPINBOX_0, 185, 195, 100, 70, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "AC is OFF", ID_BUTTON_0, 5, 215, 80, 50, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Swing is OFF", ID_BUTTON_1, 95, 215, 80, 50, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Blade in 0", ID_BUTTON_2, 5, 135, 80, 70, 0, 0x0, 0 },
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
static void _cbDialog_ac(WM_MESSAGE * pMsg) {
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
    //
    // Initialization of 'date'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_TOP);
    TEXT_SetFont(hItem, GUI_FONT_20_1);
    //
    // Initialization of 'time'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_8);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_D48);

    // Initialization of 'AC control spinbox'
    //
    AC_control = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_0);
    SPINBOX_SetRange(AC_control, AC_MIN_VALUE, AC_MAX_VALUE);
    SPINBOX_SetValue(AC_control, AC_MIN_VALUE);
    SPINBOX_SetStep(AC_control, 1);
    SPINBOX_SetButtonSize(AC_control, 50);
    SPINBOX_SetFont(AC_control, GUI_FONT_24_1);

    //
    // Initialization of 'Swing button'
    //
    swing_button = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);

    //
    // Initialization of 'AC ON/OFF button'
    //
    AC_on_off = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);

    //
    // Initialization of 'AC lever control button'
    //
    AC_L_control = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);

    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
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
    	  ac_temperature_ac = (uint8_t)SPINBOX_GetValue(AC_control);
    	  uint8_t second_int_to_send = ac_temperature_ac / 10;
    	  uint8_t first_int_to_send = ac_temperature_ac - second_int_to_send * 10;
    	  ac_controls_ac[0] = first_int_to_send;
    	  ac_controls_ac[1] = second_int_to_send;
 		 //add value "No change" for ON/OFF control
 		 ac_controls_ac[4] = AC_STATE_NOCHANGE;
 		{osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
 		osThreadCreate (osThread(AC), (void*)ac_controls_ac);}

        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_0: // Notifications sent by 'AC is OFF'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  switch(ac_state_ac) {
    	  case AC_IS_OFF:
    		  ac_state_ac = AC_IS_ON;
    		  BUTTON_SetText(AC_on_off, "AC is ON");
    		  ac_controls_ac[4] = AC_STATE_CHANGE;
    		  {osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
    		  osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
    		  break;
    	  case AC_IS_ON:
    		  ac_state_ac = AC_IS_OFF;
    		  BUTTON_SetText(AC_on_off, "AC is OFF");
    		  ac_controls_ac[4] = AC_STATE_CHANGE;
      		  {osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
      		  osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
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
    case ID_BUTTON_1: // Notifications sent by 'Swing is OFF'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  switch(ac_swing_state_ac) {
    	  case 0:
    		  ac_swing_state_ac = 1;
    		  BUTTON_SetText(swing_button, "Swing is ON");
    		  ac_controls_ac[2] = AC_SWING_ON;
    		  //add value "No change" for ON/OFF control
    		  ac_controls_ac[4] = AC_STATE_NOCHANGE;
      		  {osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
      		  osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
    		  break;
    	  case 1:
    		  ac_swing_state_ac = 0;
    		  BUTTON_SetText(swing_button, "Swing is OFF");
    		  ac_controls_ac[2] = AC_SWING_OFF;
    		  //add value "No change" for ON/OFF control
    		  ac_controls_ac[4] = AC_STATE_NOCHANGE;
      		  {osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
      		  osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
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
    case ID_BUTTON_2: // Notifications sent by 'Blade in 0'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
     	 switch(ac_lever_state_ac) {
     	 case 0:
     		 ac_lever_state_ac = 1;
     		 ac_controls_ac[3] = AC_BLADE_1;
     		 BUTTON_SetText(AC_L_control, "Blade in 1");
     		 //add value "No change" for ON/OFF control
     		 ac_controls_ac[4] = AC_STATE_NOCHANGE;
     		  {osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
       		  osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
     		 break;
     	 case 1:
     		 ac_lever_state_ac = 2;
     		 ac_controls_ac[3] = AC_BLADE_2;
     		 BUTTON_SetText(AC_L_control, "Blade in 2");
     		 //add value "No change" for ON/OFF control
     		 ac_controls_ac[4] = AC_STATE_NOCHANGE;
     		  {osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
       		  osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
     		 break;
     	 case 2:
     		 ac_lever_state_ac = 3;
     		 ac_controls_ac[3] = AC_BLADE_3;
     		 BUTTON_SetText(AC_L_control, "Blade in 3");
     		 //add value "No change" for ON/OFF control
     		 ac_controls_ac[4] = AC_STATE_NOCHANGE;
     		  {osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
       		  osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
     		 break;
     	 case 3:
     		 ac_lever_state_ac = 4;
     		 ac_controls_ac[3] = AC_BLADE_4;
     		 BUTTON_SetText(AC_L_control, "Blade in 4");
     		 //add value "No change" for ON/OFF control
     		 ac_controls_ac[4] = AC_STATE_NOCHANGE;
     		{osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
     		osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
     		 break;
     	 case 4:
     		 ac_lever_state_ac = 5;
     		 ac_controls_ac[3] = AC_BLADE_5;
     		 BUTTON_SetText(AC_L_control, "Blade in 5");
     		 //add value "No change" for ON/OFF control
     		 ac_controls_ac[4] = AC_STATE_NOCHANGE;
     		{osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
      		osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
     		 break;
     	 case 5:
     		 ac_lever_state_ac = 0;
     		 ac_controls_ac[3] = AC_BLADE_0;
     		 BUTTON_SetText(AC_L_control, "Blade in 0");
     		 //add value "No change" for ON/OFF control
     		 ac_controls_ac[4] = AC_STATE_NOCHANGE;
     		{osThreadDef(AC, ac_client_thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
      		osThreadCreate (osThread(AC), (void*)ac_controls_ac);}
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
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateWindow_ac(void) {
  main_window = GUI_CreateDialogBox(_aDialogCreate_ac, GUI_COUNTOF(_aDialogCreate_ac), _cbDialog_ac, WM_HBKWIN, 0, 0);
  return main_window;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
