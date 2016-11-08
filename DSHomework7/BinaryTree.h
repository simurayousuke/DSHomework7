#ifndef BINARYTREE
#define BINARYTREE

#include<queue>
#include<stack>

template<class T>
class BinaryTreeNode	//�������Ľڵ�
{
private:
	T element;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;
	BinaryTreeNode<T> *parent;
public:
	BinaryTreeNode()	//Ĭ�Ϲ��캯��
	{
		leftChild = 0;
		rightChild = 0;
	}
	BinaryTreeNode(const T &ele)	//ֻ��ֵ�Ĺ��캯��
	{
		element = ele;
		leftChild = 0;
		rightChild = 0;
	}
	BinaryTreeNode(const T &ele, BinaryTreeNode<T> *p)
	{
		element = ele;
		leftChild = 0;
		rightChild = 0;
		parent = p;
	}
	BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r)	//���������ӽڵ�Ĺ��캯��
	{
		element = ele;
		leftChild = l;
		rightChild = r;
	}
	BinaryTreeNode<T> *getLeftChild() const	//ȡ�����ӽڵ�
	{
		return leftChild;
	}
	BinaryTreeNode<T> *getRightChild() const	//ȡ�����ӽڵ�
	{
		return rightChild;
	}
	BinaryTreeNode<T> *getParent() const	//ȡ�����ڵ�
	{
		return parent;
	}
	void setLeftChild(BinaryTreeNode<T> *l)	//�������ӽڵ�
	{
		leftChild = l;
	}
	void setRightChild(BinaryTreeNode<T> *r)	//�������ӽڵ�
	{
		rightChild = r;
	}
	void setParent(BinaryTreeNode<T> *p)
	{
		parent = p;
	}
	T getValue() const	//ȡ���ڵ��ֵ
	{
		return element;
	}
	void setValue(const T &val)	//���ýڵ��ֵ
	{
		element = val;
	}
};

