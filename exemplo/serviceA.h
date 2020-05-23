#ifndef SERVICEA_H
#define SERVICEA_H
#include <mediator/mediator.h>

using namespace d3::mediator;
class CmdAdd;

class ServiceA : public Executor
{
	Mediator& medidor;
public:
    ServiceA(Mediator& medidor);

    double add( CmdAdd& cmd );
};


struct CmdAdd
{
    typedef ServiceA ExecutorT;
    typedef double ResultT;

    int valor;
    double divisor;

    ResultT exec(Executor* servico) {
        return ((ServiceA*)servico)->add(*this);
    }
};



#endif // SERVICEA_H
