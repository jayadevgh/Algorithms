#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
    cin >> s;

    vector<bool> vis(26);
    vis[s[0] - 'a'] = true;
    string t(1, s[0]);
    int sz = s.size();
    int pos = 0;
    for(int i = 1; i< sz; i++){
    	if(vis[s[i]-'a']){
    		if(pos-1 >= 0 && t[pos-1] == s[i]){
    			pos--;
    		}
    		else if(pos+1 < t.size() && t[pos+1] == s[i]){
    			pos++;
    		}else { 
    			cout << "NO\n"; 
    			return; 
    		}
    	}
    	else{
    		if(pos == 0){
    			t = s[i] + t;
    		}
    		else if(pos == t.size()-1){
    			t += s[i];
    			pos++;
    		}else { 
    			cout << "NO\n"; 
    			return; 
    		}
    		
    	}
    	vis[s[i] -'a'] = true;
    }
    for(int i =0; i < vis.size(); i++){
    	if(!vis[i]) t += (char) (i + 'a');
    }
    cout << "YES\n" << t << "\n";

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i = 0; i < t; i++) solve();
}