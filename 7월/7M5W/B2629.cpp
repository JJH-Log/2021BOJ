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

priority_queue<int, vector<int>, greater<int>> pqA, pqB;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i, C, M;
    int now, before, tar;
    cin >> C;
    v.resize(C, 0);
    pqA.push(0);
    for (i = 0; i < C; i++) cin >> v[i];
    for (i = 0; i < C; i++) {
        before = -1;
        while (!pqA.empty()) {
            now = pqA.top();
            pqA.pop();
            if (now == before) continue;
            pqB.push(now);
            pqB.push(now - v[i]);
            pqB.push(now + v[i]);
            before = now;
        }
        swap(pqA, pqB);
    }
    v.clear();
    v.resize(15001, 0);
    while (!pqA.empty()) {
        v[abs(pqA.top())] = 1;
        pqA.pop();
    }
    cin >> M;
    for (i = 0; i < M; i++) {
        cin >> tar;
        if (v[tar]) cout << "Y ";
        else cout << "N ";
    }


    return 0;
}