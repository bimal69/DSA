//bubblesort
#include <stdio.h>

void main(){
	int a[5]={45,0,6,9,3};
	
	int i,j,var,n=5;
	for(i=0;i<n-1;i++){
		for(j=0;j<(n-i-1);j++){
			if(a[j]>a[j+1]){
				var = a[j];
				a[j]=a[j+1];
				a[j+1]=var;
			}
		}
		
	}
	for(i=0;i<5;i++){
		printf("\n%d\t",a[i]);
	}
}
