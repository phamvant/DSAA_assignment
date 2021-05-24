#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct SV{
  char name[50];
  int MS;
}SV;

typedef struct LinkedList{
  SV data;
  struct LinkedList *next;
}*node;

node CreatNode(SV info){
  node temp;
  temp = (node)malloc(sizeof(struct LinkedList));
  temp->next = NULL;
  temp->data = info;
  return temp;
}

SV InputValue(){
  SV info;
  printf("\nMS : ");
  scanf("%d", &info.MS);
  fflush(stdin);
  printf("\nName : ");
  gets(info.name);
  return info;
}

node AddHead(node head){
  SV info = InputValue();
  node temp = CreatNode(info);
  if(head == NULL)
    head = temp;
  else{
    temp->next = head;
    head = temp;
  }
  return head;
}

node AddTail(node head){
  SV info = InputValue();
  node temp, p;
  temp = CreatNode(info);
  if(head == NULL)
    head = temp;
  else{
    p = head;
    while(p->next != NULL)
      p = p->next;
    p->next = temp;
  }
  return head;
}

int Search(node head){
  printf("\n=== Insert Search Value ===");
  SV info;
  printf("\nMS: ");
  scanf("%d", &info.MS);
  int pos = 0;
  for(node p = head; p != NULL; p = p->next){
    if(p->data.MS == info.MS)
      return pos;
    pos++;
  }
  return -1;
}

node AddAt(node head){
  int pos = Search(head);
  if(pos == 0 || head == NULL){
    head = AddHead(head);
  }else{
    int k = 1;
    node p = head;
    while(p != NULL && k != pos){
      p = p->next;
      k++;
    }
    if(k != pos){
      head = AddTail(head);
    }else{
      node temp = CreatNode(InputValue());
      temp->next = p->next->next;
      p->next->next = temp;
    }
  }
  return head;
}

node DelHead(node head){
  if(head == NULL)
    printf("Nothing to del");
  else
    head = head->next;
  return head;
}

node DelTail(node head){
  if(head == NULL || head->next == NULL)
    return DelHead(head);
  node p = head;
  while(p->next->next != NULL){
    p = p->next;
  }
  p->next = p->next->next;
  return head;
}

node DelAt(node head){
  printf("\n=== Insert Delete Position ===");
  int pos = Search(head);
  if(pos == 0 || head == NULL || head->next == NULL)
    head = DelTail(head);
  else{
    int k = 1;
    node p = head;
    while(p->next->next != NULL && k != pos){
      p = p->next;
      k++;
    }
    if(k != pos){
      head = DelTail(head);
    }else{
      p->next = NULL;
    }
  }
  return head;
}

void Travel(node head){
  printf("\n");
  for(node p = head; p != NULL; p = p->next)
    printf("%s - %d\n", p->data.name, p->data.MS);
}

node InitHead(){
  node head;
  head = NULL;
  return head;
}

void SelectMode(){
  printf("=== Select Feature ===\n");
  printf("[1]: Add head\n");
  printf("[2]: Add tail\n");
  printf("[3]: Search by code\n");
  printf("[4]: Add after\n");
  printf("[5]: Delete by code\n");
  printf("[0]: Travel -> Exit\n");
  printf("=======================\n");
}

int main(){
  int mode, i, x;
  node head = InitHead();
  do{
    system("cls");
    SelectMode();
    printf("\nMODE: ");
    scanf("%d", &mode);
    switch (mode)
    {
    case 1:
      printf("\n=== Add head ===");
      head = AddHead(head);
      break;
    
    case 2:
      printf("\n=== Add tail ===");
      printf("\nNumber of element: ");
      scanf("%d", &x);
      for(i = 0; i < x; i++)
        head = AddTail(head);
      break;

    case 3:
      printf("\n=== Search by code ===");
      node p = head; int k = 0;
      int temp = Search(head);
      while(k != temp){
        p = p->next;
        k++;
      }
      printf("%s", p->data.name);
      fflush(stdin);
      getch();
      break;
    
    case 4:
      printf("\n=== Add after ===");
      AddAt(head);
      break;

    case 5:
      printf("\n=== Delete by code ===");
      DelAt(head);
      break;

    default:
      printf("\n====================\n");
      Travel(head);
      break;
    }
  }while(mode != 0);
}