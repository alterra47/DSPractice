#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
typedef struct Btree{
	char data;
	struct Btree* lchild;
	struct Btree* rchild;
}btree;
int p(char c){
	switch(c){
		case'+':return 3;
		case'-':return 3;
		case'*':return 2;
		case'%':return 2;
		case'/':return 2;
		//case'(':return 1;
		//case')':return 4;
		default:return 0;
	}
}
btree* infix_build(char *str){
	btree* new = calloc(1,sizeof(btree));
	new->data = '#';
	new->lchild = NULL;
	new->rchild = NULL;
	if(strlen(str)==1){
		new->data = str[0];
		return new;
	}
	else{
		int j=0;
		char c = str[j];
		for(int i=1; i<strlen(str); i++){
			if(p(c)<=p(str[i])){
				c=str[i];
				j=i;
			}
		}
		new->data = c;
		char *str1=calloc(j,sizeof(char));
		char *str2=calloc(strlen(str)-j-1,sizeof(char));
		for(int i=0; i<j; i++){
			str1[i]=str[i];
		}
		for(int i=j+1; i<strlen(str); i++){
                        str2[i-j-1]=str[i];}
		new->lchild = infix_build(str1);
		new->rchild = infix_build(str2);
		return new;
	}
}
void inorder(btree *root){
	if(root){
		inorder(root->lchild);
		printf("%c",root->data);
		inorder(root->rchild);
	}
}
int main(){
	char str[50],c;
	printf("Enter any infix expression:\n");
	scanf("%s",str);
	btree *root=NULL;
	root = infix_build(str);
	printf("Contents of tree is:");
	inorder(root);
	printf("\n");
	return 0;
}
