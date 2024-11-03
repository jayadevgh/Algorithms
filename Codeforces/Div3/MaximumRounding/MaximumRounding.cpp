#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s, maxi;
	cin >> s;
	maxi = s;
	for(int i =s.size()-1; i >=0 ; i--){
		if(s[i]-48 >=5){
			//cout << "hi";
			s[i] = '0';
			if(i > 0){

				int x = (s[i-1] -47);
				//cout << s[i-1];

				if(s[i-1] != 9) s[i-1] = x + 48;
				else{
					int cur = i;
					while(i > 0 && s[i-1] == '9'){
						i--;
						//cout << s;
					}

					for(int j = cur; j >= i; j--){
						s[j] = 0;
					}
					if(i ==0){
						string x = "1";
						x += s;
						s = x;
					}
					else s[i-1]++;

				}
				
			}
			else if(i ==0){
				string x = "1";
				x += s;
				s = x;
			}
			maxi = s;
			
		}
		s[i] = '0';
	}
	cout << maxi << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0;i < t; i++) solve();
}