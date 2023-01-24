#include "person.hh"
#include <sstream>

Person::Person(const std::string& name,int age)
    :m_name(name),m_age(age)
{
}

Person::Person(Person&& person)
    : m_name(std::move(person.m_name)) , m_age(person.m_age)
{
    person.m_age = 0;
}

Person& Person::operator=(Person&& person)
{
    if(this != & person)
    {
        m_name = std::move(person.m_name);
        m_age  = person.m_age;
        person.m_age = 0;
    }
    return *this;
}

void Person::setName(const std::string& name)
{
    m_name = name;
}

std::string Person::getName()const
{
    return m_name;
}

void Person::setAge(int age)
{
    m_age = age;
}

int Person::getAge()const
{
    return m_age;
}

std::string Person::toString()const
{
    std::ostringstream oss;
    oss << "Name: " << getName() << "\n"
        << "Age: " << getAge() << "\n";
    return oss.str();
}

std::string Person::getTypeName()const
{
    return "class Person";
}



