//N-Queen
//N*N 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제
//입력 - N , 출력 - 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수 
// 1<=N<=15

#include <stdio.h>

#define MAX 40

int N;
int isused1[MAX]; // 같은 열에 존재하는 퀸이 존재하는지 여부
int isused2[MAX]; // 우상 대각선에 존재하는 퀸이 존재하는 여부
int isused3[MAX]; // 좌상 대각선에 존재하는 퀸이 존재하는 여부
int cnt = 0; // 만족하는 배치 갯수 저장 

void solve(int level) {
	if (level == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (isused1[i] || isused2[i+level] || isused3[level-i+N-1])continue; 
		isused1[i] = 1;  
		isused2[i+level] = 1;
		isused3[level-i+N-1] = 1;
		solve(level + 1);
		isused1[i] = 0;
		isused2[i + level] = 0;
		isused3[level - i + N - 1] = 0;
	}
}

int main() {
	scanf("%d",&N);
	solve(0);
	printf("%d",cnt);
}