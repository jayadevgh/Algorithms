#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin >> n;
  int p1 = 0;
  int p2 = 0;
  int p3 = 0;
  set<string> s1, s2, s3;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    s1.insert(str);
  }
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    s2.insert(str);
  }
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    s3.insert(str);
  }
  for(auto& str : s1){
    bool a = s3.find(str) != s3.end();
    bool b = s2.find(str) != s2.end();
    if(a && b) continue;
    else if(a || b) p1++;
    else p1 += 3;
  }
  for(auto& str : s2){
    bool a = s1.find(str) != s1.end();
    bool b = s3.find(str) != s3.end();
    if(a && b) continue;
    else if(a || b) p2++;
    else p2 += 3;
  }
  for(auto& str : s3){
    bool a = s1.find(str) != s1.end();
    bool b = s2.find(str) != s2.end();
    if(a && b) continue;
    else if(a || b) p3++;
    else p3 += 3;
  }
  cout << p1 << " " << p2 << " " << p3 << "\n";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t; 
  for(int j = 0; j < t; j++){
    solve();
  }
}