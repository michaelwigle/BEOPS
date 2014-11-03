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
	/// Summary for frmMethod1Input
	/// </summary>
	public ref class frmMethod1Input : public System::Windows::Forms::Form
	{
	public:
		frmMethod1Input(void)
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
		~frmMethod1Input()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^ strPrintText;
	private: System::Windows::Forms::Label^  lblMonthYear;
	protected: 
	private: System::Windows::Forms::Label^  lblBeginningMileage;
	private: System::Windows::Forms::Label^  lblEndingMileage;
	private: System::Windows::Forms::Label^  lblBusinessMileage;
	private: System::Windows::Forms::TextBox^  txtbxMonthYear;
	private: System::Windows::Forms::TextBox^  txtbxBegMileage;
	private: System::Windows::Forms::TextBox^  txtbxEndMileage;
	private: System::Windows::Forms::TextBox^  txtbxBusinessMileage;
	private: System::Windows::Forms::Button^  btnPrint;
	private: System::Windows::Forms::Button^  btnClose;


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
			this->lblBeginningMileage = (gcnew System::Windows::Forms::Label());
			this->lblEndingMileage = (gcnew System::Windows::Forms::Label());
			this->lblBusinessMileage = (gcnew System::Windows::Forms::Label());
			this->txtbxMonthYear = (gcnew System::Windows::Forms::TextBox());
			this->txtbxBegMileage = (gcnew System::Windows::Forms::TextBox());
			this->txtbxEndMileage = (gcnew System::Windows::Forms::TextBox());
			this->txtbxBusinessMileage = (gcnew System::Windows::Forms::TextBox());
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
			// lblBeginningMileage
			// 
			this->lblBeginningMileage->AutoSize = true;
			this->lblBeginningMileage->Location = System::Drawing::Point(13, 42);
			this->lblBeginningMileage->Name = L"lblBeginningMileage";
			this->lblBeginningMileage->Size = System::Drawing::Size(94, 13);
			this->lblBeginningMileage->TabIndex = 1;
			this->lblBeginningMileage->Text = L"Beginning Mileage";
			// 
			// lblEndingMileage
			// 
			this->lblEndingMileage->AutoSize = true;
			this->lblEndingMileage->Location = System::Drawing::Point(12, 74);
			this->lblEndingMileage->Name = L"lblEndingMileage";
			this->lblEndingMileage->Size = System::Drawing::Size(80, 13);
			this->lblEndingMileage->TabIndex = 2;
			this->lblEndingMileage->Text = L"Ending Mileage";
			// 
			// lblBusinessMileage
			// 
			this->lblBusinessMileage->AutoSize = true;
			this->lblBusinessMileage->Location = System::Drawing::Point(12, 109);
			this->lblBusinessMileage->Name = L"lblBusinessMileage";
			this->lblBusinessMileage->Size = System::Drawing::Size(89, 13);
			this->lblBusinessMileage->TabIndex = 3;
			this->lblBusinessMileage->Text = L"Business Mileage";
			// 
			// txtbxMonthYear
			// 
			this->txtbxMonthYear->AccessibleDescription = L"Month and Year";
			this->txtbxMonthYear->AccessibleName = L"Month and Year";
			this->txtbxMonthYear->Location = System::Drawing::Point(149, 13);
			this->txtbxMonthYear->Name = L"txtbxMonthYear";
			this->txtbxMonthYear->Size = System::Drawing::Size(100, 20);
			this->txtbxMonthYear->TabIndex = 4;
			this->txtbxMonthYear->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmMethod1Input::txtbxMonthYear_Validating);
			// 
			// txtbxBegMileage
			// 
			this->txtbxBegMileage->AccessibleDescription = L"Beginning Mileage";
			this->txtbxBegMileage->AccessibleName = L"Beginning Mileage";
			this->txtbxBegMileage->Location = System::Drawing::Point(149, 42);
			this->txtbxBegMileage->Name = L"txtbxBegMileage";
			this->txtbxBegMileage->Size = System::Drawing::Size(100, 20);
			this->txtbxBegMileage->TabIndex = 5;
			this->txtbxBegMileage->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmMethod1Input::txtbxBegMileage_Validating);
			// 
			// txtbxEndMileage
			// 
			this->txtbxEndMileage->AccessibleDescription = L"Ending Mileage";
			this->txtbxEndMileage->AccessibleName = L"Ending Mileage";
			this->txtbxEndMileage->Location = System::Drawing::Point(149, 74);
			this->txtbxEndMileage->Name = L"txtbxEndMileage";
			this->txtbxEndMileage->Size = System::Drawing::Size(100, 20);
			this->txtbxEndMileage->TabIndex = 6;
			this->txtbxEndMileage->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmMethod1Input::txtbxEndMileage_Validating);
			// 
			// txtbxBusinessMileage
			// 
			this->txtbxBusinessMileage->AccessibleDescription = L"Business Mileage";
			this->txtbxBusinessMileage->AccessibleName = L"Business Mileage";
			this->txtbxBusinessMileage->Location = System::Drawing::Point(149, 109);
			this->txtbxBusinessMileage->Name = L"txtbxBusinessMileage";
			this->txtbxBusinessMileage->Size = System::Drawing::Size(100, 20);
			this->txtbxBusinessMileage->TabIndex = 7;
			this->txtbxBusinessMileage->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmMethod1Input::txtbxBusinessMileage_Validating);
			// 
			// btnPrint
			// 
			this->btnPrint->Location = System::Drawing::Point(98, 168);
			this->btnPrint->Name = L"btnPrint";
			this->btnPrint->Size = System::Drawing::Size(75, 23);
			this->btnPrint->TabIndex = 8;
			this->btnPrint->Text = L"&Print";
			this->btnPrint->UseVisualStyleBackColor = true;
			this->btnPrint->Click += gcnew System::EventHandler(this, &frmMethod1Input::btnPrint_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(98, 208);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 9;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmMethod1Input::btnClose_Click);
			// 
			// frmMethod1Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnPrint);
			this->Controls->Add(this->txtbxBusinessMileage);
			this->Controls->Add(this->txtbxEndMileage);
			this->Controls->Add(this->txtbxBegMileage);
			this->Controls->Add(this->txtbxMonthYear);
			this->Controls->Add(this->lblBusinessMileage);
			this->Controls->Add(this->lblEndingMileage);
			this->Controls->Add(this->lblBeginningMileage);
			this->Controls->Add(this->lblMonthYear);
			this->Name = L"frmMethod1Input";
			this->Text = L"Method 1 Input";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 //delete strPrintText;
				 this->Close();
			 }
