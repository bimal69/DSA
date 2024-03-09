#include <stdio.h>

void main(){
	int n;
	printf("Enter the number");
	scanf("%d",&n);
	int z = recursive(n);
	printf("The number is %d",z);
}
int  recursive(int n){
	if(n==0){
		return 0;
	}
	else {
		return ( n + recursive(n-1)); 
	}
}
