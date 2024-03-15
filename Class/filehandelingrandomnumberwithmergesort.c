#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main(){
	FILE *fp;
	int i,n,j,tmp;
	int arr[1000];
	fp = fopen("randomnum.txt","r");
	if(fp==NULL){
		printf("File is empty");
		exit(0);
	}
	
	for(i=0;i<100000;i++){
		fscanf(fp,"%d",&arr[i]);
	}
	fclose(fp);
	for(i=0;i<100000-1;i++){
		for(j=0;j<(n-i-1);j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
		}
	
	fp=fopen("randomnum.txt", "w");
	if(fp==NULL){
		printf("File is Empty");
		exit(1);
	}
	for(i=0;i<100000;i++){
		fprintf(fp, "%d\n",arr[i]);
	}
	fclose(fp);
	getch();
}
