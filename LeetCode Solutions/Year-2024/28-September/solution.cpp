class MyCircularDeque {
public:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int x) : val(x), prev(nullptr), next(nullptr) {}
        Node(int x, Node* p, Node* n) : val(x), prev(p), next(n) {}
    };

    int size, limit;
    Node*front, *last;

    MyCircularDeque(int k) {
        size = 0, limit  = k;
        front = last = nullptr;
    }
    
    bool insertFront(int value) {
        if(size==limit)
            return false;
        if(size==0){
            front = last = new Node(value);
        }else{
            front = new Node(value, nullptr, front);
            front->next->prev = front;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==limit)
            return false;
        if(size==0){
            front = last = new Node(value);
        }else{
            last = new Node(value, last, nullptr);
            last->prev->next = last;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0)
            return false;
        if(size==1){
            front = last = nullptr;
        }else{
            front = front->next;
            front->prev = nullptr;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0)
            return false;
        if(size==1){
            front = last = nullptr;
        }else{
            last = last->prev;
            last->next = nullptr;
        }
        size--;
        return true;
    }
    
    int getFront() {
        if(!size)
            return -1;
        return front->val;
    }
    
    int getRear() {
        if(!size)
            return -1;
        return last->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==limit;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */