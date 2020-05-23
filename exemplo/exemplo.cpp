#include <mediator/mediator.h>
#include "serviceA.h"
#include "serviceB.h"
#include "serviceC.h"
using namespace d3::mediator;

int main()
{
	Mediator medidor;

	ServiceA serviceA{medidor};
	ServiceB serviceB;
	ServiceC serviceC;

	medidor.executor(serviceA);
	medidor.executor(serviceB);
	medidor.executor(serviceC);

    CmdAdd cmd;
	cmd.valor = 3;
    cmd.divisor = 4;

    double resultAdd = medidor.exec(cmd);
    double resultRdn = medidor.exec( QueryRand{} );
    auto resultFrmt = medidor.exec( CmdFormat{resultRdn} );

    cout << "Hello Mediator" << endl;
    cout << "The resultAdd is: " << resultAdd << endl;
    cout << "The resultRdn is: " << resultRdn << endl;
    cout << "The resultFmt is: " << resultFrmt << endl;
	return 0;
}
