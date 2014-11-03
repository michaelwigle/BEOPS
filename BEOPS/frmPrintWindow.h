#pragma once
#include "BEOPSGlobals.h"
namespace BEOPS {

	using namespace System;
	using namespace System::Globalization;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Printing;
	using namespace System::IO;
	

	/// <summary>
	/// Summary for frmPrintWindow
	/// </summary>
	public ref class frmPrintWindow : public System::Windows::Forms::Form
	{
	public:
		frmPrintWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: String^ strPrintText;
	private: System::Windows::Forms::Label^  lblDate;
	private: System::Windows::Forms::TextBox^  txtbxDate;
	private: System::Windows::Forms::GroupBox^  grpLastMonth;
	private: System::Windows::Forms::CheckBox^  chkbxLastEstimate;
	private: System::Windows::Forms::TextBox^  txtbxLastOther;
	private: System::Windows::Forms::RadioButton^  rdoLastOther;
	private: System::Windows::Forms::RadioButton^  rdoLastRecorded;
	private: System::Windows::Forms::CheckBox^  chkbxLastUpdate;
	private: System::Windows::Forms::GroupBox^  grpThisMonth;
	private: System::Windows::Forms::CheckBox^  chkbxThisUpdate;
	private: System::Windows::Forms::CheckBox^  chkbxThisEstimate;
	private: System::Windows::Forms::TextBox^  txtbxThisOther;
	private: System::Windows::Forms::RadioButton^  rdoThisOther;
	private: System::Windows::Forms::RadioButton^  rdoThisCurrent;
	private: System::Windows::Forms::RadioButton^  rdoThisRecorded;
	private: System::Windows::Forms::Button^  btnPrint;
	private: System::Windows::Forms::Button^  btnClose;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmPrintWindow()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->btnPrint = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->lblDate = (gcnew System::Windows::Forms::Label());
			this->txtbxDate = (gcnew System::Windows::Forms::TextBox());
			this->grpLastMonth = (gcnew System::Windows::Forms::GroupBox());
			this->chkbxLastUpdate = (gcnew System::Windows::Forms::CheckBox());
			this->chkbxLastEstimate = (gcnew System::Windows::Forms::CheckBox());
			this->txtbxLastOther = (gcnew System::Windows::Forms::TextBox());
			this->rdoLastOther = (gcnew System::Windows::Forms::RadioButton());
			this->rdoLastRecorded = (gcnew System::Windows::Forms::RadioButton());
			this->grpThisMonth = (gcnew System::Windows::Forms::GroupBox());
			this->chkbxThisUpdate = (gcnew System::Windows::Forms::CheckBox());
			this->chkbxThisEstimate = (gcnew System::Windows::Forms::CheckBox());
			this->txtbxThisOther = (gcnew System::Windows::Forms::TextBox());
			this->rdoThisOther = (gcnew System::Windows::Forms::RadioButton());
			this->rdoThisCurrent = (gcnew System::Windows::Forms::RadioButton());
			this->rdoThisRecorded = (gcnew System::Windows::Forms::RadioButton());
			this->grpLastMonth->SuspendLayout();
			this->grpThisMonth->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnPrint
			// 
			this->btnPrint->Location = System::Drawing::Point(16, 247);
			this->btnPrint->Name = L"btnPrint";
			this->btnPrint->Size = System::Drawing::Size(75, 23);
			this->btnPrint->TabIndex = 4;
			this->btnPrint->Text = L"&Print";
			this->btnPrint->UseVisualStyleBackColor = true;
			this->btnPrint->Click += gcnew System::EventHandler(this, &frmPrintWindow::btnPrint_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(98, 247);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 5;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmPrintWindow::btnClose_Click);
			// 
			// lblDate
			// 
			this->lblDate->AutoSize = true;
			this->lblDate->Location = System::Drawing::Point(13, 13);
			this->lblDate->Name = L"lblDate";
			this->lblDate->Size = System::Drawing::Size(30, 13);
			this->lblDate->TabIndex = 22;
			this->lblDate->Text = L"Date";
			// 
			// txtbxDate
			// 
			this->txtbxDate->Location = System::Drawing::Point(50, 13);
			this->txtbxDate->Name = L"txtbxDate";
			this->txtbxDate->Size = System::Drawing::Size(100, 20);
			this->txtbxDate->TabIndex = 1;
			this->txtbxDate->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmPrintWindow::txtbxDate_Validating);
			// 
			// grpLastMonth
			// 
			this->grpLastMonth->Controls->Add(this->chkbxLastUpdate);
			this->grpLastMonth->Controls->Add(this->chkbxLastEstimate);
			this->grpLastMonth->Controls->Add(this->txtbxLastOther);
			this->grpLastMonth->Controls->Add(this->rdoLastOther);
			this->grpLastMonth->Controls->Add(this->rdoLastRecorded);
			this->grpLastMonth->Location = System::Drawing::Point(16, 51);
			this->grpLastMonth->Name = L"grpLastMonth";
			this->grpLastMonth->Size = System::Drawing::Size(200, 168);
			this->grpLastMonth->TabIndex = 2;
			this->grpLastMonth->TabStop = false;
			this->grpLastMonth->Text = L"Last Month\'s Closing Inventory";
			// 
			// chkbxLastUpdate
			// 
			this->chkbxLastUpdate->AutoSize = true;
			this->chkbxLastUpdate->Location = System::Drawing::Point(7, 142);
			this->chkbxLastUpdate->Name = L"chkbxLastUpdate";
			this->chkbxLastUpdate->Size = System::Drawing::Size(114, 17);
			this->chkbxLastUpdate->TabIndex = 5;
			this->chkbxLastUpdate->Text = L"Update Inventory\?";
			this->chkbxLastUpdate->UseVisualStyleBackColor = true;
			// 
			// chkbxLastEstimate
			// 
			this->chkbxLastEstimate->AutoSize = true;
			this->chkbxLastEstimate->Location = System::Drawing::Point(7, 118);
			this->chkbxLastEstimate->Name = L"chkbxLastEstimate";
			this->chkbxLastEstimate->Size = System::Drawing::Size(72, 17);
			this->chkbxLastEstimate->TabIndex = 4;
			this->chkbxLastEstimate->Text = L"Estimate\?";
			this->chkbxLastEstimate->UseVisualStyleBackColor = true;
			// 
			// txtbxLastOther
			// 
			this->txtbxLastOther->Location = System::Drawing::Point(7, 68);
			this->txtbxLastOther->Name = L"txtbxLastOther";
			this->txtbxLastOther->Size = System::Drawing::Size(100, 20);
			this->txtbxLastOther->TabIndex = 3;
			this->txtbxLastOther->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmPrintWindow::txtbxLastOther_Validating);
			// 
			// rdoLastOther
			// 
			this->rdoLastOther->AutoSize = true;
			this->rdoLastOther->Location = System::Drawing::Point(7, 44);
			this->rdoLastOther->Name = L"rdoLastOther";
			this->rdoLastOther->Size = System::Drawing::Size(103, 17);
			this->rdoLastOther->TabIndex = 2;
			this->rdoLastOther->Text = L"Use Other Value";
			this->rdoLastOther->UseVisualStyleBackColor = true;
			this->rdoLastOther->CheckedChanged += gcnew System::EventHandler(this, &frmPrintWindow::rdoLastOther_CheckedChanged);
			// 
			// rdoLastRecorded
			// 
			this->rdoLastRecorded->AutoSize = true;
			this->rdoLastRecorded->Location = System::Drawing::Point(7, 20);
			this->rdoLastRecorded->Name = L"rdoLastRecorded";
			this->rdoLastRecorded->Size = System::Drawing::Size(124, 17);
			this->rdoLastRecorded->TabIndex = 1;
			this->rdoLastRecorded->Text = L"Use Recorded Value";
			this->rdoLastRecorded->UseVisualStyleBackColor = true;
			this->rdoLastRecorded->CheckedChanged += gcnew System::EventHandler(this, &frmPrintWindow::rdoLastRecorded_CheckedChanged);
			// 
			// grpThisMonth
			// 
			this->grpThisMonth->Controls->Add(this->chkbxThisUpdate);
			this->grpThisMonth->Controls->Add(this->chkbxThisEstimate);
			this->grpThisMonth->Controls->Add(this->txtbxThisOther);
			this->grpThisMonth->Controls->Add(this->rdoThisOther);
			this->grpThisMonth->Controls->Add(this->rdoThisCurrent);
			this->grpThisMonth->Controls->Add(this->rdoThisRecorded);
			this->grpThisMonth->Location = System::Drawing::Point(223, 51);
			this->grpThisMonth->Name = L"grpThisMonth";
			this->grpThisMonth->Size = System::Drawing::Size(200, 168);
			this->grpThisMonth->TabIndex = 3;
			this->grpThisMonth->TabStop = false;
			this->grpThisMonth->Text = L"This Month\'s Closing Inventory";
			// 
			// chkbxThisUpdate
			// 
			this->chkbxThisUpdate->AutoSize = true;
			this->chkbxThisUpdate->Location = System::Drawing::Point(6, 142);
			this->chkbxThisUpdate->Name = L"chkbxThisUpdate";
			this->chkbxThisUpdate->Size = System::Drawing::Size(114, 17);
			this->chkbxThisUpdate->TabIndex = 6;
			this->chkbxThisUpdate->Text = L"Update Inventory\?";
			this->chkbxThisUpdate->UseVisualStyleBackColor = true;
			// 
			// chkbxThisEstimate
			// 
			this->chkbxThisEstimate->AutoSize = true;
			this->chkbxThisEstimate->Location = System::Drawing::Point(6, 118);
			this->chkbxThisEstimate->Name = L"chkbxThisEstimate";
			this->chkbxThisEstimate->Size = System::Drawing::Size(72, 17);
			this->chkbxThisEstimate->TabIndex = 5;
			this->chkbxThisEstimate->Text = L"Estimate\?";
			this->chkbxThisEstimate->UseVisualStyleBackColor = true;
			this->chkbxThisEstimate->CheckedChanged += gcnew System::EventHandler(this, &frmPrintWindow::chkbxThisEstimate_CheckedChanged);
			// 
			// txtbxThisOther
			// 
			this->txtbxThisOther->Location = System::Drawing::Point(6, 91);
			this->txtbxThisOther->Name = L"txtbxThisOther";
			this->txtbxThisOther->Size = System::Drawing::Size(100, 20);
			this->txtbxThisOther->TabIndex = 4;
			this->txtbxThisOther->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmPrintWindow::txtbxThisOther_Validating);
			// 
			// rdoThisOther
			// 
			this->rdoThisOther->AutoSize = true;
			this->rdoThisOther->Location = System::Drawing::Point(6, 67);
			this->rdoThisOther->Name = L"rdoThisOther";
			this->rdoThisOther->Size = System::Drawing::Size(103, 17);
			this->rdoThisOther->TabIndex = 3;
			this->rdoThisOther->TabStop = true;
			this->rdoThisOther->Text = L"Use Other Value";
			this->rdoThisOther->UseVisualStyleBackColor = true;
			this->rdoThisOther->CheckedChanged += gcnew System::EventHandler(this, &frmPrintWindow::rdoThisOther_CheckedChanged);
			// 
			// rdoThisCurrent
			// 
			this->rdoThisCurrent->AutoSize = true;
			this->rdoThisCurrent->Location = System::Drawing::Point(6, 43);
			this->rdoThisCurrent->Name = L"rdoThisCurrent";
			this->rdoThisCurrent->Size = System::Drawing::Size(158, 17);
			this->rdoThisCurrent->TabIndex = 2;
			this->rdoThisCurrent->TabStop = true;
			this->rdoThisCurrent->Text = L"Use Current Inventory Value";
			this->rdoThisCurrent->UseVisualStyleBackColor = true;
			this->rdoThisCurrent->CheckedChanged += gcnew System::EventHandler(this, &frmPrintWindow::rdoThisCurrent_CheckedChanged);
			// 
			// rdoThisRecorded
			// 
			this->rdoThisRecorded->AutoSize = true;
			this->rdoThisRecorded->Location = System::Drawing::Point(6, 19);
			this->rdoThisRecorded->Name = L"rdoThisRecorded";
			this->rdoThisRecorded->Size = System::Drawing::Size(124, 17);
			this->rdoThisRecorded->TabIndex = 1;
			this->rdoThisRecorded->TabStop = true;
			this->rdoThisRecorded->Text = L"Use Recorded Value";
			this->rdoThisRecorded->UseVisualStyleBackColor = true;
			this->rdoThisRecorded->TextChanged += gcnew System::EventHandler(this, &frmPrintWindow::rdoThisRecorded_TextChanged);
			// 
			// frmPrintWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 282);
			this->Controls->Add(this->grpThisMonth);
			this->Controls->Add(this->grpLastMonth);
			this->Controls->Add(this->txtbxDate);
			this->Controls->Add(this->lblDate);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnPrint);
			this->Name = L"frmPrintWindow";
			this->Text = L"Print MOR";
			this->Load += gcnew System::EventHandler(this, &frmPrintWindow::frmPrintWindow_Load);
			this->grpLastMonth->ResumeLayout(false);
			this->grpLastMonth->PerformLayout();
			this->grpThisMonth->ResumeLayout(false);
			this->grpThisMonth->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmPrintWindow_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 btnPrint->Enabled = false;
				 rdoLastOther->Checked = true;
				 rdoThisOther->Checked = true;
			 }

			 
