//
// Created by Student on 2/25/2024.
//

#ifndef JOBSEARCH1_APPLY_H
#define JOBSEARCH1_APPLY_H

class Apply {
public:
    Apply();
    Apply(int id);
    Apply(const Apply & apply);
    void print();
    void setStatus(bool status);
    void setIdOfJob(int idOfJob);

    friend class ManagementSystem;





private:
    bool status;
    int idOfJob;



};

void findJob(int id);
#endif //JOBSEARCH1_APPLY_H
