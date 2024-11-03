#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;

bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
       return (a.second < b.second);
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t;
  	cin >> t;
  	while(t--){
  		int N, Q, C;
  		cin >> N >> Q >> C;

  		vector<int> arr(N, 0);
  		vector<int> maxis(N, 0);
  		vector<int> zeropos;
  		vector<ii> qs;
  		int zpos = -1;
  		int maxi =0;
  		for(int i =0;i < N; i++) {
  			int a;
  			cin >> a;
  			arr[i] = a;
  			maxi = max(maxi, a);
  			zeropos.push_back(zpos);
  			if (a == 0) zpos = i;
  			
            maxis[i] = maxi;

  		}

  		for(int i =0;i < Q; i++){
  			int a, b;
  			cin >> b >> a;
            a--;
            b--;
  			ii p = make_pair(a, b);
  			qs.push_back(p);
  		}
  		sort(qs.begin(), qs.end(), sortbyCond);
  		int ans=-1;

        vector<int> possi(N, 0);

        bool badcheck = 0;
        int prev = qs[0].first;
        for(int i = 0;i < Q;i++){
            int big = qs[i].first;
            int sml = qs[i].second;
            if(possi[big] = 1){
                badcheck = true;
                break;
            }
            for(int i = big;i > sml; i--;){

            }
        }
        if(badcheck){
            cout << -1;
            continue;
        }
        // bool check = true;
  		// for(int i =0;i < Q; i++){
  		// 	cout << qs[i].first << " " << qs[i].second << "\n";
  		// 	int big = qs[i].first;
  		// 	int sml = qs[i].second;
        //     if(possi[big] == -1){

        //         check = false;
        //         break;
        //     }
        //     if(possi[big] == 0) continue;
        //     if(arr[big] != 0 && arr[big] <= maxis[big-1]){
        //         //cout << "h";
        //         check = false;
        //         break;
        //     }

        //     if(maxis[big-1] > maxis[sml]){
        //         if(arr[sml] == 0) arr[sml] = maxis[big-1];
        //         if(zeropos[sml] == -1){check = false; break;}
        //         else {
        //             arr[zeropos[sml]] = maxis[big-1];
        //         }
        //     }
        //     if(arr[big] == 0) arr[big] = maxis[big-1]+1;
        //     for(int i = sml+1; i < big; i++){
        //         possi[i] = -1;
        //     }
        //     possi[big] == 0;



  		// }
        for(int i =0; i < N; i++){
            if(arr[i] == 0) arr[i] = 1;
            cout << arr[i] << " ";
        }
        if(!check) cout << "-1WRONG-1" << " ";
        cout << "\n\n";

  	}
}