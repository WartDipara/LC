#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
*/
class Solution
{
public:
  vector<vector<string>> ans;
  vector<string> path;
  vector<bool> col;
  vector<bool> diag_1; //左上往右下的斜线
  vector<bool> diag_2; //右上往左下的斜线

  vector<vector<string>> solveNQueens(int n)
  {
    col = vector<bool>(n);
    diag_1 = diag_2 = vector<bool>(2*n);
    path = vector<string>(n,string(n,'.'));
    dfs(0,n);
  }
  void dfs(int x, int n){
    if(x == n){
        ans.push_back(path);
        return;
    }
    for(int y=0;y<n;y++){
      if(col[y] || diag_1[y-x+n] || diag_2[y+x])  
        continue;
      col[y]=diag_1[y-x+n]=diag_2[y+x]=true;
      path[x][y]='Q';
      dfs(x+1,n);
      //回溯
      col[y]=diag_1[y-x+n]=diag_2[y+x]=false;
      path[x][y]='.';
    }
  }
};