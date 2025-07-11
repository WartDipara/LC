#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int> &ratings)
{
  int n = ratings.size();
  vector<int> candies(n, 1);

  for (int i = 1; i < n; i++)
  {
    if (ratings[i] > ratings[i - 1])
    {
      candies[i] = candies[i - 1] + 1;
    }
  }
  for (int i = n - 2; i >= 0; i--)
  {
    if (ratings[i] > ratings[i + 1])
    {
      candies[i] = max(candies[i], candies[i + 1] + 1);
    }
  }
  for (int c : candies)
  {
    cout << c << " ";
  }
  cout << endl;
  int result = 0;
  for (int c : candies)
  {
    result += c;
  }
  return result;
}

int main()
{
  vector<int> ratings = {1, 2, 2};
  cout << candy(ratings) << endl;
  return 0;
}