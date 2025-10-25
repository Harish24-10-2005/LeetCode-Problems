class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int temp = 1;
        for(int i=0;i<n;i++)
        {
            if(i%7 == 0)
            {
                temp = (i/7) + 1;
                // cout<<endl;
            }
            // cout<<temp<<" ";
            ans+=temp;
            temp++;
        }
        return ans;
    }
};