#include <queue>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Custom comparator to order the min-heap by node value
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        // Initialize the priority queue (Min-Heap)
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> minHeap(compare);
        
        // Push the head of each non-empty list into the heap
        for (ListNode* root : lists) {
            if (root != nullptr) {
                minHeap.push(root);
            }
        }
        
        // Dummy head node to simplify list building
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Process the heap until it's empty
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            // If the popped node has a next element, add it to the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};