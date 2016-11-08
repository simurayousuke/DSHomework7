#include<iostream>
#include"BinaryTree.h"

int main()
{
	//构造书93页下方的二叉树
	BinaryTree<char> tree;
	tree.getRoot()->setValue('A');
	tree.createLeftChild(tree.getRoot(), 'B');
	tree.createRightChild(tree.getRoot()->getLeftChild(), 'D');
	tree.createLeftChild(tree.getRoot()->getLeftChild()->getRightChild(), 'F');
	tree.createRightChild(tree.getRoot()->getLeftChild()->getRightChild(), 'G');
	tree.createRightChild(tree.getRoot(), 'C');
	tree.createRightChild(tree.getRoot()->getRightChild(), 'E');
	tree.createRightChild(tree.getRoot()->getRightChild()->getRightChild(), 'H');

	//构造二叉搜索树
	//int a[11] = { 50,19,55,5,35,20,52,100,53,88,92 };
	//tree.binarySearchInsertByArray(a, 11);

	//遍历操作：输出节点的值
	std::cout << "前序遍历：";
	tree.preOrder(tree.getRoot());		//前序遍历
	std::cout << std::endl << "中序遍历：";
	tree.inOrder(tree.getRoot());			//中序遍历
	std::cout << std::endl << "后序遍历：";
	tree.postOrder(tree.getRoot());		//后序遍历
	std::cout << std::endl << "层次遍历：";
	tree.breadthFirstOrder(tree.getRoot());	//广度优先遍历
	std::cout << std::endl;
	return 0;
}