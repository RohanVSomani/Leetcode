class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int dist = INT_MAX;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        queue<int> q;
        vector<int> vis(n+1,0);
        q.push(1);
        while(!q.empty()){
            int elem = q.front();
            q.pop();
            vis[elem]=1;
            for(auto road : adj[elem]){
                int dest = road.first;
                int d = road.second;
                dist = min(dist,d);
                if(vis[dest]==0)
                q.push(dest);
            }
        }
        return dist;
    }
};