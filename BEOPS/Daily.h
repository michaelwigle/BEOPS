#ifndef DAILY_H
#define DAILY_H
#pragma once
#include "time.h"

using namespace System::IO;
using namespace System;

public ref class Daily
{
public:
	Daily(void);
	void Load(array<System::String ^>^);
	double dblRefNum;
	System::DateTime dteDate;
	double dblSales;
	double dblStockPurchased;
	String^ strExpCode1;
	double dblExpAmt1;
	String^ strExpCode2;
	double dblExpAmt2;
	String^ strExpCode3;
	double dblExpAmt3;
	String^ strExpCode4;
	double dblExpAmt4;
	String^ strExpCode5;
	double dblExpAmt5;
	String^ strExpCode6;
	double dblExpAmt6;
	String^ strExpCode7;
	double dblExpAmt7;
	double dblWages;
	double dblDraw;
	double dblServiceCharge;
	double dblTaxLiability;
	double dblOhioLotteryAmt;
	double dblCateringAmt;
	double dblMiscAmt;
	double dblDailyReceipts;

};
#endif
