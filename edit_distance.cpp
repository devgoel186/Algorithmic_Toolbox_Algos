// For this program, we tend to minimize the edit distance for two strings. We will use
// backtracking pointers, so as to find the optimal path, and the minimum edit distance.

// We will construct a (n+1) * (m+1) grid to analyze the edit distance and the optimal path,
// and then use backtracking to reconstruct our optimal alignment. This is an example of Dynamic Programming.

// Remember, minimum edit distance corresponds to maximum alignment score, also known as optimal alignment.
// EDIT-DISTANCE = #INSERTIONS + #DELETIONS + #MISMATCHES
// ALIGNMENT SCORE = #MATCHES - (mu)#MISMATCHES - (sigma)#INSERTIONS OR DELETIONS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int edit_distance(const string &str1, const string &str2)
{
  vector<vector<int>> a(str1.size() + 1, vector<int>(str2.size() + 1, 0));
  for (int i = 0; i <= str1.size(); i++)
    a[i][0] = i;
  for (int j = 0; j <= str2.size(); j++)
    a[0][j] = j;
  for (int j = 1; j <= str2.size(); j++)
  {
    for (int i = 1; i <= str1.size(); i++)
    {
      int insertion = a[i][j - 1] + 1;
      int deletion = a[i - 1][j] + 1;
      int match = a[i - 1][j - 1];
      int mismatch = a[i - 1][j - 1] + 1;
      if (str1[i - 1] == str2[j - 1])
        a[i][j] = min({insertion, deletion, match});
      else
        a[i][j] = min({insertion, deletion, mismatch});
    }
  }

  // Testing Output (Edit Distance Grid)
  // for (int j = 0; j <= str2.size(); j++)
  // {
  //   for (int i = 0; i <= str1.size(); i++)
  //   {
  //     cout << a[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  return a[str1.size()][str2.size()];
}

int main()
{
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
