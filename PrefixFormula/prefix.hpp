//
//  prefix.hpp
//  Assignment3
//
//  Created by 이진희 on 2021/06/08.
//

#ifndef prefix_hpp
#define prefix_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

struct Node {
    virtual float result() const = 0;
};

struct Operation : Node {
    Node* left = nullptr;
    Node* right = nullptr;
};

struct NumberNode : Node {
    float value;
    NumberNode( int v ) : value((float) v ) {}
    virtual float result() const override {
        return value;
    }
};

struct Addition : Operation {
    virtual float result() const override {
        return (left -> result()) + (right -> result());
    }
};

struct Subtraction : Operation {
    virtual float result() const override {
        return (left -> result()) - (right -> result());
    }
};

struct Multiplication : Operation {
    virtual float result() const override {
        return (left -> result()) * (right -> result());
    }
};

struct Division : Operation {
    virtual float result() const override {
        return (left -> result()) / (right -> result());
    }
};

string getToken( istream& is);

bool isNumber( const string& s);

Node* buildTree( istream& is );

#endif /* prefix_hpp */
