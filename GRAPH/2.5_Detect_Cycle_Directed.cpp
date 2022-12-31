     #include<bits/stdc++.h>
     using namespace std ;
     #define ll long long int 
     const int  mod = 1e9+7 ;
     
      bool dfs(int src , vector<int>&vis , vector<int>&pathVis , vector<int>adj[])
      {
            vis[src]=1;
            pathVis[src]=1;

            for(auto child : adj[src])
            {
               if(!vis[child])
               {
                     if(dfs(child , vis,pathVis , adj)==true)
                     {
                        return true;
                     }
               }
               else if(pathVis[child])
               {
                  return true;
               }
            }

            pathVis[src]=0;
            return false;
      }
     int main()
     {
        int n , m ;
        cin >> n >> m ;
        vector<int>adj[n];
        for(int i = 0 ; i < m ; i++)
        {
              int  u , v ;
              cin >> u >> v; 
              adj[u].push_back(v);
              adj[v].push_back(u);
        }

        vector<int>vis(n,0);
        vector<int>pathVis(n,0);

        for (int i = 0; i < n; ++i)
        {
            if(!vis[i])
            {
                if(dfs(i , vis , pathVis , adj)==true)
                {
                    cout<<"True"<<endl;
                    return 0 ;
                }
            }
        }

        cout<<"False"<<endl;

        return 0 ;
     }