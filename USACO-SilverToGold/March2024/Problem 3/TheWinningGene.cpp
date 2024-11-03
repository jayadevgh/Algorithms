#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;
string s;
vector<int> ans;
//int tally = 0;
vector<string> prevl;


vector<pair<int, int>> nearest_smaller_values(const vector<int>& arr) {
    vector<int> left_indexes(arr.size(), -1);
    vector<int> right_indexes(arr.size(), -1);
    stack<int> s;

    // Iterate from left to right
    for (int i = 0; i < arr.size(); ++i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left_indexes[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty()) s.pop(); // Clear the stack for re-use

    // Iterate from right to left
    for (int i = arr.size() - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right_indexes[i] = s.top();
        }
        s.push(i);
    }
    vector<pair<int, int>> result;
    for (int i = 0; i < arr.size(); ++i) {
        if (right_indexes[i] == -1)
            right_indexes[i] = arr.size();
       // cout << left_indexes[i];
        //cout << right_indexes[i];
        result.push_back(make_pair(i-left_indexes[i],  right_indexes[i]-i));
        //result.push_back(make_pair(abs(i - left_indexes[i]),  abs(right_indexes[i] - 1)));
    }

    return result;

   
}





vector<int> lweights(int l){
	multiset<pair<string, int>> ms;
	if(l == 1){
		for(int i =0; i < N; i++){
			//cout << "" +s[i];
			string s1(1, s[i]);
			//cout << s1;
			prevl.push_back(s1);
		}
	}
	else{ 
		prevl.pop_back();
		for(int i = l-1; i < N; i++){
			prevl[i-(l-1)]+= s[i];
			
		}
	}
	for(int i = l-1; i < N; i++){
			ms.insert({prevl[i-(l-1)], i-(l-1)});
	}
	



	vector<int> res(N-l+1);
	int i =0;
	for(pair<string, int> p : ms){
		//cout << p.first << " " << p.second << "\n";
		res[p.second] = i;
		i++;
	}
	return res;

}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	cin >> N ;
  	cin >> s;
  	ans = vector<int>(N+1);
  	//cout << s;
	vector<int> subl;
  	for(int l =1; l <= N; l++){
  		subl = lweights(l);
  		//cout << i << "\n";
  		if(l == l){
  			cout << l << ":\n";
	  		for(int l : subl) cout << l << " ";
	  		cout << "\n";
	  	}
  		//for(string i : prevl) cout << i << " ";
  		//cout << "\n";


  		//sliding window minimum using multiset
  		// for(int k = l; k <= N; k++){
  		// 	set<int> sans;
  		// 	//if(l == l) cout << subl[0] << " ";
  		// 	sans.insert(subl[0]);
  		// 	for(int i =1; i < subl.size(); i++){
  		// 		//if(l == l) cout << subl[i] << " ";
  		// 		sans.insert(subl[i]);
  		// 		subl[i-1] = min(subl[i-1], subl[i]);
  		// 	}
  		// 	//if(l == l) cout << " ------ "  << sans.size() << "\n";
  		// 	ans[sans.size()]++;
  		// 	subl.pop_back();
  		// }

  		vector<pair<int, int>> arr = nearest_smaller_values(subl);
  		vector<int> fins(subl.size(), 0);
  		int maxi = 0;
  		for(int i =0;i < arr.size(); i++){
  			//if(l == 2) cout << arr[i].first << " " << arr[i].second << " -> ";
  			int pmax = max(arr[i].first, arr[i].second);
  			//if(l == 2) cout << pmax << " ... ";
  			maxi = max(maxi, pmax);
  			fins[subl.size()-max(arr[i].first, arr[i].second)]++;
  		}
  		fins[subl.size()-maxi]--;
  		fins[0]++;
  		for(int i = 1; i < fins.size() ; i++){
  			fins[i] += fins[i-1];
  			cout << fins[i] << " ";
  		}
  		cout << "\n";
  		for(int i =0; i < fins.size(); i++){
  			ans[fins[i]]++;
  		}

  			
  	}
  	for(int i = 1; i < N+1; i++) cout << ans[i] << "\n";
  		
  		



}