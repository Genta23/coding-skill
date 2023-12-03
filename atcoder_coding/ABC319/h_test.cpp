#include <iostream>
#include <vector>
#include <memory>
#include <set>
typedef long long ll;
using namespace std;

template<typename INT, size_t MAX_DIGIT> struct BinaryTrie {
    struct Node {
        size_t count;
        Node *prev, *left, *right;
        Node(Node *prev) : count(0), prev(prev), left(nullptr), right(nullptr) {}
    };
    INT lazy;
    Node *root;

    // constructor
    BinaryTrie() : lazy(0), root(emplace(nullptr)) {}
    inline size_t get_count(Node *v) { return v ? v->count : 0; }

    // add and get value of Node
    void add(INT val) {
        lazy ^= val;
    }
    INT get(Node *v) {
        if (!v) return -1;
        INT res = 0;
        for (int i = 0; i < MAX_DIGIT; ++i) {
            if (v == v->prev->right)
                res |= INT(1)<<i;
            v = v->prev;
        }
        return res ^ lazy;
    }

    // find Node* whose value is val
    Node* find(INT val) {
        INT nval = val ^ lazy;
        Node *v = root;
        for (int i = MAX_DIGIT-1; i >= 0; --i) {
            bool flag = (nval >> i) & 1;
            if (flag) v = v->right;
            else v = v->left;
            if (!v) return v;
        }
        return v;
    }

    // insert
    inline Node* emplace(Node *prev) {
        return new Node(prev);
    }
    void insert(INT val, size_t k = 1) {
        INT nval = val ^ lazy;
        Node *v = root;
        for (int i = MAX_DIGIT-1; i >= 0; --i) {
            bool flag = (nval >> i) & 1;
            if (flag && !v->right) v->right = emplace(v);
            if (!flag && !v->left) v->left = emplace(v);
            if (flag) v = v->right;
            else v = v->left;
        }
        v->count += k;
        while ((v = v->prev)) v->count = get_count(v->left) + get_count(v->right);
    }
    
    // erase
    Node* clear(Node *v) {
        if (!v || get_count(v)) return v;
        delete(v);
        return nullptr;
    }
    bool erase(Node *v, size_t k = 1) {
        if (!v) return false;
        v->count -= k;
        while ((v = v->prev)) {
            v->left = clear(v->left);
            v->right = clear(v->right);
            v->count = get_count(v->left) + get_count(v->right);
        }
        return true;
    }
    bool erase(INT val) {
        auto v = find(val);
        return erase(v);
    }

    // max (with xor-addition of val) and min (with xor-addition of val)
    Node* get_max(INT val = 0) {
        INT nval = val ^ lazy;
        Node* v = root;
        for (int i = MAX_DIGIT-1; i >= 0; --i) {
            bool flag = (nval >> i) & 1;
            if (!v->right) v = v->left;
            else if (!v->left) v = v->right;
            else if (flag) v = v->left;
            else v = v->right;
        }
        return v;
    }
    Node* get_min(INT val = 0) {
        return get_max(~val & ((INT(1)<<MAX_DIGIT)-1));
    }
   
    // lower_bound, upper_bound
    Node* get_cur_node(Node *v, int i) {
        if (!v) return v;
        Node *left = v->left, *right = v->right;
        if ((lazy >> i) & 1) swap(left, right);
        if (left) return get_cur_node(left, i+1);
        else if (right) return get_cur_node(right, i+1);
        return v;
    }
    Node* get_next_node(Node *v, int i) {
        if (!v->prev) return nullptr;
        Node *left = v->prev->left, *right = v->prev->right;
        if ((lazy >> (i+1)) & 1) swap(left, right);
        if (v == left && right) return get_cur_node(right, i);
        else return get_next_node(v->prev, i+1);
    }
    Node* lower_bound(INT val) {
        INT nval = val ^ lazy;
        Node *v = root;
        for (int i = MAX_DIGIT-1; i >= 0; --i) {
            bool flag = (nval >> i) & 1;
            if (flag && v->right) v = v->right;
            else if (!flag && v->left) v = v->left;
            else if ((val >> i) & 1) return get_next_node(v, i);
            else return get_cur_node(v, i);
        }
        return v;
    }
    Node* upper_bound(INT val) {
        return lower_bound(val + 1);
    }
    size_t order_of_val(INT val) {
        Node *v = root;
        size_t res = 0;
        for (int i = MAX_DIGIT-1; i >= 0; --i) {
            Node *left = v->left, *right = v->right;
            if ((lazy >> i) & 1) swap(left, right);
            bool flag = (val >> i) & 1;
            if (flag) {
                res += get_count(left);
                v = right;
            }
            else v = left;
        }
        return res;
    }

    // k-th, k is 0-indexed
    Node* get_kth(size_t k, INT val = 0) {
        Node *v = root;
        if (get_count(v) <= k) return nullptr;
        for (int i = MAX_DIGIT-1; i >= 0; --i) {
            bool flag = (lazy >> i) & 1;
            Node *left = (flag ? v->right : v->left);
            Node *right = (flag ? v->left : v->right);
            if (get_count(left) <= k) k -= get_count(left), v = right;
            else v = left;
        }
        return v;
    }

    // debug
    void print(Node *v, string prefix = "") {
        if (!v) return;
        cout << prefix << ": " << v->count << endl;
        print(v->left, prefix + "0");
        print(v->right, prefix + "1");
    }
    void print() {
        print(root);
    }
    vector<INT> eval(Node *v, int digit) {
        vector<INT> res;
        if (!v) return res;
        if (!v->left && !v->right) {
            for (int i = 0; i < get_count(v); ++i) res.push_back(0);
            return res;
        }
        const auto& left = eval(v->left, digit-1);
        const auto& right = eval(v->right, digit-1);
        for (auto val : left) res.push_back(val);
        for (auto val : right) res.push_back(val + (INT(1)<<digit));
        return res;
    }
    vector<INT> eval() {
        auto res = eval(root, MAX_DIGIT-1);
        for (auto &val : res) val ^= lazy;
        return res;
    }
};


//////////////////
// solver
//////////////////

int main() {
    int n, q; cin >> n >> q;
    vector<pair<ll, ll>> data(n);
    for(int i=0; i<n; i++) cin >> data[i].first >> data[i].second;

    BinaryTrie<pair<int, int>, 30> start, goal;
    for(int i=0; i<n; i++){
        start.insert({data[i].first, i+1});
        goal.insert({data[i].second, i+1});
    }

    for(int i=0; i<q; i++){
        int t; cin >> t;
        if(t == 1){
            int x; ll l, r;
            cin >> x >> l >> r;
            // 既存のデータの上書きを行う
            // 削除
            start.erase(start.find({data[x-1].first, x}));
            goal.erase(goal.find({data[x-1].second, x}));
            // 追加 配列への記入
            data[x-1].first = l;
            data[x-1].second = r;
            // 追加 setへの挿入
            start.insert({l, x});
            goal.insert({r, x});

        }
        else if(t == 2){
            int x; cin >> x;
            // 要素の数を数える
            --x;
            auto v = goal.get_kth(x);
            cout << goal.get(v).first << " " << goal.get(v).second << endl;
            //bt.erase(v);
        }
    }
    
    // bt.insert(x);
    // --x;
    // auto v = bt.get_kth(x);
    // cout << bt.get(v) << endl;
    // bt.erase(v);
}