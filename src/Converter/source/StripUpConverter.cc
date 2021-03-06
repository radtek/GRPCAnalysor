#include "StripUpConverter.h"
#include <vector>
#define size_strip 2.5
#define length_strip 320

int StripUpConverter::RawToIInPlate(int Asic_Id,int Channel)
{
  return (2*Channel);
}

int StripUpConverter::RawToJInPlate(int Asic_Id,int Channel)
{
  return Asic_Id;
}

int StripUpConverter::RawToI(int Dif_Id,int Asic_Id,int Channel)
{
  return RawToIInPlate(Asic_Id,Channel)+geom->GetDifPositionX(Dif_Id);
}

int StripUpConverter::RawToJ(int Dif_Id,int Asic_Id,int Channel)
{
  return RawToJInPlate(Asic_Id,Channel)+geom->GetDifPositionY(Dif_Id);
}

int StripUpConverter::RawToK(int Dif_Id,int Asic_Id,int Channel)
{
  if(geom->GetDifNbrPlate(Dif_Id)==-1) return 0;
  return geom->GetDifNbrPlate(Dif_Id);
}

float StripUpConverter::IJKToX(int I,int J,int K)
{
  CosSin(K);
  double Z= geom->GetPlatePositionZ(K);
	if(J%2==1) return cg*cb*I*size_strip+(-sg*ca+cg*sb*sa)*J*size_strip+(sg*sa+cg*sb*ca)*Z+geom->GetPlatePositionX(K)+1 ;
  else return cg*cb*I*size_strip+(-sg*ca+cg*sb*sa)*J*size_strip+(sg*sa+cg*sb*ca)*Z+geom->GetPlatePositionX(K);
}

float StripUpConverter::IJKToY(int I,int J,int K)
{
  CosSin(K);
  double Z= geom->GetPlatePositionZ(K);
	J=length_strip*1.0/2;
  return sg*cb*I*size_strip+(cg*ca+sg*sb*sa)*J*size_strip+(-cg*sa+sg*sb*ca)*Z+geom->GetPlatePositionY(K);
}
    
float StripUpConverter::IJKToZ(int I,int J,int K)
{
  CosSin(K);
  double Z= geom->GetPlatePositionZ(K);
  return -sb*I*size_strip+cb*sa*J*size_strip+cb*ca*Z;
}
