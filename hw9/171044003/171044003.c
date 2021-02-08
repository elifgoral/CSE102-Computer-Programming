#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { tree, eBotanist, flower, blank} shape;

typedef struct {	int **map;
						int height;
				  		int width;
				 		int flower_x;
				  		int flower_y;
					} Forest;

typedef struct { int cord_x;
					  int cord_y;
					  int water_bottle_size; } Botanist;

void init_game(Forest *forest,Botanist *botanist);
void print_map (Forest *forest);
void search(Forest *forest,Botanist *botanist,int counter);

int main()
{
	int i;
	Forest forest;
	Botanist botanist;
	srand(time(NULL));
	init_game(&forest,&botanist);
	search(&forest,&botanist,0);
	print_map(&forest);
	
	for(i=0;i<forest.height;i++){
		free(forest.map[i]);
	}
	free(forest.map);
	return 0;
}

void init_game(Forest *forest,Botanist *botanist)
{
	int  i,j;
	char figure;
	char buffer;
		
	FILE *file=fopen("init.txt","r");
	
	fscanf(file,"%d",&botanist->water_bottle_size);
	fscanf(file,"%d",&forest->height);
	fscanf(file,"%d",&forest->width);
	fscanf(file,"%c",&buffer);
	
	forest->map=(int **) malloc(sizeof(int **)*forest->height);
	for(i=0;i<forest->height;i++)
	{
		forest->map[i]=(int*) malloc(sizeof(int)*forest->width);
	}
	
	printf("Bottle Size: %d \n",botanist->water_bottle_size);
	printf("Height of map: %d \n",forest->height); 
	printf("Width of map : %d\n",forest->width); 		

	for(i=0;i<forest->height;++i)
	{
		for(j=0;j<=forest->width;++j)
		{
			fscanf(file,"%c",&figure);
				
				if(figure=='#')
				{ 
					forest->map[i][j]=tree;
				}
				else if(figure=='B')
				{
					forest->map[i][j]= eBotanist;
					botanist->cord_x = i;
					botanist->cord_y = j;
				}
				else if(figure=='F')
				{
					forest->map[i][j]=flower;
					forest->flower_x = i;
					forest->flower_y = j;
				}
				else if(figure==' ')
				{	
					forest->map[i][j]=blank;	
				}			 
		}
		printf("\n");
	}
	print_map(forest);

	fclose(file);
}

void print_map (Forest *forest)
{
	int i,j;

	for(i=0;i<forest->height;++i)
	{
		for(j=0;j<forest->width;++j)
		{
			switch(forest->map[i][j])
			{
				case 0:
					printf("# ");
					break;
		
				case 1:
					printf("B ");
					break;
		
				case 2:
		
					printf("F ");
					break;
	
				case 3:
					printf("  ");
					break;
		
				default:
					break;
			}
		}
		printf("\n");
	}
}

