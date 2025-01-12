class TrieNode{
public:
    bool flag;
    TrieNode* children[26];

    TrieNode() {
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        flag = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c: word){
            int index = (c - 'a');
            if(curr->children[index] == NULL){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->flag = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(string word, int index, TrieNode* root){
        TrieNode* curr = root;
        for(int i=index; i<word.length(); i++){
            char c = word[i];
            int index = (c - 'a');
            if(c == '.'){
                for(TrieNode* child: curr->children){
                    if(child != NULL && dfs(word, i+1, child)){
                        return true;
                    }
                }
                return false;
            }else{
                if(curr->children[index] == NULL){
                    return false;
                }
                curr = curr->children[index];
            }
        }

        return curr->flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */