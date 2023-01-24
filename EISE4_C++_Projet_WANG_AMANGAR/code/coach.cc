#include "coach.hh"
#include <sstream>

Coach* Coach::m_pChiefCoach = nullptr;

Coach* Coach::getChiefCoach()
{
    return m_pChiefCoach;
}


Coach::Coach(const std::string& name,int age,const std::string& employer , int years, bool bChief)
    :Member(name,age,employer),m_years(years)
{
    setChiefCoach(bChief);
}

Coach::Coach(Coach&& coach)
    :Member(std::move(coach)),m_years(coach.m_years)
{
    setChiefCoach(coach.m_bChief);
    coach.m_years = 0;
    coach.m_bChief = false;

}

Coach& Coach::operator = (Coach&& coach)
{
    if(this != &coach)
    {
        Member::operator =(std::move(coach));
        m_years = coach.m_years;
        setChiefCoach(coach.m_bChief);
        coach.m_years = 0;
        coach.m_bChief = false;
    }
    return *this;
}

Coach::Coach(const std::vector<std::string>& v)
    :Member(v[0],std::stoi(v[1]),v[2])
{
    if(v.size()>=5)
        setYearsOfCoaching(  std::stoi(v[4]) );
        
    if(v.size()==6)
        setChiefCoach( std::stoi(v[5]) != 0 ) ;

}


/*
    当flag为true ,设置当前对象为主教练
   当flag为false ,设置当前对象为非主教练
   Lorsque l’indicateur est vrai, définit l’objet actuel à l’entraîneur-chef
   Lorsque l’indicateur est faux, définissez l’objet actuel sur un non-entraîneur-chef
 * */
void Coach::setChiefCoach(bool flag)
{
    if(flag)
    {
        Coach* pc = Coach::getChiefCoach();
        if(pc != nullptr)
            pc->setChiefCoach(false);
        m_pChiefCoach = this;
    }
    else
    {
        if(m_bChief)
            m_pChiefCoach = nullptr;
    }
    m_bChief = flag;
}

bool Coach::IsChiefCoach()const
{
    return m_bChief;
}

void Coach::setYearsOfCoaching(int years)
{
    m_years = years;
}


int Coach::getYearsOfCoaching() const
{
    return m_years;
}


std::string Coach::toString()const
{
    std::ostringstream oss;
    oss << Member::toString()
        << "YearsOfCoaching: " << getYearsOfCoaching() << "\n"
        << "IsChiefCoach: " << (IsChiefCoach()?"true":"false") << "\n";
    return oss.str();
}

std::string Coach::getTypeName()const
{
    return "class Coach";
}