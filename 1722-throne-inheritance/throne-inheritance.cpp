class ThroneInheritance {
public:
  
    unordered_map<string, vector<string>>mp;
    unordered_set<string>dead;
    string nameOfKing;

    ThroneInheritance(string kingName) {
        nameOfKing=kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }

    void dfs(string parent, vector<string>&ans){
        if(dead.count(parent)==0) ans.push_back(parent);
        for(auto child : mp[parent]) dfs(child,ans);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(nameOfKing, ans);
        return ans;

    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */