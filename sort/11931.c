//수 정렬하기 4
//n개의 수가 주어졌을 때, 이를 내림차순으로 정렬하는 프로그램을 작성

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    if(*(int*)a>*(int*)b) return -1;
    else if(*(int*)a<*(int*)b) return 1;
    else return  0;
}

int main(){
    int n, i, arr[1000001] = {0};

    scanf("%d",&n);

    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,n,sizeof(int),compare);

    for(i=0; i<n; i++){
        printf("%d\n",arr[i]);
    }
}