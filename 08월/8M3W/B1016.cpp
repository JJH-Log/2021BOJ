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
#define MOD 1000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;
vector<bool> nn;

bool isPrime(int X) {
    int sX = (int)sqrt(X);
    for (int i = 0; v[i] <= sX; i++) {
        if (X % v[i] == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    lld A, B, now, check;
    int i, j;
    v.push_back(2);
    for (i = 3; i < 3162278; i += 2) if (isPrime(i)) v.push_back(i);
    cin >> A >> B;
    nn.resize(B - A + 1, true);
    for (i = 0; i < v.size(); i++) {
        check = (lld)v[i] * v[i];
        now = (A / check) * check;
        while (now <= B) {
            if (now - A >= 0) nn[now - A] = false;
            now += check;
        }
    }
    int result = 0;
    for (i = 0; i <= B - A; i++) if (nn[i]) result++;
    cout << result;

    return 0;
}