#include <stdio.h>
#include <conio.h>
#include <limits.h>

void mergesort(int a[6],int l,int r){
	if(l<r){
		int q = (l+r-1)/2;
		mergesort(a,l,q);
		mergesort(a,q+1,r);
		merge(a,l,q,r);
	}
}
void merge(int a[6],int l,int q,int r){
	int n1 = q-l+1;
	int n2 = r-q;
	int i,j,k,*L,*R;
	
	for(i=1;i<=n1;i++){
		L[i]=a[l+i];
}
	for(j=1;j<=n2;j++){
		R[j]= a[q+1+j];
	}
	
	L = (int*)malloc(sizeof(int)*(n1));
	R = (int *)malloc(sizeof(int)*(n2));
	
	L[n1-1]=INT_MAX;
	R[n2-1]=INT_MAX;
	i=0;j=0;
	for(k=1;k<=r;k++){
		if(L[i]<=R[j]){
			a[k]=L[i++];
		}
		else{
			a[k]=R[j++];
		}
}
free(L);
free(R);
}
void main(){
	int a[6] = {9,6,5,0,8,2};
	mergesort(a,0,5);
	int i;
	for(i=0;i<6;i++){
		printf("%d\t",a[i]);
	}
}
