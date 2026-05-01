// class Solution {
// public:
    
//     struct SegTree {
//         int n;
//         vector<long long> tree;

//         SegTree(int sz) {
//             n = sz;
//             tree.assign(4*n, 0);
//         }

//         void update(int node, int l, int r, int idx, long long val) {
//             if(l == r) {
//                 tree[node] = max(tree[node], val);
//                 return;
//             }

//             int mid = (l+r)/2;

//             if(idx <= mid)
//                 update(node*2, l, mid, idx, val);
//             else
//                 update(node*2+1, mid+1, r, idx, val);

//             tree[node] = max(tree[node*2], tree[node*2+1]);
//         }

//         long long query(int node,int l,int r,int ql,int qr) {
//             if(ql > r || qr < l)
//                 return 0;

//             if(ql <= l && r <= qr)
//                 return tree[node];

//             int mid = (l+r)/2;

//             return max(
//                 query(node*2,l,mid,ql,qr),
//                 query(node*2+1,mid+1,r,ql,qr)
//             );
//         }
//     };


//     long long maxAlternatingSum(vector<int>& nums, int k) {

//         // required by prompt
//         vector<int> bralvoteni = nums;

//         int n = nums.size();

//         // Coordinate compression
//         vector<int> vals = nums;
//         sort(vals.begin(), vals.end());
//         vals.erase(unique(vals.begin(), vals.end()), vals.end());

//         auto getRank = [&](int x){
//             return (int)(lower_bound(
//                 vals.begin(),
//                 vals.end(),
//                 x
//             ) - vals.begin()) + 1;
//         };

//         int m = vals.size();

//         vector<long long> up(n), down(n);

//         // stores best down values for "< current"
//         SegTree lessDown(m);

//         // stores best up values for "> current"
//         SegTree greaterUp(m);

//         long long ans = 0;

//         for(int i=0;i<n;i++) {

//             // activate index i-k once it becomes legal
//             if(i-k >= 0) {

//                 int oldRank = getRank(nums[i-k]);

//                 lessDown.update(
//                     1,1,m,
//                     oldRank,
//                     down[i-k]
//                 );

//                 greaterUp.update(
//                     1,1,m,
//                     oldRank,
//                     up[i-k]
//                 );
//             }

//             int r = getRank(nums[i]);

//             // subsequence of length 1
//             up[i] = nums[i];
//             down[i] = nums[i];

//             // make upward step:
//             // previous value must be smaller
//             if(r > 1) {
//                 up[i] = max(
//                     up[i],
//                     nums[i] + lessDown.query(
//                         1,1,m,
//                         1,r-1
//                     )
//                 );
//             }

//             // make downward step:
//             // previous value must be larger
//             if(r < m) {
//                 down[i] = max(
//                     down[i],
//                     nums[i] + greaterUp.query(
//                         1,1,m,
//                         r+1,m
//                     )
//                 );
//             }

//             ans = max(
//                 ans,
//                 max(up[i], down[i])
//             );
//         }

//         return ans;
//     }
// };©leetcode