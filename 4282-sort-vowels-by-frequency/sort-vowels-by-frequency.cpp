class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> vowels;
        unordered_map<char,int> firstPos;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
                vowels[c]++;
                if(firstPos.find(c) == firstPos.end())
                    firstPos[c] = i;
            }
        }
        vector<pair<char,int>> v;
        for(auto &it : vowels) {
            char c = it.first;
            int cnt = it.second;
            v.push_back({c,cnt});
        }
        sort(v.begin(), v.end(),
            [&](const auto& a, const auto& b) {
                if (a.second != b.second)
                    return a.second > b.second;

                return firstPos[a.first] < firstPos[b.first];
            });

        vector<char> ordered;
        for(auto &it : v) {
            int cnt = it.second;
            while(cnt--) {
                ordered.push_back(it.first);
            }
        }
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
                s[i] = ordered[j++];
            }
        }
        return s;
    }
};