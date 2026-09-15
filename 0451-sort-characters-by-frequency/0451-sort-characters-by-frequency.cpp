class Solution {
public:
    string frequencySort(string s) {
        
        // Count freq
        unordered_map<char, int> freq;
        for(char ch:s)
        {
            freq[ch]++;
        }
        
        string ans = "";

        // keep proecessing until map gets empty
        while(!freq.empty())
        {
            char maxchar;
            int maxFreq = 0;

            // find char with max freq
            for(auto it:freq)
            {
                if(it.second > maxFreq){
                    maxFreq = it.second;
                    maxchar = it.first;
                }
            }
            // Add char in max freq
            ans += string(maxFreq,maxchar);

            // remove processed char
            freq.erase(maxchar);
        } 


return ans;
    }
};