//
// Created by Student on 2/25/2024.
//

#include "Job.h"
#include <string>
#include <iostream>
#include <cstring>
#include <limits>
using namespace std;


Job::Job(){
    id = 1;
    businessName = NULL;
    jobProfession = NULL;
    address = NULL;
    salary = NULL;
    about = NULL;
    jobType = 1;
    jobHours = 1;
    experience = 1;
    jobArea = 1;
    age = 1;
    jobFor = 1;
    jobRange = 1;
//    for (int i = 0; i < numOfSub; ++i) {
//        idOfSub[i] = NULL;
//    }
    status = false;
    idOfSub = NULL;
    numOfSub = 0;
}

Job:: Job(int id, char* businessName, char* jobProfession, char* address,  char* salary, char* about,
          int jobType, int jobHours, int experience, int jobArea, int age, int jobFor, int jobRange){

    this->idOfSub = nullptr;
    this->id = id;
    this-> businessName = new char [strlen(businessName)+1];
    strcpy(this->businessName, businessName);

    this-> jobType = jobType;
    this-> jobHours = jobHours;

    this-> jobProfession = new char [strlen(jobProfession)+1];
    strcpy(this->jobProfession, jobProfession);

    this-> experience = experience;

    this-> jobArea = jobArea;

    this-> jobFor = jobFor;

    this-> address = new char [strlen(address)+1];
    strcpy(this->address, address);

    this-> jobRange = jobRange;

    this->salary = new char [strlen(salary)+1];
    strcpy(this->salary,salary);

    this-> about = new char [strlen(about)+1];
    strcpy(this->about, about);

    this-> age = age;

    this->status = true;

    this->numOfSub = 0;
}

Job:: Job( const Job& job){
    this->id = job.id;

    this-> businessName = new char [strlen(job.businessName)+1];
    strcpy(this->businessName, job.businessName);

    this-> jobType = job.jobType;

    this-> jobHours = job.jobHours;

    this-> jobProfession = new char [strlen(job.jobProfession)+1];
    strcpy(this->jobProfession, job.jobProfession);

    this-> experience = job.experience;

    this-> jobArea = job.jobArea;

    this-> jobFor = job.jobFor;

    this-> address = new char [strlen(job.address)+1];
    strcpy(this->address, job.address);

    this-> jobRange = job.jobRange;

    this->salary = new char [strlen(job.salary)+1];
    strcpy(this->salary,job.salary);

    this-> about = new char [strlen(job.about)+1];
    strcpy(this->about, job.about);

    this-> age = job.age;

    this->status = job.status;

    this->numOfSub = job.numOfSub;

    this->idOfSub = new char* [numOfSub];
    for(int i = 0; i< numOfSub; ++i)
    {
        strcpy(this->idOfSub[i], job.idOfSub[i]);
    }

}

Job& Job:: operator= (const Job& job){
    this->id = job.id;

    if(businessName != nullptr)
        delete [] businessName;
    this-> businessName = new char [strlen(job.businessName)+1];
    strcpy(this->businessName, job.businessName);

    this-> jobType = job.jobType;

    this-> jobHours = job.jobHours;

    if(jobProfession != nullptr)
        delete [] jobProfession;
    this-> jobProfession = new char [strlen(job.jobProfession)+1];
    strcpy(this->jobProfession, job.jobProfession);

    this-> experience = job.experience;

    this-> jobArea = job.jobArea;

    this-> jobFor = job.jobFor;

    if(address != nullptr)
        delete [] address;
    this-> address = new char [strlen(job.address)+1];
    strcpy(this->address, job.address);

    this-> jobRange = job.jobRange;

    if(salary != nullptr)
        delete [] salary;
    this->salary = new char [strlen(job.salary)+1];
    strcpy(this->salary,job.salary);


    if(about != nullptr)
        delete [] about;
    this-> about = new char [strlen(job.about)+1];
    strcpy(this->about, job.about);

    this-> age = job.age;

    this->status = job.status;

    this->numOfSub = job.numOfSub;

    for (int i = 0; i < this->numOfSub; ++i) {
        delete[] this->idOfSub[i];
    }
    delete[] this->idOfSub;

    this->idOfSub = new char*[this->numOfSub];
    for (int i = 0; i < this->numOfSub; ++i) {
        this->idOfSub[i] = new char[strlen(job.idOfSub[i]) + 1];
        strcpy(this->idOfSub[i], job.idOfSub[i]);
    }

    //return *this;
}

