# API
## Common Function
### BOOL __cdecl EasyWinModernCtrl_IsSystemSupport();
Check current system is windows 10 rs5 or higher version.\
if returned 'FALSE' system does not support this library.

### void __cdecl EasyWinModernCtrl_InitializeApartment(BOOL useMTA);
Initialize UWP control.\
if system supported, you must call this function to use library.

### void __cdecl EasyWinModernCtrl_UnInitialize();
Uninitialize library.\
You must call this function on exit program, if you call 'EasyWinModernCtrl_InitializeApartment' before.

## Common Function For All Controls.
### void __cdecl EasyWinModernCtrl_ShowControl(PVOID pControl, HWND parentHwnd);
Show control at parent window.

### void __cdecl EasyWinModernCtrl_AdjustLayout(PVOID pControl);
Resize uwp control if parent window size has been changed.

### HWND __cdecl EasyWinModernCtrl_GetRawControlHwnd(PVOID pControl);
Get uwp control raw hwnd.

### void __cdecl EasyWinModernCtrl_SetTheme(PVOID pControl,DWORD dwFlags);
Set uwp control theme.\
  *dwFlags : theme type (0 : system default , 1 : light , 2 : dark)
  
### void __cdecl EasyWinModernCtrl_HideControl(PVOID pControl,BOOL reShow);
Hide / Reshow uwp control.

### void __cdecl EasyWinModernCtrl_CloseControl(PVOID pControl);
Close uwp control.
### void __cdecl EasyWinModernCtrl_CleanupControl(PVOID pControl);
Cleanup uwp control.

## Textbox
### PEASYMODERNTEXTBOX __cdecl EasyWinModernCtrl_CreateTextbox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, BOOL enableMultiLine, BOOL enableUserChangeLine, DWORD maxTextLength);
Create uwp textbox.\
  *controlName : unique name for uwp control.\
  *headerTitle : Set control header text. This parameter can be NULL.\
  *textPlaceholder : Set textbox placeholder text. This parameter can be NULL.\
  *enableMultiLine : Set textbox multiple line mode.\
  *enableUserChangeLine : in multiple line mode, set user can change line using 'Enter key'.\
  *maxTextLength : Set maximum text count. Set 0 to unlimited.

### LPCWSTR __cdecl EasyWinModernCtrl_TextboxGetText(PEASYMODERNTEXTBOX pTextboxInfo);
Get entered text at textbox.

### void __cdecl EasyWinModernCtrl_TextboxSetText(PEASYMODERNTEXTBOX pTextboxInfo,LPCWSTR text);
Set text at textbox.

### void __cdecl EasyWinModernCtrl_TextboxSetReadonlyMode(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable);
Set textbox readonly mode.
  *enable : If 'TRUE' , textbox will be in readonly mode. else textbox will be in read,write mode.
 
### void __cdecl EasyWinModernCtrl_TextboxSetEnableControl(PEASYMODERNTEXTBOX pTextboxInfo, BOOL enable);
Set enable / disable textbox.\
if control disabled, control will be 'graying out'.

## Password Box
### PEASYMODERNPWDBOX __cdecl EasyWinModernCtrl_CreatePasswordBox(LPCWSTR controlName, LPCWSTR headerTitle, LPCWSTR textPlaceholder, DWORD maxLength);
Create uwp password input box.\
  *controlName : unique name for uwp control.\
  *headerTitle : Set control header text. This parameter can be NULL.\
  *textPlaceholder : Set password box placeholder text. This parameter can be NULL.\
  *maxTextLength : Set maximum password length. Set 0 to unlimited.
  
### LPCWSTR __cdecl EasyWinModernCtrl_PasswordboxGetPassword(PEASYMODERNPWDBOX pPwdboxInfo);
Get entered password in password box.

### void __cdecl EasyWinModernCtrl_PasswordboxSetEnableControl(PEASYMODERNPWDBOX pPwdboxInfo, BOOL enable);
Set enable / disable password box.\
if control disabled, control will be 'graying out'.

## Button
### PEASYMODERNBTN __cdecl EasyWinModernCtrl_CreateButton(LPCWSTR controlName,DWORD id, LPCWSTR buttonLabel);
Create uwp button.\
  *controlName : unique name for uwp control.\
  *id : user-defined unique control id. used in clicked callback function.\
  *buttonLabel : Button label.
  
