#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("shell.in","r",stdin);
	freopen("shell.out","w",stdout);
  int n; 
  cin >> n;
  vector<int> arr(4);
  for(int i = 0; i <= 3; i++) arr[i] = i;

  int ans1 = 0;
  int ans2 = 0; 
  int ans3 = 0;
  for(int i = 1; i <= n; i++){
    int a, b, g;
    cin >> a >> b >> g;
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
    if(arr[g] == 1) ans1++;
    if(arr[g] == 2) ans2++;
    if(arr[g] == 3) ans3++;
  }
  cout << max(max(ans1, ans2), ans3);
}