private: System::Void btnPrint_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
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

/*private: System::Void frmPrintWindow::MOR_After_Update(System::Object^  sender, System::EventArgs^  e)
		{
			//TODO: Turn this function into a generic one to validate data and put in local variables for the string builder
			//System::Type objType = sender->GetType;
			if(sender->GetType() == TextBox::typeid && ((TextBox^)sender)->Name == "txtbxDate")
			{
				//Validate it and put it in the local variables
				System::DateTime dteTemp;
				DateTime::TryParse(((System::Windows::Forms::TextBox^)sender)->Text, dteTemp);
				if(dteTemp != DateTime::MinValue)
				{
					this->dteDate = dteTemp;
					BuildMORPrintString();
					DateTimeFormatInfo^ dtfMonthYear = gcnew DateTimeFormatInfo();
					dtfMonthYear->YearMonthPattern = "MMMM yyyy";
					((System::Windows::Forms::TextBox^)sender)->Text = dteDate.ToString("y", dtfMonthYear);
				}
				else
					this->strPrintText = "";

			}
			if(sender->GetType() == TextBox::typeid && ((TextBox^)sender)->Name == "txtbxInventory")
			{
				double dblTemp;
				if(Double::TryParse(((System::Windows::Forms::TextBox^)sender)->Text, dblTemp))
				{
					this->dblInventory = dblTemp;
					BuildMORPrintString();
				}
				else
					this->dblInventory = -1;

			}
			if(sender->GetType() == RadioButton::typeid)
			{
				if(((System::Windows::Forms::RadioButton^)sender)->Name == "rdoActual" && ((System::Windows::Forms::RadioButton^)sender)->Checked == true)
				{
					this->bActualInventory = true;
					BuildMORPrintString();
				}
				else
				{
					this->bActualInventory = false;
					BuildMORPrintString();
				}

			}
			if(sender->GetType() == CheckBox::typeid && ((System::Windows::Forms::CheckBox^)sender)->Checked == true)
			{
				//TODO: I need to calculate the actual inventory here and put it in dblInventory
				this->dblInventory = BEOPSGlobals::datBEOPSData->GetWholesaleInventoryValue();
				bUseActualInventory = true;
				BuildMORPrintString();
			}
			else
			{
				bUseActualInventory = false;
				BuildMORPrintString();
			}


		}*/
