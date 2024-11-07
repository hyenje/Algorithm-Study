#include<stdio.h>

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	
	int staircase;
	
	scanf("%d", &staircase);
	
	int stair[301] = {0};
	int point_case[301] = {0};
		
	for(int i = 0; i < staircase; i++){
		scanf("%d", &stair[i]);
	}
	
	point_case[0] = stair[0];
	point_case[1] = max(stair[0] + stair[1], stair[1]);
	point_case[2] = max(stair[0] + stair[2], stair[1] + stair	[2]);
	
	for(int i = 3; i < staircase; i++){
		
		point_case[i] =max(point_case[i - 2] + stair[i], point_case[i - 3] + stair[i- 1] + stair[i]);
	}
	
	printf("%d \n", point_case[staircase -1]);
	
	return 0;
}