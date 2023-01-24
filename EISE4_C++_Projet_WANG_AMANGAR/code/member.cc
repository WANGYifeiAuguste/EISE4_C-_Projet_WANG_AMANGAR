#include "member.hh"
#include <sstream>

Member::Member(const std::string& name ,int age ,const std::string& employer)
    :Person(name,age),m_employer(employer)
{
}
    
Member::Member(Member&& member)
    :Person(std::move(member)),m_employer(std::move(member.m_employer))
{
}

Member& Member::operator= (Member&& member)
{
    if(this != &member)
    {
        Person::operator = (std::move(member));
        m_employer = std::move(member.m_employer);
    }
    return *this;
}

std::string Member::getEmployer()const
{
    return m_employer;
}

void Member::setEmployer(const std::string& employer)
{
    m_employer = employer;
}

std::string Member::toString()const
{
    std::ostringstream oss;
    oss << Person::toString() 
        << "Employer: " << getEmployer() << "\n";
    return oss.str();
}

std::string Member::getTypeName()const
{
    return "class Member";
}

bool Member::operator ==(const Member& member)
{
    if(this != &member)
        return false;
        
    if(getTypeName() != member.getTypeName())
        return false;
        
    return toString() == member.toString();
}