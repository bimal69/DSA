#include <stdio.h>

int fibo(int a){
	
	if(a>2){
		return fibo(a-2)+fibo(a-1);
	}
	else{
		return 1;
	}
}
void main(){
	int n;
	printf("Enter the index: ");
	scanf("%d",&n);
	printf("%d",fibo(n));
	
}

