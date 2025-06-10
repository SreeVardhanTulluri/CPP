#include <iostream>
#include <vector>

using namespace std;
class MyHashSet {
public:
    vector<int> set;
    MyHashSet() {
    }
    
    void add(int key) {
    if(contains(key) == false){
        set.push_back(key);
    }
    }
    
    void remove(int key) {
        if (contains(key)){
            set.erase(set.begin()+find(key));
        }
    }
    
    bool contains(int key) {
        return (find(key) > -1);    //bug : initially 0 -> true even if key in 1st pos
    }
private:
    int find(int key){
        for(int i = 0 ; i < set.size(); i++){   //bug : sizeof method fails to work
            if(set[i] == key){
                return i;
            }
        }
        return -1;
    }
};