#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int  mod = 1e9 + 7 ;


int main()
{
   vector<vector<int>>mat(5, vector<int>(4));

   int dp[5][4];
   for (int i = 0; i <= 4; ++i)
   {
      for (int j = 0 ; j <= 3 ; j++)
      {
         if (i == 0 and j == 3)
         {
            dp[i][j] = mat[i][j];
         }
         else if (i == 0)
         {
            dp[i][j] = mat[i][j] + dp[i][j - 1];
         }
         else if (j == 0)
         {
            dp[i][j] = mat[i][j] + dp[i - 1][j];
         }
         else {
            dp[i][j] = mat[i][j] + max(dp[i][j - 1], dp[i - 1][j]);
         }
      }
   }


   int dp2[5][4];
   int  r = 5;
   int c = 4;
   for (int i = 0; i < r; i++)
   {
      for (int j = c - 1; j >= 0; j--)
      {
         if (i == 0 and j == c - 1)
         {
            dp2[i][j] = mat[i][j];
         }

         else if (i == 0)
         {
            dp2[i][j] = mat[i][j] + dp2[i][j + 1];
         }
         else if (j == c - 1)
         {
            dp2[i][j] = mat[i][j] + dp2[i - 1][j];
         }
         else
         {
            dp2[i][j] = mat[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
         }

      }

   }

   int dp3[5][4];
   for (int i = 4; i >= 0; i--)
   {
      for (int j = 0; j <= 3; j++)
      {
         if (i == 0 and j == 0)

            dp3[i][j] = mat[i][j];

         else if (i == 0)

            dp3[i][j] = mat[i][j] + dp3[i][j - 1];

         else if (j == 0)

            dp3[i][j] = mat[i][j] + dp3[i + 1][j];

         else

            dp3[i][j] = mat[i][j] + max(dp3[i][j - 1], dp3[i + 1][j]);

      }
   }
   int dp4[i][j];

   for (int i = 4; i >= 0; i--)
   {
      for (int j = 3; j >= 0; j--)
      {
         if (i == 4 and j == 3)
            dp4[i][j] = mat[i][j];

         else if (i == 4)
            dp4[i][j] = mat[i][j] + dp4[i][j + 1];

         else if (j == 3)
            dp4[i][j] = mat[i][j] + dp4[i + 1][j];

         else
            dp4[i][j] = mat [i][j] + max(dp4[i + 1][j], dp4[i][j + 1]);
      }
   }

   int maxval = INT_MAX;

   for (int i = 1; i <=r-2; ++i)
   {
       for (int j = 1; j <=c-2; ++j)
       {
           int case1 = dp[i-1][j]+dp2[i][j+1]+dp4[i+1][j]+dp3[i][j-1];
           int case2 = dp[i][j-1]+dp4[i1][j+1]+dp3[i+1][j]+dp2[i-1][j];

           maxval = max(case1,case2);
       }
   }

   cout<<max<<endl;
   return 0 ;
}