#include <stdio.h>
#include <stdbool.h>

#define max 20

typedef struct{
	int info[max];
	unsigned int n;
}Queue;

void Initialize(Queue *Q) {
	Q->n = 0;
}

bool IsEmpty(Queue Q) {
	if (Q.n) return false;
	else return true;
}

bool IsFull(Queue Q) {
	if (Q.n == max) return true;
	else return false;
}

void PushTop(int K, Queue *Q) {
	if (IsFull(*Q)) return;
	Q->info[Q->n] = K;
	Q->n++;
}

void PushBottom(int K, Queue *Q) {
	Q->n++;
	for (int i=Q->n-1; i >=1 ; i--) {
		Q->info[i] = Q->info[i-1];
	}
	Q->info[0] = K;
}

int PopBottom(Queue *Q) {
	if (IsEmpty(*Q)) return NULL;
	int k = Q->info[0];
	for (int i = 0; i < Q->n; i++) {
		Q->info[i] = Q->info[i + 1];
	}
	Q->n--;
	return k;
}

int PopTop(Queue *Q) {
	if (IsEmpty(*Q)) return NULL;
	Q->n--;
	int k = Q->info[Q->n];
	return k;
}

void Show(Queue Q) {
	if (IsEmpty(Q))
		return;
	for (int i = 0; i < Q.n; i++)
		printf("%d", Q.info[i]);
}

void main() {
    Queue Q;
	Initialize(&Q);
	PushBottom(5, &Q);
	PushBottom(3, &Q);
	PushTop(4, &Q);
	PushBottom(2, &Q);
	PushTop(5, &Q);
	PopTop(&Q);
	PopBottom(&Q);
	Show(Q);
}