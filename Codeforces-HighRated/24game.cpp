// https://codeforces.com/contest/468/problem/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void add(int a, int b){
	cout << a << " + " << b << " = " << a+b << "\n"; 
}
void sub(int a, int b){
	cout << a << " - " << b << " = " << a-b << "\n"; 
}
void mul(int a, int b){
	cout << a << " * " << b << " = " << a*b << "\n"; 
}



int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int n;
  	cin >> n;
  	if(n < 4){
  		cout << "NO";
  		return 0;
  	}
  	cout << "YES\n";
  	int count = 0;
  	while(n > 5){
  		sub(n, n-1);
  		n -= 2;
  		count++;
  	}
  	if(n == 4){
  		mul(4, 3);
  		mul(12, 2);
  		mul(24, 1);
  	}
  	else if(n == 5){
  		sub(5, 1);
  		sub(4, 2);
  		mul(4, 2);
  		mul(8, 3);
  	}
  	for(int i =0;i < count; i++){
  		mul(24, 1);
  	}
}