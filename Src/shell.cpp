#include "shell.h"

Shell *Shell::GetInstance()
{
    if(_shell == nullptr)
        _shell = std::unique_ptr<Shell>(new Shell);

    return _shell.get();
}
