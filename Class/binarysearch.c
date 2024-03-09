//binary search
#include <stdio.h>


int binarysearch(int L[],int k, int l, int r){
	int mid;
	if(l<=r){
		mid = (l+r)/2;
		if(L[mid]>k){
			binarysearch(L,k,mid+1,r);
		}
		else if(L[mid]<k){
			binarysearch(L,k,mid+1,r);
		}
		else{
			printf("\nSearch key found");
			return 1;
		}
	}
	printf("\nSearch key not found");
}
void main(){
	int L[10]={10,12,13,14,15,18};
	
	binarysearch(L,12,2,4);
}




