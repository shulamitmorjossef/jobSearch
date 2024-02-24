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

    void setID(char* id);
    void setPasswotd(char* password);
    void setForgetPassQ(char* forgetPassQ);
    void setForgetPassA (char* forgetPassA);
    void setFName(char* fName);
    void setLName(char* lName);
    void setEmail(char* email);
    void setPhone(char* phone);
    void setAge(int age);
    void setAddress(char* address);
    void setProfession(char* profession);
    void setAbout(char* about);
    void setSubmissions (Apply* submissions);
    void setNumOfSub(int numOfSub);


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
    Apply* submissions;
    int numOfSub;





};


#endif //JOBSEARCH_CANDIDATE_H
