#include <bits/stdc++.h>
using namespace std;

class HashMap {
private:
    // The hash table is a vector of lists (chaining method)
    vector<list<pair<int, int>>> table;
    int size;

    // Hash function to map a key to an index
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor to initialize the hash map with a given size
    HashMap(int size) : size(size) {
        table.resize(size);
    }

    // Insert a key-value pair into the hash map
    void insert(int key, int value) {
        int index = hashFunction(key);
        // Check if the key already exists, update the value if it does
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // If the key doesn't exist, add a new pair to the list
        table[index].emplace_back(key, value);
    }

    // Get the value associated with a key
    int get(int key) {
        int index = hashFunction(key);
        // Search for the key in the list
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        // If the key is not found, return -1 or any sentinel value
        return -1;
    }

    // Remove a key-value pair from the hash map
    void remove(int key) {
        int index = hashFunction(key);
        // Find the key and remove the pair from the list
        table[index].remove_if([key](pair<int, int>& pair) {
            return pair.first == key;
        });
    }
};

int main() {
    HashMap hashMap(10);  // Initialize a hash map with 10 buckets

    // Insert key-value pairs
    hashMap.insert(1, 10);
    hashMap.insert(2, 20);
    hashMap.insert(3, 30);
    hashMap.insert(12, 40); // This will collide with key 2

    // Retrieve values
    cout << "Value for key 1: " << hashMap.get(1) << endl;
    cout << "Value for key 2: " << hashMap.get(2) << endl;
    cout << "Value for key 12: " << hashMap.get(12) << endl;

    // Remove a key-value pair
    hashMap.remove(2);
    cout << "Value for key 2 after removal: " << hashMap.get(2) << endl;

    return 0;
}