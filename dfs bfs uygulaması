#include <stdio.h>
#include <stdlib.h>

#define MAX 10


typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[MAX];
int visited[MAX];


Node* yeni_dugum(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->vertex = v;
    n->next = NULL;
    return n;
}


void kenar_ekle(int src, int dest) {
    Node* n = yeni_dugum(dest);
    n->next = graph[src];
    graph[src] = n;

    n = yeni_dugum(src);
    n->next = graph[dest];
    graph[dest] = n;
}


void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = graph[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFS(temp->vertex);
        temp = temp->next;
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        Node* temp = graph[v];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main() {

    for (int i = 0; i < MAX; i++)
        graph[i] = NULL;


    kenar_ekle(0, 1);
    kenar_ekle(1, 2);
    kenar_ekle(0, 3);
    kenar_ekle(1, 4);
    kenar_ekle(3, 4);

    printf("DFS: ");
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;
    DFS(0);

    printf("\nBFS: ");
    BFS(0);

    return 0;
}
