//
//  main.cpp
//  Assignment3
//
//  Created by 이진희 on 2021/06/01.
//

#include <iostream>

#include "prefix.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Node* root = buildTree( cin );
    cout << root -> result() << endl;
    
    //    for the test
    
    //    stringstream st("- + * 3 3 * 2 + 2 1 3");
    //    Node* root = buildTree(st);
    //    cout << root -> result() << endl;
    //
    //    stringstream st2("+ * + 3 3 + 2 1 / 4 3");
    //    Node* root2 = buildTree(st2);
    //    cout << root2 -> result() << endl;
    //
    //    stringstream st3("/ - + 3 4 2 + 2 1 1");
    //    Node* root3 = buildTree(st3);
    //    cout << root3 -> result() << endl;
    //
    //    stringstream st4("* + / 4 + 3 4 5 - 2 1");
    //    Node* root4 = buildTree(st4);
    //    cout << root4 -> result() << endl;
    //
    //    stringstream st5("* * 3 3 3");
    //    Node* root5 = buildTree(st5);
    //    cout << root5 -> result() << endl;
    //
    //    stringstream st6("- + 3 4 1");
    //    Node* root6 = buildTree(st6);
    //    cout << root6 -> result() << endl;
    
    return 0;
}
