#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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


int get_majority_element(vector<int> &a, int left, int right)
{
  int mid = (a.size()-1)/2, count = 0;
  for(int i = left; i < mid ; i++)
    if(a[i] == a[mid])
      count++;
  for(int i = mid; i < right ; i++)
    if(a[i] == a[mid])
      count++;
  if(count > a.size()/2)
    return mid;
  return -1;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < a.size(); ++i)
  {
    cin >> a[i];
  }
  a = merge_sort(a);
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
