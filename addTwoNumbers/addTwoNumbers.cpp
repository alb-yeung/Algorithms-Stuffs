/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* currNode1 = l1;
        ListNode* currNode2 = l2;
        ListNode* ansHead = (ListNode*)malloc(sizeof(ListNode));
        ListNode* currAnsNode = ansHead;
        int carry = 0;
        while (currNode1 && currNode2){
            int placeSum = currNode1->val + currNode2->val + carry;
            carry = placeSum / 10;
            placeSum = placeSum % 10;
            currNode1 = currNode1->next;
            currNode2 = currNode2->next;
            ListNode* tmp = new ListNode(placeSum);
            currAnsNode->next = tmp;
            currAnsNode = currAnsNode->next;
        }
        while (currNode1){
            int placeSum = currNode1->val + carry;
            carry = placeSum / 10;
            placeSum = placeSum % 10;
            ListNode* tmp = new ListNode(placeSum);
            currAnsNode->next = tmp;
            currAnsNode = currAnsNode->next;
            currNode1 = currNode1->next;
        }
        while (currNode2){
            int placeSum = currNode2->val + carry;
            carry = placeSum / 10;
            placeSum = placeSum % 10;
            ListNode* tmp = new ListNode(placeSum);
            currAnsNode->next = tmp;
            currAnsNode = currAnsNode->next;
            currNode2 = currNode2->next;
        }
        if (carry)
            currAnsNode->next = new ListNode(1);
        return ansHead->next;
    }
};