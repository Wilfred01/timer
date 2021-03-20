/*
	The goal? Make a program that can tell how many CPU clock cycles some operation takes. 

	Why is it useful? I can objectively say to someone no this way is faster. Additionally, the program may be used to
	determine if it is being run on a bare metal or hosted VM or not.

	How? using intrinsics and logic.
	
	TASKS:
	Learn about Intrinsics:
		Learn about __rdtsc
		Learn about __rtdscp
		Learn about __cpuid, __cpuidex
		Learn about the intrin.h library
		Learn about the Intel CPU architecture.
		Learn faster implementations.
	Refresh on classes in c.
			

	Resources: 
	https://docs.microsoft.com/en-us/cpp/intrinsics/rdtsc?view=msvc-160
	https://docs.microsoft.com/en-us/cpp/intrinsics/rdtscp?view=msvc-160
	https://docs.microsoft.com/en-us/cpp/intrinsics/cpuid-cpuidex?view=msvc-160
	https://stackoverflow.com/questions/59759596/is-there-any-difference-in-between-rdtsc-lfence-rdtsc-and-rdtsc-rdtscp

*/

#include "Header.h"

int main() {

	if (bVendorIntel() & RDTSCPEnabled())
	{
		printf("Vendor Genuine Intel\nRDTSCP is enabled...\n");
		RDTSCP rtdscp;
	}
	else
	{
		printf("RTDSC is enabled...\n");
		RDTSC rdtsc;
	}
	


	return 0;
}
