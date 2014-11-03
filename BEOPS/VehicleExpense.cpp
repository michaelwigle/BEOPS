#include "StdAfx.h"
#include "VehicleExpense.h"
#include "BEOPSGlobals.h"

VehicleExpense::VehicleExpense(void)
{
	dteExpenseDate = DateTime::Today;
	dblGasExpense = 0;
	dblMaintenanceExpense = 0;
	strMaintenancePurveyor = "";
	strMaintenanceDescription = "";
	dblInsuranceExpense = 0;
	dblVehiclePayment = 0;
	dblParkingAndTolls = 0;
	dblRefNum = 0;
	strVehicleID = "";

}

void VehicleExpense::Load(array<System::String ^>^ split)
{
	String^ strTemp;
	array<wchar_t>^ aTrim = {'"'};
	array<wchar_t>^ bTrim = {'$'};

	dteExpenseDate = System::Convert::ToDateTime(String::Copy(split[0]));
	strTemp = String::Copy(split[1]);
	if(strTemp!="")
	dblGasExpense = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[2]);
	if(strTemp!="")
	dblMaintenanceExpense = System::Convert::ToDouble(strTemp);

	strMaintenancePurveyor = String::Copy(split[3]);
	strMaintenancePurveyor = strMaintenancePurveyor->TrimStart(aTrim);
	strMaintenancePurveyor = strMaintenancePurveyor->TrimEnd(aTrim);

	strMaintenanceDescription = String::Copy(split[4]);
	strMaintenanceDescription = strMaintenanceDescription->TrimStart(aTrim);
	strMaintenanceDescription = strMaintenanceDescription->TrimEnd(aTrim);

	strTemp = String::Copy(split[5]);
	if(strTemp!="")
	dblInsuranceExpense = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[6]);
	if(strTemp!="")
	dblVehiclePayment = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[7]);
	if(strTemp!="")
	dblParkingAndTolls = System::Convert::ToDouble(strTemp);

	strTemp = String::Copy(split[8]);
	if(strTemp!="")
	dblRefNum = System::Convert::ToDouble(strTemp);

	strVehicleID = String::Copy(split[9]);
	strVehicleID = strVehicleID->TrimStart(aTrim);
	strVehicleID = strVehicleID->TrimEnd(aTrim);
}

void VehicleExpense::Write(StreamWriter^ sw)
{
	sw->WriteLine(System::Convert::ToString(dteExpenseDate));
	sw->WriteLine(System::Convert::ToString(dblGasExpense));
	sw->WriteLine(System::Convert::ToString(dblMaintenanceExpense));
	sw->WriteLine(strMaintenancePurveyor);
	sw->WriteLine(strMaintenanceDescription);
	sw->WriteLine(System::Convert::ToString(dblInsuranceExpense));
	sw->WriteLine(System::Convert::ToString(dblVehiclePayment));
	sw->WriteLine(System::Convert::ToString(dblParkingAndTolls));
	sw->WriteLine(System::Convert::ToString(dblRefNum));
	sw->WriteLine(strVehicleID);
}
void VehicleExpense::Read(StreamReader^ sr)
{
	dteExpenseDate = System::Convert::ToDateTime(sr->ReadLine());
	dblGasExpense = System::Convert::ToDouble(sr->ReadLine());
	dblMaintenanceExpense = System::Convert::ToDouble(sr->ReadLine());
	strMaintenancePurveyor = System::Convert::ToString(sr->ReadLine());
	strMaintenanceDescription = System::Convert::ToString(sr->ReadLine());
	dblInsuranceExpense = System::Convert::ToDouble(sr->ReadLine());
	dblVehiclePayment = System::Convert::ToDouble(sr->ReadLine());
	dblParkingAndTolls = System::Convert::ToDouble(sr->ReadLine());
	dblRefNum = System::Convert::ToDouble(sr->ReadLine());
	strVehicleID = System::Convert::ToString(sr->ReadLine());
}