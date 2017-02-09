#include "Dif.h"
#include "Types.h"
Dif::Dif(const double& x,const double& y, int DifId, const double& xy, const double& xz,const double& yz, const int& nbr, const int& up_down, const int& DifType):_PositionX(x),_PositionY(y),_DifId(DifId),_AngleXY(xy),_AngleXZ(xz),_AngleYZ(yz),_nbrPlate(nbr),_up_down(up_down),_DifType(DifType)
{
  switch ( DifType ) 
  {
    case pad:
      _AsicNbr=24;
      break;
    case positional:
      _AsicNbr=2;
      break;
    case temporal:
      _AsicNbr=2;
      break;
    case tcherenkov:
      _AsicNbr=1;
      break;
    case tricot:
      _AsicNbr=3;
      break;
    case scintillator:
      _AsicNbr=1;
      break;
    case BIF:
      _AsicNbr=1;
      break;
    case M3:
      _AsicNbr=48;
      break;
    default:
      _AsicNbr=48;
      break;
  }
};

double Dif::GetPositionX()
{
  return _PositionX;
}
  
double Dif::GetPositionY()
{
  return _PositionY;
}
  
int Dif::GetDifId()
{
  return _DifId;
}
  
double Dif::GetAngleXY()
{
  return _AngleXY;
}
  
double Dif::GetAngleXZ()
{
  return _AngleXZ;
}
  
double Dif::GetAngleYZ()
{
  return _AngleYZ;
}
  
int Dif::GetNbrPlate()
{
  return _nbrPlate;
}
  
int Dif::GetDifType()
{ 
  return _DifType;
}
  
int Dif::GetDifUpDown()
{
  return _up_down;
}

int Dif::GetAsicNbr()
{
  return _AsicNbr;
}
