#include<iostream>

using namespace std;

int main(){	
	int n; cin >> n;
	int count = 0;
	
	for(int i = 2; i <= n; i++){
		if(i%125 == 0) count += 3;
		else if(i%25 == 0) count += 2;
		else if(i%5 == 0) count++;
	}
	
	cout << count << endl;
	
	return 0;
}