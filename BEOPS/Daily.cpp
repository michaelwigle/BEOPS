#include "StdAfx.h"
#include "Daily.h"
#include "BEOPSGlobals.h"

Daily::Daily(void)
{
	dblRefNum=0;
	dteDate=DateTime::Today;
	dblSales=0;
	dblStockPurchased=0;
	strExpCode1="";
	dblExpAmt1=0;
	strExpCode2="";
	dblExpAmt2=0;
	strExpCode3="";
	dblExpAmt3=0;
	strExpCode4="";
	dblExpAmt4=0;
	strExpCode5="";
	dblExpAmt5=0;
	strExpCode6="";
	dblExpAmt6=0;
	strExpCode7="";
	dblExpAmt7=0;
	dblWages=0;
	dblDraw=0;
	dblServiceCharge=0;
	dblTaxLiability=0;
	dblOhioLotteryAmt=0;
	dblCateringAmt=0;
	dblMiscAmt=0;
	dblDailyReceipts=0;
}
void Daily::Load(array<System::String ^>^ split)
{
	String^ strTemp;
	array<wchar_t>^ aTrim = {'"'};
	array<wchar_t>^ bTrim = {'$'};

	strTemp = String::Copy(split[0]);
	dblRefNum = System::Convert::ToDouble(strTemp);


	//First step is to split out the date string and store it in a System::String

	dteDate = System::Convert::ToDateTime(String::Copy(split[1]));
	strTemp = String::Copy(split[2]);
	strTemp = strTemp->TrimStart(bTrim);
	dblSales = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[3]);
	strTemp = strTemp->TrimStart(bTrim);
	dblStockPurchased = System::Convert::ToDouble(strTemp);

	strExpCode1 = String::Copy(split[4]);
	strExpCode1 = strExpCode1->TrimStart(aTrim);
	strExpCode1 = strExpCode1->TrimEnd(aTrim);

	strTemp = String::Copy(split[5]);
	strTemp = strTemp->TrimStart(bTrim);
	dblExpAmt1 = System::Convert::ToDouble(strTemp);

	strExpCode2 = String::Copy(split[6]);
	strExpCode2 = strExpCode2->TrimStart(aTrim);
	strExpCode2 = strExpCode2->TrimEnd(aTrim);

	strTemp = String::Copy(split[7]);
	strTemp = strTemp->TrimStart(bTrim);
	dblExpAmt2 = System::Convert::ToDouble(strTemp);

	strExpCode3 = String::Copy(split[8]);
	strExpCode3 = strExpCode3->TrimStart(aTrim);
	strExpCode3 = strExpCode3->TrimEnd(aTrim);

	strTemp = String::Copy(split[9]);
	strTemp = strTemp->TrimStart(bTrim);
	dblExpAmt3 = System::Convert::ToDouble(strTemp);

	strExpCode4 = String::Copy(split[10]);
	strExpCode4 = strExpCode4->TrimStart(aTrim);
	strExpCode4 = strExpCode4->TrimEnd(aTrim);

	strTemp = String::Copy(split[11]);
	strTemp = strTemp->TrimStart(bTrim);
	dblExpAmt4 = System::Convert::ToDouble(strTemp);

	strExpCode5 = String::Copy(split[12]);
	strExpCode5 = strExpCode5->TrimStart(aTrim);
	strExpCode5 = strExpCode5->TrimEnd(aTrim);

	strTemp = String::Copy(split[13]);
	strTemp = strTemp->TrimStart(bTrim);
	dblExpAmt5 = System::Convert::ToDouble(strTemp);

	strExpCode6 = String::Copy(split[14]);
	strExpCode6 = strExpCode6->TrimStart(aTrim);
	strExpCode6 = strExpCode6->TrimEnd(aTrim);

	strTemp = String::Copy(split[15]);
	strTemp = strTemp->TrimStart(bTrim);
	dblExpAmt6 = System::Convert::ToDouble(strTemp);

	strExpCode7 = String::Copy(split[16]);
	strExpCode7 = strExpCode7->TrimStart(aTrim);
	strExpCode7 = strExpCode7->TrimEnd(aTrim);

	strTemp = String::Copy(split[17]);
	strTemp = strTemp->TrimStart(bTrim);
	dblExpAmt7 = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[18]);
	strTemp = strTemp->TrimStart(bTrim);
	dblWages = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[19]);
	strTemp = strTemp->TrimStart(bTrim);
	dblDraw = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[20]);
	strTemp = strTemp->TrimStart(bTrim);
	dblServiceCharge = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[21]);
	strTemp = strTemp->TrimStart(bTrim);
	dblTaxLiability = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[22]);
	strTemp = strTemp->TrimStart(bTrim);
	dblOhioLotteryAmt = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[23]);
	strTemp = strTemp->TrimStart(bTrim);
	dblCateringAmt = System::Convert::ToDouble(strTemp);
	
	strTemp = String::Copy(split[24]);
	strTemp = strTemp->TrimStart(bTrim);
	dblMiscAmt = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[25]);
	strTemp = strTemp->TrimStart(bTrim);
	dblDailyReceipts = System::Convert::ToDouble(strTemp);

}