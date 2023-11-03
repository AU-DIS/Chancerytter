#ifndef __REPS_CHANCERYTTER_SRC_EXPERIMENTS_SETTINGS_FILELOADER_CPP_
#define __REPS_CHANCERYTTER_SRC_EXPERIMENTS_SETTINGS_FILELOADER_CPP_

#include "../csv.h"
#include "../interfaces/single_policy.h"
#include "../singlepolicies/exp3.cpp"
#include "../singlepolicies/qbl.cpp"

class SettingsLoader {
    
    csv::CSVReader reader;
    csv::CSVRow current_row;

    public:
    SettingsLoader(std::string path) : reader(path){
    };

    std::vector<std::string> next_row() {
        reader.read_row(current_row);
        return current_row.get_col_names();
    }

    std::unique_ptr<SinglePolicy> get_bandit() {
        switch(spn::s_single_policy_names[current_row["bandit"].get()])
        {
        case spn::exp3:
            return std::make_unique<Exp3>();
        case spn::qbl:
            return std::make_unique<QBL>();
        default:
            throw std::runtime_error("Specified banditname in settingsfile is not valid");
        }
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