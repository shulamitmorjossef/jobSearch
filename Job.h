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
    void setJobHours(char* jobHours);
    void setId(int id);
    void setBusinessName( char* businessName);
    void setJobType(char* jobType);
    void setJobProfession (char* jobProfession);
    void setExperience(char* experience);
    void setJobArea (char* jobArea);
    void setAddress (char* address);
    void setAge (char* age);
    void setJobFor(char* jobFor);
    void setJobRange(char* jobRange);
    void setSalary(char* salary);
    void setAbout(char* about);
    void setStatus(bool status);
    void setNumOfSub(int numOfSub);
    void setIdOfSub (char* idOfSub);

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
