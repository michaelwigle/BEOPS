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
	
	//This code converts pre-5.1 data files to have the proper expense names for 5.1
	if(strExpName == "Supplies") strExpName = "A - Supplies";
	if(strExpName == "Janitorial") strExpName = "B - Janitorial ODOT fee paid";
	if(strExpName == "Business License") strExpName = "C - Business Licenses";
	if(strExpName == "Telecommunications") strExpName = "D - Telecommunication services / Business";
	if(strExpName == "Uniforms") strExpName = "E - Cost of uniforms rented owned and laundry when used for business";
	if(strExpName == "Advertising") strExpName = "F - Business Advertising / Promotional";
	if(strExpName == "Insurance") strExpName = "G - Insurance Premiums coverage for off-site storage";
	if(strExpName == "Rent/Commision") strExpName = "H - Commision / Grantor rent";
	if(strExpName == "Storage") strExpName = "I - Expense for storage space";
	if(strExpName == "Utilities") strExpName = "J - Utilities for facility when not included in rent";
	if(strExpName == "FICA") strExpName = "K - Employer Contribution for Social Security (FICA)";
	if(strExpName == "Workers Compensation") strExpName = "L - Workers Compensation premiums (BWC)";
	if(strExpName == "Ohio Unemployment") strExpName = "M - Ohio Unemployment (SUTA)";
	if(strExpName == "Federal Unemployment Tax") strExpName = "N - Federal Unemployment Taxes (FUTA)";
	if(strExpName == "Sales Tax") strExpName = "O - Ohio Sales Tax";
	if(strExpName == "Pre-approved Training") strExpName = "P - Pre-approved training expenses up to a $1000 limit per year";
	if(strExpName == "Temporary Operator Fee") strExpName = "Q - Temporary operator agreement fees";
	if(strExpName == "Pre-Approved Miscellaneous") strExpName = "S - Pre-Approved Miscellaneous expense";
	if(strExpName == "Business Dues") strExpName = "T - Business Dues";
	if(strExpName == "Professional Merchandise Delivery") strExpName = "U - Professional Merchandise Delivery Service";
	if(strExpName == "Pest Extermination Service") strExpName = "V - Pest Extermination Service";
	if(strExpName == "Bookkeeping/Accounting") strExpName = "W - Bookkeeping / Accounting Services";
	if(strExpName == "Computer Related Expenses") strExpName = "X - Computer and Computer Related Expenses";
	if(strExpName == "Air Conditioning, Filter, Fire, and Security") strExpName = "Z - Air Conditioning, Filter, Fire, and Security";
	if(strExpName == "Banking Fees") strExpName = "aa - Banking Fees";
	if(strExpName == "Refunds") strExpName = "bb - Documented refunds to customers";
	//End of 5.1 compatibility code

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