#pragma once
#include <string>
#include <map>
class ElogInformations
{
  public:
    void AddBruteValue(std::string key,std::string value);
    void ConstructMaps();
    std::map<std::string,std::string> BruteValues;
    std::map<int,double> HV;
    std::map<int,std::string> GasChannel;
    std::map<int,std::string> HVChannel;
    std::map<int,std::string> Type;
  private:
};
