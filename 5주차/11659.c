//구간 합 구하기 4
//수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램

//수의 갯수 N, 구해야 하는 횟수 M
//N개의 수 주어짐 
//M개의 줄에 합을 구해야 하는 구간 i,j주어짐
//M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력

//누적합 알고리즘 
#include <stdio.h>

int main(){
    int n,m,i,j,a, b;
    int arr[100001] = {0}, pre[100001]={0};

    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++){
        scanf("%d",&j);
        pre[i] = pre[i-1] + j; 
        //누적합을 이용
    }

    while(m--){
        scanf("%d %d",&a,&b);
        printf("%d\n",pre[b] - pre[a-1]);
    }

    // 최대 n*m의 연산을 해야하므로 시간이 초과될 수 있음.
    /*for(k=0; k<m; k++){
        scanf("%d %d",&i,&j);
            for(l=i; l<=j; l++){
                pre[k] += arr[l];
            }
        printf("%d",pre[k]);
    }*/
} 