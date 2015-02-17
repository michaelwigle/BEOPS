#include "stdafx.h"
#include "BEOPSData.h"
#include "BEOPSGlobals.h"
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

BEOPSData::BEOPSData(void)
{
	strCurrentFileName = "";

	dblVersionNumber = 5.1;
	strOperatorName = "";
	strOperatorNumber = "";
	strOperatorAddress1 = "";
	strOperatorAddress2 = "";
	strOperatorCity = "";
	strOperatorState = "";
	strOperatorZip = "";
	
	strBSVIArea = "";
	strFacilityNumber = "";
	strFacilityAddress1 = "";
	strFacilityAddress2 = "";
	strFacilityCity = "";
	strFacilityState = "";
	strFacilityZip = "";

	dblStartCash = 0; 
	dblAlternateInventory = 0; 
	
	arrDaily = gcnew ArrayList();
	arrInventory = gcnew ArrayList();
	arrVehicleExpense = gcnew ArrayList();
	arrMonthlyInventory = gcnew ArrayList();
}

void BEOPSData::Load(String^ strFilename)
{
	StreamReader^ sr = gcnew StreamReader(strFilename);
	int nTemp = 0;
	double dblNumberOfRecords = 0;
	strCurrentFileName = strFilename;
	dblVersionNumber = System::Convert::ToDouble(sr->ReadLine());
	strOperatorName = sr->ReadLine();
	strOperatorNumber = sr->ReadLine();
	strOperatorAddress1 = sr->ReadLine();
	strOperatorAddress2 = sr->ReadLine();
	strOperatorCity = sr->ReadLine();
	strOperatorState = sr->ReadLine();
	strOperatorZip = sr->ReadLine();
	
	strBSVIArea = sr->ReadLine();
	strFacilityNumber = sr->ReadLine();
	strFacilityAddress1 = sr->ReadLine();
	strFacilityAddress2 = sr->ReadLine();
	strFacilityCity = sr->ReadLine();
	strFacilityState = sr->ReadLine();
	strFacilityZip = sr->ReadLine();

	dblStartCash = System::Convert::ToDouble(sr->ReadLine()); 
	dblAlternateInventory = System::Convert::ToDouble(sr->ReadLine()); 

	dblNumberOfRecords = System::Convert::ToDouble(sr->ReadLine());
	while (nTemp<dblNumberOfRecords)
	{
		arrDaily->Add(gcnew BEOPSDaily());
		((BEOPSDaily^)arrDaily[nTemp])->Read(sr);
		nTemp++;
	}
	//Loop to read vehicle expenses
	nTemp = 0;
	dblNumberOfRecords = System::Convert::ToDouble(sr->ReadLine());
	while (nTemp<dblNumberOfRecords)
	{
		arrVehicleExpense->Add(gcnew VehicleExpense());
		((VehicleExpense^)arrVehicleExpense[nTemp])->Read(sr);
		nTemp++;
	}
	//Loop to read inventory
	nTemp = 0;
	dblNumberOfRecords = System::Convert::ToDouble(sr->ReadLine());
	while (nTemp<dblNumberOfRecords)
	{
		arrInventory->Add(gcnew BEOPSInventory());
		((BEOPSInventory^)arrInventory[nTemp])->Read(sr);
		nTemp++;
	}
	//Loop to read monthly inventory
	nTemp = 0;
	dblNumberOfRecords = System::Convert::ToDouble(sr->ReadLine());
	while (nTemp<dblNumberOfRecords)
	{
		arrMonthlyInventory->Add(gcnew MonthlyInventory());
		((MonthlyInventory^)arrMonthlyInventory[nTemp])->Read(sr);
		nTemp++;
	}
	sr->Close();
}

