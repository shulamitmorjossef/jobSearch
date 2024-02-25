//
// Created by Student on 2/25/2024.
//

#include "Job.h"
#include <iostream>
#include <cstring>
using namespace std;


Job::Job(){
    char* businessName = nullptr;
    char* jobType = nullptr;
    char* jobHours = nullptr;
    char* jobProfession = nullptr;
    char* experience = nullptr;
    char* jobArea = nullptr;
    char* address = nullptr;
    char* age = nullptr;
    char* jobFor = nullptr;
    char* jobRange = nullptr;
    char* salary = nullptr;
    char* about = nullptr;
    char* idOfSub = nullptr;
    bool status = false;
    int numOfSub = 0;
}

Job::Job(char* idOfSub, int id, char* businessName, char* jobType, char* jobHours, char* jobProfession, char* experience, char* jobArea, char* address, char* age, char* jobFor, char* jobRange, char* salary, char* about){
    this->idOfSub = nullptr;
    this->id = id;
    this-> businessName = new char [strlen(businessName)+1];
    strcpy(this->businessName, businessName);

    this-> jobType = new char [strlen(jobType)+1];
    strcpy(this->jobType, jobType);

    this-> jobHours = new char [strlen(jobHours)+1];
    strcpy(this->jobHours, jobHours);

    this-> jobProfession = new char [strlen(jobProfession)+1];
    strcpy(this->jobProfession, jobProfession);

    this-> experience = new char [strlen(experience)+1];
    strcpy(this->experience, experience);

    this-> jobArea = new char [strlen(jobArea)+1];
    strcpy(this->jobArea, jobArea);

    this-> jobFor = new char [strlen(jobFor)+1];
    strcpy(this->jobFor, jobFor);

    this-> address = new char [strlen(address)+1];
    strcpy(this->address, address);

    this-> jobRange = new char [strlen(jobRange)+1];
    strcpy(this->jobRange, jobRange);

    this->salary = new char [strlen(salary)+1];
    strcpy(this->salary,salary);

    this-> about = new char [strlen(about)+1];
    strcpy(this->about, about);

    this-> age = new char [strlen(age)+1];
    strcpy(this->age, age);

    this->status = true;

    this->numOfSub = 0;
}

Job:: Job( const Job& job){

    this->id = job.id;

    this-> businessName = new char [strlen(job.businessName)+1];
    strcpy(this->businessName, job.businessName);

    this-> jobType = new char [strlen(job.jobType)+1];
    strcpy(this->jobType, job.jobType);

    this-> jobHours = new char [strlen(job.jobHours)+1];
    strcpy(this->jobHours, job.jobHours);

    this-> jobProfession = new char [strlen(job.jobProfession)+1];
    strcpy(this->jobProfession, job.jobProfession);

    this-> experience = new char [strlen(job.experience)+1];
    strcpy(this->experience, job.experience);

    this-> jobArea = new char [strlen(job.jobArea)+1];
    strcpy(this->jobArea, job.jobArea);

    this-> jobFor = new char [strlen(job.jobFor)+1];
    strcpy(this->jobFor, job.jobFor);

    this-> address = new char [strlen(job.address)+1];
    strcpy(this->address, job.address);

    this-> jobRange = new char [strlen(job.jobRange)+1];
    strcpy(this->jobRange, job.jobRange);

    this->salary = new char [strlen(job.salary)+1];
    strcpy(this->salary,job.salary);

    this-> about = new char [strlen(job.about)+1];
    strcpy(this->about, job.about);

    this-> age = new char [strlen(job.age)+1];
    strcpy(this->age, job.age);

    this->status = job.status;

    this->numOfSub = job.numOfSub;

    this->idOfSub = new char [numOfSub];
    for(int i = 0; i< numOfSub; ++i){
        this->idOfSub[i] = job.idOfSub[i];
    }
}

Job:: ~Job(){
    delete [] businessName;
    delete [] jobType;
    delete [] jobHours;
    delete [] jobProfession;
    delete [] experience;
    delete [] jobArea;
    delete [] address;
    delete [] age;
    delete [] jobFor;
    delete [] jobRange;
    delete [] salary;
    delete [] about;
}

void Job::printForCand(){
    cout << "Business Name: " << businessName << ".\n";
    cout << "Type of job: " << jobType << ".\n";
    cout << "Hours of job: " << jobHours << ".\n";
    cout << "Profession: " << jobProfession << ".\n";
    cout << "Experience required: " << experience << ".\n";
    cout << "Area of job: " << jobArea << ".\n";
    cout << "Address: " << address << ".\n";
    cout << "Age required: " << age << ".\n";
    cout << "Suitable for: " << jobFor << ".\n";
    cout << "Range: " << jobRange << ".\n";
    cout << "salary: " << salary << ".\n";
    cout << "About the job: \n" << about << ".\n";


}

void Job::printForEmp() {
    cout << "Status: " << status << ".\n";
    this->printForCand();
}

//void Job::printSubPro(Candidate* candidate) {
//    candidate->printProfile();
//}

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
void Job::setJobType(char* jobType)
{
    delete[]this->jobType;
    this->jobType=new char[strlen(jobType)+1];
    strcpy(this->jobType,jobType);
}
void Job::setJobHours(char* jobHours)
{
    delete[]this->jobHours;
    this->jobHours=new char[strlen(jobHours)+1];
    strcpy(this->jobHours,jobHours);
}

void Job::setJobProfession (char* jobProfession)
{
    delete[]this->jobProfession;
    this->jobProfession=new char[strlen(jobProfession)+1];
    strcpy(this->jobProfession,jobProfession);
}
void Job::setExperience(char* experience)
{
    delete[]this->experience;
    this->experience=new char[strlen(experience)+1];
    strcpy(this->experience,experience);
}
void Job::setJobArea (char* jobArea)
{
    delete[]this->jobArea;
    this->jobArea=new char[strlen(jobArea)+1];
    strcpy(this->jobArea,jobArea);
}
void Job::setAddress (char* address)
{
    delete[]this->address;
    this->address=new char[strlen(address)+1];
    strcpy(this->address,address);
}
void Job::setAge (char* age)
{
    delete[]this->age;
    this->age=new char[strlen(age)+1];
    strcpy(this->age,age);
}
void Job::setJobFor(char* jobFor)
{
    delete[]this->jobFor;
    this->jobFor=new char[strlen(jobFor)+1];
    strcpy(this->jobFor,jobFor);
}
void Job::setJobRange(char* jobRange)
{
    delete[]this->jobRange;
    this->jobRange=new char[strlen(jobRange)+1];
    strcpy(this->jobRange,jobRange);
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
void Job::setIdOfSub (char* idOfSub)
{
    delete[]this->idOfSub;
    this->idOfSub=new char[strlen(idOfSub)+1];
    strcpy(this->idOfSub,idOfSub);
}