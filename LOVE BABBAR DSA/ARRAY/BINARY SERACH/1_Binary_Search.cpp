#include<bits/stdc++.h>
using namespace std ;


int binSearch(int arr[], int n , int key)
{
    int l , h, mid = 0 ;
    
    while(l<=h)
    {
        mid = l+(h-l)/2 ;
        if(arr[mid]==key)return mid ;

        else if (arr[mid]<key)
        {
               l= mid+1;
        }
        else h=mid-1;
    }

    return -1;
}
int main()
{
    int n ;
    cin >> n ;
    int arr[n];
    for (int i= 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    int key ;
    cin >>key ;
    cout<<"Your key at index : "<< binSearch(arr , n  , key);
}