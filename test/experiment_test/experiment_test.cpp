#ifndef __REPS_CHANCERYTTER_TEST_EXPERIMENT_TEST_EXPERIMENT_TEST_CPP_
#define __REPS_CHANCERYTTER_TEST_EXPERIMENT_TEST_EXPERIMENT_TEST_CPP_
#include "gtest/gtest.h"
#include "interfaces/experiment.h"
#include "experiments/experiment_runner.cpp"
#include "experiments/settings_fileloader.cpp"
#include "test_data/test_data.h"

// #include "src/experiments/mock_experiment.cpp"
//" /src/experiments/mock_experiment.cpp"
// #include "experiments/mock_experiment.cpp"

class MockExperimentSUCCEED : public Experiment
{
public:
    MockExperimentSUCCEED()
    {
    }
    ~MockExperimentSUCCEED()
    {
    }
    int run()
    {
        return 0;
    }
};
class MockExperimentFAIL : public Experiment
{
public:
    MockExperimentFAIL()
    {
    }
    ~MockExperimentFAIL()
    {
    }
    int run()
    {
        return 1;
    }
};

struct ExperimentRunnerTest : public testing::Test
{
    ExperimentRunner *runner;
    void SetUp() { runner = new ExperimentRunner(std::make_unique<MockExperimentSUCCEED>()); };
    void TearDown() { delete runner; };
};

TEST_F(ExperimentRunnerTest, SuceedOnGoodRun)
{
    runner->set_experiment(std::make_unique<MockExperimentSUCCEED>());
    ASSERT_EQ(0, runner->run());
}

TEST_F(ExperimentRunnerTest, FailOnBadRun)
{
    runner->set_experiment(std::make_unique<MockExperimentFAIL>());
    ASSERT_NE(0, runner->run());
}

/* ######################## SETTINGS LOADER ###################### */

struct SettingsLoaderTest : public testing::Test
{
    SettingsLoader *loader;
    std::vector<std::string> col_names;
    void SetUp() { 
        loader = new SettingsLoader(std::string(global_testdatapath).append("/test_experiment_settings.csv"));
        col_names = loader->next_row(); 
    };
    void TearDown() { delete loader; };
};

TEST_F(SettingsLoaderTest, LoadSettingsFile)
{
    SettingsLoader(std::string(global_testdatapath).append("/test_experiment_settings.csv"));
    SUCCEED();
}

TEST_F(SettingsLoaderTest, ReadBanditFromSettingsFile)
{
    ASSERT_STREQ(loader->get_bandit()->get_policy_name().c_str(),"exp3");
}

TEST_F(SettingsLoaderTest, ReadRoundsFromSettingsFile)
{
    ASSERT_EQ(loader->get_rounds(),100);
}

TEST_F(SettingsLoaderTest, ReadNbarmsFromSettingsFile)
{
    ASSERT_EQ(loader->get_nbarms(),20);
}

TEST_F(SettingsLoaderTest, ReadFromSettingsFile)
{
    ASSERT_EQ(loader->get_chosarms(),1);
}

TEST_F(SettingsLoaderTest, ReadBanditTwiceFromSettingsFile)
{
    ASSERT_STREQ(loader->get_bandit()->get_policy_name().c_str(),"exp3");
    loader->next_row();
    ASSERT_STREQ(loader->get_bandit()->get_policy_name().c_str(),"qbl");
}


/* ######################## CONDUCTOR ###################### */

#include "interfaces/conductor.h"
#include "conductors/single_choice_conductor.cpp"

struct ConductorTest : public testing::Test
{
    SettingsLoader *loader;
    std::vector<std::string> col_names;
    void SetUp() { 
        loader = new SettingsLoader(std::string(global_testdatapath).append("/test_experiment_settings.csv"));
        col_names = loader->next_row(); 
    };
    void TearDown() { delete loader; };
};

TEST_F(ConductorTest, CreateSingleChoiceConductorTest) {
    SingleChoiceConductor();
    SUCCEED();
}

TEST_F(ConductorTest, CreateSingleChoiceConductorWithLoaderTest) {
    SingleChoiceConductor(loader);
    SUCCEED();
}

TEST_F(ConductorTest, LoadConductorSettingsManuallyFromLoaderTest) {
    std::unique_ptr<Conductor> conductor = std::make_unique<SingleChoiceConductor>();
    conductor->load_settings_from_loader(*loader);
    SUCCEED();
}


#endif // __REPS_CHANCERYTTER_TEST_EXPERIMENT_TEST_EXPERIMENT_TEST_CPP_
