#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace opencvApp5;

[STAThreadAttribute]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	opencvApp5::MyForm form;
	Application::Run(%form);
}