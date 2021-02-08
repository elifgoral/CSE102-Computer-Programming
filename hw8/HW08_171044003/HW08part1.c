#include <stdio.h>


typedef enum{ P,S,M,B,T} block_types;


typedef struct {

	block_types type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
	char text[10]; 
	int data;

}  block;

int init_board(block board[10][10]);
void copy(block board[10][10],char array[]);

int main()
{
	block board[10][10];
	init_board(board);

}

int init_board(block board[10][10])
{
	int i,j;
	int k=90,l=91;
	for(i=0;i<10;i++)
	{
		if(i%2==1)
		{
			for(j=k;j>=k-9;j--)
			{	
				board[i][j].data=j;
				if(board[i][j].data==89){
					copy(board,"  M{94}");
				}
				else if(board[i][j].data==85)
					copy(board,"    P  ");
					
				else if(board[i][j].data==82)
					copy(board,"    B  ");
					
				else if(board[i][j].data==69)
					copy(board,"  M{77}");
					
				else if(board[i][j].data==63)
					copy(board,"  S{52}");
					
				else if(board[i][j].data==50)
					copy(board,"    B  ");
				
				else if(board[i][j].data==48)
					copy(board,"   P   ");
					
				else if(board[i][j].data==45)
					copy(board," S{22} ");
					
				else if(board[i][j].data==29)
					copy(board,"    B  ");
					
				else if(board[i][j].data==25)
					copy(board," S{12} ");
				
				else if(board[i][j].data==7)
					copy(board,"  M{11}");
				
				else if(board[i][j].data==6)
					copy(board,"  S{1} ");
				
				else if(board[i][j].data==1)
					copy(board,"  1{START}");
					
				else
				printf("  %3d  ",board[i][j].data);
			}
			k-=20;
			printf("\n");
		}
		
		else
		{
			for(j=l;j<=l+9;j++)
			{
				board[i][j].data=j;
				if(board[i][j].data==100)
					copy(board," 100(finish)");
					
				else if(board[i][j].data==99)
					copy(board," S{56} ");
					
				else if(board[i][j].data==98)
					copy(board,"  S{72} ");
					
				else if(board[i][j].data==79)
					copy(board,"    T  ");
					
				else if(board[i][j].data==76)
					copy(board,"  M{83}");
					
				else if(board[i][j].data==73)
					copy(board,"  S{68}");
					
				else if(board[i][j].data==60)
					copy(board,"  S{44} ");
				
				else if(board[i][j].data==57)
					copy(board,"  M{77}");
					
				else if(board[i][j].data==54)
					copy(board,"   T   ");
					
				else if(board[i][j].data==40)
					copy(board,"   T  ");
					
				else if(board[i][j].data==36)
					copy(board,"   B   ");
				
				else if(board[i][j].data==32)
					copy(board,"  M{52}");
				
				else if(board[i][j].data==17)
					copy(board,"  M{28}");
				
				else if(board[i][j].data==13)
					copy(board,"   P   ");
				
				else
				printf("  %3d  ",board[i][j].data);
			}
			l-=20;
			printf("\n");
		}
	}
}

void copy(block board[10][10],char array[])
{
	int i=0;
	while(array[i]!='\0')
	{
		board[10][10].text[i]=array[i];
		i++;
	}
	board[10][10].text[i]='\0';
	printf("%s",board[10][10].text);
}


