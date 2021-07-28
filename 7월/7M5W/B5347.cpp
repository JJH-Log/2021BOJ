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

int gcd(int x, int y) {
    int temp;
    while (y) {
        temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        cout << ((lld)x * y / gcd(x, y)) << '\n';
    }

    return 0;
}