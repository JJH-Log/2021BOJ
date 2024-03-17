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

int gcd(int X, int Y) {
    if (X < Y) return gcd(Y, X);
    if (!Y) return X;
    return gcd(Y, X % Y);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, G;
    cin >> A >> B;
    G = gcd(A, B);
    cout << (B / G - 1) * G;
    return 0;
}