private: System::Void BuildMORPrintString()
		{
			double dblLottery, dblCatering, dblMiscellaneous, dblStock, dblOther, dblWages, dblDraw, dblClosingCash, dblReceipts, dblServiceCharge, dblPriorClosing=0;
			double dblCurrentInventory, dblPreviousInventory;
			ArrayList^ arrOtherExpenses;
			String^ strActualOrEstimate;
			int nExpenseIndex, nIndex = 0, nDailyIndex=0;
			System::DateTime dteDate;
			DateTimeFormatInfo^ dtfMonthYear = gcnew DateTimeFormatInfo();
			dtfMonthYear->YearMonthPattern = "MMMM yyyy";
			DateTime::TryParse(((System::Windows::Forms::TextBox^)txtbxDate)->Text, dteDate);
			if(dteDate!=DateTime::MinValue)
			{
				//We have a valid date
				DateTime dtePreviousMonth = dteDate.AddMonths(-1);
				ArrayList^ arrDailys = BEOPSGlobals::datBEOPSData->GetMonthOfDailys(dteDate);
				if (arrDailys!= nullptr)
				{
					//We have dailys in that month
					if( ((this->rdoLastOther->Checked == true && txtbxLastOther->Text !=L"") || (rdoLastRecorded->Checked)) &&
						((this->rdoThisOther->Checked && txtbxThisOther->Text !=L"") ||(rdoThisCurrent->Checked)||(rdoThisRecorded->Checked)))  // || (this->rdoLastRecorded == true && this->dblInventory > -1))
					{
						//We have valid values for Inventory
						this->btnPrint->Enabled = true;
						arrDailys->Sort();
						dblPriorClosing = BEOPSGlobals::datBEOPSData->GetStartingBalance(((BEOPSDaily^)arrDailys[0])->dteDate);
						 
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
							L"\\qc\\lang1033\\b\\fs32 Ohio Rehabilitation Services Commission\\par Monthly Operating Report\\par\\par\\pard\\tx2160\\b\\fs24 BSVI Area \\b0 " + BEOPSGlobals::datBEOPSData->strBSVIArea + 
							L"\\tab\\b Operator Number \\b0 " + BEOPSGlobals::datBEOPSData->strOperatorNumber + L"\\tab\\b Facility Number \\b0 " + BEOPSGlobals::datBEOPSData->strFacilityNumber + 
							L"\\tab\\tab\\b Report Date \\b0  " + dteDate.ToString("y", dtfMonthYear) +
							L" \\par\\b Operator Name\\b0\\tab " + BEOPSGlobals::datBEOPSData->strOperatorName + L"\\tab\\tab\\tab\\b Prior Month's Closing\\b0\\tab " + dblPriorClosing.ToString("f2") + L"\\par " +
							L"\\par\\b Address\\b0\\tab " + BEOPSGlobals::datBEOPSData->strOperatorAddress1 + L",  " + 
							BEOPSGlobals::datBEOPSData->strOperatorCity + L", " + BEOPSGlobals::datBEOPSData->strOperatorState + L" " + BEOPSGlobals::datBEOPSData->strOperatorZip + L"\\par\\par\\pard";
						String^ strColumnHeading = 
							L"\\tqc\\tx500\\tqc\\tx1410\\tqc\\tx2475\\tqc\\tx3435\\tqc\\tx4260\\tqc\\tx5430\\tqc\\tx6645\\tqc\\tx7695\\tqc\\tx9015\\tqc\\tx10320\\fs20\\b \\tab Date\\tab Lottery\\tab Catering\\tab Misc" + 
							L"\\tab Stock\\tab Other\\tab Wages\\tab Draw\\tab Closing Cash\\tab Receipts\\b0\\par\\pard ";
						String^ strDataTabs = 
							L"\\tx90\\tqdec\\tx1440\\tqdec\\tx2520\\tqdec\\tx3375\\tqdec\\tx4245\\tx4905\\tqdec\\tx5655\\tqdec\\tx6705\\tqdec\\tx7695\\tqdec\\tx9165\\tqdec\\tx10320 ";
						String^ strRows = "";
							 
						while(nIndex<arrDailys->Count)
						{
							//This loop writes each row for each day. 
							arrOtherExpenses = BEOPSGlobals::datBEOPSData->GetOtherExpenses(((BEOPSDaily^)arrDailys[nIndex])->dteDate);
							nExpenseIndex = 0;
							dblClosingCash = BEOPSGlobals::datBEOPSData->GetEndingBalance(((BEOPSDaily^)arrDailys[nIndex])->dteDate);
							dblLottery = ((BEOPSDaily^)arrDailys[nIndex])->GetIncome(L"Ohio Lottery");
							dblCatering = ((BEOPSDaily^)arrDailys[nIndex])->GetIncome(L"Catering");
							dblMiscellaneous = ((BEOPSDaily^)arrDailys[nIndex])->GetIncome(L"Miscellaneous");
							dblStock = ((BEOPSDaily^)arrDailys[nIndex])->GetExpense(L"Stock Purchased");
								 
							dblWages = ((BEOPSDaily^)arrDailys[nIndex])->GetExpense(L"Wages");
							dblDraw = ((BEOPSDaily^)arrDailys[nIndex])->GetExpense(L"Draw");
							dblReceipts = ((BEOPSDaily^)arrDailys[nIndex])->GetIncome(L"Sales");
							
							//I'll start with the code for the first row of each day
							strRows += ((BEOPSDaily^)arrDailys[nIndex])->dteDate.ToString("d") + L"\\tab " +  dblLottery.ToString("f2") + "\\tab " +
								dblCatering.ToString("f2") + "\\tab " + dblMiscellaneous.ToString("f2") + "\\tab " + dblStock.ToString("f2");
							
							//This puts in first other expense if applicable
							if(arrOtherExpenses->Count>0)
							{
								dblOther = ((Expense^)arrOtherExpenses[nExpenseIndex])->dblExpAmt;
								strRows += "\\tab " + BEOPSGlobals::GetExpenseCode(((Expense^)arrOtherExpenses[nExpenseIndex])->strExpName) + "\\tab " + dblOther.ToString("f2") + "\\tab ";
							}
							else
								strRows += "\\tab\\tab\\tab ";
							strRows +=  dblWages.ToString("f2") + "\\tab " + dblDraw.ToString("f2") + "\\tab " + dblClosingCash.ToString("f2") + "\\tab " + dblReceipts.ToString("f2") + "\\par ";
							
							//Now I add other expense lines if applicable
							nExpenseIndex++;
							while (nExpenseIndex<arrOtherExpenses->Count)
							{
								dblOther = ((Expense^)arrOtherExpenses[nExpenseIndex])->dblExpAmt;
								strRows += "\\tab\\tab\\tab\\tab\\tab\\tab " + BEOPSGlobals::GetExpenseCode(((Expense^)arrOtherExpenses[nExpenseIndex])->strExpName) + "\\tab " + dblOther.ToString("f2") + "\\par ";
								nExpenseIndex++;
							}
							delete arrOtherExpenses;
							nIndex++;
						}
						//Now I tack on the service Charge if there is one
						dblServiceCharge = BEOPSGlobals::datBEOPSData->GetExpenseTotals(L"Service Charge",arrDailys);
						if(dblServiceCharge>0)
							strRows += "\\tab\\tab\\tab\\tab\\tab\\tab\\tab\\tab\\tab SC " + dblServiceCharge.ToString("f2") + "\\par ";
						
						//Now I calculate the totals line
						dblLottery = BEOPSGlobals::datBEOPSData->GetIncomeTotals(L"Lottery",arrDailys);
						dblCatering = BEOPSGlobals::datBEOPSData->GetIncomeTotals(L"Catering",arrDailys);
						dblMiscellaneous = BEOPSGlobals::datBEOPSData->GetIncomeTotals(L"Miscellaneous",arrDailys);
						dblReceipts = BEOPSGlobals::datBEOPSData->GetIncomeTotals(L"Sales",arrDailys);
						dblStock = BEOPSGlobals::datBEOPSData->GetExpenseTotals(L"Stock Purchased",arrDailys);
						dblWages = BEOPSGlobals::datBEOPSData->GetExpenseTotals(L"Wages",arrDailys);
						dblDraw = BEOPSGlobals::datBEOPSData->GetExpenseTotals(L"Draw",arrDailys) + dblServiceCharge;
						dblOther = BEOPSGlobals::datBEOPSData->GetOtherExpenseTotals(arrDailys);
						if (chkbxThisEstimate->Checked)
							strActualOrEstimate = "Estimated";
						else
							strActualOrEstimate = "Actual";
						
						//This section calculates current inventory
						if(rdoThisRecorded->Checked)
						{
							
							for(nIndex=0;nIndex<BEOPSGlobals::datBEOPSData->arrMonthlyInventory->Count;nIndex++)
							{
								if(BEOPSGlobals::SameMonthAndYear(dteDate, ((MonthlyInventory^)BEOPSGlobals::datBEOPSData->arrMonthlyInventory[nIndex])->dteMonthYearEnding))
								{
									dblCurrentInventory = ((MonthlyInventory^)BEOPSGlobals::datBEOPSData->arrMonthlyInventory[nIndex])->dblEndingInventory;
									nIndex = BEOPSGlobals::datBEOPSData->arrMonthlyInventory->Count;
								}
							}

						}
						else
						{
							if(rdoThisCurrent->Checked)
							{
								//Use current inventory value
								dblCurrentInventory = BEOPSGlobals::datBEOPSData->GetWholesaleInventoryValue();
							}
							else
							{
								//Use other value
								dblCurrentInventory = System::Convert::ToDouble(txtbxThisOther->Text);
							}
						}
						
						//Now I write the totals to the string
						String^ strTotals = 
							L"\\par\\b\\fs20 Totals\\b0\\tab " + dblLottery.ToString("f2") + L"\\tab " + dblCatering.ToString("f2") + L"\\tab " + dblMiscellaneous.ToString("f2") + L"\\tab " + dblStock.ToString("f2") +
							L"\\tab\\tab " + dblOther.ToString("f2") + L"\\tab " + dblWages.ToString("f2") + L"\\tab " + dblDraw.ToString("f2") + L"\\tab\\tab " + dblReceipts.ToString("f2") + 
							L"\\par\\par " +  strActualOrEstimate + L" End Of Month Inventory\\tab " + dblCurrentInventory.ToString("f2") + L"\\tab\\tab\\tab\\tab Closing Cash\\tab " + dblClosingCash.ToString("f2");
						//Here we put page 1 of the MOR in the strPrintText variable.
						this->strPrintText = strDocumentBeginning + strReportHeading + strColumnHeading + strDataTabs + strRows + strTotals + "\\par\\pard ";
						
						//Now we do page 2 of the MOR
						//First I calculate previous month ending inventory
						if(rdoLastRecorded->Checked)
						{
							for(nIndex=0;nIndex<BEOPSGlobals::datBEOPSData->arrMonthlyInventory->Count;nIndex++)
							{
								if(BEOPSGlobals::SameMonthAndYear(dtePreviousMonth, ((MonthlyInventory^)BEOPSGlobals::datBEOPSData->arrMonthlyInventory[nIndex])->dteMonthYearEnding))
								{
									dblPreviousInventory = ((MonthlyInventory^)BEOPSGlobals::datBEOPSData->arrMonthlyInventory[nIndex])->dblEndingInventory;
									nIndex = BEOPSGlobals::datBEOPSData->arrMonthlyInventory->Count;
								}

							}
						}
						else
							dblPreviousInventory = System::Convert::ToDouble(txtbxLastOther->Text);
						//Next I do the rest of the calculations for the page
						double dblCostOfGoodsSold = dblStock+dblPreviousInventory-dblCurrentInventory;
						double dblGrossProfit = dblReceipts - dblCostOfGoodsSold;
						double dblFacilityOperatingProfit = dblGrossProfit - dblOther;
						double dblNetMonthlyBusinessProceeds = dblFacilityOperatingProfit - dblWages;
						double dblPreviousMonthsBalanceDueOperator = dblPreviousInventory + dblPriorClosing - BEOPSGlobals::datBEOPSData->dblAlternateInventory; 
						double dblTotalToDateBalanceDueOperator = dblNetMonthlyBusinessProceeds + dblPreviousMonthsBalanceDueOperator - dblDraw;
						double dblWorkingCapitalBeginningOfMonth = dblPreviousInventory + dblPriorClosing;
						double dblWorkingCapitalEndOfMonth = dblCurrentInventory + dblClosingCash;
						double dblServiceCharge; 
						if(dblNetMonthlyBusinessProceeds<=1000)
							dblServiceCharge = .1 * dblNetMonthlyBusinessProceeds;
						else
							if(dblNetMonthlyBusinessProceeds<=2500)
								dblServiceCharge = 100 + ((dblNetMonthlyBusinessProceeds-1000)*.15);
							else
								dblServiceCharge = 325 + ((dblNetMonthlyBusinessProceeds-2500)*.2);
						double dblPreviousServiceCharge = 0; //Must calculate!
						double dblCreditDueOnServiceCharges = 0; //Must calculate!

						//Now I start the report text
						strReportHeading = 
							L"\\pagebb\\par\\pard\\qc\\lang1033\\b\\fs32 Monthly Operating Report\\par " + "Summary Page" + "\\b0\\par\\par\\pard\\b\\fs24 Month Year\\b0  " + dteDate.ToString("y", dtfMonthYear) + 
							L"\\tab\\b Facility Number \\b0 " + BEOPSGlobals::datBEOPSData->strFacilityNumber + L"\\tab\\tab\\b Operator Number \\b0 " + BEOPSGlobals::datBEOPSData->strOperatorNumber +  
							L"\\tab\\b Status_____\\b0\\par\\par\\pard";
						strColumnHeading = 
							L"\\tx1425\\tx2310\\tx3510\\tx4410\\tx5640\\tx6975\\tx7965\\tx8955\\tab\\b\\fs20 Lottery\\tab Catering\\tab Misc\\tab Stock(2)\\tab Expenses(3)\\tab Wages(4)\\tab Draw(5)\\tab Closing(6)\\tab Receipts(7)\\b0\\par\\pard" +
							L"\\tqdec\\tx1860\\tqdec\\tx2775\\tqdec\\tx3795\\tqdec\\tx4830\\tqdec\\tx6165\\tqdec\\tx7455\\tqdec\\tx8430\\tqdec\\tx9570\\tqdec\\tx10530\\b Column Totals\\b0\\tab " +
							dblLottery.ToString("f2") + "\\tab " + dblCatering.ToString("f2") + "\\tab " + dblMiscellaneous.ToString("f2") + "\\tab " +dblStock.ToString("f2") + "\\tab " + dblOther.ToString("f2") + 
							L"\\tab " + dblWages.ToString("f2") + "\\tab " + dblDraw.ToString("f2") + "\\tab " + dblClosingCash.ToString("f2") + "\\tab " + dblReceipts.ToString("f2") + "\\par\\par\\pard ";
						strRows = 
							L"\\tx3795\\tqdec\\tx4830\\tx6165\\tx8430\\tqdec\\tx9570\\tqdec\\tx10530 A. Initial Inventory\\tab\\tab " + BEOPSGlobals::datBEOPSData->dblAlternateInventory.ToString("f2") + 
							L"\\par B. Last Month\'s Closing Inventory\\tab B1\\tab " + dblPreviousInventory.ToString("f2") + L"\\tab Opening Cash On Hand\\tab B2\\tab " + dblPriorClosing.ToString("f2") +
							L"\\par C. This Month\'s Closing Inventory\\tab C1\\tab " + dblCurrentInventory.ToString("f2") + L"\\tab Closing Cash On Hand\\tab C2\\tab " + dblClosingCash.ToString("f2") +
							L"\\par D. Cost of Goods Sold (Column 2 Plus B1 Minus C1) \\tab\\tab\\tab\\tab\\tab " + dblCostOfGoodsSold.ToString("f2") + L"\\par " + 
							L"E. Gross Profit (Column 7 Minus D)\\tab\\tab\\tab\\tab\\tab\\tab " + dblGrossProfit.ToString("f2") + L"\\par " +
							L"F. Other Expenses (Total Column 3)\\tab\\tab\\tab\\tab\\tab\\tab " + dblOther.ToString("f2") + L"\\par G. Facility Operating Profit\\tab\\tab\\tab\\tab\\tab\\tab " +
							dblFacilityOperatingProfit.ToString("f2") + L"\\par H. Gross Emploee Wages (Column 4)\\tab\\tab\\tab\\tab\\tab\\tab " + dblWages.ToString("f2") + L"\\par " +
							L"I. Net Monthly Business Proceeds (G Minus H)\\tab\\tab\\tab\\tab\\tab " + dblNetMonthlyBusinessProceeds.ToString("f2") + L"\\par " + 
							L"J. Previous Month\'s Balance Due Operator\\tab\\tab\\tab\\tab\\tab\\tab " + dblPreviousMonthsBalanceDueOperator.ToString("f2") + L"\\par " + 
							L"K. Total Draw (Coumn 5)\\tab\\tab\\tab\\tab\\tab\\tab " + dblDraw.ToString("f2") + L"\\par L. Total to Date Balance Due Operator (I, Plus J, Minus K) \\tab\\tab\\tab\\tab\\tab " +
							dblTotalToDateBalanceDueOperator.ToString("f2") + L"\\par M. Working Capital - Beginning of Month (Sum of B1 Plus B2)\\tab\\tab\\tab\\tab " + 
							dblWorkingCapitalBeginningOfMonth.ToString("f2") + L"\\par N. Working Capital - End of Month (Sum of C1 Plus C2)\\tab\\tab\\tab\\tab\\tab " + 
							dblWorkingCapitalEndOfMonth.ToString("f2") + L"\\par O. Service Charge Due for This Month ($0.00 if negative)\\tab\\tab\\tab\\tab\\tab " + 
							dblServiceCharge.ToString("f2") + L"\\par P. Previous Service Charge Due\\par Q. Credit Due on Service Charges\\par\\pard " +
							L"\\tx357\\tx2137\\tx2493\\tx4987\\tx6056\\tx7125\\tqr\\tx11000 R. Late Fees\\tab Report\\tab\\tab Inventory\\tab\\tab Total Fee\\par\\tab\\tab Service Charge" + 
							L"\\tab\\tab Co-Pay\\par\\tab\\tab (Specify Month)\\par\\par S. Total Charge Due (Sum of Lines O, P, And R Minus Q)\\par T. Payment Must Be Received or Postmarked By" +
							L"\\par\\tab\\tab\\tab\\tab\\b RSC Use Only\\b0\\par\\par\\tab Assigned\\tab\\tab Unassigned\\tab Proxy\\tab\\tab Unassigned And Received Net\\par\\par" + 
							L"\\tab\\tab\\tab B.E. Specialist's Initials\\tab Late Report\\tab\\tab Late Payment\\par\\par\\tab\\tab\\tab\\tab\\tab\\tab Process Date\\par\\pard";
						this->strPrintText += strReportHeading + strColumnHeading + strRows;
						//Now we do Page 3 of the MOR
						//Now I start the report
						//Reset any variables I have been reusing and create any new ones I need
						int nExpenseCodeIndex = 0, nDailyExpenseIndex = 0;
						double dExpenseCodeTotal = 0, dExpenseGrandTotal = 0;
						nExpenseIndex = 0;
						nDailyIndex = 0;
						strReportHeading = 
							L"\\pagebb\\par\\pard\\qc\\lang1033\\b\\fs32 Ohio Rehabilitation Services Commission\\par Expense Code Summarization Report\\b0\\par\\par\\pard";
						strColumnHeading = L"";
						strRows = L"\\ql\\fs20\\tx1900\\tqdec\\tx6165 ";
						BEOPSDaily^ objtmpDaily;
						Expense^ objtmpExpense;
						//First the calculations - I'll need to write some pretty fancy code to sort all of the expense codes by date and grouped by code
						//I'll create an array of Expenses loaded by the array of dailies (arrDailys) that loops through looking for each code in arrExpenseCodes
						//TODO: RECREATE THIS ENTIRE SECTION! IT DOESN'T COME CLOSE TO WORKING PROPERLY!
						while(nExpenseCodeIndex<BEOPSGlobals::arrExpenseCodes->Count)
						{
							//Because I have multiple Expenses with the code of R I have to filter out the extras to make the report work.
							if(nExpenseCodeIndex<26 ||nExpenseCodeIndex>31)
							{
								while(nDailyIndex<arrDailys->Count)
								{
									objtmpDaily = (BEOPSDaily^)arrDailys[nDailyIndex];
									//Get a pointer to the Expense array and then loop on that array
									while(nDailyExpenseIndex < objtmpDaily->arrExpenses->Count)
									{
										objtmpExpense = (Expense^)objtmpDaily->arrExpenses[nDailyExpenseIndex];
										//This compare appears to be working now
										if((objtmpExpense->strExpCode->ToUpper()) == (((String^)BEOPSGlobals::arrExpenseCodes[nExpenseCodeIndex])->ToUpper()))
										{
											//Now I need to write each line
											dExpenseCodeTotal += objtmpExpense->dblExpAmt;
											strRows = strRows + objtmpExpense->strExpCode->ToUpper() + L"\\tab "+ objtmpDaily->dteDate.ToString("d") + L"\\tab " + objtmpExpense->dblExpAmt.ToString("f2") + L"\\par ";
										}
										nDailyExpenseIndex++;
									}
									nDailyExpenseIndex = 0;
									nDailyIndex++;
								}
							}
							if (dExpenseCodeTotal > 0)
								strRows = strRows + L"\\pard\\tx200\\tqdec\\tx6165\\tab\\fs22\\b Total for Code " + (((String^)BEOPSGlobals::arrExpenseCodes[nExpenseCodeIndex])->ToUpper()) 
									+ L"\\tab $" + dExpenseCodeTotal.ToString("f2") + L"\\b0\\par\\par\\pard\\fs20\\tx1900\\tqdec\\tx6165 "; //Reduce the size
							nDailyIndex = 0;
							nExpenseCodeIndex++;
							dExpenseGrandTotal += dExpenseCodeTotal;
							dExpenseCodeTotal=0;

						}
						strRows = strRows + L"\\par\\pard\\tqdec\\tx6165\\fs22\\b Grand Total\\tab $" + dExpenseGrandTotal.ToString("f2") + L"\\par\\pard ";//Make font match totals
						//End of calculating expenses grouped by code.
						this->strPrintText += strReportHeading + strRows;
						//Now we put the final text into the RTF field and reformat the date in the Date field
						this->strPrintText += "\\par}";

					}
					else
						//We don't have valid settings for inventory calculation
						btnPrint->Enabled=false;
				}
				else
					//We have no Dailies in that month
					btnPrint->Enabled=false;
			}
			else
				//We have an invalid date
				btnPrint->Enabled=false;
		}
