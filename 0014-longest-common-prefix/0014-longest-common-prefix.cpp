class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
    // when input case is emptyy
    if(strs.empty()) return "";

    // sort the string lexicographically
    sort(strs.begin(),strs.end());

    // first string in sorted order
    string first = strs[0];

    // last string in sorted order
    string last = strs[strs.size()-1];

    // to store common prefix
    string ans ="";

    // compare which shorter string
    int minLength = min(first.size(),last.size());

    // compare charachters of first and last string
    for(int i = 0; i < minLength;i++)
    {
        if(first[i] != last[i]) break;
        ans += first[i];
    }
    return ans;


    }
};