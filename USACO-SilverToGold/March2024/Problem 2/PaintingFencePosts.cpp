#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	
  	int N, P;
  	cin >> N >> P;

  	vector<ii> postjumble;
  	map<ii, pair<ii, ii>> fence;
  	map<int, int> xidx;
  	map<int, int> yidx;

  	map<ii, int> postidx;
  	for(int i =0;i < P; i++){
  		int a, b;
  		cin >> a >> b;
  		ii p1 = {a, b};
  		if(xidx.find(a) == xidx.end()){
  			xidx[a] = b;
  		}else{
  			fence[p1].first = {a, xidx[a]};
			fence[{a, xidx[a]}].first = p1;
  		}
  		if(yidx.find(b) == yidx.end()){
  			yidx[b] = a;
  		}else{
  			fence[p1].second = {yidx[b], b};
			fence[{yidx[b], b}].second = p1;
  		}
  		postjumble.push_back({a, b});
  	}
  	// for(ii p: postjumble){
  	// 	cout << p.first << ", " << p.second << "\n";
  	// 	cout << "{" << fence[p].first.first << ", " << fence[p].first.second << "} - {" << fence[p].second.first << ", " << fence[p].second.second << "}\n";
  	// }

  	vector<ii> postorder;
  	ii cur = postjumble[0];
  	int xory = 0;
  	for(int i = 0; i < postjumble.size(); i++){
  		postorder.push_back(cur);
  		postidx[cur] = i;
  		if(xory == 0)cur  = fence[cur].first;
  		else cur  = fence[cur].second;
  		xory ^= 1;
  	}
  	for(ii p: postorder){
  		cout << p.first << ", " << p.second << "\n";
  		cout << "{" << fence[p].first.first << ", " << fence[p].first.second << "} - {" << fence[p].second.first << ", " << fence[p].second.second << "}\n";
  	}

  	vector<int> perimeters(P);
  	for(int i = 0; i < postorder.size(); i++){
  		if(i== 0)perimeters[i] = abs(postorder[P-1].first - postorder[i].first);

  		else{
  			perimeters[i] = abs(postorder[i-1].second - postorder[i].second);
  			perimeters[i] += abs(postorder[i-1].first - postorder[i].first);
  		}
  		cout << perimeters[i] << " ";
  	}
  	cout << "\n";
  	vector<int> periPrefix(P+1);
  	periPrefix[0] = 0;
  	for(int i =1;i <= P; i++){
  		periPrefix[i] = periPrefix[i-1] + perimeters[i-1];
  		cout << periPrefix[i] << " ";
  	}
  	cout << "\n";

  	for(int i =0; i < N; i++){
  		ii start, end;
  		cin >> start.first >> start.second >> end.first >> end.second;


  		ii start1, start2, end1, end2;

  		if(xidx.find(start.first) != xidx.end()){
  			ii p2 = fence[{start.first, xidx[start.first]}].first;
  			if((start.second < xidx[start.first] && start.second> p2.second) || (start.second > xidx[start.first] && start.second< p2.second)){
  				start1 = {start.first, xidx[start.first]};
  				start2 = p2;
  			}
  			else{
  				start1 = {yidx[start.second], start.second};
  				start2 = fence[start1].second;
  			}
  		}
  		cout << start1.first << ", " << start1.second << " - " << start2.first << ", " << start2.second << "\n";

  	}













}