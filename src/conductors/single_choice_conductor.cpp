#ifndef __REPS_CHANCERYTTER_SRC_CONDUCTORS_SINGLE_CHOICE_CONDUCTOR_CPP_
#define __REPS_CHANCERYTTER_SRC_CONDUCTORS_SINGLE_CHOICE_CONDUCTOR_CPP_

#include "../interfaces/conductor.h"
#include "../interfaces/single_policy.h"
#include "../experiments/settings_fileloader.cpp"


class SingleChoiceConductor: public Conductor {
    
    int active_round = 0;
    int max_rounds = 0;
    int nbarms = 0;
    std::unique_ptr<SinglePolicy> policy;
    public:
    SingleChoiceConductor() {

    }

    SingleChoiceConductor(SettingsLoader &loader) {
        load_settings_from_loader(loader);
    }

    void load_settings_from_loader(SettingsLoader &loader) {

        max_rounds = loader.get_rounds();
        nbarms = loader.get_nbarms();
        policy = std::move(loader.get_bandit());
        
    }

    void set_policy(const std::string policy_name, const std::vector<double> params) {

    }


};





#endif // __REPS_CHANCERYTTER_SRC_CONDUCTORS_SINGLE_CHOICE_CONDUCTOR_CPP_