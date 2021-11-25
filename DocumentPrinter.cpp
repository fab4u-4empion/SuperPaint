#include "DocumentPrinter.h"
#include <math.h>

Void DocumentPrinter::print(Image ^img) {
	if (printDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		this->img = (Image^) img->Clone();
		document->Print();
	}
}

Void DocumentPrinter::document_PrintPage(System::Object^ sender, PrintPageEventArgs^ e) {
	int width = 100;
	int height = 100;
	int maxWidth = e->PageBounds.Width - e->PageSettings->Margins->Left - e->PageSettings->Margins->Right;
	int maxHeight = e->PageBounds.Height - e->PageSettings->Margins->Top - e->PageSettings->Margins->Bottom;
	width = maxWidth;
	double k = static_cast<double>(maxWidth) / img->Width;
	height = round(k * img->Height);
	if (height >maxHeight) {
		height = maxHeight;
		double k = static_cast<double>(maxHeight) / img->Height;
		width = round(k * img->Width);
	}
	e->Graphics->DrawImage(img, e->PageSettings->Margins->Top, e->PageSettings->Margins->Left, width, height);
}

Void DocumentPrinter::openPageSettingsDialog() {
	pageSetupDialog->ShowDialog();
}