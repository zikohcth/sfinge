#pragma once

namespace Ve2D {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for F_ShapeGen
	/// </summary>
	public ref class F_ShapeGen : public System::Windows::Forms::Form
	{
	public:
		F_ShapeGen(void)
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
		~F_ShapeGen()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TrackBar^  trackBar5;
	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Top";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Bottom";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(12, 12);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->groupBox1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->groupBox2);
			this->splitContainer1->Size = System::Drawing::Size(753, 419);
			this->splitContainer1->SplitterDistance = 251;
			this->splitContainer1->TabIndex = 3;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->trackBar5);
			this->groupBox1->Controls->Add(this->trackBar4);
			this->groupBox1->Controls->Add(this->trackBar3);
			this->groupBox1->Controls->Add(this->trackBar2);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(252, 419);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Tùy chỉnh";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(233, 263);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(19, 13);
			this->label11->TabIndex = 21;
			this->label11->Text = L"50";
			// 
			// trackBar5
			// 
			this->trackBar5->LargeChange = 10;
			this->trackBar5->Location = System::Drawing::Point(52, 263);
			this->trackBar5->Maximum = 100;
			this->trackBar5->Minimum = 10;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(140, 45);
			this->trackBar5->TabIndex = 16;
			this->trackBar5->Value = 50;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &F_ShapeGen::trackBar5_Scroll);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(233, 212);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(19, 13);
			this->label10->TabIndex = 20;
			this->label10->Text = L"50";
			// 
			// trackBar4
			// 
			this->trackBar4->LargeChange = 10;
			this->trackBar4->Location = System::Drawing::Point(52, 212);
			this->trackBar4->Maximum = 100;
			this->trackBar4->Minimum = 10;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(140, 45);
			this->trackBar4->TabIndex = 15;
			this->trackBar4->Value = 50;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &F_ShapeGen::trackBar4_Scroll);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(233, 161);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(19, 13);
			this->label9->TabIndex = 19;
			this->label9->Text = L"50";
			// 
			// trackBar3
			// 
			this->trackBar3->LargeChange = 10;
			this->trackBar3->Location = System::Drawing::Point(52, 161);
			this->trackBar3->Maximum = 100;
			this->trackBar3->Minimum = 10;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(140, 45);
			this->trackBar3->TabIndex = 14;
			this->trackBar3->Value = 50;
			this->trackBar3->ValueChanged += gcnew System::EventHandler(this, &F_ShapeGen::trackBar3_ValueChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(233, 110);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(19, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"50";
			// 
			// trackBar2
			// 
			this->trackBar2->LargeChange = 10;
			this->trackBar2->Location = System::Drawing::Point(52, 110);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Minimum = 10;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(140, 45);
			this->trackBar2->TabIndex = 13;
			this->trackBar2->Value = 50;
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &F_ShapeGen::trackBar2_ValueChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(233, 59);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(19, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"50";
			// 
			// trackBar1
			// 
			this->trackBar1->LargeChange = 10;
			this->trackBar1->Location = System::Drawing::Point(52, 59);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Minimum = 10;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(140, 45);
			this->trackBar1->TabIndex = 10;
			this->trackBar1->Value = 50;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &F_ShapeGen::trackBar1_ValueChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(11, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Mẫu dạng vân tay";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Ngón cái", L"Ngón trỏ", L"Ngón giữa", L"Ngón nhẫn", 
				L"Ngón út"});
			this->comboBox1->Location = System::Drawing::Point(110, 19);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(136, 21);
			this->comboBox1->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(11, 263);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Middle";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 212);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Right";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 161);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Left";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->pictureBox1);
			this->groupBox2->Location = System::Drawing::Point(3, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(495, 419);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Hình dạng vân tay";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(7, 20);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(482, 393);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// F_ShapeGen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(777, 443);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"F_ShapeGen";
			this->Text = L"Sinh hình dạng vân tay";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->label7->Text = System::Convert::ToString(this->trackBar1->Value);
		 }
private: System::Void trackBar2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->label8->Text = System::Convert::ToString(this->trackBar2->Value);
		 }
private: System::Void trackBar3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->label9->Text = System::Convert::ToString(this->trackBar3->Value);
		 }
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 this->label10->Text = System::Convert::ToString(this->trackBar4->Value);
		 }
private: System::Void trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 this->label11->Text = System::Convert::ToString(this->trackBar5->Value);
		 }
};
}
