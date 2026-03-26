#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

int stack[MAX] , top=-1;

bool isEmpty(){
    return top==-1;
}

void push(int iteam){
    if(top==MAX-1){
        printf("Stack is overflow!");
    }

    else{
        stack[++top]=iteam;
    }
}

int pop(){
    if(isEmpty()){
        printf("Stack is underflow");
        return -1;
    }

    else{
        return stack[top--];
    }
}

int peek(){
    if(isEmpty()){
        printf("Stack underflow!");
        return -1;
    }

    else{
        return stack[top];
    }
}

void peep(){
    int i;
    if(isEmpty()){
        printf("Stack is empty!");
    }
    else{
        for(i=top; i>-1; i--){
            printf("%d \n",stack[i]);
        }
    }
}

int main(){
    int ch, data;

    do{
        printf("\n 1.Push \n 2.Pop \n 3.Peek \n 4.peep \n 5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1 :printf("Enter the data to insert:");
            scanf("%d",&data);
            push(data);
            break;

            case 2:printf("Popped element : %d",pop());
            break;

            case 3:printf("Top element is :%d",peek());
            break;

            case 4:printf("The stack contents are :\n");
            peep();
            break;

            case 5:break;
            default: printf("Enter vaild choice:");
            break;
        }
    }
    while(ch!=5);
}
