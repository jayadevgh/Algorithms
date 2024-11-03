#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
int n;
ll a[N];
 
int cnt[N];
void solve(){
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	
	int isDistinct = 1;
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n - 1;++i) {
		if (a[i] == a[i + 1]) isDistinct = 0;
	}
	if (isDistinct == 0) {
		cout << "NO" << endl;
		return;
	}
	
	int CRT_able = 1;
	for (int mod = 2;mod <= n / 2;++mod) {
		fill(cnt, cnt + mod, 0);
		for (int i = 1;i <= n;++i) {
			cnt[a[i] % mod]++;
		}
		if (*min_element(cnt, cnt + mod) >= 2) CRT_able = 0;
	}
	cout << (CRT_able ? "YES" : "NO") << endl;
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0;i < t; i++) solve();
}