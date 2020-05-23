#include "serviceA.h"
#include "serviceB.h"

ServiceA::ServiceA(Mediator& medidor) : medidor(medidor)
{

}

double ServiceA::add(CmdAdd &cmd) {
    auto result = cmd.valor / cmd.divisor;
    
    medidor.exec( CmdRand{result} );

    return result;
}
