// Ve2D.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "FinGe.h"

using namespace Ve2D;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	FinGe^ fp = gcnew FinGe();
	Application::Run(gcnew Form1(fp));
	return 0;
}
