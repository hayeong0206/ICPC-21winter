// 피보나치 수2
// n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램 

#include <stdio.h>
#include <stdlib.h>

long long fib[100];

long long fibo(int n){
    if (fib[n]!= -1) return fib[n];
    if (n<2) return fib[n] =n;
    return fib[n] = fibo(n-1) + fibo(n-2);
}

int main(){
    int n;
    for (int i=0; i<100; i++) fib[i]=-1;
    scanf("%d",&n);
    printf("%lld",fibo(n));
}