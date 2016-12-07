#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace  std;
template<class T>
class BinaryTreeNode
{
    public:
        T element;
        BinaryTreeNode<T> *leftChild;
        BinaryTreeNode<T> *rightChild;
        BinaryTreeNode()
        {
            leftChild=rightChild=NULL;
        }
        BinaryTreeNode(const T& ele)
        {
            leftChild=rightChild=NULL;
            element=ele;
        }
        BinaryTreeNode(const T& ele,BinaryTreeNode<T> *l,BinaryTreeNode<T>* r)
        {
            element=ele;
            leftChild=l;
            rightChild=r;
        }
 
};
template<class T>
class BinaryTree
{
    private:
        BinaryTreeNode<T> *root;
    public:
        BinaryTree()
        {
            root=NULL;
        }
        ~BinaryTree()
        {
            DeleteBinaryTree(root);
        }
        bool isEmpty() 
        {
            if(root==NULL)return true;
            return false;
        }
        BinaryTreeNode<T>* Root() 
        {
            return root;
        }
        BinaryTreeNode<T>*& Getroot()
        {
            return root;
        }
        void levelOrder(BinaryTreeNode<T> *root)
        {
			cout <<"层次遍历:" << endl;
            if(root==NULL)
            {
                cout<<"This is an empty tree!"<<endl;
                return ;
            }
            queue<BinaryTreeNode<T>*>aQueue;
            aQueue.push(root);
            while(!aQueue.empty())
            {
                BinaryTreeNode<T> *pointer=aQueue.front();
                aQueue.pop();
                cout<<pointer->element;//visit(pointer);
                if(pointer->leftChild!=NULL)
                    aQueue.push(pointer->leftChild);
                if(pointer->rightChild!=NULL)
                    aQueue.push(pointer->rightChild);
            }
        }
    
        void BuildBinaryTree(BinaryTreeNode<T>* &root)
        {
            char ch;
            cin>>ch;
            if(ch=='#')root=NULL;
            else 
            {
                root=new BinaryTreeNode<T>;
                root->element=ch;
                BuildBinaryTree(root->leftChild);
                BuildBinaryTree(root->rightChild);
            }
        }
        int TreeWidth(BinaryTreeNode<T>* root)//统计二叉树的宽度
        {
            if(root==NULL)return 0;
            queue<BinaryTreeNode<T>*>aQueue;
            BinaryTreeNode<T>* pointer=root;
            aQueue.push(pointer);
            pointer=NULL;
            aQueue.push(pointer);
            int maxwidth=0,curwidth=0;
            while(aQueue.front()!=NULL)
            {
                while(aQueue.front()!=NULL)
                {
                    pointer=aQueue.front();
                    aQueue.pop();
                    curwidth++;
                    if(pointer->leftChild)aQueue.push(pointer->leftChild);
                    if(pointer->rightChild)aQueue.push(pointer->rightChild);
                }
                aQueue.pop();
                if(curwidth>maxwidth)maxwidth=curwidth;
                curwidth=0;
                pointer=NULL;
                aQueue.push(pointer);
            }
            return maxwidth;
        }
        void DeleteBinaryTree(BinaryTreeNode<T>* &root)//删去二叉树
        {
            if(root!=NULL)
            {
                DeleteBinaryTree(root->leftChild);
                DeleteBinaryTree(root->rightChild);
                delete root;
                root=NULL;
            }
        }
        
        bool JudgeCompleteBinaryTree(BinaryTreeNode<T>* root)//判断是否是完全二叉树
        {
            if(root==NULL)return true;
            queue<BinaryTreeNode<T>*>aQueue;
            BinaryTreeNode<T>* pointer=root;
            bool flag=false;
            aQueue.push(pointer);
            while(!aQueue.empty())
            {
                pointer=aQueue.front();
                aQueue.pop();
                int count=0;
                if(pointer->leftChild)
                    aQueue.push(pointer->leftChild),count++;
                if(pointer->rightChild)
                    aQueue.push(pointer->rightChild),count+=2;
                if(!flag&&count<2)flag=true;
                else if(!flag&&count==2)return false;
                else if(flag&&count)return false;
            }
            return true;
        }
};
 
int main()
{
    BinaryTree<char> asd;
    asd.BuildBinaryTree(asd.Getroot());
    asd.levelOrder(asd.Getroot());
    cout<<endl;
    return 0;
}
