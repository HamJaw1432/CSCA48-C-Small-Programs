#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_CONTAINER_SIZE 1024

typedef struct Node{
	int data;
	struct Node *next;
	
}Node;


typedef struct Container{

    Node *head;

}Container;

void initialize_container(Container* my_container){
    my_container -> head = NULL;
}

void print_container(Container *my_container){
    /* int num_items = my_container -> size;
    for(int i = 0; i< num_items; i++){
        printf("%d\n", my_container -> contents[i]);
    } */
	
	
	
}

void insert(Container *my_container, int new_data){
    //my_container -> contents[my_container -> size] = new_data;
	/* for(int i = 0; i < my_container -> size; i++)
	{
		my_container -> contents[my_container -> size -i] = my_container -> contents[my_container -> size - 1 -i];
	}
	my_container -> contents[0] = new_data;	
    my_container -> size = my_container -> size + 1; */
	
	Node *new_node = (Node*)calloc(1, sizeof(Node));
	new_node -> data = new_data;
	new_node -> next = NULL;
	
	if(my_container -> head == NULL)
	{
		
		
	}else{
	
		Node* temp_pt = my_container -> head;
		
		while (temp_pt -> next != NULL)
		{
			temp_pt = temp_pt -> next;
		}
		
		temp_pt -> next = &new_node;
	}
	
	
	 
}

bool contains(Container *my_container, int search_data){
    /* bool found = false;
    int num_items = my_container -> size;
    for(int i = 0; i < num_items; i++){
        if(my_container -> contents[i] == search_data){
            found = true;
        }
    }
    return found; */
	
	
	
	
	
	
}

int main(){

    Container my_container;
    initialize_container(&my_container);
    for(int i = 0; i < 5; i++){
        insert(&my_container, i);
    }

    print_container(&my_container);
    int search_value = 3;
    if(contains(&my_container, search_value)){
        printf("%d is in the list", search_value);
    }else{
        printf("%d is not in the list\n", search_value);
    }

    return 0;
}