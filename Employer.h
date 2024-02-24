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

    bool signUp();
    bool logIn(char* id, char* password, Employer* arr);
    bool forgetPassword(char* id, Employer* arr);
    bool addJob();
    void sortJobs();
    bool deleteJob(int id);
    void updateJob(int id);
    void subOfJOb(int id);


private:
    char* id ;
    char* password ;
    char* forgetPassQ ;
    char* forgetPassA ;
    int jobsNum;
    Job* jobs ;

};


#endif //JOBSEARCH_EMPLOYER_H
