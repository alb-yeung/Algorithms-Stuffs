#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int max = 0;
        int lastReset = -1;
        std::unordered_map<char, int> lastPlaces = std::unordered_map<char, int>();
        for (int i = 0; i < s.length(); i++){
            lastPlaces[s[i]] = -1;
        }
        for (int i = 0; i < s.length() + 1; i++){
            if (i == s.length()){
                if (lastReset == -1) lastReset = 0;
                int curr = i - lastReset;
                if (curr > max){
                    max = curr;
                }
            }
            if (lastPlaces[s[i]] > -1){
                if (lastReset == -1) lastReset = 0;
                int curr = i - lastReset;
                if (curr > max){
                    max = curr;
                }
                if (lastPlaces[s[i]] + 1 > lastReset) lastReset = lastPlaces[s[i]] + 1;
                lastPlaces[s[i]] = i;
            }else{
                lastPlaces[s[i]] = i;
                int curr = i - lastReset;
                if (curr > max) {
                    max = curr;
                }
            }
        }
        return max;
    }
};