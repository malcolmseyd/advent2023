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
    bool possible = true;
    for (auto i = start; i != end; i++) {
      smatch match = *i;
      ll count = stoll(match[1]);
      string color = match[2];
      // cout << format("{} {}\n", count, color);
      if ((color == "red" && count > 12) || (color == "green" && count > 13) ||
          (color == "blue" && count > 14)) {
        possible = false;
        break;
      }
    }
    if (possible) {
      sum += game;
    }
  }
  cout << sum << "\n";
}
