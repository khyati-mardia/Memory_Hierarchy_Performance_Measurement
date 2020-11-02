/*
 * LinearWrite4.c


 *
 *  Created on: Jan 28, 2019
 *      Author: khyati
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char **argv)
{
	long l1_cache_linesize;
	long l1_cache_size;

	l1_cache_linesize = sysconf(_SC_LEVEL1_DCACHE_LINESIZE); //To calculate L1 cache line size
	l1_cache_size = sysconf(_SC_LEVEL1_DCACHE_SIZE);

	struct array {
		char arrayElement[l1_cache_linesize]; //Array of a structure
	};

	int i, j;
	long long n = 0; //Number of Array Size

	n = atoll(argv[1]);

	struct array a[n];

	if(n<1){
		printf("Invalid input.The array size must be greater or equal to 1. \n"); //Invalid input
		return 0;
	}

	//To warm up the cache
	for (j = 0; j < n; j++)
	{
		a[j].arrayElement[0] =0;
	}

	//Commenting the complete for loop to find time
	/*// Iterate through all elements and write to the Array Elements
		for(i=0; i<2000000; i++) ////to get average time more accurate
		{
			for (j = 0; j < n; j++)
			{
				a[j].arrayElement[0]+=a[j].arrayElement[0]; //writing to the Array
			}
		}*/

	return 0;
}



