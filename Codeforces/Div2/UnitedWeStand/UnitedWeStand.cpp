#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> b;
	vector<int> c;
	priority_queue<int> pq;

	for(int i =0;i < n; i++){
		int x; cin >> x;
		b.push_back(x);
		pq.push(x);
	}
	

	while(pq.size() > 0 && c.size() ==0){
		int count = 0;
		int count2 = 0;
		int x = pq.top();
		//cout << x << " ";
		pq.pop();
		for(int i =0;i < n; i++){
			count += (b[i] % x == 0);
			count2 += (b[i] == x);
		}
		if(count == count2){
			for(int i =0;i < count; i++) c.push_back(x);
		}
	}
	if(c.size() == 0 || c.size() == n) cout << -1 <<'\n';
	else{
		cout<<n-c.size()<< " "<<c.size()<<"\n";
		for(int i =0;i < n; i++){
			if(c[0] != b[i]) cout << b[i] << " ";
		}
		cout << "\n";
		for(int i =0;i < c.size(); i++) cout << c[i] << " ";
		cout << "\n";

	}
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0;i < t; i++){
  	solve();
  }
}