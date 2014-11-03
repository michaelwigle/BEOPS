#pragma once
#include "BEOPSGlobals.h"

namespace BEOPS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmInventory
	/// </summary>
	public ref class frmInventory : public System::Windows::Forms::Form
	{
	public:
		frmInventory(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Button^  btnNew;
	private: System::Windows::Forms::Button^  btnDelete;
	public: 

	public: 

	protected:
		bool bDataChanged;
		//bool bRecalculate; //false by default. This field is made true if you edit a field that should recalculate unit costs.
		//bool bRecalculating; //False by default. Turned true during recalculation so fields changed by recalculation don't then cause themselves to be recalculated.
		bool bJustCalculated;
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmInventory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: void ClearAndLock() //This clears the screen and disables input until new record made
			 {
				 txtbxName->Text="";
				 txtbxName->Enabled=false;
				 txtbxCategory->Text="";
				 txtbxCategory->Enabled=false;
				 txtbxVendor->Text="";
				 txtbxVendor->Enabled=false;
				 txtbxUnitsInACase->Text="";
				 txtbxUnitsInACase->Enabled=false;
				 txtbxWholesaleCostOfACase->Text="";
				 txtbxWholesaleCostOfACase->Enabled=false;
				 txtbxNumberOfCases->Text="";
				 txtbxNumberOfCases->Enabled=false;
				 txtbxNumberOfItems->Text="";
				 txtbxNumberOfItems->Enabled=false;
				 txtbxWholesaleCostOfItem->Text="";
				 txtbxWholesaleCostOfItem->Enabled=false;
				 txtbxRetailValueOfCase->Text="";
				 txtbxRetailValueOfCase->Enabled=false;
				 txtbxDateUpdated->Text="";
				 txtbxDateUpdated->Enabled=false;
				 lbInventory->Text="";
				 lbInventory->Enabled=false;
				 txtbxRetailValueOfItem->Text="";
				 txtbxRetailValueOfItem->Enabled=false;
				 txtbxTotalWholesaleCost->Text="";
				 txtbxTotalWholesaleCost->Enabled=false;
				 txtbxTotalRetailValue->Text="";
				 txtbxTotalRetailValue->Enabled=false;
				 bDataChanged=false;
//				 bRecalculate=false;
//				 bRecalculating=false;
				 bJustCalculated=false;
			 }
	private: void Unlock() //This unlocks the screen to add the first item
			 {
				 txtbxName->Enabled=true;
				 txtbxCategory->Enabled=true;
				 txtbxVendor->Enabled=true;
				 txtbxUnitsInACase->Enabled=true;
				 txtbxWholesaleCostOfACase->Enabled=true;
				 txtbxNumberOfCases->Enabled=true;
				 txtbxNumberOfItems->Enabled=true;
				 txtbxWholesaleCostOfItem->Enabled=true;
				 txtbxRetailValueOfCase->Enabled=true;
				 txtbxDateUpdated->Enabled=true;
				 lbInventory->Enabled=true;
				 txtbxRetailValueOfItem->Enabled=true;
				 txtbxTotalWholesaleCost->Enabled=true;
				 txtbxTotalRetailValue->Enabled=true;

			 }


	private: System::Windows::Forms::ListBox^  lbInventory;
	private: System::Windows::Forms::Label^  lblName;
	private: System::Windows::Forms::TextBox^  txtbxName;
	private: System::Windows::Forms::Label^  lblCategory;
	private: System::Windows::Forms::TextBox^  txtbxCategory;
	private: System::Windows::Forms::Label^  lblVendor;
	private: System::Windows::Forms::TextBox^  txtbxVendor;
	private: System::Windows::Forms::Label^  lblUnitsInACase;

	private: System::Windows::Forms::TextBox^  txtbxUnitsInACase;
	private: System::Windows::Forms::Label^  lblWholesaleCostOfACase;

	private: System::Windows::Forms::TextBox^  txtbxWholesaleCostOfACase;
	private: System::Windows::Forms::Label^  lblNumberOfCases;
	private: System::Windows::Forms::TextBox^  txtbxNumberOfCases;

	private: System::Windows::Forms::Label^  lblNumberOfItems;
	private: System::Windows::Forms::TextBox^  txtbxNumberOfItems;
	private: System::Windows::Forms::Label^  lblWholesaleCostOfItem;
	private: System::Windows::Forms::TextBox^  txtbxWholesaleCostOfItem;
	private: System::Windows::Forms::Label^  lblRetailValueOfCase;
	private: System::Windows::Forms::TextBox^  txtbxRetailValueOfCase;
	private: System::Windows::Forms::Label^  lblTotalWholesaleCost;
	private: System::Windows::Forms::Label^  lblRetailValueOfItem;
	private: System::Windows::Forms::Label^  lblTotalRetailValue;
	private: System::Windows::Forms::TextBox^  txtbxTotalWholesaleCost;
	private: System::Windows::Forms::TextBox^  txtbxRetailValueOfItem;
	private: System::Windows::Forms::TextBox^  txtbxTotalRetailValue;
	private: System::Windows::Forms::Label^  lblDateUpdated;
	private: System::Windows::Forms::TextBox^  txtbxDateUpdated;
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
			this->lbInventory = (gcnew System::Windows::Forms::ListBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->txtbxName = (gcnew System::Windows::Forms::TextBox());
			this->lblCategory = (gcnew System::Windows::Forms::Label());
			this->txtbxCategory = (gcnew System::Windows::Forms::TextBox());
			this->lblVendor = (gcnew System::Windows::Forms::Label());
			this->txtbxVendor = (gcnew System::Windows::Forms::TextBox());
			this->lblUnitsInACase = (gcnew System::Windows::Forms::Label());
			this->txtbxUnitsInACase = (gcnew System::Windows::Forms::TextBox());
			this->lblWholesaleCostOfACase = (gcnew System::Windows::Forms::Label());
			this->txtbxWholesaleCostOfACase = (gcnew System::Windows::Forms::TextBox());
			this->lblNumberOfCases = (gcnew System::Windows::Forms::Label());
			this->txtbxNumberOfCases = (gcnew System::Windows::Forms::TextBox());
			this->lblNumberOfItems = (gcnew System::Windows::Forms::Label());
			this->txtbxNumberOfItems = (gcnew System::Windows::Forms::TextBox());
			this->lblWholesaleCostOfItem = (gcnew System::Windows::Forms::Label());
			this->txtbxWholesaleCostOfItem = (gcnew System::Windows::Forms::TextBox());
			this->lblRetailValueOfCase = (gcnew System::Windows::Forms::Label());
			this->txtbxRetailValueOfCase = (gcnew System::Windows::Forms::TextBox());
			this->lblTotalWholesaleCost = (gcnew System::Windows::Forms::Label());
			this->lblRetailValueOfItem = (gcnew System::Windows::Forms::Label());
			this->lblTotalRetailValue = (gcnew System::Windows::Forms::Label());
			this->txtbxTotalWholesaleCost = (gcnew System::Windows::Forms::TextBox());
			this->txtbxRetailValueOfItem = (gcnew System::Windows::Forms::TextBox());
			this->txtbxTotalRetailValue = (gcnew System::Windows::Forms::TextBox());
			this->lblDateUpdated = (gcnew System::Windows::Forms::Label());
			this->txtbxDateUpdated = (gcnew System::Windows::Forms::TextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbInventory
			// 
			this->lbInventory->AccessibleDescription = L"Inventory List Box";
			this->lbInventory->AccessibleName = L"Inventory List Box";
			this->lbInventory->FormattingEnabled = true;
			this->lbInventory->HorizontalScrollbar = true;
			this->lbInventory->Location = System::Drawing::Point(13, 13);
			this->lbInventory->Name = L"lbInventory";
			this->lbInventory->Size = System::Drawing::Size(167, 238);
			this->lbInventory->TabIndex = 0;
			this->lbInventory->SelectedIndexChanged += gcnew System::EventHandler(this, &frmInventory::lbInventory_SelectedIndexChanged);
			this->lbInventory->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmInventory::lbInventory_MouseDown);
			this->lbInventory->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &frmInventory::lbInventory_PreviewKeyDown);
			// 
			// lblName
			// 
			this->lblName->AccessibleDescription = L"Name";
			this->lblName->AccessibleName = L"Name";
			this->lblName->AutoSize = true;
			this->lblName->Location = System::Drawing::Point(186, 13);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(35, 13);
			this->lblName->TabIndex = 1;
			this->lblName->Text = L"Name";
			// 
			// txtbxName
			// 
			this->txtbxName->AccessibleDescription = L"Name";
			this->txtbxName->AccessibleName = L"Name";
			this->txtbxName->Location = System::Drawing::Point(320, 13);
			this->txtbxName->Name = L"txtbxName";
			this->txtbxName->Size = System::Drawing::Size(218, 20);
			this->txtbxName->TabIndex = 2;
			this->txtbxName->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxName_TextChanged);
			// 
			// lblCategory
			// 
			this->lblCategory->AccessibleDescription = L"Category";
			this->lblCategory->AccessibleName = L"Category";
			this->lblCategory->AutoSize = true;
			this->lblCategory->Location = System::Drawing::Point(186, 40);
			this->lblCategory->Name = L"lblCategory";
			this->lblCategory->Size = System::Drawing::Size(49, 13);
			this->lblCategory->TabIndex = 3;
			this->lblCategory->Text = L"Category";
			// 
			// txtbxCategory
			// 
			this->txtbxCategory->AccessibleDescription = L"Category";
			this->txtbxCategory->AccessibleName = L"Category";
			this->txtbxCategory->Location = System::Drawing::Point(320, 40);
			this->txtbxCategory->Name = L"txtbxCategory";
			this->txtbxCategory->Size = System::Drawing::Size(218, 20);
			this->txtbxCategory->TabIndex = 4;
			this->txtbxCategory->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxCategory_TextChanged);
			// 
			// lblVendor
			// 
			this->lblVendor->AccessibleDescription = L"Vendor";
			this->lblVendor->AccessibleName = L"Vendor";
			this->lblVendor->AutoSize = true;
			this->lblVendor->Location = System::Drawing::Point(186, 66);
			this->lblVendor->Name = L"lblVendor";
			this->lblVendor->Size = System::Drawing::Size(41, 13);
			this->lblVendor->TabIndex = 5;
			this->lblVendor->Text = L"Vendor";
			// 
			// txtbxVendor
			// 
			this->txtbxVendor->AccessibleDescription = L"Vendor";
			this->txtbxVendor->AccessibleName = L"Vendor";
			this->txtbxVendor->Location = System::Drawing::Point(320, 66);
			this->txtbxVendor->Name = L"txtbxVendor";
			this->txtbxVendor->Size = System::Drawing::Size(218, 20);
			this->txtbxVendor->TabIndex = 6;
			this->txtbxVendor->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxVendor_TextChanged);
			// 
			// lblUnitsInACase
			// 
			this->lblUnitsInACase->AccessibleDescription = L"Units in a Case";
			this->lblUnitsInACase->AccessibleName = L"Units in a Case";
			this->lblUnitsInACase->AutoSize = true;
			this->lblUnitsInACase->Location = System::Drawing::Point(186, 92);
			this->lblUnitsInACase->Name = L"lblUnitsInACase";
			this->lblUnitsInACase->Size = System::Drawing::Size(79, 13);
			this->lblUnitsInACase->TabIndex = 7;
			this->lblUnitsInACase->Text = L"Items in a Case";
			// 
			// txtbxUnitsInACase
			// 
			this->txtbxUnitsInACase->AccessibleDescription = L"Units in a Case";
			this->txtbxUnitsInACase->AccessibleName = L"Units in a Case";
			this->txtbxUnitsInACase->Location = System::Drawing::Point(320, 92);
			this->txtbxUnitsInACase->Name = L"txtbxUnitsInACase";
			this->txtbxUnitsInACase->Size = System::Drawing::Size(100, 20);
			this->txtbxUnitsInACase->TabIndex = 8;
			this->txtbxUnitsInACase->Text = L"1";
			this->txtbxUnitsInACase->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxUnitsInACase_TextChanged);
			this->txtbxUnitsInACase->Enter += gcnew System::EventHandler(this, &frmInventory::txtbxUnitsInACase_Enter);
			this->txtbxUnitsInACase->Leave += gcnew System::EventHandler(this, &frmInventory::txtbxUnitsInACase_Leave);
			// 
			// lblWholesaleCostOfACase
			// 
			this->lblWholesaleCostOfACase->AccessibleDescription = L"Wholesale Cost of a Case";
			this->lblWholesaleCostOfACase->AccessibleName = L"Wholesale Cost of a Case";
			this->lblWholesaleCostOfACase->AutoSize = true;
			this->lblWholesaleCostOfACase->Location = System::Drawing::Point(186, 147);
			this->lblWholesaleCostOfACase->Name = L"lblWholesaleCostOfACase";
			this->lblWholesaleCostOfACase->Size = System::Drawing::Size(129, 13);
			this->lblWholesaleCostOfACase->TabIndex = 15;
			this->lblWholesaleCostOfACase->Text = L"Wholesale Cost of a Case";
			// 
			// txtbxWholesaleCostOfACase
			// 
			this->txtbxWholesaleCostOfACase->AccessibleDescription = L"Wholesale Cost of a Case";
			this->txtbxWholesaleCostOfACase->AccessibleName = L"Wholesale Cost of a Case";
			this->txtbxWholesaleCostOfACase->Location = System::Drawing::Point(320, 147);
			this->txtbxWholesaleCostOfACase->Name = L"txtbxWholesaleCostOfACase";
			this->txtbxWholesaleCostOfACase->Size = System::Drawing::Size(100, 20);
			this->txtbxWholesaleCostOfACase->TabIndex = 16;
			this->txtbxWholesaleCostOfACase->Text = L"1";
			this->txtbxWholesaleCostOfACase->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxWholesaleCostOfACase_TextChanged);
			this->txtbxWholesaleCostOfACase->Enter += gcnew System::EventHandler(this, &frmInventory::txtbxWholesaleCostOfACase_Enter);
			this->txtbxWholesaleCostOfACase->Leave += gcnew System::EventHandler(this, &frmInventory::txtbxWholesaleCostOfACase_Leave);
			this->txtbxWholesaleCostOfACase->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmInventory::Double_Validating);
			// 
			// lblNumberOfCases
			// 
			this->lblNumberOfCases->AutoSize = true;
			this->lblNumberOfCases->Location = System::Drawing::Point(435, 92);
			this->lblNumberOfCases->Name = L"lblNumberOfCases";
			this->lblNumberOfCases->Size = System::Drawing::Size(88, 13);
			this->lblNumberOfCases->TabIndex = 9;
			this->lblNumberOfCases->Text = L"Number of Cases";
			// 
			// txtbxNumberOfCases
			// 
			this->txtbxNumberOfCases->Location = System::Drawing::Point(569, 92);
			this->txtbxNumberOfCases->Name = L"txtbxNumberOfCases";
			this->txtbxNumberOfCases->Size = System::Drawing::Size(100, 20);
			this->txtbxNumberOfCases->TabIndex = 10;
			this->txtbxNumberOfCases->Text = L"1";
			this->txtbxNumberOfCases->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxNumberOfCases_TextChanged);
			this->txtbxNumberOfCases->Enter += gcnew System::EventHandler(this, &frmInventory::txtbxNumberOfCases_Enter);
			this->txtbxNumberOfCases->Leave += gcnew System::EventHandler(this, &frmInventory::txtbxNumberOfCases_Leave);
			this->txtbxNumberOfCases->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmInventory::Double_Validating);
			// 
			// lblNumberOfItems
			// 
			this->lblNumberOfItems->AutoSize = true;
			this->lblNumberOfItems->Location = System::Drawing::Point(186, 118);
			this->lblNumberOfItems->Name = L"lblNumberOfItems";
			this->lblNumberOfItems->Size = System::Drawing::Size(84, 13);
			this->lblNumberOfItems->TabIndex = 11;
			this->lblNumberOfItems->Text = L"Number of Items";
			// 
			// txtbxNumberOfItems
			// 
			this->txtbxNumberOfItems->Location = System::Drawing::Point(320, 118);
			this->txtbxNumberOfItems->Name = L"txtbxNumberOfItems";
			this->txtbxNumberOfItems->Size = System::Drawing::Size(100, 20);
			this->txtbxNumberOfItems->TabIndex = 12;
			this->txtbxNumberOfItems->Text = L"1";
			this->txtbxNumberOfItems->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxNumberOfItems_TextChanged);
			this->txtbxNumberOfItems->Enter += gcnew System::EventHandler(this, &frmInventory::txtbxNumberOfItems_Enter);
			this->txtbxNumberOfItems->Leave += gcnew System::EventHandler(this, &frmInventory::txtbxNumberOfItems_Leave);
			// 
			// lblWholesaleCostOfItem
			// 
			this->lblWholesaleCostOfItem->AutoSize = true;
			this->lblWholesaleCostOfItem->Location = System::Drawing::Point(186, 174);
			this->lblWholesaleCostOfItem->Name = L"lblWholesaleCostOfItem";
			this->lblWholesaleCostOfItem->Size = System::Drawing::Size(116, 13);
			this->lblWholesaleCostOfItem->TabIndex = 17;
			this->lblWholesaleCostOfItem->Text = L"Wholesale Cost of Item";
			// 
			// txtbxWholesaleCostOfItem
			// 
			this->txtbxWholesaleCostOfItem->Location = System::Drawing::Point(320, 174);
			this->txtbxWholesaleCostOfItem->Name = L"txtbxWholesaleCostOfItem";
			this->txtbxWholesaleCostOfItem->Size = System::Drawing::Size(100, 20);
			this->txtbxWholesaleCostOfItem->TabIndex = 18;
			this->txtbxWholesaleCostOfItem->Text = L"1";
			this->txtbxWholesaleCostOfItem->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxWholesaleCostOfItem_TextChanged);
			this->txtbxWholesaleCostOfItem->Enter += gcnew System::EventHandler(this, &frmInventory::txtbxWholesaleCostOfItem_Enter);
			this->txtbxWholesaleCostOfItem->Leave += gcnew System::EventHandler(this, &frmInventory::txtbxWholesaleCostOfItem_Leave);
			this->txtbxWholesaleCostOfItem->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmInventory::Double_Validating);
			// 
			// lblRetailValueOfCase
			// 
			this->lblRetailValueOfCase->AutoSize = true;
			this->lblRetailValueOfCase->Location = System::Drawing::Point(435, 147);
			this->lblRetailValueOfCase->Name = L"lblRetailValueOfCase";
			this->lblRetailValueOfCase->Size = System::Drawing::Size(103, 13);
			this->lblRetailValueOfCase->TabIndex = 21;
			this->lblRetailValueOfCase->Text = L"Retail Value of Case";
			// 
			// txtbxRetailValueOfCase
			// 
			this->txtbxRetailValueOfCase->Location = System::Drawing::Point(569, 143);
			this->txtbxRetailValueOfCase->Name = L"txtbxRetailValueOfCase";
			this->txtbxRetailValueOfCase->Size = System::Drawing::Size(100, 20);
			this->txtbxRetailValueOfCase->TabIndex = 22;
			this->txtbxRetailValueOfCase->Text = L"1";
			this->txtbxRetailValueOfCase->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxRetailValueOfCase_TextChanged);
			this->txtbxRetailValueOfCase->Enter += gcnew System::EventHandler(this, &frmInventory::txtbxRetailValueOfCase_Enter);
			this->txtbxRetailValueOfCase->Leave += gcnew System::EventHandler(this, &frmInventory::txtbxRetailValueOfCase_Leave);
			this->txtbxRetailValueOfCase->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmInventory::Double_Validating);
			// 
			// lblTotalWholesaleCost
			// 
			this->lblTotalWholesaleCost->AutoSize = true;
			this->lblTotalWholesaleCost->Location = System::Drawing::Point(189, 201);
			this->lblTotalWholesaleCost->Name = L"lblTotalWholesaleCost";
			this->lblTotalWholesaleCost->Size = System::Drawing::Size(108, 13);
			this->lblTotalWholesaleCost->TabIndex = 19;
			this->lblTotalWholesaleCost->Text = L"Total Wholesale Cost";
			// 
			// lblRetailValueOfItem
			// 
			this->lblRetailValueOfItem->AutoSize = true;
			this->lblRetailValueOfItem->Location = System::Drawing::Point(435, 174);
			this->lblRetailValueOfItem->Name = L"lblRetailValueOfItem";
			this->lblRetailValueOfItem->Size = System::Drawing::Size(99, 13);
			this->lblRetailValueOfItem->TabIndex = 23;
			this->lblRetailValueOfItem->Text = L"Retail Value of Item";
			// 
			// lblTotalRetailValue
			// 
			this->lblTotalRetailValue->AutoSize = true;
			this->lblTotalRetailValue->Location = System::Drawing::Point(435, 201);
			this->lblTotalRetailValue->Name = L"lblTotalRetailValue";
			this->lblTotalRetailValue->Size = System::Drawing::Size(91, 13);
			this->lblTotalRetailValue->TabIndex = 25;
			this->lblTotalRetailValue->Text = L"Total Retail Value";
			// 
			// txtbxTotalWholesaleCost
			// 
			this->txtbxTotalWholesaleCost->Location = System::Drawing::Point(320, 201);
			this->txtbxTotalWholesaleCost->Name = L"txtbxTotalWholesaleCost";
			this->txtbxTotalWholesaleCost->ReadOnly = true;
			this->txtbxTotalWholesaleCost->Size = System::Drawing::Size(100, 20);
			this->txtbxTotalWholesaleCost->TabIndex = 20;
			this->txtbxTotalWholesaleCost->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxTotalWholesaleCost_TextChanged);
			// 
			// txtbxRetailValueOfItem
			// 
			this->txtbxRetailValueOfItem->Location = System::Drawing::Point(569, 173);
			this->txtbxRetailValueOfItem->Name = L"txtbxRetailValueOfItem";
			this->txtbxRetailValueOfItem->Size = System::Drawing::Size(100, 20);
			this->txtbxRetailValueOfItem->TabIndex = 24;
			this->txtbxRetailValueOfItem->Text = L"1";
			this->txtbxRetailValueOfItem->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxRetailValueOfItem_TextChanged);
			this->txtbxRetailValueOfItem->Enter += gcnew System::EventHandler(this, &frmInventory::txtbxRetailValueOfItem_Enter);
			this->txtbxRetailValueOfItem->Leave += gcnew System::EventHandler(this, &frmInventory::txtbxRetailValueOfItem_Leave);
			this->txtbxRetailValueOfItem->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmInventory::Double_Validating);
			// 
			// txtbxTotalRetailValue
			// 
			this->txtbxTotalRetailValue->Location = System::Drawing::Point(569, 200);
			this->txtbxTotalRetailValue->Name = L"txtbxTotalRetailValue";
			this->txtbxTotalRetailValue->ReadOnly = true;
			this->txtbxTotalRetailValue->Size = System::Drawing::Size(100, 20);
			this->txtbxTotalRetailValue->TabIndex = 26;
			this->txtbxTotalRetailValue->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxTotalRetailValue_TextChanged);
			// 
			// lblDateUpdated
			// 
			this->lblDateUpdated->AutoSize = true;
			this->lblDateUpdated->Location = System::Drawing::Point(435, 118);
			this->lblDateUpdated->Name = L"lblDateUpdated";
			this->lblDateUpdated->Size = System::Drawing::Size(74, 13);
			this->lblDateUpdated->TabIndex = 13;
			this->lblDateUpdated->Text = L"Date Updated";
			// 
			// txtbxDateUpdated
			// 
			this->txtbxDateUpdated->Location = System::Drawing::Point(569, 117);
			this->txtbxDateUpdated->Name = L"txtbxDateUpdated";
			this->txtbxDateUpdated->ReadOnly = true;
			this->txtbxDateUpdated->Size = System::Drawing::Size(100, 20);
			this->txtbxDateUpdated->TabIndex = 14;
			this->txtbxDateUpdated->TextChanged += gcnew System::EventHandler(this, &frmInventory::txtbxDateUpdated_TextChanged);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(433, 229);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(75, 23);
			this->btnSave->TabIndex = 29;
			this->btnSave->Text = L"&Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmInventory::btnSave_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(514, 229);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 30;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmInventory::btnClose_Click);
			// 
			// btnNew
			// 
			this->btnNew->Location = System::Drawing::Point(271, 228);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(75, 23);
			this->btnNew->TabIndex = 27;
			this->btnNew->Text = L"&New";
			this->btnNew->UseVisualStyleBackColor = true;
			this->btnNew->Click += gcnew System::EventHandler(this, &frmInventory::btnNew_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(352, 228);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 28;
			this->btnDelete->Text = L"&Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmInventory::btnDelete_Click);
			// 
			// frmInventory
			// 
			this->AccessibleDescription = L"Inventory";
			this->AccessibleName = L"Inventory";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(685, 263);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnNew);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtbxDateUpdated);
			this->Controls->Add(this->lblDateUpdated);
			this->Controls->Add(this->txtbxTotalRetailValue);
			this->Controls->Add(this->txtbxRetailValueOfItem);
			this->Controls->Add(this->txtbxTotalWholesaleCost);
			this->Controls->Add(this->lblTotalRetailValue);
			this->Controls->Add(this->lblRetailValueOfItem);
			this->Controls->Add(this->lblTotalWholesaleCost);
			this->Controls->Add(this->txtbxRetailValueOfCase);
			this->Controls->Add(this->lblRetailValueOfCase);
			this->Controls->Add(this->txtbxWholesaleCostOfItem);
			this->Controls->Add(this->lblWholesaleCostOfItem);
			this->Controls->Add(this->txtbxNumberOfItems);
			this->Controls->Add(this->lblNumberOfItems);
			this->Controls->Add(this->txtbxNumberOfCases);
			this->Controls->Add(this->lblNumberOfCases);
			this->Controls->Add(this->txtbxWholesaleCostOfACase);
			this->Controls->Add(this->lblWholesaleCostOfACase);
			this->Controls->Add(this->txtbxUnitsInACase);
			this->Controls->Add(this->lblUnitsInACase);
			this->Controls->Add(this->txtbxVendor);
			this->Controls->Add(this->lblVendor);
			this->Controls->Add(this->txtbxCategory);
			this->Controls->Add(this->lblCategory);
			this->Controls->Add(this->txtbxName);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->lbInventory);
			this->Name = L"frmInventory";
			this->Text = L"Inventory";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmInventory::frmInventory_FormClosing);
			this->Load += gcnew System::EventHandler(this, &frmInventory::frmInventory_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmInventory_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
				 //lbInventory->DataSource = BEOPSGlobals::datBEOPSData->arrInventory;
				 int nTemp=0;
				 if(BEOPSGlobals::datBEOPSData->arrInventory->Count>0)
				 {
					 BEOPSGlobals::datBEOPSData->arrInventory->Sort();
					 lbInventory->BeginUpdate();
				 
					 while (nTemp<BEOPSGlobals::datBEOPSData->arrInventory->Count)
					 {
						 lbInventory->Items->Add(BEOPSGlobals::datBEOPSData->arrInventory[nTemp]);
						 nTemp++;
					 }
					 lbInventory->EndUpdate();
					 bDataChanged = false;
				 }
				 else
				 {
					 ClearAndLock();
					 btnDelete->Enabled=false;
					 btnSave->Enabled=false;
					 btnNew->Focus();
				 }
//				 bRecalculate=false;
			 }
	private: System::Void lbInventory_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
				 double dblNumberOfCases, dblWholesaleCostOfCase, dblRetailValueOfCase, dblTotalRetailValue, dblTotalWholesaleCost;
				 dblNumberOfCases = ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitCount/((BEOPSInventory^)lbInventory->SelectedItem)->dblNumberInCase;
				 dblWholesaleCostOfCase = ((BEOPSInventory^)lbInventory->SelectedItem)->dblNumberInCase*((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitWholesaleCost;
				 dblRetailValueOfCase = ((BEOPSInventory^)lbInventory->SelectedItem)->dblNumberInCase*((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitRetailValue;
				 dblTotalRetailValue = ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitRetailValue*((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitCount;
				 dblTotalWholesaleCost = ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitWholesaleCost*((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitCount;

				 txtbxName->Text = ((BEOPSInventory^)lbInventory->SelectedItem)->strItemName;
				 txtbxDateUpdated->Text = ((BEOPSInventory^)lbInventory->SelectedItem)->dteDateRecorded.ToShortDateString();
				 txtbxVendor->Text = ((BEOPSInventory^)lbInventory->SelectedItem)->strVendorName;
				 txtbxCategory->Text = ((BEOPSInventory^)lbInventory->SelectedItem)->strCategory;
				 txtbxUnitsInACase->Text = System::Convert::ToString(((BEOPSInventory^)lbInventory->SelectedItem)->dblNumberInCase);
				 txtbxWholesaleCostOfItem->Text = ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitWholesaleCost.ToString("f2");
				 txtbxRetailValueOfItem->Text = ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitRetailValue.ToString("f2");
				 txtbxNumberOfItems->Text = System::Convert::ToString(((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitCount);
				 txtbxNumberOfCases->Text = dblNumberOfCases.ToString("f2");
				 txtbxWholesaleCostOfACase->Text = dblWholesaleCostOfCase.ToString("f2");
				 txtbxRetailValueOfCase->Text = dblRetailValueOfCase.ToString("f2");
				 txtbxTotalRetailValue->Text = dblTotalRetailValue.ToString("f2");
				 txtbxTotalWholesaleCost->Text = dblTotalWholesaleCost.ToString("f2");

				 this->Text = L"Inventory - " + txtbxName->Text;
				 bDataChanged = false;
//				 bRecalculate=false;
				 bJustCalculated=false;
			 }
private: System::Void txtbxName_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 bDataChanged = true;
		 }
private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //TODO: Find out why saving causes the number to change. I think it's in the calcuation of the fields.
			 //First, update the data object and save changes to disk
			 ((BEOPSInventory^)lbInventory->SelectedItem)->strItemName = txtbxName->Text;
			 ((BEOPSInventory^)lbInventory->SelectedItem)->dteDateRecorded = System::Convert::ToDateTime(txtbxDateUpdated->Text);
			 ((BEOPSInventory^)lbInventory->SelectedItem)->strVendorName = txtbxVendor->Text;
			 ((BEOPSInventory^)lbInventory->SelectedItem)->strCategory = txtbxCategory->Text;
			 ((BEOPSInventory^)lbInventory->SelectedItem)->dblNumberInCase = System::Convert::ToDouble(txtbxUnitsInACase->Text);
			 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitWholesaleCost = System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text);
			 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitRetailValue = System::Convert::ToDouble(txtbxRetailValueOfItem->Text);
			 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitCount = System::Convert::ToDouble(txtbxNumberOfItems->Text);
			 //I decided not to have it save to disk at this point. Saving to disk should only happen at main menu
			 //BEOPSGlobals::datBEOPSData->Save(BEOPSGlobals::datBEOPSData->strCurrentFileName);
			 //Next, clear and redraw the listbox
			 int nSelectedIndex = lbInventory->SelectedIndex;
			 lbInventory->Items->Clear();
			 int nTemp=0;
			 BEOPSGlobals::datBEOPSData->arrInventory->Sort();
			 lbInventory->BeginUpdate();
			 while (nTemp<BEOPSGlobals::datBEOPSData->arrInventory->Count)
			 {
				lbInventory->Items->Add(BEOPSGlobals::datBEOPSData->arrInventory[nTemp]);
				nTemp++;
			 }
			 lbInventory->EndUpdate();
			 lbInventory->SelectedIndex = nSelectedIndex;
			 
			 bDataChanged = false;
		 }
private: System::Void txtbxCategory_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;
		 }
private: System::Void txtbxVendor_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;
		 }
private: System::Void txtbxUnitsInACase_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 /*If you change the number of units in a case this does not change Number of items
			 However, it will change the case wholesale and retail values and the number of cases (or items?)
			 */

			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;


		 }
private: System::Void txtbxNumberOfItems_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;
		 }
private: System::Void txtbxWholesaleCostOfACase_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;
		 }
private: System::Void txtbxWholesaleCostOfItem_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;
		 }
