#include "FileManager.h"

bool FileManager::isNeedSave() {
	return needSave;
}

String^ FileManager::getFileName() {
	return fileName;
}

String^ FileManager::getFilePath() {
	return filePath;
}

bool FileManager::saveAs(Image ^img) {
	saveFileDialog->FileName = fileName;
	String^ fileExtension = Path::GetExtension(saveFileDialog->FileName);
	if (fileExtension == L".png") {
		saveFileDialog->FilterIndex = 1;
	}
	else if (fileExtension == L".jpeg" || fileExtension == L".jpg" || fileExtension == L".jpe" || fileExtension == L".jfif") {
		saveFileDialog->FilterIndex = 2;
	}
	else if (fileExtension == L".bmp" || fileExtension == L".dib") {
		saveFileDialog->FilterIndex = 3;
	}
	else {
		saveFileDialog->FilterIndex = 1;
	}
	saveFileDialog->Filter = L"PNG (*.png)|*.png; | JPEG (*.jpeg,*.jpg,*.jpe,*.jfif)|*.jpeg;*.jpg;*.jpe;*.jfif; | 256-цветный рисунок (*.bmp,*.dib)|*.bmp;*.dib;";
	if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		try {
			if (fileExtension == L".png") {
				img->Save(saveFileDialog->FileName, ImageFormat::Png);
			}
			else if (fileExtension == L".jpeg" || fileExtension == L".jpg" || fileExtension == L".jpe" || fileExtension == L".jfif") {
				img->Save(saveFileDialog->FileName, ImageFormat::Jpeg);
			}
			else if (fileExtension == L".bmp" || fileExtension == L".dib") {
				img->Save(saveFileDialog->FileName, ImageFormat::Bmp);
			}
			else {
				img->Save(saveFileDialog->FileName, ImageFormat::Png);
			}
			fileName = Path::GetFileName(saveFileDialog->FileName);
			filePath = saveFileDialog->FileName;
			needSave = false;
			isOpen = true;
			return true;
		} catch (...) {
			MessageBox::Show(L"Нет доступа к файлу \"" + saveFileDialog->FileName + L"\"", L"Сохранение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	return false;
}

bool FileManager::save(Image ^img) {
	if (isOpen) {
		try {
			String^ fileExtension = Path::GetExtension(filePath);
			if (fileExtension == L".png") {
				img->Save(filePath, ImageFormat::Png);
			}
			else if (fileExtension == L".jpeg" || fileExtension == L".jpg" || fileExtension == L".jpe" || fileExtension == L".jfif") {
				img->Save(filePath, ImageFormat::Jpeg);
			}
			else if (fileExtension == L".bmp" || fileExtension == L".dib") {
				img->Save(filePath, ImageFormat::Bmp);
			}
			else {
				img->Save(filePath, ImageFormat::Png);
			}
			needSave = false;
			isOpen = true;
			return true;
		} catch (...) {
			MessageBox::Show(L"Нет доступа к файлу \"" + filePath + L"\"", L"Сохранение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	} else {
		return saveAs(img);
	}
	return false;
}

bool FileManager::open() {
	openFileDialog->FileName = L"";
	FileStream^ fileStream;
	openFileDialog->Filter = L"Все файлы изображений (*.png, *.jpeg, *.jpg, *.jpe, *.jfif, *.bmp, *.dib;)|*.png;*.jpeg;*.jpg;*.jpe;*.jfif;*.bmp;*.dib; | PNG (*.png)|*.png; | JPEG (*.jpeg, *.jpg, *.jpe, *.jfif)|*.jpeg;*.jpg;*.jpe;*.jfif; | 256-цветный рисунок (*.bmp, *.dib)|*.bmp;*.dib;";
	if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		try {
			fileStream = File::OpenRead(openFileDialog->FileName);
			bmp = gcnew Bitmap(fileStream);
			fileStream->Close();
			if (bmp->Width <= 2000 && bmp->Height <= 2000) {
				fileName = Path::GetFileName(openFileDialog->FileName);
				filePath = openFileDialog->FileName;
				needSave = false;
				isOpen = true;
				return true;
			} else {
				MessageBox::Show(L"" + openFileDialog->FileName + L"\nНе удается открыть файл. \nРисунок слишком большой. \nМаксимальный формат 2000 на 2000 точек.", L"Открытие", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return false;
			}
		} catch (...) {
			fileStream->Close();
			MessageBox::Show(L"" + openFileDialog->FileName + L"\nНе удается прочитать файл. \nФайл не является правильным точечным рисунком (BMP), или этот формат не поддерживается.", L"Открытие", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return false;
		}
	}
	return false;
}

Void FileManager::setNeedSave(bool state) {
	needSave = state;
}

Bitmap^ FileManager::getBmp() {
	return bmp;
}