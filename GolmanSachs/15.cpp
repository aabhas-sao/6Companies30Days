class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int, int> mp;
        
        for (auto x: nums) {
            mp[(x % k + k) % k]++;
        }
        
        for (auto x: nums) {
            int rem = (x %k  + k) % k;
            if (rem == 0) {
                if (mp[rem] & 1) return false;
            } else {
                if (mp[rem] != mp[k - rem]) {
                    return false;
                }
            }
            
        }
        
        return true;
    }
};