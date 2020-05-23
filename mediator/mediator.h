#ifndef MEDIATOR_H
#define MEDIATOR_H
#include <iostream>
#include <map>
#include <functional>
#include <typeindex>

namespace d3 {
namespace mediator {

using namespace std;
struct Executor;

struct Executor {
    virtual ~Executor() = default;
};

class Mediator
{
	map<type_index, Executor*> mapExecutor;

public:
    void executor(const Executor& executor);

    template<class C> typename C::ResultT exec(C& command)
	{
		auto itr = mapExecutor.find(typeid( typename C::ExecutorT ));
        if (itr != mapExecutor.end()){
            return command.exec(itr->second);
        }else
			throw runtime_error("Executor not found, register this executor with 'Mediator::executor'");
	}

    template<class C> typename C::ResultT exec(C&& command)
    {
        return this->exec(command);
    }
};

}
}
#endif // MEDIATOR_H
