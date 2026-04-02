#include<stdio.h>

struct root{
    int root;
    struct root *right;
    struct root *left;
};

void create_tree(int val){
    struct root *root;
    root=(struct root*)malloc(sizeof(struct root));
    if(root==NULL){
        root=val;
    }

    else if(root>val){
        root->left=val;
    }
    else if(root<val){
        root->right=val;
    }
}

int main(){
    int val;

    printf("Enter the data:");
    scanf("%d",&val);

    create_tree(val);

    return 0;
}