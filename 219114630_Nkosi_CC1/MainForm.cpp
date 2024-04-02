#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
int Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	My219114630NkosiCC1::MainForm form;
	Application::Run(% form);
	return 0;
}

