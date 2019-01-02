class Solution {
public:
    /*  Works by mapping the pattern string and the words given into the same format and then comparing the two, if the formats are equal, then add the word to the return vector.
        There is another solution by not having to change everything into the same format and simply checking against each other with a map but I think having to check for uniqueness will make it have the same efficiency. 
        Runs in 4ms on leetcode
    */
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        /*  init process
            create a vector to return at the end
            placeholder for keeping track of how many unique chars there are
            replaceVals used to map unique chars in both pattern and words to same format
            newPattern used to map pattern to same format if not given in alphabetical order
        */
        vector<string> retVector = vector<string>();
        char placeholder = 'a';
        unordered_map<char, char> replaceVals = unordered_map<char, char>();
        /*  If the pattern given is always given in alphabetical order('aabbcc' and never 'ccbbaa') then this loop is not needed
        */
        string newPattern = "";
        for (char c : pattern){
            if (replaceVals.find(c) == replaceVals.end()){
                replaceVals[c] = placeholder;
                placeholder++;
            }
            newPattern += replaceVals[c];
        }
        /*  Changes the words into same format as the pattern string then checks for equality
        */
        string tempString;
        for (auto it = words.begin(); it != words.end(); it++){
            tempString = "";
            placeholder = 'a';
            replaceVals.clear();
            for (char c : *it){
                if (replaceVals.find(c) == replaceVals.end()){
                    replaceVals[c] = placeholder;
                    placeholder++;
                }
                tempString += replaceVals[c];
            }
            if (newPattern == tempString){
                retVector.push_back(*it);
            }
        }
        return retVector;
    }
};
