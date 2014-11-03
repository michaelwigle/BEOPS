#include "StdAfx.h"
#include "Inventory.h"
#include "BEOPSGlobals.h"

Inventory::Inventory(void)
{
	dteDateRecorded = DateTime::Today;
	strItemName = "";
	dblUnitCount = 0;
	strVendorName = "";
	strCategory = "";
	dblCaseCost = 0;
	dblNumberInCase = 0;
	dblUnitCost = 0;
	dblWholesaleCost = 0;
	dblUnitRetailValue = 0;
}

void Inventory::Load(array<System::String ^>^ split)
{
	String^ strTemp;
	array<wchar_t>^ aTrim = {'"'};
	array<wchar_t>^ bTrim = {'$'};

	dteDateRecorded = System::Convert::ToDateTime(String::Copy(split[0]));
	strItemName = String::Copy(split[1]);
	strItemName = strItemName->TrimStart(aTrim);
	strItemName = strItemName->TrimEnd(aTrim);

	strTemp = String::Copy(split[2]);
	if(strTemp!="")
	dblUnitCount = System::Convert::ToDouble(strTemp);

	strVendorName = String::Copy(split[3]);
	strVendorName = strVendorName->TrimStart(aTrim);
	strVendorName = strVendorName->TrimEnd(aTrim);

	strCategory = String::Copy(split[4]);
	strCategory = strCategory->TrimStart(aTrim);
	strCategory = strCategory->TrimEnd(aTrim);

	strTemp = String::Copy(split[5]);
	if(strTemp!="")
	dblCaseCost = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[6]);
	if(strTemp!="")
	dblNumberInCase = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[7]);
	if(strTemp!="")
	dblUnitCost = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[8]);
	if(strTemp!="")
	dblWholesaleCost = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[9]);
	if(strTemp!="")
	dblUnitRetailValue = System::Convert::ToDouble(strTemp);

	//This code will correct missing values in reading from the backup inventory file
	dblUnitCost = dblCaseCost/dblNumberInCase;
	dblWholesaleCost = dblUnitCost*dblUnitCount;
}
