#include "serviceC.h"
#include <sstream>

ServiceC::ServiceC()
{

}


string ServiceC::format(double number)
{
    std::stringstream sstream;
    sstream.setf(std::ios::fixed);
    sstream.precision(3);
    sstream << number;

    return sstream.str();
}