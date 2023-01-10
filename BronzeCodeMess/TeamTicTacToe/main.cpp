#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

  freopen("tttt.in","r",stdin);
	freopen("tttt.out","w",stdout);
  int solo = 0;
  int duo = 0;
  vector<vector<char>> board(3, vector<char>(3));
  set<set<char>> winners;
  
  for(int i = 0; i < 3; i++){
    string str;
    cin >> str;
    char f = str[0];
    char s = str[1];
    char t = str[2];
    if(t == f || t == s || f == s){
      if(f == s && s == t) winners.insert({f});
      else if(t==f) winners.insert({t, s});
      else winners.insert({f, t});
    }
    for(int j = 0; j < 3; j++){
      board[i][j] = str[j];
    }
  }
  char a1 = board[0][0];
  char a2 = board[0][1];
  char a3 = board[0][2];
  char a4 = board[1][0];
  char a5 = board[1][1];
  char a6 = board[1][2];
  char a7 = board[2][0];
  char a8 = board[2][1];
  char a9 = board[2][2];
  //diagonals
  if(a1 == a5 || a1 == a9 || a5 == a9){
    if(a5 == a9 && a9 == a1) winners.insert({a1});
    else if(a1==a5) winners.insert({a1, a9});
    else winners.insert({a1, a5});
  }
  if(a3 == a5 || a3 == a7|| a5 == a7){
    if(a5 == a7 && a3 == a7) winners.insert({a7});
    else if(a3==a5) winners.insert({a3, a7});
    else winners.insert({a3, a5});
  }
  //columns
  if(a1 == a4 || a1 == a7 || a4 == a7){
    if(a4 == a7 && a1 == a7) winners.insert({a1});
    else if(a1==a4) winners.insert({a1, a7});
    else winners.insert({a1, a4});
  }
  if(a2 == a5 || a2 == a8 || a5 == a8){
    if(a5 == a8 && a2 == a8) winners.insert({a2});
    else if(a2==a5) winners.insert({a2, a8});
    else winners.insert({a2, a5});
  }
  if(a3 == a6 || a3 == a9 || a6 == a9){
    if(a6 == a9 && a3 == a9) winners.insert({a3});
    else if(a3==a6) winners.insert({a3, a9});
    else winners.insert({a3, a6});
  }
  for(auto& str : winners){
    if(str.size() == 2) duo++;
    else solo++;
    // for(auto& temp : str){
    //   cout << temp;
    // }
  }
  cout << solo << '\n' << duo << '\n';
}