void search(Forest *forest,Botanist *botanist,int counter)
{
	int move=1+rand()%4;
	// 1-up 2-down 3-left 4-right	
	printf("anlık konum:(%d,%d) ",botanist->cord_x,botanist->cord_y);
	printf("%d\n",move);

	//move for up
	if(move==1 && botanist->cord_x-1>=0 && forest->map[botanist->cord_x-1][botanist->cord_y]!=tree) 
	{
		counter++;
		forest->map[botanist->cord_x][botanist->cord_y]=3;
		botanist->cord_x=botanist->cord_x-1;
		forest->map[botanist->cord_x][botanist->cord_y]=1;
		printf("(%d,%d)---counter:%d\n",botanist->cord_x,botanist->cord_y,counter);
		if(forest->map[botanist->cord_x][botanist->cord_y]==flower)
		{
			printf("I have found it on (%d,%d)!\n",botanist->cord_x,botanist->cord_y);		
		}
		else if(counter==botanist->water_bottle_size)
		{
			printf("Help! I am on (%d,%d)\n",botanist->cord_x,botanist->cord_y);
		}
		else
			search(forest,botanist,counter);
	}
	
	else if(move==1 && botanist->cord_x-1<0)
	{
		search(forest,botanist,counter);
	}
	
	else if(move==1 && forest->map[botanist->cord_x-1][botanist->cord_y]==tree)
	{
		search(forest,botanist,counter);
	}

	
	//move for down
	
	else if(move==2 && botanist->cord_x+1<=9 && forest->map[botanist->cord_x+1][botanist->cord_y]!=tree)
	{
		counter++;
		forest->map[botanist->cord_x][botanist->cord_y]=3;
		botanist->cord_x=botanist->cord_x+1;
		forest->map[botanist->cord_x][botanist->cord_y]=1;
		printf("(%d,%d)---counter:%d\n",botanist->cord_x,botanist->cord_y,counter);
		if(forest->map[botanist->cord_x][botanist->cord_y]==flower)
		{
			printf("I have found it on (%d,%d)!\n",botanist->cord_x,botanist->cord_y);		
		}
		else if(counter==botanist->water_bottle_size)
		{
			printf("Help! I am on (%d,%d)\n",botanist->cord_x,botanist->cord_y);
		}	
		else
			search(forest,botanist,counter);
	}
	else if(move==2 && botanist->cord_x+1>9)
	{
		search(forest,botanist,counter);
	}
	
	else if(move==2 && forest->map[botanist->cord_x+1][botanist->cord_y]==tree)
	{
		search(forest,botanist,counter);
	}
	
	//move for left
	
	else if(move==3 && botanist->cord_y-1>=0 && forest->map[botanist->cord_x][botanist->cord_y-1]!=tree)
	{
		counter++;
		forest->map[botanist->cord_x][botanist->cord_y]=3;
		botanist->cord_y=botanist->cord_y-1;
		forest->map[botanist->cord_x][botanist->cord_y]=1;
		printf("(%d,%d)---counter:%d\n",botanist->cord_x,botanist->cord_y,counter);
		if(forest->map[botanist->cord_x][botanist->cord_y]==flower)
		{
			printf("I have found it on (%d,%d)!\n",botanist->cord_x,botanist->cord_y);		
		}
		else if(counter==botanist->water_bottle_size)
		{
			printf("Help! I am on (%d,%d)\n",botanist->cord_x,botanist->cord_y);
		}		
		else
			search(forest,botanist,counter);	
	}

	else if(move==3 && botanist->cord_y-1<0)
	{
		search(forest,botanist,counter);
	}
	
	else if(move==3 && forest->map[botanist->cord_x][botanist->cord_y-1]==tree)
	{
		search(forest,botanist,counter);
	}

	//move for right
	
	else if(move==4 && botanist->cord_y+1<=9 && forest->map[botanist->cord_x][botanist->cord_y+1]!=tree)
	{
		counter++;
		forest->map[botanist->cord_x][botanist->cord_y]=3;
		botanist->cord_y=botanist->cord_y+1;
		forest->map[botanist->cord_x][botanist->cord_y]=1;
		printf("(%d,%d)---counter:%d\n",botanist->cord_x,botanist->cord_y,counter);
		if(forest->map[botanist->cord_x][botanist->cord_y]==flower)
		{
			printf("I have found it on (%d,%d)!\n",botanist->cord_x,botanist->cord_y);		
		}
		else if(counter==botanist->water_bottle_size)
		{
			printf("Help! I am on (%d,%d)\n",botanist->cord_x,botanist->cord_y);
		}	
		else
			search(forest,botanist,counter);
					
	}

	else if(move==4 && botanist->cord_y+1>9)
	{
		search(forest,botanist,counter);
	}
	
	else if(move==4 && forest->map[botanist->cord_x][botanist->cord_y+1]==tree)
	{
		search(forest,botanist,counter);
	}
}
