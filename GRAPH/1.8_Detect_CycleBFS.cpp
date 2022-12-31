     #include<bits/stdc++.h>
     using namespace std ;
     #define ll long long int 
     const int  mod = 1e9+7 ;
     const int N = 1e3+10;
     
   bool bfs(int src , int vis[] , vector<int>adj[])
     {
                 
                vis[src] =1 ;
                queue<pair<int,int>>q ;
                q.push({src,-1});

                while(!q.empty())
                {
                	int cur = q.front().first;
                	int parent = q.front().second;
                	q.pop();

                	for(auto child : adj[cur])
                	{
                		 if(!vis[child])
                		 {
                		 	 q.push({child , cur});
                		 	 vis[child] =1 ;
                		 }
	                	 else if (child!=parent)
	                	 {
	                	 	 return true ;
	                	 }
                	}
                }
                return false ;
     }
     int main()
     {
     	int n , m ;
     	cin >> n >>  m ;
        vector<int>adj[n+1];
        for(int i = 0 ; i < n ; i++)
        {
        	int u , v ;
        	cin >> u >> v; //

        	adj[u].push_back(v);
        	adj[v].push_back(u);
        }
        
        int vis[n]={0};

        for(int i = 0 ; i < n ; i++)
        {
             if(!vis[i])
             {
             	  if(bfs(i , vis , adj)==true) 
             	  {
             	  	cout<<"YES"<<endl;
             	  	return 0 ;
             	  }
             }
              cout<<"NO"<<endl;
              return 0 ;
        }

       
        
     	return 0 ;
     }