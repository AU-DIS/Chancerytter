#include <iostream>
#include <memory>
#include <stdexcept>
// #include <boost/random.hpp>
#include "experiments/experiment_runner.cpp"
#include "experiments/mock_experiment.cpp"

int main(int argc, char *argv[])
{
    ExperimentRunner runner(std::make_unique<MockExperiment>());
    int err = runner.run();
    if (err)
    {
        throw std::runtime_error("Experiment run failed");
    }
}
