class NumArray {
    vector<int>st;
    int n;
    void buildSegTree(vector<int>nums,int s,int e,int s_idx)
    {
        //leafNode
        if(s == e)
        {
            st[s_idx] = nums[s];
            return;
        }
        //INternal Node
        int mid = s + (e - s)/2;
        buildSegTree(nums,s,mid,2*s_idx);
        buildSegTree(nums,mid+1,e,2*s_idx+1);
        st[s_idx] = st[2*s_idx] + st[2*s_idx+1];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n+1);// 1based index
        buildSegTree(nums,0,n-1,1);
    }
    
    void updateNode(int i,int val,int s_idx,int s,int e)
    {
       
        if(s == e)//total overlap
        {
            st[s_idx] = val;
            return;
        }
        int mid = s + (e-s)/2;
        if(i <= mid){
        updateNode(i,val,2*s_idx,s,mid);
        }else{
        updateNode(i,val,2*s_idx+1,mid+1,e);
        }
        st[s_idx] = st[2*s_idx] + st[2*s_idx+1];
    }
    void update(int index, int val) {
        updateNode(index,val,1,0,n-1);
    }
    int rangeSum(int lft,int ryt,int s_idx,int s,int e)
    {
        if(s > ryt || e < lft) return 0; //no overlap

        if(s >= lft && e <= ryt) return st[s_idx]; //total overlap

        int mid = s + (e - s)/2;
        return rangeSum(lft,ryt,2*s_idx,s,mid) + rangeSum(lft,ryt,2*s_idx +1,mid+1,e);
    }
    int sumRange(int left, int right) {
        return rangeSum(left,right,1,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */