class RideSharingSystem {
public:
    queue<int>rider,driver;
    unordered_set<int>cancel;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        auto it = cancel.find(riderId);
        if(it != cancel.end()) cancel.erase(it);
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty() || driver.empty()) return {-1,-1};
        while(!rider.empty() && cancel.count(rider.front())){
            rider.pop();
        }
        if(rider.empty()) return {-1,-1};
        int r = rider.front();
        rider.pop();
        int d = driver.front();
        driver.pop();
        return {d,r};
    }
    
    void cancelRider(int riderId) {
        cancel.insert(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */