#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void menu();
void triangleOfSequences();
int find_digit(int number);
void countOccurrence();
int getInt(int mini,int maxi);
int numberGeneratorBetweenRange(int min,int max);
void horseRacingGame();


int main()
{
	srand(time(NULL));
	menu();
	return 0;
}

void menu() //After menu function runs and finish the function, menu function comes again until pressing '0'.  Except pressing 0,1,2,3, menu will shown again.
{
int selection;
	do
	{
		printf("Enter a choise number : \n");
		printf("1.Horse Racing Game\n");
		printf("2.Occurence Counter\n");
		printf("3.Triangle of Sequences\n");
		printf("0.Exit\n");
		scanf("%d",&selection);
		
		switch(selection){
			case 1 : 
				horseRacingGame();
				break;
				
			case 2 : 
				countOccurrence();
				printf("\n");
				break;
				
			case 3 :
				triangleOfSequences();
				printf("\n");
				break;
		}
	}while(selection!=0);	
}

void triangleOfSequences() // This functions generates a number between 2 and 10. After generating number, runs the program.
{
	int number=2+rand()%9;
	int i,j;
	printf("For %d\n",number);
	for(i=1;i<=number;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d\t",i*j);	
		}
		printf("\n");
	}
	
}

void countOccurrence()
{

	int BigNumber,SearchNumber;
	int Occurrence=0;
	int x=1;
	int i;
	int value;
	
	printf("BigNumber:"); scanf("%d",&BigNumber);
	printf("SearchNumber:"); scanf("%d",&SearchNumber);

	value=find_digit(SearchNumber); //That finds the digit of SearchNumber.---search number ın kaç basamaklı olduğunu buluyor.
	
	for(i=1;i<=value;i++)
	{
		x=x*10;
	}
	
	while(BigNumber>=1)
	{
		if((BigNumber%x)==SearchNumber && BigNumber>=1)
		{
			BigNumber=BigNumber/10;
			Occurrence++;
		}
		else
		{
			BigNumber=BigNumber/10;
		}
	}
	printf("Occurrence:%d\n",Occurrence);

}

int find_digit(int number) // This function finds the number of digit.
{
	int digit=0;
	do{
	number=number/10;
	digit++;	
	}while(number>=1);
	
	return digit;
}

int getInt(int mini,int maxi) //This function takes a number and control the borders. If a number unsuitable to borders, this function will run untill it will suitable.
{
	int x;
	do{
	printf("Horse Number:"); scanf("%d",&x);
	}while(x<mini || x>maxi);
	return x;
}

int numberGeneratorBetweenRange(int min,int max) // This function generates a random number between the borders.(include borders)
{
	int rand_number=min+rand()%(max-min+1);
	return rand_number;
}

void horseRacingGame() // This function generates a number between 3 and 5 with using numbergeneratorbetweenrange funciton. After that, it ask us a horse number which we want. Every horse go units which are generated randomly between 10 and 20. This function find the winner horse.
{
	int horse1;
	int i;
	int winner_horse;
	int winner=20;
	int number_of_horse=numberGeneratorBetweenRange(3,5);
	printf("Number of horse:%d\n",number_of_horse);
	int horse_number=getInt(1,number_of_horse);
	
	for( i=1;i<=number_of_horse;i++)
	{	
		int j;
		horse1=numberGeneratorBetweenRange(10,20);
		for(j=1;j<=horse1;j++)
		{
			printf("-");
		}
		printf("\n");
	
		if (horse1<winner)
		{
			winner=horse1;
			winner_horse=i;
		}
	}
	
	if(horse_number==winner_horse)
		printf("You win!  "); 
	
	else 
		printf("You lose!  ");

	printf("Winner is Horse %d\n",winner_horse);
	
}

























