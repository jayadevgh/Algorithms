#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rev(stack<int>& st){
	stack<int> a;
	while(st.size() > 0){
		a.push(st.top());
		st.pop();
	}
	st = a;
}
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	stack<int> st;
	for(int i =0;i < k; i++){
		int x; cin >> x;
		st.push(x);
	}
	rev(st);
	int exsz = n * m -2;
	set<int> empt;
	stack<int> ans;
	ans.push(k+1);
	int cnt =0;
	for(int i =0;i < k ;i++){
		int cur = st.top();
		st.pop();
		empt.insert(cur); cnt++;
		cout << ans.top() << "-" << cnt << " ";
		if(empt.find(ans.top() - 1) != empt.end()) {
			//cout << cur << "ans, ";
			ans.push(ans.top()-1);
			//if(cur != ans.top()) cnt--;
			cnt--;
		}
		if(cnt >= exsz){
			cout << "TIDAK\n";
			return; 
		}
	}

	cout << "YA\n";
}


int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t;
  	cin>> t;
  	while(t--){
  		solve();
  	}
}