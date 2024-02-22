//
// Created by Student on 2/19/2024.
//

#ifndef JOBSEARCH_EMPLOYER_H
#define JOBSEARCH_EMPLOYER_H
#include "Job.h"


class Employer {
public:
    Employer(char* id, char* password, char* forgetPass);
    Employer(const Employer& employer );
    ~Employer();
    void printJobs();

private:
    char* id ;
    char* password ;
    char* forgetPass ;
    int jobsNum;
    Job* jobs ;

};


#endif //JOBSEARCH_EMPLOYER_H
