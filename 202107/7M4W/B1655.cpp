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

priority_queue<int> pqMax;
priority_queue<int, vector<int>, greater<int>> pqMin;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x;
    cin >> N;
    pqMin.push(10001);
    pqMax.push(-10001);
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (pqMin.top() > x) {
            pqMax.push(x);
            if (pqMax.size() - pqMin.size() == 2) {
                pqMin.push(pqMax.top());
                pqMax.pop();
            }
        }
        else {
            pqMin.push(x);
            if (pqMin.size() - pqMax.size() == 1) {
                pqMax.push(pqMin.top());
                pqMin.pop();
            }
        }
        cout << pqMax.top() << '\n';
    }


    return 0;
}