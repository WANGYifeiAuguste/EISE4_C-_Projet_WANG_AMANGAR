#include "logistics.hh"
#include <sstream>

Logistics::Logistics(const std::string& name,int age,const std::string& employer)
    :Member(name,age,employer)
{
    
}


Logistics::Logistics(const std::vector<std::string>& v)
     :Member(v[0],std::stoi(v[1]),v[2])
{
    for(auto i = 4u; i< v.size(); ++i)
        *this += v[i];
}


Logistics::Logistics(const std::string& name,int age,const std::string& employer,std::vector<std::string> && responsibilities)
    :Member(name,age,employer),m_responsibilities(std::move(responsibilities))
{
}


Logistics::Logistics(Logistics&& logistics)
    :Member(std::move(logistics)),m_responsibilities(std::move(logistics.m_responsibilities))
{
}

Logistics& Logistics::operator=(Logistics&& logistics)
{
    if(this != &logistics)
    {
        Member::operator =(std::move(logistics));
        m_responsibilities = std::move(logistics.m_responsibilities);
    }
    return *this;
}


bool Logistics::operator+=(const std::string& responsibility)
{
    for(auto it = m_responsibilities.begin(); it != m_responsibilities.end(); ++it)
        if(*it == responsibility) 
            return false;
    m_responsibilities.push_back(responsibility);
    return true;
}

bool Logistics::operator-=(const std::string& responsibility)
{
    for(auto it = m_responsibilities.begin(); it != m_responsibilities.end(); ++it)
        if(*it == responsibility) 
        {
            m_responsibilities.erase(it);
            return true;
        }
    return false;
}


size_t Logistics::nCount()const
{
    return m_responsibilities.size();
}

std::string Logistics::toString() const
{
    std::ostringstream oss;
    oss << Member::toString()
        << "CountOfResponsibilities: " << m_responsibilities.size() << "\n";
        
    for(auto i = 0u ; i<m_responsibilities.size();++ i)
        oss << i + 1 << ". " << m_responsibilities[i] << "\n";

    return oss.str();
}

std::string Logistics::getTypeName()const
{
    return "class Logistics";
}