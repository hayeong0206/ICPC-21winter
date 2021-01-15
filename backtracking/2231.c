//분해합
//어떤 자연수 n
//n의 분해합은 n과 n을 이루는 각 자리수의 합
//256 = 245+2+4+5
//자연수 n이 구해졌을 때 n의 가장 작은 생성자를 구해내는 프로그램 

#include <stdio.h>

int main(){
    int i,N, ans=0,temp,k;

    scanf("%d",&N);

    for(i=0; i<N; i++){
        ans=i;
        temp = i;
        while(temp){
            ans+= temp%10;
            temp /= 10;
        } 
        if(N == ans){
            printf("%d",i);
            return 0;
        }
    }
    printf("0");
}