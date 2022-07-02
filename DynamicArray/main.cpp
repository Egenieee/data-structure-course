//
//  main.cpp
//  Assignment1
//
//  Created by 이진희 on 2021/04/16.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

#include "dynamicArray.hpp"

using namespace std;


template <typename T> void print ( const T& list ) {
    for( const auto& item : list) {
        cout << item;
    }
    cout << endl;
};


struct Student {
    long   id;
    string name;
    int    midScore;
    int    finScore;
    double avgScore = calAvg();
    friend ostream& operator << ( ostream& os, const Student& s ) {
        os << "[" << s.id << ", " << s.name << ", " << s.midScore << ", " << s.finScore << ", " << s.avgScore << "]";
        return os;
    }
    double calAvg() {
        avgScore = (double)(midScore + finScore) / 2;
        return avgScore;
    }
};
    

int main(int argc, const char * argv[]) {
    dynamic_array<Student> students(0);
    bool loop = false;
    while( !loop ) {
        print(students);
        int operationCode = 0;
        cout << "Enter Operation Code: ";
        cin >> operationCode;
        switch (operationCode){
            case 1: { //새학생 정보 추가
                cout << "Enter ID, name, mid, final scores: ";
                long   inputId;
                string inputName;
                int    inputMid;
                int    inputFin;
                cin >> inputId >> inputName >> inputMid >> inputFin;
                students.push_back({inputId, inputName, inputMid, inputFin});
            } break;
            case 2: {//ID 받아서 해당 정보 삭제
                if(students.size() == 0) {
                    break;
                }
                cout << "Enter ID: ";
                long inputId;
                cin >> inputId;
                //해당 학생이 존재할 경우에만 코드 실행
                for( auto i = 0 ; i < students.size() ; i++) {
                    if(students[i].id == inputId) {
                        students.erase(remove_if( students.begin(), students.end(), [&](const auto& a) {
                            return a.id == inputId; }));
                    }
                }
            } break;
            case 3: {//name 받아서 해당 정보 삭제
                if(students.size() == 0) {
                    break;
                }
                cout << "Enter Name: ";
                string inputName;
                cin >> inputName;
                for( auto i = 0 ; i < students.size() ; i++) {
                    if(students[i].name.compare( inputName ) == 0) {
                        students.erase(remove_if( students.begin(), students.end(), [&](const auto& a) {
                            return a.name.compare(inputName) == 0; }));
                    }
                }
            } break;
            case 4: {//학번과 중간점수 받아서 업데이트
                if(students.size() == 0) {
                    break;
                }
                cout << "Enter ID and Midterm Score: ";
                long inputId;
                int  inputMid;
                cin >> inputId >> inputMid;
                for( auto i = 0 ; i < students.size() ; i++) {
                    if(students[i].id == inputId) {
                        students[i].midScore = inputMid;
                        students[i].avgScore = students[i].calAvg();
                    }
                }
                
            } break;
            case 5: {//학번과 기말점수 받아서 업데이트
                if(students.size() == 0) {
                    break;
                }
                cout << "Enter ID and Final Score: ";
                long inputId;
                int  inputFin;
                cin >> inputId >> inputFin;
                for( auto i = 0 ; i < students.size() ; i++) {
                    if(students[i].id == inputId) {
                        students[i].finScore = inputFin;
                        students[i].avgScore = students[i].calAvg();
                    }
                }
            } break;
            case 6: {//학번 순으로 정렬
                if(students.size() == 0) {
                    break;
                }
                sort(students.begin(), students.end(), [] (const auto& a, const auto& b) {
                    return a.id < b.id;
                } );
            } break;
            case 7: {//평균 성적 순으로 정렬
                if(students.size() == 0) {
                    break;
                }
                sort(students.begin(), students.end(), [] (const auto& a, const auto& b) {
                    return a.avgScore < b.avgScore;
                } );
            } break;
            case 8: {//종료
                loop = true;
            } break;
            default:
                cout << "Wrong operation code !!" << endl;
            
        }
    }
    
    
    return 0;
}
