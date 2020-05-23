#ifndef SERVICEC_H
#define SERVICEC_H
#include <mediator/mediator.h>

using namespace d3::mediator;

class ServiceC : public Executor
{
public:
    ServiceC();

    string format(double number);
};

struct CmdFormat
{
    typedef ServiceC ExecutorT;
    typedef string ResultT;

    double number;

    ResultT exec(Executor* servico) {
        return ((ServiceC*)servico)->format(number);
    }
};


#endif // SERVICEC_H
