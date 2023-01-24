#include "team.hh"
#include "player.hh"
#include "logistics.hh"
#include "coach.hh"
#include "utility.hh"
#include <sstream>

Team::Team(std::ifstream& infile)
{
    std::string line;
    while(std::getline(infile,line))
    {
        std::vector<std::string> tokens;
        split(tokens,line,';');
        if(!tokens.empty())
        {
            std::string type(tokens[3]);
            
            if(type == "player")
                m_members.push_back( new Player(tokens) );
            else if(type == "coach")
                m_members.push_back( new Coach(tokens) );
            else if(type == "logistics")
                m_members.push_back( new Logistics(tokens) );
            else
                throw "unknown type!" ;
        }
    }
}

Team::Team(Team&& team)
    : m_members(std::move(team.m_members))
{
    
}

Team& Team::operator=(Team&&  team)
{
    if(this != &team)
        m_members = std::move(team.m_members);

    return *this;
}


bool Team::findByName(const std::string& name, std::vector<Member*>& v)
{
    int c = 0;
    std::string key = LCase(name);
    for(auto it = m_members.begin(); it != m_members.end(); ++it)
    {
        
        std::string temp = (*it)->getName();
        if( LCase(temp).find(key) != std::string::npos )
        {
            v.push_back(*it);
            ++c;
        }
    }
    return c>0 ? true:false;
}

bool Team::AddMembers( Member* member)
{
   
    for(auto it = m_members.begin(); it != m_members.end();++it)
    {
        if( *(*it) == *member )
            return false;
    }
    m_members.push_back(member);
    return true;
}

bool Team::RemoveMembers(Member* member)
{
    if(member == nullptr)
        return false;

    auto it = m_members.begin();
    bool found = false;
    for(; it != m_members.end();++it)
    {
        if( *(*it) == *member )
         {
             found = true;
             break;
         }
    }
    
    if(found)
        m_members.erase(it);
    return found;
}


std::string Team::getTypeName()const
{
    return "class Team";
}

std::string Team::toString()const 
{
    
    std::ostringstream oss;
    
    oss << "Total: " << getCount() << "\n";
    
    size_t n = 0;
    
    for(auto it = m_members.begin(); it != m_members.end(); ++it)
        oss << ++n << "#\n" << (*it)->toString() << "\n";

    return oss.str();
}

size_t Team::getCount()const
{
    return m_members.size();
}

Team::~Team()
{
    for(auto it = m_members.begin(); it != m_members.end(); ++it)
        delete *it;

    m_members.clear();
}