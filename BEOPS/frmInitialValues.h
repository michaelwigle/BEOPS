#ifndef FRMINITIALVALUES_H
#define FRMINITIALVALUES_H
#pragma once

#include "BEOPSGlobals.h"
namespace BEOPS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
//	using namespace BEOPS::frmMainMenu;

	/// <summary>
	/// Summary for frmInitialValues
	/// </summary>
	public ref class frmInitialValues : public System::Windows::Forms::Form
	{
	public:
		frmInitialValues(void)
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
		~frmInitialValues()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblOperatorName;
	private: System::Windows::Forms::TextBox^  txtbxOperatorName;
	private: System::Windows::Forms::Label^  lblOperatorNumber;
	private: System::Windows::Forms::TextBox^  txtbxOperatorNumber;
	private: System::Windows::Forms::Label^  lblBSVIArea;
	private: System::Windows::Forms::TextBox^  txtbxBSVIArea;
	private: System::Windows::Forms::Label^  lblOperatorAddress1;
	private: System::Windows::Forms::TextBox^  txtbxOperatorAddress1;
	private: System::Windows::Forms::Label^  lblOperatorAddress2;
	private: System::Windows::Forms::TextBox^  txtbxOperatorAddress2;
	private: System::Windows::Forms::Label^  lblOperatorCity;
	private: System::Windows::Forms::TextBox^  txtbxOperatorCity;
	private: System::Windows::Forms::Label^  lblOperatorState;
	private: System::Windows::Forms::TextBox^  txtbxOperatorState;
	private: System::Windows::Forms::Label^  lblOperatorZip;
	private: System::Windows::Forms::TextBox^  txtbxOperatorZip;
	private: System::Windows::Forms::TextBox^  txtbxStartingCash;
	private: System::Windows::Forms::Label^  lblStartingCash;
	private: System::Windows::Forms::Label^  lblAlternateInventory;
	private: System::Windows::Forms::TextBox^  txtbxAlternateInventory;
	private: System::Windows::Forms::Button^  btnSave;

	private: System::Windows::Forms::Label^  lblFacilityNumber;
	private: System::Windows::Forms::TextBox^  txtbxFacilityNumber;
	private: System::Windows::Forms::Label^  lblFacilityAddress1;
	private: System::Windows::Forms::TextBox^  txtbxFacilityAddress1;





	private: System::Windows::Forms::Label^  lblOperatorCity2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txtbxFacilityAddress2;
	private: System::Windows::Forms::Label^  lblFacilityCity;
	private: System::Windows::Forms::TextBox^  txtbxFacilityCity;





	private: System::Windows::Forms::Label^  lblOperatorZip2;
	private: System::Windows::Forms::Label^  lblFacilityState;
	private: System::Windows::Forms::TextBox^  txtbxFacilityState;
	private: System::Windows::Forms::Label^  lblFacilityZip;
	private: System::Windows::Forms::TextBox^  txtbxFacilityZip;



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
			this->lblOperatorName = (gcnew System::Windows::Forms::Label());
			this->txtbxOperatorName = (gcnew System::Windows::Forms::TextBox());
			this->lblOperatorNumber = (gcnew System::Windows::Forms::Label());
			this->txtbxOperatorNumber = (gcnew System::Windows::Forms::TextBox());
			this->lblBSVIArea = (gcnew System::Windows::Forms::Label());
			this->txtbxBSVIArea = (gcnew System::Windows::Forms::TextBox());
			this->lblOperatorAddress1 = (gcnew System::Windows::Forms::Label());
			this->txtbxOperatorAddress1 = (gcnew System::Windows::Forms::TextBox());
			this->lblOperatorAddress2 = (gcnew System::Windows::Forms::Label());
			this->txtbxOperatorAddress2 = (gcnew System::Windows::Forms::TextBox());
			this->lblOperatorCity = (gcnew System::Windows::Forms::Label());
			this->txtbxOperatorCity = (gcnew System::Windows::Forms::TextBox());
			this->lblOperatorState = (gcnew System::Windows::Forms::Label());
			this->txtbxOperatorState = (gcnew System::Windows::Forms::TextBox());
			this->lblOperatorZip = (gcnew System::Windows::Forms::Label());
			this->txtbxOperatorZip = (gcnew System::Windows::Forms::TextBox());
			this->txtbxStartingCash = (gcnew System::Windows::Forms::TextBox());
			this->lblStartingCash = (gcnew System::Windows::Forms::Label());
			this->lblAlternateInventory = (gcnew System::Windows::Forms::Label());
			this->txtbxAlternateInventory = (gcnew System::Windows::Forms::TextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->lblFacilityNumber = (gcnew System::Windows::Forms::Label());
			this->txtbxFacilityNumber = (gcnew System::Windows::Forms::TextBox());
			this->lblFacilityAddress1 = (gcnew System::Windows::Forms::Label());
			this->txtbxFacilityAddress1 = (gcnew System::Windows::Forms::TextBox());
			this->lblOperatorCity2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtbxFacilityAddress2 = (gcnew System::Windows::Forms::TextBox());
			this->lblFacilityCity = (gcnew System::Windows::Forms::Label());
			this->txtbxFacilityCity = (gcnew System::Windows::Forms::TextBox());
			this->lblOperatorZip2 = (gcnew System::Windows::Forms::Label());
			this->lblFacilityState = (gcnew System::Windows::Forms::Label());
			this->txtbxFacilityState = (gcnew System::Windows::Forms::TextBox());
			this->lblFacilityZip = (gcnew System::Windows::Forms::Label());
			this->txtbxFacilityZip = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// lblOperatorName
			// 
			this->lblOperatorName->AccessibleDescription = L"Label";
			this->lblOperatorName->AccessibleName = L"Operator Name";
			this->lblOperatorName->AutoSize = true;
			this->lblOperatorName->Location = System::Drawing::Point(12, 16);
			this->lblOperatorName->Name = L"lblOperatorName";
			this->lblOperatorName->Size = System::Drawing::Size(79, 13);
			this->lblOperatorName->TabIndex = 0;
			this->lblOperatorName->Text = L"Operator Name";
			// 
			// txtbxOperatorName
			// 
			this->txtbxOperatorName->AccessibleDescription = L"Edit";
			this->txtbxOperatorName->AccessibleName = L"Operator Name";
			this->txtbxOperatorName->Location = System::Drawing::Point(132, 13);
			this->txtbxOperatorName->Name = L"txtbxOperatorName";
			this->txtbxOperatorName->Size = System::Drawing::Size(190, 20);
			this->txtbxOperatorName->TabIndex = 1;
			// 
			// lblOperatorNumber
			// 
			this->lblOperatorNumber->AccessibleName = L"Operator Number";
			this->lblOperatorNumber->AutoSize = true;
			this->lblOperatorNumber->Location = System::Drawing::Point(12, 41);
			this->lblOperatorNumber->Name = L"lblOperatorNumber";
			this->lblOperatorNumber->Size = System::Drawing::Size(88, 13);
			this->lblOperatorNumber->TabIndex = 2;
			this->lblOperatorNumber->Text = L"Operator Number";
			// 
			// txtbxOperatorNumber
			// 
			this->txtbxOperatorNumber->AccessibleName = L"Operator Number";
			this->txtbxOperatorNumber->Location = System::Drawing::Point(132, 38);
			this->txtbxOperatorNumber->Name = L"txtbxOperatorNumber";
			this->txtbxOperatorNumber->Size = System::Drawing::Size(190, 20);
			this->txtbxOperatorNumber->TabIndex = 3;
			// 
			// lblBSVIArea
			// 
			this->lblBSVIArea->AccessibleName = L"BSVI Area";
			this->lblBSVIArea->AutoSize = true;
			this->lblBSVIArea->Location = System::Drawing::Point(328, 16);
			this->lblBSVIArea->Name = L"lblBSVIArea";
			this->lblBSVIArea->Size = System::Drawing::Size(56, 13);
			this->lblBSVIArea->TabIndex = 16;
			this->lblBSVIArea->Text = L"BSVI Area";
			// 
			// txtbxBSVIArea
			// 
			this->txtbxBSVIArea->AccessibleName = L"BSVI Area";
			this->txtbxBSVIArea->Location = System::Drawing::Point(448, 13);
			this->txtbxBSVIArea->Name = L"txtbxBSVIArea";
			this->txtbxBSVIArea->Size = System::Drawing::Size(191, 20);
			this->txtbxBSVIArea->TabIndex = 17;
			// 
			// lblOperatorAddress1
			// 
			this->lblOperatorAddress1->AccessibleName = L"Operator Address 1";
			this->lblOperatorAddress1->AutoSize = true;
			this->lblOperatorAddress1->Location = System::Drawing::Point(12, 67);
			this->lblOperatorAddress1->Name = L"lblOperatorAddress1";
			this->lblOperatorAddress1->Size = System::Drawing::Size(98, 13);
			this->lblOperatorAddress1->TabIndex = 4;
			this->lblOperatorAddress1->Text = L"Operator Address 1";
			// 
			// txtbxOperatorAddress1
			// 
			this->txtbxOperatorAddress1->AccessibleName = L"Operator Address 1";
			this->txtbxOperatorAddress1->Location = System::Drawing::Point(132, 64);
			this->txtbxOperatorAddress1->Name = L"txtbxOperatorAddress1";
			this->txtbxOperatorAddress1->Size = System::Drawing::Size(190, 20);
			this->txtbxOperatorAddress1->TabIndex = 5;
			// 
			// lblOperatorAddress2
			// 
			this->lblOperatorAddress2->AccessibleName = L"Operator Address 2";
			this->lblOperatorAddress2->AutoSize = true;
			this->lblOperatorAddress2->Location = System::Drawing::Point(12, 98);
			this->lblOperatorAddress2->Name = L"lblOperatorAddress2";
			this->lblOperatorAddress2->Size = System::Drawing::Size(98, 13);
			this->lblOperatorAddress2->TabIndex = 6;
			this->lblOperatorAddress2->Text = L"Operator Address 2";
			// 
			// txtbxOperatorAddress2
			// 
			this->txtbxOperatorAddress2->AccessibleName = L"Operator Address 2";
			this->txtbxOperatorAddress2->Location = System::Drawing::Point(132, 91);
			this->txtbxOperatorAddress2->Name = L"txtbxOperatorAddress2";
			this->txtbxOperatorAddress2->Size = System::Drawing::Size(190, 20);
			this->txtbxOperatorAddress2->TabIndex = 7;
			// 
			// lblOperatorCity
			// 
			this->lblOperatorCity->AccessibleName = L"Operator City";
			this->lblOperatorCity->AutoSize = true;
			this->lblOperatorCity->Location = System::Drawing::Point(12, 146);
			this->lblOperatorCity->Name = L"lblOperatorCity";
			this->lblOperatorCity->Size = System::Drawing::Size(68, 13);
			this->lblOperatorCity->TabIndex = 10;
			this->lblOperatorCity->Text = L"Operator City";
			// 
			// txtbxOperatorCity
			// 
			this->txtbxOperatorCity->AccessibleName = L"Operator City";
			this->txtbxOperatorCity->Location = System::Drawing::Point(132, 120);
			this->txtbxOperatorCity->Name = L"txtbxOperatorCity";
			this->txtbxOperatorCity->Size = System::Drawing::Size(190, 20);
			this->txtbxOperatorCity->TabIndex = 9;
			// 
			// lblOperatorState
			// 
			this->lblOperatorState->AccessibleName = L"Operator State";
			this->lblOperatorState->AutoSize = true;
			this->lblOperatorState->Location = System::Drawing::Point(12, 146);
			this->lblOperatorState->Name = L"lblOperatorState";
			this->lblOperatorState->Size = System::Drawing::Size(76, 13);
			this->lblOperatorState->TabIndex = 10;
			this->lblOperatorState->Text = L"Operator State";
			// 
			// txtbxOperatorState
			// 
			this->txtbxOperatorState->AccessibleName = L"Operator State";
			this->txtbxOperatorState->Location = System::Drawing::Point(132, 146);
			this->txtbxOperatorState->Name = L"txtbxOperatorState";
			this->txtbxOperatorState->Size = System::Drawing::Size(190, 20);
			this->txtbxOperatorState->TabIndex = 11;
			// 
			// lblOperatorZip
			// 
			this->lblOperatorZip->AccessibleName = L"Operator Zip";
			this->lblOperatorZip->AutoSize = true;
			this->lblOperatorZip->Location = System::Drawing::Point(12, 200);
			this->lblOperatorZip->Name = L"lblOperatorZip";
			this->lblOperatorZip->Size = System::Drawing::Size(66, 13);
			this->lblOperatorZip->TabIndex = 14;
			this->lblOperatorZip->Text = L"Operator Zip";
			// 
			// txtbxOperatorZip
			// 
			this->txtbxOperatorZip->AccessibleName = L"Operator Zip";
			this->txtbxOperatorZip->Location = System::Drawing::Point(132, 174);
			this->txtbxOperatorZip->Name = L"txtbxOperatorZip";
			this->txtbxOperatorZip->Size = System::Drawing::Size(190, 20);
			this->txtbxOperatorZip->TabIndex = 13;
			// 
			// txtbxStartingCash
			// 
			this->txtbxStartingCash->AccessibleDescription = L"Starting Cash";
			this->txtbxStartingCash->AccessibleName = L"Starting Cash";
			this->txtbxStartingCash->Location = System::Drawing::Point(132, 201);
			this->txtbxStartingCash->Name = L"txtbxStartingCash";
			this->txtbxStartingCash->Size = System::Drawing::Size(190, 20);
			this->txtbxStartingCash->TabIndex = 15;
			this->txtbxStartingCash->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmInitialValues::txtbxStartingCash_Validating);
			// 
			// lblStartingCash
			// 
			this->lblStartingCash->AccessibleDescription = L"Starting Cash";
			this->lblStartingCash->AccessibleName = L"Starting Cash";
			this->lblStartingCash->AutoSize = true;
			this->lblStartingCash->Location = System::Drawing::Point(13, 201);
			this->lblStartingCash->Name = L"lblStartingCash";
			this->lblStartingCash->Size = System::Drawing::Size(70, 13);
			this->lblStartingCash->TabIndex = 14;
			this->lblStartingCash->Text = L"Starting Cash";
			// 
			// lblAlternateInventory
			// 
			this->lblAlternateInventory->AccessibleDescription = L"Alternate Inventory";
			this->lblAlternateInventory->AccessibleName = L"Alternate Inventory";
			this->lblAlternateInventory->AutoSize = true;
			this->lblAlternateInventory->Location = System::Drawing::Point(328, 204);
			this->lblAlternateInventory->Name = L"lblAlternateInventory";
			this->lblAlternateInventory->Size = System::Drawing::Size(78, 13);
			this->lblAlternateInventory->TabIndex = 30;
			this->lblAlternateInventory->Text = L"Initial Inventory";
			// 
			// txtbxAlternateInventory
			// 
			this->txtbxAlternateInventory->AccessibleDescription = L"Alternate Inventory";
			this->txtbxAlternateInventory->AccessibleName = L"Alternate Inventory";
			this->txtbxAlternateInventory->Location = System::Drawing::Point(448, 201);
			this->txtbxAlternateInventory->Name = L"txtbxAlternateInventory";
			this->txtbxAlternateInventory->Size = System::Drawing::Size(191, 20);
			this->txtbxAlternateInventory->TabIndex = 31;
			this->txtbxAlternateInventory->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &frmInitialValues::txtbxStartingCash_Validating);
			// 
			// btnSave
			// 
			this->btnSave->AccessibleDescription = L"Close";
			this->btnSave->AccessibleName = L"Close";
			this->btnSave->Location = System::Drawing::Point(281, 252);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(75, 23);
			this->btnSave->TabIndex = 32;
			this->btnSave->Text = L"&Close";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmInitialValues::btnSave_Click);
			// 
			// lblFacilityNumber
			// 
			this->lblFacilityNumber->AutoSize = true;
			this->lblFacilityNumber->Location = System::Drawing::Point(328, 41);
			this->lblFacilityNumber->Name = L"lblFacilityNumber";
			this->lblFacilityNumber->Size = System::Drawing::Size(79, 13);
			this->lblFacilityNumber->TabIndex = 18;
			this->lblFacilityNumber->Text = L"Facility Number";
			// 
			// txtbxFacilityNumber
			// 
			this->txtbxFacilityNumber->Location = System::Drawing::Point(448, 41);
			this->txtbxFacilityNumber->Name = L"txtbxFacilityNumber";
			this->txtbxFacilityNumber->Size = System::Drawing::Size(191, 20);
			this->txtbxFacilityNumber->TabIndex = 19;
			// 
			// lblFacilityAddress1
			// 
			this->lblFacilityAddress1->AutoSize = true;
			this->lblFacilityAddress1->Location = System::Drawing::Point(328, 67);
			this->lblFacilityAddress1->Name = L"lblFacilityAddress1";
			this->lblFacilityAddress1->Size = System::Drawing::Size(89, 13);
			this->lblFacilityAddress1->TabIndex = 20;
			this->lblFacilityAddress1->Text = L"Facility Address 1";
			// 
			// txtbxFacilityAddress1
			// 
			this->txtbxFacilityAddress1->Location = System::Drawing::Point(448, 67);
			this->txtbxFacilityAddress1->Name = L"txtbxFacilityAddress1";
			this->txtbxFacilityAddress1->Size = System::Drawing::Size(191, 20);
			this->txtbxFacilityAddress1->TabIndex = 21;
			// 
			// lblOperatorCity2
			// 
			this->lblOperatorCity2->AutoSize = true;
			this->lblOperatorCity2->Location = System::Drawing::Point(15, 120);
			this->lblOperatorCity2->Name = L"lblOperatorCity2";
			this->lblOperatorCity2->Size = System::Drawing::Size(68, 13);
			this->lblOperatorCity2->TabIndex = 8;
			this->lblOperatorCity2->Text = L"Operator City";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(328, 98);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Facility Address 2";
			// 
			// txtbxFacilityAddress2
			// 
			this->txtbxFacilityAddress2->Location = System::Drawing::Point(448, 91);
			this->txtbxFacilityAddress2->Name = L"txtbxFacilityAddress2";
			this->txtbxFacilityAddress2->Size = System::Drawing::Size(191, 20);
			this->txtbxFacilityAddress2->TabIndex = 23;
			// 
			// lblFacilityCity
			// 
			this->lblFacilityCity->AutoSize = true;
			this->lblFacilityCity->Location = System::Drawing::Point(328, 121);
			this->lblFacilityCity->Name = L"lblFacilityCity";
			this->lblFacilityCity->Size = System::Drawing::Size(59, 13);
			this->lblFacilityCity->TabIndex = 24;
			this->lblFacilityCity->Text = L"Facility City";
			// 
			// txtbxFacilityCity
			// 
			this->txtbxFacilityCity->Location = System::Drawing::Point(448, 120);
			this->txtbxFacilityCity->Name = L"txtbxFacilityCity";
			this->txtbxFacilityCity->Size = System::Drawing::Size(191, 20);
			this->txtbxFacilityCity->TabIndex = 25;
			// 
			// lblOperatorZip2
			// 
			this->lblOperatorZip2->AutoSize = true;
			this->lblOperatorZip2->Location = System::Drawing::Point(15, 174);
			this->lblOperatorZip2->Name = L"lblOperatorZip2";
			this->lblOperatorZip2->Size = System::Drawing::Size(66, 13);
			this->lblOperatorZip2->TabIndex = 12;
			this->lblOperatorZip2->Text = L"Operator Zip";
			// 
			// lblFacilityState
			// 
			this->lblFacilityState->AutoSize = true;
			this->lblFacilityState->Location = System::Drawing::Point(328, 146);
			this->lblFacilityState->Name = L"lblFacilityState";
			this->lblFacilityState->Size = System::Drawing::Size(67, 13);
			this->lblFacilityState->TabIndex = 26;
			this->lblFacilityState->Text = L"Facility State";
			// 
			// txtbxFacilityState
			// 
			this->txtbxFacilityState->Location = System::Drawing::Point(448, 146);
			this->txtbxFacilityState->Name = L"txtbxFacilityState";
			this->txtbxFacilityState->Size = System::Drawing::Size(191, 20);
			this->txtbxFacilityState->TabIndex = 27;
			// 
			// lblFacilityZip
			// 
			this->lblFacilityZip->AutoSize = true;
			this->lblFacilityZip->Location = System::Drawing::Point(328, 174);
			this->lblFacilityZip->Name = L"lblFacilityZip";
			this->lblFacilityZip->Size = System::Drawing::Size(57, 13);
			this->lblFacilityZip->TabIndex = 28;
			this->lblFacilityZip->Text = L"Facility Zip";
			// 
			// txtbxFacilityZip
			// 
			this->txtbxFacilityZip->Location = System::Drawing::Point(448, 174);
			this->txtbxFacilityZip->Name = L"txtbxFacilityZip";
			this->txtbxFacilityZip->Size = System::Drawing::Size(191, 20);
			this->txtbxFacilityZip->TabIndex = 29;
			// 
			// frmInitialValues
			// 
			this->AccessibleDescription = L"Initial Values";
			this->AccessibleName = L"Initial Values";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 287);
			this->Controls->Add(this->txtbxFacilityZip);
			this->Controls->Add(this->lblFacilityZip);
			this->Controls->Add(this->txtbxFacilityState);
			this->Controls->Add(this->lblFacilityState);
			this->Controls->Add(this->lblOperatorZip2);
			this->Controls->Add(this->txtbxFacilityCity);
			this->Controls->Add(this->lblFacilityCity);
			this->Controls->Add(this->txtbxFacilityAddress2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblOperatorCity2);
			this->Controls->Add(this->txtbxFacilityAddress1);
			this->Controls->Add(this->lblFacilityAddress1);
			this->Controls->Add(this->txtbxFacilityNumber);
			this->Controls->Add(this->lblFacilityNumber);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtbxAlternateInventory);
			this->Controls->Add(this->lblAlternateInventory);
			this->Controls->Add(this->lblStartingCash);
			this->Controls->Add(this->txtbxStartingCash);
			this->Controls->Add(this->txtbxOperatorZip);
			this->Controls->Add(this->lblOperatorZip);
			this->Controls->Add(this->txtbxOperatorState);
			this->Controls->Add(this->lblOperatorState);
			this->Controls->Add(this->txtbxOperatorCity);
			this->Controls->Add(this->lblOperatorCity);
			this->Controls->Add(this->txtbxOperatorAddress2);
			this->Controls->Add(this->lblOperatorAddress2);
			this->Controls->Add(this->txtbxOperatorAddress1);
			this->Controls->Add(this->lblOperatorAddress1);
			this->Controls->Add(this->txtbxBSVIArea);
			this->Controls->Add(this->lblBSVIArea);
			this->Controls->Add(this->txtbxOperatorNumber);
			this->Controls->Add(this->lblOperatorNumber);
			this->Controls->Add(this->txtbxOperatorName);
			this->Controls->Add(this->lblOperatorName);
			this->Name = L"frmInitialValues";
			this->Text = L"Initial Values - BEOPS";
			this->Load += gcnew System::EventHandler(this, &frmInitialValues::frmInitialValues_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmInitialValues_Load(System::Object^  sender, System::EventArgs^  e) {
				 txtbxOperatorName->Text = BEOPSGlobals::datBEOPSData->strOperatorName;
				 txtbxOperatorNumber->Text = BEOPSGlobals::datBEOPSData->strOperatorNumber;
				 txtbxBSVIArea->Text = BEOPSGlobals::datBEOPSData->strBSVIArea;
				 txtbxOperatorAddress1->Text = BEOPSGlobals::datBEOPSData->strOperatorAddress1;
				 txtbxOperatorAddress2->Text = BEOPSGlobals::datBEOPSData->strOperatorAddress2;
				 txtbxOperatorCity->Text = BEOPSGlobals::datBEOPSData->strOperatorCity;
				 txtbxOperatorState->Text = BEOPSGlobals::datBEOPSData->strOperatorState;
				 txtbxOperatorZip->Text = BEOPSGlobals::datBEOPSData->strOperatorZip;
				 txtbxStartingCash->Text = BEOPSGlobals::datBEOPSData->dblStartCash.ToString("f2");
				 txtbxAlternateInventory->Text = BEOPSGlobals::datBEOPSData->dblAlternateInventory.ToString("f2");
				 txtbxFacilityNumber->Text = BEOPSGlobals::datBEOPSData->strFacilityNumber;
				 txtbxFacilityAddress1->Text = BEOPSGlobals::datBEOPSData->strFacilityAddress1;
				 txtbxFacilityAddress2->Text = BEOPSGlobals::datBEOPSData->strFacilityAddress2;
				 txtbxFacilityCity->Text = BEOPSGlobals::datBEOPSData->strFacilityCity;
				 txtbxFacilityState->Text = BEOPSGlobals::datBEOPSData->strFacilityState;
				 txtbxFacilityZip->Text = BEOPSGlobals::datBEOPSData->strFacilityZip;

			 }

private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 BEOPSGlobals::datBEOPSData->strOperatorName = txtbxOperatorName->Text;
			 BEOPSGlobals::datBEOPSData->strOperatorNumber = txtbxOperatorNumber->Text;
			 BEOPSGlobals::datBEOPSData->strBSVIArea = txtbxBSVIArea->Text;
			 BEOPSGlobals::datBEOPSData->strOperatorAddress1 = txtbxOperatorAddress1->Text;
			 BEOPSGlobals::datBEOPSData->strOperatorAddress2 = txtbxOperatorAddress2->Text;
			 BEOPSGlobals::datBEOPSData->strOperatorCity = txtbxOperatorCity->Text;
			 BEOPSGlobals::datBEOPSData->strOperatorState = txtbxOperatorState->Text;
			 BEOPSGlobals::datBEOPSData->strOperatorZip = txtbxOperatorZip->Text;
			 BEOPSGlobals::datBEOPSData->dblStartCash = System::Convert::ToDouble(txtbxStartingCash->Text);
			 BEOPSGlobals::datBEOPSData->dblAlternateInventory = System::Convert::ToDouble(txtbxAlternateInventory->Text);
			 BEOPSGlobals::datBEOPSData->strFacilityNumber = txtbxFacilityNumber->Text;
			 BEOPSGlobals::datBEOPSData->strFacilityAddress1 = txtbxFacilityAddress1->Text;
			 BEOPSGlobals::datBEOPSData->strFacilityAddress2 = txtbxFacilityAddress2->Text;
			 BEOPSGlobals::datBEOPSData->strFacilityCity = txtbxFacilityCity->Text;
			 BEOPSGlobals::datBEOPSData->strFacilityState = txtbxFacilityState->Text;
			 BEOPSGlobals::datBEOPSData->strFacilityZip = txtbxFacilityZip->Text;
			 //BEOPSGlobals::datBEOPSData->Save(BEOPSGlobals::datBEOPSData->strCurrentFileName);
			 this->Close();
		 }
private: System::Void txtbxStartingCash_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			 double dblTemp;
			 if(((TextBox^)sender)->Text != "")
				if(Double::TryParse(((TextBox^)sender)->Text,dblTemp))
					 ((TextBox^)sender)->Text = dblTemp.ToString("f2");
				else
					e->Cancel = true;
			 else
				 ((TextBox^)sender)->Text = "0";
		 }
};
}
#endif