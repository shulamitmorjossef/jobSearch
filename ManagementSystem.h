//
// Created by Student on 2/27/2024.
//

#ifndef JOBSEARCH1_MANAGEMENTSYSTEM_H
#define JOBSEARCH1_MANAGEMENTSYSTEM_H

#include "Job.h"
#include "Apply.h"
#include "Candidate.h"
#include "Employer.h"
#include <iostream>
#include <cstring>
#include <fstream>

class ManagementSystem {
public:
    ManagementSystem();
    ~ManagementSystem();

    void getEmp();
    void pushEmp();
    void getCan();
    void pushCan();
    void mainMenu();
    void mainEmp(Employer& employer);
    void mainCan(Candidate& candidate);
    void signUpEmp();
    void signUpCan();
    void logIn(int type);
    bool forgetPassword(int type, bool exists, int index);
    int searchJob(int* arr);

    void print();



private:
    Employer* employers;
    int numOfEmp;
    Candidate* candidates;
    int numOfCan;
    int numOfJobs;
};


#endif //JOBSEARCH1_MANAGEMENTSYSTEM_H
