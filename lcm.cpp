#include <iostream>
using namespace std;

typedef long long ll;

ll lcm_naive(int a, int b)
{
  for (long l = 1; l <= (ll)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (ll)a * b;
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

ll lcm_fast(int a, int b)
{
  return (ll)a * b / gcd_fast(a, b);
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
  //   if (lcm_naive(a, b) != lcm_fast(a, b))
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
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
