#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// template<typename T>
// class DoubleEndedPriorityQueue {
// private:
//     priority_queue<T> max_heap;
//     priority_queue<T, vector<T>, greater<T>> min_heap;

// public:
//     void push(const T& val) {
//         max_heap.push(val);
//         min_heap.push(val);
//     }

//     void pop_max() {
//         if (!max_heap.empty()) {
//             remove_from_min_heap(max_heap.top());
//             max_heap.pop();
//         }
//     }

//     void pop_min() {
//         if (!min_heap.empty()) {
//             remove_from_max_heap(min_heap.top());
//             min_heap.pop();
//         }
//     }

//     T get_max() const {
//         return max_heap.top();
//     }

//     T get_min() const {
//         return min_heap.top();
//     }

//     bool empty() const {
//         return max_heap.empty();
//     }

//     size_t size() const {
//         return max_heap.size();
//     }

// private:
//     void remove_from_min_heap(const T& val) {
//         vector<T> temp;
//         while (!min_heap.empty() && min_heap.top() != val) {
//             temp.push_back(min_heap.top());
//             min_heap.pop();
//         }
//         min_heap.pop(); // Remove the target element
//         for (const auto& x : temp) {
//             min_heap.push(x);
//         }
//     }

//     void remove_from_max_heap(const T& val) {
//         vector<T> temp;
//         while (!max_heap.empty() && max_heap.top() != val) {
//             temp.push_back(max_heap.top());
//             max_heap.pop();
//         }
//         max_heap.pop(); // Remove the target element
//         for (const auto& x : temp) {
//             max_heap.push(x);
//         }

//     }
// };

void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int, int>> arr(n);
	priority_queue<pair<int, int>> pq;

	for(int i =0;i < n; i++){
		string s;
		cin >> s;
		int zcount =0;
		for(int i =s.size()-1 ;i >= 0; i--){
			if(s[i] == '0') zcount++;
			else break;
		}
		arr.push_back(make_pair(zcount, s.size()));
		pq.push(make_pair(zcount, s.size()));

	}
	//cout << pq.size();
	int turn = 1;
	while(pq.size() > 1 || turn == 1){
		if(turn){
			pair<int, int> p = pq.front();
			// if(m == 10){
			// 	cout << p.first << " " << p.second << " - ";
			// }
			pq.pop();
			p.second -= p.first;
			p.first = 0;
			// if(m == 10){
			// 	cout << p.first << " " << p.second << " , ";
			// }
			pq.push(p);
		}
		else{
			pair<int, int> p1 = pq.front();
			//pair<int, int> p2 = pq.get_min();
			pair<int, int> p = make_pair(0, p2.second+p1.second);
			pq.pop_max();
			pq.pop_min();
			// if(m == 10){
			// 	cout << p.first << " " << p.second << " , ";
			// }
			pq.push(p);
		}
		turn = turn ^ 1;
	}

	pair<int, int> p = pq.get_max();
	if(p.second > m) cout << "Sasha\n";
	else cout << "Anna\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t; cin >> t;
  	for(int i = 0; i < t; i++) solve();
}