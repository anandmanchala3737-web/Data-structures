#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink;
    struct node *rlink;
} *head=NULL, *tail=NULL;

int count(){
    struct node *temp;
    int i=1;
    temp=head;
    while(temp->rlin pmk==head){
        temp=temp->rlink;
        i++;
    }
    return (i);
}

struct node *create(int value){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->llink=NULL;jbdjsjjj
    temp->rlink=NULL;

    return temp;
}

void insert_begin(int value){
    struct node* newnode;
    newnode=create(value);
    if(head==NULL){
        head=tail=newnode;
    }

    else{
        newnode->rlink=head;
        head->llink=newnode;
        newnode->llink=tail;
        tail->rlink=newnode;
        head=newnode;
    }
      
}

void insert_end(int value){
    struct node *newnode, *temp;
    newnode= create(value);
    if(head==NULL){
        head=tail=newnode;
    }

    else{
        tail->rlink=newnode;
        newnode->llink=tail;
        head->llink=newnode;
        newnode->rlink=head;
        tail=newnode;
    }
}

void insert_pos(int value, int pos){
    struct node *newnode, *temp, *temp1;
    int i, c=1;
    i=count();
    newnode=create(value);
    if(pos==1){
        insert_begin(value);
    }

    // else if(pos>i+1){
    //     printf("Insertion is not possible!");
    //     return ;
    // }

    else if(pos==i+1){
        insert_end(value);
    }

    else{
        temp=head;
        while(c<pos){
            temp=temp->rlink;
            c++;
        }
        temp1=temp->llink;
        temp1->rlink=newnode;
        newnode->llink=temp1;
        newnode->rlink=temp;
        temp->llink=newnode;
    }
}

void delete_begin(){
    struct node *temp;
    if(head==NULL){
        printf("Deletion is not possible");
    }

    else{
        temp=head;
        head=temp->rlink;
        if(temp==tail){
            head=tail=NULL;
        }

        else{
            head->llink=tail;
            tail->rlink=head;
        }
        free(temp);
    }
}

void delete_end(){
    struct node*temp;
    if(head==NULL){
        printf("Deletion is not possible");
    }

    else{
        temp=tail;
        tail=temp->llink;
        if(tail==head){
            tail=head=NULL;
        }
        else{
           tail->rlink=head;
           head->llink=tail; 
        }
        free(temp);
}
}

void delete_pos(int pos){
    struct node *temp, *temp1, *temp2;
    int i, c=1;
    i = count();
    if(pos==1){
        delete_begin();
    }

    // else if(pos>i){
    //     printf("Deletion id not possible!");
    //     return;
    // }

    else if(pos==i){
        delete_end();
        // printf("deleted!");
    }

    else{
        temp=head;
        while(c<pos){
            temp=temp->rlink;
            c++;
        }
        temp1=temp->llink;
        temp2=temp->rlink;
        temp1->rlink=temp2;
        temp2->llink=temp1;
        free(temp);
    }
}

void display(){
    struct node *temp;
    if(head==NULL){
        printf("List is empty");
    }
    else{
        temp=head;
        while(temp!=tail){
            printf("%d->",temp->data);
            temp=temp->rlink;
        }
    } printf("%d",temp->data);
}

void main(){
    int ch,pos,value;
    do
    {
        printf("\n 1.Insert Begin\n 2.Insert End\n 3.Insert position\n 4.Delete Begin\n 5.Delete End\n 6.Delete position\n 7.Display\n 8.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        printf("Enter the value:");
        scanf("%d",&value);
        insert_begin(value);
        break;

        case 2:
        printf("Enter the value:");
        scanf("%d",&value);
        insert_end(value);
        break;

        case 3:
        printf("Enter the value:");
        scanf("%d",&value);
        printf("Enter the position you want to insert:");
        scanf("%d",&pos);
        insert_pos(value,pos);
        break;

        case 4:delete_begin();
        break;

        case 5:delete_end();
        break;

        case 6:
        printf("Enter the position you want to delete:");
        scanf("%d",&pos);
        delete_pos(pos);
        break;

        case 7:
        display();
        break;

        case 8:
        break;

        default:printf("\n Your choice is wrong!....");
            break;
        }
    } while (ch!=8);
}
