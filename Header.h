#pragma once
#include <intrin.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <unordered_map>

#define RDTSCP false // assume false.
/*
*/
bool bVendorIntel(void)
{
	int pTempArray[4];
	// Calling __cpuid with 0x0 as the function_id argument
	// gets the number of the highest valid function ID.
	__cpuid(pTempArray, 0);
	if (pTempArray[0] < 0)
		return false;
	// extra info
	__cpuidex(pTempArray, 0, 0);
	// vendor name
	char szVendorName[0x20]; // this block is from microsoft docs
	memset(szVendorName, 0, sizeof(szVendorName));
	*reinterpret_cast<int*>(szVendorName) = pTempArray[1];
	*reinterpret_cast<int*>(szVendorName + 0x4) = pTempArray[3];
	*reinterpret_cast<int*>(szVendorName + 0x8) = pTempArray[2];
	// check the vendor name
	if (strcmp(szVendorName, "GenuineIntel") != 0)
		return false;
	return true;

}
/*
* Function: RDTSCPenabled
* Parameters: void
*
* Purpose: CPU's after 2005-2006 will have RTDSCP functionality (for intel atleast).
*		   We want to ask the CPU for information on itself, we do that using __cpuid, and __cpuidex.
*		   In order to tell if RDTSCP is available we need to check that the CPU is intel
*		   and that the 28th bit of EDX is set to true.
*
* Return: bool
* (true) CPU tells us it does have this feature.
* (false) CPU tells us it does not have this feature.
*/
bool RDTSCPEnabled(void)
{	
	if (!bVendorIntel)
		printf("Setting RDTSCP to false. Reason: Not GenuineIntel\n");
		return false;

	int pTempArray[4];
	// Calling __cpuid with 0x80000000 as the function_id argument
	// gets the number of the highest valid extended ID.
	__cpuid(pTempArray, 0x80000000);

	if (pTempArray[0] < 0x80000001)
		return false;
	// we know that cpuid will return cpuinfo in an array of four ints.
	// the final element in that array is the information returned in EDX
	__cpuidex(pTempArray, 0x80000001, 0);
	return ((pTempArray[3] & 0x8000000) == 0x8000000); // 28th bit
	return false;
}


/**/
class RDTSC
{
public:
	// Constructor
	RDTSC() {
		printf("I am RDTSC");
	}
	
protected:
	unsigned __int64 timer;
	unsigned __int64 time_to_ignore;
};

/**/
class RDTSCP
{
public:
	// Constructor. Do this upon initialization. 
	RDTSCP(){
		printf("I am RDTSCP\n");		
	}


protected:
	unsigned __int64 timer;
	unsigned __int64 time_to_ignore;
};








