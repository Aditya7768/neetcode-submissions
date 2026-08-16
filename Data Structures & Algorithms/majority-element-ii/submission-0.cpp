class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        
        vector<int> result;
        for (auto& p : freq) {
            if (p.second > n/3) {
                result.push_back(p.first);
            }
        }
        
        return result;
    }
};