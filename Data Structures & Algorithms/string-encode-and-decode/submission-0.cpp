class Solution {
public:
    string encode(vector<string>& strs) {
        string temp = "";

        // Store as: length#string
        for (string str : strs) {
            temp += to_string(str.size());
            temp += '#';
            temp += str;
        }

        int n = temp.size();

        // Empty vector case
        if (n == 0) {
            return "";
        }

        string enString(n, '\0');
        int shift = n - 1;

        for (int i = 0; i < n; i++) {
            int newI = (i + shift) % n;
            enString[newI] = temp[i];
        }

        return enString;
    }

    vector<string> decode(string s) {
        int n = s.size();

        // Empty string case
        if (n == 0) {
            return {};
        }

        int shift = n - 1;
        string deString(n, '\0');

        // Undo the shift
        for (int i = 0; i < n; i++) {
            int newI = ((i - shift) % n + n) % n;
            deString[newI] = s[i];
        }

        vector<string> ans;
        int i = 0;

        while (i < n) {
            // Read the length
            string len = "";
            while (deString[i] != '#') {
                len += deString[i];
                i++;
            }

            int k = stoi(len);
            i++; // Skip '#'

            // Read the next k characters
            string word = "";
            for (int j = 0; j < k; j++) {
                word += deString[i];
                i++;
            }

            ans.push_back(word);
        }

        return ans;
    }
};