class Solution {
public:
    long long mod = 1e9 + 7;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        n++;
        vector<int> adj[n];
        for(int i = 0; i < edges.size() ; i++){
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<long long> pow(n + 2, 0);
        pow[0] = 1;
        for(int i = 1; i <= n + 1; i++){
            pow[i] = (pow[i - 1] << 1)%mod;
        }
        vector<int> dis(n, -1);
        dis[0] = 0;
        queue<int> q;
        q.push(0);
        int maxi = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            maxi = max(maxi, dis[node]);
            for(auto it: adj[node]){
                if(dis[it] == -1){
                    dis[it] = dis[node] + 1;
                    q.push(it);
                }
            }
        }
        return pow[maxi - 1];
    }
};