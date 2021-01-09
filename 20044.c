//project Teams
//주어진 것: n개의 팀, 팀원 코딩 역량 

#include <stdio.h>
int main(){
    int N, n, arr[5001]={0}, a = 123456789;
    int i,j,temp;
    
    scanf("%d",&N);
    n = 2*N;
    //팀원의 능력치 입력받기
    for (i =0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    for(i=0; i<n; i++) printf("%d",arr[i]);
    printf("\n");

    //입력받은 능력치 오름차순으로 정렬하기. (버블정렬)
    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    /*for(i=0; i<n; i++) printf("%d",arr[i]);
    printf("\n");*/

    //팀원의 능력치 합의 최소가 최대가 되게 하는 수 구하기
    //(a1+an), (a2+an-2) ...
    for(i=0; i<n; i++){
        if(arr[i]+arr[n-i-1]<a){
            a=arr[i] + arr[n-1-i];
            //printf("%d\n",a);
        }
    }
    printf("%d",a);
}