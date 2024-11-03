#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMin(long long arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        if (res > arr[i])
            res = arr[i];
    return res;
}

int main() {
    //int num_months = 12;
    //long long no_days[] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num_months = 4;
    long long no_days[] = {31, 35, 28, 29};
    cin >> num_months;
    for(int i =0;i < num_months; i++) cin >> no_days[i];

    int n = sizeof(no_days)/sizeof(no_days[0]);

   long long min_element = getMin(no_days, n);
    long long max_value = min_element / 4;
   
    vector<long long> num;
   
    for (long long i = 1; i <= max_value; i++) {
        int count = 0;
        set<long long> s;
   
        for (long long j = 0; j < n; j++) {
            s.insert(no_days[j] % i);  
            if (s.size() == 4)
                break;
        }
        if (s.size() <= 3)
            num.push_back(i);
    }
    long long total = 0;
    for(long long i : num) total += i;

    //cout << 'l';

    cout << total;
}
