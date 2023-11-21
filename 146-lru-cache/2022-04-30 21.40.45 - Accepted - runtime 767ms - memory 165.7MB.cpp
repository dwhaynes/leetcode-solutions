class LRUCache {
    struct Node {
        int key;
        int value;
        Node *prev = nullptr, *next = nullptr;
    };
    
    void addNode(Node* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void moveToHead(Node* node){
        removeNode(node);
        addNode(node);
    }
    
    Node* popTail(){
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }
    
    map<int,Node*> cache;
    int size;
    int capacity;
    Node *head = nullptr, *tail = nullptr;
public:
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        Node* node = cache[key];
        if (!node) return -1;
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        Node* node = cache[key];
        if(!node){
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value = value;
            cache[key] = newNode;
            addNode(newNode);
            size++;
            if(size > capacity){
                Node* tail = popTail();
                cache.erase(tail->key);
                size--;
            }
        } else {
            node->value = value;
            moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */