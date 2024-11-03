#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int> 
using namespace std;

ll N, a, b, c, d, e, f, g, h, M;
class Compare {
public:
    bool operator()(ii hi, ii lo)
    {
        if (lo.first > hi.first) {
            return true;
        }
        else if (lo.first == hi.first && lo.second < hi.second) {
            return true;
        }
 
        return false;
    }
};
ii makeAcorn(int x){
  int w, u, t, y, z;
  w = 0; u = 0;
  t = a % d; y = b % d; z = c % d;
  for(int i =0; i < 5; i++){
    t = ((x % d) * t) % d;
  }
  for(int i =0; i < 2; i++){
    y = ((x % d) * y) % d;
  }
  w = (t + y + z) % d;

  t = e % h; y = f % h; z = g % h;
  for(int i =0; i < 5; i++){
    t = ((x % h) * t) % h;
  }
  for(int i =0; i < 3; i++){
    y = ((x % h) * y) % h;
  }

  u = (t + y + z) % h;
  return make_pair(u, w);
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> a >> b >> c >> d >> e >> f >> g >> h >> M;
  priority_queue<ii, vector<ii>, Compare> pq;
  for(int i =0; i < N * 3; i++){
    ii p = makeAcorn(i);
    pq.push(p);
    //cout << p.first << " " << p.second << "\n";
  }
  int ans = 0;
  for(int i = 0; i < N; i++){
    ans += pq.top().second;
    //cout << pq.top().first << " " << pq.top().second << "\n";
    pq.pop();
    ans %= M;
  }
  cout << ans;
}