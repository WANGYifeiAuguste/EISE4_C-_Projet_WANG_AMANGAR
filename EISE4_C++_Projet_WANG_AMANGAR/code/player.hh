#pragma once 

#include "member.hh"
#include <set>
#include <vector>


class Player : public Member
{
private:
    //保存已存在球员号码Enregistrer le numéro de joueur qui existe déjà

    static std::set<int> m_set;
    //角色 即门卫 前锋 中场 后卫Rôles, c’est-à-dire gardien de but, attaquant, milieu de terrain, défenseur

    std::string m_role;
    //球员号码Numéro de joueur

    unsigned int m_number = 0;
public:
    Player(const std::string&,int,const std::string&);
    Player(const std::vector<std::string>& );
    
    Player(const std::string&,int,const std::string&,const std::string&,unsigned int);
    
    //支持移动Prise en charge des joueurs
    Player(Player&&);
    Player& operator=(Player&&);
    
    //设置或返回角色Définir ou renvoyer le rôle
    void setRole(const std::string&);
    std::string getRole()const;
    
    //设置或返回球员号码Définir ou renvoyer le numéro de joueur

    bool setNumber(unsigned int);
    unsigned int getNumber()const;
    
    
    //返回类型Type de retour
    virtual std::string getTypeName()const;
    
    //返回对象信息Renvoie des informations sur l’objet
    virtual std::string toString()const;
};