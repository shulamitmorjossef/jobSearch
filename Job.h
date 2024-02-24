//
// Created by Student on 2/25/2024.
//

#ifndef JOBSEARCH1_JOB_H
#define JOBSEARCH1_JOB_H


#include "Candidate.h"

class Job {
public:
    Job();
    Job(char* idOfSub, int id, char* businessName, char* jobType, char* jobHours, char* jobProfession, char* experience, char* jobArea, char* address, char* age, char* jobFor, char* jobRange, char* salary, char* about);
    Job( const Job& job);
    ~Job();
    void printForEmp();
    void printForCand();
    void printSubPro(Candidate* candidate);

private:
    int id;
    char* businessName;
    char* jobType;
    char* jobHours;
    char* jobProfession;
    char* experience;
    char* jobArea;
    char* address;
    char* age;
    char* jobFor;
    char* jobRange;
    char* salary;
    char* about;
    bool status;
    int numOfSub;
    char* idOfSub;
};


#endif //JOBSEARCH1_JOB_H
