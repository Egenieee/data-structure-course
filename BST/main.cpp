//
//  main.cpp
//  Assignment2
//
//  Created by 이진희 on 2021/05/12.
//

#include <iostream>
#include <string>

#include "BST.hpp"

using namespace std;

struct Student {
    long id;
    string name;
    int midScore;
    int finScore;
    double avgScore = calAvg();
    friend ostream& operator << ( ostream& os, const Student& s ) {
        os << "[" << s.id << ", " << s.name << ", " << s.midScore << ", " << s.finScore << ", " << s.avgScore << "]";
        return os;
    }
    friend bool operator < ( const Student& a, const Student& b) {
        return a.id < b.id;
    }
    friend bool operator > ( const Student& a, const Student& b) {
        return a.id > b.id;
    }
    friend bool operator == ( const Student& a, const Student& b) {
        return a.id == b.id;
    }
    
    double calAvg() {
        avgScore = (double)(midScore + finScore) / 2;
        return avgScore;
    }
};

int main(int argc, const char * argv[]) {
    BST<Student> students;
    bool loop = false;
    while( !loop ) {
        int operationCode = 0;
        cout << "Enter Operation Code: ";
        cin >> operationCode;
        switch ( operationCode ) {
            case 1: {
                cout << "Enter ID, name, mid, final scores: ";
                long   inputId;
                string inputName;
                int    inputMid;
                int    inputFin;
                cin >> inputId >> inputName >> inputMid >> inputFin;
                
                Student found = students.find({inputId, "", 0, 0});
                if( found.id == inputId ) {
                    cout << "Duplicated ID" << endl;
                    break;
                }
                
                students.insert({inputId, inputName, inputMid, inputFin});
                
            } break;
            
            case 2: {
                cout << "Enter ID: ";
                long inputId;
                cin >> inputId;
                
                Student found = students.find({inputId, "", 0, 0});
                if( found.id == 0 ) {
                    cout << "No matching student" << endl;
                    break;
                }
                
                students.remove({inputId, "", 0, 0});
            } break;

            case 3: {
                students.inorderPrint();
                cout << endl;
            } break;

            case 4: {
                cout << "Enter ID: ";
                long inputId;
                cin >> inputId;
                
                Student found = students.find({inputId, "", 0, 0});
                if( found.id == 0 ) {
                    cout << "No matching student" << endl;
                    break;
                }
                
                cout << found << endl;
            } break;

            case 5: {
                loop = true;
            } break;

            default:
                cout << "Wrong operation code !!" << endl;
        }
    }
    
    
    
    
    return 0;
}