### void __cdecl EasyWinModernCtrl_ButtonSetClickCallback(PEASYMODERNBTN pBtnInfo, TEasyWinModernCtrl_BtnCallback cb, PVOID userData);
Set button clicked callback.\
  *cb : user-defined callback function. (type : 'typedef BOOL(__stdcall* TEasyWinModernCtrl_BtnCallback)(DWORD id, PVOID userData)')\
  *userData : user-defined data.

### void __cdecl EasyWinModernCtrl_ButtonSetUseAccentColor(PEASYMODERNBTN pBtnInfo, BOOL enable);
Set button system accent color. If system color is blue, button will has blue color.

### void __cdecl EasyWinModernCtrl_ButtonSetEnableControl(PEASYMODERNBTN pBtnInfo, BOOL enable);
Set enable / disable button.\
if control disabled, control will be 'graying out'.

## Slidebar (Slider)
### PEASYMODERNSLIDEBAR __cdecl EasyWinModernCtrl_CreateSlidebar(LPCWSTR controlName, DWORD id, DOUBLE minVal, DOUBLE maxVal, DOUBLE step, DOUBLE defaultValue);
Create uwp slidebar.\
  *controlName : unique name for uwp control.\
  *id : user-defined unique control id. used in clicked callback function.\
  *minVal : slidebar minimum value.\
  *maxVal : slidebar maximum value.\
  *step : slidebar step value.\
  *defaultValue : slidebar default value.

### void __cdecl EasyWinModernCtrl_SlidebarSetValueChangedCallback(PEASYMODERNSLIDEBAR pSlidebarInfo, TEasyWinModernCtrl_SlidebarCallback cb, PVOID userData);
Set slidebar value changed callback.\
  *cb : user-defined callback function. (type : 'typedef BOOL(__stdcall* TEasyWinModernCtrl_SlidebarCallback)(DWORD id, DOUBLE currentValue, PVOID userData)')\
  *userData : user-defined data.

### DOUBLE __cdecl EasyWinModernCtrl_SlidebarGetValue(PEASYMODERNSLIDEBAR pSlidebarInfo);
Get slidebar value.

### void __cdecl EasyWinModernCtrl_SlidebarSetEnableControl(PEASYMODERNSLIDEBAR pSlidebarInfo, BOOL enable);
Set enable / disable slidebar.\
if control disabled, control will be 'graying out'.
  
## Progress Ring (Loading ring)
### PEASYMODERNPROGRESSRING __cdecl EasyWinModernCtrl_CreateProgressring(LPCWSTR controlName);
Create uwp progress ring.\
  *controlName : unique name for uwp control.

  
## Time Picker
### PEASYMODERNTIMEPICKER __cdecl EasyWinModernCtrl_CreateTimePicker(LPCWSTR controlName,LPCWSTR headerText,BOOL use24hours);
Create uwp time picker.\
  *controlName : unique name for uwp control.\
  *headerTitle : Set control header text. This parameter can be NULL.\
  *use24hours : use 24 hours format.

### INT64 __cdecl EasyWinModernCtrl_TimePickerGetSelectedTimeAsSeconds(PEASYMODERNTIMEPICKER pTimePickerInfo);
Get selected time as seconds.

### void __cdecl EasyWinModernCtrl_TimePickerSetTimeUsingSeconds(PEASYMODERNTIMEPICKER pTimePickerInfo, INT64 seconds);
Set time as seconds.

### void __cdecl EasyWinModernCtrl_TimePickerSetValueChangedCallback(PEASYMODERNTIMEPICKER pTimePickerInfo, TEasyWinModernCtrl_TimePickerCallback cb, PVOID userData);
Set time changed callback.\
  *cb : user-defined callback function. (type : 'typedef BOOL(__stdcall* TEasyWinModernCtrl_TimePickerCallback)(INT64 seconds, PVOID userData)')\
  *userData : user-defined data.

### void __cdecl EasyWinModernCtrl_TimePickerEnableControl(PEASYMODERNTIMEPICKER pTimePickerInfo, BOOL enable);
Set enable / disable timepicker.\
if control disabled, control will be 'graying out'.

