#pragma once
#include "Processor.h"
#include <vector>
#include <map>
#include "IMPL/LCCollectionVec.h"
#include "UTIL/CellIDEncoder.h"
#include "UTIL/CellIDDecoder.h"
#include "IMPL/CalorimeterHitImpl.h"
#include "EVENT/RawCalorimeterHit.h" 
#include "ConstructConverters.h"
#include "TH2F.h"
using namespace lcio ;

class IJKfiller : public Processor
{
  public:
    virtual Processor*  newProcessor()
    {
      return new IJKfiller ;
    }
    IJKfiller() ;
    ~IJKfiller(){};
    virtual void init() ;
    virtual void processRunHeader( LCRunHeader* run ) ;
    virtual void processEvent( LCEvent * evt ) ;
    virtual void end() ;
    void FillIJK(RawCalorimeterHit*, LCCollectionVec*,CellIDEncoder<CalorimeterHitImpl>&,CellIDDecoder<RawCalorimeterHit>&);
    std::map<int,bool>Warningg;
    std::vector<std::string> _hcalCollections;
    std::map<std::vector<long long int>,std::map< long long int, long long int>>Negative;
    ConstructConverters* converter;
    std::vector<TH2F*> _myTH2={};
};
