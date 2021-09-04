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
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

lld v[90][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    v[0][0] = 1;
    v[0][1] = 1;
    for (int i = 1; i < 90; i++) {
        for (int j = 0; j < 2; j++) {
            v[i][0] = v[i - 1][0] + v[i - 1][1];
            v[i][1] = v[i - 1][0];
        }
    }
    int N;
    cin >> N;
    cout << v[N - 1][1];

    return 0;
}