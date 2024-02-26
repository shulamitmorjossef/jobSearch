//
// Created by Student on 2/25/2024.
//

#ifndef JOBSEARCH1_CANDIDATE_H
#define JOBSEARCH1_CANDIDATE_H


#include "Apply.h"

class Candidate {
public:
    Candidate();
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
    char* CV;
    Apply* submissions;
    int numOfSub;

};


#endif //JOBSEARCH1_CANDIDATE_H
