#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
  vector<char> a(51, '1');
  vector<int> nums;
  int n;
  string str;
  cin >> n;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    nums.push_back(num);
  }
  cin >> str;
  for(int i = 0; i < n; i++){
    if(a[nums[i]] == '1') a[nums[i]] = str[i];
    if(a[nums[i]] != str[i]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){solve();}
}