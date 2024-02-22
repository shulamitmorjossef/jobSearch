//
// Created by Student on 2/19/2024.
//

#include "Employer.h"
#include <iostream>
#include <cstring>
using namespace std;

Employer::Employer(char *id, char *password, char *forgetPass) {

    this-> id = new char [strlen(id)+1];
    strcpy(this->id, id);

    this-> password = new char [strlen(password)+1];
    strcpy(this->password, password);

    this-> forgetPass = new char [strlen(forgetPass)+1];
    strcpy(this->forgetPass, forgetPass);

    this->jobs = nullptr;
    this-> jobsNum = 0;
}

Employer:: Employer(const Employer& employer ){
    this-> id = new char [strlen(employer.id)+1];
    strcpy(this->id, employer.id);

    this-> password = new char [strlen(employer.password)+1];
    strcpy(this->password, employer.password);

    this-> forgetPass = new char [strlen(employer.forgetPass)+1];
    strcpy(this->forgetPass, employer.forgetPass);

    this->jobsNum = employer.jobsNum;

    this->jobs = new Job [employer.jobsNum];
    for(int i = 0; i < jobsNum; ++i){
        this->jobs[i] = employer.jobs[i];
    }

}

Employer::~Employer(){

    delete [] id;
    delete [] password;
    delete [] forgetPass ;
//    for( int i = 0; i< jobsNum; ++i){
//        delete jobs[i];
//
//    }

}

void Employer::printJobs(){
    for(int i = 0; i < jobsNum; ++i){
        jobs[i].print();
    }
}