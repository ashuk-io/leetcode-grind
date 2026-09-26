class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;

        for(auto& list : knowledge) {
            m[list[0]] = list[1];
        }

        string key = "";
        string res = "";
        bool flag = false;

        for(char ch : s) {
            if(ch == '(') {
                flag = true;
            }
            else if(ch == ')') {
                if(m.find(key) != m.end()) {
                    res += m[key];
                }
                else {
                    res += "?";
                }

                flag = false;
                key = "";
            }
            else if(flag) {
                key += ch;
            }
            else {
                res += ch;
            }
        }
        return res;
    }
};