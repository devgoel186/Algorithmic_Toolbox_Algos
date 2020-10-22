#include <iostream>
#include <vector>
using namespace std;

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b)
{
  if (b == 0)
    return a;
  else
  {
    return gcd_fast(b, a % b);
  }
}

int main()
{

  // Stress - Testing
  // while (true)
  // {
  //   // vector<ll> a;
  //   int a = rand() % 100000 + 1;
  //   int b = rand() % 100000 + 1;
  //   // for (int i = 0; i < len; i++)
  //   // {
  //   //     a.push_back(rand() % 1000000 + 2);
  //   // }
  //   // for (int i = 0; i < len; i++)
  //   // {
  //   printf("%d ", a);
  //   printf("%d ", b);
  //   // }
  //   // cout << "\n";
  //   if (gcd_naive(a, b) != gcd_fast(a, b))
  //   {
  //     printf("Wrong Answer!\n");
  //     break;
  //   }
  //   else
  //   {
  //     printf("OK\n");
  //   }
  // }

  int a, b;
  std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
