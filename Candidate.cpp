//
// Created by Student on 2/25/2024.
//

#include "Candidate.h"
#include <cstring>
#include <string>
#include <limits>
#include <iostream>
#include <sstream>

using namespace std;

Candidate::Candidate(){
    id = NULL ;
    password  = NULL;
    forgetPassQ = 0 ;
    forgetPassA  = NULL;
    fName = NULL;
    lName = NULL;
    email = NULL;
    phone = NULL;
    age = 0;
    address = NULL;
    profession = NULL;
    about = NULL;
    isCv = false;
    CV = NULL;
    submissions = NULL;
    numOfSub = 0;
}
Candidate::Candidate(char* id, char* password, int forgetPassQ, char* forgetPassA, char* fName, char* lName,
                     char* email, char* phone, int age, char* address, char* profession, char* about){

    this-> id = new char [strlen(id)+1];
    strcpy(this->id, id);

    this-> password = new char [strlen(password)+1];
    strcpy(this->password, password);

    this-> forgetPassQ = forgetPassQ;

    this-> forgetPassA = new char [strlen(forgetPassA)+1];
    strcpy(this->forgetPassA, forgetPassA);

    this-> fName = new char [strlen(fName)+1];
    strcpy(this->fName, fName);

    this-> lName = new char [strlen(lName)+1];
    strcpy(this->lName, lName);

    this-> email = new char [strlen(email)+1];
    strcpy(this->email, email);

    this-> phone = new char [strlen(phone)+1];
    strcpy(this->phone, phone);

    this-> address = new char [strlen(address)+1];
    strcpy(this->address, address);

    this-> profession = new char [strlen(profession)+1];
    strcpy(this->profession, profession);

    this-> about = new char [strlen(about)+1];
    strcpy(this->about, about);

    this-> age = age;

    this->submissions = NULL;

    this->numOfSub = 0;

    this->CV = NULL;

    isCv = false;
}

Candidate::Candidate(const Candidate& candidate){
    this-> id = new char [strlen(candidate.id)+1];
    strcpy(this->id, candidate.id);

    this-> password = new char [strlen(candidate.password)+1];
    strcpy(this->password, candidate.password);

    this-> forgetPassQ = candidate.forgetPassQ;

    this-> forgetPassA = new char [strlen(candidate.forgetPassA)+1];
    strcpy(this->forgetPassA, candidate.forgetPassA);

    this-> fName = new char [strlen(candidate.fName)+1];
    strcpy(this->fName, candidate.fName);

    this-> lName = new char [strlen(candidate.lName)+1];
    strcpy(this->lName, candidate.lName);

    this-> email = new char [strlen(candidate.email)+1];
    strcpy(this->email, candidate.email);

    this-> phone = new char [strlen(candidate.phone)+1];
    strcpy(this->phone, candidate.phone);

    this-> address = new char [strlen(candidate.address)+1];
    strcpy(this->address, candidate.address);

    this-> profession = new char [strlen(candidate.profession)+1];
    strcpy(this->profession, candidate.profession);

    this-> about = new char [strlen(candidate.about)+1];
    strcpy(this->about, candidate.about);

    isCv = candidate.isCv;

    this-> CV = new char [strlen(candidate.CV)+1];
    strcpy(this->CV, candidate.CV);

    this-> age = age;

    this->numOfSub = candidate.numOfSub;

    this->submissions = new Apply[numOfSub];
    for (int i = 0; i < numOfSub; ++i){
        this->submissions[i] = candidate.submissions[i];
    }

}

Candidate& Candidate::operator=(const Candidate &candidate) {
    delete [] id;
    this-> id = new char [strlen(candidate.id)+1];
    strcpy(this->id, candidate.id);
    delete[] password;
    this-> password = new char [strlen(candidate.password)+1];
    strcpy(this->password, candidate.password);

    this-> forgetPassQ = candidate.forgetPassQ;
    delete[] forgetPassA;
    this-> forgetPassA = new char [strlen(candidate.forgetPassA)+1];
    strcpy(this->forgetPassA, candidate.forgetPassA);
    delete[] fName;
    this-> fName = new char [strlen(candidate.fName)+1];
    strcpy(this->fName, candidate.fName);
    delete[] lName;
    this-> lName = new char [strlen(candidate.lName)+1];
    strcpy(this->lName, candidate.lName);
    delete[] email;
    this-> email = new char [strlen(candidate.email)+1];
    strcpy(this->email, candidate.email);
    delete[] phone;
    this-> phone = new char [strlen(candidate.phone)+1];
    strcpy(this->phone, candidate.phone);
    delete[] address;
    this-> address = new char [strlen(candidate.address)+1];
    strcpy(this->address, candidate.address);
    delete[] profession;
    this-> profession = new char [strlen(candidate.profession)+1];
    strcpy(this->profession, candidate.profession);
    delete[] about;
    this-> about = new char [strlen(candidate.about)+1];
    strcpy(this->about, candidate.about);
    if(candidate.isCv) {
        if(this->isCv)
            delete[] CV;
        this->isCv = candidate.isCv;
        this->CV = new char[strlen(candidate.CV) + 1];
        strcpy(this->CV, candidate.CV);
    } else{
        if(this->isCv) {
            delete[] CV;
            this->CV = NULL;
            this->isCv = false;
        }
    }
    this-> age = candidate.age;

    this->numOfSub = candidate.numOfSub;
    delete[] submissions;
    this->submissions = new Apply[numOfSub];
    for (int i = 0; i < numOfSub; ++i){
        this->submissions[i] = candidate.submissions[i];
    }
}

