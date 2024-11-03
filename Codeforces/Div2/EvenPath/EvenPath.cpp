#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n ,q;
  cin >> n >> q;
  vector<int> r(n);
  vector<int> c(n);
  vector<int> changeC(n+1);
  vector<int> changeR(n+1);
  changeC[0] = 0;
  changeR[0] = 0;
  for(int i = 0; i < n; i++){
  	cin  >> r[i];
  	r[i] %= 2;
  }
  for(int i = 0; i < n; i++){
  	cin  >> c[i];
  	c[i] %= 2;
  }

  for(int i= 1; i < n; i++){
    changeR[i] = changeR[i-1] + (r[i]!= r[i-1]);
    changeC[i] = changeC[i-1] + (c[i]!= c[i-1]);
  }
  for(int i = 0; i < q; i++){
  	int a, b, c, d;
  	cin >> a >> b >> c >> d;

  	if(changeR[a-1] == changeR[c-1] && changeC[b-1] == changeC[d-1]){
  		cout << "YES\n";
  	}else{
  		cout << "NO\n";
  	}
  }
}