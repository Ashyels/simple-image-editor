#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgcodecs\imgcodecs.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include <string>

namespace opencvApp5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace cv;
	using namespace std;
	Mat src, erosion_dst, dilation_dst, opening_dst, closing_dst;

	int erosion_elem = 0;
	int erosion_size = 0;
	int opening_elem = 0;
	int opening_size = 0;
	int closing_elem = 0;
	int closing_size = 0;
	int dilation_elem = 0;
	int dilation_size = 0;
	int const max_elem = 2;
	int const max_kernel_size = 21;

	/** Function Headers */
	void Erosion(Mat src);
	void Dilation(Mat src);
	void Opening_(Mat src);
	void Closing_(Mat src);


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  ptbSource;
	private: System::Windows::Forms::PictureBox^  ptbSource2;
	protected:

	protected:
	private: System::Windows::Forms::Button^  btnBrowse;
	private: System::Windows::Forms::Button^  btnProcess;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TrackBar^  tbErosi;
	private: System::Windows::Forms::TrackBar^  tbDilasi;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TrackBar^  tbClosing;

	private: System::Windows::Forms::TrackBar^  tbOpening;


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
			this->ptbSource = (gcnew System::Windows::Forms::PictureBox());
			this->ptbSource2 = (gcnew System::Windows::Forms::PictureBox());
			this->btnBrowse = (gcnew System::Windows::Forms::Button());
			this->btnProcess = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbErosi = (gcnew System::Windows::Forms::TrackBar());
			this->tbDilasi = (gcnew System::Windows::Forms::TrackBar());
			this->tbOpening = (gcnew System::Windows::Forms::TrackBar());
			this->tbClosing = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSource2))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbErosi))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbDilasi))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbOpening))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbClosing))->BeginInit();
			this->SuspendLayout();
			// 
			// ptbSource
			// 
			this->ptbSource->Location = System::Drawing::Point(6, 7);
			this->ptbSource->Name = L"ptbSource";
			this->ptbSource->Size = System::Drawing::Size(368, 165);
			this->ptbSource->TabIndex = 1;
			this->ptbSource->TabStop = false;
			// 
			// ptbSource2
			// 
			this->ptbSource2->Location = System::Drawing::Point(6, 7);
			this->ptbSource2->Name = L"ptbSource2";
			this->ptbSource2->Size = System::Drawing::Size(368, 165);
			this->ptbSource2->TabIndex = 5;
			this->ptbSource2->TabStop = false;
			// 
			// btnBrowse
			// 
			this->btnBrowse->Location = System::Drawing::Point(12, 12);
			this->btnBrowse->Name = L"btnBrowse";
			this->btnBrowse->Size = System::Drawing::Size(75, 23);
			this->btnBrowse->TabIndex = 2;
			this->btnBrowse->Text = L"Browse";
			this->btnBrowse->UseVisualStyleBackColor = true;
			this->btnBrowse->Click += gcnew System::EventHandler(this, &MyForm::btnBrowse_Click);
			// 
			// btnProcess
			// 
			this->btnProcess->Location = System::Drawing::Point(12, 41);
			this->btnProcess->Name = L"btnProcess";
			this->btnProcess->Size = System::Drawing::Size(75, 23);
			this->btnProcess->TabIndex = 3;
			this->btnProcess->Text = L"Process";
			this->btnProcess->UseVisualStyleBackColor = true;
			this->btnProcess->Click += gcnew System::EventHandler(this, &MyForm::btnProcess_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(93, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(388, 204);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->tbClosing);
			this->tabPage1->Controls->Add(this->tbOpening);
			this->tabPage1->Controls->Add(this->ptbSource);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(380, 178);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Controls->Add(this->tbErosi);
			this->tabPage2->Controls->Add(this->tbDilasi);
			this->tabPage2->Controls->Add(this->ptbSource2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(380, 178);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Erosi";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Dilasi";
			// 
			// tbErosi
			// 
			this->tbErosi->Location = System::Drawing::Point(6, 102);
			this->tbErosi->Name = L"tbErosi";
			this->tbErosi->Size = System::Drawing::Size(368, 45);
			this->tbErosi->TabIndex = 7;
			this->tbErosi->Scroll += gcnew System::EventHandler(this, &MyForm::tbErosi_Scroll);
			// 
			// tbDilasi
			// 
			this->tbDilasi->Location = System::Drawing::Point(6, 29);
			this->tbDilasi->Name = L"tbDilasi";
			this->tbDilasi->Size = System::Drawing::Size(368, 45);
			this->tbDilasi->TabIndex = 6;
			this->tbDilasi->Scroll += gcnew System::EventHandler(this, &MyForm::tbDilasi_Scroll);
			// 
			// tbOpening
			// 
			this->tbOpening->Location = System::Drawing::Point(6, 30);
			this->tbOpening->Name = L"tbOpening";
			this->tbOpening->Size = System::Drawing::Size(368, 45);
			this->tbOpening->TabIndex = 5;
			this->tbOpening->Scroll += gcnew System::EventHandler(this, &MyForm::tbOpening_Scroll);
			// 
			// tbClosing
			// 
			this->tbClosing->Location = System::Drawing::Point(6, 104);
			this->tbClosing->Name = L"tbClosing";
			this->tbClosing->Size = System::Drawing::Size(368, 45);
			this->tbClosing->TabIndex = 6;
			this->tbClosing->Scroll += gcnew System::EventHandler(this, &MyForm::tbClosing_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Opening";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Closing";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(490, 224);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->btnProcess);
			this->Controls->Add(this->btnBrowse);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSource2))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbErosi))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbDilasi))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbOpening))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbClosing))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnBrowse_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		openFileDialog1->Filter = "Image(*.jpg)|*.jpg|All files (*.*)|*.*";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		Bitmap^ bmpSrc = gcnew Bitmap(openFileDialog1->FileName);
