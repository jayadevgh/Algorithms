#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	set<ii> arr;
	set<ii> comf;
	set<ii> need;
	//set<ii> almo
	int ans = 0;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		ii p = make_pair(a, b);
		int cnt = 0;
		if(need.find(p) != need.end()) need.erase(p);

		int c =0;
		if(arr.find(make_pair(a-1, b)) != arr.end()){
			cnt++;
			int tempcnt = 1;
			int check = 0;
			ii p1 = make_pair(a-1, b+1);
			ii p2 = make_pair(a-2, b);
			ii p3 = make_pair(a-1, b-1);
			if(arr.find(p1) != arr.end()) tempcnt++;
			else check =1;
			if(arr.find(p2) != arr.end()) tempcnt++;
			else check = 2;
			if(arr.find(p3) != arr.end()) tempcnt++;
			else check = 3;

			if(tempcnt == 3){
				if(check==1) need.insert(p1);
				if(check==2) need.insert(p2);
				if(check==3) need.insert(p3);
			}

		}
		else c =1;

		if(arr.find(make_pair(a+1, b)) != arr.end()){
			cnt++;
			int tempcnt = 1;
			int check = 0;
			ii p1 = make_pair(a+1, b+1);
			ii p2 = make_pair(a+2, b);
			ii p3 = make_pair(a+1, b-1);
			if(arr.find(p1) != arr.end()) tempcnt++;
			else check =1;
			if(arr.find(p2) != arr.end()) tempcnt++;
			else check = 2;
			if(arr.find(p3) != arr.end()) tempcnt++;
			else check = 3;

			if(tempcnt == 3){
				if(check==1) need.insert(p1);
				if(check==2) need.insert(p2);
				if(check==3) need.insert(p3);
			}

		}
		else c =2;
		if(arr.find(make_pair(a, b-1)) != arr.end()){
			// cout << a << " " << b-1 << " , ";

			cnt++;
			int tempcnt = 1;
			int check = 0;
			ii p1 = make_pair(a+1, b-1);
			ii p2 = make_pair(a-1, b-1);
			ii p3 = make_pair(a, b-2);
			// cout << p1.first << " " << p1.second << " - ";
			// cout << p2.first << " " << p2.second << " - ";
			// cout << p3.first << " " << p3.second << " - ";
			if(arr.find(p1) != arr.end()) tempcnt++;
			else check =1;

			if(arr.find(p2) != arr.end()) tempcnt++;
			else check = 2;

			if(arr.find(p3) != arr.end()) tempcnt++;
			else check = 3;

			//cout << tempcnt << "\n";
			if(tempcnt == 3){
				if(check==1) need.insert(p1);
				if(check==2) need.insert(p2);
				if(check==3) need.insert(p3);
			}

		}
		else c =3;
		if(arr.find(make_pair(a, b+1)) != arr.end()){
			cnt++;
			int tempcnt = 1;
			int check = 0;
			ii p1 = make_pair(a+1, b+1);
			ii p2 = make_pair(a-1, b+1);
			ii p3 = make_pair(a, b+2);
			if(arr.find(p1) != arr.end()) tempcnt++;
			else check =1;
			if(arr.find(p2) != arr.end()) tempcnt++;
			else check = 2;
			if(arr.find(p3) != arr.end()) tempcnt++;
			else check = 3;

			if(tempcnt == 3){
				if(check==1) need.insert(p1);
				if(check==2) need.insert(p2);
				if(check==3) need.insert(p3);
			}

		}
		else c =4;
		arr.insert(p);
		if(cnt == 3){
			if(c==1) need.insert(make_pair(a-1, b));
			if(c==2) need.insert(make_pair(a+1, b));
			if(c==3) need.insert(make_pair(a, b-1));
			if(c==4) need.insert(make_pair(a, b+1));
		}

		for(ii x : arr){
			cout << x.first << " " << x.second << " | ";
		}
		cout << "\n";
		cout << need.size() << "\n\n";


		
	}
}