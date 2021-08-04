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


int gcd(int X, int Y) {
    if (X < Y) return gcd(Y, X);
    if (Y == 0) return X;
    else return gcd(Y, X % Y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, T;
    lld a, b, u, g;
    pair<int, int> ans;
    cin >> T;
    for (t = 0; t < T; t++) {
        cin >> a >> b;
        while (a != 1) {
            u = b / a + 1;
            a = a * u - b;
            b *= u;
            g = gcd(a, b);
            a /= g;
            b /= g;
            //cout << a << ' ' << b << endl;
        }
        cout << b << '\n';
    }

    return 0;
}