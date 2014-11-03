#pragma once
#include "BEOPSGlobals.h"
namespace BEOPS {
	using namespace System::Globalization;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmDaily
	/// </summary>
	public ref class frmDaily : public System::Windows::Forms::Form
	{
	public:

		frmDaily(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			nCurrentDaily=0;
			bAddTransaction = false;
			bDataChanged = false;
			arrNameColumnObjects = gcnew ArrayList();
			arrAmountColumnObjects = gcnew ArrayList();
			arrCommentColumnObjects = gcnew ArrayList();
			arrVehicleIDColumnObjects = gcnew ArrayList();
			arrButtonColumnObjects = gcnew ArrayList();			
			arrIncomeExpenseList = gcnew ArrayList();
			arrIncomeExpenseList->InsertRange(0,BEOPSGlobals::arrIncomeNames);
			arrIncomeExpenseList->InsertRange(arrIncomeExpenseList->Count, BEOPSGlobals::arrExpenseNames);

		}

	protected:
	private: System::Windows::Forms::Button^  btnAddTransaction1;
	private: System::Windows::Forms::Label^  lblBeginningCash;
	private: System::Windows::Forms::TextBox^  txtbxBeginningCash;
	private: System::Windows::Forms::Label^  lblClosingCash;
	private: System::Windows::Forms::TextBox^  txtbxClosingCash;
	private: System::Windows::Forms::Button^  btnSaveDaily;
	private: System::Windows::Forms::Button^  btnNew;
	private: System::Windows::Forms::Button^  btnDelete;
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Label^  lblGoToDate;
	private: System::Windows::Forms::TextBox^  txtbxGoToDate;
	private: System::Windows::Forms::Label^  lblVehicleID;
	private: System::Windows::Forms::Button^  btnAddTransaction2;
	protected: 
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmDaily()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnFirst;
	private: System::Windows::Forms::Button^  btnPrevious;
	private: System::Windows::Forms::Button^  btnNext;
	private: System::Windows::Forms::Button^  btnLast;
	private: System::Windows::Forms::Label^  lblDate;

	private: System::Windows::Forms::TextBox^  txtbxDate;

	private: System::Windows::Forms::Label^  lblAmountHeading;
	private: System::Windows::Forms::Label^  lblCommentHeading;

	protected: 
		int nCurrentDaily;
		ArrayList^ arrNameColumnObjects;
		ArrayList^ arrAmountColumnObjects;
		ArrayList^ arrCommentColumnObjects;
		ArrayList^ arrVehicleIDColumnObjects;
		ArrayList^ arrButtonColumnObjects;
		System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
		bool bDataChanged;
		bool bAddTransaction;
		int nCurrentRow; //This is the row that currently has focus in the listbox
		String^ strCurrentFieldName; //This tracks the column name of the current field
		ArrayList^ arrIncomeExpenseList;

	private: System::Windows::Forms::Label^  lblIncomeExpenseHeading;
	protected: 
		
		//TODO: Figure out how I'm going to put in vehicle data
		void RefreshData()
		{
			//First I have to remove any existing data in my grid objects including all controls.
			this->tableLayoutPanel1->Controls->Clear();
			this->tableLayoutPanel1->RowCount=0;
			this->arrNameColumnObjects->Clear();
			this->arrAmountColumnObjects->Clear();
			this->arrCommentColumnObjects->Clear();
			this->arrVehicleIDColumnObjects->Clear();
			this->arrButtonColumnObjects->Clear();
			 int nRow=0;
			 int nColumn=0;
			 int nExpenseCounter=0;
			 int nComboBoxIndex = 0;
			 //Here I sort the array just to keep everything in Date order and then grab the date from the Current Daily
			 //I need to validate that there is data in the array first in case I deleted the last Daily
			 if(BEOPSGlobals::datBEOPSData->arrDaily->Count==0)
			 {
				 BEOPSGlobals::datBEOPSData->arrDaily->Add(gcnew BEOPSDaily());
				 this->nCurrentDaily = 0;
			 }
			 BEOPSGlobals::datBEOPSData->arrDaily->Sort();
			 BEOPSDaily^ objDaily = ((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[this->nCurrentDaily]);
			 txtbxDate->Text = ((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[this->nCurrentDaily])->dteDate.ToShortDateString();
			 this->Text = txtbxDate->Text + " Daily";
			 //I'll start with the easy stuff filling in data for starting and closing balances
			 txtbxBeginningCash->Text = String::Format("{0:c2}",BEOPSGlobals::datBEOPSData->GetStartingBalance(((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[this->nCurrentDaily])->dteDate));
			 txtbxClosingCash->Text = String::Format("{0:c2}",BEOPSGlobals::datBEOPSData->GetEndingBalance(((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[this->nCurrentDaily])->dteDate));
			 //Now I load the data into the column arrays
			 //First I start with income rows
			 ArrayList^ arrIncomes = BEOPSGlobals::datBEOPSData->GetIncomes(System::Convert::ToDateTime(txtbxDate->Text));
			 while (nRow<arrIncomes->Count)
			 {
				 
				 //First create each control in a row and put the data in it from arrIncomes
				 this->arrNameColumnObjects->Add(gcnew System::Windows::Forms::ComboBox());
				 this->arrAmountColumnObjects->Add(gcnew System::Windows::Forms::TextBox());
				 this->arrCommentColumnObjects->Add(gcnew System::Windows::Forms::TextBox());
				 this->arrVehicleIDColumnObjects->Add(gcnew System::Windows::Forms::TextBox());
				 this->arrButtonColumnObjects->Add(gcnew System::Windows::Forms::Button());
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Location = System::Drawing::Point(0, nRow*25);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Name = L"cbobxName---" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->AccessibleName = L"Income/Expense";
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Size = System::Drawing::Size(150, 20);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->TabIndex = 20 + (4*nRow);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->SelectedValueChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Items->AddRange(arrIncomeExpenseList->ToArray());
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->DropDownStyle = ComboBoxStyle::DropDownList;
				 nComboBoxIndex = arrIncomeExpenseList->IndexOf(((Income^)arrIncomes[nRow])->strIncomeName);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->SelectedIndex = nComboBoxIndex;

				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Location = System::Drawing::Point(160, nRow*25);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Name = L"txtbxAmount-" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->AccessibleName = ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text + L" Amount";
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Size = System::Drawing::Size(70, 20);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->TabIndex = 21 + (4*nRow);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Text = ((Income^)arrIncomes[nRow])->dblIncomeAmt.ToString("f2");//System::Convert::ToString(((Income^)arrIncomes[nRow])->dblIncomeAmt);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->TextChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);

				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Location = System::Drawing::Point(240, nRow*25);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Name = L"txtbxComment" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->AccessibleName = ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text + L" Comment";
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Size = System::Drawing::Size(200, 20);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->TabIndex = 22 + (4*nRow);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Text = ((Income^)arrIncomes[nRow])->strMemo;
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->TextChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);

				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Location = System::Drawing::Point(440, nRow*25);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Name = L"txtbxVehicle" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->AccessibleName = ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text + L" Vehicle Name";
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Size = System::Drawing::Size(200, 20);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->TabIndex = 23 + (4*nRow);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Text = L"";
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->TextChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Enabled = false;


				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Location = System::Drawing::Point(450, nRow*25);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Name = L"btnDelete---" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->AccessibleName = L"Remove " + ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text;
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Size = System::Drawing::Size(60, 20);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->TabIndex = 24 + (4*nRow);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Text = L"&Remove";
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Click += gcnew System::EventHandler(this, &frmDaily::DeleteRow_Click);
				 
				 //Then add the each control for the row to Layout panel 
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow]),0,nRow+1);//column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow]),1,nRow+1); //column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow]),2,nRow+1); //column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow]),3,nRow+1); //column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow]),4,nRow+1); //column,row
				 nRow++;
			 }
			 //TODO: I need to write the code that will check for a Vehicle ID and create a fifth column for it as necessary.
			 //Next I work with expense rows
			 ArrayList^ arrExpenses = BEOPSGlobals::datBEOPSData->GetExpenses(System::Convert::ToDateTime(txtbxDate->Text));
			 while(nExpenseCounter<arrExpenses->Count)
			 {
				 this->arrNameColumnObjects->Add(gcnew System::Windows::Forms::ComboBox());
				 this->arrAmountColumnObjects->Add(gcnew System::Windows::Forms::TextBox());
				 this->arrCommentColumnObjects->Add(gcnew System::Windows::Forms::TextBox());
				 this->arrVehicleIDColumnObjects->Add(gcnew System::Windows::Forms::TextBox());
				 this->arrButtonColumnObjects->Add(gcnew System::Windows::Forms::Button());
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Location = System::Drawing::Point(0, nRow*25);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Name = L"cbobxName---" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->AccessibleName = L"Income/Expense";
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Size = System::Drawing::Size(150, 20);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->TabIndex = 20 + (4*nRow);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Items->AddRange(arrIncomeExpenseList->ToArray());
				 nComboBoxIndex = arrIncomeExpenseList->IndexOf(((Expense^)arrExpenses[nExpenseCounter])->strExpName);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->SelectedIndex = nComboBoxIndex;
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->SelectedValueChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->DropDownStyle = ComboBoxStyle::DropDownList;

				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Location = System::Drawing::Point(160, nRow*25);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Name = L"txtbxAmount-" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->AccessibleName = ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text + L" Amount";
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Size = System::Drawing::Size(70, 20);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->TabIndex = 21 + (4*nRow);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Text = ((Expense^)arrExpenses[nExpenseCounter])->dblExpAmt.ToString("f2"); //System::Convert::ToString(((Expense^)arrExpenses[nExpenseCounter])->dblExpAmt);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->TextChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);

				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Location = System::Drawing::Point(230, nRow*25);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Name = L"txtbxComment" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->AccessibleName = ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text + L" Comment";
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Size = System::Drawing::Size(200, 20);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->TabIndex = 22 + (4*nRow);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Text = ((Expense^)arrExpenses[nExpenseCounter])->strMemo;
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->TextChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);

				 //This is where I will add the Vehicle ID Column and create altered button locations
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Location = System::Drawing::Point(440, nRow*25);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Name = L"txtbxVehicle" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->AccessibleName = ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text + L" Vehicle Name";
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Size = System::Drawing::Size(200, 20);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->TabIndex = 23 + (4*nRow);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Text = ((Expense^)arrExpenses[nExpenseCounter])->strVehicleID;
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->TextChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);
				 if(!((Expense^)arrExpenses[nExpenseCounter])->IsVehicleExpense())
					 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Enabled=false;

				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Location = System::Drawing::Point(650, nRow*25);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Name = L"btnDelete---" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->AccessibleName = L"Remove " + ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text;
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Size = System::Drawing::Size(60, 20);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->TabIndex = 24 + (4*nRow);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Text = L"&Remove";
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Click += gcnew System::EventHandler(this, &frmDaily::DeleteRow_Click);

				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow]),0,nRow+1);//column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow]),1,nRow+1); //column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow]),2,nRow+1); //column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow]),3,nRow+1); //column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow]),4,nRow+1); //column,row

				 nRow++;
				 nExpenseCounter++;
			 }

			 //Here I add a new blank row if necessary
			 if (bAddTransaction)
			 {
				 this->arrNameColumnObjects->Add(gcnew System::Windows::Forms::ComboBox());
				 this->arrAmountColumnObjects->Add(gcnew System::Windows::Forms::TextBox());
				 this->arrCommentColumnObjects->Add(gcnew System::Windows::Forms::TextBox());
				 this->arrVehicleIDColumnObjects->Add(gcnew System::Windows::Forms::TextBox());
				 this->arrButtonColumnObjects->Add(gcnew System::Windows::Forms::Button());
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Location = System::Drawing::Point(0, nRow*25);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Name = L"cbobxName---" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->AccessibleName = L"Income/Expense";
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Size = System::Drawing::Size(150, 20);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->TabIndex = 20 + (4*nRow);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text = L"";
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->SelectedValueChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Items->AddRange(arrIncomeExpenseList->ToArray());
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->SelectedIndex = 0;
				 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->DropDownStyle = ComboBoxStyle::DropDownList;

				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Location = System::Drawing::Point(160, nRow*25);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Name = L"txtbxAmount-" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->AccessibleName = ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text + L" Amount";
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Size = System::Drawing::Size(70, 20);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->TabIndex = 21 + (4*nRow);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->Text = L"";
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->TextChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);

				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Location = System::Drawing::Point(230, nRow*25);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Name = L"txtbxComment" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->AccessibleName = ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text + L" Comment";
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Size = System::Drawing::Size(200, 20);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->TabIndex = 22 + (4*nRow);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->Text = L"";
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->TextChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);

				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Location = System::Drawing::Point(440, nRow*25);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Name = L"txtbxVehicle" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->AccessibleName = ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text + L" Vehicle Name";
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Size = System::Drawing::Size(200, 20);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->TabIndex = 23 + (4*nRow);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->Text = L"";
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->TextChanged += gcnew System::EventHandler(this, &frmDaily::ListData_Changed);
				 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow])->LostFocus += gcnew System::EventHandler(this, &frmDaily::ListData_LostFocus);
				 

				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Location = System::Drawing::Point(650, nRow*25);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Name = L"btnSaveTrans" + System::Convert::ToString(nRow);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->AccessibleName = L"Save " + ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow])->Text;
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Size = System::Drawing::Size(50, 20);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->TabIndex = 24 + (4*nRow);
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Text = L"Save";
				 ((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow])->Click += gcnew System::EventHandler(this, &frmDaily::btnSaveTrans_Click);

				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nRow]),0,nRow+1);//column,row
				 ((Control^)this->tableLayoutPanel1->Controls[this->tableLayoutPanel1->Controls->Count-1])->Focus();
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nRow]),1,nRow+1); //column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nRow]),2,nRow+1); //column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nRow]),3,nRow+1); //column,row
				 this->tableLayoutPanel1->Controls->Add(((System::Windows::Forms::Button^)this->arrButtonColumnObjects[nRow]),4,nRow+1); //column,row

				 //Set focus to name of new control

				 nRow++;

			 }
				 //Here I redraw the panel
			this->tableLayoutPanel1->AutoScroll = true;
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 71);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";

			 this->tableLayoutPanel1->RowCount = nRow;
			 this->tableLayoutPanel1->Size = System::Drawing::Size(800, 200);
			 this->tableLayoutPanel1->ResumeLayout(false);
			 this->tableLayoutPanel1->PerformLayout();
			 this->tableLayoutPanel1->TabIndex = 3;

			 this->bDataChanged=false;
			 this->bAddTransaction=false;
		}

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
			this->btnFirst = (gcnew System::Windows::Forms::Button());
			this->btnPrevious = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnLast = (gcnew System::Windows::Forms::Button());
			this->lblDate = (gcnew System::Windows::Forms::Label());
			this->txtbxDate = (gcnew System::Windows::Forms::TextBox());
			this->lblAmountHeading = (gcnew System::Windows::Forms::Label());
			this->lblCommentHeading = (gcnew System::Windows::Forms::Label());
			this->lblIncomeExpenseHeading = (gcnew System::Windows::Forms::Label());
			this->btnAddTransaction1 = (gcnew System::Windows::Forms::Button());
			this->btnAddTransaction2 = (gcnew System::Windows::Forms::Button());
			this->lblBeginningCash = (gcnew System::Windows::Forms::Label());
			this->txtbxBeginningCash = (gcnew System::Windows::Forms::TextBox());
			this->lblClosingCash = (gcnew System::Windows::Forms::Label());
			this->txtbxClosingCash = (gcnew System::Windows::Forms::TextBox());
			this->btnSaveDaily = (gcnew System::Windows::Forms::Button());
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->lblGoToDate = (gcnew System::Windows::Forms::Label());
			this->txtbxGoToDate = (gcnew System::Windows::Forms::TextBox());
			this->lblVehicleID = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnFirst
			// 
			this->btnFirst->Location = System::Drawing::Point(117, 305);
			this->btnFirst->Name = L"btnFirst";
			this->btnFirst->Size = System::Drawing::Size(75, 23);
			this->btnFirst->TabIndex = 6;
			this->btnFirst->Text = L"&First";
			this->btnFirst->UseVisualStyleBackColor = true;
			this->btnFirst->Click += gcnew System::EventHandler(this, &frmDaily::btnFirst_Click);
			// 
			// btnPrevious
			// 
			this->btnPrevious->Location = System::Drawing::Point(199, 305);
			this->btnPrevious->Name = L"btnPrevious";
			this->btnPrevious->Size = System::Drawing::Size(75, 23);
			this->btnPrevious->TabIndex = 7;
			this->btnPrevious->Text = L"&Previous";
			this->btnPrevious->UseVisualStyleBackColor = true;
			this->btnPrevious->Click += gcnew System::EventHandler(this, &frmDaily::btnPrevious_Click);
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(444, 305);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(75, 23);
			this->btnNext->TabIndex = 9;
			this->btnNext->Text = L"N&ext";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &frmDaily::btnNext_Click);
			// 
			// btnLast
			// 
			this->btnLast->Location = System::Drawing::Point(526, 305);
			this->btnLast->Name = L"btnLast";
			this->btnLast->Size = System::Drawing::Size(75, 23);
			this->btnLast->TabIndex = 10;
			this->btnLast->Text = L"&Last";
			this->btnLast->UseVisualStyleBackColor = true;
			this->btnLast->Click += gcnew System::EventHandler(this, &frmDaily::btnLast_Click);
			// 
			// lblDate
			// 
			this->lblDate->AutoSize = true;
			this->lblDate->Location = System::Drawing::Point(21, 9);
			this->lblDate->Name = L"lblDate";
			this->lblDate->Size = System::Drawing::Size(30, 13);
			this->lblDate->TabIndex = 4;
			this->lblDate->Text = L"Date";
			// 
			// txtbxDate
			// 
			this->txtbxDate->AccessibleName = L"Date";
			this->txtbxDate->Location = System::Drawing::Point(58, 9);
			this->txtbxDate->Name = L"txtbxDate";
			this->txtbxDate->Size = System::Drawing::Size(100, 20);
			this->txtbxDate->TabIndex = 0;
			this->txtbxDate->Leave += gcnew System::EventHandler(this, &frmDaily::txtbxDate_Leave);
			// 
			// lblAmountHeading
			// 
			this->lblAmountHeading->AutoSize = true;
			this->lblAmountHeading->Location = System::Drawing::Point(190, 55);
			this->lblAmountHeading->Name = L"lblAmountHeading";
			this->lblAmountHeading->Size = System::Drawing::Size(43, 13);
			this->lblAmountHeading->TabIndex = 2;
			this->lblAmountHeading->Text = L"Amount";
			// 
			// lblCommentHeading
			// 
			this->lblCommentHeading->AutoSize = true;
			this->lblCommentHeading->Location = System::Drawing::Point(305, 55);
			this->lblCommentHeading->Name = L"lblCommentHeading";
			this->lblCommentHeading->Size = System::Drawing::Size(51, 13);
			this->lblCommentHeading->TabIndex = 3;
			this->lblCommentHeading->Text = L"Comment";
			// 
			// lblIncomeExpenseHeading
			// 
			this->lblIncomeExpenseHeading->AutoSize = true;
			this->lblIncomeExpenseHeading->Location = System::Drawing::Point(38, 55);
			this->lblIncomeExpenseHeading->Name = L"lblIncomeExpenseHeading";
			this->lblIncomeExpenseHeading->Size = System::Drawing::Size(88, 13);
			this->lblIncomeExpenseHeading->TabIndex = 7;
			this->lblIncomeExpenseHeading->Text = L"Income/Expense";
			this->lblIncomeExpenseHeading->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnAddTransaction1
			// 
			this->btnAddTransaction1->Location = System::Drawing::Point(368, 7);
			this->btnAddTransaction1->Name = L"btnAddTransaction1";
			this->btnAddTransaction1->Size = System::Drawing::Size(97, 23);
			this->btnAddTransaction1->TabIndex = 2;
			this->btnAddTransaction1->Text = L"&Add Transaction";
			this->btnAddTransaction1->UseVisualStyleBackColor = true;
			this->btnAddTransaction1->Click += gcnew System::EventHandler(this, &frmDaily::btnAddTransaction_Click);
			// 
			// btnAddTransaction2
			// 
			this->btnAddTransaction2->Location = System::Drawing::Point(422, 271);
			this->btnAddTransaction2->Name = L"btnAddTransaction2";
			this->btnAddTransaction2->Size = System::Drawing::Size(97, 23);
			this->btnAddTransaction2->TabIndex = 5;
			this->btnAddTransaction2->Text = L"&Add Transaction";
			this->btnAddTransaction2->UseVisualStyleBackColor = true;
			this->btnAddTransaction2->Click += gcnew System::EventHandler(this, &frmDaily::btnAddTransaction_Click);
			// 
			// lblBeginningCash
			// 
			this->lblBeginningCash->AutoSize = true;
			this->lblBeginningCash->Location = System::Drawing::Point(165, 9);
			this->lblBeginningCash->Name = L"lblBeginningCash";
			this->lblBeginningCash->Size = System::Drawing::Size(81, 13);
			this->lblBeginningCash->TabIndex = 8;
			this->lblBeginningCash->Text = L"Beginning Cash";
			// 
			// txtbxBeginningCash
			// 
			this->txtbxBeginningCash->AccessibleName = L"Beginning Cash";
			this->txtbxBeginningCash->Location = System::Drawing::Point(253, 9);
			this->txtbxBeginningCash->Name = L"txtbxBeginningCash";
			this->txtbxBeginningCash->ReadOnly = true;
			this->txtbxBeginningCash->Size = System::Drawing::Size(100, 20);
			this->txtbxBeginningCash->TabIndex = 1;
			// 
			// lblClosingCash
			// 
			this->lblClosingCash->AutoSize = true;
			this->lblClosingCash->Location = System::Drawing::Point(222, 274);
			this->lblClosingCash->Name = L"lblClosingCash";
			this->lblClosingCash->Size = System::Drawing::Size(68, 13);
			this->lblClosingCash->TabIndex = 10;
			this->lblClosingCash->Text = L"Closing Cash";
			// 
			// txtbxClosingCash
			// 
			this->txtbxClosingCash->AccessibleName = L"Closing Cash";
			this->txtbxClosingCash->Location = System::Drawing::Point(307, 274);
			this->txtbxClosingCash->Name = L"txtbxClosingCash";
			this->txtbxClosingCash->ReadOnly = true;
			this->txtbxClosingCash->Size = System::Drawing::Size(100, 20);
			this->txtbxClosingCash->TabIndex = 4;
			// 
			// btnSaveDaily
			// 
			this->btnSaveDaily->Enabled = false;
			this->btnSaveDaily->Location = System::Drawing::Point(199, 336);
			this->btnSaveDaily->Name = L"btnSaveDaily";
			this->btnSaveDaily->Size = System::Drawing::Size(75, 23);
			this->btnSaveDaily->TabIndex = 12;
			this->btnSaveDaily->Text = L"&Save";
			this->btnSaveDaily->UseVisualStyleBackColor = true;
			this->btnSaveDaily->Click += gcnew System::EventHandler(this, &frmDaily::btnSaveDaily_Click);
			// 
			// btnNew
			// 
			this->btnNew->Location = System::Drawing::Point(280, 335);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(75, 23);
			this->btnNew->TabIndex = 13;
			this->btnNew->Text = L"&New";
			this->btnNew->UseVisualStyleBackColor = true;
			this->btnNew->Click += gcnew System::EventHandler(this, &frmDaily::btnNew_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(362, 336);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 14;
			this->btnDelete->Text = L"&Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmDaily::btnDelete_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(444, 336);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 15;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmDaily::btnClose_Click);
			// 
			// lblGoToDate
			// 
			this->lblGoToDate->AutoSize = true;
			this->lblGoToDate->Location = System::Drawing::Point(280, 310);
			this->lblGoToDate->Name = L"lblGoToDate";
			this->lblGoToDate->Size = System::Drawing::Size(33, 13);
			this->lblGoToDate->TabIndex = 16;
			this->lblGoToDate->Text = L"&Go to";
			// 
			// txtbxGoToDate
			// 
			this->txtbxGoToDate->AccessibleName = L"Go To";
			this->txtbxGoToDate->Location = System::Drawing::Point(320, 305);
			this->txtbxGoToDate->Name = L"txtbxGoToDate";
			this->txtbxGoToDate->Size = System::Drawing::Size(100, 20);
			this->txtbxGoToDate->TabIndex = 8;
			this->txtbxGoToDate->Leave += gcnew System::EventHandler(this, &frmDaily::txtbxGoToDate_Leave);
			// 
			// lblVehicleID
			// 
			this->lblVehicleID->AutoSize = true;
			this->lblVehicleID->Location = System::Drawing::Point(511, 55);
			this->lblVehicleID->Name = L"lblVehicleID";
			this->lblVehicleID->Size = System::Drawing::Size(73, 13);
			this->lblVehicleID->TabIndex = 17;
			this->lblVehicleID->Text = L"Vehicle Name";
			// 
			// frmDaily
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(808, 369);
			this->Controls->Add(this->lblVehicleID);
			this->Controls->Add(this->txtbxGoToDate);
			this->Controls->Add(this->lblGoToDate);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnNew);
			this->Controls->Add(this->btnSaveDaily);
			this->Controls->Add(this->txtbxClosingCash);
			this->Controls->Add(this->lblClosingCash);
			this->Controls->Add(this->txtbxBeginningCash);
			this->Controls->Add(this->lblBeginningCash);
			this->Controls->Add(this->btnAddTransaction2);
			this->Controls->Add(this->btnAddTransaction1);
			this->Controls->Add(this->lblCommentHeading);
			this->Controls->Add(this->lblAmountHeading);
			this->Controls->Add(this->lblIncomeExpenseHeading);
			this->Controls->Add(this->txtbxDate);
			this->Controls->Add(this->lblDate);
			this->Controls->Add(this->btnLast);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnPrevious);
			this->Controls->Add(this->btnFirst);
			this->Name = L"frmDaily";
			this->Text = L"frmDaily";
			this->Load += gcnew System::EventHandler(this, &frmDaily::frmDaily_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmDaily_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->Controls->Add(this->tableLayoutPanel1);
				 nCurrentDaily=0;
				 //If there aren't any Dailies yet then I create a new one.
				 if(BEOPSGlobals::datBEOPSData->arrDaily->Count==0)
					 BEOPSGlobals::datBEOPSData->arrDaily->Add(gcnew BEOPSDaily());
				 RefreshData();
				 bDataChanged = false;
			 }
