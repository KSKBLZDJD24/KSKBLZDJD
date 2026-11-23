#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(TreeNode* node,int x) {
	if (node == nullptr) {
		return new TreeNode(x);
	}
	if (x < node->val) {
		node->left = build(node->left, x);
	}
	else {
		node->right = build(node->right, x);
	}
	return node;
}

void Preorder(TreeNode* node) {
	if (node == nullptr) {
		return;
	}

	cout << node->val<<" ";
	Preorder(node->left);
	Preorder(node->right);
}

void inorder(TreeNode* node) {
	if (node == nullptr) {
		return;
	}

	inorder(node->left);
	cout << node->val << " ";
	inorder(node->right);
}

void postorder(TreeNode* node) {
	if (node == nullptr) {
		return;
	}

	postorder(node->left);
	postorder(node->right);
	cout << node->val << " ";
}

int number(TreeNode* node) {
	if (node == nullptr) {
		return 0;
	}
	
	return 1 + number(node->left) + number(node->right);
}

int leaf(TreeNode* node) {
	if (node == nullptr) {
		return 0;
	}

	if (node->left == nullptr && node->right == nullptr) {
		return 1;
	}

	return leaf(node->left) + leaf(node->right);
}

int height(TreeNode* node) {
	if (node == nullptr) {
		return 0;
	}

	int l = height(node->left);
	int r = height(node->right);

	if (l>r) {
		return l + 1;
	}
	else {
		return r + 1;
	}
}

int sum(TreeNode* node) {
	if (node == nullptr) {
		return 0;
	}

	return node->val + sum(node->left) + sum(node->right);
}

bool search(TreeNode* node,int x) {
	if (node == nullptr) {
		return false;
	}

	if (node->val == x) {
		return true;
	}

	return search(node->left, x) || search(node->right, x);
}

int main() {
	TreeNode* root = nullptr;
	int arr[] = { 27,58,7,43,23,5,82,54,6,4,3,66,97 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++) {
		root = build(root, arr[i]);
	}

	cout << "前序遍历："; Preorder(root); cout << endl;
	cout << "中序遍历："; inorder(root); cout << endl;
	cout << "后序遍历："; postorder(root); cout << endl;
	cout << "总节点数：" << number(root) << endl;
	cout << "叶子节点数：" << leaf(root) << endl;
	cout << "树高：" << height(root) << endl;
	cout << "节点总和：" << sum(root) << endl;

	return 0;
}