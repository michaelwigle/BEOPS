#pragma once
#include "BEOPSGlobals.h"
namespace BEOPS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; //for streamwriter
	using namespace System::Diagnostics; //for Process
	using namespace System::Globalization; //for DateTime


	/// <summary>
	/// Summary for frmMethod2Input
	/// </summary>
	public ref class frmMethod2Input : public System::Windows::Forms::Form
	{
	public:
		frmMethod2Input(void)
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
		~frmMethod2Input()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^ strPrintText;
	private: System::Windows::Forms::Label^  lblMonthYear;
	protected: 

	private: System::Windows::Forms::Label^  lblBusinessMileage;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtbxMonthYear;
	private: System::Windows::Forms::TextBox^  txtbxBusinessMileage;
	private: System::Windows::Forms::TextBox^  txtbxIRSRate;
	private: System::Windows::Forms::Button^  btnPrint;
	private: System::Windows::Forms::Button^  btnClose;
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
			this->lblMonthYear = (gcnew System::Windows::Forms::Label());
			this->lblBusinessMileage = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtbxMonthYear = (gcnew System::Windows::Forms::TextBox());
			this->txtbxBusinessMileage = (gcnew System::Windows::Forms::TextBox());
			this->txtbxIRSRate = (gcnew System::Windows::Forms::TextBox());
			this->btnPrint = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblMonthYear
			// 
			this->lblMonthYear->AutoSize = true;
			this->lblMonthYear->Location = System::Drawing::Point(13, 13);
			this->lblMonthYear->Name = L"lblMonthYear";
			this->lblMonthYear->Size = System::Drawing::Size(83, 13);
			this->lblMonthYear->TabIndex = 0;
			this->lblMonthYear->Text = L"Month and Year";
			// 
			// lblBusinessMileage
			// 
			this->lblBusinessMileage->AutoSize = true;
			this->lblBusinessMileage->Location = System::Drawing::Point(13, 39);
			this->lblBusinessMileage->Name = L"lblBusinessMileage";
			this->lblBusinessMileage->Size = System::Drawing::Size(89, 13);
			this->lblBusinessMileage->TabIndex = 1;
			this->lblBusinessMileage->Text = L"Business Mileage";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Current IRS Rate";
			// 
			// txtbxMonthYear
			// 
			this->txtbxMonthYear->AccessibleDescription = L"Month and Year";
			this->txtbxMonthYear->AccessibleName = L"Month and Year";
			this->txtbxMonthYear->Location = System::Drawing::Point(136, 13);
			this->txtbxMonthYear->Name = L"txtbxMonthYear";
			this->txtbxMonthYear->Size = System::Drawing::Size(124, 20);
			this->txtbxMonthYear->TabIndex = 3;
			this->txtbxMonthYear->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmMethod2Input::txtbxMonthYear_Validating);
			// 
			// txtbxBusinessMileage
			// 
			this->txtbxBusinessMileage->AccessibleDescription = L"Business Mileage";
			this->txtbxBusinessMileage->AccessibleName = L"Business Mileage";
			this->txtbxBusinessMileage->Location = System::Drawing::Point(136, 40);
			this->txtbxBusinessMileage->Name = L"txtbxBusinessMileage";
			this->txtbxBusinessMileage->Size = System::Drawing::Size(124, 20);
			this->txtbxBusinessMileage->TabIndex = 4;
			this->txtbxBusinessMileage->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmMethod2Input::txtbxBusinessMileage_Validating);
			// 
			// txtbxIRSRate
			// 
			this->txtbxIRSRate->AccessibleDescription = L"Current IRS Rate";
			this->txtbxIRSRate->AccessibleName = L"Current IRS Rate";
			this->txtbxIRSRate->Location = System::Drawing::Point(136, 68);
			this->txtbxIRSRate->Name = L"txtbxIRSRate";
			this->txtbxIRSRate->Size = System::Drawing::Size(124, 20);
			this->txtbxIRSRate->TabIndex = 5;
			this->txtbxIRSRate->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmMethod2Input::txtbxIRSRate_Validating);
			// 
			// btnPrint
			// 
			this->btnPrint->Location = System::Drawing::Point(100, 134);
			this->btnPrint->Name = L"btnPrint";
			this->btnPrint->Size = System::Drawing::Size(75, 23);
			this->btnPrint->TabIndex = 6;
			this->btnPrint->Text = L"&Print";
			this->btnPrint->UseVisualStyleBackColor = true;
			this->btnPrint->Click += gcnew System::EventHandler(this, &frmMethod2Input::btnPrint_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(100, 174);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 7;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmMethod2Input::btnClose_Click);
			// 
			// frmMethod2Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(272, 246);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnPrint);
			this->Controls->Add(this->txtbxIRSRate);
			this->Controls->Add(this->txtbxBusinessMileage);
			this->Controls->Add(this->txtbxMonthYear);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblBusinessMileage);
			this->Controls->Add(this->lblMonthYear);
			this->Name = L"frmMethod2Input";
			this->Text = L"Method 2 Input";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnPrint_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				    double dIRSRate = Double::Parse(this->txtbxIRSRate->Text);
				    int nBusinessMileage = Int32::Parse(this->txtbxBusinessMileage->Text);
					double dCalculationResult = dIRSRate*nBusinessMileage;
					System::DateTime dteDate = DateTime::Parse(this->txtbxMonthYear->Text);
					DateTimeFormatInfo^ dtfMonthYear = gcnew DateTimeFormatInfo();
					dtfMonthYear->YearMonthPattern = "MMMM yyyy";


					//Code to create document
				    strPrintText = "";
					String^ strDocumentBeginning = 
						L"{\\rtf1\\ansi\\ansicpg1252\\deff0" + //rtf1 means version 1. fbidis is unknown. ansi character set. ansicpg1252 is US Windows unicode to ansi conversion. deff0 make f0 the default font
						L"{\\fonttbl" + //The font table defines the font used in the document f0 is defined below inside the font table definition
							L"{\\f0\\froman\\fcharset128 Times New Roman;}}" + 
						L"{\\colortbl ;\\red0\\green0\\blue0;}" + //color table for the colors used in the document. The starting ; means c0 is "auto" color
						L"\\margl360\\margr360\\margt360\\margb360\\footery360" + //sets up the margins for half inch. Note that you need footery360 to resize the footer or margb won't work.
						//Below is the footer code including use of paragraph formatting and fields for special data including PAGE NUMPAGES and DATE (current)
						L"{\\footer \\fs20\\tx5000\\tqr\\tx11000 BEOPS " + BEOPSGlobals::datBEOPSData->dblVersionNumber.ToString("F1") + "\\tab " + 
						L"Page {\\field{\\*\\fldinst  PAGE }{\\fldrslt}} of {\\field{\\*\\fldinst NUMPAGES}{\\fldrslt}}\\tab "+ 
						L"Printed {\\field{\\*\\fldinst DATE}{\\fldrslt}}\\par\\pard}";
					//Begin Page 1 of report
					String^ strReportHeading = 
						L"\\qc\\lang1033\\b\\fs32 Ohio Rehabilitation Services Commission\\par Monthly Vehicle Expense Report Method 2\\par\\fs24 (Must be used and attached to MOR when using Expense Code R.)\\par\\par\\pard\\tx2160\\b BSVI Area \\b0 " + BEOPSGlobals::datBEOPSData->strBSVIArea + 
						L"\\tab\\b Operator Number \\b0 " + BEOPSGlobals::datBEOPSData->strOperatorNumber + L"\\tab\\b Facility Number \\b0 " + BEOPSGlobals::datBEOPSData->strFacilityNumber + 
						L"\\tab\\tab\\b Report Date \\b0  " + dteDate.ToString("y", dtfMonthYear) +
						L" \\par\\b Operator Name\\b0\\tab " + BEOPSGlobals::datBEOPSData->strOperatorName + L"\\tab " +
						L"\\b Address\\b0\\tab " + BEOPSGlobals::datBEOPSData->strOperatorAddress1 + L",  " + 
						BEOPSGlobals::datBEOPSData->strOperatorCity + L", " + BEOPSGlobals::datBEOPSData->strOperatorState + L" " + BEOPSGlobals::datBEOPSData->strOperatorZip + L"\\par\\pard";
					String^ strReportBody =
						L"\\par\\par Actual business miles X current IRS rate = " + nBusinessMileage.ToString() + L" X " + dIRSRate.ToString("f2") + L" = $" + dCalculationResult.ToString("f2");
					strPrintText = strDocumentBeginning + strReportHeading + strReportBody;
					strPrintText += "\\par}";
				 //This section creates the report document and then opens it
			 	 String^ strFileName = Environment::GetFolderPath( Environment::SpecialFolder::InternetCache) + L"\\report.rtf";
				 StreamWriter^ sw = gcnew StreamWriter(strFileName);
				 sw->WriteLine(this->strPrintText);
				 sw->Flush();
				 sw->Close();
				 Process^ objProcess = gcnew Process;
				 objProcess->StartInfo->FileName = strFileName;
				 objProcess->Start();

			 }
