#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
/**********************************************/
// Lab-9 Lab.Task_2
/*********************************************/
// 1- Define a stack struct
// 2- Define typedef variables
// 3- In main function;
	// 3.1- define a char array
	// 3.2- take a string from user
	// 3.3- store the string in a stack (use push function)
	// 3.4- display the stack
	// 3.5- define a new char array and a new stack pointer
	// 3.6- popped the struct and when popped, store the variables in new stak
	// 3.7- display the new stack (as reverse)
	// 3.8- compare the two arrays and display if polindrome or not (strcmp)
// 4- End 

struct stackNode{
	char data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;
// prototypes
void push(StackNodePtr *topPtr, char letter); // add 
char pop(StackNodePtr *topPtr); // remove
void printStack(StackNodePtr currentPtr); // display stcak

int main(){
	StackNodePtr stackPtr = NULL;
	printf("Enter a text: ");
	char text[N] = {'\0'};
	scanf("%s", text);
	
//	printf("The given text is: %s\n", text);
	
	int length = strlen(text);
//	printf("%d", length);

	int i = 0;
	for(i = 0; i <= length; i++){
		char x = text[i];
//		printf("%c\n", x);
		push(&stackPtr, x);
//		printStack(stackPtr);
	}
	
	printf("The given text is:");
	printStack(stackPtr);

	StackNodePtr tempPtr = NULL; // define a new stack pointer
	
	int length2 = length + 1; // increment length 
	char text2[length2]; // define a new array 
	
	while (stackPtr != NULL){
			char y = pop(&stackPtr);
			int i = 0;
			text2[i] = y;
			i++;
			push(&tempPtr, y);  // write values as reverse
//			printf("%c", y);
//			printStack(stackPtr);
	}
		
	printf("The reverse of the text: ");
	printStack(tempPtr);
	
//	puts("\n");

	if (strcmp(text, text2) == 0){ // compare two strings 
		printf("\nThe text is a polindrome.\n");
	}
	else{
		printf("\nThe text is not a polindrome.\n");
	}
	
	return 0;
}

void push(StackNodePtr *topPtr, char letter){
	unsigned sizestack = sizeof(StackNode);
	StackNodePtr newPtr = malloc(sizestack);
	if (newPtr != NULL){
		newPtr -> data = letter;
		newPtr -> nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else{
		printf("%c not inserted. No memory available.\n", letter);
	}
}

void printStack(StackNodePtr currentPtr){
	if (currentPtr == NULL){
		puts("The stack is empty.");
	}
	else{
		while(currentPtr != NULL){
			printf("%c", currentPtr);
			currentPtr = currentPtr -> nextPtr;
		}
	}
	puts(" ");
}

char pop(StackNodePtr *topPtr){
	StackNodePtr tempPtr = *topPtr;
	char popValue = (*topPtr) -> data;
	*topPtr = (*topPtr) -> nextPtr;
	free(tempPtr);
	return popValue;
}

int isEmpty(StackNodePtr topPtr){
	return topPtr == NULL;
}
