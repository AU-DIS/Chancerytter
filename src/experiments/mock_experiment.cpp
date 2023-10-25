#ifndef __REPS_CHANCERYTTER_SRC_EXPERIMENTS_MOCK_EXPERIMENT_CPP_
#define __REPS_CHANCERYTTER_SRC_EXPERIMENTS_MOCK_EXPERIMENT_CPP_

#include "../interfaces/experiment_interface.h"


class MockExperiment: public ExperimentInterface {
    public:
        MockExperiment() {
            
        }
        ~MockExperiment() {

        }
        int run() {
            return 0;
        }
};


#endif // __REPS_CHANCERYTTER_SRC_EXPERIMENTS_MOCK_EXPERIMENT_CPP_