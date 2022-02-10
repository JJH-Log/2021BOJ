#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int dayToInt(int mm, int dd) {
    if (mm < 3) return 0;
    else if (mm > 12) return 274;
    int cal[9] = { 31,30,31,30,31,31,30,31,30 };
    int result = 0;
    for (int i = 3; i < mm; i++) result += cal[i - 3];
    return result + dd - 1;

}

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, N;
    v.resize(275, -1);

    int m1, d1, m2, d2, l, r;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> m1 >> d1 >> m2 >> d2;
        l = dayToInt(m1, d1);
        r = dayToInt(m2, d2 - 1);
        v[l] = max(v[l], r);
    }

    int nmax, maxi;
    nmax = maxi = -1;
    int result = 0;
    for (i = 0; i < 275; i++) {
        if (i > maxi) {
            if (v[i] == -1) {
                if (nmax <= maxi) {
                    cout << 0;
                    return 0;
                }
            }
            nmax = max(v[i], nmax);
            maxi = nmax;
            result++;
        }
        else nmax = max(v[i], nmax);
    }

    cout << result;

    return 0;
}