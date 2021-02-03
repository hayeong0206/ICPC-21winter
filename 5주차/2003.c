//수들의 합2 
//N개의 수로 된 수열, 경우의 수 출력하기 

#include <stdio.h>

int main(){
    int n,m,i, arr[10001] = {0}, sum= 0;
    int left= 0, right = 0, count = 0;

    scanf("%d %d", &n, &m);

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sum = arr[0];

    while( right <= n-1){
        if(sum < m) {
            right++;
            sum +=arr[right];
        }
        else if(sum == m){
            count++;
            right++;
            sum +=arr[right];
        }
        else{
            sum -= arr[left];
            left++;
        }

    }
    printf("%d",count);
}