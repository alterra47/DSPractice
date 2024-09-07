#include<stdio.h>
#define MAX 3
typedef struct{
	int first;
	int rear;
	int arr[MAX];
}Queue;
int isEmpty(Queue *q){
	if(q->first==q->rear){
		printf("Queue is empty!\n");
		return 1;
	}
	else return 0;
}
int isFull(Queue *q){
	if(q->rear==MAX-1){
		printf("Queue is full!\n");
                return 1;
	}
	else return 0;
}
void insert(Queue *q, int item){
	if(isFull(q)==1)return;
	q->arr[++(q->rear)]=item;
}
void delete(Queue *q){
	if(isEmpty(q)==1)return;
	printf("Deleted value is %d\n",q->arr[++(q->first)]);
}
void display(Queue *q){
	if(isEmpty(q)==1)return;
	printf("Contents of queue are:\n");
	for(int i=q->first+1; i<=q->rear; i++)
		printf("%d ", q->arr[i]);
	printf("\n");
}
int main(){
	Queue q;
	q.first=-1;
	q.rear=-1;
	int ch, item;
	do{
		printf("Enter 1.Insert 2.Delete 3.Display  4.Quit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("Enter item to be inserted\n");
			       scanf("%d",&item);
			       insert(&q, item);
			       break;
			case 2:delete(&q);
			       break;
			case 3:display(&q);
			       break;
			default:ch=4;
		}
	}
	while(ch!=4);
	return 0;
}
