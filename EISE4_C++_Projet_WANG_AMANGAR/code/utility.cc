#include "utility.hh"
#include <sstream>
#include <cctype>
void split(std::vector<std::string>& tokens, const std::string& line, char delim )
{
    std::string token;
    std::istringstream tokenStream(line);
    while (std::getline(tokenStream, token, delim))
        tokens.push_back(token);
}

std::string LCase(const std::string& s)
{
    std::string s2;
    
    for(auto i = 0u; i < s.size(); ++i)
        s2 +=  static_cast<char>( tolower(s[i]) ) ;
    return s2;
}