#include <iostream>
#include <vector>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  int size = weights.size();
  vector<double> v_by_w(size);

  for (int j = 0; j < size; j++)
    v_by_w[j] = (double)values[j] / weights[j];

  for (int i = 0; i < size; i++)
  {
    if (capacity == 0)
      return value;

    int pos = 0;
    for (int j = 0; j < size; j++)
      if (v_by_w[j] > v_by_w[pos] && weights[j] > 0)
        pos = j;

    int min_weight = weights[pos];

    if (min_weight > capacity)
      min_weight = capacity;

    weights[pos] -= min_weight;
    value += min_weight * v_by_w[pos];
    capacity -= min_weight;
  }
  return value;
}

int main()
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
