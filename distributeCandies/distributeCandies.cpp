#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    
    /* ran in 272ms on leetcode submission*/
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        size_t count = 1;
        auto it = candies.begin();
        for(it++; it != candies.end(); it++){
            if (*it > *(it - 1)){
                count++;
            }
        }
        return min(count, candies.size()/2);
    }
    
    /* ran in 264ms on leetcode submission*/
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> UniqueCandies = unordered_set<int>();
        for (int candy : candies){
            UniqueCandies.insert(candy);
        }
        return min(UniqueCandies.size(), candies.size()/2);
    }
    
};
