#ifndef __REPS_CHANCERYTTER_SRC_INTERFACES_EXPERIMENT_H_
#define __REPS_CHANCERYTTER_SRC_INTERFACES_EXPERIMENT_H_

class Experiment
{
public:
    virtual ~Experiment() = default;
    virtual int run() = 0;
};

#endif // REPS_CHANCERYTTER_SRC_INTERFACES_EXPERIMENT_H_