private: System::Void btnFirst_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 nCurrentDaily = 0;
			 RefreshData();
			 this->bDataChanged=false;
		 }
private: System::Void btnPrevious_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (nCurrentDaily>0) nCurrentDaily--;
			 RefreshData();
			 this->bDataChanged=false;
		 }
private: System::Void btnNext_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (nCurrentDaily<BEOPSGlobals::datBEOPSData->arrDaily->Count-1) nCurrentDaily++;
			 {
				 RefreshData();
				 this->bDataChanged=false;
			 }
		 }
private: System::Void btnLast_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 nCurrentDaily = BEOPSGlobals::datBEOPSData->arrDaily->Count-1;
			 RefreshData();
			 this->bDataChanged=false;
		 }
private: System::Void txtbxDate_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //Veryify the new value is a valid date
			 DateTime dteDateField, dtePreviousDate;
			 BEOPSDaily^ objDaily;
			 int nTemp;
			 //Get the current Daily in an object before making changes or testing to be able to reset values if needed.
			 objDaily = (BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[nCurrentDaily];
			 if (DateTime::TryParse(this->txtbxDate->Text, dteDateField))
			 {
				 //Get the date of the current Daily from BEOPSData				 
				 //Compare it against the new date in the field
				 if(objDaily->dteDate != dteDateField)
				 {
					//If the date has changed then search for an existing Daily with that date
					nTemp = BEOPSGlobals::datBEOPSData->GetDailyIndex(dteDateField);
					if(nTemp== -1)
					//If the daily doesn't already exist then update the current Daily with the new date
					{
						objDaily->dteDate = dteDateField;
					}
					else
					{
						MessageBox::Show("That date already exists. Please delete the other daily first or choose a different date.","Update failed");
						this->txtbxDate->Text = objDaily->dteDate.ToShortDateString();
						this->txtbxDate->Focus();
					}
				 }
			 }
			 else
			 {
				 MessageBox::Show("Not a valid date.","Invalid date");
				 this->txtbxDate->Text = objDaily->dteDate.ToShortDateString();
				 this->txtbxDate->Focus();
			 }

		 }