bool BEOPSData::Save(String^ strFilename)
{
	StreamWriter^ sw = gcnew StreamWriter(strFilename);
	int nTemp = 0;
	sw->WriteLine(System::Convert::ToString(dblVersionNumber));
	sw->WriteLine(strOperatorName);
	sw->WriteLine(strOperatorNumber);
	sw->WriteLine(strOperatorAddress1);
	sw->WriteLine(strOperatorAddress2);
	sw->WriteLine(strOperatorCity);
	sw->WriteLine(strOperatorState);
	sw->WriteLine(strOperatorZip);
	
	sw->WriteLine(strBSVIArea);
	sw->WriteLine(strFacilityNumber);
	sw->WriteLine(strFacilityAddress1);
	sw->WriteLine(strFacilityAddress2);
	sw->WriteLine(strFacilityCity);
	sw->WriteLine(strFacilityState);
	sw->WriteLine(strFacilityZip);

	sw->WriteLine(System::Convert::ToString(dblStartCash));
	sw->WriteLine(System::Convert::ToString(dblAlternateInventory));

	sw->WriteLine(System::Convert::ToString(arrDaily->Count));
	while (nTemp<arrDaily->Count)
	{
		((BEOPSDaily^)arrDaily[nTemp])->Write(sw);
		nTemp++;
	}

	nTemp = 0;
	sw->WriteLine(System::Convert::ToString(arrVehicleExpense->Count));
	//Loop to write Vehicle Expense
	while (nTemp<arrVehicleExpense->Count)
	{
		((VehicleExpense^)arrVehicleExpense[nTemp])->Write(sw);
		nTemp++;
	}
	//Loop to write Inventory
	nTemp = 0;
	sw->WriteLine(System::Convert::ToString(arrInventory->Count));
	while (nTemp<arrInventory->Count)
	{
		((BEOPSInventory^)arrInventory[nTemp])->Write(sw);
		nTemp++;
	}
	//Loop to write MonthlyInventory
	nTemp=0;
	sw->WriteLine(System::Convert::ToString(arrMonthlyInventory->Count));
	while (nTemp<arrMonthlyInventory->Count)
	{
		((MonthlyInventory^)arrMonthlyInventory[nTemp])->Write(sw);
		nTemp++;
	}
	sw->Flush();
	sw->Close();
	return true;
}

bool BEOPSData::Import(void)
{
	bool bSuccess = false;
	FolderBrowserDialog^ dlgOpenFolder = gcnew FolderBrowserDialog;
	String^ strFileName;
	Object^ objBETEXT0 = gcnew String("\\BETEXT0.TXT");
	Object^ objBETEXT1 = gcnew String("\\BETEXT1.TXT");
	Object^ objBETEXT2 = gcnew String("\\BETEXT2.TXT");
	Object^ objBETEXT3 = gcnew String("\\BETEXT3.TXT");
	dlgOpenFolder->RootFolder=Environment::SpecialFolder::UserProfile;
	if(dlgOpenFolder->ShowDialog()==System::Windows::Forms::DialogResult::OK)
	{
		//First, I define the variables I will need for the importation process.
		StreamReader^ sr;
		String^ line;
		int nLineNumber;
		array<wchar_t>^ aTrim = {'"'};
		array<System::String ^>^ split;
		ArrayList^ tmparrDaily = gcnew ArrayList();
		arrVehicleExpense = gcnew ArrayList();
		ArrayList^ tmparrInventory = gcnew ArrayList();
		InitialValues^ datInitialValues = gcnew InitialValues();
		
		//Next, load Initial Values from BETEXT0
		strFileName=dlgOpenFolder->SelectedPath + objBETEXT0;
		datInitialValues->Load(strFileName);
		//Here I transfer them to the BEOPSData object.
		
		strOperatorName = datInitialValues->strOperatorName;
		strOperatorNumber = datInitialValues->strOperatorNumber;
		strOperatorAddress1 = datInitialValues->strOperatorAddress1;
		strOperatorAddress2 = datInitialValues->strOperatorAddress2;
		strOperatorCity = datInitialValues->strOperatorCity;
		strOperatorState = datInitialValues->strOperatorState;
		strOperatorZip = datInitialValues->strOperatorZip;

		strFacilityAddress1 = strOperatorAddress1;
		strFacilityAddress2 = strOperatorAddress2;
		strFacilityCity = strOperatorCity;
		strFacilityState = strOperatorState;
		strFacilityZip = strOperatorZip;
	
		strBSVIArea = datInitialValues->strBSVIArea;
		dblStartCash = datInitialValues->dblStartCash; 
		dblAlternateInventory = datInitialValues->dblInitialInventory; 
		

		//Next, load Dailys from BETEXT1 
		strFileName = dlgOpenFolder->SelectedPath + objBETEXT1;
		// Create an instance of StreamReader to read from a file.
		sr = gcnew StreamReader(strFileName);
		nLineNumber = 0;
		// Read from the file until the end of the file is reached.
		while ((line = sr->ReadLine()) != nullptr)
		{
			nLineNumber++;	
			if(nLineNumber>1)
			{
				//Copy the data into the old Daily format
				split = line->Split(',');
				tmparrDaily->Add(gcnew Daily());
				((Daily^)tmparrDaily[nLineNumber-2])->Load(split);
				//Copy the data into the current object
				arrDaily->Add(gcnew BEOPSDaily);
				((BEOPSDaily^)arrDaily[nLineNumber-2])->Import(((Daily^)tmparrDaily[nLineNumber-2]));
			}
		}
		delete sr;
		if(arrDaily->Count>0)
		{
			//create the starting inventory record
			DateTime dteTemp = ((BEOPSDaily^)arrDaily[0])->dteDate;
			dteTemp = dteTemp.AddMonths(-1);
			arrMonthlyInventory->Add(gcnew MonthlyInventory(dteTemp,dblAlternateInventory,true));
		}

		// Third, read the BETEXT2 file with the vehicle expenses and put them in with the other expenses.

		strFileName = dlgOpenFolder->SelectedPath + objBETEXT2;
		sr = gcnew StreamReader(strFileName);
		nLineNumber = 0;
		VehicleExpense^ tmpObjVehicleExpense;
		BEOPSDaily^ objDaily;
		while ((line = sr->ReadLine()) != nullptr)
		{
			if(nLineNumber>1)
			{
				tmpObjVehicleExpense = gcnew VehicleExpense();
				nLineNumber++;
				split = line->Split(',');
				tmpObjVehicleExpense->Load(split);
				
				objDaily = this->GetDaily(tmpObjVehicleExpense->dteExpenseDate);
				objDaily->Import(tmpObjVehicleExpense);
				
				delete tmpObjVehicleExpense;
			}
			nLineNumber++;
		}
		delete sr;

		//Next, load the BETEXT3 file with the inventory.
		strFileName = dlgOpenFolder->SelectedPath + objBETEXT3;
		sr = gcnew StreamReader(strFileName);
		nLineNumber = 0;
		while ((line = sr->ReadLine()) != nullptr)
		{
			nLineNumber++;
			if(nLineNumber>1)
			{
				split = line->Split(',');
				tmparrInventory->Add(gcnew Inventory());
				((Inventory^)tmparrInventory[nLineNumber-2])->Load(split);
				arrInventory->Add(gcnew BEOPSInventory((Inventory^)tmparrInventory[nLineNumber-2]));
				
			}
		}
		delete sr;
		bSuccess = true;
	}
	return bSuccess;
}

