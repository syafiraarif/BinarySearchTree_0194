#include <iostream>
#include <string>
using namespace std;


class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;
    
    //constructor for the node class
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr;                         //intializing ROOT to null
    }

    void insert(string element)                 //insert a node in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr);        //allocate memory for the new node
        newNode->info = element;                                    //assign value to the data flied of the new node
        newNode->leftchild = nullptr;                               //make the left child of the new node point to null
        newNode->rightchild = nullptr;                              //make the right child of the new node point to null

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode);                       //locate the node which will be the parent of the node to be ins

        if(parent == nullptr)                                       //if the parent is null(tree is empty)
        {
            ROOT = newNode;                                         //mark the new node as root
            return;                                                 //exit
        }
        if(element < parent->info)                                  //if the value in the data flied of the new node is less than that of the
        {
            parent->leftchild = newNode;                            //make the left child of the parent point to thd new node
        }
        else if(element > parent->info)
        {
            parent->rightchild = newNode;
        }
    }

    void search(string element, Node*& parent, Node*& currentNode)
    {
        currentNode = ROOT;
        parent = nullptr;

        while((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node* ptr)
    {
        if (ROOT == nullptr)
        {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr != nullptr)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(Node* ptr)
    {
        
            if (ROOT == nullptr)
            {
                cout << "Tree is Empty" << endl;
                return;
            }
            if (ptr != nullptr)
            {
                cout << ptr->info << " ";
                preorder(ptr->leftchild);
                preorder(ptr->rightchild);
            }
    }

    void postorder(Node* ptr)
    {
        if (ROOT == nullptr)
        {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr != nullptr)
        {

            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }

};


int main()
{
    BinaryTree;
    while(true)
    {
        cout << "\n Menu" << endl;
        cout << "1. imolement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. exit" << endl; 
        cout << "\n enter yoour choice (1-5) : ";

    }
    
}