Candidate::~Candidate(){
    delete [] id;
    delete [] password;
    delete [] forgetPassA;
    delete [] fName;
    delete [] lName;
    delete [] email;
    delete [] phone;
    delete [] address;
    delete [] profession;
    delete [] about;
    delete [] submissions;
    delete [] CV;
}

void Candidate::updateDetails() {
    string newValue;

    cout << "For each field enter a new value (or press Enter to skip): \n";
    cout << "First name: " << fName<<endl ;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] fName;
        fName = new char[newValue.size() + 1];
        strcpy(fName, newValue.c_str());
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    cout << "Last name: " << lName;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] lName;
        lName = new char[newValue.size() + 1];
        strcpy(lName, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Email: " << email;
    getline(cin, newValue);
    if(!newValue.empty()) {
        bool isValid = false;
        while (!isValid) {
            bool hasAt = false;
            bool hasDot = false;
            bool noSpaces = true;

            for (int i = 0; newValue[i] != '\0'; ++i) {
                if (newValue[i] == '@') {
                    hasAt = true;
                }
                if (newValue[i] == '.') {
                    hasDot = true;
                }
                if (newValue[i] == ' ') {
                    noSpaces = false;
                }
            }

            isValid = hasAt && hasDot && noSpaces;

            if (!isValid) {
                cout << "Invalid email. Try again:" << endl;
                getline(cin, newValue);
            }
        }
        delete [] email;
        email = new char[newValue.size() + 1];
        strcpy(email, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


int newAge;
    cout << "Age: " << age;

    while (true) {
        std::getline(std::cin, newValue); // Read a line of input

        if (newValue.empty()) {
            // If the input is empty (user pressed Enter), continue with program logic
            break;
        } else {
            // If the input is not empty, attempt to convert it to an integer
            std::stringstream ss(newValue);
            int temp;
            if (ss >> temp) {
                // If conversion to integer was successful, update the number variable
                age = temp;
                break; // Exit the loop
            } else {
                // If input is not a number, prompt the user to enter a valid integer
                std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            }
        }
    }

    cout << "Phone: " << phone;
    getline(cin, newValue);
    if(!newValue.empty()) {
        for (int i = 0; newValue[i] != '\0'; i++) {
            if (newValue[i] < '0' || newValue[i] > '9'||newValue.length() != 10 || cin.fail()) {
                cout << "Invalid input. Please enter your phone:" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, newValue);
                i = -1;
            }
        }
        delete [] phone;
        phone= new char[newValue.size() + 1];
        strcpy(phone, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Address: " << address;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] address;
        address = new char[newValue.size() + 1];
        strcpy(address, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Profession: " << profession;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] profession;
        profession = new char[newValue.size() + 1];
        strcpy(profession, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "About: " << about;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] about;
        about = new char[newValue.size() + 1];
        strcpy(about, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "CV: " << CV;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] CV;
        CV = new char[newValue.size() + 1];
        strcpy(CV, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Age: " << age;
    getline(cin, newValue);
    if(!newValue.empty()) {
        while (age< 0 || age>200 || cin.fail()) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Try again, Your age:" <<endl;
            getline(cin, newValue);
        }
        age =  stoi(newValue);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout<< "Your profile has been successfully updated\n";
    cout << "--------------------------------------------------------------------------------------------------------------\n";
}

void Candidate::addApply(int id) {
    Apply a1(id);
    Apply* tmp= new Apply [numOfSub + 1];
    for (int i = 0; i <numOfSub ; ++i) {
        tmp[i] = submissions[i];
    }
    delete [] submissions;
    submissions=tmp;
    submissions[numOfSub]=a1;
    numOfSub++;
    for (int i = 0; i <2 ; ++i) {
        cout<<"The Apply "<<i+1<<" is : \n";
        submissions[i].print();
    }
}

int Candidate::deleteApply(int index){

    int id = submissions[index].getIdOfJob();
    numOfSub--;
    Apply* tmp = new Apply[numOfSub];


    for (int i = 0; i < index; i++) {
        tmp[i] = submissions[i];
    }

    for (int i = index; i < numOfSub; i++) {
            tmp[i] = submissions[i+1];
    }

    delete[] submissions;
    submissions = tmp;

    return id;

}

void Candidate::printProfile() {

    cout << "First name: " << fName << endl;
    cout << "Last name: " << lName << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "Age: " << age << endl;
    cout << "Address: " << address << endl;
    cout << "Profession: " << profession << endl;
    cout << "About: " << about << endl;
    cout << "CV: " << CV << endl;
}

char* Candidate:: getId(){
    return id;
}

void Candidate::setPassword(char* password)
{
    delete[]this->password;
    this->password=new char[strlen(password)+1];
    strcpy(this->password,password);
}

void Candidate::setCv(char *cv) {
    delete [] CV;
    CV = new char [strlen(cv)+1];
    strcpy(this->CV, cv);
}
