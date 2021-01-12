//롤케이크
//친구 n명에게 롤케이크 1개씩 선물 받음 : 롤케이크의 개수 = n
//롤케이크의 길이는 a1,a2,...,an
//재현이는 길이가 10인 롤케이크만 먹음
//롤케이크를 잘라서 길이가 10인 롤케이크를 최대한 많이 만듦

//롤케이크 자르는 과정
//1. 자를 롤케이크를 고른다. 길이가 1보다 큰 롤케이크만 자를 수 있다. 고른 롤케이크의 길이 = x
//2. 0보다 크고, x보다 작은 자연수 y를 고른다.
//3. 롤케이크를 잘라 길이가 y, x-y인 롤케이크 두 개로 만든다.
//재현이는 롤케이크를 최대 M번 자를 수 있다.
//이때, 만들 수 있는 길이가 10인 롤케이크 개수의 최댓값을 구하는 프로그램을 작성하시오. 

//입력값: 첫째 줄: 롤케이크의 갯수 n, 자를 수 있는 최대 횟수 m
//둘째 줄: 롤케이크의 길이 an이 주어짐.
//출력값: 재현이가 만들 수 있는 길이가 10인 롤케이크 개수의 최댓값 출력
//10의 배수 먼저 잘라야함. ->10의 배수끼리 먼저 정렬 후 내림차순 정렬

#include <stdio.h>
#include <stdlib.h>

typedef struct cake{
    int ten;
    int cons;
}Cake;

int static compare (const void* first, const void* second){
    Cake * num1=((Cake*)first);
    Cake * num2=((Cake*)second);
    if(num1->ten>num2->ten) return 1 ;
    else if(num1->ten<num2->ten) return -1;
    else return 0;
}
int static compare2 (const void* first, const void* second){
    Cake * num1=((Cake*)first);
    Cake * num2=((Cake*)second);
    if(num1->cons>num2->cons) return -1 ;
    else if(num1->cons<num2->cons) return 1;
    else return 0;
}

int main(){
    int n,m,len[10000]={0};
    int i, count=0, origin=0, num=0;

    Cake *cake= (Cake *)malloc(sizeof(Cake)*n);

    scanf("%d %d", &n, &m);
    for (i=0; i<n; i++){
        scanf("%d",&len[i]);
    }

    for(i=0; i<n; i++){
        if (len[i] % 10 ==0){
            cake[i].ten = len[i];
        }
        else {
            cake[i].cons = len[i];
        }
    }

    for(i=0; i<n;i++){
        printf("%d ",cake[i].ten);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",cake[i].cons);
    }
    printf("\n");

    qsort(cake,n,sizeof(Cake),compare);
    qsort(cake,n,sizeof(Cake),compare2);
    
    

    for(i=0; i<n;i++){
        printf("%d ",cake[i].ten);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",cake[i].cons);
    }
    printf("\n");

    //10의 배수일 때 자르는 수
    for(i=0; i<n; i++){
        //if(cake[i].ten == 10) origin++;
        if(cake[i].ten != 0){
            if(count + (cake[i].ten/10) - 1 >m){
                num += m - count;
                break;
            }
            else{
                num += cake[i].ten/10;
                count +=((cake[i].ten/10)-1);
            }
        }
        printf("%d %d %d\n",count,num,origin);
    }
    printf("\n");
    //10의 배수가 아닐 때 자르는 수 
    for(i=0; i<sizeof(cake->cons); i++){
        if(cake[i].cons <10) break;
        else{
            if (count + (cake[i].cons / 10) <= m){
                num += cake[i].cons / 10;
                count += cake[i].cons / 10;
            }
            else if (count + (cake[i].cons / 10) > m){
                num += m - count;
                break;
            }
        }

        printf("%d %d %d\n",count,num, origin);
    }
    
    printf("%d",num);
    free(cake);
    return 0;
}