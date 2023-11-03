#ifndef __REPS_CHANCERYTTER_SRC_INTERFACES_CONDUCTOR_H_
#define __REPS_CHANCERYTTER_SRC_INTERFACES_CONDUCTOR_H_
#include "../experiments/settings_fileloader.cpp"

class Conductor
{
public:
    virtual ~Conductor() = default;
    virtual void load_settings_from_loader(SettingsLoader &loader) = 0;
    //virtual int run() = 0;

};
#endif // __REPS_CHANCERYTTER_SRC_INTERFACES_CONDUCTOR_H_