// For this problem, we proceed towards a similar implementation as the money change problem.
// We use dynamic programming to store the number of operations(or steps) taken to achieve that state.
// Refer to money change problem for more clarifications.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> optimal_sequence(int n)
{
  std::vector<int> sequence;
  while (n >= 1)
  {
    sequence.push_back(n);
    if (n % 3 == 0)
    {
      n /= 3;
    }
    else if (n % 2 == 0)
    {
      n /= 2;
    }
    else
    {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dynamic_implementation_sequence(int n)
{
  vector<int> sequence, operations(n + 1);
  operations[0] = 0, operations[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    operations[i] = operations[i - 1] + 1;

    if (i % 2 == 0 && operations[i / 2] + 1 <= operations[i])
      operations[i] = operations[i / 2] + 1;

    if (i % 3 == 0 && operations[i / 3] + 1 <= operations[i])
      operations[i] = operations[i / 3] + 1;
  }

  int i = n;
  while (i != 0)
  {
    sequence.push_back(i);
    if (operations[i] == operations[i - 1] + 1)
      i -= 1;
    else if (operations[i] == operations[i / 2] + 1)
      i /= 2;
    else
      i /= 3;
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  int n;
  cin >> n;
  // vector<int> sequence = optimal_sequence(n);
  vector<int> sequence = dynamic_implementation_sequence(n);
  cout << sequence.size() - 1 << endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    cout << sequence[i] << " ";
  }
}
