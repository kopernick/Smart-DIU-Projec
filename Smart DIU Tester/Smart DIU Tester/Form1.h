#pragma once


namespace SmartDIUTester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonCancel;
	protected: 
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  checkBoxHWFlow;
	private: System::Windows::Forms::CheckBox^  checkBoxEcho;
	private: System::Windows::Forms::TextBox^  textBoxPostCond;
	private: System::Windows::Forms::TextBox^  textBoxPreCond;
	private: System::Windows::Forms::TextBox^  textBoxOutputSize;
	private: System::Windows::Forms::TextBox^  textBoxInputSize;
	private: System::Windows::Forms::ComboBox^  comboBoxStopBits;
	private: System::Windows::Forms::ComboBox^  comboBoxParity;
	private: System::Windows::Forms::ComboBox^  comboBoxComport;
	private: System::Windows::Forms::ComboBox^  comboBoxDataBits;
	private: System::Windows::Forms::ComboBox^  comboBoxBPS;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxHWFlow = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxEcho = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxPostCond = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPreCond = (gcnew System::Windows::Forms::TextBox());
			this->textBoxOutputSize = (gcnew System::Windows::Forms::TextBox());
			this->textBoxInputSize = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxStopBits = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxParity = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxComport = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxDataBits = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxBPS = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(786, 335);
			this->buttonCancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(110, 38);
			this->buttonCancel->TabIndex = 3;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(668, 335);
			this->buttonOK->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(110, 38);
			this->buttonOK->TabIndex = 2;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->checkBoxHWFlow);
			this->groupBox1->Controls->Add(this->checkBoxEcho);
			this->groupBox1->Controls->Add(this->textBoxPostCond);
			this->groupBox1->Controls->Add(this->textBoxPreCond);
			this->groupBox1->Controls->Add(this->textBoxOutputSize);
			this->groupBox1->Controls->Add(this->textBoxInputSize);
			this->groupBox1->Controls->Add(this->comboBoxStopBits);
			this->groupBox1->Controls->Add(this->comboBoxParity);
			this->groupBox1->Controls->Add(this->comboBoxComport);
			this->groupBox1->Controls->Add(this->comboBoxDataBits);
			this->groupBox1->Controls->Add(this->comboBoxBPS);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(18, 18);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Size = System::Drawing::Size(878, 308);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Port Settings";
			// 
			// checkBoxHWFlow
			// 
			this->checkBoxHWFlow->AutoSize = true;
			this->checkBoxHWFlow->Location = System::Drawing::Point(570, 238);
			this->checkBoxHWFlow->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBoxHWFlow->Name = L"checkBoxHWFlow";
			this->checkBoxHWFlow->Size = System::Drawing::Size(239, 24);
			this->checkBoxHWFlow->TabIndex = 3;
			this->checkBoxHWFlow->Text = L"H/W Flow Control (RTS/CTS)";
			this->checkBoxHWFlow->UseVisualStyleBackColor = true;
			// 
			// checkBoxEcho
			// 
			this->checkBoxEcho->AutoSize = true;
			this->checkBoxEcho->Location = System::Drawing::Point(424, 238);
			this->checkBoxEcho->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBoxEcho->Name = L"checkBoxEcho";
			this->checkBoxEcho->Size = System::Drawing::Size(72, 24);
			this->checkBoxEcho->TabIndex = 3;
			this->checkBoxEcho->Text = L"Echo";
			this->checkBoxEcho->UseVisualStyleBackColor = true;
			// 
			// textBoxPostCond
			// 
			this->textBoxPostCond->Location = System::Drawing::Point(608, 188);
			this->textBoxPostCond->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxPostCond->Name = L"textBoxPostCond";
			this->textBoxPostCond->Size = System::Drawing::Size(150, 26);
			this->textBoxPostCond->TabIndex = 2;
			this->textBoxPostCond->Text = L"30";
			this->textBoxPostCond->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBoxPreCond
			// 
			this->textBoxPreCond->Location = System::Drawing::Point(608, 138);
			this->textBoxPreCond->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxPreCond->Name = L"textBoxPreCond";
			this->textBoxPreCond->Size = System::Drawing::Size(150, 26);
			this->textBoxPreCond->TabIndex = 2;
			this->textBoxPreCond->Text = L"30";
			this->textBoxPreCond->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBoxOutputSize
			// 
			this->textBoxOutputSize->Location = System::Drawing::Point(608, 91);
			this->textBoxOutputSize->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxOutputSize->Name = L"textBoxOutputSize";
			this->textBoxOutputSize->Size = System::Drawing::Size(150, 26);
			this->textBoxOutputSize->TabIndex = 2;
			this->textBoxOutputSize->Text = L"4096";
			this->textBoxOutputSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBoxInputSize
			// 
			this->textBoxInputSize->Location = System::Drawing::Point(608, 45);
			this->textBoxInputSize->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxInputSize->Name = L"textBoxInputSize";
			this->textBoxInputSize->Size = System::Drawing::Size(150, 26);
			this->textBoxInputSize->TabIndex = 2;
			this->textBoxInputSize->Text = L"4096";
			this->textBoxInputSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// comboBoxStopBits
			// 
			this->comboBoxStopBits->FormattingEnabled = true;
			this->comboBoxStopBits->Location = System::Drawing::Point(177, 232);
			this->comboBoxStopBits->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBoxStopBits->Name = L"comboBoxStopBits";
			this->comboBoxStopBits->Size = System::Drawing::Size(217, 28);
			this->comboBoxStopBits->TabIndex = 1;
			// 
			// comboBoxParity
			// 
			this->comboBoxParity->FormattingEnabled = true;
			this->comboBoxParity->Location = System::Drawing::Point(177, 183);
			this->comboBoxParity->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBoxParity->Name = L"comboBoxParity";
			this->comboBoxParity->Size = System::Drawing::Size(217, 28);
			this->comboBoxParity->TabIndex = 1;
			// 
			// comboBoxComport
			// 
			this->comboBoxComport->FormattingEnabled = true;
			this->comboBoxComport->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"7", L"8", L"9" });
			this->comboBoxComport->Location = System::Drawing::Point(177, 45);
			this->comboBoxComport->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBoxComport->Name = L"comboBoxComport";
			this->comboBoxComport->Size = System::Drawing::Size(217, 28);
			this->comboBoxComport->TabIndex = 1;
			// 
			// comboBoxDataBits
			// 
			this->comboBoxDataBits->FormattingEnabled = true;
			this->comboBoxDataBits->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"7", L"8", L"9" });
			this->comboBoxDataBits->Location = System::Drawing::Point(177, 135);
			this->comboBoxDataBits->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBoxDataBits->Name = L"comboBoxDataBits";
			this->comboBoxDataBits->Size = System::Drawing::Size(217, 28);
			this->comboBoxDataBits->TabIndex = 1;
			// 
			// comboBoxBPS
			// 
			this->comboBoxBPS->FormattingEnabled = true;
			this->comboBoxBPS->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"2400", L"4800", L"9600", L"19200", L"38400",
					L"115200"
			});
			this->comboBoxBPS->Location = System::Drawing::Point(177, 89);
			this->comboBoxBPS->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBoxBPS->Name = L"comboBoxBPS";
			this->comboBoxBPS->Size = System::Drawing::Size(217, 28);
			this->comboBoxBPS->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(420, 192);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(154, 20);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Post Condition Time:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(78, 237);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 20);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Stop Bits:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(420, 143);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(147, 20);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Pre-Condition Time:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(778, 192);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(54, 20);
			this->label12->TabIndex = 0;
			this->label12->Text = L"mSec.";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(778, 143);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(54, 20);
			this->label11->TabIndex = 0;
			this->label11->Text = L"mSec.";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(778, 95);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(59, 20);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Byte(s)";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(778, 49);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(59, 20);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Byte(s)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(105, 188);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 20);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Parity:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(117, 49);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(42, 20);
			this->label13->TabIndex = 0;
			this->label13->Text = L"Port:";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(420, 95);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(145, 20);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Output Buffer Size:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(76, 140);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 20);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Data Bits:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(420, 49);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(133, 20);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Input Buffer Size:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 94);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Bits Per Second:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(470, 270);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 39);
			this->button1->TabIndex = 4;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(922, 402);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"Serial Port Properties";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

