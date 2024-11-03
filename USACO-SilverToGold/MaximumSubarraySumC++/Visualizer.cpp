#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;

    const int m = 10;
    vector<vector<int>> mat(m, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                mat[x][y]++;
            }
        }
    }

    int current = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
            if (mat[i][j] == k) {
                current++;
            }
        }
        cout << endl;
    }

    cout << current << endl;
}