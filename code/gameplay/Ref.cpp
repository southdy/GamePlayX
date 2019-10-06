#include "Base.h"
#include "Ref.h"
#include "Game.h"

namespace gameplay
{

Ref::Ref() :
    _refCount(1)
{
}

Ref::Ref(const Ref& copy) :
    _refCount(1)
{
}

Ref::~Ref()
{
}

void Ref::addRef()
{
    GP_ASSERT(_refCount > 0 && _refCount < 1000000);
    ++_refCount;
}

void Ref::release()
{
    GP_ASSERT(_refCount > 0 && _refCount < 1000000);
    if ((--_refCount) <= 0)
    {
        delete this;
    }
}

unsigned int Ref::getRefCount() const
{
    return _refCount;
}

}
