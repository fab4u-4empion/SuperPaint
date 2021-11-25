#include <cstdlib>
#include <time.h>
#include <math.h>
#include "History.h"
#include "FileManager.h"
#include <iostream>
#include <windows.h>
#include "InfoForm.h"
#include "NewFile.h"
#include "DocumentPrinter.h"

#define PI 3.1415926535

#pragma once

namespace SuperPaint {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form {
		public:
			MainForm(void) {
				InitializeComponent();
			}

		protected:
			/// <summary>
			/// Освободить все используемые ресурсы.
			/// </summary>
			~MainForm() {
				if (components)
				{
					delete components;
				}
			}

		private: DocumentPrinter ^printer; 
		private: Graphics ^Painter;
		private: FileManager ^file;
		private: Graphics ^gBrushWidth;
		private: Graphics ^tempPainter;
		private: Bitmap ^tempBMP;
		private: Bitmap ^bmp;
		private: Bitmap ^BrushWidthBMP;
		private: History^ history;
		private: SolidBrush^ brush;
		private: Pen^ pen;
		private: Drawing::Size^ rectangleSize;
		private: Point^ recStart;
		private: Point^ recEnd;
		private: enum class Tools {
			Brush,
			Spray,
			Pipette,
			Eraser,
			Fill,
			Line,
			Ellipse,
			Rectangle
		};
		private: Tools CurrentTool = Tools::Brush;
		private: int StartX;
		private: int StartY;
		private: int BrushWidth = 10;
		private: Color BrushColor = Color::Black;
		private: bool withFill = false;
		private: System::Windows::Forms::PictureBox^ Canvas;
		private: System::Windows::Forms::ColorDialog^ colorDialog1;
		private: System::Windows::Forms::Button^ CurrentColorBtn;
		private: System::Windows::Forms::Button^ ColorBtn_1;
		private: System::Windows::Forms::Panel^ panel1;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Panel^ panel2;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Panel^ panel3;
		private: System::Windows::Forms::Button^ ColorBtn_2;
		private: System::Windows::Forms::Button^ ColorBtn_20;
		private: System::Windows::Forms::Button^ ColorBtn_19;
		private: System::Windows::Forms::Button^ ColorBtn_18;
		private: System::Windows::Forms::Button^ ColorBtn_17;
		private: System::Windows::Forms::Button^ ColorBtn_16;
		private: System::Windows::Forms::Button^ ColorBtn_15;
		private: System::Windows::Forms::Button^ ColorBtn_14;
		private: System::Windows::Forms::Button^ ColorBtn_13;
		private: System::Windows::Forms::Button^ ColorBtn_12;
		private: System::Windows::Forms::Button^ ColorBtn_11;
		private: System::Windows::Forms::Button^ ColorBtn_10;
		private: System::Windows::Forms::Button^ ColorBtn_9;
		private: System::Windows::Forms::Button^ ColorBtn_8;
		private: System::Windows::Forms::Button^ ColorBtn_7;
		private: System::Windows::Forms::Button^ ColorBtn_6;
		private: System::Windows::Forms::Button^ ColorBtn_5;
		private: System::Windows::Forms::Button^ ColorBtn_4;
		private: System::Windows::Forms::Button^ ColorBtn_3;
		private: System::Windows::Forms::ToolStripMenuItem^ History_Back;
		private: System::Windows::Forms::MenuStrip^ menuStrip1;
		private: System::Windows::Forms::Panel^ panel4;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TrackBar^ BrushWidthTrack;
		private: System::Windows::Forms::Panel^ BrushWidth_Panel;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::PictureBox^ BrushWidthType;
		private: System::Windows::Forms::Panel^ panel6;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::NumericUpDown^ BrushWidthUpDown;
		private: System::Windows::Forms::Panel^ panel7;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Button^ Ellipse_BTN;
		private: System::Windows::Forms::Button^ Rectangle_BTN;
		private: System::Windows::Forms::Button^ Line_BTN;
		private: System::Windows::Forms::Button^ Fill_BTN;
		private: System::Windows::Forms::Button^ Eraser_BTN;
		private: System::Windows::Forms::Button^ Pipette_BTN;
		private: System::Windows::Forms::Button^ Spray_BTN;
		private: System::Windows::Forms::Button^ Brush_BTN;
		private: System::Windows::Forms::Timer^ Spray_down;
		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::ToolTip^ toolTip1;
		private: System::Windows::Forms::Panel^ Fill_Panel;
		private: System::Windows::Forms::RadioButton^ With_Fill_BTN;
		private: System::Windows::Forms::RadioButton^ Without_Fill_BTN;
		private: System::Windows::Forms::ToolStripMenuItem^ History_Forward;
		private: System::Windows::Forms::ToolStripMenuItem^ File_BTN;
		private: System::Windows::Forms::ToolStripMenuItem^ SaveFile_BTN;
		private: System::Windows::Forms::Label^ FileName_Label;
		private: System::Windows::Forms::ToolStripMenuItem^ Save_BTN;
		private: System::Windows::Forms::ToolStripMenuItem^ OpenFile_BTN;
		private: System::Windows::Forms::Panel^ CanvasPanel;

		private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
		private: System::Windows::Forms::ToolStripMenuItem^ AboutToolStripMenuItem;

		private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
		private: System::Windows::Forms::ToolStripMenuItem^ ExitToolStripMenuItem;

		private: System::Windows::Forms::ToolStripMenuItem^ NewToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ PrintToolStripMenuItem;
		private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
		private: System::Windows::Forms::ToolStripMenuItem^ PrinterToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ PageParamToolStripMenuItem;



		private: System::ComponentModel::IContainer^ components;

		protected:

