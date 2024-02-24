//
// Created by Student on 2/19/2024.
//

#ifndef JOBSEARCH_APPLY_H
#define JOBSEARCH_APPLY_H


class Apply {
public:
    Apply();
    Apply(int id);
    Apply(const Apply & apply);
    void print();

private:
    bool status;
    int idOfJob;

};


#endif //JOBSEARCH_APPLY_H
