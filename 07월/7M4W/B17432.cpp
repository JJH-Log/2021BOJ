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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, t, N, M, T;
    int state;
    cin >> T;
    for (t = 0; t < T; t++) {
        cin >> N >> M;
        state = N - 1;
        while (M >= state && M > 0) {
            cout << state + 1 << ' ';
            M -= state;
            state--;
        }
        cout << M + 1 << ' ';
        for (i = 1; i <= state + 1; i++) if (i != M + 1) cout << i << ' ';
        cout << endl;
    }
    return 0;
}