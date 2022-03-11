#include<stdio.h>
#include<stdlib.h>
#define n 10

int arr[n],front=-1,rear=-1,graph[10][10],u[6],visited[10],k=0,v;

int isFull(){
    if(rear==n-1)
        return 1;
    return 0;
}

int isEmpty(){
    if(front==rear)
        return 1;
    return 0;
}

void push(int item){
    if(isFull())
        printf("Queue is full!!\n");
    else{
        rear=rear+1;
        arr[rear]=item;
    }
}

int pop(){
    if(isEmpty())
    printf("Queue is empty!!\n");
    else{
        front=front+1;
        // printf("Deleted %d!",arr[front]);
        return arr[front];
    }
}

void display(){
    if(isEmpty())
    printf("Queue is empty!");
    else{
        printf("\nQueue is: \n");
        for (int i = front+1; i <= rear; i++){
            printf("%3d",arr[i]);
        }
        printf("\n");
    }
}

void bfs(int a){
    FILE *fp=fopen("abc.txt","r");
    fscanf(fp,"%d",&v);
    printf("vertix=%d",v);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
        fscanf(fp,"%d",&graph[i][j]);
    }
    for(int i=0;i<v;i++)
    visited[i]=0;
    push(a);
    u[k]=a;
    visited[0]=1;
    while(!isEmpty()){
        u[k]=pop();
        for(int i=0;i<v;i++){
            if(graph[k][i]==1){
                if(visited[i]==0){
                    push(a+i);
                    visited[i]=1;
                }
            }
        }
        k++;
    }
}
int main()
{
    bfs(65);
    printf("\n");
    for(int i=0;i<v;i++){
        printf("%3c",u[i]);
    }
    return 0;
}