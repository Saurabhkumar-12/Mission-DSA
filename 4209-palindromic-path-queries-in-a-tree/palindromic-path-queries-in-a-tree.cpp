#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> tree;
    int cur_pos;

    int dfs(int v, vector<int>& sz) {
        int size = 1, max_c_sz = 0;
        for (int c : adj[v]) {
            if (c != parent[v]) {
                parent[c] = v;
                depth[c] = depth[v] + 1;
                int c_sz = dfs(c, sz);
                size += c_sz;
                if (c_sz > max_c_sz) {
                    max_c_sz = c_sz;
                    heavy[v] = c;
                }
            }
        }
        sz[v] = size;
        return size;
    }

    void decompose(int v, int h, vector<int>& s_chars) {
        head[v] = h;
        pos[v] = cur_pos;
        update_tree(1, 0, n - 1, cur_pos, 1 << (s_chars[v] - 'a'));
        cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h, s_chars);
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c, s_chars);
        }
    }

    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update_tree(2 * node, start, mid, idx, val);
        else
            update_tree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

    int query_path(int u, int v) {
        int res = 0;
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (depth[head[u]] > depth[head[v]])
                swap(u, v);
            res ^= query_tree(1, 0, n - 1, pos[head[v]], pos[v]);
        }
        if (depth[u] > depth[v])
            swap(u, v);
        res ^= query_tree(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        tree.assign(4 * n, 0);
        cur_pos = 0;

        vector<int> sz(n);
        dfs(0, sz);
        vector<int> s_chars(n);
        for (int i = 0; i < n; ++i) s_chars[i] = s[i];
        decompose(0, 0, s_chars);

        vector<bool> answer;
        for (const string& q : queries) {
            if (q[0] == 'u') {
                int space1 = q.find(' ', 7);
                int u = stoi(q.substr(7, space1 - 7));
                char c = q[space1 + 1];
                s_chars[u] = c;
                update_tree(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int space1 = q.find(' ', 6);
                int space2 = q.find(' ', space1 + 1);
                int u = stoi(q.substr(6, space1 - 6));
                int v = stoi(q.substr(space1 + 1, space2 - space1 - 1));
                
                int mask = query_path(u, v);
                // Check if at most one bit is set
                bool is_palindrome = (mask & (mask - 1)) == 0;
                answer.push_back(is_palindrome);
            }
        }
        return answer;
    }
};