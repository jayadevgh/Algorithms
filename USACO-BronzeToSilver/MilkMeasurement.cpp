#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<tuple<int, string,int>> input;
  int n;
  cin >> n; 
  for(int i = 0; i < n; i++){
    int day;
    string name;
    int amount;
    cin >> day >> name >> amount;
    input.push_back(make_tuple(day, name, amount));
  }
  sort(input.begin(), input.end());

  map<string, int> cows = {
  {"Bessie", 0},{"Mildred", 0},{"Elsie", 0}
  };
  int changes = 0;

  pair<int, string> frame;
  frame.first = 0;
  frame.second = "BessieMildredElsie";
  for(int i = 0; i < n; i++){
    
    cows[get<1>(input[i])] += get<2>(input[i]);

    frame.first = max({cows["Bessie"], cows["Elsie"], cows["Mildred"]});
    string newframe = "";
    if(cows["Bessie"] == frame.first){
      newframe += "Bessie";
    }
    if(cows["Mildred"] == frame.first){
      newframe += "Mildred";
    }
    if(cows["Elsie"] == frame.first){
      newframe += "Elsie";
    } 
    if(frame.second != newframe){
      changes++;
      frame.second = newframe;
    }
  }
  cout << changes << endl;
}