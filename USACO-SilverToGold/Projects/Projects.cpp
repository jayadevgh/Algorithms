#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	long long n;
  	cin >> n;

  	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
  	vector<pair<long long, pair<long long, long long>>> arr;
  	for(long long i =0;i < n; i++){
  		long long a, b, p;
  		cin >> a >> b >> p;
  		arr.push_back({a, {b, p}});
  		// while(!pq.empty() && pq.top().first < b) {
  		// 	pq.pop();
  		// }
  	}
  	sort(arr.begin(), arr.end());

  	for(long long i =0;i < n; i++){
  		long long a = arr[i].first;
  		pair<long long, long long> bp = arr[i].second;
  		long long b= bp.first;
  		long long p = bp.second;
  		long long newp = 0;

  		while(!pq.empty() && pq.top().first < a) {
  			pair<long long, long long> pai = pq.top();
  			pq.pop();
  			newp = max(pai.second, newp);
  		}
  		// cout << a << " " << b << " " << p << "\n";
  		// cout << a << " " << newp << "\n";
  		// cout << b << " " << p + newp << "\n\n";
  		pq.push({a-1, newp});
  		pq.push({b, p + newp});
  	}

  	long long ans = 0;
  	while(!pq.empty()){
  		ans = max(ans, pq.top().second);
  		pq.pop();
  	}
  	cout << ans;
}	