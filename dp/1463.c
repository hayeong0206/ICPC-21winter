//1로 만들기 

#include <stdio.h>

int dp[10000000];

int min(int a, int b){
    return (a<b) ? a:b;
}

int solve(int n){
    int i;
    dp[1] = 0;
    for(i=2; i<=n; i++){
        dp[i] = dp[i-1] +1;
        if (i%3 == 0) {
            dp[i]= min(dp[i/3]+1,dp[i]);
        }
        if (i%2 ==0) {
            dp[i]= min(dp[i/2]+1,dp[i]);
        }
    }
    return dp[n];
}

int main(){
    int num;
    scanf("%d",&num);
    printf("%d",solve(num));
}