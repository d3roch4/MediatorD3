#include "mediator.h"
namespace d3::mediator {

void Mediator::executor(const Executor& executor) {
  Executor* ptr = (Executor*) &executor;
  mapExecutor[typeid( *ptr )] = ptr;
}

}
