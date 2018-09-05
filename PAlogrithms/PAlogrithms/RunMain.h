#include <iostream>

class RunMain
{
    RunMain();
    ~RunMain();
    
    virtual void Run();
    
    virtual void Run(void* (f)(void*));
}
