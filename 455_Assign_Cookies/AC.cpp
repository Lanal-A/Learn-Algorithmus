class Solution {
public:
    int findContentChildren(vector<int> &children, vector<int> &cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int child_i = 0, cookie_i = 0;
    int n_children = children.size(), n_cookies = cookies.size();
    while (child_i < n_children && cookie_i < n_cookies) {
        if (children[child_i] <= cookies[cookie_i]) {
            ++child_i;
        }
        ++cookie_i;
    }
    return child_i;
}
};
