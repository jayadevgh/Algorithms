#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve(){
	int N, P;
	cin >> N >> P;
	//cout << N << " " << P << "\n";
	stack<int> one; 
	stack<int> two;
	stack<int> three;
	string s1, s2;
	cin >> s1 >> s2;
	//cout << "\n";
	for(int i =0;i < N; i++){
		int x; x = s1[i]-'0';
		if(!one.empty()){
			if(x == one.top()) continue;
		}
		one.push(x);
		//cout << x << " ";
	}
	//cout << "\n";
	for(int i =0;i < N; i++){
		int x; x = s2[i]-'0';
		if(!two.empty()){
			if(x == two.top()) continue;
		}
		two.push(x);
		//cout << x << " ";
	}
	//cout << "\n";
	vector<pair<int, int>> ans;
	int cnt = 0;
	while(true){
		if(!one.empty() && !two.empty() && one.top() == two.top()){
			if(one.size() < two.size()){two.pop(); ans.push_back({2, 1});}
			else {one.pop(); ans.push_back({1, 2});};

		}
		else if(!one.empty() && !three.empty() && one.top() == three.top()){
			if(one.size() <= 1) {three.pop(); ans.push_back({3, 1});}
			//if
			else {one.pop(); ans.push_back({1, 3});}
		}
		else if(!two.empty() && !three.empty() && two.top() == three.top()){
			if(two.size() <= 1) {three.pop(); ans.push_back({3, 2});}
			else {two.pop(); ans.push_back({2, 3});}
		}
		else if(!one.empty() && !two.empty() && one.top() != two.top()){
			if(one.size() < two.size()){
				three.push(one.top());
				one.pop(); 
				ans.push_back({1, 3});
				
			}
			else {
				three.push(two.top());
				two.pop(); 
				ans.push_back({2, 3});
			};

		}else if(three.size() ==1 && one.empty() && two.size() == 1){
			one.push(three.top()); three.pop(); ans.push_back({3, 1}); 
		}
		else if(three.size() ==1 && two.empty() && one.size() == 1){
			two.push(three.top()); three.pop(); ans.push_back({3, 2});
		}

		if(cnt == 10){cout << "HI"; break;}
		if(one.size() == 1 && two.size() == 1 && three.empty()){
			//cout << one.size() << " " << two.size() << " " << three.size() << "\n";
			break;
		}
		cnt++;
	}
	//cout << "\n";
	if(P == 1) cout << ans.size() << "\n";
	if(P == 2 || P == 3){
		cout << ans.size() <<"\n";
		for(int i =0;i < ans.size(); i++){
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}
	//cout << "\n";
	//cout << "\n--\n--\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t;
  	cin >> t;
  	while(t--) { solve();}
}