		private:
			/// <summary>
			/// Обязательная переменная конструктора.
			/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->Canvas = (gcnew System::Windows::Forms::PictureBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->CurrentColorBtn = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->ColorBtn_20 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_19 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_18 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_17 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_16 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_15 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_14 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_13 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_12 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_11 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_10 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_9 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_8 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_7 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_6 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_5 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_4 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_3 = (gcnew System::Windows::Forms::Button());
			this->ColorBtn_2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->History_Back = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->File_BTN = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenFile_BTN = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Save_BTN = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveFile_BTN = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->PrintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PrinterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PageParamToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->AboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ExitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->History_Forward = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BrushWidthTrack = (gcnew System::Windows::Forms::TrackBar());
			this->BrushWidth_Panel = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->BrushWidthUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->BrushWidthType = (gcnew System::Windows::Forms::PictureBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->Ellipse_BTN = (gcnew System::Windows::Forms::Button());
			this->Rectangle_BTN = (gcnew System::Windows::Forms::Button());
			this->Line_BTN = (gcnew System::Windows::Forms::Button());
			this->Fill_BTN = (gcnew System::Windows::Forms::Button());
			this->Eraser_BTN = (gcnew System::Windows::Forms::Button());
			this->Pipette_BTN = (gcnew System::Windows::Forms::Button());
			this->Spray_BTN = (gcnew System::Windows::Forms::Button());
			this->Brush_BTN = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Spray_down = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->Fill_Panel = (gcnew System::Windows::Forms::Panel());
			this->With_Fill_BTN = (gcnew System::Windows::Forms::RadioButton());
			this->Without_Fill_BTN = (gcnew System::Windows::Forms::RadioButton());
			this->FileName_Label = (gcnew System::Windows::Forms::Label());
			this->CanvasPanel = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Canvas))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BrushWidthTrack))->BeginInit();
			this->BrushWidth_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BrushWidthUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BrushWidthType))->BeginInit();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->Fill_Panel->SuspendLayout();
			this->CanvasPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// Canvas
			// 
			this->Canvas->BackColor = System::Drawing::SystemColors::Window;
			this->Canvas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Canvas->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Canvas->Location = System::Drawing::Point(0, 0);
			this->Canvas->Name = L"Canvas";
			this->Canvas->Size = System::Drawing::Size(1334, 571);
			this->Canvas->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Canvas->TabIndex = 0;
			this->Canvas->TabStop = false;
			this->Canvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::Canvas_MouseDown);
			this->Canvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::Canvas_MouseMove);
			this->Canvas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::Canvas_MouseUp);
			// 
			// CurrentColorBtn
			// 
			this->CurrentColorBtn->BackColor = System::Drawing::Color::Black;
			this->CurrentColorBtn->Enabled = false;
			this->CurrentColorBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->CurrentColorBtn->Location = System::Drawing::Point(11, 3);
			this->CurrentColorBtn->Name = L"CurrentColorBtn";
			this->CurrentColorBtn->Size = System::Drawing::Size(50, 50);
			this->CurrentColorBtn->TabIndex = 1;
			this->CurrentColorBtn->UseVisualStyleBackColor = false;
			// 
			// ColorBtn_1
			// 
			this->ColorBtn_1->BackColor = System::Drawing::Color::Black;
			this->ColorBtn_1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_1->Location = System::Drawing::Point(14, 13);
			this->ColorBtn_1->Name = L"ColorBtn_1";
			this->ColorBtn_1->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_1->TabIndex = 2;
			this->ColorBtn_1->UseVisualStyleBackColor = false;
			this->ColorBtn_1->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(777, 44);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(569, 130);
			this->panel1->TabIndex = 3;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel4->Controls->Add(this->button1);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Location = System::Drawing::Point(482, 14);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(72, 104);
			this->panel4->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->button1->ImageKey = L"(отсутствует)";
			this->button1->Location = System::Drawing::Point(11, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 50);
			this->button1->TabIndex = 22;
			this->toolTip1->SetToolTip(this->button1, L"Изменение цветов\r\n\r\nВыбор цвета в палитре");
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_More_Click);
			// 
			// label2
			// 
			this->label2->AutoEllipsis = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Roboto", 10));
			this->label2->Location = System::Drawing::Point(0, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 48);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Другие цвета";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel3->Controls->Add(this->ColorBtn_20);
			this->panel3->Controls->Add(this->ColorBtn_19);
			this->panel3->Controls->Add(this->ColorBtn_18);
			this->panel3->Controls->Add(this->ColorBtn_17);
			this->panel3->Controls->Add(this->ColorBtn_16);
			this->panel3->Controls->Add(this->ColorBtn_15);
			this->panel3->Controls->Add(this->ColorBtn_14);
			this->panel3->Controls->Add(this->ColorBtn_13);
			this->panel3->Controls->Add(this->ColorBtn_12);
			this->panel3->Controls->Add(this->ColorBtn_11);
			this->panel3->Controls->Add(this->ColorBtn_10);
			this->panel3->Controls->Add(this->ColorBtn_9);
			this->panel3->Controls->Add(this->ColorBtn_8);
			this->panel3->Controls->Add(this->ColorBtn_7);
			this->panel3->Controls->Add(this->ColorBtn_6);
			this->panel3->Controls->Add(this->ColorBtn_5);
			this->panel3->Controls->Add(this->ColorBtn_4);
			this->panel3->Controls->Add(this->ColorBtn_3);
			this->panel3->Controls->Add(this->ColorBtn_2);
			this->panel3->Controls->Add(this->ColorBtn_1);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Location = System::Drawing::Point(92, 14);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(384, 104);
			this->panel3->TabIndex = 3;
			// 
			// ColorBtn_20
			// 
			this->ColorBtn_20->BackColor = System::Drawing::Color::Plum;
			this->ColorBtn_20->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_20->Location = System::Drawing::Point(338, 49);
			this->ColorBtn_20->Name = L"ColorBtn_20";
			this->ColorBtn_20->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_20->TabIndex = 21;
			this->ColorBtn_20->UseVisualStyleBackColor = false;
			this->ColorBtn_20->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_20_Click);
			// 
			// ColorBtn_19
			// 
			this->ColorBtn_19->BackColor = System::Drawing::Color::MediumPurple;
			this->ColorBtn_19->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_19->Location = System::Drawing::Point(338, 13);
			this->ColorBtn_19->Name = L"ColorBtn_19";
			this->ColorBtn_19->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_19->TabIndex = 20;
			this->ColorBtn_19->UseVisualStyleBackColor = false;
			this->ColorBtn_19->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_19_Click);
			// 
			// ColorBtn_18
			// 
			this->ColorBtn_18->BackColor = System::Drawing::Color::CornflowerBlue;
			this->ColorBtn_18->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_18->Location = System::Drawing::Point(302, 49);
			this->ColorBtn_18->Name = L"ColorBtn_18";
			this->ColorBtn_18->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_18->TabIndex = 19;
			this->ColorBtn_18->UseVisualStyleBackColor = false;
			this->ColorBtn_18->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_18_Click);
			// 
			// ColorBtn_17
			// 
			this->ColorBtn_17->BackColor = System::Drawing::Color::Blue;
			this->ColorBtn_17->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_17->Location = System::Drawing::Point(302, 13);
			this->ColorBtn_17->Name = L"ColorBtn_17";
			this->ColorBtn_17->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_17->TabIndex = 18;
			this->ColorBtn_17->UseVisualStyleBackColor = false;
			this->ColorBtn_17->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_17_Click);
			// 
			// ColorBtn_16
			// 
			this->ColorBtn_16->BackColor = System::Drawing::Color::LightSkyBlue;
			this->ColorBtn_16->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->ColorBtn_16->Location = System::Drawing::Point(266, 49);
			this->ColorBtn_16->Name = L"ColorBtn_16";
			this->ColorBtn_16->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_16->TabIndex = 17;
			this->ColorBtn_16->UseVisualStyleBackColor = false;
			this->ColorBtn_16->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_16_Click);
			// 
			// ColorBtn_15
			// 
			this->ColorBtn_15->BackColor = System::Drawing::Color::DodgerBlue;
			this->ColorBtn_15->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_15->Location = System::Drawing::Point(266, 13);
			this->ColorBtn_15->Name = L"ColorBtn_15";
			this->ColorBtn_15->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_15->TabIndex = 16;
			this->ColorBtn_15->UseVisualStyleBackColor = false;
			this->ColorBtn_15->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_15_Click);
			// 
			// ColorBtn_14
			// 
			this->ColorBtn_14->BackColor = System::Drawing::Color::LawnGreen;
			this->ColorBtn_14->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_14->Location = System::Drawing::Point(230, 49);
			this->ColorBtn_14->Name = L"ColorBtn_14";
			this->ColorBtn_14->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_14->TabIndex = 15;
			this->ColorBtn_14->UseVisualStyleBackColor = false;
			this->ColorBtn_14->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_14_Click);
			// 
			// ColorBtn_13
			// 
			this->ColorBtn_13->BackColor = System::Drawing::Color::Green;
			this->ColorBtn_13->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_13->Location = System::Drawing::Point(230, 13);
			this->ColorBtn_13->Name = L"ColorBtn_13";
			this->ColorBtn_13->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_13->TabIndex = 14;
			this->ColorBtn_13->UseVisualStyleBackColor = false;
			this->ColorBtn_13->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_13_Click);
			// 
			// ColorBtn_12
			// 
			this->ColorBtn_12->BackColor = System::Drawing::Color::LemonChiffon;
			this->ColorBtn_12->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_12->Location = System::Drawing::Point(194, 49);
			this->ColorBtn_12->Name = L"ColorBtn_12";
			this->ColorBtn_12->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_12->TabIndex = 13;
			this->ColorBtn_12->UseVisualStyleBackColor = false;
			this->ColorBtn_12->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_12_Click);
			// 
			// ColorBtn_11
			// 
			this->ColorBtn_11->BackColor = System::Drawing::Color::Yellow;
			this->ColorBtn_11->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_11->Location = System::Drawing::Point(194, 13);
			this->ColorBtn_11->Name = L"ColorBtn_11";
			this->ColorBtn_11->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_11->TabIndex = 12;
			this->ColorBtn_11->UseVisualStyleBackColor = false;
			this->ColorBtn_11->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_11_Click);
			// 
			// ColorBtn_10
			// 
			this->ColorBtn_10->BackColor = System::Drawing::Color::Gold;
			this->ColorBtn_10->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_10->Location = System::Drawing::Point(158, 49);
			this->ColorBtn_10->Name = L"ColorBtn_10";
			this->ColorBtn_10->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_10->TabIndex = 11;
			this->ColorBtn_10->UseVisualStyleBackColor = false;
			this->ColorBtn_10->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_10_Click);
			// 
			// ColorBtn_9
			// 
			this->ColorBtn_9->BackColor = System::Drawing::Color::Orange;
			this->ColorBtn_9->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_9->Location = System::Drawing::Point(158, 13);
			this->ColorBtn_9->Name = L"ColorBtn_9";
			this->ColorBtn_9->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_9->TabIndex = 10;
			this->ColorBtn_9->UseVisualStyleBackColor = false;
			this->ColorBtn_9->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_9_Click);
			// 
			// ColorBtn_8
			// 
			this->ColorBtn_8->BackColor = System::Drawing::Color::LightCoral;
			this->ColorBtn_8->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_8->Location = System::Drawing::Point(122, 49);
			this->ColorBtn_8->Name = L"ColorBtn_8";
			this->ColorBtn_8->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_8->TabIndex = 9;
			this->ColorBtn_8->UseVisualStyleBackColor = false;
			this->ColorBtn_8->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_8_Click);
			// 
			// ColorBtn_7
			// 
			this->ColorBtn_7->BackColor = System::Drawing::Color::Red;
			this->ColorBtn_7->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_7->Location = System::Drawing::Point(122, 13);
			this->ColorBtn_7->Name = L"ColorBtn_7";
			this->ColorBtn_7->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_7->TabIndex = 8;
			this->ColorBtn_7->UseVisualStyleBackColor = false;
			this->ColorBtn_7->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_7_Click);
			// 
			// ColorBtn_6
			// 
			this->ColorBtn_6->BackColor = System::Drawing::Color::Chocolate;
			this->ColorBtn_6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_6->Location = System::Drawing::Point(86, 49);
			this->ColorBtn_6->Name = L"ColorBtn_6";
			this->ColorBtn_6->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_6->TabIndex = 7;
			this->ColorBtn_6->UseVisualStyleBackColor = false;
			this->ColorBtn_6->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_6_Click);
			// 
			// ColorBtn_5
			// 
			this->ColorBtn_5->BackColor = System::Drawing::Color::DarkRed;
			this->ColorBtn_5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_5->Location = System::Drawing::Point(86, 13);
			this->ColorBtn_5->Name = L"ColorBtn_5";
			this->ColorBtn_5->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_5->TabIndex = 6;
			this->ColorBtn_5->UseVisualStyleBackColor = false;
			this->ColorBtn_5->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_5_Click);
			// 
			// ColorBtn_4
			// 
			this->ColorBtn_4->BackColor = System::Drawing::Color::Silver;
			this->ColorBtn_4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_4->Location = System::Drawing::Point(50, 49);
			this->ColorBtn_4->Name = L"ColorBtn_4";
			this->ColorBtn_4->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_4->TabIndex = 5;
			this->ColorBtn_4->UseVisualStyleBackColor = false;
			this->ColorBtn_4->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_4_Click);
			// 
			// ColorBtn_3
			// 
			this->ColorBtn_3->BackColor = System::Drawing::Color::DimGray;
			this->ColorBtn_3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_3->Location = System::Drawing::Point(50, 13);
			this->ColorBtn_3->Name = L"ColorBtn_3";
			this->ColorBtn_3->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_3->TabIndex = 4;
			this->ColorBtn_3->UseVisualStyleBackColor = false;
			this->ColorBtn_3->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_3_Click);
			// 
			// ColorBtn_2
			// 
			this->ColorBtn_2->BackColor = System::Drawing::Color::White;
			this->ColorBtn_2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorBtn_2->Location = System::Drawing::Point(14, 49);
			this->ColorBtn_2->Name = L"ColorBtn_2";
			this->ColorBtn_2->Size = System::Drawing::Size(30, 30);
			this->ColorBtn_2->TabIndex = 3;
			this->ColorBtn_2->UseVisualStyleBackColor = false;
			this->ColorBtn_2->Click += gcnew System::EventHandler(this, &MainForm::ColorBtn_2_Click);
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label1->Font = (gcnew System::Drawing::Font(L"Roboto", 10));
			this->label1->Location = System::Drawing::Point(0, 84);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(384, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Палитра";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel2->Controls->Add(this->CurrentColorBtn);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(14, 14);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(72, 104);
			this->panel2->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoEllipsis = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Roboto", 10));
			this->label3->Location = System::Drawing::Point(0, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 48);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Текущий цвет";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// History_Back
			// 
			this->History_Back->Enabled = false;
			this->History_Back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"History_Back.Image")));
			this->History_Back->Name = L"History_Back";
			this->History_Back->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->History_Back->Size = System::Drawing::Size(34, 24);
			this->History_Back->ToolTipText = L"Отменить (CTRL + Z)\r\n\r\nОтмена последнего действия\r\n";
			this->History_Back->Click += gcnew System::EventHandler(this, &MainForm::History_Back_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->File_BTN, this->History_Back,
					this->History_Forward
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1361, 28);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// File_BTN
			// 
			this->File_BTN->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->NewToolStripMenuItem,
					this->OpenFile_BTN, this->Save_BTN, this->SaveFile_BTN, this->toolStripSeparator3, this->PrintToolStripMenuItem, this->toolStripSeparator1,
					this->AboutToolStripMenuItem, this->toolStripSeparator2, this->ExitToolStripMenuItem
			});
			this->File_BTN->Name = L"File_BTN";
			this->File_BTN->Size = System::Drawing::Size(59, 24);
			this->File_BTN->Text = L"Файл";
			// 
			// NewToolStripMenuItem
			// 
			this->NewToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"NewToolStripMenuItem.Image")));
			this->NewToolStripMenuItem->Name = L"NewToolStripMenuItem";
			this->NewToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->NewToolStripMenuItem->Size = System::Drawing::Size(291, 26);
			this->NewToolStripMenuItem->Text = L"Создать";
			this->NewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::NewToolStripMenuItem_Click);
			// 
			// OpenFile_BTN
			// 
			this->OpenFile_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"OpenFile_BTN.Image")));
			this->OpenFile_BTN->Name = L"OpenFile_BTN";
			this->OpenFile_BTN->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->OpenFile_BTN->Size = System::Drawing::Size(291, 26);
			this->OpenFile_BTN->Text = L"Открыть";
			this->OpenFile_BTN->Click += gcnew System::EventHandler(this, &MainForm::OpenFile_BTN_Click);
			// 
			// Save_BTN
			// 
			this->Save_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Save_BTN.Image")));
			this->Save_BTN->Name = L"Save_BTN";
			this->Save_BTN->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->Save_BTN->Size = System::Drawing::Size(291, 26);
			this->Save_BTN->Text = L"Сохранить";
			this->Save_BTN->Click += gcnew System::EventHandler(this, &MainForm::Save_BTN_Click);
			// 
			// SaveFile_BTN
			// 
			this->SaveFile_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SaveFile_BTN.Image")));
			this->SaveFile_BTN->Name = L"SaveFile_BTN";
			this->SaveFile_BTN->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->SaveFile_BTN->Size = System::Drawing::Size(291, 26);
			this->SaveFile_BTN->Text = L"Сохранить как...";
			this->SaveFile_BTN->Click += gcnew System::EventHandler(this, &MainForm::SaveFile_BTN_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(288, 6);
			// 
			// PrintToolStripMenuItem
			// 
			this->PrintToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->PrinterToolStripMenuItem,
					this->PageParamToolStripMenuItem
			});
			this->PrintToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PrintToolStripMenuItem.Image")));
			this->PrintToolStripMenuItem->Name = L"PrintToolStripMenuItem";
			this->PrintToolStripMenuItem->Size = System::Drawing::Size(291, 26);
			this->PrintToolStripMenuItem->Text = L"Печать";
			// 
			// PrinterToolStripMenuItem
			// 
			this->PrinterToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PrinterToolStripMenuItem.Image")));
			this->PrinterToolStripMenuItem->Name = L"PrinterToolStripMenuItem";
			this->PrinterToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->PrinterToolStripMenuItem->Size = System::Drawing::Size(335, 26);
			this->PrinterToolStripMenuItem->Text = L"Печать";
			this->PrinterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::PrintToolStripMenuItem_Click);
			// 
			// PageParamToolStripMenuItem
			// 
			this->PageParamToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PageParamToolStripMenuItem.Image")));
			this->PageParamToolStripMenuItem->Name = L"PageParamToolStripMenuItem";
			this->PageParamToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::P));
			this->PageParamToolStripMenuItem->Size = System::Drawing::Size(335, 26);
			this->PageParamToolStripMenuItem->Text = L"Параметры страницы";
			this->PageParamToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::PageParamToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(288, 6);
			// 
			// AboutToolStripMenuItem
			// 
			this->AboutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AboutToolStripMenuItem.Image")));
			this->AboutToolStripMenuItem->Name = L"AboutToolStripMenuItem";
			this->AboutToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->AboutToolStripMenuItem->Size = System::Drawing::Size(291, 26);
			this->AboutToolStripMenuItem->Text = L"О программе";
			this->AboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::AboutToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(288, 6);
			// 
			// ExitToolStripMenuItem
			// 
			this->ExitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ExitToolStripMenuItem.Image")));
			this->ExitToolStripMenuItem->Name = L"ExitToolStripMenuItem";
			this->ExitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::E));
			this->ExitToolStripMenuItem->Size = System::Drawing::Size(291, 26);
			this->ExitToolStripMenuItem->Text = L"Выход";
			this->ExitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ExitToolStripMenuItem_Click);
			// 
			// History_Forward
			// 
			this->History_Forward->Enabled = false;
			this->History_Forward->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"History_Forward.Image")));
			this->History_Forward->Name = L"History_Forward";
			this->History_Forward->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y));
			this->History_Forward->Size = System::Drawing::Size(34, 24);
			this->History_Forward->ToolTipText = L"Вернуть (CTRL + Y)\r\n\r\nПовтор последнего действия";
			this->History_Forward->Click += gcnew System::EventHandler(this, &MainForm::History_Forward_Click);
			// 
			// BrushWidthTrack
			// 
			this->BrushWidthTrack->BackColor = System::Drawing::SystemColors::ControlLight;
			this->BrushWidthTrack->Location = System::Drawing::Point(0, 3);
			this->BrushWidthTrack->Maximum = 100;
			this->BrushWidthTrack->Minimum = 1;
			this->BrushWidthTrack->Name = L"BrushWidthTrack";
			this->BrushWidthTrack->Size = System::Drawing::Size(200, 56);
			this->BrushWidthTrack->TabIndex = 6;
			this->toolTip1->SetToolTip(this->BrushWidthTrack, L"Толщина\r\n\r\nВыбор ширины для заданного инструмента\r\n");
			this->BrushWidthTrack->Value = 10;
			this->BrushWidthTrack->ValueChanged += gcnew System::EventHandler(this, &MainForm::BrushWidthTrackBar_ValueChanged);
			// 
			// BrushWidth_Panel
			// 
			this->BrushWidth_Panel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->BrushWidth_Panel->Controls->Add(this->label5);
			this->BrushWidth_Panel->Controls->Add(this->BrushWidthUpDown);
			this->BrushWidth_Panel->Controls->Add(this->BrushWidthTrack);
			this->BrushWidth_Panel->Controls->Add(this->label4);
			this->BrushWidth_Panel->Location = System::Drawing::Point(430, 44);
			this->BrushWidth_Panel->Name = L"BrushWidth_Panel";
			this->BrushWidth_Panel->Size = System::Drawing::Size(202, 130);
			this->BrushWidth_Panel->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(1, 51);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(198, 23);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Текущий размер";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// BrushWidthUpDown
			// 
			this->BrushWidthUpDown->Location = System::Drawing::Point(26, 75);
			this->BrushWidthUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->BrushWidthUpDown->Name = L"BrushWidthUpDown";
			this->BrushWidthUpDown->Size = System::Drawing::Size(150, 22);
			this->BrushWidthUpDown->TabIndex = 10;
			this->toolTip1->SetToolTip(this->BrushWidthUpDown, L"Толщина\r\n\r\nВыбор ширины для заданного инструмента");
			this->BrushWidthUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->BrushWidthUpDown->ValueChanged += gcnew System::EventHandler(this, &MainForm::BrushWidthUpDown_ValueChanged);
			// 
			// label4
			// 
			this->label4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label4->Font = (gcnew System::Drawing::Font(L"Roboto", 10));
			this->label4->Location = System::Drawing::Point(0, 110);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(202, 20);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Размер";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// BrushWidthType
			// 
			this->BrushWidthType->BackColor = System::Drawing::SystemColors::Window;
			this->BrushWidthType->Location = System::Drawing::Point(10, 10);
			this->BrushWidthType->Name = L"BrushWidthType";
			this->BrushWidthType->Size = System::Drawing::Size(110, 110);
			this->BrushWidthType->TabIndex = 8;
			this->BrushWidthType->TabStop = false;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel6->Controls->Add(this->BrushWidthType);
			this->panel6->Location = System::Drawing::Point(635, 44);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(130, 130);
			this->panel6->TabIndex = 9;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel7->Controls->Add(this->Ellipse_BTN);
			this->panel7->Controls->Add(this->Rectangle_BTN);
			this->panel7->Controls->Add(this->Line_BTN);
			this->panel7->Controls->Add(this->Fill_BTN);
			this->panel7->Controls->Add(this->Eraser_BTN);
			this->panel7->Controls->Add(this->Pipette_BTN);
			this->panel7->Controls->Add(this->Spray_BTN);
			this->panel7->Controls->Add(this->Brush_BTN);
			this->panel7->Controls->Add(this->label7);
			this->panel7->Location = System::Drawing::Point(12, 44);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(244, 130);
			this->panel7->TabIndex = 24;
			// 
			// Ellipse_BTN
			// 
			this->Ellipse_BTN->BackColor = System::Drawing::Color::Transparent;
			this->Ellipse_BTN->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Ellipse_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Ellipse_BTN.Image")));
			this->Ellipse_BTN->Location = System::Drawing::Point(163, 59);
			this->Ellipse_BTN->Name = L"Ellipse_BTN";
			this->Ellipse_BTN->Size = System::Drawing::Size(35, 35);
			this->Ellipse_BTN->TabIndex = 29;
			this->toolTip1->SetToolTip(this->Ellipse_BTN, L"Овал");
			this->Ellipse_BTN->UseVisualStyleBackColor = false;
			this->Ellipse_BTN->Click += gcnew System::EventHandler(this, &MainForm::Ellipse_BTN_Click);
			// 
			// Rectangle_BTN
			// 
			this->Rectangle_BTN->BackColor = System::Drawing::Color::Transparent;
			this->Rectangle_BTN->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Rectangle_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Rectangle_BTN.Image")));
			this->Rectangle_BTN->Location = System::Drawing::Point(163, 17);
			this->Rectangle_BTN->Name = L"Rectangle_BTN";
			this->Rectangle_BTN->Size = System::Drawing::Size(35, 35);
			this->Rectangle_BTN->TabIndex = 28;
			this->toolTip1->SetToolTip(this->Rectangle_BTN, L"Прямоугольник");
			this->Rectangle_BTN->UseVisualStyleBackColor = false;
			this->Rectangle_BTN->Click += gcnew System::EventHandler(this, &MainForm::Rectangle_BTN_Click);
			// 
			// Line_BTN
			// 
			this->Line_BTN->BackColor = System::Drawing::Color::Transparent;
			this->Line_BTN->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Line_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Line_BTN.Image")));
			this->Line_BTN->Location = System::Drawing::Point(122, 58);
			this->Line_BTN->Name = L"Line_BTN";
			this->Line_BTN->Size = System::Drawing::Size(35, 35);
			this->Line_BTN->TabIndex = 27;
			this->toolTip1->SetToolTip(this->Line_BTN, L"Линия");
			this->Line_BTN->UseVisualStyleBackColor = false;
			this->Line_BTN->Click += gcnew System::EventHandler(this, &MainForm::Line_BTN_Click);
			// 
			// Fill_BTN
			// 
			this->Fill_BTN->BackColor = System::Drawing::Color::Transparent;
			this->Fill_BTN->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Fill_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Fill_BTN.Image")));
			this->Fill_BTN->Location = System::Drawing::Point(122, 17);
			this->Fill_BTN->Name = L"Fill_BTN";
			this->Fill_BTN->Size = System::Drawing::Size(35, 35);
			this->Fill_BTN->TabIndex = 26;
			this->toolTip1->SetToolTip(this->Fill_BTN, L"Заливка цветом\r\n\r\nЩелкните область холста, чтобы залить ее цветом");
			this->Fill_BTN->UseVisualStyleBackColor = false;
			this->Fill_BTN->Click += gcnew System::EventHandler(this, &MainForm::Fill_BTN_Click);
			// 
			// Eraser_BTN
			// 
			this->Eraser_BTN->BackColor = System::Drawing::Color::Transparent;
			this->Eraser_BTN->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Eraser_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Eraser_BTN.Image")));
			this->Eraser_BTN->Location = System::Drawing::Point(81, 58);
			this->Eraser_BTN->Name = L"Eraser_BTN";
			this->Eraser_BTN->Size = System::Drawing::Size(35, 35);
			this->Eraser_BTN->TabIndex = 25;
			this->toolTip1->SetToolTip(this->Eraser_BTN, L"Ластик\r\n\r\nУдаление фрагмента рисунка");
			this->Eraser_BTN->UseVisualStyleBackColor = false;
			this->Eraser_BTN->Click += gcnew System::EventHandler(this, &MainForm::Eraser_BTN_Click);
			// 
			// Pipette_BTN
			// 
			this->Pipette_BTN->BackColor = System::Drawing::Color::Transparent;
			this->Pipette_BTN->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Pipette_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Pipette_BTN.Image")));
			this->Pipette_BTN->Location = System::Drawing::Point(81, 17);
			this->Pipette_BTN->Name = L"Pipette_BTN";
			this->Pipette_BTN->Size = System::Drawing::Size(35, 35);
			this->Pipette_BTN->TabIndex = 24;
			this->toolTip1->SetToolTip(this->Pipette_BTN, L"Палитра\r\n\r\nВыбор на изображении цвета для рисования");
			this->Pipette_BTN->UseVisualStyleBackColor = false;
			this->Pipette_BTN->Click += gcnew System::EventHandler(this, &MainForm::Pipette_BTN_Click);
			// 
			// Spray_BTN
			// 
			this->Spray_BTN->BackColor = System::Drawing::Color::Transparent;
			this->Spray_BTN->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Spray_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Spray_BTN.Image")));
			this->Spray_BTN->Location = System::Drawing::Point(40, 59);
			this->Spray_BTN->Name = L"Spray_BTN";
			this->Spray_BTN->Size = System::Drawing::Size(35, 35);
			this->Spray_BTN->TabIndex = 23;
			this->toolTip1->SetToolTip(this->Spray_BTN, L"Распылитель\r\n");
			this->Spray_BTN->UseVisualStyleBackColor = false;
			this->Spray_BTN->Click += gcnew System::EventHandler(this, &MainForm::Spray_BTN_Click);
			// 
			// Brush_BTN
			// 
			this->Brush_BTN->BackColor = System::Drawing::Color::LightPink;
			this->Brush_BTN->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Brush_BTN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Brush_BTN.Image")));
			this->Brush_BTN->Location = System::Drawing::Point(40, 17);
			this->Brush_BTN->Name = L"Brush_BTN";
			this->Brush_BTN->Size = System::Drawing::Size(35, 35);
			this->Brush_BTN->TabIndex = 22;
			this->toolTip1->SetToolTip(this->Brush_BTN, L"Кисть\r\n\r\nРисование линии произвольной формы с выбранной толщиной");
			this->Brush_BTN->UseVisualStyleBackColor = false;
			this->Brush_BTN->Click += gcnew System::EventHandler(this, &MainForm::Brush_BTN_Click);
			// 
			// label7
			// 
			this->label7->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label7->Font = (gcnew System::Drawing::Font(L"Roboto", 10));
			this->label7->Location = System::Drawing::Point(0, 110);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(244, 20);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Инструменты";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Spray_down
			// 
			this->Spray_down->Interval = 50;
			this->Spray_down->Tick += gcnew System::EventHandler(this, &MainForm::Spray_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1511, 154);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 25;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// toolTip1
			// 
			this->toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			// 
			// Fill_Panel
			// 
			this->Fill_Panel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->Fill_Panel->Controls->Add(this->With_Fill_BTN);
			this->Fill_Panel->Controls->Add(this->Without_Fill_BTN);
			this->Fill_Panel->Location = System::Drawing::Point(262, 71);
			this->Fill_Panel->Name = L"Fill_Panel";
			this->Fill_Panel->Size = System::Drawing::Size(162, 71);
			this->Fill_Panel->TabIndex = 26;
			this->Fill_Panel->Visible = false;
			// 
			// With_Fill_BTN
			// 
			this->With_Fill_BTN->AutoSize = true;
			this->With_Fill_BTN->Location = System::Drawing::Point(13, 39);
			this->With_Fill_BTN->Name = L"With_Fill_BTN";
			this->With_Fill_BTN->Size = System::Drawing::Size(103, 20);
			this->With_Fill_BTN->TabIndex = 1;
			this->With_Fill_BTN->TabStop = true;
			this->With_Fill_BTN->Text = L"С заливкой";
			this->With_Fill_BTN->UseVisualStyleBackColor = true;
			this->With_Fill_BTN->CheckedChanged += gcnew System::EventHandler(this, &MainForm::With_Fill_BTN_CheckedChanged);
			// 
			// Without_Fill_BTN
			// 
			this->Without_Fill_BTN->AutoSize = true;
			this->Without_Fill_BTN->Location = System::Drawing::Point(13, 10);
			this->Without_Fill_BTN->Name = L"Without_Fill_BTN";
			this->Without_Fill_BTN->Size = System::Drawing::Size(111, 20);
			this->Without_Fill_BTN->TabIndex = 0;
			this->Without_Fill_BTN->TabStop = true;
			this->Without_Fill_BTN->Text = L"Без заливки";
			this->Without_Fill_BTN->UseVisualStyleBackColor = true;
			this->Without_Fill_BTN->CheckedChanged += gcnew System::EventHandler(this, &MainForm::Without_Fill_BTN_CheckedChanged);
			// 
			// FileName_Label
			// 
			this->FileName_Label->AutoSize = true;
			this->FileName_Label->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->FileName_Label->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FileName_Label->Location = System::Drawing::Point(140, 6);
			this->FileName_Label->Name = L"FileName_Label";
			this->FileName_Label->Size = System::Drawing::Size(129, 20);
			this->FileName_Label->TabIndex = 27;
			this->FileName_Label->Text = L"FileName_Label";
			// 
			// CanvasPanel
			// 
			this->CanvasPanel->AutoScroll = true;
			this->CanvasPanel->Controls->Add(this->Canvas);
			this->CanvasPanel->Location = System::Drawing::Point(12, 180);
			this->CanvasPanel->Name = L"CanvasPanel";
			this->CanvasPanel->Size = System::Drawing::Size(1334, 571);
			this->CanvasPanel->TabIndex = 28;
			// 
			// MainForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->ClientSize = System::Drawing::Size(1361, 763);
			this->Controls->Add(this->CanvasPanel);
			this->Controls->Add(this->FileName_Label);
			this->Controls->Add(this->Fill_Panel);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->BrushWidth_Panel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SuperPaint";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Canvas))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BrushWidthTrack))->EndInit();
			this->BrushWidth_Panel->ResumeLayout(false);
			this->BrushWidth_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BrushWidthUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BrushWidthType))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->Fill_Panel->ResumeLayout(false);
			this->Fill_Panel->PerformLayout();
			this->CanvasPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
 
		/// Методы, реализующие рисование объектов
