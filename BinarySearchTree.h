//
// Created by henri on 11/27/2023.
//

#ifndef UNTITLED5_BINARYSEARCHTREE_H
#define UNTITLED5_BINARYSEARCHTREE_H

#include <iostream>

class BinarySearchTree {
private:
    struct Node {
        int val;
        Node* left;
        Node* right;

        explicit Node(int aVal, Node* left = nullptr, Node* right = nullptr);
    };
    Node* root;

private:
    void deleteNode(int aVal, Node*& aNodePtr);
    void makeDeletion(Node *& aNodePtr);




public:
    BinarySearchTree();
    void insert(Node *&aNodePtr, Node *&aNewNodePtr);
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);

     void displayInOrder(Node* aNodePtr){
        if (aNodePtr) {
            displayInOrder(aNodePtr->left);
            std::cout << aNodePtr->val << " ";
            displayInOrder(aNodePtr->right);
        }
    }

    void printTree(){
        displayInOrder(root);
        std::cout << std::endl;
    };

};

#endif //UNTITLED5_BINARYSEARCHTREE_H
