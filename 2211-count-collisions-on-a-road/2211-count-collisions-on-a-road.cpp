class Solution {
public:
    int countCollisions(string d) {
        int ans = 0;
        int cnt = 0;
        char lst = 'L';
        for(int i=0;i<d.size();i++)
        {
            if(d[i] == 'L')
            {
                if(lst == 'S')
                {
                    ans+=cnt;
                    cnt = 1;
                    lst = 'S';
                }
                else if(lst == 'R')
                {
                    ans+=cnt + 1;
                    cnt = 1;
                    lst = 'S';
                } 
            }
            else if(d[i] == 'R')
            {
                if(lst == 'S')
                {
                    lst = 'R';
                    continue;
                }
                cnt++;
                lst = 'R';
            }
            else
            {
                if(lst == 'R')
                {
                    ans+=cnt;
                }
                cnt = 1;
                lst = 'S';
            }
            cout<<ans<<" "<<lst<<endl;
        }
        return ans;
    }
};