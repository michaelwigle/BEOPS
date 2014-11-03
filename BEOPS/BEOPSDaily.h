#ifndef BEOPSDAILY_H
#define BEOPSDAILY_H
#pragma once
#include "time.h"
#include "Expense.h"
#include "Income.h"
#include "Daily.h"
#include "VehicleExpense.h"

using namespace System::IO;
using namespace System;
using namespace System::Collections;

public ref class BEOPSDaily: public IComparable
{
public:
	BEOPSDaily(void);
	BEOPSDaily(System::DateTime);
	void Read(StreamReader^);
	void Import(Daily^);
	void Import(VehicleExpense^);
	void Write(StreamWriter^);
	virtual Int32 CompareTo(Object^);
	double GetIncome(String^);
	double GetExpense(String^);

	System::DateTime dteDate;
	ArrayList^ arrIncome;
	ArrayList^ arrExpenses;
};
#endif