// https://codeforces.com/contest/484/problem/A


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string itobt(long long n){
	string bitstr = "";
	while(n > 0){
		bitstr += (n % 2) + '0';
		n/= 2;
	}
	reverse(bitstr.begin(), bitstr.end());
	return bitstr;
}

long long bttoi(string str){
	long long num = 0;

	for(int i =0; i < str.size(); i++){
		num = num * 2 + (long long)(str[i] - '0');
	}
	return num;
}

void solve(){
	int n;
	cin >> n;
	for(int i =0;i < n; i++){
		long long lo, hi;
		cin >> lo >> hi;

		string strlo, strhi;
		strlo = itobt(lo);
		strhi = itobt(hi);

		//cout << strlo << " " << strhi << "\n";

		bool allone = true;
		for(int i = 0; i < strhi.size(); i++) {if(strhi[i] == '0') {allone = false; break;}}

		if(allone){
			cout << hi << "\n";
			continue;
		}
		// string strans(strhi.size()-1, '1');
		// cout << strans;
		if(strhi.size() > strlo.size()){
			string strans(strhi.size()-1, '1');
			long long ans = bttoi(strans);
			cout << ans << "\n";

		}
		else{
			string strans = "";
			for(int i = 0; i < strhi.size(); i++){
				if(strhi[i] != strlo[i]){
					string rest(strhi.size() - i-1, '1');

					allone = true;
					for(int j = i; j < strhi.size(); j++) {if(strhi[j] == '0') {allone = false; break;}}
					
					if(allone || rest.size() == 0) strans += '1';
					else strans += '0';
					strans += rest;
					break;
				}
				strans += strhi[i];
			}
			//cout << strans << " ";
			long long ans = bttoi(strans);
			cout << ans << "\n";
		}
	}
}


int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t =1 ;
  	while(t--){
  		solve();
  	}
  	//cout << itobt(9) << " " << itobt(11);
}