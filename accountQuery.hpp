//
//  accountQuery.hpp
//  Banksystem
//
//  Created by 孔秀志 on 2019/12/15.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#ifndef accountQuery_h
#define accountQuery_h

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::fstream;

class AccountQuery
{
private:
    char m_accountNumber[20];
    char m_firstName[10];
    char m_lastName[10];
    float m_totalBalance;
public:
    void readData();
    void showData();
    void writeRec();
    void readRec();
    void searchRec();
    void editRec();
    void deleteRec();
};

#endif
