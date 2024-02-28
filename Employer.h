//
// Created by Student on 2/25/2024.
//

#ifndef JOBSEARCH1_EMPLOYER_H
#define JOBSEARCH1_EMPLOYER_H
#include "Job.h"

class Employer {
public:
    Employer();
    Employer(char* id, char* password, int forgetPassQ, char* forgetPassA );
    Employer(const Employer& employer );
    Employer& operator= (const Employer& employer);
    ~Employer();
    void printDetails();

    void printJobs();
    bool addJob(int id);          // aderet
    void sortJobs();

    bool deleteJob(int index);

    void updateJob(int id);
    void subOfJOb(int id);

    void setID(char* id);
    void setPassword (char* password);
    void setForgetPassQ (int forgetPassQ);
    void setForgetPassA(char* forgetPassA);
    void setJobsNum(int jobsNum);
    void setJobs(Job* jobs);

    friend class ManagementSystem;


private:
    char* id ;
    char* password ;
    int forgetPassQ ;
    char* forgetPassA ;
    int jobsNum;
    Job* jobs ;

};




#endif //JOBSEARCH1_EMPLOYER_H
