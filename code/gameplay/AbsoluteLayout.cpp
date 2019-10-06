#include "Base.h"
#include "Control.h"
#include "AbsoluteLayout.h"
#include "Container.h"

namespace gameplay
{

AbsoluteLayout::AbsoluteLayout()
{
}

AbsoluteLayout::~AbsoluteLayout()
{
}

AbsoluteLayout* AbsoluteLayout::create()
{
    return new AbsoluteLayout();
}

Layout::Type AbsoluteLayout::getType()
{
    return Layout::LAYOUT_ABSOLUTE;
}

void AbsoluteLayout::update(const Container* container)
{
    // Nothing to do for absolute layout
}

}