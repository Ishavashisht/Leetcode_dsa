class Trie {
public:
    class TrieNode {
    public:
        char value;
        bool isTerminal;
        TrieNode* children[26];

        TrieNode(char val) {
            value = val;
            isTerminal = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    // Constructor for the Trie
    Trie() {
        root = new TrieNode('\0'); // Root node with null character
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode(ch);
            }
            current = current->children[index];
        }
        current->isTerminal = true; // Mark the end of the word
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false; // Character not found
            }
            current = current->children[index];
        }
        return current->isTerminal; // Check if it's a terminal node
    }

    // Check if any word starts with a given prefix
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false; // Prefix not found
            }
            current = current->children[index];
        }
        return true; // Prefix exists
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */