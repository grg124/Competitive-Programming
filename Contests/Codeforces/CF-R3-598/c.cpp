#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void test_case() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m + 1);
    int left = n;
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
        left -= c[i];
    }
    vector<int> mark(n + 1);
    int ctr = 1;
    int pos = 0;
    while (pos <= n) {
        int jmp = min(d, left + 1);
        pos += jmp;
        left -= jmp - 1;
        for (int i = 0; i < c[ctr]; ++i) {
            mark[pos + i] = ctr;
        }
        pos += c[ctr] - 1;
        ++ctr;
        if (ctr == m + 1) {
            if (pos + d > n) {
                break;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        cout << mark[i] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