private: System::Void txtbxTotalWholesaleCost_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 bDataChanged = true;
			 double dblTemp;
			 if(Double::TryParse(txtbxTotalWholesaleCost->Text, dblTemp))
			 {
				dblTemp = System::Convert::ToDouble(txtbxTotalWholesaleCost->Text);
				txtbxTotalWholesaleCost->Text = dblTemp.ToString("f2");

			 }
			 if(bJustCalculated) bDataChanged = false;
		 }
private: System::Void txtbxNumberOfCases_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;
		 }
private: System::Void txtbxDateUpdated_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;

		 }
private: System::Void txtbxRetailValueOfCase_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;
		 }
private: System::Void txtbxRetailValueOfItem_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 bDataChanged = true;
			 if(bJustCalculated) bDataChanged = false;

		 }
private: System::Void txtbxTotalRetailValue_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

			 bDataChanged = true;
			 double dblTemp;
			 if(Double::TryParse(txtbxTotalRetailValue->Text, dblTemp))
			 {
				dblTemp = System::Convert::ToDouble(txtbxTotalRetailValue->Text);
				txtbxTotalRetailValue->Text = dblTemp.ToString("f2");

			 }
			 if(bJustCalculated) bDataChanged = false;
		 }
private: System::Void txtbxUnitsInACase_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(bDataChanged)
			 {

			double dTemp;
			if (!System::Double::TryParse(txtbxUnitsInACase->Text,dTemp))
			{
				txtbxUnitsInACase->Text = L"1";
				txtbxUnitsInACase->Select();
			}
			else
			{

				double dblNumberOfCases, dblWholesaleCostOfACase, dblRetailValueOfCase;
				dblNumberOfCases = System::Convert::ToDouble(txtbxNumberOfItems->Text)/System::Convert::ToDouble(txtbxUnitsInACase->Text);
				dblWholesaleCostOfACase = System::Convert::ToDouble(txtbxUnitsInACase->Text)*System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text);
				dblRetailValueOfCase = System::Convert::ToDouble(txtbxUnitsInACase->Text)*System::Convert::ToDouble(txtbxRetailValueOfItem->Text);

				txtbxNumberOfCases->Text = dblNumberOfCases.ToString("f2");
				txtbxWholesaleCostOfACase->Text = dblWholesaleCostOfACase.ToString("f2");
				txtbxRetailValueOfCase->Text = dblRetailValueOfCase.ToString("f2");

			}
			bJustCalculated=true;
			 }
		 }
