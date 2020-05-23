#ifndef SERVICEB_H
#define SERVICEB_H
#include <mediator/mediator.h>

using namespace d3::mediator;
class CmdRand;

class ServiceB : public Executor
{
    double lastRdn;
public:
    ServiceB();

    void random(CmdRand& cmd);

    double getLastRdn();
};

struct QueryRand{
    typedef ServiceB ExecutorT;
    typedef double ResultT;

    ResultT exec(Executor* servico) {
        return ((ServiceB*)servico)->getLastRdn();
    }
};

struct CmdRand{
    typedef ServiceB ExecutorT;
    typedef void ResultT;

    double randorize;

    ResultT exec(Executor* servico) {
        return ((ServiceB*)servico)->random(*this);
    }
};

#endif // SERVICEB_H
