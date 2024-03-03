//
// Created by Student on 2/25/2024.
//

#include "Employer.h"
#include <iostream>
#include <cstring>
using namespace std;

Employer:: Employer(){
    this->id = nullptr;
    this->password = nullptr;
    this->forgetPassQ = 0;
    this->forgetPassA = nullptr;
    this->jobsNum = 0;
    this->jobs = nullptr;

}

Employer::Employer(char *id, char *password, int forgetPassQ, char* forgetPassA) {

    this-> id = new char [strlen(id)+1];
    strcpy(this->id, id);

    this-> password = new char [strlen(password)+1];
    strcpy(this->password, password);

    this-> forgetPassQ = forgetPassQ;

    this-> forgetPassA = new char [strlen(forgetPassA)+1];
    strcpy(this->forgetPassA, forgetPassA);

    this->jobs = nullptr;
    this-> jobsNum = 0;

}

Employer &Employer::operator=(const Employer &employer) {
    delete [] id;
    this-> id = new char [strlen(employer.id)+1];
    strcpy(this->id, employer.id);
    delete [] password;
    this-> password = new char [strlen(employer.password)+1];
    strcpy(this->password, employer.password);

    this-> forgetPassQ = employer.forgetPassQ;
    delete [] forgetPassA;
    this-> forgetPassA = new char [strlen(employer.forgetPassA)+1];
    strcpy(this->forgetPassA, employer.forgetPassA);

    this->jobsNum = employer.jobsNum;
    delete [] jobs;
    this->jobs = new Job [employer.jobsNum];
    for(int i = 0; i < jobsNum; ++i){
        this->jobs[i] = employer.jobs[i];
    }
}

Employer:: Employer(const Employer& employer ){
    this-> id = new char [strlen(employer.id)+1];
    strcpy(this->id, employer.id);

    this-> password = new char [strlen(employer.password)+1];
    strcpy(this->password, employer.password);

    this-> forgetPassQ = employer.forgetPassQ;

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

    delete [] forgetPassA ;
    delete [] jobs ;

}



void Employer:: printDetails() {
    cout << "Id: " << id << endl;
    cout << "Password: " << password << endl;
    cout << "Question: " << forgetPassQ << endl;
    cout << "Answer: " << forgetPassA << endl;
    cout << "Jobs:\n";
    this->printJobs();

}

void Employer::printJobs(){
    if(this->jobsNum == 0)
        cout << "No jobs have been posted yet\n";
    else
        for(int i = 0; i < jobsNum; ++i){
            cout << i+1 << ".\n";
            jobs[i].printForEmp();
        }
}
bool Employer:: addJob(int num){
    int id;
    char businessName [20];
    char jobProfession [20];
    char address [20];
    char salary [20];
    char about [200];
    int jobType;
    int jobHours;
    int experience;
    int jobArea;
    int age;
    int jobFor;
    int jobRange;
    bool status;
    id = num + 1;

    cout << "Enter business name:\n";
    cin >> businessName;

    cout << "Enter job profession:\n";
    cin >> jobProfession;

    cout << "Enter business address:\n";
    cin >> address ;

    cout << "Enter job's salary:\n";
    cin >> salary ;
    cout << "Tell about the job:\n";
    cin >> about ;
    cout << "The job is:\nFull time job (1)\nPart time job (2)\n";
    cin >> jobType;
    cout << "The job is:\nIn the morning hours (1)\nIn the evening hours (2)\n";
    cin >> jobHours;
    cout << "The position requires experience of:\nInexperienced (1)\nUp to three years (2)\nThree years or more (3)\n";
    cin >> experience;
    cout << "The job is in the:\nNorth (1)\nCenter (2)\nSouth (3)\n";
    cin >> jobArea;
    cout << "The job for ages:\nUp to 18 (1)\n18-24 (2)\n24 and above (3)\n";
    cin >> age;
    cout << "The job is suitable for:\nStudents (1)\nSoldiers (2)\nPupils (3)\nElse (4)\n";
    cin >> jobFor;
    cout << "The job is:\nShort term job (1)\nLong term job (2)\n";
    cin >> jobRange;
    status = true;
    Job job(id, businessName, jobProfession, address, salary, about, jobType, jobHours, experience, jobArea, age, jobFor, jobRange);
    Job* tmp = new Job[jobsNum+1];
    for(int i = 0; i < jobsNum; ++i)
        tmp[i] = this->jobs[i];
    tmp[jobsNum] = job;
//    for(int i = 0 ; i < jobsNum; ++i)
//        delete jobs[i];
    delete [] this->jobs;
    this->jobs = tmp;
    jobsNum++;
    job.printForCand();
    return true;
}
void Employer::  sortJobs() {
    if (this->jobsNum == 0)
        cout << "No jobs have been posted yet\n";
    else {
        cout << "Available jobs:\n";
        for (int i = 0; i < jobsNum; ++i) {
            if (jobs[i].getStatus())
                jobs[i].printForCand();
        }
        cout << "Unavailable jobs:\n";
        for (int i = 0; i < jobsNum; ++i) {
            if (!jobs[i].getStatus())
                jobs[i].printForCand();
        }
    }
}            //0 1 2 3     0 1 3
bool Employer:: deleteJob(int index){
    Job *tmp = new Job[jobsNum - 1];
    for (int i = 0; i < index; ++i)
        tmp[i] = jobs[i];
    for (int i = index + 1; i < jobsNum; ++i)
        tmp[i-1] = jobs[i];
    delete [] jobs;
    jobs = tmp;
    jobsNum--;
    return true;
}



void Employer::setID(char* id)
{
    delete[]this->id;
    this->id=new char[strlen(id)+1];
    strcpy(this->id,id);
}
void Employer::setPassword (char* password)
{
    delete[]this->password;
    this->password=new char[strlen(password)+1];
    strcpy(this->password,password);
}
void Employer::setForgetPassQ (int forgetPassQ)
{
    this->forgetPassQ= forgetPassQ;
}
void Employer::setForgetPassA(char* forgetPassA)
{
    delete[]this->forgetPassA;
    this->forgetPassA=new char[strlen(forgetPassA)+1];
    strcpy(this->forgetPassA,forgetPassA);

}
void Employer::setJobsNum(int jobsNum)
{
    this->jobsNum=jobsNum;

}
//void Employer::setJobs(Job* jobs)
//{
//
//}
