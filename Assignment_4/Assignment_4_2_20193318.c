#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mon{
  unsigned int Ma;
  char Ten[50];
  int TinChi;
}Mon;

typedef struct LinkedList{
  Mon data;
  struct LinkedList *next;
}*node;

node CreatNode(Mon info){
  node temp;
  temp = (node)malloc(sizeof(struct LinkedList));
  temp->next = NULL;
  temp->data = info;
  return temp;
}

node head;

void AddHead(Mon info){
  node temp = CreatNode(info);
  if(head == NULL)
    head = temp;
  else{
    temp->next = head;
    head = temp;
  }
}

void AddTail(Mon info){
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
}

int Search(int value){
  int pos = 0;
  for(node p = head; p != NULL; p = p->next){
    if(p->data.TinChi == value)
      return pos;
    pos++;
  }
  return -1;
}

void Add(Mon info){
  node p = head;
  if(p == NULL || p->data.TinChi > info.TinChi){
    AddHead(info);
    return;
  }
  while(p->next->data.TinChi < info.TinChi){
    p = p->next;
  }
    node temp = CreatNode(info);
    temp->next = p->next;
    p->next = temp;
}

void Del(int value){
  int pos = Search(value);
  node p = head;
  if(pos == 0 || head == NULL || head->next == NULL)
    head = head->next;
  else{
    int k = 1;
    node p = head;
    while(p->next->next != NULL && k != pos){
      p = p->next;
      k++;
    }
    if(k != pos){
      printf("Nothing no del");
    }else{
      p->next = p->next->next;
    }
  }
}

void Travel(){
  printf("\n");
  for(node p = head; p != NULL; p = p->next)
    printf("%d - %s - %d\n", p->data.Ma, p->data.Ten, p->data.TinChi);
}

Mon input(int Ma, char* Ten, int TinChi){
  Mon temp;
  temp.Ma = Ma;
  strcpy(temp.Ten, Ten);
  temp.TinChi = TinChi;
  return temp;
}

int main(){
  Mon Math, DSAA, DE, IF;
  Math = input(1121, "Math", 4);
  DE = input(2200, "DE", 2);
  DSAA = input(2100, "DSAA", 3);
  IF = input(2201, "RAN", 1);
  printf("\nTin chi dau vao: %d - %d - %d - %d\n", Math.TinChi, DE.TinChi, DSAA.TinChi, IF.TinChi);
  Add(Math);
  Add(DSAA);
  Add(DE);
  Add(IF);
  Travel();
  printf("\nXoa mon 3 tin chi\n");
  Del(3);
  Travel();
}