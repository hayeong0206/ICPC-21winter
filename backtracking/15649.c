//N과 M(1)
//자연수 N과 M이 주어진다.
//1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열 모두 출력 
//시간 제한 1초, 메모리 제한 512
//수열은 사전 순으로 증가하는 순서로 출력 

#include <stdio.h>

int N,M;
int ans[10];
int check[10];

int function(int num){
    int i;
    if (num==M){
        for (i=0; i<M; i++) printf("%d ",ans[i]);
        printf("\n");
        return num;
    }

    for (i=1; i<=N; i++){
        if(check[i]) continue;
        check[i] = 1;
        ans[num] = i;
        function(num+1);
        check[i] = 0;
    }
}
    

int main(){

    scanf("%d %d",&N, &M);
    function(0);
}