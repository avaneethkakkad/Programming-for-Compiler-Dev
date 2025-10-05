// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // Non negative weights use dijkstra algorithm 
        //priority queue min heap
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e:edges){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(V,INT_MAX);
        
        //from 2 to 2 dis
        result[src]=0;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &vec:adj[node])
            {
                int adjNode = vec.first;
                int wt = vec.second;
                
                if(d+wt<result[adjNode])
                {
                    result[adjNode]=d+wt;
                    pq.push({d+wt,adjNode});
                    
                }
            }
        }
        return result;
        
        
    }
};
