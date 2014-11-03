#ifndef INITIALVALUES_H
#define INITIALVALUES_H
#pragma once
#include "time.h"

using namespace System::IO;
using namespace System;

public ref class InitialValues
{
public:
	InitialValues(void);
	String^ strOperatorName;
	String^ strOperatorNumber;
	String^ strOperatorAddress1;
	String^ strOperatorAddress2;
	String^ strOperatorCity;
	String^ strOperatorState;
	String^ strOperatorZip;
	
	String^ strBSVIArea;
	String^ strFacilityNumber;
	String^ strFacilityAddress1;
	String^ strFacilityAddress2;
	String^ strFacilityCity;
	String^ strFacilityState;
	String^ strFacilityZip;

	DateTime dteStartDate;
	double dblStartCash;
	double dblInitialInventory;

	void Load(String^);

	
};

#endif
