#include<iostream>
#include"BinaryTree.h"

int main()
{
	//������93ҳ�·��Ķ�����
	BinaryTree<char> tree;
	tree.getRoot()->setValue('A');
	tree.createLeftChild(tree.getRoot(), 'B');
	tree.createRightChild(tree.getRoot()->getLeftChild(), 'D');
	tree.createLeftChild(tree.getRoot()->getLeftChild()->getRightChild(), 'F');
	tree.createRightChild(tree.getRoot()->getLeftChild()->getRightChild(), 'G');
	tree.createRightChild(tree.getRoot(), 'C');
	tree.createRightChild(tree.getRoot()->getRightChild(), 'E');
	tree.createRightChild(tree.getRoot()->getRightChild()->getRightChild(), 'H');

	//�������������
	//int a[11] = { 50,19,55,5,35,20,52,100,53,88,92 };
	//tree.binarySearchInsertByArray(a, 11);

	//��������������ڵ��ֵ
	std::cout << "ǰ�������";
	tree.preOrder(tree.getRoot());		//ǰ�����
	std::cout << std::endl << "���������";
	tree.inOrder(tree.getRoot());			//�������
	std::cout << std::endl << "���������";
	tree.postOrder(tree.getRoot());		//�������
	std::cout << std::endl << "��α�����";
	tree.breadthFirstOrder(tree.getRoot());	//������ȱ���
	std::cout << std::endl;
	return 0;
}