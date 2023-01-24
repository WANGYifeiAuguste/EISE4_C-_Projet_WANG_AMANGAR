#pragma once

#include "member.hh"
#include <vector>
class Coach : public Member
{
private:
    //保存主教练的指针enregistrer le pointeur vers l'entraîneur-chef
    static Coach* m_pChiefCoach;
    
    //执教年限Années d’enseignement
    int m_years = 0;
    
    //是否为主教练Être entraîneur-chef ou non
    bool m_bChief = false;
public:
    //构造函数Constructeur
    Coach(const std::string&,int ,const std::string&, int = 0, bool = false);
    Coach(const std::vector<std::string>& );
    
    //支持对象移动Soutenir le mouvement d'objet
    Coach(Coach&&);
    Coach& operator = (Coach&&);
    
    //返回主教练指针Retour au pointeur de l’entraîneur-chef
    static Coach* getChiefCoach();
    
    //设置主教练Mettre en place un entraîneur-chef
    void setChiefCoach(bool = true);
    
    //返回是否是主教练Retourne que ce soit l’entraîneur-chef ou non
    bool IsChiefCoach()const;
    
    //设置执教年限Définir le nombre d’années d’enseignement
    void setYearsOfCoaching(int years);
    
    //返回执教年限Retour aux années d’enseignement
    int getYearsOfCoaching() const;
    
    //返回类名  "class Coach"
	//Renvoie le nom de classe «class Coach»
    virtual std::string getTypeName()const;
    
    //返回对象信息Renvoie des informations sur l’objet
    virtual std::string toString()const;
};