#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node* next;	
}Node;

typedef struct Container{
	Node* head;
}Container;

void initialize_container(Container* my_container){
	my_container -> head = NULL;

}

void insert_end(Container *my_container, int new_data){
	Node *head = my_container -> head;
	//v1 insert at end of list
	Node *new_node = (Node *)calloc(1, sizeof(Node));
	new_node -> data = new_data;
	//if the list is empty (first try with void)
	if(head == NULL){
			head = new_node;
	}else{
		Node *pointer = head;
		while(pointer -> next != NULL){
			pointer = pointer ->next;
		}
		//should now be pointing to last item in list
		pointer -> next = new_node;
	}
	
	my_container -> head = head;
}

void insert_front(Container *my_container, int new_data){
	Node *head = my_container -> head;
	Node *new_node = (Node *)calloc(1, sizeof(Node));
	new_node -> data = new_data;
	new_node -> next = head;
	head = new_node;
	my_container -> head = head;

}

bool contains_unsorted(Container *my_container, int search_data){
	Node *head = my_container -> head;
	Node* pointer;
	bool found = false;
	if(head != NULL){
		pointer = head;
		while(pointer != NULL && found == false){
			if(pointer -> data == search_data){
				found = true;
			}
			pointer = pointer -> next;
		
		}
	}
	return found;
}

void print_container(Container *my_container){
	Node *pointer = my_container -> head;
	while(pointer != NULL){
		printf("%d\n", pointer -> data);
		pointer = pointer -> next;
	}

}

//sorted insertion
void insert(Container *my_container, int new_data){
	Node *my_pointer = my_container -> head;
	Node *new_node = (Node *)calloc(1, sizeof(Node));
	new_node -> data = new_data;
	Node *my_trailer = NULL;
	bool found = false;
	while(my_pointer != NULL && found == false){
		if(my_pointer -> data > new_data){
			found = true;
		}else{
			my_trailer = my_pointer;
			my_pointer = my_pointer -> next;
		}
		
	}
	if(my_trailer == NULL){
		my_container -> head = new_node;
		new_node -> next = my_pointer;
	}else{
		//at this point trailer should point to the last node before insertion point
		new_node -> next = my_pointer;
		my_trailer -> next = new_node;
	}
}

bool contains(Container *my_container, int search_data){
	Node* head = my_container -> head;
	Node* pointer;
	bool found = false;
	bool stop = false;
	if(head != NULL){
		pointer = head;
		while(pointer != NULL && found == false && stop == false){
		printf("Checking %d\n", pointer->data);
			if(pointer -> data == search_data){
				found = true;
			}
			if(pointer -> data > search_data){
				stop = true;
			}
			pointer = pointer -> next;
		
		}
	}
	return found;
}

void delete_front(Container *my_container){
	Node* temp = my_container -> head;
	my_container -> head = my_container -> head -> next;
	free(temp);
}

void delete_end(Container *my_container){
	//Node* follower = NULL;
	Node* prt = my_container -> head;
	
	while (prt -> next != NULL)
	{
		prt = prt -> next;
	}
	
	free(prt);

}


void delete(Container *my_container, int delete_data){
	Node *follower = NULL;
	Node *prt = my_container -> head;
	
	while (prt -> data != delete_data && prt != NULL)
	{
		follower = prt;
		prt = prt -> next;
	}
	if(prt -> data == delete_data && follower -> next == NULL)
	{
		my_container -> head  = prt -> next;
		free(prt);
	}
	else if(prt -> data == delete_data && follower -> next != NULL)
	{
		follower -> next = prt -> next;
		free(prt);
	}
}


int main(){
	
	//Node *head = NULL;
	//Node *new_node;
	Container my_container;
	initialize_container(&my_container);

	insert(&my_container, 3);
	insert(&my_container, 10);
	insert(&my_container, 20);
	
	insert(&my_container, 7);
	insert(&my_container, 2);
	
	
	print_container(&my_container);
	printf("deleting\n");
	delete(&my_container, 10);
	delete(&my_container, 12);
	delete(&my_container, 2);
	print_container(&my_container);
	
	
	int search_value = 7;
	if(contains(&my_container, search_value)){
		printf("%d is in the list\n", search_value);
	}else{
		printf("%d is not in the list\n", search_value);
	}
	

}