class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store sorted string as key and original strings as values
        unordered_map<string, vector<string>> anagramMap;
        
        for (string s : strs) {
            string sortedS = s;
            // Sort the string to create the "key"
            sort(sortedS.begin(), sortedS.end());
            
            // Push the original string into the corresponding bucket
            anagramMap[sortedS].push_back(s);
        }
        
        // Prepare the final result
        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};