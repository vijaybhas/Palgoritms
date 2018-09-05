#include <iostream>

typedef void* (f)(void*) MainFunc;

class RunMain
{
    RunMain();
    ~RunMain();
    
    virtual void Run();
    
    virtual void RunFunc((void*) (f)(void*));
}
