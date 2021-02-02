//구간합 구하기

#include <stdio.h>


int main(){
    int n,m,d, i,j, x1, x2, y1, y2;
    int pre[1024][1024] = {0} ;

    scanf("%d %d",&n,&m);

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d",&d);
            pre[i][j] = d + pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1];
        }
    }

    for(i=0; i<m; i++){
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        printf("%d\n", pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1]);
    }
    return 0;
}