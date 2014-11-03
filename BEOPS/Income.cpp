#include "StdAfx.h"
#include "Income.h"
#include "BEOPSGlobals.h"

Income::Income(void)
{
	strIncomeName = "";
	dblIncomeAmt = 0;
	strMemo = "";
}
Income::Income(String^ strNewIncomeName, double dblNewIncomeAmt, String^ strNewMemo)
{
	strIncomeName = strNewIncomeName;
	dblIncomeAmt = dblNewIncomeAmt;
	strMemo = strNewMemo;
}

void Income::Load(void)
{

}

void Income::Write(StreamWriter^ sw)
{
	sw->WriteLine(strIncomeName);
	sw->WriteLine(System::Convert::ToString(dblIncomeAmt));
	sw->WriteLine(strMemo);
}

void Income::Read(StreamReader^ sr)
{
	strIncomeName = sr->ReadLine();
	dblIncomeAmt = System::Convert::ToDouble(sr->ReadLine());
	strMemo = sr->ReadLine();
}