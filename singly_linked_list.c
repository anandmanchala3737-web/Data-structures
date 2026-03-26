#include<stdio.h>
#include<stdlib.h>

struct node
{

    int data;
    struct node *next;
    
};
*head = NULL;

int count(){
    struct node *temp;
    int i=1;
    temp=head;
    while(temp->next != NULL){
        temp=temp->next;
        i++;
    }
    return (i);
}
/* creating list*/
struct node *create(int value){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    return temp;
}

/*Insertion begin*/
void insert_begin(int value){
    struct node *newnode;
    newnode=create(value);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
/*Insertion end*/
void insert_end(int value){
    struct node *newnode, *temp;
    newnode=create(value);
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void insert_pos(int value, int pos){
    struct node *newnode, *temp1, *temp2;
    int i,c=1;
    newnode=create(value);
    i=count();
    if(pos==1){
        insert_begin(value);
    }
    else if(pos>i+1){
        printf("Insertion is not possible!");
        return;
    }
    else{
        temp1=head;
        while(c<pos && temp1 != NULL){
            temp2=temp1;
            temp1=temp1->next;
            c++;
        }
        newnode->next=temp2->next;
        temp2->next=newnode;
    }
}

/*  */
void delete_begin(){
    struct node *temp;
    if(head==NULL){
        printf("Dletion is not possible!");
    }
    else{
        temp=head;
        head=temp->next;
        free(temp);
    }
}

/* Delete at end */
void delete_end(){
    struct node *temp1, *temp2;
    if(head==NULL){
        printf("Deletion is not possible");
    }
    else{
        temp1=head;
        while(temp1->next != NULL){
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        free(temp1);
    }
}

/*delete at a position*/
void delete_pos(int pos){
    struct node *temp1, *temp2;
    int i, c=1;
    i=count();
    if(pos==1){
        delete_begin();
    }
    else if(pos>i){
        printf("Dletion is not possible");
        return;
    }
    else{
        temp1=head;
        while(c<=pos && temp1->next != NULL){
            temp2=temp1;
            temp1=temp1->next;
            c++;
        }
        temp2->next=temp1->next;
        free(temp1);
    }
}

/*Disply*/
void display(){
    struct node *temp;
    if(head==NULL){
        printf("List is empty");
    }
    else{
        temp=head;
        while(temp->next != NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

/*main*/
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