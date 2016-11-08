#ifndef BINARYTREE
#define BINARYTREE

#include<queue>
#include<stack>

template<class T>
class BinaryTreeNode	//二叉树的节点
{
private:
	T element;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;
	BinaryTreeNode<T> *parent;
public:
	BinaryTreeNode()	//默认构造函数
	{
		leftChild = 0;
		rightChild = 0;
	}
	BinaryTreeNode(const T &ele)	//只赋值的构造函数
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
	BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r)	//带有左右子节点的构造函数
	{
		element = ele;
		leftChild = l;
		rightChild = r;
	}
	BinaryTreeNode<T> *getLeftChild() const	//取出左子节点
	{
		return leftChild;
	}
	BinaryTreeNode<T> *getRightChild() const	//取出右子节点
	{
		return rightChild;
	}
	BinaryTreeNode<T> *getParent() const	//取出父节点
	{
		return parent;
	}
	void setLeftChild(BinaryTreeNode<T> *l)	//设置左子节点
	{
		leftChild = l;
	}
	void setRightChild(BinaryTreeNode<T> *r)	//设置右子节点
	{
		rightChild = r;
	}
	void setParent(BinaryTreeNode<T> *p)
	{
		parent = p;
	}
	T getValue() const	//取出节点的值
	{
		return element;
	}
	void setValue(const T &val)	//设置节点的值
	{
		element = val;
	}
};

template<class T>
class BinaryTree	//二叉树
{
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree()	//默认构造函数
	{
		root = 0;
	}
	~BinaryTree()
	{

	}
	bool isEmpty() const	//返回树是否为空
	{
		if (root == 0)
			return true;
		return false;
	}
	BinaryTreeNode<T> *getRoot()	//取出根节点
	{
		if (root == 0)
			root = new BinaryTreeNode<T>;
		return root;
	}
	BinaryTreeNode<T> *getParent(BinaryTreeNode<T> *current) const	//取出父节点
	{
		return current->getParent();
	}
	BinaryTreeNode<T> *getLeftChild(BinaryTreeNode<T> *current) const	//取出左子节点
	{
		return current->getLeftChild();
	}
	BinaryTreeNode<T> *getRightChild(BinaryTreeNode<T> *current) const	//取出右子节点
	{
		return current->getRightChild();
	}
	void createLeftChild(BinaryTreeNode<T> *parent, const T &val)	//创建左子节点
	{
		parent->setLeftChild(new BinaryTreeNode<T>(val));
	}
	void createRightChild(BinaryTreeNode<T> *parent, const T &val)	//创建右子节点
	{
		parent->setRightChild(new BinaryTreeNode<T>(val));
	}
	void visit(BinaryTreeNode<T> *current)	//访问函数，用来操作遍历的节点
	{
		std::cout << current->getValue();
	}
	void breadthFirstOrder(BinaryTreeNode<T> *root)	//广度优先遍历
	{
		using std::queue;
		queue<BinaryTreeNode<T> *> nodeQueue;	//存储将要访问的节点
		BinaryTreeNode<T> *pointer = root;

		if (pointer)
			nodeQueue.push(pointer);	//如果根节点非空，将其加入队列
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();	//读取队列首节点
			visit(pointer);	//访问当前节点
			nodeQueue.pop();	//将访问过的节点移出队列
			if (pointer->getLeftChild())
				nodeQueue.push(pointer->getLeftChild());	//将访问过的节点的左右子节点依次加入队列
			if (pointer->getRightChild())
				nodeQueue.push(pointer->getRightChild());	//将访问过的节点的左右子节点依次加入队列
		}
	}
	void preOrder(BinaryTreeNode<T> *root)			//深度优先：前序遍历DLR
	{
		using std::stack;

		stack<BinaryTreeNode<T> *> nodeStack;	//存放待访问节点的栈
		BinaryTreeNode<T> *pointer = root;	//保存根节点

		while (!nodeStack.empty() || pointer)	//栈为空时遍历结束
		{
			if (pointer)
			{
				visit(pointer);	//访问当前节点
				if (pointer->getRightChild() != NULL)
					nodeStack.push(pointer->getRightChild());	//当前访问节点的右子树的根节点入栈
				pointer = pointer->getLeftChild();	//转向访问其左子树
			}
			else  //左子树访问完毕，转向访问右子树
			{
				pointer = nodeStack.top();	//读取栈顶待访问节点
				nodeStack.pop();	//删除栈顶节点
			}
		}
	}
	void inOrder(BinaryTreeNode<T> *root)			//深度优先：中序遍历LDR
	{
		using std::stack;

		stack<BinaryTreeNode<T> *> nodeStack;	//存储待访问节点
		BinaryTreeNode<T> *pointer = root;		//保存根节点

		while (!nodeStack.empty() || pointer)	//栈为空时遍历结束
		{
			if (pointer)
			{
				nodeStack.push(pointer);	//当前节点入栈
				pointer = pointer->getLeftChild();	//转向访问左子节点
			}
			else //左子树访问完毕，转向右子树
			{
				pointer = nodeStack.top();	//读取栈顶待访问节点
				visit(pointer);	//访问节点
				pointer = pointer->getRightChild();	//转向右子节点
				nodeStack.pop();	//删除栈顶节点
			}
		}
	}
	void postOrder(BinaryTreeNode<T> *root)			//深度优先：后序遍历LRD
	{
		using std::stack;

		stack<BinaryTreeNode<T> *> nodeStack;	//存储待访问节点
		BinaryTreeNode<T> *pointer = root;		//保存根节点
		BinaryTreeNode<T> *pre = root;			//保存前一个被访问节点

		while (pointer)
		{
			for (; pointer->getLeftChild() != NULL; pointer = pointer->getLeftChild())
				nodeStack.push(pointer);	//向左搜索

			while (pointer != NULL && (pointer->getRightChild() == NULL || pointer->getRightChild() == pre))//当前节点没有右子节点或右子节点刚被访问过则访问该节点
			{
				visit(pointer);
				pre = pointer;	//记录刚访问过的节点
				if (nodeStack.empty())
					return;
				pointer = nodeStack.top();	//取栈顶节点
				nodeStack.pop();
			}
			nodeStack.push(pointer);
			pointer = pointer->getRightChild();	//转向当前节点的右子树
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