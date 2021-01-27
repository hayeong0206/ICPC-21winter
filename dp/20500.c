//Ezreal 여눈부터 가네 ㅈㅈ

//입력 -> N이 주어진다
//1과 5로만 구성된 N자리 양의 정수 중에서 15의 배수 갯수를 구한다.
//출력 -> 갯수를 1000000007로 나눈 나머지를 출력한다.

#include <stdio.h>
#include <math.h>
#define MAX 1000000007

long long combi[1600][1600];

int main(){
    int n, arr[1515], i,ans=0;

    scanf("%d",&n);

    combi[2][0] = 1;
    combi[2][1] = 1;

    for(i=3; i<n+1; i++){
        combi[i][0] = (combi[i-1][1] + combi[i-1][2])%MAX;
        combi[i][1] = (combi[i-1][0] + combi[i-1][2])%MAX;
        combi[i][2] = (combi[i-1][1] + combi[i-1][0])%MAX;
    }
    
    ans= combi[n][0] % MAX;

    printf("%d",ans);
}