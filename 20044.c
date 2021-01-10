//project Teams
//주어진 것: n개의 팀, 팀원 코딩 역량 

#include <stdio.h>

void bubble(int arr[], int n){
    short temp,i,j;

    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int n, arr[10001]={0}, a = 123456789;
    //틀렸던 이유 - 팀의 갯수는 n, 팀원수는 2n이므로 팀원의 배열을 5001이 
    //아닌 10001로 잡아야함.
    short i,j;
    
    scanf("%d",&n);
    n = 2*n;
    //팀원의 능력치 입력받기
    for (i =0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    //입력받은 능력치 오름차순으로 정렬하기. (버블정렬)
    bubble(arr, n);

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