private: System::Void frmDaily::ListData_Changed(System::Object^  sender, System::EventArgs^  e)
		 {
			 bDataChanged = true;
			 //Here I can use sender->Text vs sender->CurrentText to determine if the combo box was changed between income/expense
			 //If it was, I can send the new value to the Lost Focus function so it can select the correct value after the delete and create
		 }

		 //TODO: This code works but it would be nicer if when you change the combobox value it remembers the values and puts them in
		 //as defaults in the new entry.
private: System::Void frmDaily::ListData_LostFocus(System::Object^  sender, System::EventArgs^  e)
		 {
			 //Only update data to data object if not adding new row
			 if(!bAddTransaction)
			 {
				 //This is where I update the data to the BEOPSData object			 
				 BEOPSDaily^ objDaily = ((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[this->nCurrentDaily]);
 				 if(bDataChanged)
				 {
					 nCurrentRow = System::Convert::ToInt32(((System::Windows::Forms::Control^)sender)->Name->Substring(12));
					 UpdateAccessibleNamesForRow(nCurrentRow);

					 //At this point I need to be able to figure out if the combobox changed between income and expense. If so, I need to delete
					 //one and create the other. Or, I could test and warn that it's not permitted. That would make the rest of this code work.
					 //Or I could simply have it delete the row and then add a new transaction.
					 if(sender->GetType() == ComboBox::typeid)
					 {
						 //TODO: I have a problem here. I need to confirm a change between Income and Expense before running this code
						 //This is the delete_row_click code slightly altered because calling that code directly causes the 
						 //Lost Focus event to happen part-way through
						 if(nCurrentRow < objDaily->arrIncome->Count)
						 {
							 //It's an Income transaction and we will delete the memory for the object and then item from the array
							 delete objDaily->arrIncome[nCurrentRow];
							 objDaily->arrIncome->RemoveAt(nCurrentRow);
						 }
						 else
						 {
							 //It's an Expense and we will delete the memory for the object and then the item from the array
							 delete objDaily->arrExpenses[nCurrentRow-objDaily->arrIncome->Count];
							 objDaily->arrExpenses->RemoveAt(nCurrentRow-objDaily->arrIncome->Count);
						 }

						 this->btnAddTransaction_Click(sender,e);
					 }

					 else
					 {
						 //We're not changing the combobox and editing can happen normally.
						if(nCurrentRow < objDaily->arrIncome->Count)
						{
							//It's from the Income array
							strCurrentFieldName = ((System::Windows::Forms::Control^)sender)->Name->Substring(0,12);
							if(strCurrentFieldName == L"cbobxName---")
							{
								((Income^)objDaily->arrIncome[nCurrentRow])->strIncomeName = ((System::Windows::Forms::ComboBox^)sender)->SelectedItem->ToString();
							}
							else
								if(strCurrentFieldName == L"txtbxAmount-")
									((Income^)objDaily->arrIncome[nCurrentRow])->dblIncomeAmt = System::Convert::ToDouble(((System::Windows::Forms::TextBox^)sender)->Text);
								else
									((Income^)objDaily->arrIncome[nCurrentRow])->strMemo = ((System::Windows::Forms::TextBox^)sender)->Text;
						}
						else
						{
							//It's from the Expense array
							strCurrentFieldName = ((System::Windows::Forms::Control^)sender)->Name->Substring(0,12);
							nCurrentRow = nCurrentRow - objDaily->arrIncome->Count;
							if(strCurrentFieldName == L"cbobxName---")
							{
								((Expense^)objDaily->arrExpenses[nCurrentRow])->strExpName = ((System::Windows::Forms::ComboBox^)sender)->SelectedItem->ToString();
							}
							else
								if(strCurrentFieldName == L"txtbxAmount-")
									((Expense^)objDaily->arrExpenses[nCurrentRow])->dblExpAmt = System::Convert::ToDouble(((System::Windows::Forms::Control^)sender)->Text);
								else
									if(strCurrentFieldName == L"txtbxComment")
										((Expense^)objDaily->arrExpenses[nCurrentRow])->strMemo = ((System::Windows::Forms::Control^)sender)->Text;
									else
										((Expense^)objDaily->arrExpenses[nCurrentRow])->strVehicleID = ((System::Windows::Forms::Control^)sender)->Text;
						}

					 }
				 }
			 }
			 else
			 {
				 //It's a new row but I need to update the accessible names anyway.
				 if(bDataChanged)
				 {
					 nCurrentRow = System::Convert::ToInt32(((System::Windows::Forms::Control^)sender)->Name->Substring(12));
					 UpdateAccessibleNamesForRow(nCurrentRow);
				 }
			 }
			 bDataChanged = false;
		 }
private: System::Void frmDaily::DeleteRow_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //Find the transaction to delete
			 BEOPSDaily^ objDaily = ((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[this->nCurrentDaily]);
			 nCurrentRow = System::Convert::ToInt32(((System::Windows::Forms::Button^)sender)->Name->Substring(12));
			 if(nCurrentRow < objDaily->arrIncome->Count)
			 {
				 //It's an Income transaction and we will delete the memory for the object and then item from the array
				 delete objDaily->arrIncome[nCurrentRow];
				 objDaily->arrIncome->RemoveAt(nCurrentRow);
			 }
			 else
			 {
				 //It's an Expense and we will delete the memory for the object and then the item from the array
				 delete objDaily->arrExpenses[nCurrentRow-objDaily->arrIncome->Count];
				 objDaily->arrExpenses->RemoveAt(nCurrentRow-objDaily->arrIncome->Count);
			 }
			 RefreshData();
			 
		 }
		 //Next step. Create a button for adding new transactions to a daily.
private: System::Void btnAddTransaction_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //I have to mark bAddTransaction to True the first time for the RefreshData to work properly
			 bAddTransaction = true;
			 RefreshData();
			 //I have to mark bAddTransaction to True again for the combo box editing code to function correctly because
			 //RefreshData marks the value as false
			 bAddTransaction = true;

		 }

