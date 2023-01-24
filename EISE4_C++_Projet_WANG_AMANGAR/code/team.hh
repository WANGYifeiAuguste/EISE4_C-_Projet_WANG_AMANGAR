#include "manage.hh"

#include <fstream>
#include <list>



class Team : public IManage, public Object
{
private:
    //保存成员信息enregistrer les informations sur les membres
    std::list<Member*> m_members;
public:
    //构造函数Constructeur
    Team(std::ifstream& infile);
    
    //使用默认构造函数Utiliser le constructeur par défaut
    Team() = default;
    
    //不支持对象的拷贝和赋值La copie et l’affectation de valeurs aux objets ne sont pas prises en charge
    Team(const Team& ) = delete;
    Team& operator=(const Team& ) = delete;
    
    //支持移动对象Prise en charge des objets en mouvement
    Team(Team&&);
    Team& operator=(Team&& );
    
    //析构函数Destructeur
    virtual ~Team();
    
    
public:
    //通过名称检索成员， 如"mi"  ,返回姓名中含有"mi"的所有成员，不区分大小写
	//Récupérer les membres par nom, tel que « mi », pour renvoyer tous les membres dont le nom contient « mi », sans distinction majuscules/minuscules
    virtual bool findByName(const std::string& , std::vector<Member*>& );
    //添加成员Ajouter des membres
    virtual bool AddMembers(Member*);
    //删除成员Supprimer un membre
    virtual bool RemoveMembers(Member*);
    //返回成员数量Renvoie le nombre de membres
    virtual size_t getCount()const;
    
    
    //返回类名Renvoie le nom de la classe
    virtual std::string getTypeName()const;
    
    //返回team对象的信息Renvoie des informations sur l'objet "team"
    virtual std::string toString()const;
};