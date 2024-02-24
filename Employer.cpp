//
// Created by Student on 2/25/2024.
//

#include "Employer.h"
#include <iostream>
#include <cstring>
using namespace std;

Employer::Employer(char *id, char *password, char* forgetPassQ, char* forgetPassA) {

    this-> id = new char [strlen(id)+1];
    strcpy(this->id, id);

    this-> password = new char [strlen(password)+1];
    strcpy(this->password, password);

    this-> forgetPassQ = new char [strlen(forgetPassQ)+1];
    strcpy(this->forgetPassQ, forgetPassQ);

    this-> forgetPassA = new char [strlen(forgetPassA)+1];
    strcpy(this->forgetPassA, forgetPassA);

    this->jobs = nullptr;
    this-> jobsNum = 0;
}

Employer:: Employer(const Employer& employer ){
    this-> id = new char [strlen(employer.id)+1];
    strcpy(this->id, employer.id);

    this-> password = new char [strlen(employer.password)+1];
    strcpy(this->password, employer.password);

    this-> forgetPassQ = new char [strlen(employer.forgetPassQ)+1];
    strcpy(this->forgetPassQ, employer.forgetPassQ);

    this-> forgetPassA = new char [strlen(employer.forgetPassA)+1];
    strcpy(this->forgetPassA, employer.forgetPassA);

    this->jobsNum = employer.jobsNum;

    this->jobs = new Job [employer.jobsNum];
    for(int i = 0; i < jobsNum; ++i){
        this->jobs[i] = employer.jobs[i];
    }

}

Employer::~Employer(){

    delete [] id;
    delete [] password;
    delete [] forgetPassQ ;
    delete [] forgetPassA ;
    delete [] jobs ;

}

void Employer::printJobs(){
    if(this->jobsNum == 0)
        cout << "No jobs have been posted yet\n";
    else
        for(int i = 0; i < jobsNum; ++i){
            cout << i << ".\n";
            jobs[i].printForEmp();
        }
}

void Employer:: printDetails() {
    cout << "Id: " << id << endl;
    cout << "Password: " << password << endl;
    cout << "Question: " << forgetPassQ << endl;
    cout << "Answer: " << forgetPassA << endl;
    cout << "Jobs:\n";
    this->printJobs();

}
