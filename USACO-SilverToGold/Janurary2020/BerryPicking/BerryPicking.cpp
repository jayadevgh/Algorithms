#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//Console
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
  	int N, K;
  	cin >> N >> K;

  	priority_queue<int> pq;
  	priority_queue<int> baskets;

  	for(int i =0;i < N; i++){
  		int num;
  		cin >> num;
  		pq.push(num);

  	}
  	for(int i =0; i < K; i++) pq.push(0);
  	baskets.push(pq.top());
  	pq.pop();
  	//cout << baskets.top();
  	while(baskets.size() != K && !pq.empty()){
  		if((baskets.top() / 2) >= pq.top()){
  			int a = baskets.top()/2;
  			int b = baskets.top() - a;
  			baskets.push(a);
  			baskets.push(b);
  			baskets.pop();
  		}
  		else{
  			baskets.push(pq.top());
  			pq.pop();
  		}
  	}
  	int ans =0;
  	for(int i =0; i < K; i++){
  		if(i >= K/2) ans+= baskets.top();
  		baskets.pop();
  	}
  	cout << ans;
}