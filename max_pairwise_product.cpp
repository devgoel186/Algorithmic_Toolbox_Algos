#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll MaxPairwiseProduct(const vector<ll> &numbers)
{
    ll max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = max(max_product,
                              numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

ll MaxPairwiseProductFast(const vector<ll> &numbers)
{
    ll max_product = 0;
    int n = numbers.size();
    ll largest = 0;
    int pos1 = 0;
    ll sec_largest = 0;

    for (int i = 0; i < n; ++i)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
            pos1 = i;
        }
    }

    for (int i = 0; i < n; i++)
        if (i != pos1 && numbers[i] > sec_largest)
            sec_largest = numbers[i];

    max_product = largest * sec_largest;
    return max_product;
}

int main()
{
    //Stress - Testing
    // while (true)
    // {
    //     vector<ll> a;
    //     int len = rand() % 100 + 2;
    //     for (int i = 0; i < len; i++)
    //     {
    //         a.push_back(rand() % 1000000 + 2);
    //     }
    //     for (int i = 0; i < len; i++)
    //     {
    //         printf("%lld ", a[i]);
    //     }
    //     cout << "\n";
    //     if (MaxPairwiseProduct(a) != MaxPairwiseProductFast(a)) {
    //         printf("Wrong Answer!\n");
    //         break;
    //     }
    //     else
    //     {
    //         printf("OK\n");
    //     }
    // }
    int n;
    cin >> n;
    vector<ll> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
