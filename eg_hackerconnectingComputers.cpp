/*
 * There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
 * You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
 * Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
 * DFS - Depth First Search
 */

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    
    void dfs(vector<int>graph[],vector<int>&vis,int node){
        vis[node]=1;
        
        for(auto nbr:graph[node]){
            if(!vis[nbr]){
                dfs(graph,vis,nbr);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& v) {
        int e=v.size();  
        if(e<n-1){return -1;}  // If  number of edges(cables) is less than the number of (nodes -1) then we cannot connect all the pcs. Hence , return -1;
        
        vector<int>graph[n];
        vector<int>vis(n,0);
        
        for(int i=0;i<e;i++){
            graph[v[i][0]].push_back(v[i][1]);
            graph[v[i][1]].push_back(v[i][0]);
        }

        for(auto x : graph)
        {
            for(auto y : x)
                cout << y << " ";
            cout << endl;
        }

        
        int cnt=0;  // To count number of connected components
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,vis,i);
                cnt++;
            }
            
        }
        
        return cnt-1;
    }
};

int main()
{
    //vector<vector<int>> network = {{0,1},{0,2},{0,3},{1,2},{1,3}}; int nodes = 6;
    vector<vector<int>> network = {{0,1},{0,2},{1,3}}; int nodes = 4;
    Solution s;
    cout << " Minimum cable extractions = "<< s.makeConnected(nodes, network) << endl;
    return 0;
}