#include <bits/stdc++.h> 
/*
	Tree Node class.

	class BinaryTreeNode 
	{
		T data;
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;

		BinaryTreeNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
	}
*/

long long solve(BinaryTreeNode<int> *root){
	if(root == NULL){
		return 0;
	}

	int sum = 0;

	if(root -> left){
		sum += root -> left -> data;
	}

	sum += solve(root -> left);
	sum += solve(root -> right);


	return sum;
}


long long leftSum(BinaryTreeNode<int> *root)
{
	long long leftNode = solve(root);
	return leftNode;
}