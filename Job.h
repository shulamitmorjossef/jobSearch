//
// Created by Student on 2/25/2024.
//

#ifndef JOBSEARCH1_JOB_H
#define JOBSEARCH1_JOB_H


#include "Candidate.h"

class Job {
public:

    Job();
    Job(int id, char* businessName, char* jobProfession, char* address,  char* salary, char* about,
        int jobType, int jobHours, int experience, int jobArea, int age, int jobFor, int jobRange);
    Job( const Job& job);
    Job& operator= (const Job& job);
    ~Job();


    void addSub(char* id);
    void deleteSub(char* id);
    void printForEmp();
    void printForCand();
    void printSubPro(Candidate* candidate, int len);
    void updateJob();
    bool getStatus();
    void setStatus(bool status);
    void setBusinessName( char* businessName);
    void setJobProfession (char* jobProfession);
    void setAddress (char* address);
    void setSalary(char* salary);
    void setAbout(char* about);


    friend class ManagementSystem;


private:
    int id;
    char* businessName;
    char* jobProfession;
    char* address;
    char* salary;
    char* about;

    int jobType;
    int jobHours;
    int experience;
    int jobArea;
    int age;
    int jobFor;
    int jobRange;

    bool status;
    int numOfSub;
    char** idOfSub;
};


#endif //JOBSEARCH1_JOB_H
