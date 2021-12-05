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

struct Node {
    bool fin;
    int cnt;
    map<char, Node*> next;
    Node() { fin = 0, cnt = 0; }
};
int N;

int dfs(Node* now, int depth) {
    int result;
    if (now->cnt == 1 && depth) return depth;
    if (now->fin) result = depth;
    else result = 0;
    if (now->next.size() == 1) result += dfs(now->next.begin()->second, max(1, depth + now->fin));
    else {
        for (auto tar : now->next) {
            result += dfs(tar.second, depth + 1);
        }
    }
    return result;
}

int simulation() {
    string s;
    int total = 0;
    Node* root = new Node();
    for (int i = 0; i < N; i++) {
        Node* curr = root;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (!curr->next.count(s[j])) {
                curr->next[s[j]] = new Node();
            }
            curr->cnt++;
            curr = curr->next[s[j]];
            if (j == s.size() - 1) {
                curr->fin = true;
                curr->cnt++;
            }
        }
    }
    return dfs(root, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(2);
    while (true) {
        cin >> N;
        if (cin.eof()) break;
        cout << (double)simulation() / N << '\n';
    }
}
