#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node* insert(struct Node* root,int value) {
    if(root==NULL){
        return createNode(value);
    }
    if(value < root->data){
        root->left=insert(root->left,value);
    } else if (value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}

void inorder(struct Node* root){
    if (root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node* root=NULL;
    int n,value;
    printf("Enter the number of nodes to insert in BST: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter value for node %d: ",i+1);
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("\nInorder traversal of the BST: ");
    inorder(root);
    printf("\n");
    return 0;
}