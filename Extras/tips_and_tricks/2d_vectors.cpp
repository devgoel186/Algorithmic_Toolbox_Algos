#include <limits>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /* We initialize a 2D vector named "vect" on line 16 with different number of values 
    in each element. */

    vector<vector<int>> vect{
        {1, 2},         /* Element one with 2 values in it. */
        {4, 5, 6},      /* Element two with 3 values in it. */
        {7, 8, 9, 10}}; /* Element three with 4 values in it. */

    // Now we print the vector that we just defined using a simple nested for loop.

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl ;
    }    
    cout << "\n";

    // We initialize a 2-d array using nested loops.

    int n = 3;
    int m = 4;

    /* We create a 2D vector containing "n" elements each having the value "vector<int> (m, 0)".
    "vector<int> (m, 0)" means a vector having "m" elements each of value "0". Here these elements are vectors.*/
    vector<vector<int>> vec(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}