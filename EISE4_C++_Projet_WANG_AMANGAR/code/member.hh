#pragma once

#include "person.hh"


class Member : public Person
{
private:
    //球队老板或雇主    如 "阿根廷国家队" 
	//Propriétaire ou employeur de l’équipe telle que « équipe nationale d’Argentine »
    std::string m_employer;
public:
    //构造函数Constructeur
    Member(const std::string& name ,int age ,const std::string& employer);
    
    //支持对象移动Prise en charge des objets
    Member(Member&&);
    Member& operator= (Member&&);
    
    //析构函数Destructeur
    virtual ~Member(){}
    
    //返回雇主Retour à l’employeur
    std::string getEmployer()const;
    
    //设置雇主Configurer un employeur
    void setEmployer(const std::string&);
    
    //判断两个Member 内容是否相同 Déterminer si le contenu des deux membres est le même
    bool operator ==(const Member&);
    
    //返回类名retourner le nom de la classe
    virtual std::string getTypeName()const;
    
    //返回对象信息Renvoie des informations sur l’objet
    virtual std::string toString()const;
};