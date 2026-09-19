class Solution {
public:
    string frequencySort(string s) {

        // 1. Count frequency
        unordered_map<char, int> freq;

        for(char ch : s) {
            freq[ch]++;
        }

        // 2. Create buckets
        vector<vector<char>> bucket(s.size() + 1);

        // 3. Put each character in its frequency bucket
        for(auto it : freq) {
            char ch = it.first;
            int count = it.second;

            bucket[count].push_back(ch);
        }

        // 4. Build answer from highest frequency to lowest
        string ans = "";

        for(int i = s.size(); i >= 1; i--) {

            for(char ch : bucket[i]) {
                ans += string(i, ch);
            }
        }

        return ans;
    }
};