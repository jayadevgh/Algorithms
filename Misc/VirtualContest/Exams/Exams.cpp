#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int main() {
  //Console
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // int n, m;
  // cin >> n >> m;
  // vector<int> arr(n);
  // vector<int> ind(m);
  // for(auto& x: arr) cin >> x;
  // for(auto& x: ind) cin >> x;
  // int ans =0;
// 	int hi = n-1;
// 	int lo = 0;
// 	while(lo < hi){
// 		int mid = (lo+hi)/2;


// 	}
  const int max_N = 1e5 + 10;
  vector<int> passDays[max_N];
int d[max_N], a[max_N], b[max_N];
 
int main()
{
	ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> a[i];
		passDays[a[i]].push_back(i);
	}
	for (int i = 1; i <= M; ++i) {
		cin >> d[i];
	}
	int low = 1, high = N, mid, ans = -1;
	while(low <= high) {
		memset(b, 0, sizeof(b));
		int mid = (low + high) >> 1;
		for (int i = 1; i <= M; ++i) {
			passDays[i].clear();
		}
		for (int i = 1; i <= mid; ++i) {
			passDays[a[i]].push_back(i);
		}
		int poss = 1;
		for (int i = 1; i <= M; ++i) {
			if (passDays[i].empty()) {
				poss = 0;
			} else {
				b[passDays[i].back()] = i;
			}
		}
		if (!poss) {
			low = mid + 1;
			continue;
		}
		int prep = 0;
		for (int i = 1; i <= N; ++i) {
			if (b[i] == 0) {
				++prep;
			} else if (d[b[i]] > prep) {
				poss = 0;
			} else {
				prep -= d[b[i]];
			}
		}
		if (poss) {
			high = mid - 1;
			ans = mid;
		} else {
			low = mid + 1;
		}
	}
	cout << ans << endl;
}	