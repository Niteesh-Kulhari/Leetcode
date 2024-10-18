class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";

        for(string s: strs){
            ans += to_string(s.length()) + "#" + s;
        }

        //cout << "The String is: " << ans << endl;

        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        
        int i = 0;

        while( i < s.length()){
            int j = s.find("#", i);
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            string temp = s.substr(i, length);
            ans.push_back(temp);
            i += length;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));