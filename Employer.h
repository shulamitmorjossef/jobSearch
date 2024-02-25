//
// Created by Student on 2/25/2024.
//

#ifndef JOBSEARCH1_EMPLOYER_H
#define JOBSEARCH1_EMPLOYER_H
#include "Job.h"

class Employer {
public:
    Employer(char* id, char* password, char* forgetPassQ, char* forgetPassA );
    Employer(const Employer& employer );
    ~Employer();
    void printJobs();
    void printDetails();

    bool signUp();         //rina
    bool logIn(char* id, char* password, Employer* arr);
    bool forgetPassword(char* id, Employer* arr);
    bool addJob();          // aderet
    void sortJobs();
    bool deleteJob(int id);
    void updateJob(int id);
    void subOfJOb(int id);

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




#endif //JOBSEARCH1_EMPLOYER_H
