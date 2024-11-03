#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void solve(){
	long double n, m, k;
	cin >> n >> m >> k;
	multiset<long double> a, b;
	long double suma = 0, sumb = 0;
	//long double l = 1e5-1e4;
	//n = l, m = l;
	for(long double i =0;i < n; i++){
		long double x;
		cin >> x;
		//x = 1e9-59;
		a.insert(x);
		suma += x;
		//cout << a.count(x);
	}
	for(long double i =0;i < m; i++){
		long double x;
		cin >> x;
		b.insert(x);
		sumb += x;
	}
	long double ans = (suma/n + sumb/m)/2;
	for(long double i =0; i < k; i++){
		long double mina = *a.begin();
		long double minb = *b.begin();
		long double maxa = *a.rbegin();
		long double maxb = *b.rbegin();
		//cout << "(" << mina << ", " << maxa << ", " << minb << ", " << maxb << ") ";
		long double des = 0;
		long double maxi = (suma/n + sumb/m)/2;
		if(maxi < ((suma-mina)/(n-1) + (sumb + mina)/(m+1))/2 ){

			maxi = ((suma-mina)/(n-1) + (sumb + mina)/(m+1))/2;
			des =1;
		}
		if(maxi < ((suma-maxa)/(n-1) + (sumb + maxa)/(m+1))/2 ){
			maxi = ((suma-maxa)/(n-1) + (sumb + maxa)/(m+1))/2;
			des =2;
		}
		if(maxi < ((suma+minb)/(n+1) + (sumb - minb)/(m-1))/2 ){
			maxi = ((suma+minb)/(n+1) + (sumb - minb)/(m-1))/2;
			des =3;
		}
		if(maxi < ((suma+maxb)/(n+1) + (sumb - maxb)/(m-1))/2 ){
			maxi = ((suma+maxb)/(n+1) + (sumb - maxb)/(m-1))/2;
			des =4;
		}
		//cout << "(" << (suma/n + sumb/m)/2 << ", " << ((suma-mina)/(n-1) + (sumb + mina)/(m+1))/2 << ", " << ((suma-maxa)/(n-1) + (sumb + maxa)/(m+1))/2 << ", " << ((suma+minb)/(n+1) + (sumb - minb)/(m-1))/2 << ", " << ((suma+maxb)/(n+1) + (sumb - maxb)/(m-1))/2 << ")\n";
		ans = maxi;
		if(des == 0) break;
		if(des==1){
			//cout << a.count(mina);
			a.erase(a.find(mina));
			//cout << a.count(mina);
			b.insert(mina);
			n--; m++;
			suma-= mina;
			sumb += mina;
		}
		if(des==2){
			a.erase(a.find(maxa));
			b.insert(maxa);
			n--; m++;
			suma-= maxa;
			sumb += maxa;
		}
		if(des==3){
			//cout << b.count(minb);
			b.erase(b.find(minb));
			//cout << b.count(minb);
			a.insert(minb);
			n++; m--;
			suma += minb;
			sumb -= minb;
		}
		if(des==4){
			b.erase(b.find(maxb));
			a.insert(maxb);
			n++; m--;
			suma += maxb;
			sumb -= maxb;
		}
		mina = *a.begin();
		minb = *b.begin();
		maxa = *a.rbegin();
		maxb = *b.rbegin();
		//cout << "(" << mina << ", " << maxa << ", " << minb << ", " << maxb << ")\n\n";

	}

	cout << (suma/n + sumb/m)/2<<"\n";


}

int main() {
  //Console
	cout << setprecision(16);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long double t;
	cin >> t;
	for(long double i =0;i < t; i++){
		solve();
	}
	// long double yest = ((92.00000000/13.000000000) + 14.0)/2.0;
	// cout << setprecision(10) << yest;
}