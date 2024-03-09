#include <stdio.h>

void swap(int a[8],int i,int j){
	int tmp;
	tmp = a[i];
	a[i]=a[j];
	a[j]=tmp;
}

int partation(int a[20],int l,int r){
	int pivot=a[r];
	int i = l-1;
	int j,tmp;
	for(j=l;j<r;j++){
		if(a[j]<=pivot){
			i=i+1;
			swap(a,i,j);
		}
	}
	swap(a,i+1,r);
	return i+1;
}
void  quicksort(int a[8],int l,int r){
	if(l<r){
	 	int q=partation(a,l,r);
		quicksort(a,l,q-1); //apply quicksort on left part
		quicksort(a,q+1,r); //apply quicksort on right part
	}
}
int main(){
	int a[8]={6,9,5,0,8,2,4,7};
	int l=0,r=7;
	int i;
	quicksort(a,l,r);
	for(i=0;i<8;i++){
		printf("%d\t",a[i]);
	}
	return 0;
}
