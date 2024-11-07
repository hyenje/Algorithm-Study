#include<iostream>
#include <queue>

using namespace std;

int main(){	
	int n; cin >> n;
	queue<pair<int,int>> s;
	s.push(make_pair(n, 0));
	
	while(!s.empty()){
		if(s.front().first == 1){
			cout << s.front().second << endl;
			break;
		}
		if(s.front().first%3 == 0)
			s.push(make_pair(s.front().first/3, s.front().second + 1));
		if(s.front().first%2 == 0)
			s.push(make_pair(s.front().first/2, s.front().second + 1));
		s.push(make_pair(s.front().first - 1, s.front().second + 1));
		s.pop();
	}
	
	return 0;
}