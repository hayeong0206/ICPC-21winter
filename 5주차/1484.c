//다이어트
//입력 - G (빠진 몸무게)
//출력 - 가능한 성원이의 현재 몸무게 , 가능하지 않으면 -1 출력 

#include <stdio.h>

int main(){
    int G, a=1;
    unsigned int origin, diet;

    scanf("%d",&G);

    for(origin = 2; origin <= 50000; origin ++){
        if(origin>G) break;
        for(diet = 1; diet <= origin; diet++){
            if(origin + diet > G) break;
            else if((origin+diet) * (origin - diet) == G){
                printf("%d\n",origin);
                a=0;
            }
            
        }
    }
    if(a==1){
        printf("-1");
    }
}