#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    //Console
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n; cin >> n;
    for(int i = 0 ; i < n; i++){
      string x; cin >> x;
      int l = x.size();
      bool doub = false;
      for(int j = 1; j < x.size(); j++){
        if(x[j] == x[j-1]) doub = true;
      }
      if(doub){
        cout << "YES\n";
        for(int j =0;j < l; j++) cout << "()";
        cout << "\n";
      }else{
        if(x == "()") cout << "NO\n";
        else{
          cout << "YES\n";
          for(int j =0;j < l; j++) cout << "(";
          for(int j =0;j < l; j++) cout << ")";
          cout << "\n";
        }
      }
    }
  
}