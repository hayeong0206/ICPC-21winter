//게임을 만든 동준이
//주어진 것 : n개의 레벨 수, 각 레벨을 클리어하면 얻는 점수(<20000)
//문제 : 레벨을 올라갈 때마다 점수가 올라가야 하는데, 실수로 높은 레벨에 낮은 점수가 주어질 때가 생감
//전 레벨보다 큰 점수를 얻기 위해서 점수를 감소시키려고 한다
//점수 줄이는 횟수를 최소한으로 하고자 한다.
//1만큼 감소시키는 것이 1번

#include <stdio.h>

int main(){
    int n,i, score[101]= {0}, ans = 0;

    //레벨과 점수 입력
    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%d",&score[i]);
    }

    //오름차순- 뒤에 수가 더 작다면 뒷 수 - 앞 수 +1
    //아니라면 넘기기
    /*for(i = 0; i<n-1; i++){
        if(score[i]>=score[i+1]){
            ans += score[i] - score[i+1] +1;
            score[i] -= score[i] - score[i+1] +1;
        }
    }*/
    //결과 - 실패
    //왜?

    //내림차순- 앞의 수가 더 크다면 앞수 - 뒷 수 +1
    //아니라면 넘기기, 
    //앞수의 점수 바꾸기 
    for(i = n-2; i>=0; i--){
        if(score[i]>= score[i+1]){
            ans += score[i] - score[i+1] +1;
            score[i] -= score[i] - score[i+1] +1;
        }
    }

    printf("%d", ans);
}