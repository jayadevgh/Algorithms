// https://codeforces.com/contest/1859/problem/D

#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int getIndex(const std::vector<ii>& V, int val)
{
    auto iter = std::upper_bound(V.begin(), V.end(), make_pair(val, INT_MAX));
    if ( iter != V.begin())
       // return the index of the item before the found item
       return std::distance(V.begin(), std::prev(iter));

    // return the first item
    return -1;
}

void solve(){
	int n;
	cin >> n;
	vector<ii> line;
	for(int i =0;i < n; i++){
		int w, x, y, z;
		cin >> w >> x >> y >> z;
		line.push_back(make_pair(w, z));
	}
	sort(line.begin(), line.end());
	//for(auto& x : line) cout << x.first << " " << x.second << " | ";
	vector<ii> line2;
	for(int i =0;i < n; i++){
		ii x = line[i];
		while(i+1 < n && x.second >= line[i+1].first){
			x.second = max(x.second, line[i+1].second);
			//cout << line[i+1].first << " " << line[i+1].second << " | ";
			//cout << x.first << " " << x.second << "\n";
			i++;
		}
		line2.push_back(x);
	}
	//for(auto& x : line2) cout << x.first << " " << x.second << " | ";
	int q;
	cin >> q;
	for(int i =0;i < q; i++){
		int x;
		cin >> x;
		int idx = getIndex(line2, x);
		if(idx == -1) cout << x << " ";
		else cout << max(line2[idx].second, x) << " ";
	}
	cout << "\n";	
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0;i < t; i++) solve();
}