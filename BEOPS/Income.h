#ifndef INCOME_H
#define INCOME_H
#pragma once

using namespace System::IO;
using namespace System;

public ref class Income
{
public:
	Income(void);
	Income(String^,double,String^);
	void Load(void);
	void Write(StreamWriter^);
	void Read(StreamReader^);

	String^ strIncomeName;
	double dblIncomeAmt;
	String^ strMemo;
};
#endif