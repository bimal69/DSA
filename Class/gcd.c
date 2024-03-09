//GCD of 2 positive number labreport
#include <stdio.h>

void main(){
	int a = 10, b= 100;
	int c =  gcd(a,b);
	printf("gcd(%d,%d)=%d",a,b,c);
}
int gcd(int n1,int n2){
	if(n2!=0){
		return gcd(n2,n1%n2);
	}
	else {
		return n1;
	}
}



