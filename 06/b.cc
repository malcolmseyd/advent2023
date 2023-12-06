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

#ifndef NDEBUG
#define DEBUG(args...) (cout << format(args))
#else
#define DEBUG(...) 0
#endif

ll read_space_number() {
  while (getchar() != ':')
    ;
  ll num = 0;
  char c;
  while ((c = getchar()) != '\n') {
    if (c == ' ') continue;
    num *= 10;
    num += c - '0';
  }
  return num;
}

struct Solution {
  auto solve() {
    ll time = read_space_number();
    ll max_dist = read_space_number();
    // DEBUG("time={} max_dist={}\n", time, max_dist);
    return solve_line(time, max_dist);
  }
  ll solve_line(ll time, ll max_dist) {
    ll ways = 0;
    for (int hold = 0; hold <= time; hold++) {
      ll dist = hold * (time - hold);
      // DEBUG("hold={} dist={} max_dist={}\n", hold, dist, max_dist);
      if (dist > max_dist) ways++;
    }
    return ways;
  }
};

int main() { cout << Solution().solve() << endl; }
