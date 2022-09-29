#include <iostream>
using namespace std;
int n, inorder[100010], postorder[100010], in_idx[100010];

void preorder(int in_begin, int in_end, int post_begin, int post_end) {
	if (in_begin > in_end || post_begin > post_end)
		return;
	int root = postorder[post_end];
	cout << root << " ";
	preorder(in_begin, in_idx[root] - 1, post_begin, post_begin + (in_idx[root] - in_begin) - 1);
	preorder(in_idx[root] + 1, in_end, post_begin + (in_idx[root] - in_begin), post_end - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
	for (int i = 0; i < n; i++)
		in_idx[inorder[i]] = i;
	preorder(0, n - 1, 0, n - 1);
	return 0;
}