//
//  BST.hpp
//  Assignment2
//
//  Created by 이진희 on 2021/05/12.
//

#ifndef BST_hpp
#define BST_hpp

#include <iostream>

using namespace std;

template <typename T>
struct BST_Node {
    T val;
    BST_Node* left = nullptr;
    BST_Node* right = nullptr;
};

template <typename T>
struct BST {
    BST_Node<T>* root = nullptr;
    
    static BST_Node<T>* insert_rec(BST_Node<T>* node, const T& value) {
        
        if( node == nullptr ) {
            node = new BST_Node<T> {value, nullptr, nullptr};
//            node -> left = nullptr;
//            node -> right = nullptr;
            return node;
        }
        
        else {
            if (node -> val > value ) {
                node -> left = insert_rec(node -> left, value);
            }
            else if ( node -> val < value ) {
                node -> right = insert_rec(node -> right, value);
            }
        }
        
        return node;
    }
    
    void insert( const T& value ) {
        if( !root ) {
            root = new BST_Node<T> {value, nullptr, nullptr};
        }
        else {
            insert_rec( root, value );
        }
    }
    
    static BST_Node<T>* find_rec(BST_Node<T>* node, const T& key) {
        if( !node ) {
            return nullptr;
        }
        if( key == node -> val) {
            return node;
        }
        if( key < node -> val ) {
            return find_rec( node -> left, key );
        }
        else {
            return find_rec( node -> right, key );
        }
    }
    
    T find( const T& key) {
        BST_Node<T>* found = find_rec( root, key );
        if( found ) {
            return found -> val;
        }
        else {
            return T();
        }
    }
    
    static BST_Node<T>* leftSuccessor( BST_Node<T>* start ) {
        if( start -> left ) {
            return leftSuccessor( start -> left );
        }
        return start;
    }
    
    static BST_Node<T>* remove_rec(BST_Node<T>* node, const T& key) {
        if( !node ) {
            return nullptr;
        }
        if( key < node -> val ) {
            node -> left = remove_rec( node -> left, key );
        }
        else if ( key > node -> val ) {
            node -> right = remove_rec(node -> right, key );
        }
        else if( !node -> left) {
            auto ref = remove_rec( node -> right, key );
            delete node;
            return ref;
        }
        else if( !node -> right) {
            auto ref = remove_rec( node -> left, key );
            delete node;
            return ref;
        }
        else {
            auto successNode = leftSuccessor( node -> right );
            auto left = node -> left;
            auto right = node -> right;
            *node = *successNode;
            node -> left = left;
            node -> right = right;
            node -> right = remove_rec(node -> right, successNode -> val );
        }
        
        return node;
    }
    
    void remove( const T& key) {
        root = remove_rec(root, key);
    }
    
    static void inorderPrint_rec( BST_Node<T>* node ) {
        if ( !node ) {
            return;
        }
        inorderPrint_rec(node -> left);
        cout << node -> val << " ";
        inorderPrint_rec( node -> right);
    }
    
    void inorderPrint() {
        inorderPrint_rec(root);
    }
    
    template<typename Func>
    static void visit_rec( BST_Node<T>* node, Func func) {
        if( node -> left ) {
            visit_rec(node -> left, func);
        }
        func(node);
        if( node -> right) {
            visit_rec(node -> right, func);
        }
    }
    
    template<typename Func>
    void visit( Func func ) {
        if( root ) {
            visit_rec(root, func);
        }
    }
};


#endif /* BST_hpp */
