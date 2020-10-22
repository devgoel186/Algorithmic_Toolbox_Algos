#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n)
{
    vector<int> a(n + 1, 0);
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = (a[i - 1]%10 + a[i - 2]%10)%10;
    }
    return a[n];
}

int main()
{
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    int d = get_fibonacci_last_digit_fast(n);
    // std::cout << c << '\n';
    std::cout << d << '\n';
}
