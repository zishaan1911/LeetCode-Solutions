class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> intMap;
        for (int i : nums) {
            if (intMap.find(i) != intMap.end()) intMap.erase(i);
            else intMap.insert(i);
        }
        vector<int> result;
        for (int i : intMap) {
            result.push_back(i);
        }
        return result;
    }
};