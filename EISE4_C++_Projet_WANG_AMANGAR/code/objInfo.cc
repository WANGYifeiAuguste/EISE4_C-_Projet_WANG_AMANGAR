#include "objInfo.hh"


std::ostream&  operator << (std::ostream& os, const Object& object)
{
    return os << object.toString();
}