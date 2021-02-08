#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void letter_grade(int number);
	
int main()
{
	int sum,number,count;
	double average;
	int most_successful,most_unsuccessful;
	int selection;
	int gradeA, gradeB, gradeC, gradeD, gradeF;
	int i;
	int index1,index2;
	
	gradeA = 0;
	gradeB = 0;
	gradeC = 0;
	gradeD = 0;
	gradeF = 0;
	
	
	printf("Enter student count between 3 and 50: "); 
	scanf("%d",&count);
	

	if (0<count && count<3) // Program should say "Not in range" between 0 and 3. So, I used this statement.
	{
		printf("Not in Range!!!\n\a");
	}
	
	else if (count>50) // Program should say "Not in range" over 50. So, I used this statement.
	{
		printf("Not in Range!!!\n\a");
	}

	else 
	{
		srand(time(NULL)); 
		most_successful=0;
		most_unsuccessful=100;
		sum=0;

		for(i=1;i<=count;i++)
		{
			number=rand()%100; 						 // Pragram creates random numbers for student's grades. 
			printf("%d\t",number);
			if(number>most_successful)				 // When the number is bigger than the most successful student's grade's value, number will be equaled the most successfull student's grade's value. 
			{
				most_successful=number; 
				index1=i;								 // The last "i" will be the index value of most succesfull student after these situations.
			}
			
			else if (number<most_unsuccessful)   // When the number is smaller than the most unsuccessful student's grade's value, number will be equaled the most unsuccessfull student's grade's value.  
			{
				most_unsuccessful=number;
				index2=i;							    // The last "i" will be the index value of most succesfull student after these situations.
			}
		
			if (number>=90 && number <=100)
			{
				gradeA++;								//  As taken numbers between 90 and 100, this statement increase the gradeA.This statement find the number of grade A.
			}
			
			else if(number>=80 && number <=89)
			{
				gradeB++;							//  As taken numbers between 80 and 89, this statement increase the gradeA.This statement find the number of grade B.
			}
			
			else if(number>=70 && number <=79)
			{
				gradeC++;								//  As taken numbers between 70 and 79, this statement increase the gradeA.This statement find the number of grade C.
			}	
			
			else if(number>=60 && number <=69)
			{
				gradeD++;							//  As taken numbers between 60 and 69, this statement increase the gradeA.This statement find the number of grade D.
			}
			
			else if(number>=0 && number <=59)
			{
				gradeF++;						  //  As taken numbers below 59, this statement increase the gradeA.This statement find the number of grade F.
			}
			sum=sum+number;
		}
		printf("\n");
		
		do{
		printf("Student Score Calculator Menu for %d Students\n\n",count);
		printf(" 1) Most Successful Student \n");
		printf(" 2) Most Unsuccessful Student \n");
		printf(" 3) Letter Grade Statics \n");
		printf(" 4) Calculate Average \n");
		printf(" 5) Show All Data \n");
		printf("Make Selection :"); scanf("%d",&selection);
		printf("\n");
		
		switch (selection){
		case 1 :
			printf(" Most Successful Student:\n ");
			printf("Index:%d\n",index1);
			printf(" Score:%d\n ",most_successful);
			printf("Letter grade:");		
			letter_grade(most_successful);
			printf("\n\n");
		break;

		case 2 :
			printf(" Most Unsuccessful Student:\n");
			printf(" Index:%d\n",index2);
			printf(" Score:%d\n ",most_unsuccessful);
			printf("Letter grade: ");
			letter_grade(most_unsuccessful);
			printf("\n\n");
		break;

		case 3 :
			printf(" Letter Grade Statics: \n ");
			printf(" %d students got letter grade 'A' \n", gradeA );
			printf(" %d students got letter grade 'B' \n", gradeB );
			printf(" %d students got letter grade 'C' \n", gradeC );
			printf(" %d students got letter grade 'D' \n", gradeD );
			printf(" %d students got letter grade 'F' \n", gradeF );
			
		break;
	
		case 4 :
			average= (double)sum/(double)count;
			printf(" The average Score of %d student is %.2f \n",count,average);
		break;
	
		case 5 :
			printf("Most Successful Student:\n ");
			printf("Index:%d\n",index1);
			printf(" Score:%d\n ",most_successful);
			printf("Letter grade:");		
			letter_grade(most_successful);
			printf("\n\n");
			printf(" Most Unsuccessful Student:\n");
			printf(" Index:%d\n",index2);
			printf(" Score:%d\n ",most_unsuccessful);
			printf("Letter grade: ");
			letter_grade(most_unsuccessful);
			printf("\n\n");
			printf(" %d students got letter grade 'A' \n", gradeA );
			printf(" %d students got letter grade 'B' \n", gradeB );
			printf(" %d students got letter grade 'C' \n", gradeC );
			printf(" %d students got letter grade 'D' \n", gradeD );
			printf(" %d students got letter grade 'F' \n", gradeF );
			printf("\n\n");
			average= (double)sum/(double)count;
			printf(" The average Score of %d student is %.2f \n",count,average);
			printf("\n");
		break;

		case -1 :
			return 0;
			break;
		
		default :	
			printf("False Selection!!\n");  
		break;
		}
		}while(selection!=-1); //Until the pressing '-1', program will work to infinity.
	
	}
	

	printf("\n");
	return 0;
}

	void letter_grade(int number){
		if(number>=90 && number <=100)
		{
			printf("'A'");
		}
		else if(number>=80 && number <=89)
		{
			printf("'B'");
		}
		else if(number>=70 && number <=79)
		{
			printf("'C'");
		}	
		else if(number>=60 && number <=69)
		{
			printf("'D'");
		}
		else
		{
			printf("'F'");
		}
	}




