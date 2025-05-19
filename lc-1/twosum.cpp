#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> ht;
      for(int i=0;i<nums.size();i++){
        ht[nums[i]]=i;
      }
      for(int j=0;j<nums.size();j++){
        if(ht.find(target-nums[j])!=ht.end() && ht[target-nums[j]]!=j){
          return {j,ht[target-nums[j]]};
        }
      }
      return {};
    }
};

int main() {
    int k;
    cin >> k;
    vector<int> nums(k);
    for(int i = 0; i < k; i++) {
        cin >> nums[i]; 
    }
    int target;
    cin >> target;
    Solution s;
    vector<int> ans = s.twoSum(nums, target);
    for(auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}