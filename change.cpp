#include <iostream>

using namespace std;

int get_change(int m) {
  int n = (m/10) + (m%10)/5 + (m%5);
  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
