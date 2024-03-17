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
#define MOD 10007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int du, mmy, a, b, c, d;
        cin >> du >> mmy;
        cin >> a >> b >> c >> d;
        if (a > b || c > d || (a * c > (b - a) * (d - c))) cout << "GOD\n";
        else cout << "KDH\n";

    }
    return 0;
}