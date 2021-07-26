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

set<string> state;
queue<pair<string, int>> q;


vector<string> getState(string X) {
    vector<string> result;
    string cX;
    int i, zero;
    for (i = 0; i < 9; i++) if (X[i] == '0') zero = i;
    if (zero % 3) {
        cX = X;
        swap(cX[zero], cX[zero - 1]);
        result.push_back(cX);
    }
    if (zero % 3 != 2) {
        cX = X;
        swap(cX[zero], cX[zero + 1]);
        result.push_back(cX);
    }
    if (zero / 3) {
        cX = X;
        swap(cX[zero], cX[zero - 3]);
        result.push_back(cX);
    }
    if (zero / 3 != 2) {
        cX = X;
        swap(cX[zero], cX[zero + 3]);
        result.push_back(cX);
    }
    return result;
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    int result = -1;
    char c;
    string start = "";
    string end = "123456780";

    
    for (i = 0; i < 9; i++) {
        cin >> c;
        start += c;
    }
    q.push({ start, 0 });
    while (!q.empty() && (result == -1)) {
        pair<string, int> now = q.front();
        q.pop();
        if (now.first == end) result = now.second;
        else {
            vector<string> next = getState(now.first);
            for (i = 0; i < next.size(); i++) {
                if (!state.count(next[i])) {
                    state.insert(next[i]), q.push({ next[i], now.second + 1 });
                }
            }
        }
    }   
    cout << result;
    return 0;
}