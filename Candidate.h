//
// Created by Student on 2/25/2024.
//

#ifndef JOBSEARCH1_CANDIDATE_H
#define JOBSEARCH1_CANDIDATE_H


#include "Apply.h"

class Candidate {
public:
    Candidate(char* id, char* password, char* forgetPassQ, char* forgetPassA, char* fName = nullptr,
              char* lName = nullptr, char* email = nullptr, char* phone = nullptr, int age = 0,
              char* address = nullptr, char* profession = nullptr, char* about = nullptr);

    Candidate(const Candidate& candidate);
    ~Candidate();
    void printSub();                // sahar
    void printProfile();
    void printDetails();

    bool signUp();              //rina
    bool logIn(char* id, char* password, Candidate* arr);
    bool forgetPassword(char* id, Candidate* arr);
    void searchJob();
    bool addApply(int id);          // sahar
    void sortSub();
    bool deleteApply(int id);        // sahar
    void updateDetails();




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


#endif //JOBSEARCH1_CANDIDATE_H
