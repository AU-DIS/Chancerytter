#ifndef __REPS_CHANCERYTTER_SRC_INTERFACES_SINGLE_POLICY_H_
#define __REPS_CHANCERYTTER_SRC_INTERFACES_SINGLE_POLICY_H_

#include <string>
#include <map>
#include <memory>



class SinglePolicy
{
public:
    virtual ~SinglePolicy() = default;
    virtual int choose() = 0;
    virtual void give_reward(int, double) = 0;  
    virtual std::string get_policy_name() = 0;
};

namespace spn {

template<typename T> std::unique_ptr<SinglePolicy> createSinglePolicy() {return std::make_unique<T>();}

typedef std::map<std::string, std::unique_ptr<SinglePolicy>(*)()> policy_map;

static policy_map single_policy_map = {};

}


#endif // __REPS_CHANCERYTTER_SRC_INTERFACES_SINGLE_POLICY_H_