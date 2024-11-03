#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

struct ClosestCmp {
    bool operator()(const int & x, const int & y) { return x > y; }
};

// vec is assumed to be sorted
int closest(const std::vector<int> & vec, int value)
{
    std::vector<int>::const_reverse_iterator cri =
        std::lower_bound(vec.rbegin(), vec.rend(), value, ClosestCmp());
    if (cri != vec.rend()) {
        return *cri;
    }
    return -1;
}


void solve(){
	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<vector<int>> inter(2, vector<int>());
	int par = (int)s[0]-48;
	for(int i =0;i < n; i++){
		if(s[i]-48 == par){
			inter[par].push_back(i);
			par = par^1;

		}
	}
	for(int x : inter[0]) cout << x << " ";
	cout << "\n";
	for(int x : inter[1]) cout << x << " ";
	cout << "\n\n";
	bool flag = false;
	set<ii> idxs;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		int para = (int)s[a]-48;
		int parb = (int)s[b]-48;

		cout << para << " "<< parb << "   ";

		int idx = lower_bound(inter[para].begin(), inter[para].end(), b) -inter[para].begin();
		int idx2 = lower_bound(inter[parb].begin(), inter[parb].end(), b) -inter[parb].begin();
		if(idx != 0 && inter[para][idx] != a) idx--;
		if(idx != 0 && inter[parb][idx] != b) idx2--;

		int idx3;
		if(idx != idx2 && para == 0)

		int x = inter[para][idx];
		int y = inter[parb][idx2];
		cout << x << " " << y << "\n";

	}
	cout << idxs.size() + flag << "\n";

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0; i < t; i++) solve();
}