private: System::Void txtbxNumberOfCases_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(bDataChanged)
			 {
			double dTemp;
			if (!System::Double::TryParse(txtbxNumberOfCases->Text,dTemp))
			{
				dTemp = System::Convert::ToDouble(txtbxNumberOfItems->Text)/System::Convert::ToDouble(txtbxUnitsInACase->Text);
				txtbxNumberOfCases->Text = dTemp.ToString("f2");
				txtbxNumberOfCases->Select();
			}
			else
			{
				double dblRetailValue = System::Convert::ToDouble(txtbxRetailValueOfItem->Text)*System::Convert::ToDouble(txtbxNumberOfItems->Text);
				double dblWholesaleCost = System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text)*System::Convert::ToDouble(txtbxNumberOfItems->Text);
				txtbxNumberOfItems->Text = System::Convert::ToString(System::Convert::ToDouble(txtbxNumberOfCases->Text)*System::Convert::ToDouble(txtbxUnitsInACase->Text));
				txtbxTotalRetailValue->Text = dblRetailValue.ToString("f2");
				txtbxTotalWholesaleCost->Text = dblWholesaleCost.ToString("f2");
				bJustCalculated=true;
			}
			
			 }
		 }
private: System::Void txtbxNumberOfItems_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(bDataChanged)
			 {
			 
			 double dTemp;
			 if(!System::Double::TryParse(txtbxNumberOfItems->Text,dTemp))
			 {
				 dTemp = System::Convert::ToDouble(txtbxNumberOfCases->Text)*System::Convert::ToDouble(txtbxUnitsInACase->Text);
				 txtbxNumberOfItems->Text = dTemp.ToString("f2");
				 txtbxNumberOfItems->Select();
			 }
			 else
			 {
				 double dblTotalRetailValue = System::Convert::ToDouble(txtbxRetailValueOfItem->Text)*System::Convert::ToDouble(txtbxNumberOfItems->Text);
				 double dblTotalWholesaleCost = System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text)*System::Convert::ToDouble(txtbxNumberOfItems->Text);
				 txtbxNumberOfCases->Text = System::Convert::ToString(System::Convert::ToDouble(txtbxNumberOfItems->Text)/System::Convert::ToDouble(txtbxUnitsInACase->Text));
				 txtbxTotalRetailValue->Text = dblTotalRetailValue.ToString("f2");
				 txtbxTotalWholesaleCost->Text = dblTotalWholesaleCost.ToString("f2");

			 }
			 bJustCalculated=true;
			 }
		 }
