class Solution {
    int answer = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int sum = left.first + right.first + node->val;
        int count = left.second + right.second + 1;

        if (sum / count == node->val) {
            answer++;
        }

        return {sum, count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return answer;
    }
};