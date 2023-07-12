#include<bits/stdc++.h>
class LRUCache
{
public:
class node{
    public:int key;
    int val;
    node*next;
    node*prev;
    node(int _key,int _val){
        key = _key;
        val = _val;
 }
};
  node*head = new node(-1,-1);
  node*tail = new node(-1,-1);
  int cap;
  unordered_map<int,node*> mp;

    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
  void addnode(node* newnode){
      node*temp = head->next;
      newnode->next = temp;
      newnode->prev=head;
      head->next=newnode;
      temp->prev=newnode;
  }
  void deletenode(node* newnode){
    node*delnext = newnode->next;
    node*delprev = newnode->prev;
    delprev->next = delnext;
    delnext->prev = delprev;
  }
    int get(int key)
    {
        // Write your code here
        if(mp.find(key)!=mp.end()){
            node*res = mp[key];
            int value = res->val;
            mp.erase(key);
            deletenode(res);
            addnode(res);
            mp[key]=head->next;
            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key)!=mp.end()){
            node* res = mp[key];
            mp.erase(key);
            deletenode(res);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key] = head->next;
    }
};
