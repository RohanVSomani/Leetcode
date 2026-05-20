class Solution {
public:
    int nthUglyNumber(int n) {
       priority_queue<long,vector<long>,greater<long>> heap;
       vector<long> pri={2,3,5};
       unordered_set<long> done;
       heap.push(1);
       done.insert(1);
       long now;
       for(int i=0;i<n;i++){
            now = heap.top();
            heap.pop();
            for(long p:pri){
                if(done.find(now*p)==done.end()){
                    heap.push(now*p);
                    done.insert(now*p);
                }
            }
       }
       return (int)now;
    }
};