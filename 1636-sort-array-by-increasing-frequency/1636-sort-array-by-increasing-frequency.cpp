class Solution {
public:
    using pii = pair<int, int>;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>mp;
        for( auto num : nums){
            mp[num]++;
        }
        priority_queue<pii, vector<pii>, greater<pii>>minh;
        for( auto it : mp){
            minh.push({it.second, -it.first});
        }
        vector<int>result;
        while(!minh.empty()){
            int freq = minh.top().first;
            int val = -minh.top().second;
            minh.pop();
            while(freq--){
                result.push_back(val);
            }
        }
        return result;
    }
};