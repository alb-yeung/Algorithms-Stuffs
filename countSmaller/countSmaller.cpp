/*  Runs in 28ms on leetcode
    Creates a BST to for cached less than count value when adding to right side.
    When adding to right side, don't need to traverse the left side to count because count already in node, and simply add 1 to count.
    When adding to left side, start at 0 for new node but add 1 to left side count to original node.
*/
class Solution {
public:
    /*
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> retVals = vector<int>();
        for (int i : nums){
            retVals.push_back(0);
        }
        size_t retIt = nums.size() - 2;
        bool found = false;
        for (size_t numsBack = retIt+1; numsBack >= 0; --numsBack){
            for (size_t findLessThan = numsBack + 1; findLessThan < nums.size() && !found; ++findLessThan){
                if (nums[findLessThan] < nums[numsBack]){
                    retVals[numsBack] = retVals[findLessThan] + 1;
                    found = true;
                }
            }
            found = false;
            retIt--;
        }
        return retVals;
    }
    */
    
    class Node{
    public:
        int val;
        int onLeft;
        Node* left;
        Node* right;
        Node(int n) : val(n), onLeft(0), left(0), right(0) {}
    };
    
    int insert(Node* node, int value, int numSmaller){
        if (value > node->val){
            numSmaller += node->onLeft + 1;
            if (node->right){
                return insert(node->right, value, numSmaller);
            }else{
                node->right = new Node(value);
                return numSmaller;
            }
        }else{
            ++node->onLeft;
            if (node->left){
                return insert(node->left, value, numSmaller);
            }else{
                node->left = new Node(value);
                return numSmaller;
            }
        }
    }
    
    vector<int> countSmaller(vector<int>& nums){
        if (nums.size() == 0){
            return vector<int>(0);
        }
        vector<int> retValues = vector<int>(nums.size());
        auto retValIt = retValues.rbegin();
        auto numsIt = nums.rbegin();
        Node * head = new Node(*numsIt);
        for (++numsIt; numsIt != nums.rend(); ++numsIt){
            ++retValIt;
            *retValIt = insert(head, *numsIt, 0);
        }
        return retValues;
    } 
    
};
