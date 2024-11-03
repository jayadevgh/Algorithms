#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// segment into nondecreasing sequences
// ex 1 4 | 2 | 5 7 8 | 3 | 2 | 19
// if number lb not same as another number lb then split apart 
int N;
vector<int> arr;
set<int> sortset;

// Use sorted set
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  for(int i =0; i < N; i++){
  	int x; cin >> x;
  	arr.push_back(x);
  }
  
  int seg = 0;
  int count = 0;
  int prev = INT_MIN;
  while(arr[count] > prev){
  	sortset.insert(arr[count]);
    prev = arr[count];
  	count++;
  	if(count == N) break;
    
  }
  for(int x : sortset){
    cout << x << " ";
  }
  cout << "\n";
  //bool newSeg = true;
  vector<int> segment;
  int anchorLb = -1;

  for(int i = count; i < N; i++){
    auto it = sortset.lower_bound(arr[i]);
    int lb = *it;
    cout << lb << " ";
  	if(anchorLb != lb || prev > arr[i]){
      for(int x : segment){
        sortset.insert(x);
        cout << x << " ";
      }
      cout << "\n";
      segment.clear();
      anchorLb = lb;
      segment.push_back(arr[i]);
      seg++;

    }else{
      segment.push_back(arr[i]);
    }
    prev = arr[i];

  }
  // for(int x : sortset){
  //   cout << x << " ";
  // }
  seg++;
  cout << seg;
  
}