## Radio button
### PEASYMODERNRADIOBTN __cdecl EasyWinModernCtrl_CreateRadioButton(LPCWSTR groupName, LPCWSTR headerText, BOOL useVerticalMode);
Create radio button group.\
  *groupName : unique radio button group name.\
  *headerText : Set control header text. This parameter can be NULL.\
  *useVerticalMode : Add radio buttons to vertical.\
  Normal Mode\
  ![image](https://user-images.githubusercontent.com/12496720/127257222-e728a05e-77a9-4a53-a137-fdadcf93f852.png)\
  Vertical Mode\
  ![image](https://user-images.githubusercontent.com/12496720/127257288-8401a58f-cc5d-4170-be9b-d0778bbcf8d3.png)

 
### void __cdecl EasyWinModernCtrl_RadioBtnInsertItem(PEASYMODERNRADIOBTN pRadioBtn,DWORD idx, LPCWSTR text, BOOL defaultChecked, BOOL enabled);
Insert radio button at group.\
  *idx : radio button index. starts with 0.\
  *text : radio button text.\
  *defaultChecked : if 'TRUE' radio button will checked default.\
  *enabled : if 'FALSE' radio button will disabled.
  
### DWORD __cdecl EasyWinModernCtrl_RadioBtnGetCheckedItem(PEASYMODERNRADIOBTN pRadioBtn);
Get Selected radio button.\
Returned selected radio button index number.\
If any radio buttons are not selected, will returned MAXDWORD value.

### void __cdecl EasyWinModernCtrl_RadioBtnSetCheckedItem(PEASYMODERNRADIOBTN pRadioBtn, DWORD idx);
Set radio button selected.\
  *idx : radio button index number which you want to select.\
  
### void  EasyWinModernCtrl_RadioBtnSetValueChangedCallback(PEASYMODERNRADIOBTN pRadioBtn, TEasyWinModernCtrl_RadioBtnCallback cb,PVOID userData);
Set radio button select changed callback.\
  *cb : user-defined callback function (type 'typedef BOOL(__stdcall* TEasyWinModernCtrl_RadioBtnCallback)(LPCWSTR groupName, DWORD selectedIdx, PVOID userData)')\
  *userData : user-defined data.
  
## Calendar Date Picker
### PEASYMODERNCALENDARDATEPICKER __cdecl EasyWinModernCtrl_CreateCalendarDatePicker(LPCWSTR controlName,LPCWSTR headerText);
Create uwp calendar date picker.\
  *controlName : unique name for uwp control.\
  *headerTitle : Set control header text. This parameter can be NULL.
  
### BOOL __cdecl EasyWinModernCtrl_CalendarDatePickerGetSelectedDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker,PFILETIME pSelectedTime);
Get selected date.\
if user select date, function will return 'TRUE' and 'pSelectedTime' will has selected date.\
if user does not select date, function will return 'FALSE'

### void __cdecl EasyWinModernCtrl_CalendarDatePickerSetDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date);
Set date.\
  *date : date data if you want to set at calendar.

### void __cdecl EasyWinModernCtrl_CalendarDatePickerSetMinDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date);
Set minimum date at calendar.\
If you set minimum date, user cannot select date before minimum date.

### void __cdecl EasyWinModernCtrl_CalendarDatePickerSetMaxDate(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, FILETIME date);
Set maximum date at calendar.\
If you set maximum date, user cannot select date after maximum date.

### void __cdecl EasyWinModernCtrl_CalendarDatePickerSetSelectedDateCallback(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, TEasyWinModernCtrl_CalendarDatePickerCallback cb, PVOID userData);
Set date changed callback function.\
  *cb : user-defined callback function (type 'typedef BOOL(__stdcall* TEasyWinModernCtrl_CalendarDatePickerCallback)(FILETIME selectedDate, PVOID userData)')\
  *userData : user-defined data.
  
### declspec(dllexport) void __cdecl EasyWinModernCtrl_CalendarDatePickerEnableControl(PEASYMODERNCALENDARDATEPICKER pCalendarDatePicker, BOOL enable);
Set enable / disable datepicker.\
if control disabled, control will be 'graying out'.


