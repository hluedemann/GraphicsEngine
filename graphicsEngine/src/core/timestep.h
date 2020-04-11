#ifndef TIMESTEP_H
#define TIMESTEP_H

namespace engine {

class TimeStep
{
public:
    TimeStep(float _time)
        : time_(_time)
    {
    }

    float getSeconds() const { return time_; }
    float getMilliSeconds() const { return  1000.0f * time_; }

private:
    float time_;
};

}

#endif // TIMESTEP_H
