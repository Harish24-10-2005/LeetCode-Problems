class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0;
        int cnt = 1;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]!=chars[l])
            {
                l = i;
            }
            else 
            {
                chars[i] = ' ';
                cnt++;
            }
        }
        cnt = 0;
        chars.push_back('a');
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i] == ' ')
            {
                cnt++;
            }
            else
            {
                int t = cnt;
                string s = to_string(cnt+1);
                // cout<<s<<endl;
                cnt = 0;
                if(t == 0) continue; 
                int temp = i-1;
                // cout<<temp<<endl;
                for(int j=s.size()-1;j>=0;j--)
                {
                    chars[temp] = s[j];
                    // cout<<s[j]<<endl;
                    temp-=1;
                }
            }
        }
        chars.pop_back();
        int i=0;
        while(i<chars.size())
        {
            if(chars[i] == ' ')
            {
                chars.erase(chars.begin()+i);
                i--;
            } 
            i++;
        }
        return chars.size();
    }
};