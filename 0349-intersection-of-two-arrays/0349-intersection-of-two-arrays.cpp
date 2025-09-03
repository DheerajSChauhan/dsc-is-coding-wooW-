class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        map<int, int> map1;
        for (auto it : A) {
            map1[it]++;
        }
        map<int, int> map2;
        for (auto it : B) {
            map2[it]++;
        }
        vector<int> ans;
        for (auto it : map1) {
            if (map2.find(it.first) != map2.end()) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};