template<class T>
class BinaryTree	//������
{
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree()	//Ĭ�Ϲ��캯��
	{
		root = 0;
	}
	~BinaryTree()
	{

	}
	bool isEmpty() const	//�������Ƿ�Ϊ��
	{
		if (root == 0)
			return true;
		return false;
	}
	BinaryTreeNode<T> *getRoot()	//ȡ�����ڵ�
	{
		if (root == 0)
			root = new BinaryTreeNode<T>;
		return root;
	}
	BinaryTreeNode<T> *getParent(BinaryTreeNode<T> *current) const	//ȡ�����ڵ�
	{
		return current->getParent();
	}
	BinaryTreeNode<T> *getLeftChild(BinaryTreeNode<T> *current) const	//ȡ�����ӽڵ�
	{
		return current->getLeftChild();
	}
	BinaryTreeNode<T> *getRightChild(BinaryTreeNode<T> *current) const	//ȡ�����ӽڵ�
	{
		return current->getRightChild();
	}
	void createLeftChild(BinaryTreeNode<T> *parent, const T &val)	//�������ӽڵ�
	{
		parent->setLeftChild(new BinaryTreeNode<T>(val));
	}
	void createRightChild(BinaryTreeNode<T> *parent, const T &val)	//�������ӽڵ�
	{
		parent->setRightChild(new BinaryTreeNode<T>(val));
	}
	void visit(BinaryTreeNode<T> *current)	//���ʺ������������������Ľڵ�
	{
		std::cout << current->getValue();
	}
	void breadthFirstOrder(BinaryTreeNode<T> *root)	//������ȱ���
	{
		using std::queue;
		queue<BinaryTreeNode<T> *> nodeQueue;	//�洢��Ҫ���ʵĽڵ�
		BinaryTreeNode<T> *pointer = root;

		if (pointer)
			nodeQueue.push(pointer);	//������ڵ�ǿգ�����������
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();	//��ȡ�����׽ڵ�
			visit(pointer);	//���ʵ�ǰ�ڵ�
			nodeQueue.pop();	//�����ʹ��Ľڵ��Ƴ�����
			if (pointer->getLeftChild())
				nodeQueue.push(pointer->getLeftChild());	//�����ʹ��Ľڵ�������ӽڵ����μ������
			if (pointer->getRightChild())
				nodeQueue.push(pointer->getRightChild());	//�����ʹ��Ľڵ�������ӽڵ����μ������
		}
	}
	void preOrder(BinaryTreeNode<T> *root)			//������ȣ�ǰ�����DLR
	{
		using std::stack;

		stack<BinaryTreeNode<T> *> nodeStack;	//��Ŵ����ʽڵ��ջ
		BinaryTreeNode<T> *pointer = root;	//������ڵ�

		while (!nodeStack.empty() || pointer)	//ջΪ��ʱ��������
		{
			if (pointer)
			{
				visit(pointer);	//���ʵ�ǰ�ڵ�
				if (pointer->getRightChild() != NULL)
					nodeStack.push(pointer->getRightChild());	//��ǰ���ʽڵ���������ĸ��ڵ���ջ
				pointer = pointer->getLeftChild();	//ת�������������
			}
			else  //������������ϣ�ת�����������
			{
				pointer = nodeStack.top();	//��ȡջ�������ʽڵ�
				nodeStack.pop();	//ɾ��ջ���ڵ�
			}
		}
	}
	void inOrder(BinaryTreeNode<T> *root)			//������ȣ��������LDR
	{
		using std::stack;

		stack<BinaryTreeNode<T> *> nodeStack;	//�洢�����ʽڵ�
		BinaryTreeNode<T> *pointer = root;		//������ڵ�

		while (!nodeStack.empty() || pointer)	//ջΪ��ʱ��������
		{
			if (pointer)
			{
				nodeStack.push(pointer);	//��ǰ�ڵ���ջ
				pointer = pointer->getLeftChild();	//ת��������ӽڵ�
			}
			else //������������ϣ�ת��������
			{
				pointer = nodeStack.top();	//��ȡջ�������ʽڵ�
				visit(pointer);	//���ʽڵ�
				pointer = pointer->getRightChild();	//ת�����ӽڵ�
				nodeStack.pop();	//ɾ��ջ���ڵ�
			}
		}
	}
	void postOrder(BinaryTreeNode<T> *root)			//������ȣ��������LRD
	{
		using std::stack;

		stack<BinaryTreeNode<T> *> nodeStack;	//�洢�����ʽڵ�
		BinaryTreeNode<T> *pointer = root;		//������ڵ�
		BinaryTreeNode<T> *pre = root;			//����ǰһ�������ʽڵ�

		while (pointer)
		{
			for (; pointer->getLeftChild() != NULL; pointer = pointer->getLeftChild())
				nodeStack.push(pointer);	//��������

			while (pointer != NULL && (pointer->getRightChild() == NULL || pointer->getRightChild() == pre))//��ǰ�ڵ�û�����ӽڵ�����ӽڵ�ձ����ʹ�����ʸýڵ�
			{
				visit(pointer);
				pre = pointer;	//��¼�շ��ʹ��Ľڵ�
				if (nodeStack.empty())
					return;
				pointer = nodeStack.top();	//ȡջ���ڵ�
				nodeStack.pop();
			}
			nodeStack.push(pointer);
			pointer = pointer->getRightChild();	//ת��ǰ�ڵ��������
		}
	}
	void binarySearchInsert(const T &val)
	{
		if (root == 0)
			root = new BinaryTreeNode<T>(val);
		BinaryTreeNode<T> *current = root;		
		while (true)
		{
			if (current->getValue() == val)
				return;
			else if (current->getValue() > val)
			{
				if (current->getLeftChild() != 0)
					current = current->getLeftChild();
				else
				{
					createLeftChild(current, val);
					break;
				}
			}
			else
			{
				if (current->getRightChild() != 0)
					current = current->getRightChild();
				else
				{
					createRightChild(current, val);
					break;
				}
			}
		}
	}
	void binarySearchInsertByArray(T *values, int num)
	{
		for (int i = 0; i < num; i++)
			binarySearchInsert(values[i]);
	}
};

#endif