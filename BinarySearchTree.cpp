//
// Created by henri on 11/27/2023.
//

#include "BinarySearchTree.h"

void BinarySearchTree::insert(Node *&aNodePtr, Node *&aNewNodePtr) {
    if (aNodePtr == nullptr) {
        aNodePtr = aNewNodePtr;
    }
    else if(aNewNodePtr->val < aNodePtr->val) {
        insert(aNodePtr->left, aNewNodePtr);
    }
    else {
        insert(aNodePtr->right, aNewNodePtr);
    }
}

bool BinarySearchTree::searchNode(int aVal) {
    Node* currentNode = root;

    while(currentNode) {
        if(currentNode->val == aVal) {
            return true;
        }
        else if (aVal < currentNode->val) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }
    return false;
}

void BinarySearchTree::deleteNode(int aVal, BinarySearchTree::Node *&aNodePtr) {
    if (aVal < aNodePtr->val) {
        deleteNode(aVal, aNodePtr->left);
    }
    else if (aVal > aNodePtr->val) {
        deleteNode(aVal, aNodePtr->right);
    }
    else {
        makeDeletion(aNodePtr);
    }

}

void BinarySearchTree::makeDeletion(BinarySearchTree::Node *&aNodePtr) {
    Node* tempNodePtr = nullptr;

    if (aNodePtr == nullptr) {
        std::cout << "Cannot remove empty Node" << std::endl;
    }
    else if (aNodePtr->right == nullptr) {
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else if (aNodePtr->left == nullptr) {
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else {
        tempNodePtr = aNodePtr->right;

        while(tempNodePtr->left) {
            tempNodePtr = tempNodePtr->left;
        }

        tempNodePtr->left = aNodePtr->left;

        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right;

        delete tempNodePtr;
    }

}

void BinarySearchTree::remove(int aVal) {
    deleteNode(aVal, BinarySearchTree::root);
}

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree::insertNode(int val) {
    Node* aNewNode = new Node(val);
    insert(root, aNewNode);
}

BinarySearchTree::Node::Node(int aVal, BinarySearchTree::Node* aLeft, BinarySearchTree::Node* aRight) {
    val = aVal;
    left = aLeft;
    right = aRight;
}
