#pragma once
#include <string>

/*
    所有类的父类
     只有两个纯虚函数
	 La classe parente de toutes les classes
     Il n’y a que deux fonctions virtuelles pures
*/
class Object
{
public:
    // 返回类型名称  Renvoie le nom du type.
    virtual std::string getTypeName()const = 0;
    // 返回对象的具体信息  Renvoie des informations spécifiques sur un objet
    virtual std::string toString()const = 0;
};

//重载   operator << 输出Object对象信息
//Charge lourde. operator << Informations sur l’objet Output
std::ostream&  operator << (std::ostream& os, const Object& object);