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

	static BEOPSGlobals(void)
	{

		arrIncomeNames = gcnew ArrayList;
		arrIncomeNames->Add("Sales");
		arrIncomeNames->Add("Ohio Lottery");
		arrIncomeNames->Add("Catering");
		arrIncomeNames->Add("Miscellaneous");
		arrIncomeNames->Add("Operator Equity");

		arrExpenseNames = gcnew ArrayList;
		arrExpenseNames->Add("Supplies");
		arrExpenseNames->Add("Janitorial");
		arrExpenseNames->Add("Business License");
		arrExpenseNames->Add("Telecommunications");
		arrExpenseNames->Add("Uniforms");
		arrExpenseNames->Add("Advertising");
		arrExpenseNames->Add("Insurance");
		arrExpenseNames->Add("Rent/Commision");
		arrExpenseNames->Add("Storage");
		arrExpenseNames->Add("Utilities");
		arrExpenseNames->Add("FICA");
		arrExpenseNames->Add("Workers Compensation");
		arrExpenseNames->Add("Ohio Unemployment");
		arrExpenseNames->Add("Federal Unemployment Tax");
		arrExpenseNames->Add("Sales Tax");
		arrExpenseNames->Add("Pre-approved Training");
		arrExpenseNames->Add("Temporary Operator Fee");
		arrExpenseNames->Add("Vehicle Expense");
		arrExpenseNames->Add("Pre-Approved Miscellaneous");
		arrExpenseNames->Add("Business Dues");
		arrExpenseNames->Add("Professional Merchandise Delivery");
		arrExpenseNames->Add("Pest Extermination Service");
		arrExpenseNames->Add("Bookkeeping/Accounting");
		arrExpenseNames->Add("Computer Related Expenses");
		arrExpenseNames->Add("Air Conditioning, Filter, Fire, and Security");
		arrExpenseNames->Add("Banking Fees");
		arrExpenseNames->Add("Refunds");
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