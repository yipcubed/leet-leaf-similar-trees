#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// https://leetcode.com/problems/leaf-similar-trees/

#include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool isLeaf(TreeNode *r) {
        return r && !r->left && !r->right;
    }

    void inorder(TreeNode *r, vector<int>& leaves) {
        if (!r) return;
        inorder(r->left, leaves);
        if (isLeaf(r))
            leaves.push_back(r->val);
        inorder(r->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left;
        vector<int> right;
        inorder(root1, left);
        inorder(root2, right);
        return left == right;
    }

/*
 * When inorder is already defined

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        vector<int> r1leaves;
        vector<int> r2leaves;
        auto r1lam = [&r1leaves](int val) { r1leaves.push_back(val); };
        auto r2lam = [&r2leaves](int val) { r2leaves.push_back(val); };
        root1->inorder(r1lam);
        root2->inorder(r2lam);
        return r1leaves == r2leaves;
    }

 */
};

void test1() {
    vector<int> v1{3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
    auto t1 = new TreeNode(v1, -1);

    vector<int> v2{3, -1, 4, 8, 9, 66, 77, 88, 99, 6, 7, -1, 4, -1, 9, -1, 8};
    auto t2 = new TreeNode(v2, -1);
    cout << "1 ? " << Solution().leafSimilar(t1, t2) << endl;

}

void test2() {

}

void test3() {

}