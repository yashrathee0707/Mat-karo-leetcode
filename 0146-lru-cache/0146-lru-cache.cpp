class LRUCache {
  public:
    // Node structure for the doubly linked list
    class node {
      public:
        int key;  // Key of the node
        int val;  // Value of the node
        node * next;  // Pointer to the next node
        node * prev;  // Pointer to the previous node
        
        // Constructor to initialize a node with a given key-value pair
        node(int _key, int _val) {
          key = _key;
          val = _val;
        }
    };

    // Pseudo head and tail nodes to facilitate easy addition and deletion
    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);

    int cap;  // Capacity of the LRU Cache
    unordered_map < int, node * > m;  // Hash map to store key-node pairs for O(1) access

    // Constructor to initialize the LRU cache with a given capacity
    LRUCache(int capacity) {
      cap = capacity;
      head -> next = tail;  // Head initially points to tail
      tail -> prev = head;  // Tail initially points to head
    }

    // Function to add a node right after the head (most recently used position)
    void addnode(node * newnode) {
      node * temp = head -> next;  // Store the node next to head
      newnode -> next = temp;  // Point new node's next to temp
      newnode -> prev = head;  // Point new node's prev to head
      head -> next = newnode;  // Update head's next to new node
      temp -> prev = newnode;  // Update temp's previous to new node
    }

    // Function to delete a given node from the doubly linked list
    void deletenode(node * delnode) {
      node * delprev = delnode -> prev;  // Get previous node
      node * delnext = delnode -> next;  // Get next node
      delprev -> next = delnext;  // Link previous node to next node
      delnext -> prev = delprev;  // Link next node to previous node
    }

    // Function to get the value of a key from the cache
    int get(int key_) {
      if (m.find(key_) != m.end()) {  // If key exists in cache
        node * resnode = m[key_];  // Get the corresponding node
        int res = resnode -> val;  // Store its value
        m.erase(key_);  // Remove key from the hash map
        deletenode(resnode);  // Remove node from linked list
        addnode(resnode);  // Move node to front (most recently used)
        m[key_] = head -> next;  // Update the hash map with the new position
        return res;  // Return the value
      }
      return -1;  // If key is not found, return -1
    }

    // Function to put a key-value pair into the cache
    void put(int key_, int value) {
      if (m.find(key_) != m.end()) {  // If key already exists
        node * existingnode = m[key_];  // Get the existing node
        m.erase(key_);  // Remove it from the hash map
        deletenode(existingnode);  // Remove it from the linked list
      }
      
      if (m.size() == cap) {  // If cache is full
        m.erase(tail -> prev -> key);  // Remove the least recently used key from the map
        deletenode(tail -> prev);  // Remove the least recently used node from linked list
      }

      addnode(new node(key_, value));  // Add the new node to the front (most recently used)
      m[key_] = head -> next;  // Update the hash map with the new node
    }
};
