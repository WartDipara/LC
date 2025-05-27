#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4

*/

// 维护一个链表，最近被使用的就移动去头，利用链表插入O（1）的优势。
class LRUcache
{
  class Node
  {
  public:
    int key, val;
    Node *prev, *next;
    Node() : key(0), val(0), prev(nullptr), next(nullptr) {};
    Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {};
  };
  int _size;
  int _capacity;
  unordered_map<int, Node *> _cache;
  Node *head;
  Node *tail;

public:
  LRUcache(int capacity) : _capacity(capacity), _size(0)
  {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }
  int get(int key)
  {
    if (!_cache.count(key))
    {
      // 找不到
      return -1;
    }
    else
    {
      // 找到了
      // 返回结果同时把他放到链表头
      Node *node = _cache[key];
      _moveToHead_(node);
      return node->val;
    }
  }

  void put(int key, int val)
  {
    if (_cache.count(key))
    {
      // 找到了
      Node *node = _cache[key];
      node->val = val;
      _moveToHead_(node);
    }
    else
    {
      // 没找到
      Node *node = new Node(key, val);
      _cache[key] = node;
      _addToHead_(node);
      _size++;
      if (_size > _capacity)
      {
        // 超出容量，开始LRU
        Node *removedNode = _removeTail_();
        _cache.erase(removedNode->key);
        delete removedNode;
        _size--;
      }
    }
  }

private:
  void _addToHead_(Node *node)
  {
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    node->prev = head;
  }

  void _removeNode_(Node *node)
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  void _moveToHead_(Node *node)
  {
    _removeNode_(node);
    _addToHead_(node);
  }
  Node *_removeTail_()
  {
    Node *node = tail->prev;
    _removeNode_(node);
    return node;
  }
};

int main() {
    vector<string> ops = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    vector<vector<int>> params = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};
    vector<string> output;
    
    LRUcache* lru = nullptr;
    
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == "LRUCache") {
            lru = new LRUcache(params[i][0]);
            output.push_back("null");
        } else if (ops[i] == "put") {
            lru->put(params[i][0], params[i][1]);
            output.push_back("null");
        } else if (ops[i] == "get") {
            int result = lru->get(params[i][0]);
            output.push_back(to_string(result));
        }
    }
    
    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i < output.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}