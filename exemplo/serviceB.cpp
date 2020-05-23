#include "serviceB.h"

ServiceB::ServiceB()
{
    srand(time(nullptr));
}

double ServiceB::getLastRdn()
{
    return lastRdn;
}

void ServiceB::random(CmdRand& cmd)
{
    lastRdn += (rand()) * cmd.randorize;
}