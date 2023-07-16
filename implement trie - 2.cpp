#include <bits/stdc++.h> 
struct Node{
    Node*links[26];
    int cp = 0, ew=0;
    bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
    Node*get (char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node*node){
        links[ch-'a'] = node;
    }
    void increaseend(){
        ew++;
    }
    void incpref(){
        cp++;
    }
    void decend(){
        ew--;
    }
    void decpref(){
        cp--;
    }
    int getend(){
        return ew;
    }
    int getpref(){
        return  cp;
    }
};
class Trie{
 private: Node*root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        	Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
            node->incpref();
		}
        node->increaseend();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        	Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (node->containKey(word[i])) {
				node = node->get(word[i]);
			}
			else return 0;
		}
    return node->getend();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (node->containKey(word[i])) {
				node = node->get(word[i]);
			}
			else return 0;
		}
    return node->getpref();
    }

    void erase(string &word){
        // Write your code here.
        Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (node->containKey(word[i])) {
				node = node->get(word[i]);
                node->decpref();
			}
			else return;
		}
    node->decend();
    }
};
