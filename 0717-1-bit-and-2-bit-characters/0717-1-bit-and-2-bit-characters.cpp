class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n= bits.size();
        if(n%2 == 0) return false;
        int i = 0;
        int l = 0;
        while(i<n)
        {
            if(bits[i] == 1) i+=2;
            else 
            {
                l = i;
                i+=1;
            }
        }
        cout<<l<<endl;
        return l == n-1;
    }
};