ArrayList^ BEOPSData::GetIncomes(System::DateTime dteSearch)
{
	int nIndex;
	int nLoop;
	ArrayList^ arrIncomes = gcnew ArrayList();
	for (nIndex = 0; nIndex < arrDaily->Count ; nIndex++)
	{
		if (((BEOPSDaily^)arrDaily[nIndex])->dteDate==dteSearch)
		{
			for(nLoop = 0;nLoop<((BEOPSDaily^)arrDaily[nIndex])->arrIncome->Count; nLoop++)
			{
				arrIncomes->Add(((BEOPSDaily^)arrDaily[nIndex])->arrIncome[nLoop]);
			}
			nIndex = arrDaily->Count;
		}
	}
	return arrIncomes;
}
ArrayList^ BEOPSData::GetExpenses(System::DateTime dteSearch)
{
	int nIndex;
	int nLoop;
	ArrayList^ arrExpenses = gcnew ArrayList();
	for (nIndex = 0; nIndex < arrDaily->Count ; nIndex++)
	{
		if (((BEOPSDaily^)arrDaily[nIndex])->dteDate==dteSearch)
		{
			for(nLoop = 0;nLoop<((BEOPSDaily^)arrDaily[nIndex])->arrExpenses->Count; nLoop++)
			{
				arrExpenses->Add(((BEOPSDaily^)arrDaily[nIndex])->arrExpenses[nLoop]);
			}
			nIndex = arrDaily->Count;
		}
	}
	return arrExpenses;
}

