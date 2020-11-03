// THE BASIC IDEA OF MERGE SORT ALGORITHM IS TO SORT AN ARRAY USING THE DIVIDE AND CONQUER TECHNIQUE. THE ARRAY IS DIVIDED
// INTO SUBPARTS USING A RECURSIVE ALGO AND THEN MERGED TO GIVE A SORTED ARRAY.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> &x, vector<int> &y);

// MERGE SORT ALGORITHM (TO DIVIDE ARRAY OR VECTOR INTO SUBDIVISIONS AND SORT USING DIVIDE AND CONQUER ALGO)
vector<int> merge_sort(vector<int> &b) {
  int n = b.size();
  if(n == 1)
    return b;
  int mid = n/2;
  vector<int> c, d;
  for(int i=0; i<mid; i++) {
    c.push_back(b[i]);
  }
  for(int i=mid; i<n; i++) {
    d.push_back(b[i]);
  }
  c = merge_sort(c);
  d = merge_sort(d);
  vector<int>merged = merge(c, d);
  return merged;
}


// MERGE ALGORITHM - TO MERGE BACK DIVIDED DATASETS (VECTORS OR ARRAYS)
vector<int> merge(vector<int> &x, vector<int> &y) {
  vector<int> s;
  while(x.size() != 0 && y.size() != 0) {
    vector<int>::iterator it1 = x.begin();
    vector<int>::iterator it2 = y.begin();
    if(x[0] < y[0]) {
      s.push_back(x[0]);
      x.erase(it1);
    }
    else {
      s.push_back(y[0]);
      y.erase(it2);
    }
  }
  s.insert(s.end(), x.begin(), x.end());
  s.insert(s.end(), y.begin(), y.end());
  return s;
}


int main()
{
  int n; // Enter size of array to be sorted
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < a.size(); ++i)
  {
    cin >> a[i]; // Input array elements
  }
  vector<int>b = merge_sort(a);
  for (int i = 0; i < b.size(); ++i)
  {
    cout << b[i] << " ";
  }  
}
