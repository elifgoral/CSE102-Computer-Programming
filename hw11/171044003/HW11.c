#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct customers_t { int room_num;
									char name[20];
									char surname[20];
							 		int age;
									char gender[20];
									struct customers_t *next;
} customers_t;

typedef struct rooms{int room_number;
							int capacity;
							int floor;
							struct rooms *next;
							customers_t *customer;
} rooms;
						 

void print_customer(customers_t *root);// that function writes the customers.
void print_room(rooms *root); //that function writes the rooms.
void add_room_to_end(rooms *root,int room_number,int capacity,int floor);//that function links the rooms.
void add_customer_to_end(customers_t *root,int room_number,char name[],char surname[],int age,char gender[]);// that function links the customers
void delete(rooms *root); //that function removes the room which is entered.
void get_by_floor(rooms *root); // that function show the rooms according to floor which is entered.

int main()
{
	FILE *file_room=fopen("rooms.txt","r");
	FILE *file_customer=fopen("customers.txt","r");
	
	//this place reads the room.txt .
	rooms *root_room=NULL;
	customers_t *root_customer=NULL;
	int room_number,capacity,floor;

	while(fscanf(file_room,"%d,%d,%d",&room_number,&capacity,&floor)!=EOF)
	{
		if(root_room==NULL){
			root_room=(rooms*)malloc(sizeof(rooms));
			root_room->room_number=room_number;
			root_room->capacity=capacity;
			root_room->floor=floor;
		}
		else{
			add_room_to_end(root_room,room_number,capacity,floor);
		}
	}
	print_room(root_room);
	printf("\n");
	
	//this place reads the customer.txt .
	
	int room_no,age;
	char name[20],surname[20],gender[20],line;
	while(fscanf(file_customer,"%d,%s %s,%d,%s",&room_no,name,surname,&age,gender)!=EOF)
	{		
		// I use strtok because	'%s' which is reads the surname; read surname,age and gender.
		char *token=strtok(surname,",");
		strcpy(surname,token);
		token=strtok(NULL,",");
		age=atoi(token);
		token=strtok(NULL,",");
		strcpy(gender,token);
	
		if(root_customer==NULL){
			root_customer=(customers_t*)malloc(sizeof(customers_t));
			root_customer->room_num=room_no;
			strcpy(root_customer->name,name);
			strcpy(root_customer->surname,surname);
			root_customer->age=age;
			strcpy(root_customer->gender,gender);
		}
		else{
			add_customer_to_end(root_customer,room_no,name,surname,age,gender);		
		}
	}
	print_customer(root_customer);
	printf("\n");
	get_by_floor(root_room);
	delete(root_room);
	print_room(root_room);
	
	
	fclose(file_room);
	fclose(file_customer);		
}

void add_customer_to_end(customers_t *root,int room_number,char name[],char surname[],int age,char gender[])
{
	customers_t *current=root;
		
	while(current->next!=NULL)
		current=current->next;	

	current->next=(customers_t*)malloc(sizeof(customers_t));
	current->next->room_num=room_number;
	strcpy(current->next->name,name);
	strcpy(current->next->surname,surname);
	current->next->age=age;
	strcpy(current->next->gender,gender);

	current->next->next=NULL;
}


void add_room_to_end(rooms *root,int room_number,int capacity,int floor)
{	
	rooms *current=root;
	
	while(current->next!=NULL)
		current=current->next;	
	
	current->next=(rooms*)malloc(sizeof(rooms));
	current->next->room_number=room_number;
	current->next->capacity=capacity;
	current->next->floor=floor;
	
	current->next->next=NULL;
}

void print_customer(customers_t *root)
{
	customers_t *current=root;
	
	while(current!=NULL)
	{
		printf("%d,%s %s,%d,%s \n",current->room_num,current->name,current->surname,current->age,current->gender);
		current=current->next;	
	}	
}

void print_room(rooms *root)
{
	rooms *current=root;
	
	while(current!=NULL)
	{
		printf("room number :%d   capacity: %d   floor:%d\n",current->room_number,current->capacity,current->floor);
		current=current->next;
	}
}

void get_by_floor(rooms *root)
{
	int floor_num;
	printf("floor number: "); scanf("%d",&floor_num);

	rooms *current=root;
	
	while(current!=NULL)
	{
		if(current->floor==floor_num)
		{
			printf("%d on floor %d \n",current->room_number,current->floor);
			current=current->next;
		}
		else{
		current=current->next;
		}
	}
}

void delete(rooms *root)
{
	int i,del;
	printf("Which room do you want to remove :"); scanf("%d",&del);

	rooms *current=root;
	rooms *current1=root;
	rooms *current2=root;
	
	// for first room
	if(root->room_number==del)
	{
		rooms *temp=current1->next;
		free(current1);
		root=temp;
	}
	
	//for second room
	else if(current2->next->room_number==del)
	{
		rooms *temp1= current2->next->next;
		free(current2->next);
		current2->next=temp1;
	}
	
	//for other rooms
	else
	{
		for(i=0;current!=NULL && current->next->next->room_number!=del;i++)
		{
			current=current->next;
		}
		rooms *temp2=current->next->next->next;
		free(current->next->next);
		current->next->next=temp2;
	}
}



