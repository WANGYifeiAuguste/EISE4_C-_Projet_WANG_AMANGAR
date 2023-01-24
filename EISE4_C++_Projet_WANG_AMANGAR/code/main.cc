#include "person.hh"
#include "member.hh"
#include "player.hh"
#include "logistics.hh"
#include "coach.hh"
#include "team.hh"
#include <fstream>
#include <cassert>

void TestPlayers()
{
    std::cout << "====" << __func__ << "====" << std::endl;
    Player p1("Messi",35,"Argentina");
    p1.setNumber(10);
    Player p2("Romero",24,"Argentina","defender",17);
    assert( p2.setNumber(10) == false );
    assert( p2.setNumber(13) == true);
    assert( p2.getNumber() != 17 );
	std::cout << "====pass====" << std::endl;
}

void TestCoach()
{
    std::cout << "====" << __func__ << "====" << std::endl;
    Coach c1("Scaloni",44,"Argentina");
    c1.setChiefCoach();
    Coach c2("Ayala",49,"Argentina");
    c2.setChiefCoach();
    assert(c1.IsChiefCoach() == false);
    assert(c2.IsChiefCoach() == true);
	std::cout << "====pass====" << std::endl;
}

void TestLogistics()
{
    std::cout << "====" << __func__ << "====" << std::endl;
    Logistics l1("Tom",43,"Argentina");
    std::string tasks[] = {"a1","a2","b3","d4"};
    for(auto i = 0u;i < sizeof(tasks)/sizeof(tasks[0]);++i)
        l1 += tasks[i];
    
    assert(l1.nCount() == 4);
    l1 -=("a2");
    l1 -=("a2");
    assert(l1.nCount() == 3);
	std::cout << "====pass====" << std::endl;
}

void TestTeam()
{
    std::cout << "====" << __func__ << "====" << std::endl;
    std::ifstream infile("members.txt");
    if(!infile)
        throw "It's failed to open the \'members.txt\' file!";
        
    Team team(infile);
    std::cout << team << std::endl;
    
    IManage* IM = &team;
    std::vector<Member*> results;
    std::string key = "AL";
    bool b = IM->findByName(key,results);
    std::cout << "The number of names containing \'"  << key  <<  "\' is " << results.size()  <<".   (ignore case)"<< std::endl;
    int i = 0;
    if(b)
    {
        for(auto m : results)
            std::cout << ++i << ". " << m->getName() << std::endl;
    }
    
    size_t n = IM->getCount();
    
    Member* member = new Player("Aguero",22,"Argentina National Team");
    assert(IM->AddMembers(member));
    assert(IM->AddMembers(member) == false);
    assert(n == IM->getCount() - 1);
    assert(IM->RemoveMembers(member));
    member = nullptr;
    assert(n == IM->getCount());
	std::cout << "====pass====" << std::endl;
}


int main()
{
    try
    {
        TestPlayers();
        TestCoach();
        TestLogistics();
        TestTeam();
        std::cout << "The program has been successfully executed." << std::endl;
    }
    catch(const char*  pErrMsg)
    {
        std::cout  << pErrMsg << std::endl;
    }
	return 0;
}
