#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
  int totalGas = 0;
  int totalCost = 0;
  for (auto g : gas)
    totalGas += g;
  for (auto c : cost)
    totalCost += c;

  if (totalGas < totalCost)
    return -1;

  int currentGas = 0;
  int start = 0;
  for (int i = 0; i < gas.size(); i++)
  {
    currentGas += gas[i] - cost[i];
    if (currentGas < 0)
    {
      // i,.....,j,j+1 如果j+1无法到达，则i和j之间任意一点都无法到达，直接从j+1开始找
      currentGas = 0;
      start = i + 1;
    }
  }
  return start;
}

int main()
{
  vector<int> gas{1, 2, 3, 4, 5}, cost{3, 4, 5, 1, 2};
  cout << canCompleteCircuit(gas, cost);
  return 0;
}