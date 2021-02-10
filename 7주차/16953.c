//A와 B
// Graph 알고리즘

#include <stdio.h>

int a, b, count=0;

int dfs(int x){

    while(1){

        if(x<a){
            return -1;
            break;
        }
        if(a==x){
            count++;
            return count;
            break;
        }
        else if (x % 10 == 1){
            x = x / 10;
            count++;
        }
        else if (x % 2 == 0){
            x = x / 2;
            count++;
        }
        else return -1; 
    }
}

int main(){
    scanf("%d %d",&a, &b);

    printf("%d",dfs(b));
}