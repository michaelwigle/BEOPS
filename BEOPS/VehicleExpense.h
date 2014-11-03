#ifndef VEHICLE_EXPENSE_H
#define VEHICLE_EXPENSE_H
#pragma once
#include "time.h"

using namespace System::IO;
using namespace System;

public ref class VehicleExpense
{
public:
	VehicleExpense(void);
	void Load(array<System::String ^>^);
	void Write(StreamWriter^);
	void Read(StreamReader^);

	DateTime dteExpenseDate;
	double dblGasExpense;
	double dblMaintenanceExpense;
	String^ strMaintenancePurveyor;
	String^ strMaintenanceDescription;
	double dblInsuranceExpense;
	double dblVehiclePayment;
	double dblParkingAndTolls;
	double dblRefNum;
	String^ strVehicleID;
};
#endif