private: System::Void btnPrint_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			int nBeginningMileage = Int32::Parse(this->txtbxBegMileage->Text);
			int nEndingMileage = Int32::Parse(this->txtbxEndMileage->Text);
			int nTotalMileage = nEndingMileage - nBeginningMileage;
			int nBusinessMileage = Int32::Parse(this->txtbxBusinessMileage->Text);
			double dBusinessPercent = (double)nBusinessMileage/(double)nTotalMileage*100;
			double dGasTotal = 0, dMaintenanceTotal = 0, dInsuranceTotal = 0, dVehiclePaymentTotal = 0, dGeneralExpenses = 0;
			double dTotalDeductibleExpense = 0, dParkingTolls = 0, dTotalReportedExpense = 0;
			System::DateTime dteDate = DateTime::Parse(this->txtbxMonthYear->Text); //Note that this is just a month and year
			DateTimeFormatInfo^ dtfMonthYear = gcnew DateTimeFormatInfo();
			dtfMonthYear->YearMonthPattern = "MMMM yyyy";
			int nDailyIndex = 0, nExpenseIndex = 0;

			//Code to collect and calculate vehicle expenses
			ArrayList^ arrDailys = BEOPSGlobals::datBEOPSData->GetMonthOfDailys(dteDate);
			Expense^ objtmpExpense;
			ArrayList^ arrGasExpenses = gcnew ArrayList();
			ArrayList^ arrMaintenanceExpenses = gcnew ArrayList();

			dGasTotal = BEOPSGlobals::datBEOPSData->GetExpenseTotals("Vehicle Gas",arrDailys);
			dMaintenanceTotal = BEOPSGlobals::datBEOPSData->GetExpenseTotals("Vehicle Maintenance",arrDailys);
			dInsuranceTotal = BEOPSGlobals::datBEOPSData->GetExpenseTotals("Vehicle Insurance",arrDailys);
			dVehiclePaymentTotal = BEOPSGlobals::datBEOPSData->GetExpenseTotals("Vehicle Payment",arrDailys);
			dParkingTolls = BEOPSGlobals::datBEOPSData->GetExpenseTotals("Vehicle Parking and Tolls",arrDailys);
			dGeneralExpenses = dGasTotal + dMaintenanceTotal + dInsuranceTotal + dVehiclePaymentTotal;
			dTotalDeductibleExpense = dGeneralExpenses * dBusinessPercent / 100;
			dTotalReportedExpense = dTotalDeductibleExpense + dParkingTolls;
			

				if (arrDailys != nullptr)
				{
					//We have dailys in that month
				

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
					L"\\qc\\lang1033\\b\\fs32 Ohio Rehabilitation Services Commission\\par Monthly Vehicle Expense Report Method 1\\par\\fs24 (Must be used and attached to MOR when using Expense Code R.)\\par\\par\\pard\\tx2160\\b BSVI Area \\b0 " + BEOPSGlobals::datBEOPSData->strBSVIArea + 
					L"\\tab\\b Operator Number \\b0 " + BEOPSGlobals::datBEOPSData->strOperatorNumber + L"\\tab\\b Facility Number \\b0 " + BEOPSGlobals::datBEOPSData->strFacilityNumber + 
					L"\\tab\\tab\\b Report Date \\b0  " + dteDate.ToString("y", dtfMonthYear) +
					L" \\par\\b Operator Name\\b0\\tab " + BEOPSGlobals::datBEOPSData->strOperatorName + L"\\tab " +
					L"\\b Address\\b0\\tab " + BEOPSGlobals::datBEOPSData->strOperatorAddress1 + L",  " + 
					BEOPSGlobals::datBEOPSData->strOperatorCity + L", " + BEOPSGlobals::datBEOPSData->strOperatorState + L" " + BEOPSGlobals::datBEOPSData->strOperatorZip + L"\\par\\par";
				String^ strFirstPage =
					L"\\tx2850\\tx5700\\tqr\\tx9975\\par\\par This Month's\\tab ending mileage:\\tab\\tab " + nEndingMileage.ToString() +
					L"\\par Minus -\\tab ending mileage:\\tab\\tab " + nBeginningMileage.ToString() + "\\par (A)\\tab Total mileage for month:\\tab\\tab " + nTotalMileage.ToString() +
					L"\\par\\tab Actual total business miles divided by total miles\\par " + nBusinessMileage.ToString() + "\\tab = % of business use\\tab\\tab " + dBusinessPercent.ToString("f2") + L"%" + 
					L"\\par\\par General Expenses:\\par Gas:\\tab $" + dGasTotal.ToString("f2") + L"\\tab (Total from back of page)" +
					L"\\par Maintenance:\\tab $" + dMaintenanceTotal.ToString("f2") + L"\\tab (Total from back of page)" + 
					L"\\par Insurance:\\tab $" + dInsuranceTotal.ToString("f2") + L"\\par Vehicle Payment:\\tab $" + dVehiclePaymentTotal.ToString("f2") +L"\\par Equals = \\par " + 
					L"General Expenses\\tab\\tab\\tab\\tab $" + dGeneralExpenses.ToString() + L"\\par    Times X   Business Use Percentage\\tab\\tab " + dBusinessPercent.ToString("f2") + L"%\\par " + 
					L"Total deductible expense\\tab\\tab\\tab $" + dTotalDeductibleExpense.ToString("f2") + L"\\par    Plus +   Parking/Tolls=\\tab\\tab\\tab $" + dParkingTolls.ToString("f2") + L"\\par " +
					L"Equals= \\par Total Vehicle Expense Reported=\\tab\\tab $" + dTotalReportedExpense.ToString("f2");
				//This starts page 2
				String^ strSecondPage =
					L"\\page\\qc\\b Vehicle Expense Report\\b0\\par\\pard GasPurchases:\\par " + 
					L"\\trowd\\trql\\ltrrow\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl0\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr0" + //This sets up padding around cell
					L"\\clbrdrt\\brdrhair\\brdrw1\\brdrcf1\\clbrdrl\\brdrhair\\brdrw1\\brdrcf1\\clbrdrb\\brdrhair\\brdrw1\\brdrcf1\\cellx1661" + //This sets up first cell
					L"\\clbrdrt\\brdrhair\\brdrw1\\brdrcf1\\clbrdrl\\brdrhair\\brdrw1\\brdrcf1\\clbrdrb\\brdrhair\\brdrw1\\brdrcf1\\cellx3323" + //This sets up second cell
					L"\\clbrdrt\\brdrhair\\brdrw1\\brdrcf1\\clbrdrl\\brdrhair\\brdrw1\\brdrcf1\\clbrdrb\\brdrhair\\brdrw1\\brdrcf1\\cellx4985" + //This sets up third cell
					L"\\clbrdrt\\brdrhair\\brdrw1\\brdrcf1\\clbrdrl\\brdrhair\\brdrw1\\brdrcf1\\clbrdrb\\brdrhair\\brdrw1\\brdrcf1\\cellx6647" + //This sets up fourth cell
					L"\\clbrdrt\\brdrhair\\brdrw1\\brdrcf1\\clbrdrl\\brdrhair\\brdrw1\\brdrcf1\\clbrdrb\\brdrhair\\brdrw1\\brdrcf1\\cellx8309" + //This sets up fifth cell
					L"\\clbrdrt\\brdrhair\\brdrw1\\brdrcf1\\clbrdrl\\brdrhair\\brdrw1\\brdrcf1\\clbrdrb\\brdrhair\\brdrw1\\brdrcf1\\clbrdrr\\brdrhair\\brdrw1\\brdrcf1\\cellx9971 " + //This sets up sixth cell
					L"\\intbl Date\\cell\\intbl Amount\\cell\\intbl Date \\cell\\intbl Amount\\cell\\intbl Date\\cell\\intbl Amount\\cell\\row "; //This is the header row
					//int nGasIndex = 0;
					int nColumnCount = 0;
					int nRowCount = 0;
					arrDailys->Sort();
					//This loop will go through each daily, grab gas expense and write the data to the table using Daily for date
					while (arrDailys->Count > nDailyIndex)
					{
						ArrayList^ arrExpenses = BEOPSGlobals::datBEOPSData->GetExpenses(((BEOPSDaily^)arrDailys[nDailyIndex])->dteDate);
						nExpenseIndex=0;
						while (arrExpenses->Count > nExpenseIndex)
						{
							objtmpExpense = ((Expense^)arrExpenses[nExpenseIndex]);
							if (objtmpExpense->strExpName == "Vehicle Gas")
							{
								//write your cell
								strSecondPage += "\\intbl " + ((BEOPSDaily^)arrDailys[nDailyIndex])->dteDate.ToShortDateString() + "\\cell\\intbl $" + objtmpExpense->dblExpAmt.ToString("f2") 
									+ L"\\cell";
								nColumnCount++;
							}
							if (nColumnCount >=3)
							{
								strSecondPage += "\\row";
								nColumnCount = 0;
							}

							nExpenseIndex++;
						}
						nDailyIndex++;
					}
					//This loop finishes off whatever column I finished in and puts in the row tag
					while (nColumnCount<3)
					{
						strSecondPage += "\\intbl\\cell\\intbl\\cell ";
						nColumnCount++;
					}
					strSecondPage += L"\\row\\intbl Total\\cell\\intbl\\cell\\intbl\\cell\\intbl\\cell\\intbl\\cell\\intbl $" + dGasTotal.ToString("f2") + L"\\cell\\row\\pard"; //This ends the table
					//This sets up the second table
					strSecondPage +=
					L"\\par\\pard Maintenance and Repair / Other:\\par " + 
					L"\\trowd\\trql\\ltrrow\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl0\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr0" + //This sets up padding around cell
					L"\\clbrdrt\\brdrhair\\brdrw1\\brdrcf1\\clbrdrl\\brdrhair\\brdrw1\\brdrcf1\\clbrdrb\\brdrhair\\brdrw1\\brdrcf1\\cellx1661" + //This sets up first cell
					L"\\clbrdrt\\brdrhair\\brdrw1\\brdrcf1\\clbrdrl\\brdrhair\\brdrw1\\brdrcf1\\clbrdrb\\brdrhair\\brdrw1\\brdrcf1\\cellx8309" + //This sets up second cell
					L"\\clbrdrt\\brdrhair\\brdrw1\\brdrcf1\\clbrdrl\\brdrhair\\brdrw1\\brdrcf1\\clbrdrb\\brdrhair\\brdrw1\\brdrcf1\\clbrdrr\\brdrhair\\brdrw1\\brdrcf1\\cellx9971 " + //This sets up third cell
					L"\\intbl Date\\cell\\intbl Description\\cell\\intbl Amount\\cell\\row "; //This is the header row

					//This loop will go through each daily, grab maintenance expense and write the data to the table using Daily for date
					nExpenseIndex = 0;
					nColumnCount = 0;
					nRowCount = 0;
					nDailyIndex = 0;
					while (arrDailys->Count > nDailyIndex)
					{
						ArrayList^ arrExpenses = BEOPSGlobals::datBEOPSData->GetExpenses(((BEOPSDaily^)arrDailys[nDailyIndex])->dteDate);
						nExpenseIndex=0;
						while (arrExpenses->Count > nExpenseIndex)
						{
							objtmpExpense = ((Expense^)arrExpenses[nExpenseIndex]);
							if (objtmpExpense->strExpName == "Vehicle Maintenance")
							{
								//write your cell
								strSecondPage += "\\intbl " + ((BEOPSDaily^)arrDailys[nDailyIndex])->dteDate.ToShortDateString() + L"\\cell\\intbl " + objtmpExpense->strMemo + L"\\cell\\intbl $"+ objtmpExpense->dblExpAmt.ToString("f2") 
									+ L"\\cell\\row ";
							}

							nExpenseIndex++;
						}
						nDailyIndex++;
					}
					//This loop finishes off whatever column I finished in and puts in the row tag
					strSecondPage += L"\\intbl Total\\cell\\intbl\\cell\\intbl $" + dMaintenanceTotal.ToString("f2") + L"\\cell\\row\\pard"; //This ends the table



				strPrintText = strDocumentBeginning + strReportHeading + strFirstPage + strSecondPage;
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
				else
				{
					MessageBox::Show("There are no vehicle expenses for that month and year","No Data", MessageBoxButtons::OK);
				}



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
private: System::Void txtbxBegMileage_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
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
private: System::Void txtbxEndMileage_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
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
};
}
