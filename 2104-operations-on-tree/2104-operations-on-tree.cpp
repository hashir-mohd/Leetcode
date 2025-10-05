class LockingTree {
private:
    vector<int>lockStatus;
    vector<int>parent;
    vector<vector<int>> adj;

    void dfs(bool &upgradable, int num){
        if(lockStatus[num]!=-1){
            upgradable=true;
            lockStatus[num]=-1;
        }
        for(auto &it:adj[num]){
            
                dfs(upgradable,it);
            
        }
    }
public:
    LockingTree(vector<int>& parentt) {
        int n = parentt.size();
        parent=parentt;
        lockStatus.assign(n,-1);
        adj.resize(n);
        for(int i =1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(lockStatus[num]==-1){
            lockStatus[num]=user;
            return true;
        }
        return false;
        
    }
    
    bool unlock(int num, int user) {
        if(lockStatus[num]==user){
            lockStatus[num]=-1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        bool upgradable= false;
        if(lockStatus[num]!=-1){
            return false;
        }
        int temp=parent[num];
        while(temp!=-1){
            if(lockStatus[temp]!=-1){
                return false;
            }
            temp=parent[temp];
        }
        //checking locked descendent
        dfs(upgradable,num);
        if(upgradable){
            lockStatus[num]=user;
            return true;
        }
        return false;

    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */