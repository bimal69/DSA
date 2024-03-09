#include <stdio.h>

void main(){
	int i,j,var,n=5,min;
	int a[5]={45,0,6,9,3};
	for(i=0;i<n-1;i++){
		min=i;
		for(j=0;j<n;j++){
			if(a[min]<a[j]){
				min = j;
			}	
		}
		if(min!=i){
				var = a[i];
				a[i]=a[min];
				a[min]=var;
			}
	}
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	
}
