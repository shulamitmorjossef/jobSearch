//
// Created by Student on 2/19/2024.
//

#ifndef JOBSEARCH_APPLY_H
#define JOBSEARCH_APPLY_H
#include "Job.h"

class Apply {
public:
    Apply(int id);
    Apply(const Apply & apply);

private:
    bool status;
    int idOfJob;

};


#endif //JOBSEARCH_APPLY_H
