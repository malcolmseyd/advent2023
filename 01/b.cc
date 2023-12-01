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

int parse(string_view s) {
  if (s.length() == 0) return 0;
  if (s[0] >= '0' && s[0] <= '9') return s[0] - '0';
  if (s == "one") {
    return 1;
  } else if (s == "two") {
    return 2;
  } else if (s == "three") {
    return 3;
  } else if (s == "four") {
    return 4;
  } else if (s == "five") {
    return 5;
  } else if (s == "six") {
    return 6;
  } else if (s == "seven") {
    return 7;
  } else if (s == "eight") {
    return 8;
  } else if (s == "nine") {
    return 9;
  }
  return 0;
}

int main() {
  regex number_pattern("one|two|three|four|five|six|seven|eight|nine|[0-9]");
  regex number_backwards_pattern(
      "enin|thgie|neves|xis|evif|ruof|eerht|owt|eno|[0-9]");
  string line;
  ll sum = 0;
  while (getline(cin, line)) {
    ll first = -1;
    ll last = -1;

    smatch match;
    regex_search(line, match, number_pattern);
    first = parse(match.str());

    reverse(all(line));
    regex_search(line, match, number_backwards_pattern);
    string s = match.str();
    reverse(all(s));
    last = parse(s);

    sum += first * 10 + last;
    // cout << (first * 10 + last) << endl;
  }
  cout << sum << endl;
}
