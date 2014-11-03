#pragma once
#include "frmPrintWindow.h"
#include "frmVehicleReportMenu.h"
#include "BEOPSGlobals.h"
namespace BEOPS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	/// <summary>
	/// Summary for Reports
	/// </summary>
	public ref class frmReports : public System::Windows::Forms::Form
	{
	public:
		frmReports(void)
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
		~frmReports()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnInventoryByItem;
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Button^  btnMonthly;
	private: System::Windows::Forms::Button^  btnVehicleReport;
	protected: 

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
			this->btnInventoryByItem = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnMonthly = (gcnew System::Windows::Forms::Button());
			this->btnVehicleReport = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnInventoryByItem
			// 
			this->btnInventoryByItem->Location = System::Drawing::Point(40, 12);
			this->btnInventoryByItem->Name = L"btnInventoryByItem";
			this->btnInventoryByItem->Size = System::Drawing::Size(112, 23);
			this->btnInventoryByItem->TabIndex = 0;
			this->btnInventoryByItem->Text = L"&Inventory By Item";
			this->btnInventoryByItem->UseVisualStyleBackColor = true;
			this->btnInventoryByItem->Click += gcnew System::EventHandler(this, &frmReports::btnInventoryByItem_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(61, 122);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 3;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmReports::btnClose_Click);
			// 
			// btnMonthly
			// 
			this->btnMonthly->Location = System::Drawing::Point(40, 42);
			this->btnMonthly->Name = L"btnMonthly";
			this->btnMonthly->Size = System::Drawing::Size(112, 23);
			this->btnMonthly->TabIndex = 1;
			this->btnMonthly->Text = L"&Monthly Report";
			this->btnMonthly->UseVisualStyleBackColor = true;
			this->btnMonthly->Click += gcnew System::EventHandler(this, &frmReports::btnMonthly_Click);
			// 
			// btnVehicleReport
			// 
			this->btnVehicleReport->Location = System::Drawing::Point(40, 72);
			this->btnVehicleReport->Name = L"btnVehicleReport";
			this->btnVehicleReport->Size = System::Drawing::Size(112, 23);
			this->btnVehicleReport->TabIndex = 2;
			this->btnVehicleReport->Text = L"&Vehicle Report";
			this->btnVehicleReport->UseVisualStyleBackColor = true;
			this->btnVehicleReport->Click += gcnew System::EventHandler(this, &frmReports::btnVehicleReport_Click);
			// 
			// frmReports
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(199, 157);
			this->Controls->Add(this->btnVehicleReport);
			this->Controls->Add(this->btnMonthly);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnInventoryByItem);
			this->Name = L"frmReports";
			this->Text = L"Reports";
			this->Load += gcnew System::EventHandler(this, &frmReports::frmReports_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmReports_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(BEOPSGlobals::datBEOPSData->arrInventory == nullptr)
					 btnInventoryByItem->Enabled=false;
				 if(BEOPSGlobals::datBEOPSData->arrInventory == nullptr || BEOPSGlobals::datBEOPSData->arrDaily == nullptr)
					 btnMonthly->Enabled=false;
			 }
	private: System::Void btnInventoryByItem_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 //This function will create the RTF code and open the document
				 CultureInfo^ ci = gcnew CultureInfo("en-us");
				 int nIndex = 0;
				 double dblUnitValue;
				 double dblCaseCost;
				 double dblEndingValue;
				 String^ strPrintText = "";
				 String^ strReportName = "Inventory By Item Report";
				 String^ strDocumentBeginning = 
					 L"{\\rtf1\\ansi\\ansicpg1252\\deff0" + //rtf1 means version 1. fbidis is unknown. ansi character set. ansicpg1252 is US Windows unicode to ansi conversion. deff0 make f0 the default font
						L"{\\fonttbl" + //The font table defines the fonts used in the document f0-3 are defined below inside the font table definition
							L"{\\f0\\froman\\fcharset128 Times New Roman;}}" + 
						L"{\\colortbl ;\\red0\\green0\\blue0;}" + //color table for the colors used in the document. The starting ; means c0 is "auto" color
						L"\\margl360\\margr360\\margt360\\margb360\\footery360" + //sets up the margins for a quarter inch. Note that you need footery360 to resize the footer or margb won't work.
						//Below is the footer code including use of paragraph formatting and fields for special data including PAGE NUMPAGES and DATE (current)
						L"{\\footer \\fs20\\tx5000\\tqr\\tx11000 BEOPS " + BEOPSGlobals::datBEOPSData->dblVersionNumber.ToString("F1") + "\\tab " + 
						L"Page {\\field{\\*\\fldinst  PAGE }{\\fldrslt}} of {\\field{\\*\\fldinst NUMPAGES}{\\fldrslt}}\\tab "+ 
						L"Printed {\\field{\\*\\fldinst DATE}{\\fldrslt}}\\par\\pard}";
				 //In the code below viewkind 4 is for normal layout (not print preview). UC1 si a special unicode character - needed?. pard stops formatting from inheriting forward.  qc means centered. cf1 mean foreground color 1. kerning, to kern of course. f1 is font 1. fs20 is font size 10 (divide by 2) b for bold and b0 to turn it off. tx2160 is tab stop
				 String^ strReportHeading = 
						L"\\qc\\lang1033\\b\\fs32 Ohio Rehabilitation Services Commission\\par " + strReportName + "\\par\\par\\pard\\tx2160\\b\\fs24 BSVI Area \\b0 " + BEOPSGlobals::datBEOPSData->strBSVIArea + 
						L"\\tab\\b Operator Number \\b0 " + BEOPSGlobals::datBEOPSData->strOperatorNumber + L"\\tab\\b Facility Number \\b0 " + BEOPSGlobals::datBEOPSData->strFacilityNumber + 
						L"\\par\\b Operator Name\\b0\\tab " + BEOPSGlobals::datBEOPSData->strOperatorName + L"\\par\\b Address\\b0\\tab " + BEOPSGlobals::datBEOPSData->strOperatorAddress1 + L",  " + 
						BEOPSGlobals::datBEOPSData->strOperatorCity + L", " + BEOPSGlobals::datBEOPSData->strOperatorState + L" " + BEOPSGlobals::datBEOPSData->strOperatorZip + L"\\par\\par\\pard";
				 String^ strColumnHeading = L"\\tx3600\\tx4536\\tx5760\\tx7920\\tx9360\\fs20\\b Item\\tab Count\\tab Case Cost\\tab Number In Case\\tab Unit Value\\tab Ending Value\\b0\\par\\pard";
				 String^ strDataTabs = L"\\tqr\\tx3960\\tqdec\\tx5040\\tqdec\\tx6480\\tqdec\\tx8280\\tqdec\\tx10080 ";
				 strPrintText = strDocumentBeginning;
				 strPrintText+=strReportHeading;
				 strPrintText+=strColumnHeading;
				 strPrintText+=strDataTabs;
				 BEOPSGlobals::datBEOPSData->arrInventory->Sort();
				 while(nIndex<BEOPSGlobals::datBEOPSData->arrInventory->Count)
				 {
					 dblCaseCost = (((BEOPSInventory^)BEOPSGlobals::datBEOPSData->arrInventory[nIndex])->dblUnitWholesaleCost*((BEOPSInventory^)BEOPSGlobals::datBEOPSData->arrInventory[nIndex])->dblNumberInCase);
					 dblUnitValue = ((BEOPSInventory^)BEOPSGlobals::datBEOPSData->arrInventory[nIndex])->dblUnitWholesaleCost;
					 dblEndingValue = dblUnitValue * ((BEOPSInventory^)BEOPSGlobals::datBEOPSData->arrInventory[nIndex])->dblUnitCount;
					 strPrintText+=  
						 ((BEOPSInventory^)BEOPSGlobals::datBEOPSData->arrInventory[nIndex])->strItemName + L"\\tab " + System::Convert::ToString(((BEOPSInventory^)BEOPSGlobals::datBEOPSData->arrInventory[nIndex])->dblUnitCount) + 
						 L"\\tab " + dblCaseCost.ToString("C", ci) + L"\\tab " + System::Convert::ToString(((BEOPSInventory^)BEOPSGlobals::datBEOPSData->arrInventory[nIndex])->dblNumberInCase) + L"\\tab " + 
						 dblUnitValue.ToString("C", ci) + L"\\tab " + dblEndingValue.ToString("C", ci) + L"\\par ";
					 nIndex++;
				 }
				 strPrintText+="\\par}";
				 String^ strFileName = Environment::GetFolderPath( Environment::SpecialFolder::InternetCache) + L"\\report.rtf";
				 StreamWriter^ sw = gcnew StreamWriter(strFileName);
				 sw->WriteLine(strPrintText);
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
	private: System::Void btnMonthly_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 frmPrintWindow^ dlgPrintWindow= gcnew frmPrintWindow;
				 dlgPrintWindow->ShowDialog();

			 }
private: System::Void btnVehicleReport_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 frmVehicleReportMenu^ dlgVehicleReportMenu = gcnew frmVehicleReportMenu();
			 dlgVehicleReportMenu->ShowDialog();
		 }
};
}
