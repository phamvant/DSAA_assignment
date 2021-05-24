#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node *next;
}*Node;
 
Node Createtemp(int data) {
    Node temp = (Node) malloc (sizeof(Node));
    temp -> data = data;
    return temp;
}
 
void Display(Node Cir) {
    Node current = Cir;
    if (Cir != NULL) {
        do {
            current = current -> next;
            printf(" %d -> ", current -> data);
        } while (current != Cir);
    }
}

int Length(Node Cir) {
    Node current = Cir;
    int i = 1;
    if (Cir == NULL) {
        return 0;
    } else {
        current = current -> next;
        while (current != Cir) {
            i++;
            current = current -> next;
        }
    }
    return i;
}
 
Node AddHead(Node Cir, int data) {
    Node temp = Createtemp(data);
    if (Cir == NULL) {
        Cir = temp;
        temp -> next = temp;
    } else {
        temp -> next = Cir -> next;
        Cir -> next = temp;
    }
    return Cir;
}
 
Node AddEnd(Node Cir, int data) {
    return AddHead(Cir, data) -> next;
}
 
Node AddAt(Node Cir, int data, int location) {
    int len = Length(Cir), i;
    if (location < 1 || location > len + 1) {
        printf("\nInvalid location to enter data\n");
    } else {
        if (Cir == NULL) return AddHead(Cir, data);
        Node temp = Createtemp(data), current = Cir;
        for (i = 1; i != location; i++) current = current->next;
        temp -> next = current -> next;
        current -> next = temp;
        if (location == len + 1) Cir = temp;
    }
    return Cir;
}
 
Node DeleteAt(Node Cir, int data) {
    Node current = Cir, previous;
    if (Cir == NULL) return Cir;
    else if (Cir == Cir -> next) {
        if (Cir -> data == data) {
            Cir = NULL;
            free(current);
        }
        return Cir;
    }
    do {
        previous = current;
        current = current -> next;
        if (current -> data == data) {
            previous -> next = current -> next;
            if (current == Cir) Cir = previous;
            free(current);
            current = previous -> next;
        }
    } while (current != Cir);
    return Cir;
}
 
int main() {
    Node Cir = NULL;
    AddHead(Cir, 5);
    AddEnd(Cir, 6);
    AddAt(Cir, 2, 1);
    DeleteAt(Cir, 5);
    Display(Cir);
    return 0;
}