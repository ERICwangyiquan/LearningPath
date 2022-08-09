#pragma once
#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
    BSTreeNode<K>* _left;
    BSTreeNode<K>* _right;
    K _key;

    BSTreeNode(const K& key)
    :_left(nullptr)
    ,_right(nullptr)
    ,_key(key)
    {}
};


template<class K>
struct BSTree
{
    typedef BSTreeNode<K> Node;

private:
    Node* _root;

public:
    BSTree()
    :_root(nullptr)
    {}

    bool Insert(const K& key)
    {
        if(_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }

        Node* parent = nullptr;
        Node* curr = _root;
        while(curr)
        {
            if(key < curr->_key)
            {
                parent = curr;
                curr = curr->_left;
            }
            else if(key > curr->_key)
            {
                parent = curr;
                curr = curr->_right;
            }
            else
            {
                return false;
            }
        }
        //parent->_left == curr
        if(key < parent->_key)
        {
            parent->_left = new Node(key);
        }
        else
        {
            parent->_right = new Node(key);
        }
        
        return true;
    }

    Node* Find(const K& key)
    {
        Node* curr = _root;
        while(curr)
        {
            if(key < curr->_key)
            {
                curr = curr->_left;
            }
            else if(key > curr->_key)
            {
                curr = curr->_right;
            }
            else
            {
                return curr;
            }
        }
        return nullptr;
    }

    bool Erase(const K& key)
    {
        Node* parent = nullptr;
        Node* curr = _root;
        while(curr)
        {
            if(key < curr->_key)
            {
                parent = curr;
                curr = curr->_left;
            }
            else if(key > curr->_key)
            {
                parent = curr;
                curr = curr->_right;
            }
            else //find it, start to delete the node
            {
                // leaf node and one-child node have the same solutions
                if(curr->_left == nullptr)
                {
                    if(parent == nullptr)
                    {
                        _root = _root->_right;
                        delete curr;
                        curr = nullptr;
                    }
                    else
                    {
                        if(parent->_left == curr)
                        {
                            parent->_left = curr->_right;
                            delete curr;
                            curr = nullptr;
                            return true;
                        }
                        else
                        {
                            parent->_right = curr->_right;
                            delete curr;
                            curr = nullptr;
                            return true;
                        }
                    }
                }
                else if(curr->_right == nullptr)
                {
                    if(parent == nullptr)
                    {
                        _root = _root->_left;
                        delete curr;
                        curr = nullptr;
                        return true;
                    }
                    else
                    {
                        if(parent->_left == curr)
                        {
                            parent->_left = curr->_left;
                            delete curr;
                            curr = nullptr;
                            return true;
                        }
                        else
                        {
                            parent->_right = curr->_left;
                            delete curr;
                            curr = nullptr;
                            return true;
                        }
                    }
                }
                // 2 childs' circumstance
                else
                {
                    Node* orig = curr;
                    parent = curr;
                    curr = curr->_left;
                    while(curr->_right)
                    {
                        parent = curr;
                        curr = curr->_right;
                    }
                    orig->_key = curr->_key;
                    if(parent->_left == curr)
                    {
                        parent->_left = curr->_left;
                        delete curr;
                        curr = nullptr;
                        return true;
                    }
                    else
                    {
                        parent->_right = curr->_left;
                        delete curr;
                        curr = nullptr;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool InsertR(const K& key)
    {
        _InsertR(_root, key);
    }

    Node* FindR(const K& key)
    {
        _FindR(_root, key);
    }

    // bool EraseR(const K& key)
    // {
    //     _EraseR(_root, key);
    // }

    void InOrder()
    {
        _InOrder(_root);
    }

private:
    bool _InsertR(Node*& root, const K& key)
    {
        if(root == nullptr)
        {
            //判断大小然后插入
        }

        if(key < root->_key)
        {
            return _InsertR(root->_left, key);
        }
        else if(key > root->_key)
        {
            return _InsertR(root->_right, key);
        }
        else
        {
            return false;
        }
    }

    Node* _FindR(Node* root, const K& key)
    {
        if(root == nullptr)
        {
            return nullptr;
        }

        if(key < root->key)
        {
            return Find(root->_left, key);
        }
        else
        {
            return Find(root->_right, key);
        }
        return root;
    }

    // bool _EraseR(Node* root, const K& key)
    // {

    // }

    void _InOrder(Node* root)
    {
        if(root==nullptr)
        {
            return;
        }

        _InOrder(root->_left);
        cout << root->_key << ' ';
        _InOrder(root->_right);
    }
};


void TestBSTree()
{
    BSTree<int> t;
    int a[] = {5,3,4,1,7,8,2,6,0,9};
    for(auto i : a)
    {
        t.Insert(i);
    }

    t.InOrder();
}