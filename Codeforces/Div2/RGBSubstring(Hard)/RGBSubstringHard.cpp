#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> diff1(n, 0);
	vector<int> diff2(n, 0);
	vector<int> diff3(n, 0);

	string t1 = "", t2 ="", t3 = "";
	int idx1 = 0, idx2 = 1, idx3 = 2;
	string offset = "RGB";
	int count = 0;
	while(count < n){
		idx1 %= 3;idx2 %= 3;idx3 %= 3;
		t1 += offset[idx1];
		t2 += offset[idx2];
		t3 += offset[idx3];
		count++;
		idx1++;
		idx2++;
		idx3++;
	}
	int ans =k;
	//cout << t1 << " " << t2 << " " << t3 << " ";
	int cur1 =0, cur2 = 0, cur3 = 0;
	for(int i =0; i < n; i++){
		diff1[i] = (t1[i] != s[i]); 
		cur1+= diff1[i];
		if(i >= k) cur1 -= diff1[i-k];
		if(i >= k-1) ans = min(ans, cur1);


		diff2[i] = (t2[i] != s[i]); 
		cur2+= diff2[i];
		//cout << diff2[i] << " ";
		if(i >= k) cur2 -= diff2[i-k];
		if(i >= k-1) ans = min(ans, cur2);

		diff3[i] = (t3[i] != s[i]); 
		cur3+= diff3[i];
		if(i >=k) cur3 -= diff3[i-k];
		if(i >= k-1) ans = min(ans, cur3);
	}
	cout << ans << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q; cin >> q;
  for(int i =0; i < q; i++) solve();
}