#include <iostream>
#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int N, K;
  	cin >> N >> K;
  	K--;
  	set<int> temp;
  	for(int i =0 ;i < N ;i++){
  		int x;
  		cin >> x;
  		x = x /12;
  		x++;
  		temp.insert(x);
  	}
  	temp.insert(0);
  	vector<int> arr(temp.begin(), temp.end());
  	//for(int x : arr) cout << x << " ";
  	//`cout << "\n";

  	priority_queue<int, vector<int>, greater<int>> pq;
  	int sum = 0;
  	for(int i = 1;i < arr.size(); i++){
  		int inter = arr[i] - arr[i-1] - 1;
  		
  		if(pq.size() < K) pq.push(inter);
  		else if(inter > pq.top()){
  			sum += pq.top();
  			pq.pop();
  			pq.push(inter);
  		}
  		else sum+=inter;
  		//cout << pq << " ";
  	}	
  	sum += temp.size()-1;
  	cout << sum * 12;

}