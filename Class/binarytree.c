//C implementation of binary search tree
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

int key;
void insert(struct node*,int);
void search(struct node*, int);
void displayinorder(struct node*);
void displaypreorder(struct node*);
struct node *createnode(int);

struct node* root;
int main(){
	root = NULL;
	insert(root,50);
	insert(root,59);
	insert(root,12);
	insert(root,20);
	insert(root,67);
	insert(root,5);
	
	printf("\n\nCurrent BST: \n\n");
	displayinorder(root);
	displaypreorder(root);
//	printf("\n\nEnter an element to search: ");scanf("%d",&key);
//	search(root,key);
//	printf("\n\nEnter an element to delete: ");scanf("%d",&key);
}
struct node *createnode(int data){
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void search(struct node*tmp,int data){
	struct node *newnode;
	if(tmp=NULL){
		printf("\nSearch unsuccessfull!\n%d does not exist in the BST\n",key);getch();
	}	
	
}
void deletenode(struct node*tmp,int el){
	struct node *res, *parent, *pred;
	int dt;
	if(tmp==NULL){
		printf("BTS is empty");return;
	}
	res = find(tmp,el);
	if(res ==NULL){
		printf("Deletion not possible");
	}
	else{
		if(numchild(res)==0){
			if(res==root){
				tmp = root;
				free(tmp);
				root = NULL;
			}
			else{
				parent = findparent(tmp,el);
				if(res == parent->left){
					if(res->left ==NULL){
						parent->left =res->right;
					}
					
				else{
					parent->right = NULL;
				}
				free(res);
				}
			}
			
			
			else{
				pred = inorderpredecessor(res->left);
				dt=pred->data;
				deletenode(root ,pred->value);
			}
		}
	}
}

void insert(struct node *tmp,int newdata){
	struct node *newnode;
	if(tmp==NULL){
		newnode = createnode(newdata);
		root = newnode;
	}
	else if(newdata< tmp->data){
		if(tmp->left ==NULL){
			newnode = createnode(newdata);
			tmp->left = newnode;
		}
		else { 
			insert(tmp->left,newdata);
		}
	}
	else if(newdata>=tmp->data){
		if(tmp->right ==NULL){
			newnode = createnode(newdata);
			tmp->right = newnode;
		}
		else{
			insert(tmp->right ,newdata);
		}
	}
}

void displayinorder(struct node *tmp){
	if(tmp!=NULL){
		dispalyinorder(tmp->left);
		printf("%d\t",tmp->data);
		displayinorder(tmp->right);
	}
}
void displaypreorder(struct node* tmp){
	if(tmp!=NULL){
		printf("%d\t",tmp->data);
		dispalyinorder(tmp->left);
		
		displayinorder(tmp->right);
	}
}








