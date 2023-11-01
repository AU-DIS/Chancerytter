#ifndef __REPS_CHANCERYTTER_TEST_GENERALTESTS_H_
#define __REPS_CHANCERYTTER_TEST_GENERALTESTS_H_
#include "gtest/gtest.h"
#include <boost/random.hpp>

TEST(GeneralTest, BoostExists)
{
    boost::mt19937 rng;
    SUCCEED();
}

#endif // __REPS_CHANCERYTTER_TEST_GENERALTESTS_H_