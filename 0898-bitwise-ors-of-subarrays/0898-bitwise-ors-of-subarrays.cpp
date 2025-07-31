class Solution {
// void rec(int i,vector<int>&arr)
// {
//     if(i == n)
//     {
//         return ;
//     }
//     rec(i+1,)

// }
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        set<int>st;
        int ans = 1;
        int i =0;
        for(int i=0;i<n;i++)
        {
            if(i+1< n && arr[i] == arr[i+1]) continue;
            
            for(int j=i;j<n;j++)
            {   
                int x = 0;
                for(int k=i;k<=j;k++){x|=arr[k];}
                cout<<x<<endl;
                st.insert(x);
            }
        }
        return st.size();
    }
};