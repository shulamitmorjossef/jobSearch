//
// Created by Student on 2/19/2024.
//

#ifndef JOBSEARCH_CANDIDATE_H
#define JOBSEARCH_CANDIDATE_H
#include "Apply.h"

class Candidate {
public:
    Candidate(char* id, char* password, char* forgetPass, char* fName, char* lName, char* email, char* phone, int age, char* address, char* profession, char* about);
    Candidate(const Candidate& candidate);
    ~Candidate();


private:
    char* id ;
    char* password ;
    char* forgetPass ;
    char* fName;
    char* lName;
    char* email;
    char* phone;
    int age;
    char* address;
    char* profession;
    char* about;
    Apply* submissions;
    int numOfSub;




};


#endif //JOBSEARCH_CANDIDATE_H
