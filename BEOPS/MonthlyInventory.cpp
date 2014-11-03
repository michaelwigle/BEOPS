#include "StdAfx.h"
#include "MonthlyInventory.h"


MonthlyInventory::MonthlyInventory(void)
{
	dteMonthYearEnding = DateTime::MinValue;
	dblEndingInventory = 0;
	bEstimate = false;
}

MonthlyInventory::MonthlyInventory(System::DateTime dteTemp,double dblTemp,bool bTemp)
{
	dteMonthYearEnding = dteTemp;
	dblEndingInventory = dblTemp;
	bEstimate = bTemp;
}

void MonthlyInventory::Write(StreamWriter^ sw)
{
	sw->WriteLine(dteMonthYearEnding.ToString());
	sw->WriteLine(dblEndingInventory.ToString());
	sw->WriteLine(bEstimate.ToString());
}

void MonthlyInventory::Read(StreamReader^ sr)
{
	dteMonthYearEnding = System::Convert::ToDateTime(sr->ReadLine());
	dblEndingInventory = System::Convert::ToDouble(sr->ReadLine());
	bEstimate = System::Convert::ToBoolean(sr->ReadLine());
}