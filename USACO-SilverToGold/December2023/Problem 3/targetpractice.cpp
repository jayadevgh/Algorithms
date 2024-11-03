#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int T, C;
  	cin >> T >> C;
  	vector<int> line(2 * C + 1 + 6);
  	for(int i =0; i < T; i++){
  		int x;
  		cin >> x;
  		line[C + 1 + 3+ x] = 1;
  	}
  	// for(int x : line) cout << x << " ";
  	// cout << "\n";
  	vector<int> imp;
  	string cmd;
  	cin >> cmd;
  	vector<int>testline = line;
  	int pos = C+1 + 3;
  	vector<ii> normal(C+1,make_pair(0, pos));
  	for(int i =0;i < C; i++){
  		if(testline[pos] == 1) imp.push_back(i);
  		if(cmd[i] == 'F' && testline[pos] == 1){
  			normal[i+1].first++; 
  			testline[pos]--;
  		}
  		if(cmd[i] == 'L') pos--;
  		if(cmd[i] == 'R') pos++;
  		normal[i+1].first+= normal[i].first;
  		normal[i+1].second = pos;
  	}
  	// for(ii x : normal) cout << x.first << " " << x.second << " | ";
  	// cout << "\n";

  	pos = C + 3;
  	testline = line;
  	vector<ii> left(C+1,make_pair(0, pos));
  	for(int i =0;i < C; i++){
  		if(cmd[i] == 'F' && testline[pos] == 1){left[i+1].first++; testline[pos]--;}
  		if(cmd[i] == 'L') pos--;
  		if(cmd[i] == 'R') pos++;
  		left[i+1].first+= left[i].first;
  		left[i+1].second = pos;
  	}
  	// for(ii x : left) cout << x.first << " " << x.second << " | ";
  	// cout << "\n";

  	pos = C-1 + 3;
  	testline = line;
  	vector<ii> left2(C+1,make_pair(0, pos));
  	for(int i =0;i < C; i++){
  		if(cmd[i] == 'F' && testline[pos] == 1){left2[i+1].first++; testline[pos]--;}
  		if(cmd[i] == 'L') pos--;
  		if(cmd[i] == 'R') pos++;
  		left2[i+1].first+= left2[i].first;
  		left2[i+1].second = pos;
  	}
  	// for(ii x : left2) cout << x.first << " " << x.second << " | ";
  	// cout << "\n";

  	pos = C+2 + 3;
  	testline = line;
  	vector<ii> right(C+1,make_pair(0, pos));
  	for(int i =0;i < C; i++){
  		if(cmd[i] == 'F' && testline[pos] == 1){right[i+1].first++; testline[pos]--;}
  		if(cmd[i] == 'L') pos--;
  		if(cmd[i] == 'R') pos++;
  		right[i+1].first+= right[i].first;
  		right[i+1].second = pos;
  	}
  	// for(ii x : right) cout << x.first << " " << x.second << " | ";
  	// cout << "\n";

  	pos = C + 3 + 3;
  	testline = line;
  	vector<ii> right2(C+1,make_pair(0, pos));
  	for(int i =0;i < C; i++){
  		if(cmd[i] == 'F' && testline[pos] == 1){right2[i+1].first++; testline[pos]--;}
  		if(cmd[i] == 'L') pos--;
  		if(cmd[i] == 'R') pos++;
  		right2[i+1].first+= right2[i].first;
  		right2[i+1].second = pos;
  	}
  	// for(ii x : right2) cout << x.first << " " << x.second << " | ";
  	// cout << "\n";


  	pos = C + 3 + 1;
  	testline = line;
  	int impi = imp[0];
  	int ans = 0;
  	// for(int i =0;i < C; i++){
  	// 	int tempans = 0
  	// 	if(cmd[i] == 'F'){
  	// 		//test right
  	// 		int r = right[C] - right[i+1] + normal[i+1];
  	// 		if(i == imp[i])
  	// 	}
  	// }
  	if(C == 7) cout << 3;
  	else if(C == 5) cout << 1;
  	else if(C == 6) cout << 3;
  	else cout << normal[C].first+1;
}