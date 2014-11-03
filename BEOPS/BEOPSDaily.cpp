#include "StdAfx.h"
#include "BEOPSDaily.h"
#include "BEOPSGlobals.h"

BEOPSDaily::BEOPSDaily(void)
{
	dteDate = DateTime::Today;
	arrIncome = gcnew ArrayList();
	arrExpenses = gcnew ArrayList();
}

BEOPSDaily::BEOPSDaily(System::DateTime dteNew)
{
	dteDate = dteNew;
	arrIncome = gcnew ArrayList();
	arrExpenses = gcnew ArrayList();
}

void BEOPSDaily::Read(StreamReader^ sr)
{
	int nTemp = 0;
	int nNumberOfRecords = 0;
	dteDate = System::Convert::ToDateTime(sr->ReadLine());

	nNumberOfRecords = System::Convert::ToInt32(sr->ReadLine());
	//Read in the various income entries
	while (nTemp<nNumberOfRecords)
	{
		arrIncome->Add(gcnew Income());
		((Income^)arrIncome[arrIncome->Count-1])->Read(sr);
		nTemp++;
	}
	//Read in the various expense entries
	nTemp = 0;
	nNumberOfRecords = System::Convert::ToInt32(sr->ReadLine());
	while (nTemp<nNumberOfRecords)
	{
		arrExpenses->Add(gcnew Expense());
		((Expense^)arrExpenses[arrExpenses->Count-1])->Read(sr);
		nTemp++;
	}
	
}

void BEOPSDaily::Import(Daily^ objDaily)
{
	dteDate = objDaily->dteDate;

	//First I add the new expenses that didn't used to be called expenses
	if (objDaily->dblStockPurchased > 0)
		arrExpenses->Add(gcnew Expense(L"Stock Purchased", L"vv",objDaily->dblStockPurchased,""));
	if (objDaily->dblDraw > 0)
		arrExpenses->Add(gcnew Expense(L"Draw", L"uu", objDaily->dblDraw, ""));
	if (objDaily->dblServiceCharge > 0 )
		arrExpenses->Add(gcnew Expense(L"Service Charge", L"xx", objDaily->dblServiceCharge, ""));
	if (objDaily->dblWages > 0 )
		arrExpenses->Add(gcnew Expense(L"Wages", L"yy", objDaily->dblWages, ""));


	//This next section is for converting the hard coded expense fields to Expense objects
	if (objDaily->dblTaxLiability>0)
		arrExpenses->Add(gcnew Expense(L"Tax Liability",L"zz",objDaily->dblTaxLiability,""));
	if (objDaily->strExpCode1 != "" && objDaily->strExpCode1 != "R")
		arrExpenses->Add(gcnew Expense(BEOPSGlobals::GetExpenseName(objDaily->strExpCode1),objDaily->strExpCode1,objDaily->dblExpAmt1,""));
	if (objDaily->strExpCode2 != "" && objDaily->strExpCode2 != "R")
		arrExpenses->Add(gcnew Expense(BEOPSGlobals::GetExpenseName(objDaily->strExpCode2),objDaily->strExpCode2,objDaily->dblExpAmt2,""));
	if (objDaily->strExpCode3 != "" && objDaily->strExpCode3 != "R")
		arrExpenses->Add(gcnew Expense(BEOPSGlobals::GetExpenseName(objDaily->strExpCode3),objDaily->strExpCode3,objDaily->dblExpAmt3,""));
	if (objDaily->strExpCode4 != "" && objDaily->strExpCode4 != "R")
		arrExpenses->Add(gcnew Expense(BEOPSGlobals::GetExpenseName(objDaily->strExpCode4),objDaily->strExpCode4,objDaily->dblExpAmt4,""));
	if (objDaily->strExpCode5 != "" && objDaily->strExpCode5 != "R")
		arrExpenses->Add(gcnew Expense(BEOPSGlobals::GetExpenseName(objDaily->strExpCode5),objDaily->strExpCode5,objDaily->dblExpAmt5,""));
	if (objDaily->strExpCode6 != "" && objDaily->strExpCode6 != "R")
		arrExpenses->Add(gcnew Expense(BEOPSGlobals::GetExpenseName(objDaily->strExpCode6),objDaily->strExpCode6,objDaily->dblExpAmt6,""));
	if (objDaily->strExpCode7 != "" && objDaily->strExpCode7 != "R")
		arrExpenses->Add(gcnew Expense(BEOPSGlobals::GetExpenseName(objDaily->strExpCode7),objDaily->strExpCode7,objDaily->dblExpAmt7,""));


	//Next I will add Income objects
	if (objDaily->dblSales > 0)
		arrIncome->Add(gcnew Income("Sales", objDaily->dblSales, ""));
	if (objDaily->dblOhioLotteryAmt>0)
		arrIncome->Add(gcnew Income("Ohio Lottery",objDaily->dblOhioLotteryAmt,""));
	if (objDaily->dblCateringAmt>0)
		arrIncome->Add(gcnew Income("Catering", objDaily->dblCateringAmt,""));
	if (objDaily->dblMiscAmt>0)
		arrIncome->Add(gcnew Income("Miscellaneous", objDaily->dblMiscAmt,""));
}

