//숨바꼭질
//수빈이가 있는 위치 n, 동생이 있는 위치 k
//수빈이가 동생을 찾는 가장 빠른 시간

//최단거리 -> bfs

#include <stdio.h>

int n,k;
int queue[250000] = {0}, check[100001] = {0}, front = -1, rear = -1;
int d[100001];

int main(){
    scanf("%d %d", &n, &k);
    if(n == k){
        printf("0");
        return 0;
    }
    queue[++rear] = n;
    while(front != rear){
        front++;
        if (check[queue[front]*2] == 0 && (queue[front]*2 < 100001) && (queue[front] * 2) >= 0){
            queue[++rear] = queue[front] * 2;
            d[rear] = d[front] + 1;
            check[queue[rear]] = 1;
        }
        if(queue[rear] == k) break;
        if(check[queue[front]-1]==0 && (queue[front]-1) < 100001 && queue[front]-1 >= 0){
            queue[++rear] = queue[front]-1;
            d[rear] = d[front] +1;
            check[queue[rear]] = 1;
        }
        if(queue[rear] == k) break;
        if(check[queue[front] + 1] == 0 && queue[front] + 1 < 100001 && queue[front] +1 >=0){
            queue[++rear] = queue[front]+1;
            d[rear] = d[front] +1;
            check[queue[rear]] = 1;
        }
        if(queue[rear] == k) break;
    }
    printf("%d",d[rear]);
    return 0;
}