class Solution {
    struct Node {
        long long cnt[5] = {};
        int prod = 1;
    };

    int K;
    vector<Node> tree;

    Node mergeNode(const Node& L, const Node& R) {
        Node res;

        // Product of the entire segment
        res.prod = (L.prod * R.prod) % K;

        // Prefixes completely inside the left segment
        for (int r = 0; r < K; r++) {
            res.cnt[r] += L.cnt[r];
        }

        // Prefix = whole left segment + prefix of right segment
        for (int r = 0; r < K; r++) {
            int nr = (L.prod * r) % K;
            res.cnt[nr] += R.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int v = nums[l] % K;
            tree[node].prod = v;
            tree[node].cnt[v] = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = mergeNode(tree[node * 2],
                               tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            for (int i = 0; i < 5; i++)
                tree[node].cnt[i] = 0;

            int v = value % K;
            tree[node].prod = v;
            tree[node].cnt[v] = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, value);
        else
            update(node * 2 + 1, mid + 1, r, idx, value);

        tree[node] = mergeNode(tree[node * 2],
                               tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = l + (r - l) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        K = k;
        int n = nums.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> result;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Consider nums[start ... n-1]
            Node ans = query(1, 0, n - 1, start, n - 1);

            result.push_back((int)ans.cnt[x]);
        }

        return result;
    }
};