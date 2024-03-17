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

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int total, N, M, temp;
    M = 0; total = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        total += temp;
        if (temp > M) M = temp;
    }
    cout << total + M * (N - 2);
    return 0;
}