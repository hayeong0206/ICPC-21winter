// DFS 와 BFS
// 그래프를 dfs와 bfs로 탐색한 결과를 출력하는 프로그램 
//입력 - 정점의 개수 N, 간서의 개수 M, 탐색을 시작할 정점의 번호 V
//입력 - M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.

//출력 - 첫째줄에 DFS 수행한 결과, 두번째줄 BFS을 수행한 결과 (V부터 방문된 점을 순서대로 출력)

#include <stdio.h>

int arr[1001][1001] = {-1};
int check[1001] = {0};
int n,m,v,i;

#define MAX 10001

int front=-1;
int rear=-1;
int queue[MAX];
 
int IsEmpty(void){
    if(front==rear)//front와 rear가 같으면 큐는 비어있는 상태 
        return 1;
    else return 0;
}
int IsFull(void){
    int tmp=(rear+1); //원형 큐에서 rear+1을 MAX로 나눈 나머지값이
    if(tmp==front)//front와 같으면 큐는 가득차 있는 상태 
        return 1;
    else
        return 0;
}
void addq(int value){
    if(IsFull()==1);
    else{
         rear = (rear+1);
         queue[rear]=value;
        }

}
int deleteq(){
    if(IsEmpty()==1);
    else{
        front = (front+1);
        return queue[front];
    }
}


void dfs(int x){
    if(check[x] == 1) return;
    
    printf("%d ",x);
    check[x] = 1;

    for(i=1; i<=n; i++){
        if(arr[x][i]==1){
            dfs(i);
        }
    }
    
}

void bfs(int x){
    addq(x);
    check[x] = 1;
    while(1){
        if(IsEmpty()==1) break;
        x = queue[front];
        printf("%d ",queue[front]);
        deleteq();
        for(i=1; i<=n; i++){
            if(check[i] == 0 || arr[x][i] == 1) continue;
            addq(i);
            check[i] = 1;
        }

    }
}

int main(){
    int s, t;

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
    bfs(v);
}