BEOPSDaily^ BEOPSData::GetDaily(System::DateTime dteSearch)
{
	int nIndex;
	BEOPSDaily^ objFoundDaily = nullptr;
	for (nIndex = 0; nIndex < arrDaily->Count ; nIndex++)
	{
		if (((BEOPSDaily^)arrDaily[nIndex])->dteDate==dteSearch)
			objFoundDaily = ((BEOPSDaily^)arrDaily[nIndex]);
	}
	return objFoundDaily;
}
int BEOPSData::GetDailyIndex(System::DateTime dteSearch)
{
	int nIndex;
	int nReturn = -1;
	BEOPSDaily^ objFoundDaily = nullptr;
	arrDaily->Sort();
	for (nIndex = 0; nIndex < arrDaily->Count ; nIndex++)
	{
		if (((BEOPSDaily^)arrDaily[nIndex])->dteDate==dteSearch)
		{
			nReturn = nIndex;
			nIndex = arrDaily->Count;
		}
	}
	return nReturn;
}

double BEOPSData::GetStartingBalance(System::DateTime dteTemp)
{
	System::DateTime dteSearch = dteTemp;
	int nDailyIndex = 0;
	int nIncomeIndex = 0;
	int nExpenseIndex = 0;
	double dIncomeTotal = 0;
	double dExpenseTotal = 0;
	double dStartingBalance = 0;
	BEOPSDaily^ objDaily;
	while (nDailyIndex<arrDaily->Count)
	{
		objDaily = ((BEOPSDaily^)arrDaily[nDailyIndex]);
		if (dteSearch>objDaily->dteDate)
		{
			//We have a Daily to check for incomes
			while (nIncomeIndex<objDaily->arrIncome->Count)
			{
				dIncomeTotal+=((Income^)objDaily->arrIncome[nIncomeIndex])->dblIncomeAmt;
				nIncomeIndex++;
			}
		}
		if (dteSearch>objDaily->dteDate)
		{
			//We have a Daily to check for expenses
			while (nExpenseIndex<objDaily->arrExpenses->Count)
			{
				if(((Expense^)objDaily->arrExpenses[nExpenseIndex])->strExpName!="Tax Liability")
					dExpenseTotal+=((Expense^)objDaily->arrExpenses[nExpenseIndex])->dblExpAmt;
				nExpenseIndex++;
			}
		}
		nDailyIndex++;
		nIncomeIndex=0;
		nExpenseIndex=0;
	}
	dStartingBalance = dblStartCash + dIncomeTotal - dExpenseTotal;
	return dStartingBalance;
}

