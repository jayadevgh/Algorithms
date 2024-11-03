// https://codeforces.com/contest/1184/problem/C1

#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ii> points;
  vector<int> xmaxis(51);
  vector<int> ymaxis(51);
  int xcounter =0, ycounter =0;
  vector<int> xlist, ylist;
  int xmin, xmax, ymin, ymax;
  int ansa, ansb;
  for(int i =0 ; i < (4 * n + 1); i++){
  	int a, b; cin >> a >> b;
  	xmaxis[a]++; ymaxis[b]++;
  	points.push_back(make_pair(a, b));
  	// if(a ==0 && b > n){ ansa = a; ansb = b; break;}
  	// else if(a >n && b ==0){ ansa = a; ansb = b; break;}
  	// else if(a >n && b ==n){ ansa = a; ansb = b; break;}
  	// else if(a==n && b >n){ ansa = a; ansb = b; break;}
  	// else if(a !=0 && b !=0 && a != n && b!= n){ ansa = a; ansb = b; break;}
  }
  for(int i = 0; i < 51; i++){
  	if(xmaxis[i] >= n){
  		xlist.push_back(i);
  	}
  	if(ymaxis[i] >= n){
  		ylist.push_back(i);
  	}
  }
  sort(xlist.begin(), xlist.end());
  sort(ylist.begin(), ylist.end());
  xmin = xlist[0];
  xmax = xlist[xlist.size()-1];
  ymin = ylist[0];
  ymax = ylist[ylist.size()-1];
  //cout << xmin << " " << xmax << " " << ymin << " " << ymax << "\n";
  bool br = false;
  for(ii pr : points){
  	int a = pr.first, b = pr.second;


  	if((a == xmax || a ==xmin) && (b > ymax || b < ymin)) br = true;
  	else if((a > xmax || a <xmin) && (b == ymax || b == ymin)) br = true;
  	else if(a !=xmin && b !=ymin && a != xmax && b!= ymax) br = true;

  	if(br) { ansa = a; ansb = b; break;}

  }
  cout << ansa << " " << ansb;
}	