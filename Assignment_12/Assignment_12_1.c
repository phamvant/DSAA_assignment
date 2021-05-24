#include <stdio.h>
#include <stdlib.h>
#define NULL ( (void *) 0)

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}*node_t;

int sum = 0, count = 0;

void Free(node_t root)
{
    if(root == NULL)
        return
    free(root->left);
    free(root->right);
    free(root);
}

int LeftOf(const int value, const node_t root)
{
    return value < root->data;
}

int RightOf(const int value, const node_t root)
{
    return value > root->data;
}

node_t Insert(node_t root, const int value)
{
    if(root == NULL)
    {
        node_t temp = (node_t)malloc(sizeof(node_t));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = value;
        return temp;
    }
    if(LeftOf(value, root))
        root->left = Insert(root->left, value);
    else if(RightOf(value, root))
        root->right = Insert(root->right, value);
    return root;
}

int Search(const node_t root, int value)
{
    if(root == NULL)
        return 0;
    if(root->data == value){
        return 1;
    }else if(LeftOf(value, root)){
        return Search(root->left, value);
    }else if(RightOf(value, root)){
        return Search(root->right, value);
    }return 0;
}

int LeftMost(node_t root)
{
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

int RightMost(node_t root)
{
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

node_t Delete(node_t root, int value)
{
    if(root == NULL)
        return root;
    if(LeftOf(value, root))
        root->left = Delete(root->left, value);
    else if(RightOf(value, root))
        root->right = Delete(root->right, value);
    else
    {
        if(root->left == NULL)
        {
            node_t temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL)
        {
            node_t temp = root->left;
            free(root);
            return temp;
        }
        root->data = LeftMost(root->right);
        root->right = Delete(root->right, root->data);
    }
    return root;
}

void InOrder(node_t root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

void Sum(node_t root){
    if(root != NULL)
    {
        Sum(root->left);
        Sum(root->right)            ;
        sum += root->data;
        count += 1;
    }
}

int main(){
    printf("\n============Binary Search Tree===========\n\n");
    node_t root = NULL;
    root = Insert( root, 1);
    root = Insert( root, 9);
    root = Insert( root, 5);
    root = Insert( root, 8);
    root = Insert( root, 2);
    root = Insert( root, 7);
    Delete(root, 9);
    root = Insert( root, 3);
    printf("InOrder: ");
    InOrder(root);
    Sum(root);
    int search_value = 5;
    if(Search(root, search_value))
        printf("\n\nFound a node with key = %d\n", search_value);
    else
        printf("Not found!");
    printf("\nNumber of Elements: %d\nSum: %d\n\n", count, sum);
}