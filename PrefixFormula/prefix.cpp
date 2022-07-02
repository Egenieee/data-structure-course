//
//  prefix.cpp
//  Assignment3
//
//  Created by 이진희 on 2021/06/08.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "prefix.hpp"

using namespace std;


string getToken( istream& is ) {
    string s;
    is >> s;
    return s;
}

bool isNumber( const string& s ) {
    return s[0] >= '0' && s[0] <= '9';
}


Node* buildTree( istream& is ) {
    auto s = getToken( is );
    if(isNumber( s )) {
        int num = atoi( s.c_str() ); //문자열을 int형으로 변환
        return new NumberNode(num);
    }
    Operation* op = nullptr;
    if(s[0] == '+') {
        op = new Addition;
    }
    else if(s[0] == '-') {
        op = new Subtraction;
    }
    else if(s[0] == '*') {
        op = new Multiplication;
    }
    else if(s[0] == '/') {
        op = new Division;
    }
    if( op == nullptr ) {
        cout << "Invalid Operator" << endl;
        exit(0);
    }
    
    op -> left = buildTree( is );
    op -> right = buildTree( is );
    
    return op;
}
