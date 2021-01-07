//한조서열정리하고옴 ㅋㅋ

#include <stdio.h>

int main(){
    int n,i,a=0, mt[100001] = {0};
    int max, ans = 0;

    //산봉우리의 개수, 높이 입력
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&mt[i]);
    }

    max = mt[0];

    //산봉우리의 높이 확인- 뒤에있는 산봉우리의 높이가 더 낮으면 a+1
    //뒤에 있는 산봉우리의 높이가 더 높으면 a 값 초기화 
    for(i = 0; i<n; i++){
        if(max>mt[i]){
            a++;
        }
        else if (max<mt[i]){
            max = mt[i];
            if(a> ans){
                ans = a;
            }
            a=0;
            //공격수 중 최댓값 찾기
        }
    }

    if (a > ans) {
        ans = a;
    }
    printf("%d",ans);
}