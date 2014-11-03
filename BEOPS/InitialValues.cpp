#include "StdAfx.h"
#include "InitialValues.h"
#include "BEOPSGlobals.h"

InitialValues::InitialValues(void)
{
	strOperatorName = "";
	strOperatorNumber = "";
	strOperatorAddress1 = "";
	strOperatorAddress2 = "";
	strOperatorCity = "";
	strOperatorState = "";
	strOperatorZip = "";
	
	strBSVIArea = "";
	strFacilityNumber = "";
	strFacilityAddress1 = "";
	strFacilityAddress2 = "";
	strFacilityCity = "";
	strFacilityState = "";
	strFacilityZip = "";

	dteStartDate = DateTime::Today;
	dblStartCash = 0;
	dblInitialInventory = 0;

}
void InitialValues::Load(String^ strTmpFileName)
{
	try
	{
		// Create an instance of StreamReader to read from a file.
		// The using statement also closes the StreamReader.
		StreamReader^ sr = gcnew StreamReader(strTmpFileName);
		String^ line;
		int nLineNumber = 0;
		array<wchar_t>^ aTrim = {'"'};

		// Read and display lines from the file until the end of
		// the file is reached.
		while ((line = sr->ReadLine()) != nullptr)
		{
			nLineNumber++;	
			if (nLineNumber==2)
			{
				//Seperate the data into the object
				array<System::String ^>^ split = line->Split(',');

				//Trim and copy the data into each field
				strOperatorName = String::Copy(split[0]);
				strOperatorName = strOperatorName->TrimStart(aTrim);
				strOperatorName = strOperatorName->TrimEnd(aTrim);
				BEOPSGlobals::datBEOPSData->strOperatorName = strOperatorName;

				strOperatorNumber = String::Copy(split[1]);
				strOperatorNumber = strOperatorNumber->TrimStart(aTrim);
				strOperatorNumber = strOperatorNumber->TrimEnd(aTrim);
				BEOPSGlobals::datBEOPSData->strOperatorNumber = strOperatorNumber;

				strBSVIArea = String::Copy(split[2]);
				strBSVIArea = strBSVIArea->TrimStart(aTrim);
				strBSVIArea = strBSVIArea->TrimEnd(aTrim);
				BEOPSGlobals::datBEOPSData->strBSVIArea = strBSVIArea;

				strOperatorAddress1 = String::Copy(split[3]);
				strOperatorAddress1 = strOperatorAddress1->TrimStart(aTrim);
				strOperatorAddress1 = strOperatorAddress1->TrimEnd(aTrim);
				BEOPSGlobals::datBEOPSData->strOperatorAddress1 = strOperatorAddress1;

				strOperatorAddress2 = String::Copy(split[4]);
				strOperatorAddress2 = strOperatorAddress2->TrimStart(aTrim);
				strOperatorAddress2 = strOperatorAddress2->TrimEnd(aTrim);
				BEOPSGlobals::datBEOPSData->strOperatorAddress2 = strOperatorAddress2;

				strOperatorCity = String::Copy(split[5]);
				strOperatorCity = strOperatorCity->TrimStart(aTrim);
				strOperatorCity = strOperatorCity->TrimEnd(aTrim);
				BEOPSGlobals::datBEOPSData->strOperatorCity = strOperatorCity;

				strOperatorState = String::Copy(split[6]);
				strOperatorState = strOperatorState->TrimStart(aTrim);
				strOperatorState = strOperatorState->TrimEnd(aTrim);
				BEOPSGlobals::datBEOPSData->strOperatorState = strOperatorState;

				strOperatorZip = String::Copy(split[7]);
				strOperatorZip = strOperatorZip->TrimStart(aTrim);
				strOperatorZip = strOperatorZip->TrimEnd(aTrim);
				BEOPSGlobals::datBEOPSData->strOperatorZip = strOperatorZip;

				strFacilityNumber = String::Copy(split[8]);
				strFacilityNumber = strFacilityNumber->TrimStart(aTrim);
				strFacilityNumber = strFacilityNumber->TrimEnd(aTrim);
				BEOPSGlobals::datBEOPSData->strFacilityNumber = strFacilityNumber;


				//First step is to split out the date string and store it in a System::String

				dteStartDate = System::Convert::ToDateTime(String::Copy(split[9]));

				String^ strTemp = String::Copy(split[10]);
				dblStartCash = System::Convert::ToDouble(strTemp);
				BEOPSGlobals::datBEOPSData->dblStartCash = dblStartCash;

				strTemp = String::Copy(split[11]);
				dblInitialInventory = System::Convert::ToDouble(strTemp);
				BEOPSGlobals::datBEOPSData->dblAlternateInventory = dblInitialInventory;
				
			}
		}
		sr->Close();
	}
	catch (Exception^ e)
	{
		// Let the user know what went wrong.
		Console::WriteLine("The file could not be read:");
		Console::WriteLine(e->Message);
	}
}						
				