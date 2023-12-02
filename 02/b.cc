#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

template <typename T>
T nxt() {
  T x;
  cin >> x;
  return x;
}

int main() {
  regex color_pattern("(\\d+) (red|green|blue)");
  string line;
  ll sum = 0;
  ll game = 0;
  while (getline(cin, line)) {
    game += 1;
    sregex_iterator start(all(line), color_pattern);
    sregex_iterator end;
    ll maxr = 0;
    ll maxg = 0;
    ll maxb = 0;
    for (auto i = start; i != end; i++) {
      smatch match = *i;
      ll count = stoll(match[1]);
      string color = match[2];
      // cout << format("{} {}\n", count, color);
      if (color == "red") {
        maxr = max(maxr, count);
      } else if (color == "green") {
        maxg = max(maxg, count);
      } else if (color == "blue") {
        maxb = max(maxb, count);
      }
    }
    sum += maxr * maxg * maxb;
  }
  cout << sum << "\n";
}
