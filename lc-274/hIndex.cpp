#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int> &citations)
{
  sort(citations.begin(), citations.end());
  int h = 0;
  int p = citations.size() - 1;
  while (p >= 0)
  {
    if (h < citations[p--])
    {
      h++;
    }
    else
      break;
  }
  return h;
}

int main()
{
  vector<int> test{3, 0, 6, 1, 5};
  cout << hIndex(test);
  return 0;
}