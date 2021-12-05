#define _CRT_SECURE_NO_WARNINGS
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
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


deque<int> q;
multiset<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, temp, K, N;
    lld total = 0;
    cin >> N >> K;
    for (i = 0; i < K; i++) {
        cin >> temp;
        q.push_back(temp);
        s.insert(temp);
    }
    multiset<int>::iterator it = s.begin();
    multiset<int>::iterator rm;
    for (i = 0; i < (K / 2); i++) it++;
    if (K % 2 == 0) it--;

    total += (*it);
    for (i = K; i < N; i++) {
        cin >> temp;
        q.push_back(temp);
        s.insert(temp);

        if (temp >= (*it)) it++;
        temp = q.front();
        if (temp > (*it)) it--;
        rm = s.lower_bound(temp);
        if (rm == it) it--;
        s.erase(rm);
        q.pop_front();

        total += (*it);
    }
    cout << total;
    return 0;
}