#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	vector<int> count(2);
	vector<ii> arr(s.size());
	int n = s.size();
	int cnt = n-1;
	for(char x : s) {
		arr[cnt] = make_pair(count[0], count[1]);
		count[x]++;
		cnt--;

}
	int goal = (count[1] + count[0]) / 2;

	for(int i =n-1;i < n; i--)
}