//회의실 배정
//주어지는 것: 회의의 수, 회의가 시작하고 끝나는 정보. 

//회의시간이 가장 빨리 끝나는 시간부터 배정한다.

#include <stdio.h>
#include <stdlib.h>

//퀵정렬 - 최악의 경우 n^2의 시간복잡도를 가질 수 있음...

/*void Swap(int arr[], int a, int b) // a,b 스왑 함수 
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int Partition(int arr[],int arr2[], int left, int right)
{
    int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
    int low = left + 1;
    int high = right;
 
    while (low <= high) // 교차되기 전까지 반복한다 
    {
        while (low <= right && pivot >= arr[low]) // 피벗보다 큰 값을 찾는 과정 
        {
            low++; // low를 오른쪽으로 이동 
        }
        while (high >= (left+1)  && pivot <= arr[high]) // 피벗보다 작은 값을 찾는 과정 
        {
            high--; // high를 왼쪽으로 이동
        }
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
        {
            Swap(arr, low, high); //low와 high를 스왑 
            Swap(arr2,low, high);
        }
    }
    Swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환
    Swap(arr2, left, high); 
    return high;  // 옮겨진 피벗의 위치정보를 반환 
 
}
 
 
void QuickSort(int arr[], int arr2[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr,arr2, left, right); // 둘로 나누어서
        QuickSort(arr,arr2, left, pivot - 1); // 왼쪽 영역을 정렬한다.
        QuickSort(arr,arr2, pivot + 1, right); // 오른쪽 영역을 정렬한다.
    }
}*/


int main(){
    int n, timein[100001]={0},timeout[100001]= {0};
    int i,a=0, b=0;
    
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        scanf("%d %d",&timein[i],&timeout[i]);
    }
    //퀵소트를 이용해 오름차순 정렬
    QuickSort(timeout,timein, 0, n-1);

    /*for(i=0; i<n;i++){
        printf("%d %d\n", timeout[i],timein[i]);
    }*/

    for (i=0; i<n; i++){
        if(timein[i]<a) continue;
        else{
            a = timeout[i];
            b++;
        }
        //printf("a: %d b: %d\n", a, b);
    }

    printf("%d",b);
    return 0;
}