double BEOPSData::GetEndingBalance(System::DateTime dteSearch)
{
	double dEndingBalance = 0;
	int nDailyIndex = 0;
	int nIncomeIndex = 0;
	int nExpenseIndex = 0;
	double dIncomeTotal = 0;
	double dExpenseTotal = 0;
	BEOPSDaily^ objDaily; 
	while (nDailyIndex<arrDaily->Count)
	{
		objDaily = ((BEOPSDaily^)arrDaily[nDailyIndex]);
		if (dteSearch>=objDaily->dteDate)
		{
			//We have a Daily to check for incomes
			while (nIncomeIndex<objDaily->arrIncome->Count)
			{
				dIncomeTotal+=((Income^)objDaily->arrIncome[nIncomeIndex])->dblIncomeAmt;
				nIncomeIndex++;
			}
		}
		if (dteSearch>=objDaily->dteDate)
		{
			//We have a Daily to check for expenses
			while (nExpenseIndex<objDaily->arrExpenses->Count)
			{
				if(((Expense^)objDaily->arrExpenses[nExpenseIndex])->strExpName!="Tax Liability")
					dExpenseTotal+=((Expense^)objDaily->arrExpenses[nExpenseIndex])->dblExpAmt;
				nExpenseIndex++;
			}
		}
		nDailyIndex++;
		nIncomeIndex=0;
		nExpenseIndex=0;
	}
	dEndingBalance = dblStartCash + dIncomeTotal - dExpenseTotal;

	return dEndingBalance;
}
ArrayList^ BEOPSData::GetMonthOfDailys(System::DateTime dteSearch)
{
	int nIndex;
	ArrayList^ arrDailys = gcnew ArrayList;
	arrDaily->Sort();
	for (nIndex = 0; nIndex < arrDaily->Count ; nIndex++)
	{
		if (((BEOPSDaily^)arrDaily[nIndex])->dteDate.Month==dteSearch.Month && ((BEOPSDaily^)arrDaily[nIndex])->dteDate.Year==dteSearch.Year)
		{
			arrDailys->Add(((BEOPSDaily^)arrDaily[nIndex]));
			
		}
	}
	if( arrDailys->Count == 0)
	{
		delete arrDailys;
		arrDailys = nullptr;
	}
	return arrDailys;
}
ArrayList^ BEOPSData::GetOtherExpenses(System::DateTime dteSearch)
{
	int nIndex;
	int nLoop;
	ArrayList^ arrExpenses = gcnew ArrayList();
	BEOPSDaily^ objDaily;
	for (nIndex = 0; nIndex < arrDaily->Count ; nIndex++)
	{
		if (((BEOPSDaily^)arrDaily[nIndex])->dteDate==dteSearch)
		{
			objDaily = ((BEOPSDaily^)arrDaily[nIndex]);
			for (nLoop = 0; nLoop < objDaily->arrExpenses->Count; nLoop++)
			{
				if(	((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Stock Purchased" && 
					((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Wages" &&
					((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Draw" &&
					((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Service Charge" &&
					((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Tax Liability")
				{
					arrExpenses->Add(((Expense^)objDaily->arrExpenses[nLoop]));
				}
			}
			nIndex = arrDaily->Count;
		}
	}
	
	return arrExpenses;
}
double BEOPSData::GetOtherExpenseTotals(ArrayList^ arrDaily)
{
	int nIndex;
	int nLoop;
	double dblExpenseTotals = 0;
	BEOPSDaily^ objDaily;
	for (nIndex = 0; nIndex < arrDaily->Count ; nIndex++)
	{
			objDaily = ((BEOPSDaily^)arrDaily[nIndex]);
			for (nLoop = 0; nLoop < objDaily->arrExpenses->Count; nLoop++)
			{
				if(	((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Stock Purchased" && 
					((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Wages" &&
					((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Draw" &&
					((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Service Charge" &&
					((Expense^)objDaily->arrExpenses[nLoop])->strExpName != L"Tax Liability")
				{
					dblExpenseTotals += ((Expense^)objDaily->arrExpenses[nLoop])->dblExpAmt;
				}
			}
	}
	
	return dblExpenseTotals;

}
double BEOPSData::GetExpenseTotals(String^ strExpenseName, ArrayList^ arrDailys)
{
	double dblExpenseTotal = 0;
	ArrayList^ arrExpenses;
	if(arrDailys!=nullptr)
	{
		for(int nIndex=0;nIndex<arrDailys->Count;nIndex++)
		{
			arrExpenses = ((BEOPSDaily^)arrDailys[nIndex])->arrExpenses;
			for(int nLoop=0;nLoop<arrExpenses->Count;nLoop++)
			{
				if(((Expense^)arrExpenses[nLoop])->strExpName == strExpenseName)
					dblExpenseTotal += ((Expense^)arrExpenses[nLoop])->dblExpAmt;
			}
		}
	}
	return dblExpenseTotal;
}
double BEOPSData::GetIncomeTotals(String^ strIncomeName, ArrayList^ arrDailys)
{
	double dblIncomeTotal = 0;
	ArrayList^ arrIncome;
	if(arrDailys!=nullptr)
	{
		for(int nIndex=0;nIndex<arrDailys->Count;nIndex++)
		{
			arrIncome = ((BEOPSDaily^)arrDailys[nIndex])->arrIncome;
			for(int nLoop=0;nLoop<arrIncome->Count;nLoop++)
			{
				if(((Income^)arrIncome[nLoop])->strIncomeName == strIncomeName)
					dblIncomeTotal += ((Income^)arrIncome[nLoop])->dblIncomeAmt;
			}
		}
	}
	return dblIncomeTotal;
}

double BEOPSData::GetWholesaleInventoryValue()
{
	double dblUnitCount, dblUnitValue, dblValue = 0;
	if(this->arrInventory!=nullptr)
	{
		for(int nIndex=0; nIndex<arrInventory->Count; nIndex++)
		{
			dblUnitCount = ((BEOPSInventory^)arrInventory[nIndex])->dblUnitCount;
			dblUnitValue = ((BEOPSInventory^)arrInventory[nIndex])->dblUnitWholesaleCost;
			dblValue += (dblUnitCount * dblUnitValue);
		}
	}
	return dblValue;
}