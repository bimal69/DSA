#include <stdio.h>

void shellsort(int a[50],int n){
	int gap, i, j, tmp;
	for(gap=n/2;gap>0;gap/=2){
		
		for(j=gap;j<n;j++){
			tmp = a[j];
			for(i=j;i>=gap && a[i-gap]>tmp;i=i-gap){
				a[i] = a[i-gap];
			}
			a[i]=tmp;
		}
	}
}
void main(){
	int a[50]={23,29,15,19,31,7,9,5,2};
	int i;
	shellsort(a,10);
	for(i=1;i<10;i++){
		printf("%d\t",a[i]);
	}
}
