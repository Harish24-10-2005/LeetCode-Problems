class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        int n = words.size();
        vector<string>res;
        while(i < n)
        {
            int j = i;
            int curlen = 0;
            while(j<n && curlen + words[j].size() + (j-i) <= maxWidth)
            {
                curlen+=words[j].size();
                j++;
            }

            int gap = j - i - 1;
            string line = "";

            if(j == n || gap == 0)
            {
                for(int k=i;k<j;k++)
                {
                    line+=words[k];
                    if(k != j-1) line+= " ";
                }
                line += string(maxWidth - line.size(),' ');
            }
            else
            {
                int total_sp = maxWidth - curlen;
                int gap_sp = total_sp/gap;
                int extra = total_sp % gap;
                for(int k=i;k<j-1;k++)
                {
                    line+= words[k];
                    line+= string(gap_sp + (extra-- > 0 ?1:0),' ');
                }
                line+=words[j-1];
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};