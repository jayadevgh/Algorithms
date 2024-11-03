#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ii pair<ll, ll>


ll yCoord(ll slope, ii coord){
	ll newslope = slope;

	return coord.second - coord.first * (newslope);
}

bool cmp(pair<ii, ii> p1, pair<ii, ii>p2){
	return p1.second.second > p2.second.second;
}
void solve(){
	ll n, x1;
	cin >> n >> x1;

	vector<pair<ii, ii>> coordarr;
	ll poscount =0;
	ll negcount = 0;
	ll meany = 0;
	for(ll i =0;i < n; i++){
		ll y1, y2, x2;
		cin >> y1 >> y2 >> x2;
		meany += y1; meany += y2;

		coordarr.push_back({{x2, y1}, {1, 0}});
		coordarr.push_back({{x2, y2}, {-1, 0}});
		coordarr.push_back({{x1, y1}, {0, 0}});
		coordarr.push_back({{x1, y2}, {0, 0}});
		poscount++; negcount++;
	}
	meany /= (2 * n);

	priority_queue<ll> pos;
	priority_queue<ll, vector<ll>, greater<ll>> neg;

	for(ll i =0;i < (n * 4) ;i++){
		ll x; cin >> x;
		if(x > 0) {
			//cout << x << " : pos, ";
			pos.push(x);
		}
		else {
			//cout << x << " : neg, ";
			neg.push(x);
		}
		//cout << x << " ";
	}
	//cout << "\n";
	if(neg.size() < n || pos.size() < n){
		cout << -1 << "\n";
		return;
	}
	
	for(ll i =0; i< (4 * n); i++){
		coordarr[i].second.second = yCoord(neg.top(), coordarr[i].first);
	}
	sort(coordarr.begin(), coordarr.end(), cmp);
	reverse(coordarr.begin(), coordarr.end());
	ll ymax = INT_MIN;
	ll ymin = INT_MAX;
	priority_queue<ll> temppos = pos;
	priority_queue<ll, vector<ll>, greater<ll>> tempneg = neg;
	ll tempposcnt = poscount;
	ll tempnegcnt = negcount;
	for(ll i = 0; i< (4*n); i++){
		pair<ii, ii> coordInfo = coordarr[i];
		ll slope =0;
		if(coordInfo.second.first == 1){
			slope = pos.top();
			pos.pop();
			poscount--;
		}
		else if(coordInfo.second.first == -1 || pos.empty()){
			slope = neg.top();
			neg.pop();
			negcount--;
		}
		else if(neg.size() > negcount){
			slope = neg.top();
			neg.pop();
			//negcount--;
		}
		else if(pos.size() > poscount){
			slope = pos.top();
			pos.pop();
			//poscount--;
		}
		ll ycoor = yCoord(slope, coordInfo.first);
		cout << coordInfo.first.first << " " << coordInfo.first.second << " | ";
		cout << slope << " " << ycoor << " | " << coordInfo.second.second << "\n";
		ymax = max(ymax, ycoor);
		ymin = min(ymin, ycoor);
	}
	cout << "\n";
	for(ll i =0; i< (4 * n); i++){
		coordarr[i].second.second = yCoord(pos.top(), coordarr[i].first);
	}
	sort(coordarr.begin(), coordarr.end(), cmp);
	//reverse(coordarr.begin(), coordarr.end());
	pos = temppos;
	neg = tempneg;
	poscount = tempposcnt;
	negcount = tempnegcnt;
	for(ll i = 0; i< (4*n); i++){
		pair<ii, ii> coordInfo = coordarr[i];
		ll slope =0;
		if(coordInfo.second.first == 1){
			slope = pos.top();
			pos.pop();
			poscount--;
		}
		else if(coordInfo.second.first == -1 || pos.empty()){
			slope = neg.top();
			neg.pop();
			negcount--;
		}
		else if(pos.size() > poscount){
			slope = pos.top();
			pos.pop();
			//poscount--;
		}
		else if(neg.size() > negcount){
			slope = neg.top();
			neg.pop();
			//negcount--;
		}
		
		ll ycoor = yCoord(slope, coordInfo.first);
		cout << coordInfo.first.first << " " << coordInfo.first.second << " | ";
		cout << slope << " " << ycoor << " | " << coordInfo.second.second << "\n";
		ymax = max(ymax, ycoor);
		ymin = min(ymin, ycoor);
	}
	//for()

	// cout << pos.top() << " ";
	// cout << neg.top() << "";
	cout << ymax << " " << ymin;
	cout << "\n"; 
}


int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t; cin >> t;
  	for(ll i =0;i < t; i++) solve();
}