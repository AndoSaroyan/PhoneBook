#include <iostream>
#include <fstream>
#include<string>
using namespace std;

struct contact {
    string name;
    string surname;
    string phnumber;
    string address;
};

void addData() {
    contact man;
    cout << "\n\tEnter Name : ";
    cin.get();
    getline(cin, man.name);
    cout << "\n\tEnter Surname : ";
    cin >> man.surname;
    cout << "\n\tEnter Phone Number : ";
    cin >> man.phnumber;
    cin.ignore();
    cout << "\n\tEnter Address : ";
    cin >> man.address;


    ofstream write;
    write.open("Tvyalner.txt", ios::app);
    
    write << "\n\n" << man.name ;
    write << "\n" << man.surname;
    write << "\n" << man.phnumber;
    write << "\n" << man.address;

    write.close();

    cout << "\n\tInformation saved to file";
}

void print(contact s) {
    cout << "\n\t---Information---";
    cout << "\n\tName is : " << s.name;
    cout << "\n\tSurname  is : " << s.surname;
    cout << "\n\tPhone Number  is : " << s.phnumber;
    cout << "\n\tAddress  is :" << s.address;

}

void readData() {
    contact man;
    ifstream read;
    read.open("Tvyalner.txt");
    while (!read.eof()) {
        read >> man.name;
        read.ignore();
        getline(read, man.surname);
        getline(read, man.phnumber);
        getline(read, man.address);
        print(man);
    }
    read.close();
}

string searchData() {
    string id;
    cout << "\n\tEnter Name you want to search : ";
    cin >> id;
    contact man;
    ifstream read;
    read.open("Tvyalner.txt");
    while (!read.eof()) {
        read >> man.name;
        read.ignore();
        getline(read, man.surname);
        getline(read, man.phnumber);
        getline(read, man.address);

        if (man.name == id) {
            print(man);
            //return id;
        }
    }
    return id;
}

void deleteData() {
    string id = searchData();
    cout << "\n\tYou want to delete Data (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        contact man;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Tvyalner.txt");
        while (!read.eof()) {
            read >> man.name;
            read.ignore();
            getline(read, man.surname);
            getline(read, man.phnumber);
            getline(read, man.address);
            

            if (man.name != id) {
                tempFile << "\n" << man.name;
                tempFile << "\n" << man.surname;
                tempFile << "\n" << man.phnumber;
                tempFile << "\n" << man.address;

            }
        }
        read.close();
        tempFile.close();
        remove("Tvyalner.txt");
        rename("temp.txt", "Tvyalner.txt");
        cout << "\n\tData deleted successfuly";
    }
    else {
        cout << "\n\tData not deleted";
    }
}

void updateData() {
    string id = searchData();
    cout << "\n\tYou want to update Data? (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        contact newData;
        cout << "\n\tEnter Name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter Surname : ";
        cin >> newData.surname;
        cout << "\n\tEnter Phone Number : ";
        cin >> newData.phnumber;
        cout << "\n\tEnter Address : ";
        cin >> newData.address;
       
        contact man;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Tvyalner.txt");
        while (!read.eof()) {
            read >> man.name;
            read.ignore();
            getline(read, man.surname);
            getline(read, man.phnumber);
            getline(read, man.address);
           
            if (man.name != id) {
                tempFile << "\n" << man.name;
                tempFile << "\n" << man.surname;
                tempFile << "\n" << man.phnumber;
                tempFile << "\n" << man.address;
                
            }
            else {
                tempFile << "\n"<< newData.name;
                tempFile << "\n"<< newData.surname;
                tempFile << "\n"<< newData.phnumber;
                tempFile << "\n"<< newData.address;

            }
        }
        read.close();
        tempFile.close();
        remove("Tvyalner.txt");
        rename("temp.txt", "Tvyalner.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tData not deleted";
    }
}

int main()
{


    while (true) {
        cout << "\n\t1.Add Name";
        cout << "\n\t2.See All";
        cout << "\n\t3.Search Data";
        cout << "\n\t4.Delete Data";
        cout << "\n\t5.Update Data";
        cout << "\n\t6.Save And Exit";
        int choice;
        cout << "\n\tChoose Option : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addData();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        case 6:
        cout << " !!!-- Shnorhavor Amanor & Surb Cnund --!!!";
        return 0;
            break;
        }
        
    }

}