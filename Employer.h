//
// Created by Student on 2/19/2024.
//

#ifndef JOBSEARCH_EMPLOYER_H
#define JOBSEARCH_EMPLOYER_H
#include "Job.h"


class Employer {
public:
    Employer(char* id, char* password, char* forgetPassQ, char* forgetPassA );
    Employer(const Employer& employer );
    ~Employer();
    void printJobs();
    void printDetails();

    void setID(char* id);
    void setPassword (char* password);
    void setForgetPassQ (char* forgetPassQ);
    void setForgetPassA(char* forgetPassA);
    void setJobsNum(int jobsNum);
    void setJobs(Job* jobs);



private:
    char* id ;
    char* password ;
    char* forgetPassQ ;
    char* forgetPassA ;
    int jobsNum;
    Job* jobs ;

};


#endif //JOBSEARCH_EMPLOYER_H
