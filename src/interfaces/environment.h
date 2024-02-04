#ifndef __REPS_CHANCERYTTER_SRC_INTERFACES_ENVIRONMENT_H_
#define __REPS_CHANCERYTTER_SRC_INTERFACES_ENVIRONMENT_H_

#include <vector>
class Environment {
    public:
    virtual ~Environment() = default;
    virtual void create_game_matrix(int round) = 0;
    virtual double pull(int armid) = 0;
    virtual double pull_matrix(int armid, int round) = 0;
    virtual std::vector<std::vector<double>> get_advise() = 0;
};

#endif // __REPS_CHANCERYTTER_SRC_INTERFACES_ENVIRONMENT_H_