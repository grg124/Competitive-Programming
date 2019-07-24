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

const int LIM = 1e5;

void test_case() {
  int n;
  cin >> n;
  int up = -LIM, down = LIM, left = -LIM, right = LIM;
  for (int i = 1; i <= n; ++i) {
    int x, y, f1, f2, f3, f4;
    cin >> x >> y >> f1 >> f2 >> f3 >> f4;
    int u = -LIM, d = LIM, l = -LIM, r = LIM;
    if (f1 == 0) {
      u = x;
    }
    if (f2 == 0) {
      r = y;
    }
    if (f3 == 0) {
      d = x;
    }
    if (f4 == 0) {
      l = y;
    }
    up = max(up, u);
    down = min(down, d);
    left = max(left, l);
    right = min(right, r);
  }
  if (up <= down && left <= right) {
    cout << 1 << " " << up << " " << left << "\n";
  } else {
    cout << 0 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    test_case();
  }
  return 0;
}
