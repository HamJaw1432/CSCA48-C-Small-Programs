#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1024

typedef struct Stack{
	int contents[MAX_SIZE];
	int size;
}Stack;

void initialize_stack(Stack* my_stack){
	my_stack -> size = 0;
}

void push(Stack *my_stack, int new_data){
	my_stack -> contents[my_stack->size] = new_data;
	my_stack -> size += 1;
}

int pop(Stack *my_stack){
	int result = my_stack -> contents[my_stack->size -1];
	my_stack -> size -= 1;
	return result;
}

typedef struct Queue{
	int contents[MAX_SIZE];
	int size;
}Queue;

void initialize_queue(Queue *my_queue){
	my_queue -> size = 0;
}

void enqueue(Queue *my_queue, int new_data){
	my_queue -> contents[my_queue -> size] = new_data;
	my_queue -> size += 1;
}

int dequeue(Queue *my_queue){
		int result = my_queue -> contents[0];
	for(int i = 0; i < (my_queue -> size - 1); i++){
		my_queue -> contents[i] = my_queue -> contents[i + 1];
	}
	my_queue -> size -= 1;
	return result;
}



int main(){
	Stack my_stack;
	initialize_stack(&my_stack);
	push(&my_stack, 3);
	push(&my_stack, 7);
	push(&my_stack, 9);
	printf("%d\n",pop(&my_stack));
	printf("%d\n",pop(&my_stack));
	printf("%d\n",pop(&my_stack));
	
	Queue my_queue;
	initialize_queue(&my_queue);
	enqueue(&my_queue, 3);
	enqueue(&my_queue, 7);
	enqueue(&my_queue, 9);
	printf("%d\n",dequeue(&my_queue));
	printf("%d\n",dequeue(&my_queue));
	printf("%d\n",dequeue(&my_queue));

}