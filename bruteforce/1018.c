// 체스판 다시 칠하기
// m*n 크기의 보드, 체스판의 상태 입력 
// B -검은색, W - 흰색
// 다시 칠해야 하는 정사각형 개수의 최솟값 출력 

#include <stdio.h>

int Min(int a, int b, int c){
     if (a < b && a < c)
          return a;

     else if (b < a && b < c)
          return b;

     else
          return c;

}

int main(){
    int M,N, i,j, ans =1e9, a,b;
    char arr[51][51] = {0};
    int num1=0, num2=0;

    //행과 열 입력 
    scanf("%d %d", &N, &M); 

    //체스판의 색 입력 
    for(i=0; i<N; i++){
        scanf("%s", arr[i]);
    } 

    
    //검사하기 왼쪽 위 첫번째 칸이 흰색 -> 다음 색은 검은 색 

    for(i=0; i<=N-8; i++){
        for(j=0; j<=M-8; j++){
            num1=0; num2=0;
            for(a=i; a< i+8; a++){
                for(b=j; b< j+8; b++){
                    if(arr[a][b] == 'W') {
                        if((a+b) %2 == 0) num1++;
                        else num2++;
                    }
                    else {
                        if((a+b)%2 == 0) num2++;
                        else num1++;
                    }
                }
            }
            printf("%d %d %d\n",ans,num1,num2);
            ans = Min(ans, num1, num2);
        }
    }

    //답 출력
    printf("%d",ans);
}