Job:: ~Job(){
    delete [] businessName;
    delete [] jobProfession;
    delete [] address;
    delete [] salary;
    delete [] about;
}

void Job::printForCand(){
    cout << "Business Name: " << businessName <<".\n";
    cout << "Profession: " << jobProfession << ".\n";
    cout << "Address: " << address << ".\n";
    cout << "salary: " << salary << ".\n";
    cout << "About the job: \n" << about << ".\n";
    cout << "Type of job: ";
    if(jobType == 1)
        cout << "Full time job.\n";
    else
        cout << "Part time job.\n";
    cout << "Hours of job: " ;
    if(jobHours == 1)
        cout << "Morning hours.\n";
    else
        cout << "Evening hours.\n";
    cout << "Experience required: ";
    if(experience == 1)
        cout << "Inexperienced.\n";
    else if(experience == 2)
        cout << "Up to three years.\n";
    else
        cout << "Three years or more.\n";
    cout << "Area of job: ";
    if(jobArea == 1)
        cout << "North.\n";
    else if(jobArea == 2)
        cout << "Center.\n";
    else
        cout << "South.\n";
    cout << "Age required: " ;
    if(jobArea == 1)
        cout << "Up to 18.\n";
    else if(jobArea == 2)
        cout << "18-24.\n";
    else
        cout << "24 and above.\n";
    cout << "Suitable for: " ;
    if(jobFor == 1)
    cout << "Students.\n";
    else if(jobFor == 2)
        cout << "Soldiers.\n";
    else if(jobFor == 3)
        cout << "Pupils.\n";
    else
        cout << "Not a special job.\n";
    cout << "Range: " ;
    if(jobRange == 1)
        cout << "Short term job.\n";
    else
        cout << "Long term job.\n";



}

bool Job:: getStatus(){
    return status;
}

