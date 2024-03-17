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

vector<int> dv; //약수를 저장
int N;

lld getEulerPhi(lld now, int modulo, bool div) {
    lld result = 1;
    if (div) {
        int cnt = 0;
        while (!(now % modulo)) now /= modulo, cnt++;
        for (int i = 0; i < cnt - 1; i++) result *= modulo;
        result *= (modulo - 1);
        modulo++;
    }
    for (int i = modulo; i <= sqrt(now); i++) {
        if (!(now % i)) return result * getEulerPhi(now, i, true);
    }
    if (now == 1) return result;
    else return result * (now - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= sqrt(N); i++) {
        if (!(N % i)) dv.push_back(i), dv.push_back(N / i);
    }
    sort(dv.begin(), dv.end());
    for (auto div : dv) {
        if (N == getEulerPhi(div, 2, false) * div) {
            cout << div;
            return 0;
        }
    }
    cout << -1;

    return 0;
}