#include <stdio.h>
#include <stdlib.h>

#define QMAX 100
bool visited[QMAX] = {0};
int queue[QMAX], front = -1, rear = -1;

struct adj_list {
    int n;
    adj_list *next;
};

int GM[100][100] = {0};
adj_list *GL[100];

void addq(int n) {
    queue[++rear] = n;
}

int deleteq() {
    return queue[++front];
}

void dfs(int v) {
    adj_list *p;
    visited[v] = true;
    printf("%d}", v);
    for(p = GL[v]->next ; p ; p = p->next)
        if(!visited[p->n]) {
			printf(", {%d,", v);
			dfs(p->n);
        }
}

void bfs(int v) {
    adj_list *w = GL[v]->next;
    int flag = 0;
    // printf("%d", v);
    addq(w->n);
    visited[v] = true;
    while(front != rear) {
        v = deleteq();

        for(w = GL[v]->next ; w ; w = w->next) {
            if(!visited[w->n]) {
				if (flag) printf(", ");
				else flag = 1;
				printf("{%d,%d}", v, w->n);
                // printf(" %d", w->n);
                addq(w->n);
                visited[w->n] = true;
            }
        }
    }
}

void attach(int num, adj_list **p) {
    adj_list *temp = (adj_list *)malloc(sizeof(adj_list));
    temp->n = num;
    (*p)->next = temp;
    *p = temp;
}

int main() {
    int i, j, max = -1;
    adj_list *p;
    while(scanf("%d%d", &i, &j) != EOF) {
        GM[i][j] = GM[j][i] = 1;
        if(i >= max) max = i + 1;
        if(j >= max) max = j + 1;
    }

    for(i = 0 ; i < max ; ++i) {
        adj_list *rear = (adj_list *)malloc(sizeof(adj_list));
        GL[i] = rear;
        for(j = 0 ; j < max ; ++j) {
            if(GM[i][j]) {
                attach(j, &rear);
                rear->next = NULL;
            }
        }
    }

    printf("Adjacency list:\n");
    for(i = 0 ; i < max ; ++i) {
        p = GL[i]->next;
        printf("%d: %d", i, p->n);
        for(p = p->next ; p != NULL ; p = p->next)
            printf(" -> %d", p->n);
        printf(" -> end\n");
    }
    //dfs
    printf("\nAdjacency list Depth First Search:\n");
    printf("{0,");
    visited[0] = true;
    dfs(GL[0]->next->n);
    printf("\n");

    for(i = 0 ; i < max ; ++i)
        visited[i] = false;
    //bfs
    printf("\nAdjacency list Breadth First Search:\n");
    addq(0);
    bfs(0);
    printf("\n");
    return max;
}
