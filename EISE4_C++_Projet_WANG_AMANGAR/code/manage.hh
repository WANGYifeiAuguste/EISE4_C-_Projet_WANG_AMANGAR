#pragma once

#include "member.hh"
#include <vector>


class IManage 
{
public:
 // 通过成员姓名检索成员Récupérer les membres par nom de membre
    virtual bool findByName(const std::string& , std::vector<Member*>& ) = 0;
    //添加成员 Ajouter des membres
    virtual bool AddMembers(Member*) = 0;
    // 删除成员 Supprimer un membre
    virtual bool RemoveMembers(Member*) = 0;
    //返回成员人数Renvoie le nombre de membres
    virtual size_t getCount()const  = 0 ;
};


