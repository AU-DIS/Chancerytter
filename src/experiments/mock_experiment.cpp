#ifndef __REPS_CHANCERYTTER_SRC_EXPERIMENTS_MOCK_EXPERIMENT_CPP_
#define __REPS_CHANCERYTTER_SRC_EXPERIMENTS_MOCK_EXPERIMENT_CPP_

#include "../interfaces/experiment.h"
#include "settings_fileloader.cpp"

class MockExperiment : public Experiment
{
public:
    MockExperiment()
    {
    }
    ~MockExperiment()
    {
    }
    int run()
    {
        return 0;
    }
};

#endif // __REPS_CHANCERYTTER_SRC_EXPERIMENTS_MOCK_EXPERIMENT_CPP_