private: System::Void txtbxWholesaleCostOfACase_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(bDataChanged)
			 {
			 double dTemp;
			 if(!System::Double::TryParse(txtbxWholesaleCostOfACase->Text,dTemp))
			 {
				dTemp = System::Convert::ToDouble(txtbxUnitsInACase->Text)*System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text);
				txtbxWholesaleCostOfACase->Text = dTemp.ToString("f2");
				txtbxWholesaleCostOfACase->Select();
			 }
			 else
			 {
				 double dblWholesaleCostOfItem = System::Convert::ToDouble(txtbxWholesaleCostOfACase->Text)/System::Convert::ToDouble(txtbxUnitsInACase->Text);
				 double dblTotalWholesaleCost = System::Convert::ToDouble(txtbxWholesaleCostOfACase->Text)*System::Convert::ToDouble(txtbxNumberOfCases->Text);
				 txtbxWholesaleCostOfItem->Text = dblWholesaleCostOfItem.ToString("f2");
				 txtbxTotalWholesaleCost->Text = dblTotalWholesaleCost.ToString("f2");
				 
			 }
			 
			 }
			 bJustCalculated=true;
		 }
private: System::Void txtbxWholesaleCostOfItem_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
			 if(bDataChanged)
			 {
			 double dTemp;
			 if(!System::Double::TryParse(txtbxWholesaleCostOfItem->Text,dTemp))
			 {
				 dTemp = System::Convert::ToDouble(txtbxTotalWholesaleCost->Text)/System::Convert::ToDouble(txtbxNumberOfItems->Text);
				 txtbxWholesaleCostOfItem->Text = dTemp.ToString("f2");
				 txtbxWholesaleCostOfItem->Select();
			 }
			 else
			 {
				 double dblWholesaleCostOfACase = System::Convert::ToDouble(txtbxUnitsInACase->Text)*System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text);
				 double dblTotalWholesaleCost = System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text)*System::Convert::ToDouble(txtbxNumberOfItems->Text);
				 txtbxWholesaleCostOfACase->Text = dblWholesaleCostOfACase.ToString("f2");
				 txtbxTotalWholesaleCost->Text = dblTotalWholesaleCost.ToString("f2");

			 }
			 bJustCalculated=true;
			 }

		 }
