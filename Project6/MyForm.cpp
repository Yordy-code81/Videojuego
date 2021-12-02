#include "MyForm.h"

using namespace System;
using namespace Windows::Forms;

void main(array<String^>^arg) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew Project6::MyForm());
}