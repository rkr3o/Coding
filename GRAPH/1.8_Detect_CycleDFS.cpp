     #include<bits/stdc++.h>
     using namespace std ;
     #define ll long long int 
     const int  mod = 1e9+7 ;
     const int N = 1e3+10;
     
   bool dfs(int src , int parent ,  int vis[] , vector<int>adj[])
     {
                 
                vis[src] =1 ;
                
                for(auto child : adj[src])
                {
                	if(!vis[child])
                	{
                		 if(dfs(child , src , vis , adj)==true)
                		 {
                		 	 return true ; 
                		 }
                	}else if (parent !=child)
                	{
                		 return false ; 
                	}
                }
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
             	  if(dfs(i , -1, vis , adj)==true) 
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