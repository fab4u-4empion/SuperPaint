#pragma once

namespace SuperPaint {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для NewFile
	/// </summary>
	public ref class NewFile : public System::Windows::Forms::Form
	{
	public:
		NewFile(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NewFile()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

	public: int width;

	public:

	public: int height;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ CancelBTN;


	private: System::Windows::Forms::Button^ CreateBTN;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MaskedTextBox^ heightTextBox;
	private: System::Windows::Forms::MaskedTextBox^ widthTextBox;
	private: System::Windows::Forms::Label^ label2;



	public:
	public: bool isCreated = false;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewFile::typeid));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->heightTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->widthTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->CancelBTN = (gcnew System::Windows::Forms::Button());
			this->CreateBTN = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->heightTextBox);
			this->groupBox1->Controls->Add(this->widthTextBox);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Roboto", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(266, 130);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Размер";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(6, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"По вертикали";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(6, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"По горизонтали";
			// 
			// heightTextBox
			// 
			this->heightTextBox->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->heightTextBox->Location = System::Drawing::Point(150, 76);
			this->heightTextBox->Mask = L"0000";
			this->heightTextBox->Name = L"heightTextBox";
			this->heightTextBox->Size = System::Drawing::Size(100, 28);
			this->heightTextBox->TabIndex = 1;
			// 
			// widthTextBox
			// 
			this->widthTextBox->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->widthTextBox->Location = System::Drawing::Point(150, 25);
			this->widthTextBox->Mask = L"0000";
			this->widthTextBox->Name = L"widthTextBox";
			this->widthTextBox->Size = System::Drawing::Size(100, 28);
			this->widthTextBox->TabIndex = 0;
			// 
			// CancelBTN
			// 
			this->CancelBTN->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CancelBTN->Location = System::Drawing::Point(163, 148);
			this->CancelBTN->Name = L"CancelBTN";
			this->CancelBTN->Size = System::Drawing::Size(115, 36);
			this->CancelBTN->TabIndex = 2;
			this->CancelBTN->Text = L"Отмена";
			this->CancelBTN->UseVisualStyleBackColor = true;
			this->CancelBTN->Click += gcnew System::EventHandler(this, &NewFile::CancelBTN_Click);
			// 
			// CreateBTN
			// 
			this->CreateBTN->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->CreateBTN->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CreateBTN->Location = System::Drawing::Point(41, 148);
			this->CreateBTN->Name = L"CreateBTN";
			this->CreateBTN->Size = System::Drawing::Size(115, 36);
			this->CreateBTN->TabIndex = 1;
			this->CreateBTN->Text = L"Создать";
			this->CreateBTN->UseVisualStyleBackColor = true;
			this->CreateBTN->UseWaitCursor = true;
			this->CreateBTN->Click += gcnew System::EventHandler(this, &NewFile::CreateBTN_Click);
			// 
			// NewFile
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(292, 197);
			this->Controls->Add(this->CreateBTN);
			this->Controls->Add(this->CancelBTN);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"NewFile";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Новый рисунок";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void CancelBTN_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		private: System::Void CreateBTN_Click(System::Object^ sender, System::EventArgs^ e) {
			int::TryParse(widthTextBox->Text, width);
			int::TryParse(heightTextBox->Text, height);
			if (width > 0 && width <= 2000 && height > 0 && height <= 2000) {
				isCreated = true;
				this->Close();
			} else {
				MessageBox::Show(L"\nВведите допустимое число в диапазоне от 1 до 2000.", L"Новый рисунок", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
};
}
