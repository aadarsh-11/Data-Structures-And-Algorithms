class Node
{
    public:
    Node* pre, *next;
    int val;
    int k;
    
    Node(int value)
    {
        val = value;
        next = NULL;
        pre = NULL;
    }
    
    Node(int value, Node* prev, Node* nxt)
    {
        pre = prev;
        next = nxt;
        val = value;
    }
};

class LRUCache {
public:
    int cap;
    int curr = 0;
    map<int,Node*> mp;
    Node* head,*tail;
        
    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
        head = new Node(0,NULL,NULL);
        tail = new Node(0,head, NULL);
        head->next = tail;
    }
    
    int get(int key) {
        if(mp[key])
        {
            Node* before = mp[key]->pre;
            Node* after = mp[key]->next;
            before->next = after;
            after->pre = before;
            after = head->next;
            head->next = mp[key];
            after->pre = mp[key];
            mp[key]->pre = head;
            mp[key]->next = after;
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp[key])
        {
            mp[key]->val = value;
            get(key);
            return;
        }
        if(curr == cap)
        {
            Node* rem = tail->pre;
            mp.erase(rem->k);
            tail->pre = rem->pre;
            rem->pre->next = tail;
        }
        else
        {
            curr++;
        }
        Node* after = head->next;
        Node* cur = new Node(value,head,after);
        cur->k = key;
        head->next = cur;
        after->pre = cur;
        mp[key] = cur;
        get(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */