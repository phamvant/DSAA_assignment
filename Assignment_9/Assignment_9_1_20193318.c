#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} *Node;

int Left(int value, Node root){
    return value < root->data;
}

int Right(int value, Node root){
    return value > root->data;
}

Node Insert(Node root, int value){
    if(root == NULL){
        Node temp = (Node)malloc(sizeof(Node));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = value;
        // strcpy(temp->data, value);
        return temp;
    }
    if(Left(value, root))
        root->left = Insert(root->left, value);
    else if(Right(value, root))
        root->right = Insert(root->right, value);
    return root;
}

bool Search(Node root, int value){
    if(root == NULL)
        return false;
    if(root->data == value)
        return true;
    else if (Left(value, root))
        return Search(root->left, value);
    else if (Right(value, root))
        return Search(root->right, value);
}

void PreOrder(Node root){
    if(root != NULL){
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(Node root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

void PostOrder(Node root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
 
int main(){
    Node root = NULL;
    int n = 12345678;
    for(int i = 0; i < 8; i++){
        root = Insert(root, n % 10);
        n /= 10;
    }
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder: ");
    PostOrder(root);

    return 0;
}