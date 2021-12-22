//
// Created by Song Xu on 2021/12/15.
//

#include "Demo01.h"
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include "zlib.h"
using namespace std;

void printVector(vector<int>& v) {

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int>v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    cout << "swap then" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

void test02()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }

    cout << "ca:" << v.capacity() << endl;
    cout << "si" << v.size() << endl;

    v.resize(3);

    cout << "ca:" << v.capacity() << endl;
    cout << "si:" << v.size() << endl;

//    v.shrink_to_fit();

    cout << "ca:" << v.capacity() << endl;
    cout << "si" << v.size() << endl;
}

int main() {
    test01();
    test02();

    gzFile dfp = gzopen("src/test.fq", "r");
    if (dfp == 0)
    {
        fprintf(stderr, "[ERROR] Cannot find the input read file: \n");
        exit(0);
    }
    gzclose(dfp);
    return 0;
}




