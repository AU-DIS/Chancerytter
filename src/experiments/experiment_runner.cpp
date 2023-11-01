#ifndef __REPS_CHANCERYTTER_SRC_EXPERIMENTS_EXPERIMENT_RUNNER_CPP_
#define __REPS_CHANCERYTTER_SRC_EXPERIMENTS_EXPERIMENT_RUNNER_CPP_
#include <memory>
#include "../interfaces/experiment.h"

class ExperimentRunner
{
private:
    std::unique_ptr<Experiment> experiment_;

public:
    explicit ExperimentRunner(std::unique_ptr<Experiment> &&experiment = {}) : experiment_(std::move(experiment)) {}
    void set_experiment(std::unique_ptr<Experiment> &&experiment)
    {
        experiment_ = std::move(experiment);
    }
    int run()
    {
        return experiment_->run();
    }
};
#endif // __REPS_CHANCERYTTER_SRC_EXPERIMENTS_EXPERIMENT_RUNNER_CPP_