private: System::Void rdoLastOther_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(((RadioButton^)sender)->Checked == false)
				 txtbxLastOther->Enabled = false;
			 else
				 txtbxLastOther->Enabled = true;
			 BuildMORPrintString();
			 //btnPrint->Enabled = ReadyToPrint();
		 }
private: System::Void txtbxDate_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			System::DateTime dteCurrentMonthYear, dtePreviousMonthYear, dteTemp;
			DateTime::TryParse(((System::Windows::Forms::TextBox^)sender)->Text, dteTemp);
			if(dteTemp == DateTime::MinValue)
			{
				e->Cancel = true;
			}
			else
			{
				int nTemp=0;
				dteCurrentMonthYear = dteTemp;
				dtePreviousMonthYear = dteTemp.AddMonths(-1);
				//These three lines convert the date to Month and Year format
				DateTimeFormatInfo^ dtfMonthYear = gcnew DateTimeFormatInfo();
				dtfMonthYear->YearMonthPattern = "MMMM yyyy";
				((System::Windows::Forms::TextBox^)sender)->Text = dteCurrentMonthYear.ToString("y", dtfMonthYear);
				//Now check for valid monthly history record and enable the rdoLastRecorded accordingly
				for(nTemp=0;nTemp<BEOPSGlobals::datBEOPSData->arrMonthlyInventory->Count;nTemp++)
				{
					if(BEOPSGlobals::SameMonthAndYear(dtePreviousMonthYear,((MonthlyInventory^)BEOPSGlobals::datBEOPSData->arrMonthlyInventory[nTemp])->dteMonthYearEnding))
					{
						rdoLastRecorded->Enabled = true;
						nTemp=BEOPSGlobals::datBEOPSData->arrMonthlyInventory->Count;
					}
					else
					{
						rdoLastRecorded->Enabled = false;
						rdoLastOther->Checked = true;
					}
				}
				//Now check for existing current month inventory record
				for(nTemp=0;nTemp<BEOPSGlobals::datBEOPSData->arrMonthlyInventory->Count;nTemp++)
				{
					if(BEOPSGlobals::SameMonthAndYear(dteCurrentMonthYear,((MonthlyInventory^)BEOPSGlobals::datBEOPSData->arrMonthlyInventory[nTemp])->dteMonthYearEnding))
					{
						rdoThisRecorded->Enabled = true;
						nTemp = BEOPSGlobals::datBEOPSData->arrMonthlyInventory->Count;
					}
					else
					{
						rdoThisRecorded->Enabled = false;
						rdoThisRecorded->Checked = false;
					}
				}

			}
			BuildMORPrintString();
			//btnPrint->Enabled = ReadyToPrint();
		 }
