#include <stdio.h>

void menu();
int find_size_of_line(char line[]);
void reverse_line(char line[],int line_lenght);
void encrypy_open_msg(char line[],int line_lenght);

int main()
{
	
	//char text[]="elif";
	char text;
	int lenght;
	// these four lines below  work seperately but they don't work together.
	//menu(); 
	//printf("%s\n",text); 
	//printf("%d\n",find_size_of_line(text));
	//reverse_line(text,lenght);
	
	encrypy_open_msg(&text,lenght);
	return 0;
}


void menu()
{
	int choice;	
	printf("1. Encrypt\n2. Decrypt\n0. Exit\nChoice:");
	scanf("%d",&choice);
	
	do{
		switch(choice){
			case 1:
			
				break;
			
			case 2:
				
				break;
			
			case 0:
				break;
			}
	}while(choice!=0);

}

int find_size_of_line(char line[])
{
	int size;
	for(size=0;line[size]!='\0';++size)
	{
	}
	return size;
}


void reverse_line(char line[],int line_lenght)
{
	int i;
	char copy[line_lenght];
	line_lenght=find_size_of_line(line);
	for(i=0;line[i]!='\0';i++)
	{	
		copy[line_lenght-1]=line[i];
		line_lenght--;
	}
	printf("%s ",copy);
}


void encrypy_open_msg(char line[],int line_lenght) // when I use reverse_line function, after the first line program takes the lenght of line for "universitesi" word. I couldn't fix it.
{
	FILE *file=fopen("open_msg.txt","r");
	int i;
	while(fscanf(file,"%s",line)!=EOF)
	{
		printf("%s ",line);
		//reverse_line(line,line_lenght);
		for(i=0;i<find_size_of_line(line);++i)
		{
			if(line[i]=='.')
			{
				printf("\n");
			}
		}
	}
}


