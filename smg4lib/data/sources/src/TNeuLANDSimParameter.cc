#include "TNeuLANDSimParameter.hh"

#include <iostream>
#include <math.h>

ClassImp(TNeuLANDSimParameter)
//____________________________________________________________________
TNeuLANDSimParameter::TNeuLANDSimParameter(TString name)
: TSimParameter(name),
  fIsLoaded(false),
  fNeutNum(0), fVetoNum(0), fLayerNum(0), fSubLayerNum(0), 
  fNeutNumPerLayer(0), fVetoNumPerLayer(0), 
  fPosition(0,0,0), fNeutSize(12,180,12), fVetoSize(32,1,190), 
  fSize(200,200,200), fAngle(0,0,0),
  fTimeReso(0.15*sqrt(2)),// ns
  fV_scinti(150),   //mm/ns
  fAttLen_Neut(3473),// mm
  fAttLen_Veto(2580),// mmm
  fQ_factor(1)
{
  std::cout<<"TNeuLANDSimParameter"<<std::endl;
}
//____________________________________________________________________
TNeuLANDSimParameter::~TNeuLANDSimParameter()
{;}
//____________________________________________________________________
TDetectorSimParameter*  TNeuLANDSimParameter::FindDetectorSimParameter(Int_t id)
{
  std::map<int, TDetectorSimParameter>::iterator it
    = fNeuLANDDetectorParameterMap.find(id);
  if (it==fNeuLANDDetectorParameterMap.end()) return 0;
  return &(it->second);
}
//____________________________________________________________________
std::ostream& operator<<(std::ostream& out,  const TNeuLANDSimParameter& prm)
{
  out << prm.GetName() <<": "
      << "fIsLoaded="       <<prm.fIsLoaded <<" "
      << "fNeutNum="        <<prm.fNeutNum <<" "
      << "fVetoNum="        <<prm.fVetoNum <<" "
      << "fLayerNum="       <<prm.fLayerNum      <<" "
      << "fSubLayerNum="    <<prm.fSubLayerNum   <<" "
      << "fNeutNumPerLayer="<<prm.fNeutNumPerLayer <<" "
      << "fVetoNumPerLayer="<<prm.fVetoNumPerLayer <<" "
      << "fPosition="       <<prm.fPosition.x() <<" "<<prm.fPosition.y() <<" "<<prm.fPosition.z() <<" "
      << "fNeutSize="       <<prm.fNeutSize.x() <<" "<<prm.fNeutSize.y() <<" "<<prm.fNeutSize.z() <<" "
      << "fVetoSize="       <<prm.fVetoSize.x() <<" "<<prm.fVetoSize.y() <<" "<<prm.fVetoSize.z() <<" "
      << "fAngle="          <<prm.fAngle.x()<<" "<<prm.fAngle.y()<<" "<<prm.fAngle.z()<<" "
      << "fTimeReso="       <<prm.fTimeReso<<" "
      << "fQ_factor="       <<prm.fQ_factor<<" ";
  return out;
}
//____________________________________________________________________
void TNeuLANDSimParameter::Print(Option_t*) const
{
  std::cout << GetName() <<": "
	    << "fIsLoaded="       <<fIsLoaded <<": "
	    << "fNeutNum="        <<fNeutNum <<" "
	    << "fVetoNum="        <<fVetoNum <<" "
	    << "fLayerNum="       <<fLayerNum      <<" "
	    << "fSubLayerNum="    <<fSubLayerNum   <<" "
	    << "fNeutNumPerLayer="<<fNeutNumPerLayer <<" "
	    << "fVetoNumPerLayer="<<fVetoNumPerLayer <<" "
	    << "fPosition="       <<fPosition.x() <<" "<<fPosition.y() <<" "<<fPosition.z() <<" "
	    << "fNeutSize="       <<fNeutSize.x() <<" "<<fNeutSize.y() <<" "<<fNeutSize.z() <<" "
	    << "fVetoSize="       <<fVetoSize.x() <<" "<<fVetoSize.y() <<" "<<fVetoSize.z() <<" "
	    << "fAngle="          <<fAngle.x()<<" "<<fAngle.y()<<" "<<fAngle.z()<<" "
            << "fTimeReso="       <<fTimeReso<<" "
            << "fQ_factor="       <<fQ_factor<<" "
	    << std::endl;
}
//____________________________________________________________________
