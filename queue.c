#include<stdio.h>
int front=-1,rear=-1,q[5],maxsize=5,j;
void enqueue(){
if(front==-1 && rear==-1){
front=0;
rear=0;
printf("Enter the numbers into the queue:");
scanf("%d",&q[rear]);
for(j=front;j<=rear;j++){
printf(" %d ",q[j]);
}
}
else if(rear==maxsize-1){
printf("overflow\n");
for(j=front;j<=rear;j++){
printf("%d ",q[j]);
}
}
else{
rear++;
printf("Enter the numbers");
scanf("%d",&q[rear]);
for(j=front;j<=rear;j++){
printf("%d ",q[j]);
}
}
}
void dequeue(){
//dequeue
if(front==-1 && rear==-1){
printf("Underflow");
for(j=front;j<=rear;j++){
printf("\n%d ",q[j]);
}
}
else if(front<=rear){
printf("deleted element is %d",q[front]);
front++;
for(j=front;j<=rear;j++){
printf("\n%d ",q[j]);
}
}
else{
printf("underflow");
front=rear=-1;
for(j=front;j<=rear;j++){
printf("\n%d ",q[j]);
}
}
}
int main(){
int m,p;
printf("\nEnter the operation 1:enqueue 2:dequeue:");
scanf("%d",&p);
while(p==1 ||p==2){
if(p==1)
enqueue();
else if(p==2)
dequeue();
else
break;
printf("\nEnter the operation 1:enqueue 2:dequeue");
scanf("%d",&p);
}
return 0;
}
