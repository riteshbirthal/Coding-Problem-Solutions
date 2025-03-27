// design the class in the most optimal way

class LRUCache {
    private:
    int capacity, pri;
    unordered_map<int, int> cache, keyPriority, priorityKey;
    set<int> priority;
    public:
      // Constructor for initializing the cache capacity with the given value.
      LRUCache(int cap) {
          // code here
          capacity = cap;
          pri = 1;
      }
  
      // Function to return value corresponding to the key.
      int get(int key) {
          // your code here
          if(cache.find(key)!=cache.end()){
              // previous priority of the key
              int prePri = keyPriority[key];
              // erased the previous priority from currently stored priorities
              priority.erase(prePri);
              // updated the key priority to latest priority
              keyPriority[key] = pri;
              // inserted the new priority
              priority.insert(pri);
              // mapping the latest priority to the key
              priorityKey[pri] = key;
              // erasing the previously mapped priority to the key
              priorityKey.erase(prePri);
              // updating the priority value
              pri += 1;
              return cache[key];
          }
          return -1;
      }
  
      // Function for storing key-value pair.
      void put(int key, int value) {
          // your code here
          if(cache.find(key)!=cache.end()){
              int prePri = keyPriority[key];
              priority.erase(prePri);
              priorityKey.erase(prePri);
          }else{
              if(capacity==0){
                  int leastPri = *priority.begin();
                  priority.erase(leastPri);
                  cache.erase(priorityKey[leastPri]);
                  priorityKey.erase(leastPri);
              }else{
                  capacity--;
              }
          }
          keyPriority[key] = pri;
          priority.insert(pri);
          priorityKey[pri] = key;
          pri += 1;
          cache[key] = value;
      }
  };