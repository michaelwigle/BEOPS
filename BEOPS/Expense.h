#ifndef EXPENSE_H
#define EXPENSE_H
#pragma once

using namespace System::IO;
using namespace System;

public ref class Expense
{
public:
	Expense(void);
	Expense(String^, String^, double, String^);
	Expense(String^, String^, double, String^, String^);
	void Load(void);
	void Write(StreamWriter^);
	void Read(StreamReader^);
	bool IsVehicleExpense();

	String^ strExpName;
	String^ strExpCode;
	double dblExpAmt;
	String^ strMemo;
	String^ strVehicleID;
};
#endif