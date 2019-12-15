//
//  accountQuery.cpp
//  Banksystem
//
//  Created by 孔秀志 on 2019/12/15.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#include "accountQuery.hpp"

void AccountQuery::readData()
{
    cout << "\nEnter Account Number: ";
    cin >>m_accountNumber;
    cout << "Enter first name: ";
    cin >> m_firstName;
    cout << "Enter Last Name: ";
    cin >> m_lastName;
    cout << "Enter Balance: ";
    cin >> m_totalBalance;
    cout << endl;
}

void AccountQuery::showData()
{
    cout << "Account Number: " << m_accountNumber << endl;
    cout << "First Name: " << m_firstName << endl;
    cout << "Last Name: " << m_lastName << endl;
    cout << "Current Balance: RS.  " << m_totalBalance << endl;
    cout << "------------------------------------"<< endl;
}

void AccountQuery::writeRec()
{
    ofstream ofs;
    ofs.open("record.bank",ios::out|ios::app);
    readData();
    ofs.write(reinterpret_cast<char *>(this), sizeof(*this)); //任意指针类型转换，不改变bit数,一个类保存到文件；
    ofs.close();
}

void AccountQuery::readRec()
{
    ifstream ifs;
    ifs.open("record.bank",ios::binary);
    if(!ifs.is_open())
    {
        cout <<"Error in Opening! File Not Found!!" << endl;
        return;
    }
    cout << "\n*******Data from file********" << endl;
    while (!ifs.eof())
    {
        if(ifs.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            showData();
        }
    }
    ifs.close();
}

void AccountQuery::searchRec()
{
    int n;
    ifstream ifs;
    ifs.open("record.bank",ios::binary);
    if(!ifs.is_open())
    {
        cout <<"Error in Opening! File Not Found!!" << endl;
        return;
    }
    ifs.seekg(0,ios::end);
    int count = (int)ifs.tellg()/sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout << "\n Enter Record Number to Search: ";
    cin >> n;
    ifs.seekg((n-1)*sizeof(*this));
    ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
    showData();
}

void AccountQuery::editRec()
{
    int n;
    fstream iofs;
    iofs.open("record.bank",ios::in|ios::binary);
    if(!iofs.is_open())
    {
        cout <<"Error in Opening! File Not Found!!" << endl;
        return;
    }
    
    iofs.seekg(0,ios::end);
    int count = (int)iofs.tellg()/sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout << "\n Enter Record Number to Search: ";
    cin >> n;
    iofs.seekg((n-1)*sizeof(*this));
    iofs.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout << "Record " << n << " has following data" << endl;
    showData();
    iofs.close();
    iofs.open("record.bank",ios::out|ios::in|ios::binary);
    iofs.seekp((n-1)*sizeof(*this));
    cout <<"\Enter data to Modify " << endl;
    readData();
    iofs.write(reinterpret_cast<char*>(this), sizeof(*this));
}

void AccountQuery::deleteRec()
{
    int n;
    ifstream ifs;
    ifs.open("record.bank",ios::binary);
    if(!ifs.is_open())
    {
        cout <<"Error in Opening! File Not Found!!" << endl;
        return;
    }
    ifs.seekg(0,ios::end);
    int count = (int)ifs.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("temfile.bank",ios::out|ios::binary);
    ifs.seekg(0);
    for(int i = 0; i < count; i++)
    {
        ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
        if(i == n-1)
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    ifs.close();
    tmpfile.close();
    remove("record.bank");
    rename("temfile.bank", "record.bank");
}
