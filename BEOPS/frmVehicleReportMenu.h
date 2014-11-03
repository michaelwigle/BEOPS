#pragma once
#include "frmMethod1Input.h"
#include "frmMethod2Input.h"

namespace BEOPS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmVehicleReportMenu
	/// </summary>
	public ref class frmVehicleReportMenu : public System::Windows::Forms::Form
	{
	public:
		frmVehicleReportMenu(void)
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
		~frmVehicleReportMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnMethod1;
	private: System::Windows::Forms::Button^  btnMethod2;
	private: System::Windows::Forms::Button^  btnClose;
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
			this->btnMethod1 = (gcnew System::Windows::Forms::Button());
			this->btnMethod2 = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnMethod1
			// 
			this->btnMethod1->Location = System::Drawing::Point(67, 31);
			this->btnMethod1->Name = L"btnMethod1";
			this->btnMethod1->Size = System::Drawing::Size(75, 23);
			this->btnMethod1->TabIndex = 0;
			this->btnMethod1->Text = L"Method &1";
			this->btnMethod1->UseVisualStyleBackColor = true;
			this->btnMethod1->Click += gcnew System::EventHandler(this, &frmVehicleReportMenu::btnMethod1_Click);
			// 
			// btnMethod2
			// 
			this->btnMethod2->Location = System::Drawing::Point(67, 70);
			this->btnMethod2->Name = L"btnMethod2";
			this->btnMethod2->Size = System::Drawing::Size(75, 23);
			this->btnMethod2->TabIndex = 1;
			this->btnMethod2->Text = L"Method &2";
			this->btnMethod2->UseVisualStyleBackColor = true;
			this->btnMethod2->Click += gcnew System::EventHandler(this, &frmVehicleReportMenu::btnMethod2_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(67, 110);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 2;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmVehicleReportMenu::btnClose_Click);
			// 
			// frmVehicleReportMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(212, 165);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnMethod2);
			this->Controls->Add(this->btnMethod1);
			this->Name = L"frmVehicleReportMenu";
			this->Text = L"Vehicle Report";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->Close();
			 }
	private: System::Void btnMethod2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 frmMethod2Input^ dlgMethod2Input = gcnew frmMethod2Input();
				 dlgMethod2Input->ShowDialog();
			 }
	private: System::Void btnMethod1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 frmMethod1Input^ dlgMethod1Input = gcnew frmMethod1Input();
				 dlgMethod1Input->ShowDialog();
			 }
	};
}
