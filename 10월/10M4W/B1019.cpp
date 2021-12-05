#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

lld cnt[10];

pair<int, int> getHighestNum(int X) { //degree, num
    int result = 0;
    while (X >= 10) {
        X /= 10;
        result++;
    }
    return { result, X };
}

void getPage(int X) {
    if (!X) return;
    pair<int, int> best = getHighestNum(X);
    lld divs = 1;
    for (int i = 0; i < best.first; i++) divs *= 10;
    for (int i = 1; i < best.second; i++) cnt[i] += divs;
    cnt[best.second] += (X % divs) + 1;
    for (int i = 1; i < 10; i++) cnt[i] += (lld)best.second * best.first * divs / 10;
    getPage(X % divs);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int N;
    cin >> N;
    getPage(N);
    lld total = 0;
    for (int i = 1; i < 10; i++) total += cnt[i];

    pair<int, int> best = getHighestNum(N);
    lld divs = 1;
    for (int i = 0; i < best.first; i++) divs *= 10;
    cnt[0] = ((lld)N + 1) * (best.first + 1) - total;
    while (divs) cnt[0] -= divs, divs /= 10;
    
    for (int i = 0; i < 10; i++) cout << cnt[i] << ' ';


    return 0;
}