private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->Close();
		 }
private: System::Void txtbxMonthYear_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			System::DateTime dteCurrentMonthYear, dtePreviousMonthYear, dteTemp;
			DateTime::TryParse(((System::Windows::Forms::TextBox^)sender)->Text, dteTemp);
			if(dteTemp == DateTime::MinValue)
			{
				e->Cancel = true;
			}
			else
			{
				//These three lines convert the date to Month and Year format
				DateTimeFormatInfo^ dtfMonthYear = gcnew DateTimeFormatInfo();
				dtfMonthYear->YearMonthPattern = "MMMM yyyy";
				((System::Windows::Forms::TextBox^)sender)->Text = dteTemp.ToString("y", dtfMonthYear);

				e->Cancel = false;
			}

		 }
private: System::Void txtbxBusinessMileage_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			 int nTemp = 0;
			 if(Int32::TryParse(((TextBox^)sender)->Text,nTemp))
			 {
				 ((TextBox^)sender)->Text = nTemp.ToString();
			 }
			 else
			 {
				 if(((TextBox^)sender)->Text == "")
					 ((TextBox^)sender)->Text = "0";
				 else
					 e->Cancel = true;
			 }
		 }
private: System::Void txtbxIRSRate_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			 double dTemp = 0;
			 if(Double::TryParse(((TextBox^)sender)->Text,dTemp))
			 {
				 ((TextBox^)sender)->Text = dTemp.ToString("f2");
			 }
			 else
			 {
				 if(((TextBox^)sender)->Text == "")
					 ((TextBox^)sender)->Text = "0.00";
				 else
					 e->Cancel = true;
			 }

		 }
};
}
