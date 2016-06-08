// BEOPS.cpp : main project file.

#include "stdafx.h"
#include "frmMainMenu.h"
#include "frmReports.h"
#include "BEOPSGlobals.h"


using namespace BEOPS;

[STAThreadAttribute]
int main(array<System::String ^> ^args)

{

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew frmMainMenu());
	return 0;

}
