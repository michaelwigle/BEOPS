#ifndef BEOPSINVENTORY_H
#define BEOPSINVENTORY_H
#pragma once
#include "time.h"
#include "Inventory.h"

using namespace System::IO;
using namespace System;

public ref class BEOPSInventory: public IComparable //A thing you buy in the store
{
public:
	BEOPSInventory(void);
	BEOPSInventory(Inventory^);
	void Read(StreamReader^);
	void Write(StreamWriter^);
	virtual String^ ToString() override;
	virtual Int32 CompareTo( Object^);

	System::DateTime dteDateRecorded;
	String^ strItemName;
	String^ strVendorName;
	String^ strCategory;
	double dblNumberInCase;
	double dblUnitWholesaleCost;
	double dblUnitRetailValue;
	double dblUnitCount;
};
#endif