#include "player.hh"
#include <sstream>
#include <set>
std::set<int> Player::m_set;

Player::Player(const std::string& name,int age,const std::string& employer)
    :Member(name,age,employer)
{   
}

Player::Player(const std::string& name,int age,const std::string& employer,const std::string& role,unsigned int number)
    :Member(name,age,employer),m_role(role)
{
    setNumber(number);
}

Player::Player(Player&& player)
    :Member(std::move(player)),m_role(std::move(player.m_role)),m_number(player.m_number)
{
    player.m_number = 0;
}

Player& Player::operator=(Player&& player)
{
    if(this != &player)
    {
        Member::operator =(std::move(player));
        m_role = std::move(player.m_role);
        m_number = player.m_number;
        player.m_number = 0;
    }
    return *this;
}

void Player::setRole(const std::string& role)
{
    m_role = role;
}

std::string Player::getRole()const
{
    return m_role;
}

/*
    每次设置号码时 ，都会先从set容器中，检索该函数是否存在
     如果存在，则设置失败，不存在，则设置成功
	 Chaque fois que vous définissez un nombre, il récupère d’abord si la fonction existe ou non à partir du conteneur défini
     S’il est présent, le paramètre échoue et, s’il n’existe pas, le paramètre réussit
*/

bool Player::setNumber(unsigned int number)
{
    if(number == 0)
    {
        if(m_number != 0 )
            m_set.erase(number);
            
        m_number = 0;
    }
    else
    {
        if(m_set.count(number) == 0)
        {
            m_set.insert(number);
            
            if(m_number != 0 )
                m_set.erase(m_number);
            
            m_number = number;
        }
        else
            return false;
    }
    
    return true;
}

unsigned int Player::getNumber()const
{
    return m_number;
}

std::string Player::toString()const
{
    std::ostringstream oss;
    oss << Member::toString()
        << "Number: " << getNumber() << "\n"
        << "Role: " << getRole() << "\n";

    return oss.str();
}

Player::Player(const std::vector<std::string>& v)
    :Member(v[0],std::stoi(v[1]),v[2])
{
    if(v.size() >=5 )
        setRole(v[4]);
    
    if(v.size() == 6)
        setNumber(std::stoi(v[5]));
}


std::string Player::getTypeName()const
{
    return "class Player";
}