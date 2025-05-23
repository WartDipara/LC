#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
// eg 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//    输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hash table用来记录，sort用来让字符顺序变得一致。
        unordered_map<string,vector<string>> dict;
        vector<vector<string>> ans;
        // 将string都加进字典里
        for(string str:strs){
          string key = str;
          sort(key.begin(),key.end());
          dict[key].push_back(key);
        }
        for(auto it=dict.begin();it!=dict.end();it++){
          ans.push_back(it->second);
        }
        return ans;
    }
};