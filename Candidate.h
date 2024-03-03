//
// Created by Student on 2/25/2024.
//

#ifndef JOBSEARCH1_CANDIDATE_H
#define JOBSEARCH1_CANDIDATE_H


#include "Apply.h"

class Candidate {
public:
    Candidate();
    Candidate(char* id, char* password, int forgetPassQ, char* forgetPassA, char* fName,
              char* lName, char* email, char* phone , int age,
              char* address, char* profession, char* about);

    Candidate(const Candidate& candidate);
    Candidate& operator= (const Candidate& candidate);
    ~Candidate();
    void printSub();
    void printProfile();
    void printDetails();
    void addApply(int id);
    void printSortSub();
    int deleteApply(int index);
    void updateDetails();
    void setPassword(char* password);
    char* getId();

    void setID(char* id);
    void setForgetPassQ(int forgetPassQ);
    void setForgetPassA (char* forgetPassA);
    void setFName(char* fName);
    void setLName(char* lName);
    void setEmail(char* email);
    void setPhone(char* phone);
    void setAge(int age);
    void setAddress(char* address);
    void setProfession(char* profession);
    void setAbout(char* about);

    void setCv(char *cv);

    friend class ManagementSystem;

private:
    char* id ;
    char* password ;
    int forgetPassQ ;
    char* forgetPassA ;
    char* fName;
    char* lName;
    char* email;
    char* phone;
    int age;
    char* address;
    char* profession;
    char* about;
    bool isCv;
    char* CV;
    int numOfSub;
    Apply* submissions;

};


#endif //JOBSEARCH1_CANDIDATE_H
