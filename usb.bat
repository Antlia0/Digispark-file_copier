@echo off
setlocal

chcp 65001
set "destFolder=docx"
set "foundDrive="
set "targetLabel=USB-NAME"  :: write the usb name here

:: USB sürücülerini bul ve kontrol et
for %%D in (A B C D E F G H I J K L M N O P Q R S T U V W X Y Z) do (
    vol %%D: 2>nul | find "%targetLabel%" >nul
    if not errorlevel 1 (
        set "usbDrive=%%D:"
        set "foundDrive=true"
        goto :found
    )
)

:found
:: USB sürücüsü bulunduysa devam et
if defined foundDrive (
    echo USB sürücüsü bulundu: %usbDrive%
    if not exist "%usbDrive%\%destFolder%" (
        mkdir "%usbDrive%\%destFolder%"
    )
    for /r "C:\" %%f in (*.docx) do (
        xcopy "%%f" "%usbDrive%\%destFolder%\" /y
    )
) else (
    echo USB sürücüsü bulunamadı.
)

endlocal
pause
  
