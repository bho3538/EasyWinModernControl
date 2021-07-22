# EasyWinModernControl

Easy UWP Modern Control in plain win32 program. (C/C++)

![image](https://user-images.githubusercontent.com/12496720/126588737-32817b55-bb49-46a8-956c-12fff14413e5.png)

## Supported Control
Textbox\
Password box\
Button\
Slider\
Time Picker

## How to use
1.Download pre-compiled dll files and link it.\
2.You should add manifest file in your program like this.
```xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <compatibility xmlns="urn:schemas-microsoft-com:compatibility.v1">
    <application>
      <maxversiontested Id="10.0.18362.0"/>
      <supportedOS Id="{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}" />
    </application>
  </compatibility>
</assembly>
```

## Supported OS
Windows 10 RS5 +

If your program need support old windows version, check support status in runtime and both old (win32 control or etc) and modern controls can be used.\
For example, if you want to create button in Windows 10 RS5 or higher version, 'EasyWinModernCtrl_IsSystemSupport()' will returned 'TRUE'.\
And you can use 'EasyWinModernCtrl_CreateButton()' to create UWP button.\
Otherwise (like Windows 7 or ~Windows 10 RS4) Your program need using classic win32 button.\

![not_support](https://user-images.githubusercontent.com/12496720/126590113-7c87cb45-3627-4b3d-b17c-2fefe8d09974.png)

Like this picture, Using this library does not mean that it cannot run on old version OS.

##License : MIT
