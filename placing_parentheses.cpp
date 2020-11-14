#include <iostream>
#include <algorithm>
#include <limits>
#include <cassert>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

ll eval(ll a, ll b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else
  {
    assert(0);
  }
}

ll get_maximum_value(const string &exp)
{
  vector<vector<ll>> M(exp.length() / 2 + 1, vector<ll>(exp.length() / 2 + 1, 0)), m(exp.length() / 2 + 1, vector<ll>(exp.length() / 2 + 1, 0));
  for (ll i = 0; i < exp.length() / 2 + 1; i++)
  {
    m[i][i] = stoll(exp.substr(2 * i, 1));
    M[i][i] = stoll(exp.substr(2 * i, 1));
  }

  for (ll s = 0; s < exp.length() / 2; s++)
  {
    for (ll i = 0; i < exp.length() / 2 - s; i++)
    {
      ll j = i + s + 1;
      ll max = numeric_limits<ll>::min();
      ll min = numeric_limits<ll>::max();
      for (ll k = i; k < j; k++)
      {
        ll a = eval(M[i][k], M[k + 1][j], exp[2 * k + 1]);
        ll b = eval(M[i][k], m[k + 1][j], exp[2 * k + 1]);
        ll c = eval(m[i][k], M[k + 1][j], exp[2 * k + 1]);
        ll d = eval(m[i][k], m[k + 1][j], exp[2 * k + 1]);

        min = std::min({min, a, b, c, d});
        max = std::max({max, a, b, c, d});
      }
      m[i][j] = min;
      M[i][j] = max;
    }
  }
  // Testing Output (Grid Output)
  // for (int i = 0; i < exp.length() / 2 + 1; i++)
  //   for (int j = 0; j < exp.length() / 2 + 1; j++)
  //     cout << M[i][j] << " ";
  //   cout << "\n";
  // cout << "\n";
  // for (int i = 0; i < exp.length() / 2 + 1; i++)
  //   for (int j = 0; j < exp.length() / 2 + 1; j++)
  //     cout << m[i][j] << " ";
  //   cout << "\n";

  return M[0][exp.length() / 2];
}

int main()
{
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}
