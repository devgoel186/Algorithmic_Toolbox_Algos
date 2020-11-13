#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int get_change(int m)
{
  if (m < 0)
    return -1;
  vector<int> minNumCoins(m + 1), coins{1, 3, 4};
  minNumCoins[0] = 0, minNumCoins[1] = 1;
  for (int money = 2; money <= m; money++)
  {
    minNumCoins[money] = numeric_limits<int>::max();
    for (int coin = 0; coin < 3; coin++)
    {
      if (money >= coins[coin])
      {
        int numCoins = minNumCoins[money - coins[coin]] + 1;
        if (numCoins < minNumCoins[money])
        {
          minNumCoins[money] = numCoins;
        }
      }
    }
  }
  return minNumCoins[m];
}

int main()
{
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
