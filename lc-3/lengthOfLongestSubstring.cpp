#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int ans = 0;
    int left, right;
    left = right = 0;
    unordered_map<char, int> cnt;
    while (right < s.size())
    {
      cnt[s[right]]++;
      while(cnt[s[right]]>1){
        cnt[s[left]]--;
        left++;
      }
      ans = max(ans,right-left+1);
      right++;
    }
    return ans;
  }
};

int main()
{
  string s;
  cin>> s;
  cout<<s<<endl;
  Solution test;
  cout<<"ans:"<<test.lengthOfLongestSubstring(s)<<endl;
}