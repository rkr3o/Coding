#include <bits/stdc++.h>
using namespace std;

class DSU
{
   vector<int> rank, parent;

public:
   // make function
   DSU(int n)
   {
      rank.resize(n + 1, 0);
      parent.resize(n + 1);
      for (int i = 0; i < n; i++)
      {
         parent[i] = i;
      }
   }
   // path compression
   int find(int node)
   {
      if (node == parent[node])
      {
         return node;
      }

      return parent[node] = find(parent[node]);
   }
   // union by rank

   void Union(int u, int v)
   {
      u = find(u);
      v = find(v);

      if (u != v)
      {
         if (rank[u] < rank[v])
         {
            swap(u, v);
         }
      }
      parent[v] = u;
      if (rank[u] == rank[v])
      {
         rank[u]++;
      }
   }
};
int main()
{

   DSU ds(7);
   ds.Union(1, 2);
   ds.Union(2, 3);
   ds.Union(4, 5);
   ds.Union(6, 7);
   ds.Union(5, 6);

   if (ds.find(3) == ds.find(7))
   {
      cout << "YES" << endl;
   }
   else
   {
      cout << "NO" << endl;
   }

   ds.Union(3, 7);

   if (ds.find(3) == ds.find(7))
   {
      cout << "YES" << endl;
   }
   else
   {
      cout << "NO" << endl;
   }
   return 0;
}