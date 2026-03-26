#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head=tail=NULL;
    }

    int count(){
        Node *temp=head;
        int c=1;
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        return c;
    }

    void push_front(int val){
        Node* newnode = new Node(val);

        if(head==NULL){
            head=tail=newnode;
            return;
        }

        else{
            newnode->next=head;
            head=newnode;
        }
    }

    void push_back(int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head=tail=newnode;
            
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    void push_pos(int pos, int val){
        Node* newnode = new Node(val);
        Node* temp=head;
        int c=1;
        int i=count();

        if(head==NULL){
            head=tail=newnode;
            return;
        }

        else if(pos==1){
            push_front(val);
            return;
        }
        
        else if(pos==i+1){
            push_back(val);
            return;
        }
        else if(pos>i+1){
            cout<<"Insertion is not possible!";
            return;
        }
        else{
            while(c<pos-1 && temp!=NULL){
                temp=temp->next;
                c++;
            }
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

    void pop_front(){
        if(head==NULL){
            printf("list is empty");
            tail=NULL;
            return ;
        }
        else{
            Node *temp=head;
            head=head->next;
            delete temp;
        }
    }

    void pop_back(){
        if(head==NULL){
            return;
        }
        else{
            Node *temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            tail->next = NULL;
        }
    }

    void pop_pos(int pos){
        Node* temp=head;
        Node* temp1;
        int c=1;
        int i=count();

        if(head==NULL){
            cout<<"Deletion is not possible!";
            return;
        }

        else if(pos==1){
            pop_front();
            return;
        }
        
        else if(pos==i){
            pop_back();
            return;
        }
        else if(pos>i){
            cout<<"Deletion is not possible!";
            return;
        }
        while(c<pos && temp->next != NULL){
            temp1=temp;
            temp=temp->next;
            c++;
        }
        temp1->next=temp->next;
        delete temp;
    }

    void search(int val){
        Node* temp=head;
        int c=1;
        while(temp!=NULL){
            if(temp->data==val){
                // printf("Data is found at %d position",c);
                cout<<"Data is found at "<<c <<" position";
                break;
            }
            temp=temp->next;
            c++;
            }
            cout<<"Data is not found!";
    }

    void Display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data << "->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    List ll;

    ll.pop_back();

    ll.push_front(4);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_pos(3,3);
    ll.pop_front();
    ll.pop_pos(3);
    ll.pop_back();
    ll.Display();
    ll.search(3);

    return 0;
}