//
// Created by Student on 2/25/2024.
//

#include "Apply.h"

#include <iostream>
#include <cstring>
using namespace std;


Apply::Apply() {
    idOfJob = 0;
    status = false;
}

Apply::Apply(int id) {
    this->idOfJob = id;
    this->status = true;
}

Apply::Apply(const Apply & apply){
    this->status = apply.status;
    this->idOfJob = apply.idOfJob;
}

void Apply::print(){
    cout << "Status: ";
    if(status) {
        cout << "In process";
    }
    else{
        cout << "Postponed";
    }
    cout << "Job details: \n";
//    finJob(idOfJob);

}


void Apply::setStatus(bool status)
{
    this->status=status;
}
void Apply::setIdOfJob(int idOfJob)
{
    this->idOfJob=idOfJob;
}

int Apply::getIdOfJob() const {
    return idOfJob;
}

bool Apply::isStatus() const {
    return status;
}
