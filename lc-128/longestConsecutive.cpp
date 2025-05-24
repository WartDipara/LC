#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
解释:[0,0,1,2,3,4,5,6,7,8] ,不考虑重复的
*/

 // 最快的排序算法都是nlogn，因此不考虑先排序再搜索
 // 打表，使用哈希法存入，然后遍历搜索

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> dict(nums.begin(),nums.end());
      //找两个点，如果当前值的前一位不存在，则必然当前位置的数是起点，往后遍历即可。
      //如果存在，那必然它是中间的结果，那么该数列就不可能是最长，直接跳过。
      int ans = 0;
      for(auto i : dict){
        if(!dict.count(i-1)){
          //上一个点不存在，开始找
          int x=i+1;
          while(dict.count(x)) x++;
          ans = max(ans,x-i);
        }
      }
      return ans;
    }
};