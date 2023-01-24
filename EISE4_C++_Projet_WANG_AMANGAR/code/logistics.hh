#pragma once

#include "member.hh"

#include <vector>

class Logistics : public Member
{
private:
    //保存负责的事宜Préservation des responsables
    std::vector<std::string> m_responsibilities;
public:
    //构造函数Constructeur

    Logistics(const std::string&,int,const std::string& );
    Logistics(const std::vector<std::string>& );
    Logistics(const std::string&,int,const std::string&,std::vector<std::string> &&);
    
    //支持对应移动Prise en charge des Logistics
    Logistics(Logistics&&);
    Logistics& operator=(Logistics&&);
    
    //添加事宜Ajouter une sujets
    bool operator+=(const std::string&);
    //删除事宜supprimer des sujets
    bool operator-=(const std::string&);
    //返回事宜数量Renvoie le nombre de sujets
    size_t nCount()const;
    
    //返回类名Renvoie le nom de la classe
    virtual std::string getTypeName()const;
    
    //返回对象信息retourner les informations sur l'objet
    virtual std::string toString() const;
};