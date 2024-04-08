// https://leetcode.cn/problems/intersection-of-two-linked-lists/submissions/517704062/
// https://r07na4yqwor.feishu.cn/docx/L08BdumO8ouSDSxlLDCcMTYmnwd
#include "../leetcode.h"

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};