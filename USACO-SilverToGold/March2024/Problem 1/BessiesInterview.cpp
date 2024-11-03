#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, K;

vector<ll> line;

struct DSU {
	vector<ll> father;
	vector<ll> size;

	DSU(ll n) {
		// we can use nodes from 0 to n (inclusive)
		father.resize(n + 1);
		size.resize(n + 1);

		for(ll i = 0; i <= n; i++) {
			father[i] = i;
			size[i] = 1;
		}
	}

	ll find(ll x) {
		if(father[x] == x) {
			return x;
		}
		return father[x] = find(father[x]); // Path-compression - Optimization 1
	}

	bool unite(ll x, ll y) { // -> return true if and only if x and y were in different sets
		x = find(x);
		y = find(y);

		if(x == y) {
			return false; // If the two were already in the same set, return false
		}

		if(size[x] < size[y]) { // I will always make the larger in size one the father
			swap(x, y); // Size-based Merging - Optimization 2
		}

		father[y] = x;
		size[x] += size[y];
		return true;
	}

	bool SameSet(ll x, ll y) {
		return find(x) == find(y);
	}
};


void solve(){
	cin >> N >> K;
	//cout << "hi";
	line = vector<ll>(N);
	for(ll i =0;i < N; i++) cin >> line[i];

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	DSU interview(N);
	for(ll i =0;i < K; i++){
		pq.push({line[i], i+1});
	}
	pair<ll, ll> prev = make_pair(-1, -1);
	for(ll i = K; i < N; i++){
		pair<ll, ll> cur = pq.top();
		pq.pop();
		if(prev.first == cur.first){
			interview.unite(prev.second, cur.second);
		}
		prev = cur;
		cur.first += line[i];
		pq.push(cur);
	}

	pair<ll, ll> ans = pq.top();
	while(!pq.empty() && pq.top().first == ans.first){
		interview.unite(ans.second, pq.top().second);
		pq.pop();
	}
	cout << ans.first << "\n";
	for(ll i = 1; i <= K; i++){
		if(interview.find(ans.second) == interview.find(i)){
			cout << 1;
		}
		else cout << 0;
	}
	cout << "\n";
}


int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	ll t = 1;
  	while(t--) solve();
}