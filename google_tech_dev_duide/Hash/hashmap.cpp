#include <vector>

class MyHashMap {
public:

    std::vector<int> keys,values;
    MyHashMap() {
    }
    
    void put(int key, int value) {
        int key_index = find(key);
        if (key_index > -1){ values[key_index] = value;return;}
        keys.push_back(key);
        values.push_back(value);
    }
    
    int get(int key) {
        key = find(key);
        if (key > -1)  return values[key];
        return key;
        
    }
    
    void remove(int key) {
        int key_index = find(key);
        if(key_index > -1){
            keys.erase(keys.begin() + key_index);
            values.erase(values.begin() + key_index);   //bug : need to check iterators carefully
        }   
    }
private:
    int find(int key){
        for (int i = 0; i < keys.size() ; i++){ if (keys[i] == key){ return i;} }
        return -1;
    }
};

int main(){
    MyHashMap* obj = new MyHashMap();
    obj->put(1,1);
    obj->put(2,2);
    int param_2 = obj->get(1);
    int param_3 = obj->get(3);
    obj->put(2,1);
    int param_4 = obj->get(2);
    obj->remove(2);
    int param_5 = obj->get(2);
}
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */