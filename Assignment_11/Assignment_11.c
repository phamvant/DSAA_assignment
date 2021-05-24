#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count, sum;

typedef struct student
{
      char name[2];
      int id;
      char classes[2];
      int GPA;
}student;


typedef struct Tree
{
      student data;
      struct Tree* left;
      struct Tree* right;
}*Tree;


bool leftOf(const Tree root, const student data)
{
      return data.id < root->data.id;
}


bool rightOf(const Tree root, const student data)
{
      return data.id >= root->data.id;
}


void Put_out(const Tree root)
{
      printf("\nName: %s         |", root->data.name);
      printf("\nID: %d           |", root->data.id);
      printf("\nClass: %s        |", root->data.classes);
      printf("\nGPA: %d          |", root->data.GPA);
      printf("\n_______________________\n");
}


Tree Insert(Tree root, const student data)
{
      if(root == NULL)
      {
            Tree temp = (Tree)malloc(30); //Unknown sizeof(Tree)
            temp->left = NULL;
            temp->right = NULL;
            temp->data = data;
            return temp;
      }
      if(leftOf(root, data))
            root->left = Insert(root->left, data);
      else if(rightOf(root, data))
            root->right = Insert(root->right, data);
      return root;
}


void InOrder(const Tree root)
{
      if(root != NULL)
      {
            InOrder(root->left);
            Put_out(root);
            InOrder(root->right);
      }
}


void Ave_GPA(const Tree root)
{
      if(root != NULL)
      {
            Ave_GPA(root->left);
            count += 1;
            sum = sum + root->data.GPA;
            Ave_GPA(root->right);
      }
}


void Search_by_id(const Tree root, const int value)
{
      if(root->data.id == value)
            Put_out(root);
      else if(value < root->data.id)
            Search_by_id(root->left, value);
      else if(value >= root->data.id)
            Search_by_id(root->right, value);
      return;
}


void Search_by_name(const Tree root, char name[2])
{
      if(root != NULL)
      {
            Search_by_name(root->left, name);
            if(!strcmp(root->data.name, name))
            {
                  Put_out(root);
                  return;
            }
            Search_by_name(root->right, name);
      }
}


student leftMost(Tree root)
{
      while(1)
      {
            root = root->left;
            if(root->left == NULL)
                  break;
      }
      return root->data;
}


void best_st(Tree root)
{
      while(1)
      {
            root = root->right;
            if(root->right == NULL)
                  break;
      }
      Put_out(root);
}


Tree Delete_by_id(Tree root, int value)
{
      if(root == NULL)
            return root;
      if(value < root->data.id)
            root->left = Delete_by_id(root->left, value);
      else if(value > root->data.id)
            root->right = Delete_by_id(root->right, value);
      else
      {
            if(root->left == NULL)
            {
                  Tree temp = root->right;
                  free(root);
                  return temp;
            }
            if(root->right == NULL)
            {
                  Tree temp = root->left;
                  free(root);
                  return temp;
            }
            root->data = leftMost(root->right);
            root->right = Delete_by_id(root->right, root->data.id);
      }
      return root;
}


student Insert_data(int id, char name[2], char classes[2], int GPA)
{
      student st;
      st.id = id;
      strcpy(st.name, name);
      strcpy(st.classes, classes);
      st.GPA = GPA;
      return st;
}


int main(){
      Tree root = NULL;
      student s1, s2, s3, s4;
      s1 = Insert_data(1, "A", "X", 1);
      s2 = Insert_data(2, "B", "Y", 2);
      s3 = Insert_data(3, "C", "Z", 3);
      s4 = Insert_data(4, "D", "W", 4);
      root = Insert(root, s1);
      root = Insert(root, s3);
      root = Insert(root, s2);
      root = Insert(root, s4);
      printf("\n----------------------\n");
      InOrder(root);
      printf("\n--------Delete_student_B--------\n");
      root = Delete_by_id(root, 2);
      InOrder(root);
      printf("\n---------Search_by_name--------\n");
      Search_by_name(root, "A");
      printf("\n\n---------Best_student---------\n");
      best_st(root);
      printf("\n--------Average_GPA-------------\n\n");
      Ave_GPA(root);
      printf("GPA: %d\n", sum / count);
      printf("\n-------------End-----------------\n\n");
}