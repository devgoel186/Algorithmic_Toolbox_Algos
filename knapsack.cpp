// This is a problem for discrete knapsack, to be specific, knapsack without repetitions

#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w)
{
  vector<vector<int>> values(w.size() + 1, vector<int>(W + 1, 0));

  for (int i = 0; i <= w.size(); i++)
    values[i][0] = 0;

  for (int j = 0; j <= W; j++)
    values[0][j] = 0;

  for (int i = 1; i <= w.size(); i++)
  {
    for (int weight = 1; weight <= W; weight++)
    {
      values[i][weight] = values[i - 1][weight];
      if (w[i - 1] <= weight)
      {
        int val = values[i - 1][weight - w[i - 1]] + w[i - 1];
        if (values[i][weight] < val)
          values[i][weight] = val;
      }
    }
  }

  // Testing Output (Edit Distance Grid)
  // for (int i = 0; i <= w.size(); i++)
  // {
  //   for (int j = 0; j <= W; j++)
  //   {
  //     cout << values[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  return values[w.size()][W];
}

int main()
{
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
  }
  cout << optimal_weight(W, w) << '\n';
}
