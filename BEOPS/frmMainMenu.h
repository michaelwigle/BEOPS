#pragma once
#include "frmReports.h"
#include "frmInitialValues.h"
#include "BEOPSGlobals.h"
#include "frmInventory.h"
#include "frmDaily.h"

namespace BEOPS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	

	
	/// <summary>
	/// Summary for MainMenu
	/// </summary>
	public ref class frmMainMenu : public System::Windows::Forms::Form
	{
	public:
		OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuImport;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuSave;
	private: System::Windows::Forms::Button^  btnInventory;
	private: System::Windows::Forms::Button^  btnDaily;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuNew;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuClose;
	public: 
		//InitialValues^ datInitialValues;
	private: System::Windows::Forms::Button^  btnInitialValues;
	public: 
		
		frmMainMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//Don't do this here. Do it in New and Open and Import
			//BEOPSGlobals::datBEOPSData = gcnew BEOPSData;

		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMainMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::Button^  btnReports;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFile;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuOpen;





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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMainMenu::typeid));
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnReports = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mnuFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuNew = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuImport = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnInitialValues = (gcnew System::Windows::Forms::Button());
			this->btnInventory = (gcnew System::Windows::Forms::Button());
			this->btnDaily = (gcnew System::Windows::Forms::Button());
			this->mnuClose = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnExit
			// 
			this->btnExit->AccessibleDescription = L"Exit";
			this->btnExit->AccessibleName = L"Exit";
			this->btnExit->Location = System::Drawing::Point(337, 27);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 5;
			this->btnExit->Text = L"E&xit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &frmMainMenu::btnExit_Click);
			// 
			// btnReports
			// 
			this->btnReports->AccessibleDescription = L"Reports";
			this->btnReports->AccessibleName = L"Reports";
			this->btnReports->Location = System::Drawing::Point(256, 27);
			this->btnReports->Name = L"btnReports";
			this->btnReports->Size = System::Drawing::Size(75, 23);
			this->btnReports->TabIndex = 4;
			this->btnReports->Text = L"&Reports";
			this->btnReports->UseVisualStyleBackColor = true;
			this->btnReports->Click += gcnew System::EventHandler(this, &frmMainMenu::btnReports_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->mnuFile});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(428, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mnuFile
			// 
			this->mnuFile->AccessibleDescription = L"File Menu";
			this->mnuFile->AccessibleName = L"File Menu";
			this->mnuFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->mnuNew, this->mnuOpen, 
				this->mnuSave, this->mnuImport, this->mnuClose});
			this->mnuFile->Name = L"mnuFile";
			this->mnuFile->Size = System::Drawing::Size(37, 20);
			this->mnuFile->Text = L"File";
			// 
			// mnuNew
			// 
			this->mnuNew->Name = L"mnuNew";
			this->mnuNew->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->mnuNew->Size = System::Drawing::Size(152, 22);
			this->mnuNew->Text = L"&New";
			this->mnuNew->Click += gcnew System::EventHandler(this, &frmMainMenu::mnuNew_Click);
			// 
			// mnuOpen
			// 
			this->mnuOpen->AccessibleDescription = L"Open";
			this->mnuOpen->AccessibleName = L"Open";
			this->mnuOpen->Name = L"mnuOpen";
			this->mnuOpen->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->mnuOpen->Size = System::Drawing::Size(152, 22);
			this->mnuOpen->Text = L"&Open";
			this->mnuOpen->Click += gcnew System::EventHandler(this, &frmMainMenu::mnuOpen_Click);
			// 
			// mnuSave
			// 
			this->mnuSave->AccessibleDescription = L"Save";
			this->mnuSave->AccessibleName = L"Save";
			this->mnuSave->Name = L"mnuSave";
			this->mnuSave->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->mnuSave->Size = System::Drawing::Size(152, 22);
			this->mnuSave->Text = L"&Save";
			this->mnuSave->Click += gcnew System::EventHandler(this, &frmMainMenu::mnuSave_Click);
			// 
			// mnuImport
			// 
			this->mnuImport->Name = L"mnuImport";
			this->mnuImport->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::I));
			this->mnuImport->Size = System::Drawing::Size(152, 22);
			this->mnuImport->Text = L"&Import";
			this->mnuImport->Click += gcnew System::EventHandler(this, &frmMainMenu::mnuImport_OnClick);
			// 
			// btnInitialValues
			// 
			this->btnInitialValues->AccessibleDescription = L"Initial Values";
			this->btnInitialValues->AccessibleName = L"Initial Values";
			this->btnInitialValues->Location = System::Drawing::Point(12, 27);
			this->btnInitialValues->Name = L"btnInitialValues";
			this->btnInitialValues->Size = System::Drawing::Size(75, 23);
			this->btnInitialValues->TabIndex = 1;
			this->btnInitialValues->Text = L"&Initial Values";
			this->btnInitialValues->UseVisualStyleBackColor = true;
			this->btnInitialValues->Click += gcnew System::EventHandler(this, &frmMainMenu::btnInitialValues_Click);
			// 
			// btnInventory
			// 
			this->btnInventory->AccessibleDescription = L"Inventory";
			this->btnInventory->AccessibleName = L"Inventory";
			this->btnInventory->Location = System::Drawing::Point(175, 27);
			this->btnInventory->Name = L"btnInventory";
			this->btnInventory->Size = System::Drawing::Size(75, 23);
			this->btnInventory->TabIndex = 3;
			this->btnInventory->Text = L"I&nventory";
			this->btnInventory->UseVisualStyleBackColor = true;
			this->btnInventory->Click += gcnew System::EventHandler(this, &frmMainMenu::btnInventory_Click);
			// 
			// btnDaily
			// 
			this->btnDaily->Location = System::Drawing::Point(94, 27);
			this->btnDaily->Name = L"btnDaily";
			this->btnDaily->Size = System::Drawing::Size(75, 23);
			this->btnDaily->TabIndex = 2;
			this->btnDaily->Text = L"&Daily";
			this->btnDaily->UseVisualStyleBackColor = true;
			this->btnDaily->Click += gcnew System::EventHandler(this, &frmMainMenu::btnDaily_Click);
			// 
			// mnuClose
			// 
			this->mnuClose->Name = L"mnuClose";
			this->mnuClose->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->mnuClose->Size = System::Drawing::Size(152, 22);
			this->mnuClose->Text = L"&Close";
			this->mnuClose->Click += gcnew System::EventHandler(this, &frmMainMenu::mnuClose_Click);
			// 
			// frmMainMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 61);
			this->Controls->Add(this->btnDaily);
			this->Controls->Add(this->btnInventory);
			this->Controls->Add(this->btnInitialValues);
			this->Controls->Add(this->btnReports);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"frmMainMenu";
			this->Text = L"Main Menu - BEOPS 5.0";
			this->Activated += gcnew System::EventHandler(this, &frmMainMenu::frmMainMenu_Activated);
			this->Load += gcnew System::EventHandler(this, &frmMainMenu::frmMainMenu_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmMainMenu_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(BEOPSGlobals::datBEOPSData == nullptr)
				 {
					 btnInventory->Enabled = false;
					 btnInitialValues->Enabled = false;
					 btnReports->Enabled = false;
					 btnDaily->Enabled = false;
					 mnuSave->Enabled = false;
				 }
				 else
				 {
					 btnInventory->Enabled = true;
					 btnInitialValues->Enabled = true;
					 btnReports->Enabled = true;
					 btnDaily->Enabled = true;
					 mnuSave->Enabled = true;

				 }
			 }
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
			 
				 if(BEOPSGlobals::datBEOPSData!= nullptr)
				 {
					 if(BEOPSGlobals::datBEOPSData->strCurrentFileName!="")
					 {
						 BEOPSGlobals::datBEOPSData->Save(BEOPSGlobals::datBEOPSData->strCurrentFileName);
					 }
				 }
				 Application::Exit();
			 }
	private: System::Void btnReports_Click(System::Object^  sender, System::EventArgs^  e) {
				 frmReports^ dlgReports = gcnew frmReports();
				 dlgReports->ShowDialog();
			 }
	private: System::Void mnuOpen_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 BEOPSGlobals::datBEOPSData = gcnew BEOPSData();
				//These line are for choosing a single file
				OpenFileDialog^ dlgOpen = gcnew OpenFileDialog;
				dlgOpen->InitialDirectory = Environment::GetFolderPath( Environment::SpecialFolder::Personal);
				dlgOpen->Filter = "BEOPS Files (.bo)|*.bo|All Files (*.*)|*.*";
				dlgOpen->FilterIndex = 1;
				dlgOpen->RestoreDirectory = true;

				
				if ( dlgOpen->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				{
					//InitialValues objInitialValues;
					BEOPSGlobals::datBEOPSData->Load(dlgOpen->FileName);
					BEOPSGlobals::datBEOPSData->strCurrentFileName = dlgOpen->FileName;
					this->Text = L"Main Menu - Facility " + BEOPSGlobals::datBEOPSData->strFacilityNumber + " - BEOPS 5.0";
					btnInventory->Enabled = true;
					btnInitialValues->Enabled = true;
					btnReports->Enabled = true;
					btnDaily->Enabled = true;
					mnuOpen->Enabled = false;
					mnuImport->Enabled = false;
					mnuSave->Enabled = true;
				}
				
			 }
