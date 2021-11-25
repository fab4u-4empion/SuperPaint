#pragma once

#include <windows.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Printing;
using namespace System::Windows::Forms;

ref class DocumentPrinter {
	public: DocumentPrinter() {
		printDialog = gcnew PrintDialog();
		document = gcnew PrintDocument();
		pageSetupDialog = gcnew PageSetupDialog();
		pageSetupDialog->Document = document;
		printDialog->Document = document;
		printDialog->UseEXDialog = true;
		pageSetupDialog->EnableMetric = true;
		document->PrintPage += gcnew PrintPageEventHandler(this, &DocumentPrinter::document_PrintPage);
		pageSetupDialog->PageSettings->Margins = gcnew Margins(50, 50, 50, 50);
	}

	protected: ~DocumentPrinter() {

	}

	private: PrintDialog ^printDialog;
	private: PrintDocument ^document;
	private: PageSetupDialog ^pageSetupDialog;
	private: Image^ img;

	private: Void document_PrintPage(System::Object ^sender, PrintPageEventArgs ^e);

	/// <summary>
	/// ������ �����������
	/// </summary>
	/// <param name="img">�����������, ������������ �� ������</param>
	public: Void print(Image^ img);

	/// <summary>
	/// �������� ���� ��������� ���������� ��������
	/// </summary>
	public: Void openPageSettingsDialog();
};

