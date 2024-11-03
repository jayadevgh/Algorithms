#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int n, k;
  	cin >> n >> k;
  	vector<vector<char>> grid(4, vector<char>(n, '.'));
  	cout << "YES\n";

  	if(k%2 == 0){
  		for(int i = 1;i < (k/2)+1; i++){
  			grid[1][i] = '#';
  			grid[2][i] = '#';
  		}

  	}
  	else if(k%2 == 1){
  		grid[1][n/2] = '#';
  		k--;
  		for(int i =1;i < n/2; i++){
  			if(k==0) break;
  			grid[1][i] = '#';
  			grid[1][n-i-1] = '#';
  			k-= 2;
  		}
  		if(k != 0){
  			for(int i =1;i < (k/2)+1; i++){
	  			grid[2][i] = '#';
	  			grid[2][n-i-1] = '#';
	  			
	  		}
  		}
  	}

  	for(vector<char> row : grid){
  		for(char c : row) cout << c << "";
  		cout << "\n";
  	}

}