#include <stdio.h>
#include <stdlib.h>
#define numberofblack 16
#define numberofwhite 16

typedef enum{white_man,black_man,white_king,black_king,empty} piece;
typedef enum {white=10,black=20} player;


void init_board(int piece_board[][8]) // it shows the first figure.
{
	enum piece ;
	
	int i,j;
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(piece_board[i][j]==0)
				printf("w");
			else if(piece_board[i][j]==1)
				printf("b");
			else if(piece_board[i][j]==2)
				printf("W");
			else if (piece_board[i][j]==3)
				printf("B");
			else if(piece_board[i][j]==4)
				printf("-");
		}
		printf("\n");
	}
}

int create_king(int piece_board[][8],int from_x,int from_y,int player_p) // it creates a king from man.
{
	if(player_p==0)
	{
		int i;
		for(i=0;i<8;i++)
		{
			if(piece_board[from_y][from_x]==piece_board[0][i])
			{
				player_p==2;
			}
		}
	}
	
	else if(player_p==1)
	{
		int j;
		for(j=0;j<8;j++)
		{
			if(piece_board[from_y][from_x]==piece_board[7][j])
			{
				player_p==3;
			}
		}
	}
}

int move(int piece_board[][8],int from_x,int from_y,int to_x,int to_y,int player_p) // movement function
{
	enum piece;
	if(player_p==0){
		if(piece_board[from_y][from_x-1]==4)
			return 1;
		if(piece_board[from_y][from_x-1]==1 && piece_board[from_y][from_x-2]==4)
			return 1;
	
		if(piece_board[from_y][from_x+1]==4)
			return 1;
		if(piece_board[from_y][from_x+1]==1 && piece_board[from_y][from_x+2]==4)
			return 1;
			
		if(piece_board[from_y-1][from_x]==4)
			return 1;
		if(piece_board[from_y-1][from_x]==1 && piece_board[from_y-2][from_x]==4)
			return 1;
			
		else
			return -2;		
	}
	
	else if(player_p==1){
		if(piece_board[from_y][from_x-1]==4)
			return 1;
		if(piece_board[from_y][from_x+1]==4)
			return 1;
		if(piece_board[from_y+1][from_x]==4)
			return 1;
		else
			return -2;
	}
	
	else if(player_p==2)
	{
		int i,j,bosluk=0,a;
		if(from_x<to_x) // it continous to right from left.
		{
			if(piece_board[to_y][to_x-1]==1 || piece_board[to_y][to_x-1]==3) // it checks the squares are empty except the previous one.       
			{
				for(i=from_x;i<to_x-1;i++)
				{
					if(piece_board[from_y][i]==4)
					{
						from_x=to_x;
						return 1;
					}
					
					else
					{ 
						return 0;
						break;
					}
				}	
			}
			int a=to_x-from_x;
			
			j=from_x;
			do{ // it checks if all of the squares are empty.
				if(piece_board[from_y][j+1]==4)
				{
					bosluk++;
					j++;
				}
			}while(j<=to_x-2);
			
			if(bosluk==a-1){
				from_x=to_x;
				return 1;
				}
			else if(bosluk!=a-1)
				return 0;
		}
		
		int k,m;
		if(to_x<from_x) // it continous to left from right.
		{
			if(piece_board[to_y][to_x+1]==1 || piece_board[to_y][to_x+1]==3) // it checks the squares are empty except the previous one.       
			{
				for(k=from_x;k>to_x+1;k--)
				{
					if(piece_board[from_y][k]==4)
						return 1;
					else
					{ 
						return 0;
						break;
					}
				}	
			}
			int b=from_x-to_x;
			
			m=from_x;
			do{ // it checks if all of the squares are empty.
				if(piece_board[from_y][m-1]==4)
				{
					bosluk++;
					m--;
				}
			}while(j<=to_x-2);
			
			if(bosluk==b-1)
				return 1;
			else if(bosluk!=b-1)
				return 0;
		}
		
	}
}


int check_end_of_game(int piece_board[][8]) // it checks if the game is over or continous.
{
	if(numberofblack==0)
		return white;
	else if(numberofwhite==0)
		return black;
	else
		return -1;
	
}

void display_board(int piece_board[][8])
{

}

void sample_game_1()
{

}

void sample_game_2()
{

}

int main()
{
	int piece_board[8][8]={{empty,empty,empty,empty,empty,empty,empty,empty},
	 						 {black_man,black_man,black_man,black_man,black_man,black_man,black_man,black_man},
	 				   	 {black_man,black_man,black_man,black_man,black_man,black_man,black_man,black_man},
	 						 {empty,empty,empty,empty,empty,empty,empty,empty},
	 						 {empty,empty,empty,empty,empty,empty,empty,empty},
	 						 {white_man,white_man,white_man,white_man,white_man,white_man,white_man,white_man},
							 {white_man,white_man,white_man,white_man,white_man,white_man,white_man,white_man},
							 {empty,empty,empty,empty,empty,empty,empty,empty}};
	
	
	
	init_board(piece_board);
	int a=move(piece_board,2,1,2,3,1);
	printf("%d",a);
	return 0;
}	