#pragma region Drawing
		private: System::Void Canvas_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			Canvas->Cursor = Cursors::Cross;
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				pen->Color = BrushColor;
				pen->Width = BrushWidth;
				brush->Color = BrushColor;
				int sprayWidth = BrushWidth < 2 ? 2 : BrushWidth;
				recStart->X = Math::Min(StartX, e->X);
				recStart->Y = Math::Min(StartY, e->Y);
				recEnd->X = Math::Max(StartX, e->X);
				recEnd->Y = Math::Max(StartY, e->Y);
				switch (CurrentTool) {
					case Tools::Brush:
						Painter->DrawLine(pen, StartX, StartY, e->X, e->Y);
						StartX = e->X;
						StartY = e->Y;
						Painter->FillPie(brush, e->X - BrushWidth / 2, e->Y - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
						Canvas->Image = bmp;
						break;

					case Tools::Spray:
						brush->Color = BrushColor;
						for (int i = 0; i < 25; i++) {
							int r = rand() % (sprayWidth / 2);
							int deg = rand() % 360;
							int x = round(r * cos(PI / 180 * deg));
							int y = round(r * sin(PI / 180 * deg));
							Painter->FillPie(brush, StartX - x, StartY - y, 2, 2, 0, 360);
						}
						StartX = e->X;
						StartY = e->Y;
						Canvas->Image = bmp;
						break;

					case Tools::Eraser:
						pen->Color = Color::White;
						brush->Color = Color::White;
						Painter->DrawLine(pen, StartX, StartY, e->X, e->Y);
						Painter->FillPie(brush, e->X - BrushWidth / 2, e->Y - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
						StartX = e->X;
						StartY = e->Y;
						Canvas->Image = bmp;
						break;

					case Tools::Line:
						tempBMP = (Bitmap^ ) bmp->Clone();
						tempPainter = Graphics::FromImage(tempBMP);
						tempPainter->FillPie(brush, StartX - BrushWidth / 2, StartY - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
						tempPainter->DrawLine(pen, StartX, StartY, e->X, e->Y);
						tempPainter->FillPie(brush, e->X - BrushWidth / 2, e->Y - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
						Canvas->Image = tempBMP;
						break;

					case Tools::Rectangle:
						tempBMP = (Bitmap^ ) bmp->Clone();
						tempPainter = Graphics::FromImage(tempBMP);
						rectangleSize->Height = Math::Abs(recStart->Y - recEnd->Y);
						rectangleSize->Width = Math::Abs(recStart->X - recEnd->X);
						if (withFill) {
							tempPainter->FillRectangle(brush, recStart->X, recStart->Y, rectangleSize->Width, rectangleSize->Height);
						} else {
							tempPainter->DrawRectangle(pen, recStart->X, recStart->Y, rectangleSize->Width, rectangleSize->Height);
							if (rectangleSize->Width != 0 && rectangleSize->Height != 0) {
								tempPainter->FillPie(brush, recStart->X - BrushWidth / 2, recStart->Y - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
							} else {
								tempPainter->DrawLine(pen, StartX, StartY, e->X, e->Y);
							}
						}
						Canvas->Image = tempBMP;
						break;

					case Tools::Ellipse:
						tempBMP = (Bitmap^ ) bmp->Clone();
						tempPainter = Graphics::FromImage(tempBMP);
						rectangleSize->Height = Math::Abs(recStart->Y - recEnd->Y);
						rectangleSize->Width = Math::Abs(recStart->X - recEnd->X);
						if (withFill) {
							tempPainter->FillEllipse(brush, recStart->X, recStart->Y, rectangleSize->Width, rectangleSize->Height);
						} else {
							if (rectangleSize->Width < BrushWidth || rectangleSize->Height < BrushWidth) {
								tempPainter->FillEllipse(brush, recStart->X, recStart->Y, rectangleSize->Width, rectangleSize->Height);
							} else {
								tempPainter->DrawEllipse(pen, recStart->X, recStart->Y, rectangleSize->Width, rectangleSize->Height);
							}
						}
						Canvas->Image = tempBMP;
						break;
				}
			}
		}

		private: System::Void Canvas_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (!file->isNeedSave()) {
				file->setNeedSave(true);
			}
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				brush->Color = BrushColor;
				int sprayWidth = BrushWidth < 2 ? 2 : BrushWidth;
				StartX = e->X;
				StartY = e->Y;
				switch (CurrentTool) {
					case Tools::Brush:
						Painter->FillPie(brush, StartX - BrushWidth / 2, StartY - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
						break;
					case Tools::Spray:
						for (int i = 0; i < 25; i++) {
							int r = rand() % (sprayWidth / 2);
							int deg = rand() % 360;
							int x = round(r * cos(PI / 180 * deg));
							int y = round(r * sin(PI / 180 * deg));
							Painter->FillPie(brush, StartX - x, StartY - y, 2, 2, 0, 360);
						}
						Spray_down->Enabled = true;
						break;
					case Tools::Eraser:
						brush->Color = Color::White;
						Painter->FillPie(brush, StartX - BrushWidth / 2, StartY - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
						break;
					case Tools::Fill:
						Drawer::Drawer::Fill(bmp, BrushColor, Point(StartX, StartY));
						break;
				}
				Canvas->Image = bmp;
			}
		}

		private: System::Void Canvas_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			Spray_down->Enabled = false;
			if (CurrentTool == Tools::Pipette) {
				BrushColor = bmp->GetPixel(e->X, e->Y);
				Pipette_BTN->BackColor = Color::Transparent;
				Brush_BTN->BackColor = Color::LightPink;
				CurrentTool = Tools::Brush;
				if (BrushColor == Color::Transparent) {
					BrushColor = Color::White;
				}
				CurrentColorBtn->BackColor = BrushColor;
			}
			if (CurrentTool == Tools::Line || CurrentTool == Tools::Rectangle || CurrentTool == Tools::Ellipse) {
				bmp = (Bitmap^) tempBMP->Clone();
				Painter = Graphics::FromImage(bmp);
				Canvas->Image = bmp;
			}
			history->push((Bitmap^ ) bmp->Clone());
			History_Back->Enabled = history->canBack();
			History_Forward->Enabled = history->canForward();
		}

		private: System::Void Spray_Tick(System::Object^ sender, System::EventArgs^ e) {
			brush->Color = BrushColor;
			int sprayWidth = BrushWidth < 2 ? 2 : BrushWidth;
			for (int i = 0; i < 25; i++) {
				int r = rand() % (sprayWidth / 2);
				int deg = rand() % 360;
				int x = round(r * cos(PI / 180 * deg));
				int y = round(r * sin(PI / 180 * deg));
				Painter->FillPie(brush, StartX - x, StartY - y, 2, 2, 0, 360);
			}
			Canvas->Image = bmp;
		}
#pragma endregion

		/// Загрузка формы
		private: System::Void MainForm_Shown(System::Object^ sender, System::EventArgs^ e) {
			srand(time(NULL));
			printer = gcnew DocumentPrinter();
			file = gcnew FileManager();
			brush = gcnew SolidBrush(Color::Black);
			pen = gcnew Pen(BrushColor, BrushWidth);
			rectangleSize = gcnew Drawing::Size();
			recStart = gcnew Point();
			recEnd = gcnew Point();
			history = gcnew History();
			bmp = gcnew Bitmap(Canvas->Width, Canvas->Height);
			tempBMP = gcnew Bitmap(Canvas->Width, Canvas->Height);
			BrushWidthBMP = gcnew Bitmap(110, 110);
			Painter = Graphics::FromImage(bmp);
			Painter->Clear(Color::White);
			tempPainter = Graphics::FromImage(tempBMP);
			tempPainter->Clear(Color::White);
			gBrushWidth = Graphics::FromImage(BrushWidthBMP);
			gBrushWidth->FillPie(brush, 55 - BrushWidth / 2, 55 - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
			BrushWidthType->Image = BrushWidthBMP;
			Without_Fill_BTN->Checked = true;
			button2->Focus();
			history->push((Bitmap^ ) bmp->Clone());
			FileName_Label->Text = file->getFileName();
			Canvas->Image = bmp;
		}
 
		/// Изменение цветов
#pragma region Colors
		private: System::Void ColorBtn_1_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_1->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_2_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_2->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_3_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_3->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_4_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_4->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_5_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_5->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_6_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_6->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_7_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_7->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_8_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_8->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_9_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_9->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_10_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_10->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_11_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_11->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_12_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_12->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_13_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_13->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_14_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_14->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_15_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_15->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_16_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_16->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_17_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_17->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_18_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_18->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_19_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_19->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_20_Click(System::Object^ sender, System::EventArgs^ e) {
			BrushColor = ColorBtn_20->BackColor;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
		private: System::Void ColorBtn_More_Click(System::Object^ sender, System::EventArgs^ e) {
			colorDialog1->ShowDialog();
			BrushColor = colorDialog1->Color;
			CurrentColorBtn->BackColor = BrushColor;
			button2->Focus();
		}
#pragma endregion
		 
		/// Изменение размера кисти
		private: System::Void BrushWidthTrackBar_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			BrushWidth = BrushWidthTrack->Value;
			BrushWidthUpDown->Value = BrushWidth;
			SolidBrush^ brush = gcnew SolidBrush(Color::Black);
			gBrushWidth->Clear(Color::White);
			gBrushWidth->FillPie(brush, 55 - BrushWidth / 2, 55 - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
			BrushWidthType->Image = BrushWidthBMP;
		}

		private: System::Void BrushWidthUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			BrushWidth = Decimal::operator int (BrushWidthUpDown->Value);
			BrushWidthTrack->Value = BrushWidth;
			SolidBrush^ brush = gcnew SolidBrush(Color::Black);
			gBrushWidth->Clear(Color::White);
			gBrushWidth->FillPie(brush, 55 - BrushWidth / 2, 55 - BrushWidth / 2, BrushWidth, BrushWidth, 0, 360);
			BrushWidthType->Image = BrushWidthBMP;
		}
 
		/// Смена инструмента 
#pragma region Tools
		private: System::Void Brush_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			CurrentTool = Tools::Brush;
			Brush_BTN->BackColor = Color::LightPink;
			Spray_BTN->BackColor = Color::Transparent;
			Pipette_BTN->BackColor = Color::Transparent;
			Eraser_BTN->BackColor = Color::Transparent;
			Fill_BTN->BackColor = Color::Transparent;
			Line_BTN->BackColor = Color::Transparent;
			Ellipse_BTN->BackColor = Color::Transparent;
			Rectangle_BTN->BackColor = Color::Transparent;
			Fill_Panel->Visible = false;
			BrushWidth_Panel->Enabled = true;
			button2->Focus();
		}

		private: System::Void Spray_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			CurrentTool = Tools::Spray;
			Spray_BTN->BackColor = Color::LightPink;
			Brush_BTN->BackColor = Color::Transparent;
			Pipette_BTN->BackColor = Color::Transparent;
			Eraser_BTN->BackColor = Color::Transparent;
			Fill_BTN->BackColor = Color::Transparent;
			Line_BTN->BackColor = Color::Transparent;
			Ellipse_BTN->BackColor = Color::Transparent;
			Rectangle_BTN->BackColor = Color::Transparent;
			Fill_Panel->Visible = false;
			BrushWidth_Panel->Enabled = true;
			button2->Focus();
		}

		private: System::Void Pipette_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			Pipette_BTN->BackColor = Color::LightPink;
			Spray_BTN->BackColor = Color::Transparent;
			Brush_BTN->BackColor = Color::Transparent;
			Eraser_BTN->BackColor = Color::Transparent;
			Fill_BTN->BackColor = Color::Transparent;
			Line_BTN->BackColor = Color::Transparent;
			Ellipse_BTN->BackColor = Color::Transparent;
			Rectangle_BTN->BackColor = Color::Transparent;
			CurrentTool = Tools::Pipette;
			Fill_Panel->Visible = false;
			BrushWidth_Panel->Enabled = true;
			button2->Focus();
		}

		private: System::Void Eraser_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			Pipette_BTN->BackColor = Color::Transparent;
			Spray_BTN->BackColor = Color::Transparent;
			Brush_BTN->BackColor = Color::Transparent;
			Eraser_BTN->BackColor = Color::LightPink;
			Fill_BTN->BackColor = Color::Transparent;
			Line_BTN->BackColor = Color::Transparent;
			Ellipse_BTN->BackColor = Color::Transparent;
			Rectangle_BTN->BackColor = Color::Transparent;
			CurrentTool = Tools::Eraser;
			Fill_Panel->Visible = false;
			BrushWidth_Panel->Enabled = true;
			button2->Focus();
		}

		private: System::Void Fill_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			Pipette_BTN->BackColor = Color::Transparent;
			Spray_BTN->BackColor = Color::Transparent;
			Brush_BTN->BackColor = Color::Transparent;
			Eraser_BTN->BackColor = Color::Transparent;
			Fill_BTN->BackColor = Color::LightPink;
			Line_BTN->BackColor = Color::Transparent;
			Ellipse_BTN->BackColor = Color::Transparent;
			Rectangle_BTN->BackColor = Color::Transparent;
			CurrentTool = Tools::Fill;
			Fill_Panel->Visible = false;
			BrushWidth_Panel->Enabled = true;
			button2->Focus();
		}

		private: System::Void Line_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			Pipette_BTN->BackColor = Color::Transparent;
			Spray_BTN->BackColor = Color::Transparent;
			Brush_BTN->BackColor = Color::Transparent;
			Eraser_BTN->BackColor = Color::Transparent;
			Fill_BTN->BackColor = Color::Transparent;
			Line_BTN->BackColor = Color::LightPink;
			Ellipse_BTN->BackColor = Color::Transparent;
			Rectangle_BTN->BackColor = Color::Transparent;
			CurrentTool = Tools::Line;
			Fill_Panel->Visible = false;
			BrushWidth_Panel->Enabled = true;
			button2->Focus();
		}

		private: System::Void Rectangle_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			Pipette_BTN->BackColor = Color::Transparent;
			Spray_BTN->BackColor = Color::Transparent;
			Brush_BTN->BackColor = Color::Transparent;
			Eraser_BTN->BackColor = Color::Transparent;
			Fill_BTN->BackColor = Color::Transparent;
			Line_BTN->BackColor = Color::Transparent;
			Ellipse_BTN->BackColor = Color::Transparent;
			Rectangle_BTN->BackColor = Color::LightPink;
			CurrentTool = Tools::Rectangle;
			Fill_Panel->Visible = true;
			BrushWidth_Panel->Enabled = !withFill;
			button2->Focus();
		}

		private: System::Void Ellipse_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			Pipette_BTN->BackColor = Color::Transparent;
			Spray_BTN->BackColor = Color::Transparent;
			Brush_BTN->BackColor = Color::Transparent;
			Eraser_BTN->BackColor = Color::Transparent;
			Fill_BTN->BackColor = Color::Transparent;
			Line_BTN->BackColor = Color::Transparent;
			Ellipse_BTN->BackColor = Color::LightPink;
			Rectangle_BTN->BackColor = Color::Transparent;
			CurrentTool = Tools::Ellipse;
			Fill_Panel->Visible = true;
			BrushWidth_Panel->Enabled = !withFill;
			button2->Focus();
		}
