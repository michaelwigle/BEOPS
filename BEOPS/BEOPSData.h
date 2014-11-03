#ifndef BEOPSDATA_H
#define BEOPSDATA_H
#pragma once
#include "time.h"
#include "BEOPSInventory.h"
#include "BEOPSDaily.h"
#include "VehicleExpense.h"
#include "MonthlyInventory.h"

using namespace System::IO;
using namespace System;

public ref class BEOPSData
{
public:
	BEOPSData(void);
	void Load(String^);
	bool Save(String^);
	bool Import(void);
	ArrayList^ GetIncomes(System::DateTime); //for one day
	ArrayList^ GetExpenses(System::DateTime); //for one day
	ArrayList^ GetOtherExpenses(System::DateTime); //for one day
	BEOPSDaily^ GetDaily(System::DateTime);
	int GetDailyIndex(System::DateTime);
	double GetStartingBalance(System::DateTime);
	double GetEndingBalance(System::DateTime);
	ArrayList^ GetMonthOfDailys(System::DateTime); //Takes Datetime value and returns array of Dailys for that month
	double GetExpenseTotals(String^, ArrayList^); //Takes an array of Dailys
	double GetIncomeTotals(String^, ArrayList^); //Takes an array of Dailys
	double GetOtherExpenseTotals(ArrayList^); //Takes an array of Dailys
	double GetWholesaleInventoryValue();
	//These are per session variables not written to disk
	String^ strCurrentFileName;

	//These are written to disk
	double dblVersionNumber;
	String^ strOperatorName;
	String^ strOperatorNumber;
	String^ strOperatorAddress1;
	String^ strOperatorAddress2;
	String^ strOperatorCity;
	String^ strOperatorState;
	String^ strOperatorZip;
	
	String^ strBSVIArea;
	String^ strFacilityNumber;
	String^ strFacilityAddress1;
	String^ strFacilityAddress2;
	String^ strFacilityCity;
	String^ strFacilityState;
	String^ strFacilityZip;

	double dblStartCash; //Cash on hand at beginning of the date range of transactions
	double dblAlternateInventory; //This can be used in lieu of keeping an updated inventory
	
	ArrayList^ arrDaily;
	ArrayList^ arrVehicleExpense;
	ArrayList^ arrInventory;
	ArrayList^ arrMonthlyInventory;

};
#endif