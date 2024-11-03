#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int n, m;
  	cin >> n >> m;

  	vector<vector<int>> m1(n, vector<int>(m));
  	vector<vector<int>> m2(n, vector<int>(m));
  	for(int i =0;i < n ;i++){
  		for(int j = 0; j < m ;j++){
  			cin >> m1[i][j];
  		}
  	}
  	for(int i =0;i < n ;i++){
  		for(int j = 0; j < m ;j++){
  			cin >> m2[i][j];
  		}
  	}
  	if((n==1 || m == 1) && m1 != m2 ){
  			cout << "NO";
  			return 0;
  	}
  	for(int i =0; i< (n+m-2); i++){
  		multiset<int> diag1, diag2;
  		for(int j =0; j <= i; j++){
  			if(j >= n || i-j >= m) continue;
  			diag1.insert(m1[j][i-j]);
  			diag2.insert(m2[j][i-j]);
  		}
  		if(diag1 != diag2){
  			cout << "NO";
  			return 0;
  		}
  	}
  	cout << "YES";
}