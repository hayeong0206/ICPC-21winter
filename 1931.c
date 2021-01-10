//회의실 배정
//주어지는 것: 회의의 수, 회의가 시작하고 끝나는 정보. 

//회의시간이 가장 빨리 끝나는 시간부터 배정한다.

#include <stdio.h>
#include <stdlib.h>

typedef struct time{
    int in;
    int out;
}Time;

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

//병합 정렬 - 시간복잡도는 확실하게 O(nlog(n))을 만족하지만 메모리활용 비효율적
//메모리 초과로 실패
/*void merge(Time *time, int start, int middle, int end){
	int i = start;
	int j = middle + 1;
	int k = start;
    Time *temp_arr=(Time *)malloc(sizeof(Time)* (end+1));
	
	//비교하여 데이터정렬 및 삽입
	while(i<=middle && j<=end){
		if(time[i].out<=time[j].out) {
            temp_arr[k] = time[i++];
        }
		else if(time[i].out>time[j].out) {
            temp_arr[k] = time[j++];
        }
		k++;
	}
	
	//남은 데이터 삽입
	if(i>middle){
		for(int t=j;t<=end;++t){
			temp_arr[k] = time[t];
			++k;
		}
	}
	else{
		for(int t=i;t<=middle;++t){
			temp_arr[k] = time[t];
			++k;
		}
	}
	
	//임시 저장용 배열에 저장된 값을 원래 배열에 넣어줌
	for(int t=start;t<=end;++t){
		time[t] = temp_arr[t];
	}

    free(temp_arr);
}


void mergeSort(Time *arr, int start, int end){
	//크기가 1 일대 까지 호출, 1단위 까지 쪼갬
	if(start < end){
		int middle = (start + end) / 2;
		mergeSort(arr, start, middle);
		mergeSort(arr, middle+1, end);
		//다시 병합
		//merge(arr, start, middle, end);
        merge(arr,start, middle, end);
	}
}*/

int static compare (const void* first, const void* second){
    Time *timeA = ((Time *)first);
    Time *timeB = ((Time *)second);
    if(timeA->out<timeB->out) return -1 ;
    else if(timeA->out>timeB->out) return 1;
    else return 0;
}



int main(){
    int n;
    int i,a=0, b=0;

    scanf("%d",&n);
    
    Time *time=(Time *)malloc(sizeof(Time)*n);
    
    for(i = 0; i<n; i++){
        scanf("%d %d",&time[i].in,&time[i].out);
    }
    //printf("\n");
    //퀵소트를 이용해 오름차순 정렬
    //QuickSort(timeout,timein, 0, n-1);
    //mergeSort(time, 0,n-1);

    qsort(time,n,sizeof(Time),compare);

    /*for(i=0; i<n;i++){
        printf("%d %d\n", time[i].out,time[i].in);
    }*/

    for (i=0; i<n; i++){
        if(time[i].in<a) continue;
        if(time[i].out==time[i+1].out&&time[i].in>=time[i].in) b++;
        else{
            a = time[i].out;
            b++;
        }
        //printf("a: %d b: %d\n", a, b);
    }

    printf("%d",b);
    free(time);
    return 0;
}