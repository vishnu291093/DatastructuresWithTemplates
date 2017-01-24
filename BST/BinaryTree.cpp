#include <iostream>


template <class T>
class NodeTree{
    public:
    T DATA;
    NodeTree<T> * parent = NULL;
    NodeTree<T> * left = NULL;
    NodeTree<T> * right = NULL;

};

template <class T>
class TreeStructure{
    public:
        TreeStructure(){};
        ~TreeStructure(){};
        void InsertNode(T);
        void DestroyTree();
        void PrintCount()

        {
            std::cout<<counter<<std::endl;

        }
        void PrintTree()
        {
            PrintTree( root);
        }
    private:
        void PrintTree(NodeTree<T> * leaf)
        {
            if(leaf !=NULL)
            {
                std::cout<<leaf->DATA<<std::endl;
                PrintTree(leaf->left);
                PrintTree(leaf->right);

            }
        }
        int counter=0;
        void DestroyTree(NodeTree<T> * leaf );
        NodeTree<T> *root = NULL;
        NodeTree<T> InsertNode(T data ,NodeTree<T> * leaf);
};
template <class T>
void TreeStructure<T>::InsertNode(T data)
{
    if (root == NULL)
    {
        root =new NodeTree<T>;
        root->DATA= data;
        counter++;
    }
    else
    {
        InsertNode(data , root);
    }

}
template <class T>
NodeTree<T> TreeStructure<T>::InsertNode(T data ,NodeTree<T> * leaf)
{
    if (data < leaf->DATA)
    {
        if (leaf->left == NULL)
        {
            leaf->left = new NodeTree<T>;
            leaf->left->DATA= data;
            leaf->left->parent = leaf;
            counter++;
            return leaf->left;
        }
        else
            InsertNode(data , leaf->left);
    }
    else if (data >= leaf->DATA)
    {
        if (leaf->right == NULL)
        {
            leaf->right = new NodeTree<T>;
            leaf->right->DATA= data;
            leaf->right->parent = leaf;
            counter++;
            return leaf->right;
        }
        else
            InsertNode(data , leaf->right);

    }
}
template <class T>
void TreeStructure<T>::DestroyTree()
{
    DestroyTree(root);

}

template <class T>
void TreeStructure<T>::DestroyTree(NodeTree<T> *leaf)
{
  if(leaf!=NULL)
  {
    DestroyTree(leaf->left);
    DestroyTree(leaf->right);
    delete leaf;
  }
}

