/*
 * Problem: Merge k Sorted Lists
 * Link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3615/
 * Runtime: 328ms
 * Memory Usage: 13.8 MB
 * Time complexity: O(n*k)
 * Comments: This is a brute force solution hence very inefficient
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
  public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
      ListNode *newList = nullptr;
      if (lists.empty())
      {
        return newList;
      }
      newList = new ListNode();
      ListNode *head = newList;
      int lowest;
      bool isEnd = false;
      int k, i;
      while (!isEnd)
      {
        k = 0;
        i = 0;
        isEnd = true;
        lowest = INT_MAX;
        for (ListNode* listNode : lists)
        {
          if (listNode != nullptr)
          {
            isEnd = false;
            if (listNode->val < lowest)
            {
              lowest = listNode->val;
              i = k;
            }
          }
          k++;
        }
        if (isEnd)
        {
          continue;
        }
        newList->next = new ListNode(lowest);
        newList = newList->next;

        // Delete the node from kth list once its been added
        ListNode *temp = lists[i];
        lists[i] = lists[i]->next;
        delete temp;
      }
      // Delete extra node created in the starting
      ListNode *temp = head;
      head = head->next;
      delete temp;

      return head;
    }
};
