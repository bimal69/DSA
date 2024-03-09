#include <stdio.h>

int linearsearch(int l[],int k,int N){
	int i;
	for (i=0;i<N;i++){
		if(l[i]==k){
			printf("Found %d\n",k);return 1;
		}
	}
	
	printf("\n%d Not Found\n",k);return 0;
}

void main(){
	int l[20] = { 2,4,5,10,56,7,3};
	linearsearch(l,569,20);
	linearsearch(l,5,20);
}
