#include "StdAfx.h"
#include "BEOPSInventory.h"
#include "BEOPSGlobals.h"

BEOPSInventory::BEOPSInventory(void)
{
	dteDateRecorded = DateTime::Today;
	strItemName = "";
	strVendorName = "";
	strCategory = "";
	dblNumberInCase = 1;
	dblUnitWholesaleCost = 1;
	dblUnitRetailValue = 1;
	dblUnitCount = 1;
}

void BEOPSInventory::Read(StreamReader^ sr)
{
	dteDateRecorded = System::Convert::ToDateTime(sr->ReadLine());
	strItemName = System::Convert::ToString(sr->ReadLine());
	strVendorName = System::Convert::ToString(sr->ReadLine());
	strCategory = System::Convert::ToString(sr->ReadLine());
	dblNumberInCase = System::Convert::ToDouble(sr->ReadLine());
	dblUnitWholesaleCost = System::Convert::ToDouble(sr->ReadLine());
	dblUnitRetailValue = System::Convert::ToDouble(sr->ReadLine());
	dblUnitCount = System::Convert::ToDouble(sr->ReadLine());
}

BEOPSInventory::BEOPSInventory(Inventory^ objNewInventoryItem)
{
	dteDateRecorded = objNewInventoryItem->dteDateRecorded;
	strItemName = objNewInventoryItem->strItemName;
	strVendorName = objNewInventoryItem->strVendorName;
	strCategory = objNewInventoryItem->strCategory;
	dblNumberInCase = objNewInventoryItem->dblNumberInCase;
	dblUnitWholesaleCost = objNewInventoryItem->dblUnitCost;
	dblUnitRetailValue = objNewInventoryItem->dblUnitRetailValue;
	dblUnitCount = objNewInventoryItem->dblUnitCount;

}

void BEOPSInventory::Write(StreamWriter^ sw)
{
	sw->WriteLine(System::Convert::ToString(dteDateRecorded));
	sw->WriteLine(strItemName);
	sw->WriteLine(strVendorName);
	sw->WriteLine(strCategory);
	sw->WriteLine(System::Convert::ToString(dblNumberInCase));
	sw->WriteLine(System::Convert::ToString(dblUnitWholesaleCost));
	sw->WriteLine(System::Convert::ToString(dblUnitRetailValue));
	sw->WriteLine(System::Convert::ToString(dblUnitCount));
}
String^ BEOPSInventory::ToString()
	{
		return strItemName;
	}

Int32 BEOPSInventory::CompareTo( Object^ obj)
{
	if (obj == nullptr) return 1;
	BEOPSInventory^ tmpObj = (BEOPSInventory^)obj;
	return strItemName->CompareTo(tmpObj->strItemName);
}