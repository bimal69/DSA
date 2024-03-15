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
	
	for(i=0;i<1000;i++){
		fscanf(fp,"%d",&arr[i]);
	}
	fclose(fp);
	for(i=0;i<1000;i++){
		for(j=i+1;j<1000;j++){
			if(arr[i]>arr[j]){
				tmp = arr[i];
				arr[i]=arr[j];
				arr[j] = tmp;
			}
		}
	}
	fp=fopen("randomnum.txt", "w");
	if(fp==NULL){
		printf("File is Empty");
		exit(1);
	}
	for(i=0;i<1000;i++){
		fprintf(fp, "%d\n",arr[i]);
	}
	fclose(fp);
	getch();
}
