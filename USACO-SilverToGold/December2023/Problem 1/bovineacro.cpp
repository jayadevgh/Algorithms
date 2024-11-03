#include <iostream>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define iii pair<ll, pair<ll, ll>>

using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N, M, K;
  	cin >> N >> M >> K;
  	vector<ii> arr(N);
  	for(ll i =0;i < N; i++){
  		ll a, b;
  		cin >> a >> b;
  		arr[i] = make_pair(a, b);
  		//cout << arr[i].first << " " << arr[i].second << "\n";
  	}
  	sort(arr.begin(), arr.end());
  	reverse(arr.begin(), arr.end());
  	priority_queue<iii> pq;
  	priority_queue<iii> temppq;
  	pq.push(make_pair(1, arr[0]));


  	for(ll i =1;i < N; i++){
  		ii p = arr[i];
  		
  		while(p.second > 0 || !pq.empty()){
  			if(p.second == 0 && !pq.empty()){
  				temppq.push(pq.top());
  				pq.pop();
  			}
  			if(pq.empty()) {

  				temppq.push(make_pair(1, p)); 
  				//cout << 0 << " " << p.first << " " << p.second << "\n";
  				break;
  			}
  			iii topp = pq.top();
  			if(topp.second.first < p.first + K){
  				temppq.push(topp);
  				pq.pop();
  				continue;
  			}
  			pq.pop();
  			//cout << topp.first << " " << topp.second.first << " " << topp.second.second << "\n";
  			if(p.second < topp.second.second){

  				iii topp2 = topp;
  				topp2.first++;
  				topp2.second.second = p.second;
  				topp2.second.first = p.first;
  				topp.second.second = topp.second.second - p.second;
  				p.second =0;
  				temppq.push(topp2);
  				temppq.push(topp);
  			}
  			else if(p.second == topp.second.second){

  				iii topp2 = topp;
  				topp2.first++;
  				topp2.second.first = p.first;
  				p.second =0;
  				temppq.push(topp2);
  			}
  			else{
  				topp.first++;
  				topp.second.first = p.first;
  				temppq.push(topp);
  				p.second -= topp.second.second;
  			}


  		}

  		pq = temppq;
  		// while(!temppq.empty()){
  		// 	iii a = temppq.top();
  		// 	temppq.pop();
  		// 	//cout << a.first << " " << a.second.first << " " << a.second.second << "\n";
  		// }
  		//cout << "\n";
  		temppq = priority_queue <iii>();
  		//iii topp = pq.top();
  		
  	}
  	ll cows = 0, towers =0;
  	while(!pq.empty()){
  		iii a = pq.top();
  		//cout << a.first << " " << a.second.first << " " << a.second.second << "\n";
  		pq.pop();
  		ll t = 0, c =0 ;
  		t += a.second.second;
  		c += a.first;
  		if(t + towers > M) t = M - towers;
  		cows += c * t;
  		towers += t;
  	}
  	cout << cows << "\n";
}