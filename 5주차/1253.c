//좋다
//N개의 수 중에서 어떤 수 두 개의 합으로 나타낼 수 있다면 그 수를 "좋다"고 한다.
//N개의 수가 주어지면 그 중에서 좋은 수의 갯수 출력
//입력 - 수의 개수 N, i번째 수를 나타내는 Ai가 N개
//출력 - 좋은 수의 갯수 

#include <stdio.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(){
    int n,i, arr[2001];
    int check = 1, ans = 0, mid, num;
    int left, right;

    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,n,sizeof(int),compare);

    for(i=0; i<n; i++){
        left = 0; right = n-1;
        mid = arr[i];
        while(left<right){
            num = arr[left] + arr[right];
            if(num == mid){
                if(left != i && right != i){
                    ans++;
                    break;
                }
                else if(left == i){
                    left++;
                }
                else if(right == i){
                    right--;
                }
            }
            else if(num > mid){
                right --;
            }
            else{
                left++;
            }
        }
    }
    printf("%d", ans);
}