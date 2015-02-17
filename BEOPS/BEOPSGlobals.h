#ifndef BEOPSGLOBALS_H
#define BEOPSGLOBALS_H
#include "InitialValues.h"
#include "Daily.h"
#include "VehicleExpense.h"
#include "Inventory.h"
#include "BEOPSData.h"

//#include <string>
//#include <iostream>
using namespace std;
using namespace System;

public ref class BEOPSGlobals {

public:
	static BEOPSData^ datBEOPSData;
	static ArrayList^ arrIncomeNames;
	static ArrayList^ arrExpenseNames;
	static ArrayList^ arrExpenseCodes;
	//TODO: Thoughts. i am going to have to write some code to check for the version
	//of the data file and convert the old names to the new names or all will crash
	static BEOPSGlobals(void)
	{

		arrIncomeNames = gcnew ArrayList;
		arrIncomeNames->Add("Sales");
		arrIncomeNames->Add("Ohio Lottery");
		arrIncomeNames->Add("Catering");
		arrIncomeNames->Add("Miscellaneous");
		arrIncomeNames->Add("Operator Equity");

		arrExpenseNames = gcnew ArrayList;
		arrExpenseNames->Add("A - Supplies");//arrExpenseNames->Add("Supplies");
		arrExpenseNames->Add("B - Janitorial ODOT fee paid");//arrExpenseNames->Add("Janitorial");
		arrExpenseNames->Add("C - Business Licenses");//arrExpenseNames->Add("Business License");
		arrExpenseNames->Add("D - Telecommunication services / Business");//arrExpenseNames->Add("Telecommunications");
		arrExpenseNames->Add("E - Cost of uniforms rented owned and laundry when used for business");//arrExpenseNames->Add("Uniforms");
		arrExpenseNames->Add("F - Business Advertising / Promotional");//arrExpenseNames->Add("Advertising");
		arrExpenseNames->Add("G - Insurance Premiums coverage for off-site storage");//arrExpenseNames->Add("Insurance");
		arrExpenseNames->Add("H - Commision / Grantor rent");//arrExpenseNames->Add("Rent/Commision");
		arrExpenseNames->Add("I - Expense for storage space");//arrExpenseNames->Add("Storage");
		arrExpenseNames->Add("J - Utilities for facility when not included in rent");//arrExpenseNames->Add("Utilities");
		arrExpenseNames->Add("K - Employer Contribution for Social Security (FICA)");//arrExpenseNames->Add("FICA");
		arrExpenseNames->Add("L - Workers Compensation premiums (BWC)");//arrExpenseNames->Add("Workers Compensation");
		arrExpenseNames->Add("M - Ohio Unemployment (SUTA)");//arrExpenseNames->Add("Ohio Unemployment");
		arrExpenseNames->Add("N - Federal Unemployment Taxes (FUTA)");//arrExpenseNames->Add("Federal Unemployment Tax");
		arrExpenseNames->Add("O - Ohio Sales Tax");//arrExpenseNames->Add("Sales Tax");
		arrExpenseNames->Add("P - Pre-approved training expenses up to a $1000 limit per year");//arrExpenseNames->Add("Pre-approved Training");
		arrExpenseNames->Add("Q - Temporary operator agreement fees");//arrExpenseNames->Add("Temporary Operator Fee");
		//arrExpenseNames->Add("R - Vehicle expense report");//arrExpenseNames->Add("Vehicle Expense"); //This general Vehicle expense removed for 5.1
		arrExpenseNames->Add("S - Pre-Approved Miscellaneous expense");//arrExpenseNames->Add("Pre-Approved Miscellaneous");
		arrExpenseNames->Add("T - Business Dues");//arrExpenseNames->Add("Business Dues");
		arrExpenseNames->Add("U - Professional Merchandise Delivery Service");//arrExpenseNames->Add("Professional Merchandise Delivery");
		arrExpenseNames->Add("V - Pest Extermination Service");//arrExpenseNames->Add("Pest Extermination Service");
		arrExpenseNames->Add("W - Bookkeeping / Accounting Services");//arrExpenseNames->Add("Bookkeeping/Accounting");
		arrExpenseNames->Add("X - Computer and Computer Related Expenses");//arrExpenseNames->Add("Computer Related Expenses");
		arrExpenseNames->Add("Y - Business Legal Fees (not associated with any adversarial procedures against OOD)");//Added in 5.1
		arrExpenseNames->Add("Z - Air Conditioning, Filter, Fire, and Security");//arrExpenseNames->Add("Air Conditioning, Filter, Fire, and Security");
		arrExpenseNames->Add("aa - Banking Fees");//arrExpenseNames->Add("Banking Fees");
		arrExpenseNames->Add("bb - Documented refunds to customers");//arrExpenseNames->Add("Refunds");
		arrExpenseNames->Add("Vehicle Gas");
		arrExpenseNames->Add("Vehicle Parking and Tolls");
		arrExpenseNames->Add("Vehicle Payment");
		arrExpenseNames->Add("Vehicle Insurance");
		arrExpenseNames->Add("Vehicle Maintenance");
		arrExpenseNames->Add("Draw");
		arrExpenseNames->Add("Stock Purchased");
		arrExpenseNames->Add("Miscellaneous");
		arrExpenseNames->Add("Service Charge");
		arrExpenseNames->Add("Wages");
		arrExpenseNames->Add("Tax Liability");

		arrExpenseCodes = gcnew ArrayList;
		arrExpenseCodes->Add("A");
		arrExpenseCodes->Add("B");
		arrExpenseCodes->Add("C");
		arrExpenseCodes->Add("D");
		arrExpenseCodes->Add("E");
		arrExpenseCodes->Add("F");
		arrExpenseCodes->Add("G");
		arrExpenseCodes->Add("H");
		arrExpenseCodes->Add("I");
		arrExpenseCodes->Add("J");
		arrExpenseCodes->Add("K");
		arrExpenseCodes->Add("L");
		arrExpenseCodes->Add("M");
		arrExpenseCodes->Add("N");
		arrExpenseCodes->Add("O");
		arrExpenseCodes->Add("P");
		arrExpenseCodes->Add("Q");
		arrExpenseCodes->Add("R");
		arrExpenseCodes->Add("S");
		arrExpenseCodes->Add("T");
		arrExpenseCodes->Add("U");
		arrExpenseCodes->Add("V");
		arrExpenseCodes->Add("W");
		arrExpenseCodes->Add("X");
		arrExpenseCodes->Add("Y");//This is new in 5.1
		arrExpenseCodes->Add("Z");
		arrExpenseCodes->Add("AA");
		arrExpenseCodes->Add("BB");
		arrExpenseCodes->Add("R");
		arrExpenseCodes->Add("R");
		arrExpenseCodes->Add("R");
		arrExpenseCodes->Add("R");
		arrExpenseCodes->Add("R");
		arrExpenseCodes->Add("UU");
		arrExpenseCodes->Add("VV");
		arrExpenseCodes->Add("WW");
		arrExpenseCodes->Add("XX");
		arrExpenseCodes->Add("YY");
		arrExpenseCodes->Add("ZZ");

	}

	static String^ GetExpenseCode(String^ strExpName)
	{
		String^ strExpCode = "";
		int nIndex = arrExpenseNames->IndexOf(strExpName);
		strExpCode = ((String^)arrExpenseCodes[nIndex]);
		return strExpCode;
	}

	static String^ GetExpenseName(String^ strExpCode)
	{
		String^ strExpenseName = gcnew String("Other");
		strExpCode = strExpCode->ToUpper();
		int nIndex = arrExpenseCodes->IndexOf(strExpCode);
		strExpenseName = ((String^)arrExpenseNames[nIndex]);
		return strExpenseName;
		
	}

	static bool SameMonthAndYear(System::DateTime dteOne, System::DateTime dteTwo)
	{
		bool bSame = false;
		if(dteOne.Month == dteTwo.Month && dteOne.Year == dteTwo.Year)
			bSame = true;
		return bSame;
	}
	
};


#endif