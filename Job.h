//
// Created by Student on 2/25/2024.
//

#ifndef JOBSEARCH1_JOB_H
#define JOBSEARCH1_JOB_H


#include "Candidate.h"

class Job {
public:
    Job();
    Job(char** idOfSub, int id, char* businessName, int jobType, int jobHours, char* jobProfession,
        int experience, int jobArea, char* address, int age, int jobFor, int jobRange, char* salary,
        char* about);
    Job( const Job& job);
    Job& operator= (const Job& job);
    ~Job();

    void printForEmp();
    void printForCand();
    void printSubPro(Candidate* candidate);

    void setJobHours(int jobHours);
    void setId(int id);
    void setBusinessName( char* businessName);
    void setJobType(int jobType);
    void setJobProfession (char* jobProfession);
    void setExperience(int experience);
    void setJobArea (int jobArea);
    void setAddress (char* address);
    void setAge (int age);
    void setJobFor(int jobFor);
    void setJobRange(int jobRange);
    void setSalary(char* salary);
    void setAbout(char* about);
    void setStatus(bool status);
    void setNumOfSub(int numOfSub);
    void setIdOfSub (char** idOfSub);

    friend void searchJob(Job* jobs, int len);
    friend void findJob(int id);
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
