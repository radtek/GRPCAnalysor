#pragma once
#include <map>
#include <vector>
#include "Processor.h"
#include "EVENT/RawCalorimeterHit.h"
#include "IMPL/LCCollectionVec.h"
#include "UTIL/CellIDEncoder.h"
#include "IMPL/CalorimeterHitImpl.h"
#include "EVENT/LCRunHeader.h"
#include "IMPL/LCEventImpl.h"
#include <set>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

class Trivent : public Processor
{
public:
    Trivent();
    ~Trivent();
    Processor *newProcessor()
    {
        return new Trivent();
    }
    void init();
    void processEvent(EVENT::LCEvent *evtP);
    void processRunHeader( LCRunHeader* run);
    void end();
    inline void FillTimes();
private:  
    std::vector<std::string> _hcalCollections;
    int _timeWin;
    int _TimeWin_Noise;
    std::map<int,int>Times;
    int _TriggerTime;
    unsigned int TouchedEvents;
    unsigned int EventsSelected;
    unsigned int eventtotal;
    int _Time_from_Track;
    unsigned int _eventNr;
    int _trig_count;
    int _noiseCut;
    int _LayerCut;
    LCWriter* _EventWriter;
    std::map<int,bool>Warningg;
    std::string _outFileName;
    std::map< int,std::vector<CalorimeterHit*> > RawHits;
};
