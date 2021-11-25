#include <windows.h>

#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::IO;

public ref class FileManager {

	/// <summary>Конструктор класса FileManager.</summary>
	public: FileManager() {
		needSave = false;
		isOpen = false;
		fileName = L"Безымянный.png";
		filePath = L"";
		saveFileDialog = gcnew SaveFileDialog();
		openFileDialog = gcnew OpenFileDialog();
		bmp = gcnew Bitmap(1, 1);
	}

	public: FileManager(int width, int height) {
		needSave = false;
		isOpen = false;
		fileName = L"Безымянный.png";
		filePath = L"";
		saveFileDialog = gcnew SaveFileDialog();
		openFileDialog = gcnew OpenFileDialog();
		bmp = gcnew Bitmap(width, height);
	}

	/// <summary>Потребность файла в сохранении.</summary>
	private: bool needSave;

	/// <summary>Открыт существующий файл.</summary>
	private: bool isOpen;

	/// <summary>Имя файла.</summary>
	private: String ^fileName;

	/// <summary>Путь к файлу.</summary>
	private: String ^filePath;

	private: SaveFileDialog^ saveFileDialog;

	private: OpenFileDialog^ openFileDialog;

	private: Bitmap ^bmp;

	public: bool isNeedSave();

	public: Void setNeedSave(bool state);

	public: Bitmap^ getBmp();

	/// <summary>
	/// Сохранение в файл.
	/// </summary>
	/// <param name="img">Сохраняемое изображение.</param>
	public: bool save(Image ^img);

	/// <summary>
	/// Сохранение в файл с созданием нового файла.
	/// </summary>
	/// <param name="img">Сохраняемое изображение.</param>
	public: bool saveAs(Image ^img);

	/// <summary>
	/// Чтение изображения из файла.
	/// </summary>
	/// <returns>
	/// true, если изображение прочитано успешно.
	/// false, если возникли ошибки при чтении.
	/// </returns>
	public: bool open();

	/// <returns>
	///	Имя файла.
	/// </returns>
	public: String^ getFileName();

	/// <returns>
	///	Путь к файлу.
	/// </returns>
	public: String^ getFilePath();
};

