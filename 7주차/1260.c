// DFS 와 BFS
// 그래프를 dfs와 bfs로 탐색한 결과를 출력하는 프로그램 
//입력 - 정점의 개수 N, 간서의 개수 M, 탐색을 시작할 정점의 번호 V
//입력 - M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.

//출력 - 첫째줄에 DFS 수행한 결과, 두번째줄 BFS을 수행한 결과 (V부터 방문된 점을 순서대로 출력)

#include <stdio.h>

int arr[1001][1001] = {0};
int check[1001] = {0};
int n,m,v;
int queue[1001];


void dfs(int x){
    int i;
    printf("%d ",x);
    check[x] = 1;

    for(i=1; i<=n; i++){
        if(arr[x][i]==1 && check[i]==0){
            dfs(i);
        }
    }
    
}

void bfs(int x, int n){
    int front=1, rear=1;
    int i, pop;
    printf("%d ", x);
    queue[1] = x;
    rear++;
    check[x] = 1;
    
    while(front<rear){
        pop = queue[front];
        front++;

        for(i=1; i<=n; i++){
            if(arr[pop][i] == 1 && check[i]==0){
                printf("%d ",i);
                queue[rear] = i;
                rear++;
                check[i] = 1;
            }
        }
    }
    return;
}

int main(){
    int i, s, t;

    scanf("%d %d %d", &n, &m, &v);

    for(i=0; i<m; i++){
        scanf("%d %d", &s, &t);
        arr[s][t] = 1;
        arr[t][s] = 1;
    }
    dfs(v);
    for(i=0; i<=n; i++){
        check[i] = 0;
    }
    printf("\n");
    bfs(v,n);
}