private: bool ReadyToPrint()
		 {
			bool bReady = false;
			System::DateTime dteTemp;
			DateTime::TryParse(txtbxDate->Text, dteTemp);
			if(dteTemp != DateTime::MinValue)
			{
				if(rdoLastOther->Checked)
				{
					if(rdoThisOther->Checked)
					{
						btnPrint->Enabled = true;
					}
				}

			}
			return bReady;
		 }

private: System::Void rdoThisOther_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(((RadioButton^)sender)->Checked == false)
				 txtbxThisOther->Enabled = false;
			 else
				 txtbxThisOther->Enabled = true;
			 BuildMORPrintString();
			 //btnPrint->Enabled = ReadyToPrint();
		 }
private: System::Void rdoLastRecorded_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(((RadioButton^)sender)->Checked)
				 txtbxLastOther->Enabled = false;
			 else
				 txtbxLastOther->Enabled = true;
			 BuildMORPrintString();
		 }
private: System::Void txtbxLastOther_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			 double dblTemp = 0;
			 if(Double::TryParse(((TextBox^)sender)->Text,dblTemp))
			 {
				 ((TextBox^)sender)->Text = dblTemp.ToString("f2");
			 }
			 else
				 if(((TextBox^)sender)->Text != "")
					 e->Cancel = true;
			 BuildMORPrintString();
		 }
private: System::Void rdoThisRecorded_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(((RadioButton^)sender)->Checked)
			 {
				 ((TextBox^)txtbxThisOther)->Enabled = false;
			 }
			 BuildMORPrintString();
		 }
private: System::Void rdoThisCurrent_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(((RadioButton^)sender)->Checked)
			 {
				 ((TextBox^)txtbxThisOther)->Enabled = false;
			 }
			 BuildMORPrintString();

		 }
private: System::Void txtbxThisOther_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			 double dblTemp = 0;
			 if(Double::TryParse(((TextBox^)sender)->Text,dblTemp))
			 {
				 ((TextBox^)sender)->Text = dblTemp.ToString("f2");
			 }
			 else
				 if(((TextBox^)sender)->Text!="")
					e->Cancel = true;
			 BuildMORPrintString();

		 }
private: System::Void chkbxThisEstimate_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 BuildMORPrintString();
		 }
};
}
