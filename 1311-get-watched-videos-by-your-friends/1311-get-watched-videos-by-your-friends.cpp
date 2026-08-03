class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends,
                                          int id,
                                          int level) {

        int n = friends.size();

        // Queue for BFS
        queue<int> q;

        // Visited array to avoid visiting same person multiple times
        vector<bool> visited(n, false);

        q.push(id);
        visited[id] = true;

        int currentLevel = 0;

        // BFS till we reach the required level
        while (!q.empty() && currentLevel < level) {

            int sz = q.size();   // Number of nodes at current level

            while (sz--) {

                int person = q.front();
                q.pop();

                // Visit all friends of current person
                for (int fr : friends[person]) {

                    if (!visited[fr]) {
                        visited[fr] = true;
                        q.push(fr);
                    }
                }
            }

            // Finished one complete level
            currentLevel++;
        }

        // Count frequency of videos watched by people at required level
        unordered_map<string, int> freq;

        while (!q.empty()) {

            int person = q.front();
            q.pop();

            for (string &video : watchedVideos[person]) {
                freq[video]++;
            }
        }

        // Convert map into vector for sorting
        vector<pair<string, int>> videos;

        for (auto &it : freq) {
            videos.push_back(it);
        }

        // Sort:
        // 1. Frequency (ascending)
        // 2. Lexicographical order if frequency is same
        sort(videos.begin(), videos.end(),
             [](pair<string, int> &a, pair<string, int> &b) {

                 if (a.second == b.second)
                     return a.first < b.first;

                 return a.second < b.second;
             });

        // Prepare answer
        vector<string> ans;

        for (auto &it : videos)
            ans.push_back(it.first);

        return ans;
    }
};