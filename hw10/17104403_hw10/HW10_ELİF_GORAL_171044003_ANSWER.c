#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct Node {  int data;
							  struct Node *next;
						  }	node;

int read_func(FILE*file);
int isPrime(int number);
void find_primes(int *arr,int *arrPrime);

int main()
{
	time_t start,end;
	time(&start);
	FILE *file;

	file=fopen("data.txt","r");
	int *arr=(int*)malloc(sizeof(int)*1000000);
	int *arrPrime=(int*)malloc(sizeof(int)*1000000);
	
	int i;
	for(i=0;i<1000000;i++)
	{
		arr[i]=read_func(file);
	}
	find_primes(arr,arrPrime);
	time(&end);
	printf("time : %.2lf sn",difftime(end,start));
	fclose(file);
	return 0;
}

int read_func(FILE *file)
{
	int number;
	fscanf(file,"%d,00",&number);

	return number;
}

void find_primes(int *arr,int *arrPrime)
{
	FILE *file1=fopen("output_prime_dynamic_array.txt","w");
	int i,k=0;
	for(i=0;i<1000000;i++)
	{
		if(isPrime(arr[i])==1)
		{
			arrPrime[k]=arr[i];
			printf("%d. prime:%d \n",k,arrPrime[k]);
			fprintf(file1,"%d. prime: %d",k,arrPrime[k]);
			k++;
		}
	}
	fclose(file1);
}

int isPrime(int number)
{
	int i,j;
	for(i=0;i<1000000;i++)
	{
		if(number<2)
			return 0;
		
		else if(number==2)
			return 1;
		
		for(j=3;j<number;j++)
		{
			if(number%j==0)
				return 0;		
		}
		return 1;
	}
}