private: System::Void dlgFolderBrowser_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnInitialValues_Click(System::Object^  sender, System::EventArgs^  e) {
			 frmInitialValues^ dlgInitialValues = gcnew frmInitialValues();
			 dlgInitialValues->ShowDialog();
		 }
private: System::Void mnuImport_OnClick(System::Object^  sender, System::EventArgs^  e) {
			 BEOPSGlobals::datBEOPSData = gcnew BEOPSData();
			 if(BEOPSGlobals::datBEOPSData->Import())
			 {
				 SaveFileDialog^ dlgSaveFile= gcnew SaveFileDialog;
				 dlgSaveFile->CheckPathExists = true;
				 dlgSaveFile->CreatePrompt = true;
				 dlgSaveFile->Filter = "BEOPS Files (*.bo)|*.bo";
				 dlgSaveFile->DefaultExt = "*.bo";
				 dlgSaveFile->InitialDirectory = Environment::GetFolderPath( Environment::SpecialFolder::Personal);
				 if (dlgSaveFile->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 BEOPSGlobals::datBEOPSData->Save(dlgSaveFile->FileName);
					 BEOPSGlobals::datBEOPSData->strCurrentFileName = dlgSaveFile->FileName;
					 this->Text = L"Main Menu - Facility " + BEOPSGlobals::datBEOPSData->strFacilityNumber + " - BEOPS 5.0";
					 btnInventory->Enabled = true;
					 btnInitialValues->Enabled = true;
					 btnReports->Enabled = true;
					 btnDaily->Enabled = true;
					 mnuOpen->Enabled = false;
					 mnuImport->Enabled = false;
				 }
			 }
			 else
				 delete BEOPSGlobals::datBEOPSData;
		 }