private: System::Void txtbxRetailValueOfCase_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
			 if(bDataChanged)
			 {
			 double dTemp;
			 if(!System::Double::TryParse(txtbxRetailValueOfCase->Text,dTemp))
			 {
				 dTemp = System::Convert::ToDouble(txtbxUnitsInACase->Text)*System::Convert::ToDouble(txtbxRetailValueOfItem->Text);
				 txtbxRetailValueOfCase->Text = dTemp.ToString("f2");
				 txtbxRetailValueOfCase->Select();
			 }
			 else
			 {
				 double dblRetailValueOfItem = System::Convert::ToDouble(txtbxRetailValueOfCase->Text)/System::Convert::ToDouble(txtbxUnitsInACase->Text);
				 double dblTotalRetailValue = System::Convert::ToDouble(txtbxRetailValueOfCase->Text)*System::Convert::ToDouble(txtbxNumberOfCases->Text);
				 txtbxRetailValueOfItem->Text = dblRetailValueOfItem.ToString("f2");
				 txtbxTotalRetailValue->Text = dblTotalRetailValue.ToString("f2");
				 bJustCalculated=true;
			 }
			 
			 }
		 }
private: System::Void txtbxRetailValueOfItem_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(bDataChanged)
			 {
			 double dTemp;
			 if(!System::Double::TryParse(txtbxRetailValueOfCase->Text,dTemp))
			 {
				 dTemp = System::Convert::ToDouble(txtbxRetailValueOfCase->Text)/System::Convert::ToDouble(txtbxUnitsInACase->Text);
				 txtbxRetailValueOfItem->Text = dTemp.ToString("f2");
				 txtbxRetailValueOfItem->Select();
			 }
			 else
			 {
				 double dblRetailValueOfCase = System::Convert::ToDouble(txtbxUnitsInACase->Text)*System::Convert::ToDouble(txtbxRetailValueOfItem->Text);
				 double dblTotalRetailValue = System::Convert::ToDouble(txtbxRetailValueOfItem->Text)*System::Convert::ToDouble(txtbxNumberOfItems->Text);
				 txtbxRetailValueOfCase->Text = dblRetailValueOfCase.ToString("f2");
				 txtbxTotalRetailValue->Text = dblTotalRetailValue.ToString("f2");
				 bJustCalculated=true;
			 }
			 
			 }
		 }