/*		ptbSource->Image = bmpSrc;
		ptbSource->Refresh();
		ptbSource2->Image = bmpSrc;
		ptbSource2->Refresh();
*/
		src = imread(ConvertString2Char(openFileDialog1->FileName));
		imshow("Source Image showing via openCV", src);
	}

		private: char* ConvertString2Char(System::String^ str)
		{
			char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
			return str2;
		}

	private: System::Void btnProcess_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void tbDilasi_Scroll(System::Object^  sender, System::EventArgs^  e) {
	dilation_size = System::Math::Round(tbDilasi->Value);
	Dilation(src);
}
private: System::Void tbErosi_Scroll(System::Object^  sender, System::EventArgs^  e) {
	erosion_size = System::Math::Round(tbErosi->Value);
	Erosion(src);
}
private: System::Void tbOpening_Scroll(System::Object^  sender, System::EventArgs^  e) {
	opening_size = System::Math::Round(tbOpening->Value);
	Opening_(src);
}
private: System::Void tbClosing_Scroll(System::Object^  sender, System::EventArgs^  e) {
	closing_size = System::Math::Round(tbClosing->Value);
	Closing_(src);
}
};


void Erosion(Mat src)
{
	int erosion_type;
	if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
	else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
	else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(erosion_type,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));

	/// Apply the erosion operation
	erode(src, erosion_dst, element);
	imshow("Erosion Demo", erosion_dst);
}

/** @function Dilation */
void Dilation(Mat src)
{
	int dilation_type;
	if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
	else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
	else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(dilation_type,
		cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		cv::Point(dilation_size, dilation_size));
	/// Apply the dilation operation
	dilate(src, dilation_dst, element);

	imshow("Dilation Demo", dilation_dst);
}

/** @function Opening */
void Opening_(Mat src)
{
	int opening_type;
	if (opening_elem == 0) { opening_type = MORPH_RECT; }
	else if (opening_elem == 1) { opening_type = MORPH_CROSS; }
	else if (opening_elem == 2) { opening_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(opening_type,
		cv::Size(2 * opening_size + 1, 2 * opening_size + 1),
		cv::Point(opening_size, opening_size));
	/// Apply the dilation operation
	erode(src, opening_dst, element);
	dilate(opening_dst, opening_dst, element);

	imshow("Opening Demo", opening_dst);
}

/** @function Closing */
void Closing_(Mat src)
{
	int closing_type;
	if (closing_elem == 0) { closing_type = MORPH_RECT; }
	else if (closing_elem == 1) { closing_type = MORPH_CROSS; }
	else if (closing_elem == 2) { closing_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(closing_type,
		cv::Size(2 * closing_size + 1, 2 * closing_size + 1),
		cv::Point(closing_size, closing_size));
	/// Apply the dilation operation
	dilate(src, closing_dst, element);
	erode(closing_dst, closing_dst, element);

	imshow("Closing Demo", closing_dst);
}

}
