#include<stdio.h>
#define MAX 5
typedef struct{
	int front;
	int rear;
	int arr[MAX];
}CQ;
int IsFull(CQ *cq){
	if((cq->rear+1)%MAX==cq->front){
		printf("Queue is full!\n");
		return 1;
	}
	else return 0;
}
int IsEmpty(CQ *cq){
	if(cq->rear==cq->front){
                printf("Queue is empty!\n");
                return 1;
        }
        else return 0;
}
void insert(CQ *cq){
	int item;
	if(IsFull(cq)==1)return;
	printf("Enter item to be inserted:\n");
	scanf("%d",&item);
	cq->rear=(cq->rear+1)%MAX;
	//printf("rear: %d\n",cq->rear);
	cq->arr[cq->rear]=item;
}
void delete(CQ *cq){
	if(IsEmpty(cq)==1)return;
        cq->front=(cq->front+1)%MAX;
        printf("Delete element is %d\n",cq->arr[cq->front]);
}
void display(CQ *cq){
	if(IsEmpty(cq)==1)return;
	printf("Contents of circular queue are:\n");
	for(int i=(cq->front+1)%MAX;i!=cq->rear;i=(i+1)%MAX){
		printf("%d ", cq->arr[i]);
	}
	printf("%d ", cq->arr[cq->rear]);
	printf("\n");
}
int main(){
	CQ cq;
	cq.front=0;
	cq.rear=0;
	int ch;
	do{
		printf("Enter 1.Insert 2.Delete 3.Display 4.Quit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:insert(&cq);
			       break;
			case 2:delete(&cq);
			       break;
			case 3:display(&cq);
			       break;
			default:ch=4;
		}
	}
	while(ch!=4);
	return 0;
}