void Job::updateJob(){
    string newValue;
    cout << "For each field enter a new value (or press Enter to skip): \n";
    cout << "Business Name: " << businessName;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] businessName;
        businessName = new char[newValue.size() + 1];
        strcpy(businessName, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Profession: " << jobProfession;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] jobProfession;
        jobProfession = new char[newValue.size() + 1];
        strcpy(jobProfession, newValue.c_str());
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
    cout << "Salary: " << salary;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] salary;
        salary= new char[newValue.size() + 1];
        strcpy(salary, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "About the job: " << about;
    getline(cin, newValue);
    if(!newValue.empty()) {
        delete [] about;
        about = new char[newValue.size() + 1];
        strcpy(about, newValue.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "The job is: ";
    if(jobType == 1)
        cout << "Full time job.\n";
    else
        cout << "Part time job.\n";
    cout << "Press 1/2/enter\nFull time job (1)\nPart time job (2)\n";
    getline(cin, newValue);
    if(!newValue.empty()) {
        jobType =  stoi(newValue);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Hours of job: " ;
    if(jobHours == 1)
        cout << "Morning hours.\n";
    else
        cout << "Evening hours.\n";
    cout << "Press 1/2/enter\nMorning hours (1)\nEvening hours (2)\n";
    getline(cin, newValue);
    if(!newValue.empty()) {
        jobHours =  stoi(newValue);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Experience required: ";
    if(experience == 1)
        cout << "Inexperienced.\n";
    else if(experience == 2)
        cout << "Up to three years.\n";
    else
        cout << "Three years or more.\n";
    cout << "Press 1/2/3/enter\nInexperienced (1)\nUp to three years (2)\nThree years or more (3)\n";
    getline(cin, newValue);
    if(!newValue.empty()) {
        experience =  stoi(newValue);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Area of job: ";
    if(jobArea == 1)
        cout << "North.\n";
    else if(jobArea == 2)
        cout << "Center.\n";
    else
        cout << "South.\n";
    cout << "Press 1/2/3/enter\nNorth (1)\nCenter (2)\nSouth (3)\n";
    getline(cin, newValue);
    if(!newValue.empty()) {
        jobArea =  stoi(newValue);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Age required: " ;
    if(jobArea == 1)
        cout << "Up to 18.\n";
    else if(jobArea == 2)
        cout << "18-24.\n";
    else
        cout << "24 and above.\n";
    cout << "Press 1/2/3/enter\nUp to 18 (1)\n18-24 (2)\n24 and above (3)\n";
    getline(cin, newValue);
    if(!newValue.empty()) {
        age =  stoi(newValue);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Suitable for: " ;
    if(jobFor == 1)
        cout << "Students.\n";
    else if(jobFor == 2)
        cout << "Soldiers.\n";
    else if(jobFor == 3)
        cout << "Pupils.\n";
    else
        cout << "Not a special job.\n";
    cout << "Press 1/2/3/4/enter\nStudents (1)\nSoldiers (2)\nPupils (3)\nElse (4)\n";
    getline(cin, newValue);
    if(!newValue.empty()) {
        jobFor =  stoi(newValue);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Range: " ;
    if(jobRange == 1)
        cout << "Short term job.\n";
    else
        cout << "Long term job.\n";
    cout << "Press 1/2/enter\nShort term job (1)\nLong term job (2)\n";
    getline(cin, newValue);
    if(!newValue.empty()) {
        jobRange =  stoi(newValue);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(!status) {
        cout << "The job is not available, click 1 to post it again or enter to continue\n";
        getline(cin, newValue);
        if(!newValue.empty()) {
            status = true;
        }
    }
}

void Job::addSub(char *id) {
    char** tmp = new char* [numOfSub + 1];
    for (int i = 0; i < numOfSub; ++i) {
        tmp[i] = new char [strlen(idOfSub[i])+1];
        strcpy(tmp[i], idOfSub[i]);
    }
    tmp[numOfSub] = new char [strlen(id)+1];
    strcpy(tmp[numOfSub], id);
    delete [] idOfSub;
    idOfSub = tmp;
    numOfSub++;
}

void Job::deleteSub(char *id) {

    char** tmp = new char* [numOfSub -1];
    int index = 0;
    while (strcmp(idOfSub[index], id) != 0) {
        tmp[index] = new char[strlen(idOfSub[index])];
        strcpy(tmp[index], idOfSub[index]);
        index++;
    }

    for(int i = index; i < numOfSub; ++i) {
        if(strcmp(idOfSub[i], id) != 0) {
            tmp[i] = new char[strlen(idOfSub[i+1])];
            strcpy(tmp[i], idOfSub[i+1]);
        }
    }
    delete [] idOfSub;
    idOfSub = tmp;
    numOfSub--;
}

void Job::printForEmp() {
    cout << "Status: " ;
    if( status )
        cout << "Available.\n";
    else
        cout << "Unavailable.\n";
    this->printForCand();
}

void Job::printSubPro(Candidate* candidate, int len) {
    for(int i = 0; i < numOfSub; ++i)
        for(int j = 0; j < len; ++j)
            if(strcmp(idOfSub[i], candidate[j].getId()) == 0) {
                cout << i + 1 << ".\n";
                candidate[j].printProfile();
            }
}

void Job::setId(int id)
{
    this->id=id;

}
void Job::setBusinessName( char* businessName)
{
    delete[]this->businessName;
    this->businessName=new char[strlen(businessName)+1];
    strcpy(this->businessName,businessName);
}
void Job::setJobType(int jobType)
{
    this->jobType= jobType;
}
void Job::setJobHours(int jobHours)
{
    this->jobHours=jobHours;
}
void Job::setJobProfession (char* jobProfession)
{
    delete[]this->jobProfession;
    this->jobProfession=new char[strlen(jobProfession)+1];
    strcpy(this->jobProfession,jobProfession);
}
void Job::setExperience(int experience)
{
    this->experience= experience;
}
void Job::setJobArea (int jobArea)
{
    this->jobArea=jobArea;
}
void Job::setAddress (char* address)
{
    delete[]this->address;
    this->address=new char[strlen(address)+1];
    strcpy(this->address,address);
}
void Job::setAge (int age)
{
    this->age=age;
}
void Job::setJobFor(int jobFor)
{
    this->jobFor=jobFor;
}
void Job::setJobRange(int jobRange)
{
    this->jobRange=jobRange;
}
void Job::setSalary(char* salary)
{
    delete[]this->salary;
    this->salary=new char[strlen(salary)+1];
    strcpy(this->salary,salary);
}
void Job::setAbout(char* about)
{
    delete[]this->about;
    this->about=new char[strlen(about)+1];
    strcpy(this->about,about);
}
void Job::setStatus(bool status)
{
    this->status=status;
}
void Job::setNumOfSub(int numOfSub)
{
    this->numOfSub=numOfSub;
}

