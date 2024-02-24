//
// Created by Student on 2/19/2024.
//

#ifndef JOBSEARCH_CANDIDATE_H
#define JOBSEARCH_CANDIDATE_H
#include "Apply.h"

class Candidate {
public:
    Candidate(char* id, char* password, char* forgetPassQ, char* forgetPassA, char* fName = nullptr,
              char* lName = nullptr, char* email = nullptr, char* phone = nullptr, int age = 0,
              char* address = nullptr, char* profession = nullptr, char* about = nullptr);

    Candidate(const Candidate& candidate);
    ~Candidate();
    void printSub();
    void printProfile();
    void printDetails();



private:
    char* id ;
    char* password ;
    char* forgetPassQ ;
    char* forgetPassA ;
    char* fName;
    char* lName;
    char* email;
    char* phone;
    int age;
    char* address;
    char* profession;
    char* about;
    char* CV;
    Apply* submissions;
    int numOfSub;




};


#endif //JOBSEARCH_CANDIDATE_H
