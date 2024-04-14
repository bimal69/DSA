//DFS (Depth first search) Implementation in C
#include <stdio.h>
#include <conio.h>

#define N 6
void dfs(int[][N],int);
void push(int);
void initvisited(int[][N]);
int top = -1;
int visited[N];
int stack[N];
int isempty();
void main(){
	int graph[N][N]={{0,1,1,1,0,1},{1,0,1,1,1,0},{1,1,0,1,0,1},{1,1,1,0,0,1},{0,1,0,0,0,1},{1,0,1,1,1,0}};
	initvisited(graph);
	visited[2]=1;
	push(2);
	dfs(graph ,2);
	
}
void push(int k){
	if(top==N-1){
		printf("Stack is full!!");getch();return;
	}
	stack[++top]=k;
}
int pop(){
	if(top==-1){
		printf("Stack is empty!!");getch();return;
	}
	return stack[top--];
}
void initvisited(int graph[][N]){
	int i;
	for(i=0;i<N;i++){
		visited[i]=0;
	}
}
int isempty(){
	return(top==-1)?1:0;
}
void dfs(int g[][N],int k){
	int i,r;
	
	while(isempty()){
		int r=pop();
		printf("\n%d",r);	
		for(i=0;i<N;i++){
			if(!visited[i] && g[r][i]){
				visited[i]=1;
				push(i);
				dfs(g,i);
			}
		}
	}
}