private: System::Void btnSaveTrans_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int nIndex;
			 double dTemp;
			 //I need to be able to determine if the transaction is Income or Expense before saving it.
			 nCurrentRow = System::Convert::ToInt32(((System::Windows::Forms::Button^)sender)->Name->Substring(12));
			 if(Double::TryParse(((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nCurrentRow])->Text,dTemp))
			 {
			 if(BEOPSGlobals::arrIncomeNames->Contains(((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nCurrentRow])->Text))
			 {
				 //Then it is an Income
				 BEOPSDaily^ objDaily = ((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[this->nCurrentDaily]);
				 objDaily->arrIncome->Add(gcnew Income(
					 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nCurrentRow])->Text,
					 System::Convert::ToDouble(((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nCurrentRow])->Text),
					 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nCurrentRow])->Text));
			 }
			 else
			 {
				 //It is an expense
				 BEOPSDaily^ objDaily = ((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[this->nCurrentDaily]);
				 nIndex = BEOPSGlobals::arrExpenseNames->IndexOf(((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nCurrentRow])->Text);
				 objDaily->arrExpenses->Add(gcnew Expense(
					 ((System::Windows::Forms::ComboBox^)this->arrNameColumnObjects[nCurrentRow])->Text,
					 (String^)BEOPSGlobals::arrExpenseCodes[nIndex],
					 System::Convert::ToDouble(((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nCurrentRow])->Text),
					 ((System::Windows::Forms::TextBox^)this->arrCommentColumnObjects[nCurrentRow])->Text,
					 ((System::Windows::Forms::TextBox^)this->arrVehicleIDColumnObjects[nCurrentRow])->Text));
			 }
			 bAddTransaction = false;
			 RefreshData();
			 }
			 else
			 {
				 ((System::Windows::Forms::TextBox^)this->arrAmountColumnObjects[nCurrentRow])->Focus();
			 }
			 
		 }

