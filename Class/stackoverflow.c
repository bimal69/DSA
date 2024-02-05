//Evaluating a postfix expression using a stack.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

void push(int);
int pop();
int isoperand(char);
int isoperator(char);
int performoperation(int, char, int);
int stack[30];
int top=-1;
  


int stack[30];


void main(){
	char postfix[30],k;
	int len, opd1, opd2,i,res;
	printf("Enter the postfix expression: \n");
	gets(postfix);
	len = strlen (postfix);
	for (i=0;i<len;i++){
		k = postfix[i];
		
		if(isoperand(k)){
			push(k - '0');  
		} 
		else if(isoperator(k)){
			opd2 = pop();
			opd1=pop();
			res = performoperation(opd1,k,opd2);
			push(res);
		}
		
	}
	printf("\n\nfinal result of postfix evaluation :%d",pop());
}
void push(int k){
	if(top == 29){
		printf("\nStack is full \n");getch();return;
	}
	stack[++top] = k;
}
int pop(){
	if (top==-1){
		printf("\nStack is empty\n");getch();return -999;
	}
	return stack[top--];
}
int isoperand(char c){
	if (c>=48 && c<=57){
		return 1;
	}
	else {
		return 0;
	}
}
int isoperator(char c){
	switch (c){
		case '+': 
		case '-':
		case '*':
		case '/':
		case '^':return 1;
		default: return 0;
	}
}
int performoperation(int opd1,char op, int opd2){
		switch(op){
			case '+': return opd1 + opd2;
			case '-': return opd1 - opd2;
			case '*': return opd1 * opd2;
			case '/': return opd1 / opd2;
			case '^': return pow(opd1,opd2);
			default: printf("invalid");
	}
}





