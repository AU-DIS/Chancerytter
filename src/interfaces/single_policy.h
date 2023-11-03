#ifndef __REPS_CHANCERYTTER_SRC_INTERFACES_SINGLE_POLICY_H_
#define __REPS_CHANCERYTTER_SRC_INTERFACES_SINGLE_POLICY_H_

#include <string>
#include <map>

namespace spn {
enum Single_Policy_Names 
{
    exp3,
    qbl,
};


static std::map<std::string, spn::Single_Policy_Names> s_single_policy_names = {
    {std::string("exp3"), spn::exp3},
    {std::string("qbl"), spn::qbl}
};
}




class SinglePolicy
{
public:
    virtual ~SinglePolicy() = default;
    virtual int choose() = 0;
    virtual void give_reward(int, double) = 0;  
    virtual std::string get_policy_name() = 0;
};

#endif // __REPS_CHANCERYTTER_SRC_INTERFACES_SINGLE_POLICY_H_