private: System::Void btnSaveDaily_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //I need to figure a way to have it check to see that the new date isn't already there
			 //That may have to happen in cell validation.
			 //((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[nCurrentDaily])->dteDate = System::Convert::ToDateTime(txtbxDate->Text);
		 }
private: System::Void btnNew_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 BEOPSGlobals::datBEOPSData->arrDaily->Sort();
			 System::TimeSpan tSpan(1,0,0,0); //Equals 1 day
			 System::DateTime dteTemp = ((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[BEOPSGlobals::datBEOPSData->arrDaily->Count-1])->dteDate;
			 dteTemp = dteTemp + tSpan;
			 BEOPSGlobals::datBEOPSData->arrDaily->Add(gcnew BEOPSDaily(dteTemp));
			 nCurrentDaily = BEOPSGlobals::datBEOPSData->arrDaily->Count-1;
			 RefreshData();

		 }
private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MessageBox::Show("The Daily for " + this->txtbxDate->Text + " has been deleted.","Deleted" );
			 delete ((BEOPSDaily^)BEOPSGlobals::datBEOPSData->arrDaily[nCurrentDaily]);
			 BEOPSGlobals::datBEOPSData->arrDaily->RemoveAt(nCurrentDaily);
			 if(nCurrentDaily==BEOPSGlobals::datBEOPSData->arrDaily->Count)
				 nCurrentDaily--;
			 RefreshData();
			 
			 
		 }
