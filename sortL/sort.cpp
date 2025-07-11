#include <iostream>
#include <vector>
using namespace std;

class sortFunction
{
public:
  // if conv is True that should sort by desc
  // 冒泡，最简单的排序
  void bubbleSort(vector<int> &arr, bool conv = false)
  {
    if (!conv)
    {
      for (int i = 0; i < arr.size(); i++)
      {
        for (int j = i + 1; j < arr.size(); j++)
        {
          if (arr[j] < arr[i])
          {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
          }
        }
      }
    }
    else
    {
      for (int i = 0; i < arr.size(); i++)
      {
        for (int j = i + 1; j < arr.size(); j++)
        {
          if (arr[j] > arr[i])
          {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
          }
        }
      }
    }
  }

  // 分治思想，拆分数组
  void mergeSort(vector<int> &arr, bool conv = false)
  {
    _merge_sort_(arr, 0, arr.size() - 1, conv);
  }

private:
  void _merge_(vector<int> &arr, int left, int mid, int right, bool conv = false)
  {
    vector<int> temp;
    int l = left;
    int r = mid + 1;
    if (!conv)
    {
      while (l <= mid && r <= right)
      {
        if (arr[l] <= arr[r])
        {
          temp.push_back(arr[l]);
          l++;
        }
        else
        {
          temp.push_back(arr[r]);
          r++;
        }
      }
    }
    else
    {
      while (l <= mid && r <= right)
      {
        if (arr[l] >= arr[r])
        {
          temp.push_back(arr[l]);
          l++;
        }
        else
        {
          temp.push_back(arr[r]);
          r++;
        }
      }
    }
    while (l <= mid)
      temp.push_back(arr[l++]);
    while (r <= right)
      temp.push_back(arr[r++]);

    for (int i = 0; i < temp.size(); i++)
    {
      arr[left + i] = temp[i];
    }
  }
  void _merge_sort_(vector<int> &arr, int left, int right, bool conv = false)
  {
    if (left >= right)
    {
      return;
    }
    int mid = (left + right) / 2;
    _merge_sort_(arr, left, mid, conv);
    _merge_sort_(arr, mid + 1, right, conv);
    _merge_(arr, left, mid, right, conv);
  }
};

int main()
{
  vector<int> test = {5, 4, 8, 1, 9};
  sortFunction f;
  f.bubbleSort(test, true);
  cout << "bubble sort:";
  for (auto t : test)
  {
    cout << t << " ";
  }
  cout << endl;
  f.mergeSort(test,true);
  cout << "merge sort:";
  for (auto t : test)
  {
    cout << t << " ";
  }
  return 0;
}