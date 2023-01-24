#pragma once

#include <vector>
#include <string>

//通过一个分割符，分割字符串，将结果保存到vector容器里， 例如 split(v,"abf;34;41;3333",';')   被分成4个字串 v = { "abf","34","41","3333"}
//Divisez la chaîne avec un séparateur et enregistrez le résultat dans le conteneur vectoriel, par exemple split(v,"abf; 34; 41; 3333",'; ') est divisé en 4 chaînes v = { « abf »,"34 »,"41 »,"3333"}
void split(std::vector<std::string>& tokens, const std::string& line, char delim = ' ');

//将字符串小写化  如  LCase("BAe123")  返回 "bae123"
//// Minuscule la chaîne telle que LCase("BAe123") renvoie "bae123"
std::string LCase(const std::string& s);