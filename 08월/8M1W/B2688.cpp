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

vector<vector<lld>> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    v.resize(64, vector<lld>(10, 0));
    int i, j, k, t, T, now;
    lld result;
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 10; j++) {
            if (!i) v[i][j] = 1;
            else for (k = 0; k <= j; k++) v[i][j] += v[i - 1][k];
        }
    }

    cin >> T;
    for (t = 0; t < T; t++) {
        result = 0;
        cin >> now;
        for (int i = 0; i < 10; i++) result += v[now - 1][i];
        cout << result << '\n';
    }
    
    return 0;
}