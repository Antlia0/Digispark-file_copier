Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objDrive = objFSO.GetDrive(objFSO.GetDriveName(WScript.ScriptFullName))
strDriveLetter = objDrive.DriveLetter

Set WshShell = CreateObject("WScript.Shell")
strCommand = Chr(34) & strDriveLetter & ":\usb.bat" & Chr(34)
WshShell.Run strCommand, 0, False
