#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> arr(n);
	vector<int> parr(n+1);
	parr[0] =0;
	ll sum=0;
	for(int i =0; i < n; i++){
		cin >> arr[i];
		parr[i+1] = parr[i] + arr[i];
		sum += arr[i];
	}
	//set<int> psum(parr.begin(), parr.end());

	int ans = n;
	if (equal(arr.begin() + 1, arr.end(), arr.begin())) ans = 1;
	
	for(int i = 2; i < sqrt(sum); i+=2){
		int maxseg = INT_MIN;
		bool work = true;
		if(sum % i == 0){
			for(int k =0; k < 2; k++){
				int seg = 0;
				int sums = sum/i;

				for(int j = 1; j <= n; j++){
					//cout << arr[j-1] << " ";
					seg++;
					if(parr[j] > sums) {work = false;break;}
					else if(parr[j] == sums) {
						//cout << "|";
						sums += sum/i; 
						maxseg = max(maxseg, seg);
						seg = 0;
					}

				}
				//cout << "\n";
				if(work) ans = min(maxseg, ans);
				maxseg =0;
				i = sum/i;
			}
		}
		if(i == 2) i--;
	}
	cout << ans << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0; i < t; i++)solve();
}