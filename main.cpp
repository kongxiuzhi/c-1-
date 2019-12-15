//
//  main.cpp
//  Banksystem
//
//  Created by 孔秀志 on 2019/12/15.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#include <iostream>
#include "accountQuery.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    AccountQuery A;
    int choice;
    cout << "***Account Information System***" << endl;
    while(true)
    {
        cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Show record from file";
        cout<<"\n\t3-->Search Record from file";
        cout<<"\n\t4-->Update Record";
        cout<<"\n\t5-->Delete Record";
        cout<<"\n\t6-->Quit";
        cout<<"\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                A.writeRec();
                break;
            case 2:
                A.readRec();
                break;
            case 3:
                A.searchRec();
                break;
            case 4:
                A.editRec();
                break;
            case 5:
                A.deleteRec();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "\n Enter corret choice";
                exit(0);
        }
    }
    system("pause");
    return 0;
}

//seekg seekp tellg tellp (reinterpret_cast<char*>(this), sizeof(*this));
