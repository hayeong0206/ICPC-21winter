//수 찾기

#include <stdio.h>
#include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

//재귀를 이용한 이진탐색을 이용하여 탐색
void BinarySearch(int *arr, int start, int end, int key) {
 
    if (start > end) {
        printf("0\n");
        return ; //key 값이 없을 때
    }
 
    int mid = (start + end) / 2;
 
    if (arr[mid] == key) {    //key 값을 찾았을 때
        printf("1\n");
        return ;
    } 
    else if (arr[mid] > key) { //key 값이 mid 의 값보다 작을때(왼쪽으로)
        return BinarySearch(arr, start, mid - 1, key);
        
    } 
    else {  //key 값이 mid 의 값보다 작을때(왼쪽으로)
        return BinarySearch(arr, mid + 1, end, key);
        
    }
}

int main(){
    int n, m, i, arr[100001]={0},ans[100001]={0}, num;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    
    qsort(arr,n,sizeof(int),compare);
    
    scanf("%d",&m);
    for(i=0; i<m; i++){
        scanf("%d",&ans[i]);
    }
    
    for(i=0;i<m; i++){
        BinarySearch(arr,0,n-1,ans[i]);
    }
    
}