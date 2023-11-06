class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
       for(int i=1;i<=n;i++){
           pq.push(i);
       } 
    }    
    int reserve() {
        if(pq.size()==0){
            return -1;
        }
        int num=pq.top(); 
        pq.pop();  
        return num;
    }
    void unreserve(int seatnumber) {
        pq.push(seatnumber);
    }
};
