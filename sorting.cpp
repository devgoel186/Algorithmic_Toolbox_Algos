#include <iostream>
#include <vector>
#include <cstdlib>

using std::swap;
using std::vector;

vector<int> partition3(vector<int> &a, int l, int r)
{
  int x = a[l];
  vector<int> m(2);
  int j = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] <= x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  m[1] = j;
  for (int i = l; i < j;)
  {
    if (a[i] == x)
    {
      j--;
      swap(a[i], a[j]);
    }
    else
    {
      i++;
    }
  }
  m[0] = j;
  return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
}
