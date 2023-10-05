// Appraoch-01 Straight Forward using a large array to store the key values  
class MyHashMap {
public: 
    int size;
    vector<int> ans;
    MyHashMap() {
        size=1e6+1;
        ans.resize(size,-1);        
    }    
    void put(int key, int value) {
        ans[key]=value;
    }    
    int get(int key) {
        return ans[key];        
    }    
    void remove(int key) {
        ans[key]=-1;        
    }
};



// Approach -02 Better And Optimal
class MyHashMap {
public:
    vector<list<pair<int,int>>>buckets;
    int size;
    MyHashMap() {
        size=100000;
        buckets.resize(size);
    }    
    void put(int key, int value) {
        int index=key%size;
        auto &chain=buckets[index];

        for(auto &it:chain){
            if(it.first==key){
                it.second=value;
                return;
            }
        } 
        chain.emplace_back(key,value);       
    }
    int get(int key) {
        int index=key%size;
        auto &chain=buckets[index];
        if(chain.empty()){
            return -1;
        }
        for(auto &it:chain){
            if(it.first==key){
                return it.second;
            }
        }
    return -1;        
    }
    void remove(int key) {
        int index=key%size;
        auto &chain=buckets[index];
        for(auto it=chain.begin();it!=chain.end();it++){
            if(it->first==key){
                chain.erase(it);
                return;
            }
        }        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
