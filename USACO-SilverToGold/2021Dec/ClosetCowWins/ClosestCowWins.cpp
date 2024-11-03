#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int K, M, N;
  	cin >> K >> M >> N;
  	vector<ii> grass;
  	vector<int> nhoj(M);
  	for(int i =0;i < K; i++){
  		int pos, taste;
  		cin >> pos >> taste;
  		grass.push_back(make_pair(pos, taste));
  	}
  	for(int i =0;i < M; i++){
  		cin >> nhoj[i];
  	}
  	priority_queue<int> pq;
  	sort(grass.begin(), grass.end());
  	sort(nhoj.begin(), nhoj.end());
  	ii a = grass[0];
  	int aidx =0;
  	int sum = 0;

  	//not accounting for M =1 for now.

  	vector<ii> line;

  	int j =0;
  	for(int i =0;i < M-1; i++){
  		while(j < K && grass[j].first < nhoj[i]){
  			line.push_back(make_pair(0, j));
  			j++;
  		}
  		if(grass[j].first == nhoj[i]) j++;
  		line.push_back(make_pair(1, i));
  	}
  	while(j < K){
		line.push_back(make_pair(0, j));
		j++;
	}
	for(ii a : line){
		cout << a.first << " " << a.second << "\n";
	}
}