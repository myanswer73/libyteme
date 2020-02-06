// Partial taken from: https://codeforces.com/contest/1242/submission/64373553

namespace factor_t {
template <class T>
vector<pair<T, int>> factors(T n) {
  vector<pair<T, int>> ret;
  for (T i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      ret.push_back({i, cnt});
    }
  }
  if (n > 1) {
    ret.push_back({n, 1});
  }
  return ret;
}

ll phi(ll x) {
  for (auto& a : factors(x)) {
    x -= x / a.x;
  }
  return x;
}

template <class T>
void tour(vector<pair<T, int>>& v, vector<T>* ret, int idx, T cur) {
  if (idx == v.size()) {
    ret->push_back(cur);
  }
  else {
    T mul = 1;
    for (int i = 0, i < v[idx].second + 1; i++) {
      tour(v, ret, idx + 1, cur * mul);
      mul *= v[idx].first;
    }
  }
}

template <class T>
vector<T> get_divi(T x) {
  auto v = factor(x);
  vector<T> ret;
  tour(v, &ret, 0, (T)1);
  sort(ret.begin(), ret.end());
  return ret;
}

template <int N>
bitset<N> sieve() {
  bitset<N> bs;
  bs.set();
  bs[0] = 0;
  bs[1] = 0;
  for (int i = 2; i < N; i++) {
    if (bs.test(i)) {
      for (int j = i + i; j < N; j += i) {
        bs.reset(j);
      }
    }
  }
  return bs;
}

template <int N>
vector<int> get_prime() {
  vector<int> prime;
  auto bs = sieve<N>();
  for (int i = 1; i < N; i++) {
    if (bs.test(i)) {
      prime.push_back(i);
    }
  }
  return prime;
}

bool is_prime(ll n) {
  for (ll x = 2; x * x <= n; x++) {
    if (n % x == 0) {
      return false;
    }
  }
  return true;
}
}  // namespace factor_t
