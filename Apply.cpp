//
// Created by Student on 2/19/2024.
//

#include "Apply.h"
#include <cstring>
using namespace std;


Apply::Apply(int id) {
    this->idOfJob = id;
    this->status = true;
}
Apply::Apply(const Apply & apply){
    this->status = apply.status;
    this->idOfJob = apply.idOfJob;
}
void Apply::setStatus(bool status)
{
    this->status=status;
}
void Apply::setIdOfJob(int idOfJob)
{
    this->idOfJob=idOfJob;
}
