#include<stdio.h>

int main(){
	
	int dynamic[10] = {1, 2, 4};
	int T;
	
	
	scanf("%d", &T);
	
	int occation[T] = {0,};
	
	for(int i = 0; i < T; i++){
		
		scanf("%d", &occation[i]);
		
		if(occation[i] > 4){
			for(int j = 3; j < occation[i]; j++){
				dynamic[j] = dynamic[j - 1] + dynamic[j + -2] + dynamic[j -3];
			}
		}

	}
	
	for(int i = 0; i <T; i++){
		printf("%d \n", dynamic[occation[i] -1]);
	}
	
	return 0;
}