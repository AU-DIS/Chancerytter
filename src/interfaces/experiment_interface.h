#ifndef __REPS_CHANCERYTTER_SRC_INTERFACES_EXPERIMENT_INTERFACE_H_
#define __REPS_CHANCERYTTER_SRC_INTERFACES_EXPERIMENT_INTERFACE_H_

class ExperimentInterface {
    public:
        virtual ~ExperimentInterface() = default;
        virtual int run() = 0;
};

#endif //REPS_CHANCERYTTER_SRC_INTERFACES_EXPERIMENT_INTERFACE_H_