#pragma endregion

		/// Контроль заливки
		private: System::Void Without_Fill_BTN_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			withFill = false;
			BrushWidth_Panel->Enabled = true;
		}
		private: System::Void With_Fill_BTN_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			withFill = true;
			BrushWidth_Panel->Enabled = false;
		}
 
		/// Управление историей
		private: System::Void History_Back_Click(System::Object^ sender, System::EventArgs^ e) {
			bmp = (Bitmap^) history->back()->Clone();
			Canvas->Image = (Bitmap^) bmp->Clone();
			Painter = Graphics::FromImage(bmp);
			History_Back->Enabled = history->canBack();
			History_Forward->Enabled = history->canForward();
			file->setNeedSave(true);
		}

		private: System::Void History_Forward_Click(System::Object^ sender, System::EventArgs^ e) {
			bmp = (Bitmap^)history->forward()->Clone();
			Canvas->Image = (Bitmap^)bmp->Clone();
			Painter = Graphics::FromImage(bmp);
			History_Back->Enabled = history->canBack();
			History_Forward->Enabled = history->canForward();
			file->setNeedSave(true);
		}


#pragma region Files
		/// Закрытие, открытие и сохранение
		private: System::Void Save_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			file->save(Canvas->Image);
		}

		private: System::Void SaveFile_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			file->saveAs(Canvas->Image);
			FileName_Label->Text = file->getFileName();
		}

		private: System::Void openFile() {
			if (file->open()) {
				FileName_Label->Text = file->getFileName();
				bmp = file->getBmp();
				Canvas->Width = bmp->Width;
				Canvas->Height = bmp->Height;
				Canvas->Image = bmp;
				Painter = Graphics::FromImage(bmp);
				Painter->FillPie(gcnew SolidBrush(bmp->GetPixel(1, 1)), 1, 1, 1, 1, 0, 360);
				history = gcnew History();
				History_Back->Enabled = false;
				History_Forward->Enabled = false;
				history->push((Bitmap^ ) bmp->Clone());
			}
		}

		private: System::Void OpenFile_BTN_Click(System::Object^ sender, System::EventArgs^ e) {
			Windows::Forms::DialogResult result;
			if (file->isNeedSave()) {
				result = Windows::Forms::MessageBox::Show(L"Вы хотите сохранить изменения в файле " + file->getFileName() + L"?", L"Открытие", MessageBoxButtons::YesNoCancel);
				if (result == Windows::Forms::DialogResult::Yes) {
					if (file->save(Canvas->Image)) {
						openFile();
					}
				}
			}
			if (result == Windows::Forms::DialogResult::No || !file->isNeedSave()) {
				openFile();
			}
		}

		private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			if (file->isNeedSave()) {
				Windows::Forms::DialogResult result = Windows::Forms::MessageBox::Show(L"Вы хотите сохранить изменения в файле " + file->getFileName() + L"?", L"Выход", MessageBoxButtons::YesNoCancel);
				if (result == Windows::Forms::DialogResult::Yes) {
					e->Cancel = !file->save(Canvas->Image);
				} else if (result == Windows::Forms::DialogResult::Cancel) {
					e->Cancel = true;
				}
			}
		}
