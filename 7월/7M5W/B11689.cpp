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


int modulo;

lld getEulerPhi(lld now, int modulo, bool div) {
    lld result = 1;
    if (div) {
        int cnt = 0;
        while (!(now % modulo)) now /= modulo, cnt++;
        result = pow(modulo, cnt - 1);
        result *= (lld)modulo - 1;
        modulo++;
    }
    for (int i = modulo; i <= (int)sqrt(now); i++) {
        if (now % i == 0) return result * getEulerPhi(now, i, true);
    }
    if (now == 1) return result;
    else return result * (now - 1);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    lld N, result;
    cin >> N;
    result = getEulerPhi(N, 2, false);
    cout << result;
    return 0;
}