#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
1 1 1
1 0 1
1 1 1
 ↓
1 0 1
0 0 0
1 0 1
*/
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    bool rowZero, colZero; // 标记位，用来记录第一行第一列是不是一开始就有0
    rowZero = colZero = false;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
          if(i==0)
            rowZero=true;
          if(j==0)
            rowZero=true;
        }
      }
    }
    for(int i=1;i<m;i++){
      for(int j=1;j<n;j++){
        if(matrix[i][0]==0 || matrix[0][j]==0){
          matrix[i][j]=0;
        }
      }
    }
    for(int i=0;i<m && colZero ;i++) matrix[0][i]=0;
    for(int i=0;i<n && rowZero ;i++) matrix[i][0]=0;
  }
};