private: System::Void mnuSave_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(BEOPSGlobals::datBEOPSData->strCurrentFileName!="")
			 {
				 BEOPSGlobals::datBEOPSData->Save(BEOPSGlobals::datBEOPSData->strCurrentFileName);
			 }
			 else
			 {
				 SaveFileDialog^ dlgSaveFile= gcnew SaveFileDialog;
				 dlgSaveFile->CheckPathExists = true;
				 dlgSaveFile->CreatePrompt = true;
				 dlgSaveFile->Filter = "BEOPS Files (*.bo)|*.bo";
				 dlgSaveFile->DefaultExt = "*.bo";
				 dlgSaveFile->InitialDirectory = Environment::GetFolderPath( Environment::SpecialFolder::Personal);
				 if (dlgSaveFile->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 BEOPSGlobals::datBEOPSData->Save(dlgSaveFile->FileName);
					 BEOPSGlobals::datBEOPSData->strCurrentFileName = dlgSaveFile->FileName;
				 }
			 }
		 }
private: System::Void btnInventory_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 frmInventory^ dlgInventory = gcnew frmInventory();
			 dlgInventory->ShowDialog();
		 }
private: System::Void btnDaily_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 frmDaily^ dlgDaily = gcnew frmDaily();
			 dlgDaily->ShowDialog();
		 }
private: System::Void mnuNew_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
			 //Code from mnuSave
			 SaveFileDialog^ dlgSaveFile= gcnew SaveFileDialog;
			 dlgSaveFile->CheckPathExists = true;
			 dlgSaveFile->CreatePrompt = true;
			 dlgSaveFile->Filter = "BEOPS Files (*.bo)|*.bo";
			 dlgSaveFile->DefaultExt = L"*.bo";
			 dlgSaveFile->InitialDirectory = Environment::GetFolderPath( Environment::SpecialFolder::Personal);
			 if (dlgSaveFile->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			 {
				 BEOPSGlobals::datBEOPSData = gcnew BEOPSData;
				 BEOPSGlobals::datBEOPSData->Save(dlgSaveFile->FileName);
				 BEOPSGlobals::datBEOPSData->strCurrentFileName = dlgSaveFile->FileName;
				 //Code from mnuOpen
				 BEOPSGlobals::datBEOPSData->Load(dlgSaveFile->FileName);
				 BEOPSGlobals::datBEOPSData->strCurrentFileName = dlgSaveFile->FileName;
				 this->Text = L"Main Menu - Facility " + BEOPSGlobals::datBEOPSData->strFacilityNumber + " - BEOPS 5.0";
				 btnInventory->Enabled = true;
				 btnInitialValues->Enabled = true;
				 btnReports->Enabled = true;
				 btnDaily->Enabled = true;

			 }

		 }

private: System::Void frmMainMenu_Activated(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(BEOPSGlobals::datBEOPSData == nullptr)
				 this->Text = L"Main Menu - BEOPS 5.0";
			 else
			 {
				 if(BEOPSGlobals::datBEOPSData->strFacilityNumber=="")
					this->Text = L"Main Menu - BEOPS 5.0";
				 else
					 this->Text = L"Main Menu - Facility " + BEOPSGlobals::datBEOPSData->strFacilityNumber + " - BEOPS 5.0";
			 }
		 }
private: System::Void mnuClose_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(BEOPSGlobals::datBEOPSData->strCurrentFileName!="")
			 {
				 BEOPSGlobals::datBEOPSData->Save(BEOPSGlobals::datBEOPSData->strCurrentFileName);
			 }

			 delete BEOPSGlobals::datBEOPSData;
			 this->Text = L"Main Menu - BEOPS 5.0";
			 mnuOpen->Enabled=true;
			 mnuImport->Enabled=true;
			 mnuNew->Enabled=true;
		 }
};


}

