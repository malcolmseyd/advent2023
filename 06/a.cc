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

struct Solution {
  void read() {
    string line;

    while (getchar() != ':') times_;
    getline(cin, line);
    stringstream ss(line);
    ll num;
    while (ss >> num) {
      // DEBUG("{} ", num);
      times_.push_back(num);
    }
    // DEBUG("\n");
    while (getchar() != ':')
      ;
    getline(cin, line);
    ss = stringstream(line);
    while (ss >> num) {
      // DEBUG("{} ", num);
      distances_.push_back(num);
    }
  }
  auto solve() {
    read();
    ll ans = 1;
    for (ll i = 0; i < times_.size(); i++) {
      ll ways = solve_line(times_[i], distances_[i]);
      ans *= ways;
    }
    return ans;
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
  vector<ll> times_;
  vector<ll> distances_;
};

int main() { cout << Solution().solve() << endl; }