private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->Close();
		 }
private: System::Void txtbxGoToDate_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //First, try to parse the data to a date.
			 DateTime dteTemp;
			 int nTemp;
			 if (DateTime::TryParse(txtbxGoToDate->Text, dteTemp))
			 {
					//It's a date, check to see if there is a daily for that date
					txtbxGoToDate->Text = "";
					nTemp = BEOPSGlobals::datBEOPSData->GetDailyIndex(dteTemp);
					if(nTemp!= -1)
					{
						//There is, go there and move focus to date field for confirmation
						nCurrentDaily = nTemp;
						RefreshData();
						txtbxDate->Focus();
					}
					else
					{
						//There isn't, return them to the GoToDate field to try again
						RefreshData();
						txtbxGoToDate->Focus();
					}
			 }
			 else
				 //It's not a date, blank the field and let the user go where they want
				 txtbxGoToDate->Text = "";
		 }

private: System::Void UpdateAccessibleNamesForRow(int nRow)
		 {
			 int nIndex=0;
			 String^ strNewName = "";
			 for(nIndex = 0; nIndex<this->tableLayoutPanel1->Controls->Count; nIndex++)
			 {
				 if(((Control^)this->tableLayoutPanel1->Controls[nIndex])->Name == (L"cbobxName---" + nRow.ToString()))
				 {
					 strNewName = ((Control^)this->tableLayoutPanel1->Controls[nIndex])->Text;
					 nIndex = this->tableLayoutPanel1->Controls->Count;
				 }
			 }
			 if(strNewName!="")
			 {
				 for(nIndex = 0; nIndex<this->tableLayoutPanel1->Controls->Count; nIndex++)
				 {
					 if(((Control^)this->tableLayoutPanel1->Controls[nIndex])->Name == (L"txtbxAmount-" + nRow.ToString()))
						 ((Control^)this->tableLayoutPanel1->Controls[nIndex])->AccessibleName = strNewName + L" Amount";
					 if(((Control^)this->tableLayoutPanel1->Controls[nIndex])->Name == (L"txtbxComment" + nRow.ToString()))
						 ((Control^)this->tableLayoutPanel1->Controls[nIndex])->AccessibleName = strNewName + L" Comment";
					 if(((Control^)this->tableLayoutPanel1->Controls[nIndex])->Name == (L"txtbxVehicle" + nRow.ToString()))
						 ((Control^)this->tableLayoutPanel1->Controls[nIndex])->AccessibleName = strNewName + L" Vehicle";
					 if(((Control^)this->tableLayoutPanel1->Controls[nIndex])->Name == (L"btnDelete---" + nRow.ToString()))
						 ((Control^)this->tableLayoutPanel1->Controls[nIndex])->AccessibleName = L"Delete " + strNewName;
					 if(((Control^)this->tableLayoutPanel1->Controls[nIndex])->Name == (L"btnSaveTrans" + nRow.ToString()))
						 ((Control^)this->tableLayoutPanel1->Controls[nIndex])->AccessibleName = L"Save " + strNewName;
				 }

			 }
		 }
};
}
