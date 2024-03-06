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
#include <vector>


class ManagementSystem {
public:
    ManagementSystem();
    ~ManagementSystem();

    char* setPass();
    void getID();
    void pushID();
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
    void searchJob(Candidate& candidate);
    void addApply(Job* jobs, int num, Candidate& candidate);
    void printSubOfCan(Candidate& candidate);
    void printSortSub(Candidate& candidate);
    void printSub(Apply& sub);

private:
    Employer* employers;
    int numOfEmp;
    Candidate* candidates;
    int numOfCan;
    int numOfJobs;
    int ID;
};


#endif //JOBSEARCH1_MANAGEMENTSYSTEM_H