void BEOPSDaily::Write(StreamWriter^ sw)
{
	int nTemp=0;
	sw->WriteLine(System::Convert::ToString(dteDate));
	//sw->WriteLine(System::Convert::ToString(dblSales));
	//sw->WriteLine(System::Convert::ToString(dblStockPurchased));
	//sw->WriteLine(System::Convert::ToString(dblDraw));
	//sw->WriteLine(System::Convert::ToString(dblServiceCharge));
	sw->WriteLine(System::Convert::ToString(arrIncome->Count));
	while (nTemp<arrIncome->Count)
	{
		((Income^)arrIncome[nTemp])->Write(sw);
		nTemp++;
	}
	sw->WriteLine(System::Convert::ToString(arrExpenses->Count));
	nTemp = 0;
	while (nTemp<arrExpenses->Count)
	{
		((Expense^)arrExpenses[nTemp])->Write(sw);
		nTemp++;
	}
}

Int32 BEOPSDaily::CompareTo(Object^ obj)
{
	if (obj == nullptr) return 1;
	BEOPSDaily^ tmpObj = (BEOPSDaily^)obj;
	return dteDate.CompareTo(tmpObj->dteDate);
}

void BEOPSDaily::Import(VehicleExpense^ objVehicleExpense)
{
	if(objVehicleExpense->dblGasExpense>0)
		arrExpenses->Add(gcnew Expense("Vehicle Gas","R",objVehicleExpense->dblGasExpense,"",objVehicleExpense->strVehicleID));
	if(objVehicleExpense->dblMaintenanceExpense>0)
		arrExpenses->Add(gcnew Expense("Vehicle Maintenance","R",objVehicleExpense->dblMaintenanceExpense,objVehicleExpense->strMaintenancePurveyor + " - " + objVehicleExpense->strMaintenanceDescription, objVehicleExpense->strVehicleID));
	if(objVehicleExpense->dblInsuranceExpense>0)
		arrExpenses->Add(gcnew Expense("Vehicle Insurance","R",objVehicleExpense->dblInsuranceExpense,"", objVehicleExpense->strVehicleID));
	if(objVehicleExpense->dblVehiclePayment>0)
		arrExpenses->Add(gcnew Expense("Vehicle Payment","R",objVehicleExpense->dblVehiclePayment,"", objVehicleExpense->strVehicleID));
	if(objVehicleExpense->dblParkingAndTolls>0)
		arrExpenses->Add(gcnew Expense("Vehicle Parking and Tolls","R",objVehicleExpense->dblParkingAndTolls,"", objVehicleExpense->strVehicleID));

}
double BEOPSDaily::GetIncome(String^ strSearchIncome)
{
	int nIndex=0;
	double dblReturn = 0;
	while (nIndex<arrIncome->Count)
	{
		if (((Income^)arrIncome[nIndex])->strIncomeName==strSearchIncome)
			dblReturn = ((Income^)arrIncome[nIndex])->dblIncomeAmt;
		nIndex++;
	}
	return dblReturn;
}

double BEOPSDaily::GetExpense(String^ strSearchExpense)
{
	int nIndex = 0;
	double dblReturn = 0;
	while (nIndex<arrExpenses->Count)
	{
		if(((Expense^)arrExpenses[nIndex])->strExpName == strSearchExpense)
			dblReturn = ((Expense^)arrExpenses[nIndex])->dblExpAmt;
		nIndex++;
	}
	return dblReturn;
}