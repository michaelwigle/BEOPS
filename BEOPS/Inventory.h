#ifndef INVENTORY_H
#define INVENTORY_H
#pragma once
#include "time.h"

using namespace System::IO;
using namespace System;

public ref class Inventory
{
public:
	Inventory(void);
	void Load(array<System::String ^>^);

	DateTime dteDateRecorded;
	String^ strItemName;
	double dblUnitCount;
	String^ strVendorName;
	String^ strCategory;
	double dblCaseCost;
	double dblNumberInCase;
	double dblUnitCost;
	double dblWholesaleCost;
	double dblUnitRetailValue;
};
#endif