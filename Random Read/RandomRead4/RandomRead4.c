/*
 * RandomRead4.c


 *
 *  Created on: Jan 29, 2019
 *      Author: khyati
 */


#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

uint64_t* generate_random_list(int elements) //Random Number generator
{
  uint64_t* list = (uint64_t*) malloc(sizeof(uint64_t) * elements);

  int i;
  for(i = 0; i < elements; i++) list[i] = rand() % elements;

  return list;
}

int main(int argc, char **argv)
{
	long l1_cache_linesize;
	long l1_cache_size;

	l1_cache_linesize = sysconf(_SC_LEVEL1_DCACHE_LINESIZE); //To calculate L1 cache line size
	l1_cache_size = sysconf(_SC_LEVEL1_DCACHE_SIZE);

	int size=sizeof(double);
	int l1_cache_elements=l1_cache_linesize/size; //Conversion

	typedef struct array {
		double arrayElement[l1_cache_elements]; //Array of a structure
	}array;

	long long n = 0; //Number of Array Size
	n = atoll(argv[1]);

	array a[n];
	array *pointer[n];

	if(n<1){
		printf("Invalid input.The array size must be greater or equal to 1.Program will terminate\n"); //Invalid input
		return 0;
	}

	register long long result=0; //Result is declared as register to avoid copying data in cache

	srand(time(0)); //Random number generator function initialization

	int i,j,k,l =0;
	int r = 0;

	for(i=0;i<n;i++) //Warm-up the cache
	{
		a[i].arrayElement[1]=i;

	}

	for(j=0;j<n;j++){
		pointer[j]=( array *)malloc(sizeof(array)); //Allocation for memory for random access
		pointer[j]->arrayElement[1]=0;
	}

	uint64_t* random_list = generate_random_list(n); //Generating random numbers

	//Commenting the complete for loop to find time
	/*// Iterate through all elements and store in the variable - Reading all elements of array randomly
	for(k=0;k<2000000;k++) //to get average time more accurate
	{
		for(l=0;l<n;l++)
		{
			result += pointer[l]->arrayElement[1];  //randomly generated locations stored in a variable
		}
	}*/

	printf("result = %lld\n",result);

	return 0;
}