#pragma endregion

		private: System::Void AboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			InfoForm ^info = gcnew InfoForm();
			info->Show();
		}

		private: System::Void ExitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		/// Создание нового рисунка 
		private: System::Void NewToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Windows::Forms::DialogResult result;
			if (file->isNeedSave()) {
				result = Windows::Forms::MessageBox::Show(L"Вы хотите сохранить изменения в файле " + file->getFileName() + L"?", L"Открытие", MessageBoxButtons::YesNoCancel);
				if (result == Windows::Forms::DialogResult::Yes) {
					if (file->save(Canvas->Image)) {
						NewFile ^a = gcnew NewFile();
						a->Show();
					}
				}
			}
			if (result == Windows::Forms::DialogResult::No || !file->isNeedSave()) {
				NewFile ^newFileDialog = gcnew NewFile();
				newFileDialog->ShowDialog();
				if (newFileDialog->isCreated) {
					file = gcnew FileManager(newFileDialog->width, newFileDialog->height);
					FileName_Label->Text = file->getFileName();
					bmp = file->getBmp();
					Canvas->Width = bmp->Width;
					Canvas->Height = bmp->Height;
					Canvas->Image = bmp;
					Painter = Graphics::FromImage(bmp);
					Painter->Clear(Color::White);
					Painter->FillPie(gcnew SolidBrush(bmp->GetPixel(1, 1)), 1, 1, 1, 1, 0, 360);
					history = gcnew History();
					History_Back->Enabled = false;
					History_Forward->Enabled = false;
					history->push((Bitmap^)bmp->Clone());
					CanvasPanel->HorizontalScroll->Value = 0;
					CanvasPanel->VerticalScroll->Value = 0;
				}
			}
		}

		/// Печать
		private: System::Void PrintToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			printer->print(Canvas->Image);
		}
		private: System::Void PageParamToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			printer->openPageSettingsDialog();
		}
	};
}

