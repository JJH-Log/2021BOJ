#include<iostream>
#include<vector>
using namespace std;

vector<vector <int>> v;

int main()
{
    int i, j, k, N, result;
    int lmax, rmax;
    cin >> N;
    v.resize(N, vector<int>(3, -1));

    for (i = 0; i < N; i++) {
        cin >> v[i][0];
    }

    result = -1;
    for (i = 1; i <= 1000; i++) {
        lmax = -1;
        for (j = 0; j < N; j++) {
            if ((lmax < v[j][1]) & (v[j][0] !=i)) lmax = v[j][1];
            if (v[j][0] == i) {
                rmax = -1;
                for (k = j; k < N; k++) {
                    if ((rmax < v[k][2]) & (v[k][0] != i)) rmax = v[k][2];
                }
                v[j][1] = lmax+1;
                v[j][2] = rmax+1;
                if (result < lmax + rmax + 3) {
                    result = lmax + rmax + 3;
                }
               // cout << v[j][0] << " " << v[j][1] << " " << v[j][2] << "\n";
            }
        }
    }

    cout << result;
    return 0;
}
