#include <stdio.h>

//void find_month(int *month);
int convert_func(int *day,int *month, int *year,int *day_1, int *month_1, int *year_1);
//void find_day(int *day_code,int *day,int *month, int *year,int *day_1, int *month_1, int *year_1);
//int find_month_code(int *month);


int main()
{
	int day_1,month_1,year_1,day,month,year;
	convert_func(&day,&month,&year,&day_1,&month_1,&year_1);
	return 0;
}

int convert_func(int *day,int *month, int *year,int *day_1, int *month_1, int *year_1)
{
	char tire;
	int day_code;
	printf("Start Date:"); scanf("%d%c%d%c%d",day,&tire,month,&tire,year);
	printf("End Date:"); scanf("%d%c%d%c%d",day_1,&tire,month_1,&tire,year_1);
	
	int i,j,k,a,b,c,d,e;
	
	FILE *file=fopen("input_date.txt","w");
	//FILE *file1=fopen("new_date.txt","w");
		
		if((*month)==4 || (*month)==6 || (*month)==9 || (*month)==11) //this loop is complete the start date of the month till the end of the month. For example start day is 12 may.this loop writes 12-13......31 may.
		{
				for(e=(*day);e<=30;e++)
				{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",e,(*month),(*year));
				}
			}
			
			else if((*month)==2)
			{
				if((*year%4)==0)
				{
					for(e=(*day);e<=29;e++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",e,(*month),(*year));
					}
				}
				else
				{
					for(e=(*day);e<=28;e++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",e,(*month),(*year));
					}
				}
			}
			else 
			{
				for(e=(*day);e<=31;e++)
				{
				//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",e,(*month),(*year));
				}
			}
	
	for(a=((*month)+1);a<=12;a++) //başladığı yılın sonuna kadar gidiyor(ortadan başladığı için yaptım) (o ay dahil değil) // this loop includes the rest of months except the started month on started year.
	{
	
		if(a==4 || a==6 || a==9 || a==11){
				for(b=1;b<=30;b++)
				{
				//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",b,a,(*year));
				}
			}
			
			else if(a==2)
			{
				if((*year%4)==0)
				{
					for(b=1;b<=29;b++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",b,a,(*year));
					}
				}
				else
				{
					for(b=1;b<=28;b++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",b,a,(*year));
					}
				}
			}
			else 
			{
				for(b=1;b<=31;b++)
				{
				//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",b,a,(*year));
				}
			}
	}
	
	for(i=((*year)+1);i<(*(year_1));i++) // arada geçen tam yıllar için //this loop is for full years between dates.
	{
		for(j=1;j<=12;j++)
		{
			if(j==4 || j==6 || j==9 || j==11){
				for(k=1;k<=30;k++)
				{
				//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",k,j,i);
				}
			}
			
			else if(j==2)
			{
				if((*year%4)==0)
				{
					for(k=1;k<=29;k++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",k,j,i);
					}
				}
				else
				{
					for(k=1;k<=28;k++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",k,j,i);
					}
				}
			}
			else 
			{
				for(k=1;k<=31;k++)
				{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",k,j,i);
				}
			}
			
		}
	}
	
	for(c=1;c<(*(month_1));c++) //son yılın bitmesini istediğimiz ayına kadar yapıyor // this loop writes until the last month except the last month on last year.
	{
		if(c==4 || c==6 || c==9 || c==11){
				for(d=1;d<=30;d++)
				{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",d,c,(*(year_1)));
				}
			}
			
			else if(c==2)
			{
				if((*year%4)==0)
				{
					for(d=1;d<=29;d++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",d,c,(*(year_1)));
					}
				}
				else
				{
					for(d=1;d<=28;d++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",d,c,(*(year_1)));
					}
				}
			}
			else 
			{
				for(d=1;d<=31;d++)
				{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",d,c,(*(year_1)));
				}
			}
		}
		
		
			if((*(month_1))==4 || ((*month_1))==6 || (*(month_1))==9 || (*(month_1))==11) //bittiği yılın son ayının son gününe kadar yazar. // this loop writes the days on the last month and last year.
			{
				for(e=1;e<=(*(day_1));e++)
				{
				//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",e,(*(month_1)),(*(year_1)));
				}
			}
			
			else if((*(month_1))==2)
			{
				if(((*(year_1))%4)==0)
				{
					for(e=1;e<=(*(day_1));e++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",e,(*(month_1)),(*(year_1)));
					}
				}
				else
				{
					for(e=1;e<=(*(day_1));e++)
					{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
						fprintf(file,"%d/%d/%d\n",e,(*(month_1)),(*(year_1)));
					}
				}
			}
			else 
			{
				for(e=1;e<=(*(day_1));e++)
				{
					//find_day(&day_code,day,month,year,day_1,month_1,year_1);
					//find_month(month);
					//fprintf(file1,"%d/%d/%d\n",e,(*month),(*year));
					fprintf(file,"%d/%d/%d\n",e,(*(month_1)),(*(year_1)));
				}
			}
		fclose(file);
		//fclose(file1);
				
	
	return 0;
}
// these comment lines which are written below are working but I couldn't write to new_date file. These codes are working with printf instead of fprintf.
/*
void find_day(int *day_code,int *day,int *month, int *year,int *day_1, int *month_1, int *year_1)// hangi tarihin hangi güne denk geldiğini buluyor. // that finds the which date corresponds to which day.
{
	FILE *file1=fopen("new_date.txt","w");
	int date_code,year_code,month_code;

	//formul:(tarih_kodu%7)+(ay_kodu)+(yıl_kodu%7)+((yıl/4)%7)= (gün_kodu)
	// örnek: 29 ekim 1923
	// tarih kodu: 29
	// ay kodu=1
	// yıl kodu=1923-1900=23
	// (yıl/4)%7= (23/4)%7=5%7=5
	// eğer 7 den büyükse 7-çıkan sonuç yaparız.
	
	month_code=find_month_code(month);
	date_code=*day;
	year_code=(*year)-1900;

	*day_code=((date_code%7)+(month_code)+(year_code%7)+((year_code/4)%7))%7;

	//printf("day code:%d",*day_code);

	switch(*day_code)
	{
		case 1:
			fprintf(file1,"Sunday,");
			//printf("Sunday");
			break;
		
		case 2:
			fprintf(file1,"Monday,");
			//printf("Monday");
			break;
			
		case 3:
			fprintf(file1,"Tuesday,");
			//printf("Tuesday");
			break;
			
		case 4:
			fprintf(file1,"Wednesdsay,");			
			//printf("Wednesday");
			break;
			
		case 5:
			fprintf(file1,"Thursday,");
			//printf("Thursay");
			break;
		
		case 6:
			fprintf(file1,"Friday,");
			//printf("Friday");
			break;
		
		case 7:
			fprintf(file1,"Saturday,");
			//printf("Saturday");
			break;
		
		case 0:
			fprintf(file1,"Saturday,");
			//printf("Saturday");
			break;	

	}
	fclose(file1);
}

void find_month(int *month)// new_date dosyası için ay adını yazıyor.//this writes a  month name for new_date file.
{
	FILE *file1=fopen("new_date.txt","w");
	
	switch(*month)
	{
		case 1:
			fprintf(file1,"January");
			break;
		
		case 2:
			fprintf(file1,"February");
			break;
			
		case 3:
			fprintf(file1,"March");
			break;
			
		case 4:
			fprintf(file1,"April");
			break;
			
		case 5:
			fprintf(file1,"May");
			break;
		
		case 6:
			fprintf(file1,"June");
			break;
		
		case 7:
			fprintf(file1,"July");
			break;
			
		case 8:
			fprintf(file1,"August");
			break;
		
		case 9:
			fprintf(file1,"September");
			break;
		
		case 10:
			fprintf(file1,"October");
			break;
		
		case 11:
			fprintf(file1,"November");
			break;
		
		case 12:
			fprintf(file1,"December");
				break;
		}
			fclose(file1);	
}

int find_month_code(int *month)// hangi güne denk geldiğini bulmak için kullandığımız month code u buluyor. //This finds the month code for the find which date corresponds to which day.
{
	int month_code;
	switch(*month)
	{
		case 1:
			month_code=1;
			break;
		
		case 2:
			month_code=4;
			break;
			
		case 3:
			month_code=4;
			break;
			
		case 4:
			month_code=7;
			break;
			
		case 5:
			month_code=2;
			break;
		
		case 6:
			month_code=5;
			break;
		
		case 7:
			month_code=7;
			break;
			
		case 8:
			month_code=3;
			break;
		
		case 9:
			month_code=6;
			break;
		
		case 10:
			month_code=1;
			break;
		
		case 11:
			month_code=4;
			break;
		
		case 12:
			month_code=6;
			break;
		}

	return month_code;

}
*/
