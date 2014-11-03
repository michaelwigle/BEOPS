#ifndef MONTHLYINVENTORY_H
#define MONTHLYINVENTORY_H
#pragma once
using namespace System;
using namespace System::IO;
public ref class MonthlyInventory
{
public:
	MonthlyInventory(void);
	MonthlyInventory(System::DateTime,double,bool);
	void Write(StreamWriter^);
	void Read(StreamReader^);

	System::DateTime dteMonthYearEnding;
	double dblEndingInventory;
	bool bEstimate;

};

#endif