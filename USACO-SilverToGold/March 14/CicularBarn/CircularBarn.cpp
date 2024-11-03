#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<bool> isPrime(5e6+3, true);
void sieveOfEratosthenes() {
	int n = 5e6+3;
    isPrime[1] = true;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

}
vector<int> maxmod(5e6+3, 1);
void maxp(){
	int n = 5e6+3;
	vector<int> mods = {0, 1, 2, 3};
	for(int i = 2;i < n; i++){
		if(isPrime[i]) mods[i%4] = i;
		maxmod[i] = mods[i%4];
	}
}

void solve(){
	int n;
	bool win = false;
	cin >> n;
	pair<string, int> ans = {"Farmer John\n", INT_MAX};
	for(int i =0;i < n ;i++){
		int num;
		cin >> num;
		if(isPrime[num]) win = true;	

		if(num % 4 == 0){
			if(ans.second > num/4) ans = {"Farmer Nhoj\n", num/4};
		}
		else {if(ans.second > (num-maxmod[num])/4) ans = {"Farmer John\n", (num-maxmod[num])/4};}
	}
	if(win) cout << "Farmer John\n";

	else cout << ans.first;
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	sieveOfEratosthenes();
  	maxp();
  	int t;
  	cin >> t;
  	while(t--) solve();
}