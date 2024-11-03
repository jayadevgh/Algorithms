#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

bool checkseq(string seq){
	//diag
	if(seq[0] == '2' && seq[4] == '1' && seq[8] == '1') return true;
	if(seq[0] == '1' && seq[4] == '1' && seq[8] == '2') return true;
	if(seq[6] == '2' && seq[4] == '1' && seq[2] == '1') return true;
	if(seq[6] == '1' && seq[4] == '1' && seq[2] == '2') return true;

	//row
	if(seq[0] == '2' && seq[1] == '1' && seq[2] == '1') return true;
	if(seq[0] == '1' && seq[1] == '1' && seq[2] == '2') return true;
	if(seq[3] == '2' && seq[4] == '1' && seq[5] == '1') return true;
	if(seq[3] == '1' && seq[4] == '1' && seq[5] == '2') return true;
	if(seq[6] == '2' && seq[7] == '1' && seq[8] == '1') return true;
	if(seq[6] == '1' && seq[7] == '1' && seq[8] == '2') return true;

	//col
	if(seq[0] == '2' && seq[3] == '1' && seq[6] == '1') return true;
	if(seq[0] == '1' && seq[3] == '1' && seq[6] == '2') return true;
	if(seq[1] == '2' && seq[4] == '1' && seq[7] == '1') return true;
	if(seq[1] == '1' && seq[4] == '1' && seq[7] == '2') return true;
	if(seq[2] == '2' && seq[5] == '1' && seq[8] == '1') return true;
	if(seq[2] == '1' && seq[5] == '1' && seq[8] == '2') return true;
	return false;
}
vector<int> moves;
vector<bool> movis;
vector<vector<int>> adj;
set<string> win;
string finseq = "000000000";
int ans = -1;
vector<vector<int>> repon;
void dfs(int k){
	if(movis[k]) return;
	movis[k] = true;

	int num = moves[k];
	int num2 = num;
	int y = (num % 10) - 1;

	num = num/ 10;
	int x = (num % 10) -1;
	num = num/10;
	//cout << x << " " << y << " ";
	if(finseq[x*3 + y] == '0')finseq[x*3 + y] = '0' + num;
	else return;
	cout << k << " " << num2 << " " << finseq << "\n";

	if(win.find(finseq) != win.end()){
		cout << "^" << "\n";
		win.erase(finseq);
		ans++;
		return;
	}
	if(checkseq(finseq)) {
		//cout << "fake" << "\n";
		return;
	}

	repon.push_back(adj[k]);
	for(int i =0;i < repon.size(); i++){
		for(int j =0; j < repon[i].size(); j++){
			cout << repon[i][j] << " ";
		}
	}
	cout <<"\n";
	for(bool i : movis) cout << i << " ";
	cout << "\n\n";
	string checker = "";
	for(int i =0;i < repon.size(); i++){
		for(int j =0; j < repon[i].size(); j++){
			int tempk = repon[i][j];
			checker += to_string(tempk) + " ";
			dfs(tempk);
		}
	}
	
	repon.pop_back();
	movis[k] = false;
	finseq[x*3 + y] = '0';
	//cout << " d\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int N;
  	cin >> N;
  	vector<vector<int>> grid(N, vector<int>(N, 0));
  	
  	int a =1;
  	moves.push_back(0);
  	for(int i = 0;i < N; i++){
  		string str;
  		cin >> str;
  		for(int j = 0; j < N; j++){
  			char x = str[3*j];
  			int b = (str[3*j+1]-'0')*10 + str[3*j+2]-'0';
  			//cout << b << "\n";
  			if(x == '#') grid[i][j] = -1;
  			else if(x == 'M') {
  				moves.push_back(200+b);
  				grid[i][j] = a;
  				a++;
  			}
  			else if(x == 'O') {
  				moves.push_back(100+b);
  				grid[i][j] = a;
  				a++;
  			}
  			else if(x == 'B') grid[i][j] = -2;
  		}
  	}

  	
  	adj.resize(moves.size(), vector<int>());
  	vector<bool> defmovis(moves.size(), 0);
  	movis = defmovis;
  	vector<vector<bool>> visted_base(N, vector<bool>(N, 0));
  	vector<vector<bool>> vis = visted_base;
  	vector<int> starts;
  	for(int i = 0; i< N; i++){
  		for(int j = 0; j < N; j++){
  			if(grid[i][j] > 0){
  				queue<ii> q;
  				q.push(make_pair(i+1, j));
  				q.push(make_pair(i-1, j));
  				q.push(make_pair(i, j+1));
  				q.push(make_pair(i, j-1));
  				vis[i][j] = 1;
  				while(!q.empty()){
  					ii p = q.front();
  					int num = grid[p.first][p.second];
  					q.pop();
  					if(vis[p.first][p.second]) continue;
  					vis[p.first][p.second] = 1;
  					if(num == -1) continue;
  					if(num == -2) starts.push_back(grid[i][j]);
  					if(num > 0){
  						adj[grid[i][j]].push_back(num);
  						continue;
  					} 
  					q.push(make_pair(p.first+1, p.second));
	  				q.push(make_pair(p.first-1, p.second));
	  				q.push(make_pair(p.first, p.second+1));
	  				q.push(make_pair(p.first, p.second-1));
  				}
  				vis = visted_base;
  			}
  			cout << grid[i][j] << " ";
  		}
  		cout << "\n";
  	}
  	for(vector<int> x : adj){
  		for(int i : x) cout << i << " ";
  		cout << "\n";
  	}
  	// for(int i : starts) cout << i << " ";
  	// cout << "\n";
  	string seq = "000000000";
  	string seq1 = "222222222";

  	while(seq.compare(seq1) != 0){
  		seq[0] += 1;
  		if(seq[0] == '3'){ seq[0] = '0'; seq[1]++; }
  		if(seq[1] == '3'){ seq[1] = '0'; seq[2]++; }
  		if(seq[2] == '3'){ seq[2] = '0'; seq[3]++; }
  		if(seq[3] == '3'){ seq[3] = '0'; seq[4]++; }
  		if(seq[4] == '3'){ seq[4] = '0'; seq[5]++; }
  		if(seq[5] == '3'){ seq[5] = '0'; seq[6]++; }
  		if(seq[6] == '3'){ seq[6] = '0'; seq[7]++; }
  		if(seq[7] == '3'){ seq[7] = '0'; seq[8]++; }

  		if(checkseq(seq)) win.insert(seq);

  	}
  	//cout << checkseq("112000000")<< " ";
  	//cout << win.size() << "\n";

  	for(int i : starts){
  		dfs(i);
  		cout << "\n\n";
  		finseq = "000000000";
  		movis = defmovis;
  	}
  	cout << ans + 1 ;
  	//cout << moves[9];
}