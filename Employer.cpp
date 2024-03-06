//
// Created by Student on 2/25/2024.
//

#include "Employer.h"
#include <iostream>
#include <cstring>
#include <limits>

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


void Employer:: printJobs(){
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
    char businessName [200];
    char jobProfession [200];
    char address [200];
    char salary [200];
    char about [200];
    int jobType=-2;
    int jobHours=-2;
    int experience=-2;
    int jobArea=-2;
    int age=-2;
    int jobFor=-2;
    int jobRange=-2;
//    bool status;
    id = num + 1;

    cout << "Enter business name:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(businessName,100);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(businessName, 100);
    }

    cout << "Enter job profession:\n";
    cin.getline(jobProfession,100);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(jobProfession, 100);
    }

    cout << "Enter business address:\n";
    cin.getline(address,100);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(address, 100);
    }

    cout << "Enter job's salary:\n";
    cin.getline(salary,100);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(salary, 100);
    }
    cout << "Tell about the job:\n";
    cin.getline(about,100);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(about, 100);
    }
    cout << "The job is:\nFull time job (1)\nPart time job (2)\n";
    while (!(cin >> jobType) || (jobType != 1 && jobType != 2)|| cin.peek() != '\n') {
        cout << "Invalid input. Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "The job is:\nIn the morning hours (1)\nIn the evening hours (2)\n";
    while (!(cin >> jobHours) || (jobHours != 1 && jobHours != 2)|| cin.peek() != '\n') {
        cout << "Invalid input. Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "The position requires experience of:\nInexperienced (1)\nUp to three years (2)\nThree years or more (3)\n";
    while (!(cin >> experience) || (experience != 1 && experience != 2 && experience != 3)|| cin.peek() != '\n') {
        cout << "Invalid input. Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "The job is in the:\nNorth (1)\nCenter (2)\nSouth (3)\n";
    while (!(cin >> jobArea) || (jobArea != 1 && jobArea != 2 && jobArea != 3)|| cin.peek() != '\n') {
        cout << "Invalid input. Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "The job for ages:\nUp to 18 (1)\n18-24 (2)\n24 and above (3)\n";
    while (!(cin >> age) || (age != 1 && age != 2 && age != 3)|| cin.peek() != '\n') {
        cout << "Invalid input. Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "The job is suitable for:\nStudents (1)\nSoldiers (2)\nPupils (3)\nElse (4)\n";
    while (!(cin >> jobFor) || (jobFor != 1 && jobFor != 2 && jobFor != 3 && jobFor != 4)|| cin.peek() != '\n') {
        cout << "Invalid input. Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "The job is:\nShort term job (1)\nLong term job (2)\n";
    while (!(cin >> jobRange) || (jobRange != 1 && jobRange != 2 )|| cin.peek() != '\n') {
        cout << "Invalid input. Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Job job(id, businessName, jobProfession, address, salary, about, jobType, jobHours, experience, jobArea, age, jobFor, jobRange);
    Job* tmp = new Job[jobsNum+1];
    for(int i = 0; i < jobsNum; ++i)
        tmp[i] = this->jobs[i];
    tmp[jobsNum] = job;
    delete [] this->jobs;
    this->jobs = tmp;
    jobsNum++;
    job.printForCand();
    cout << "--------------------------------------------------------------------------------------------------------------\n";
    cout << "Job has been successfully posted\n";
    cout << "--------------------------------------------------------------------------------------------------------------\n";
    return true;
}

void Employer:: sortJobs() {
    if (this->jobsNum == 0) {
        cout << "No jobs have been posted yet\n";
        cout
                << "--------------------------------------------------------------------------------------------------------------\n";
    } else {
        cout << "Available jobs:\n";
        for (int i = 0; i < jobsNum; ++i) {
            if (jobs[i].getStatus())
                jobs[i].printForCand();
        }

        cout << "\nUnavailable jobs:\n";
        for (int i = 0; i < jobsNum; ++i) {
            if (!jobs[i].getStatus())
                jobs[i].printForCand();
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------------\n";
}

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

void Employer::setPassword (char* password)
{
    delete[]this->password;
    this->password=new char[strlen(password)+1];
    strcpy(this->password,password);
}