private: System::Void frmInventory_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		 {
			 if(bDataChanged)
			 {
				 //Dialog to see if want to save changes
				 String^ strMessage = "There are unsaved changes to this record. Do you want to save them now?";
				 String^ strCaption = "Unsaved changes";
				 MessageBoxButtons mbbButtons = MessageBoxButtons::YesNoCancel;
				 System::Windows::Forms::DialogResult drResult;

				 drResult = MessageBox::Show(this,strMessage,strCaption,mbbButtons,MessageBoxIcon::Question,MessageBoxDefaultButton::Button1);
				 if (drResult == System::Windows::Forms::DialogResult::Yes)
				 {
					 //Then save
					 ((BEOPSInventory^)lbInventory->SelectedItem)->strItemName = txtbxName->Text;
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dteDateRecorded = System::Convert::ToDateTime(txtbxDateUpdated->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->strVendorName = txtbxVendor->Text;
					 ((BEOPSInventory^)lbInventory->SelectedItem)->strCategory = txtbxCategory->Text;
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblNumberInCase = System::Convert::ToDouble(txtbxUnitsInACase->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitWholesaleCost = System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitRetailValue = System::Convert::ToDouble(txtbxRetailValueOfItem->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitCount = System::Convert::ToDouble(txtbxNumberOfItems->Text);
					 
					 e->Cancel = false;
				 }
				 if (drResult == System::Windows::Forms::DialogResult::No)
				 {
					 e->Cancel = false;
				 }
				 if (drResult == System::Windows::Forms::DialogResult::Cancel)
				 {
					 e->Cancel = true;
				 }
				 bDataChanged = false;
			 }
			 else
				 e->Cancel = false;
		 }

private: System::Void lbInventory_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) 
		 {
			 if (bDataChanged)
			 {
				 //Dialog to see if want to save changes
				 String^ strMessage = "There are unsaved changes to this record. Do you want to save them now?";
				 String^ strCaption = "Unsaved changes";
				 MessageBoxButtons mbbButtons = MessageBoxButtons::YesNo;
				 System::Windows::Forms::DialogResult drResult;

				 drResult = MessageBox::Show(this,strMessage,strCaption,mbbButtons,MessageBoxIcon::Question,MessageBoxDefaultButton::Button1);
				 if (drResult == System::Windows::Forms::DialogResult::Yes)
				 {
					 //Then save
					 ((BEOPSInventory^)lbInventory->SelectedItem)->strItemName = txtbxName->Text;
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dteDateRecorded = System::Convert::ToDateTime(txtbxDateUpdated->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->strVendorName = txtbxVendor->Text;
					 ((BEOPSInventory^)lbInventory->SelectedItem)->strCategory = txtbxCategory->Text;
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblNumberInCase = System::Convert::ToDouble(txtbxUnitsInACase->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitWholesaleCost = System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitRetailValue = System::Convert::ToDouble(txtbxRetailValueOfItem->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitCount = System::Convert::ToDouble(txtbxNumberOfItems->Text);
					 
				 }
				 bDataChanged = false;
			 }
		 }
private: System::Void lbInventory_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 if (bDataChanged)
			 {
				 //Dialog to see if want to save changes
				 String^ strMessage = "There are unsaved changes to this record. Do you want to save them now?";
				 String^ strCaption = "Unsaved changes";
				 MessageBoxButtons mbbButtons = MessageBoxButtons::YesNo;
				 System::Windows::Forms::DialogResult drResult;

				 drResult = MessageBox::Show(this,strMessage,strCaption,mbbButtons,MessageBoxIcon::Question,MessageBoxDefaultButton::Button1);
				 if (drResult == System::Windows::Forms::DialogResult::Yes)
				 {
					 //Then save
					 ((BEOPSInventory^)lbInventory->SelectedItem)->strItemName = txtbxName->Text;
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dteDateRecorded = System::Convert::ToDateTime(txtbxDateUpdated->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->strVendorName = txtbxVendor->Text;
					 ((BEOPSInventory^)lbInventory->SelectedItem)->strCategory = txtbxCategory->Text;
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblNumberInCase = System::Convert::ToDouble(txtbxUnitsInACase->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitWholesaleCost = System::Convert::ToDouble(txtbxWholesaleCostOfItem->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitRetailValue = System::Convert::ToDouble(txtbxRetailValueOfItem->Text);
					 ((BEOPSInventory^)lbInventory->SelectedItem)->dblUnitCount = System::Convert::ToDouble(txtbxNumberOfItems->Text);
					 
				 }
				 bDataChanged = false;
			 }

		 }
private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //First, delete the object and save to disk
			delete((BEOPSInventory^)BEOPSGlobals::datBEOPSData->arrInventory[lbInventory->SelectedIndex]);
			int nSelectedIndex = lbInventory->SelectedIndex;
			BEOPSGlobals::datBEOPSData->arrInventory->Remove((BEOPSInventory^)lbInventory->SelectedItem);
			//I decided not to save to disk here but only in main menu
			//BEOPSGlobals::datBEOPSData->Save(BEOPSGlobals::datBEOPSData->strCurrentFileName);
			//Next, clear out and redraw the listbox
			lbInventory->Items->Clear();
			int nTemp=0;
			lbInventory->BeginUpdate();
			while (nTemp<BEOPSGlobals::datBEOPSData->arrInventory->Count)
			{
				lbInventory->Items->Add(BEOPSGlobals::datBEOPSData->arrInventory[nTemp]);
				nTemp++;
			}
			lbInventory->EndUpdate();
			//Determine which item in the list to get focus
			if (nSelectedIndex == BEOPSGlobals::datBEOPSData->arrInventory->Count) 
					lbInventory->SelectedIndex = BEOPSGlobals::datBEOPSData->arrInventory->Count-1;
			else
				lbInventory->SelectedIndex = nSelectedIndex;
			//Blank out delete and save buttons if the list is empty
			if(BEOPSGlobals::datBEOPSData->arrInventory->Count==0)
			{
				btnSave->Enabled=false;
				btnDelete->Enabled=false;
				btnNew->Focus();
				ClearAndLock();
			}
		 }
private: System::Void btnNew_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			Unlock(); //Unlocks the screen - only really needed if screen was locked
			BEOPSGlobals::datBEOPSData->arrInventory->Add(gcnew BEOPSInventory);
			lbInventory->Items->Clear();
			int nTemp=0;
			lbInventory->BeginUpdate();
			while (nTemp<BEOPSGlobals::datBEOPSData->arrInventory->Count)
			{
				lbInventory->Items->Add(BEOPSGlobals::datBEOPSData->arrInventory[nTemp]);
				nTemp++;
			}
			lbInventory->EndUpdate();
			lbInventory->SelectedIndex = BEOPSGlobals::datBEOPSData->arrInventory->LastIndexOf(BEOPSGlobals::datBEOPSData->arrInventory[nTemp-1]);
			txtbxName->Focus();
			btnDelete->Enabled=true;
			btnSave->Enabled=true;
		 }
private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->Close();
		 }

private: System::Void Double_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			 double dblTemp;
			 if(Double::TryParse(((TextBox^)sender)->Text, dblTemp))
				 ((TextBox^)sender)->Text = dblTemp.ToString("f2");
		 }
private: System::Void txtbxUnitsInACase_Enter(System::Object^  sender, System::EventArgs^  e) 
		 {
			 bJustCalculated=false;
		 }
private: System::Void txtbxNumberOfCases_Enter(System::Object^  sender, System::EventArgs^  e) {
			 bJustCalculated=false;
		 }
private: System::Void txtbxNumberOfItems_Enter(System::Object^  sender, System::EventArgs^  e) {
			 bJustCalculated=false;
		 }
private: System::Void txtbxWholesaleCostOfACase_Enter(System::Object^  sender, System::EventArgs^  e) {
			 bJustCalculated=false;
		 }
private: System::Void txtbxRetailValueOfCase_Enter(System::Object^  sender, System::EventArgs^  e) {
			 bJustCalculated=false;
		 }
private: System::Void txtbxWholesaleCostOfItem_Enter(System::Object^  sender, System::EventArgs^  e) {
			 bJustCalculated=false;
		 }
private: System::Void txtbxRetailValueOfItem_Enter(System::Object^  sender, System::EventArgs^  e) {
			 bJustCalculated=false;
		 }
};
}
