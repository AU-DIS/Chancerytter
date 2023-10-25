#ifndef __REPS_CHANCERYTTER_TEST_EXPERIMENT_TEST_EXPERIMENT_TEST_CPP_
#define __REPS_CHANCERYTTER_TEST_EXPERIMENT_TEST_EXPERIMENT_TEST_CPP_
#include "gtest/gtest.h"
#include "interfaces/experiment_interface.h"
#include "experiments/experiment_runner.cpp"

//#include "src/experiments/mock_experiment.cpp"
   //" /src/experiments/mock_experiment.cpp"
//#include "experiments/mock_experiment.cpp"

class MockExperimentSUCCEED: public ExperimentInterface {
    public:
        MockExperimentSUCCEED() {    
        }
        ~MockExperimentSUCCEED() {
        }
        int run() {
            return 0;
        }
};
class MockExperimentFAIL: public ExperimentInterface {
    public:
        MockExperimentFAIL() {    
        }
        ~MockExperimentFAIL() {
        }
        int run() {
            return 1;
        }
};


struct ExperimentRunnerTest: public testing::Test {
    ExperimentRunner *runner;
    void SetUp() {runner = new ExperimentRunner(std::make_unique<MockExperimentSUCCEED>());};
    void TearDown() {delete runner;};
};

TEST_F(ExperimentRunnerTest, SuceedOnGoodRun) {
    runner->set_experiment(std::make_unique<MockExperimentSUCCEED>());
    std::cout<<runner->run()<<std::endl;
    ASSERT_EQ(0,runner->run());
}

TEST_F(ExperimentRunnerTest, FailOnBadRun) {
    runner->set_experiment(std::make_unique<MockExperimentFAIL>());
    ASSERT_NE(0, runner->run());
}


#endif // __REPS_CHANCERYTTER_TEST_EXPERIMENT_TEST_EXPERIMENT_TEST_CPP_



