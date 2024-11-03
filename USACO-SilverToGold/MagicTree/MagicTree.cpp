#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//vector will store multiple maps + arrays and will condense them into one parent
void condense(){

}

void algo(set<int> arr, map<int,int> descendCheck, int day, int juice){

	auto itor2 = arr.upper_bound(day);
	if(itor2 != arr.begin()){--itor2;}
	if(itor2 == arr.begin() || (*itor2 > juice && descendCheck.find[day] != descendCheck.end())) return;

	if(arr.find(day) != arr.end()) descendCheck[day] += juice;
	else {
		descendCheck[day] = juice;
		arr.insert(day);
	}
	auto itor = arr.lower_bound(day);
	while(itor != *arr.rbegin() && descendCheck[day] > descendCheck[*itor]){
		arr.erase(*itor);
		descendCheck.erase(*itor);
	}
	for(auto i = descendCheck.begin(); i != descendCheck.end(); i++){
		cout << i->first << ", " << i->second << " | ";
	}

}


int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> edgeList(n+1, 0);
	for(int i =2;i < n+1;i++){
		int x;
		cin >> x;
		edgeList[i] = x;
	}
	vector<int> edgeDay(n+1, 0);
	vector<int> edgeJuice(n+1, 0);
	for(int i =0;i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edgeDay[a] = b;
		edgeJuice[a] = c;

	}

//algo test 

	
	set<int> test;
	map<int, int> descendCheck;
	test.insert(1);
	test.insert(3);
	test.insert(5);
	test.insert(7);
	test.insert(8);
	test.insert(11);
	descendCheck[1] = 3;
	descendCheck[3] = 6;
	descendCheck[5] = 12;
	descendCheck[7] = 13;
	descendCheck[8] = 17;
	descendCheck[11] = 21;
	algo(test, descendCheck, 9, 18);
	algo(test, descendCheck, 9, 16);
	algo(test, descendCheck, 3, 11);
	algo(test, descendCheck, 3, 12);
	algo(test, descendCheck, 12, 22);

}