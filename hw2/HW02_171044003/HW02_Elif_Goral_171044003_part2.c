#include <stdio.h>


int find_digit(int number);

int main()
{	
		int number,i;
		printf("Enter the number between 23 and 98760:  "); scanf("%d",&number);
		
		int a=find_digit(number);
	
		if(23<=number && number<=98760)
		{
				do{
						for(i=1;i<=a;i++)
						{
							printf("%d th digit is %d\n",i,number%10);
							number=number/10;
						}
				}while(number>0);	
		}
		else
		{
			printf("Enter the number between 23 and 98760:");
		}
		return 0;
}


		int find_digit(int number){
		// finding digit numbers.
		int digit=0;
		do{
			number=number/10;	
			digit++;
		
		} while(number>=1); // Due to (number>=1) is number's final state has one digit. If first number start with '1', number's last rest digit will be 1.
		return digit;
		}
