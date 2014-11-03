#include "StdAfx.h"
#include "Expense.h"
#include "BEOPSGlobals.h"

Expense::Expense(void)
{
	strExpName = "";
	strExpCode = "";
	dblExpAmt = 0;
	strMemo = "";
	strVehicleID = "";
}

void Expense::Load(void)
{

}

Expense::Expense(String^ strNewExpName, String^ strNewExpCode, double dblNewExpAmt, String^ strNewMemo)
{
	strExpName = strNewExpName;
	strExpCode = strNewExpCode;
	dblExpAmt = dblNewExpAmt;
	strMemo = strNewMemo;
	strVehicleID = "";
}

Expense::Expense(String^ strNewExpName, String^ strNewExpCode, double dblNewExpAmt, String^ strNewMemo, String^ strNewVehicleID)
{
	strExpName = strNewExpName;
	strExpCode = strNewExpCode;
	dblExpAmt = dblNewExpAmt;
	strMemo = strNewMemo;
	strVehicleID = strNewVehicleID;
}

void Expense::Write(StreamWriter^ sw)
{
	sw->WriteLine(strExpName);
	sw->WriteLine(strExpCode);
	sw->WriteLine(System::Convert::ToString(dblExpAmt));
	sw->WriteLine(strMemo);
	sw->WriteLine(strVehicleID);
}
	
void Expense::Read(StreamReader^ sr)
{
	strExpName = sr->ReadLine();
	strExpCode = sr->ReadLine();
	dblExpAmt = System::Convert::ToDouble(sr->ReadLine());
	strMemo = sr->ReadLine();
	strVehicleID = sr->ReadLine();
}

bool Expense::IsVehicleExpense()
{
	bool bReturn = false;
	if (strExpCode->ToUpper() == "R")
		bReturn = true;
	return bReturn;
}