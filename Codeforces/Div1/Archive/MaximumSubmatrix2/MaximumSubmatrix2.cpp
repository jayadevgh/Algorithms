#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>());
  for(int i =0 ; i < n; i++){
  	string s;
  	cin >> s;
  	for(auto &ch : s){
  		arr[i].push_back((int)ch - 48);
  	}

  }
  for(int i =0;i < n; i++){
  	int sum = 0;
  	for(int j = m-1; j >= 0; j--){
  		if(arr[i][j] == 1) sum++;
  		else sum = 0;
  		arr[i][j] = sum;
  	}
  }
  // for(int i = 0; i < n; i++){
  // 	for(int j = 0; j < m; j++){
  // 		cout << arr[i][j] << " ";
  // 	}
  // 	cout << '\n';
  // }

  int ans = 0;
  priority_queue<int, vector<int>, greater<int> > pq;

  for(int i =0;i < m; i++){
  	
  	for(int j = 0; j < n; j++){
  		if(arr[j][i] != 0) pq.push(arr[j][i]);
  	}
  	int tempsize = pq.size()+1-1;
  	for(int j = 0; j < tempsize; j++){
  		int temp  =(pq.top() * pq.size());
  		//cout << pq.top() << " " << pq.size() << "\n";
  		if(ans < temp) {ans = temp; }
  		pq.pop();
  	}
  }
  cout << ans << "\n";
}