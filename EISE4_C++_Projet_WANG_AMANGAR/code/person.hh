#pragma once

#include <iostream>
#include <string>
#include "objInfo.hh"



class Person : public Object
{
private:
    //姓名Nom
    std::string m_name;
    //年龄Age
    int m_age;
public:
    Person(const std::string&,int);
    
    //不支持对象的拷贝与复制La copie et la réplication d’objets ne sont pas prises en charge
    Person(const Person&)  = delete;
    Person& operator=(const Person&) = delete;
    
    //支持对象移动Prise en charge des objets
    Person(Person&&);
    Person& operator=(Person&&);
    
public:
    //设置姓名Définir le nom
    void setName(const std::string&);
    //获取姓名Obtenir le nom
    std::string getName()const;
    
    //设置年龄Définir l’âge
    void setAge(int);
    //获取年龄Obtenir l’âge
     int getAge()const;
    
    //返回类型名称   "class Person"   
	//retourne le nom du type "class Person"
    virtual std::string getTypeName()const;
    
    //返回Person信息   如  “Name: xxx\n Age: 20”
	//Renvoie des informations sur la personne telles que « Nom : xxx\n Âge : 20 ans »
    virtual std::string toString()const;
};
