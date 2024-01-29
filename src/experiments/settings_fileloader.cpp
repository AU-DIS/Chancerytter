#ifndef __REPS_CHANCERYTTER_SRC_EXPERIMENTS_SETTINGS_FILELOADER_CPP_
#define __REPS_CHANCERYTTER_SRC_EXPERIMENTS_SETTINGS_FILELOADER_CPP_

#include <map>
#include "../csv.h"
#include "../interfaces/single_policy.h"
//#include "../singlepolicies/exp3.hpp"
//#include "../singlepolicies/qbl.cpp"

#include "../singlepolicies/exp3.cpp"
#include "../singlepolicies/qbl.cpp"

//TODO: Move this function to somewhere more general
static void add_policies() {
    spn::single_policy_map.insert({std::string("exp3"), &spn::createSinglePolicy<Exp3>});
    spn::single_policy_map.insert({std::string("qbl"), &spn::createSinglePolicy<QBL>});
}

class SettingsLoader {

    csv::CSVReader reader;
    csv::CSVRow current_row;

    public:
    SettingsLoader(std::string path) : reader(path){
        add_policies();
    };

    std::vector<std::string> next_row() {
        reader.read_row(current_row);
        return current_row.get_col_names();
    }

    std::unique_ptr<SinglePolicy> get_bandit() {
        spn::policy_map::iterator it = spn::single_policy_map.find(current_row["bandit"].get());
        if (it == spn::single_policy_map.end()) {
            throw std::runtime_error("Specified banditname in settingsfile is not valid");
        }
        return it->second();
    }

    int get_rounds() {
        return current_row["rounds"].get<int>();
    }

    //Total number of arms
    int get_nbarms() {
        return current_row["nbarms"].get<int>();
    }

    //Arms to select in every round
    int get_chosarms() {
        return current_row["chosarms"].get<int>();
    }
    
};

#endif // __REPS_CHANCERYTTER_SRC_EXPERIMENTS_SETTINGS_FILELOADER_CPP_