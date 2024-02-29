//
// Created by Student on 2/25/2024.
//

#include "Candidate.h"
#include <cstring>
#include <string>
#include <limits>
#include <iostream>
using namespace std;


Candidate::Candidate(){

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

    this->submissions = nullptr;

    this->numOfSub = 0;

    this->CV = nullptr;
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
//    delete [] id;
    this-> id = new char [strlen(candidate.id)+1];
    strcpy(this->id, candidate.id);
  //  delete[] password;
    this-> password = new char [strlen(candidate.password)+1];
    strcpy(this->password, candidate.password);
//    delete[]forgetPassQ;
    this-> forgetPassQ = candidate.forgetPassQ;
//    delete[] forgetPassA;
    this-> forgetPassA = new char [strlen(candidate.forgetPassA)+1];
    strcpy(this->forgetPassA, candidate.forgetPassA);
//    delete[] fName;
    this-> fName = new char [strlen(candidate.fName)+1];
    strcpy(this->fName, candidate.fName);
//    delete[] lName;
    this-> lName = new char [strlen(candidate.lName)+1];
    strcpy(this->lName, candidate.lName);
//    delete[] email;
    this-> email = new char [strlen(candidate.email)+1];
    strcpy(this->email, candidate.email);
//    delete[] phone;
    this-> phone = new char [strlen(candidate.phone)+1];
    strcpy(this->phone, candidate.phone);
//    delete[] address;
    this-> address = new char [strlen(candidate.address)+1];
    strcpy(this->address, candidate.address);
//    delete[] profession;
    this-> profession = new char [strlen(candidate.profession)+1];
    strcpy(this->profession, candidate.profession);
//    delete[] about;
    this-> about = new char [strlen(candidate.about)+1];
    strcpy(this->about, candidate.about);
//    delete[] CV;
//    this-> CV = new char [strlen(candidate.CV)+1];
//    strcpy(this->CV, candidate.CV);

    this-> age = age;

    this->numOfSub = candidate.numOfSub;
//    delete[] submissions;
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
}

void Candidate::updateDetails() {
    string newValue;

    cout << "For each field enter a new value (or press Enter to skip): \n";
    cout << "First name: " << fName ;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] fName;
        fName = new char[newValue.size() + 1];
        strcpy(fName, newValue.c_str());
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
        delete [] email;
        email = new char[newValue.size() + 1];
        strcpy(email, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Phone: " << phone;
    getline(cin, newValue);
    if(!newValue.empty()) {
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
        age =  stoi(newValue);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
bool Candidate::addApply(int id) {
    Apply a1(id);
    Apply* tmp= new Apply [numOfSub + 1];
    for (int i = 0; i <numOfSub ; ++i) {
        tmp[i] = submissions[i];
    }
    delete [] submissions;
    submissions=tmp;
    submissions[numOfSub]=a1;
    submissions++;
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

void Candidate::printSub() {
    if(numOfSub == 0)
        cout << "You have not applied yet\n";
    else
        for(int i = 0; i < numOfSub; ++i){
            cout << i +1 << ".\n";
            submissions[i].print();
        }
}

void Candidate:: printSortSub(){
    if(numOfSub == 0){
//    if (submissions==NULL){
        cout<<"You have no submissions \n";
    }

    cout << "The apply In process: \n";
    for (int i = 0; i < numOfSub ; ++i) {
        if (submissions[i].isStatus()) {
            submissions[i].print();
        }
    }
    cout << "The apply Postponed: \n";
    for (int i = 0; i < numOfSub ; ++i) {
        if (!submissions[i].isStatus()) {
            submissions[i].print();
        }
    }
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

void Candidate::printDetails() {
    cout << "Id: " << id << endl;
    cout << "Password: " << password << endl;
    cout << "Question: " << forgetPassQ << endl;
    cout << "Answer: " << forgetPassA << endl;
    cout << "First name: " << fName << endl;
    cout << "Last name: " << lName << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "Age: " << age << endl;
    cout << "Address: " << address << endl;
    cout << "Profession: " << profession << endl;
    cout << "About: " << about << endl;
    cout << "Submissions: \n";
    this->printSub();
}
char* Candidate:: getId(){
    return id;
}
void Candidate::setID(char* id)
{
    delete[]this->id;
    this->id=new char[strlen(id)+1];
    strcpy(this->id,id);
}
void Candidate::setPassword(char* password)
{
    delete[]this->password;
    this->password=new char[strlen(password)+1];
    strcpy(this->password,password);
}
void Candidate::setForgetPassQ(int forgetPassQ)
{
    this->forgetPassQ= forgetPassQ;
}
void Candidate::setForgetPassA (char* forgetPassA)
{
    delete[]this->forgetPassA;
    this->forgetPassA=new char[strlen(forgetPassA)+1];
    strcpy(this->forgetPassA,forgetPassA);

}
void Candidate::setFName(char* fName)
{
    delete[]this->fName;
    this->fName=new char[strlen(fName)+1];
    strcpy(this->fName,fName);
}
void Candidate::setLName(char* lName)
{
    delete[]this->lName;
    this->lName=new char[strlen(lName)+1];
    strcpy(this->lName,lName);
}
void Candidate::setEmail(char* email)
{
    delete[]this->email;
    this->email=new char[strlen(email)+1];
    strcpy(this->email,email);
}
void Candidate::setPhone(char* phone)
{
    delete[]this->phone;
    this->phone=new char[strlen(phone)+1];
    strcpy(this->phone,phone);

}
void Candidate::setAge(int age)
{
    this->age=age;
}
void Candidate::setAddress(char* address)
{
    delete[]this->address;
    this->address=new char[strlen(address)+1];
    strcpy(this->address,address);

}
void Candidate::setProfession(char* profession)
{
    delete[]this->profession;
    this->profession=new char[strlen(profession)+1];
    strcpy(this->profession,profession);

}
void Candidate::setAbout(char* about)
{
    delete[]this->about;
    this->about=new char[strlen(about)+1];
    strcpy(this->about,about);

}
