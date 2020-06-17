#ifndef SimG4Core_EventAction_H
#define SimG4Core_EventAction_H

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "SimG4Core/Notification/interface/G4SimEvent.h"
#include "SimG4Core/Notification/interface/SimTrackManager.h"
#include "SimG4Core/Notification/interface/TrackWithHistory.h"
#include "SimG4Core/Notification/interface/TrackContainer.h" 
#include "SimG4Core/Notification/interface/SimActivityRegistry.h" 

#include "G4UserEventAction.hh"

#include <vector>
#include <map>
#include <string>
#include "TH1F.h"
#include "TFile.h"

class SimRunInterface;
class BeginOfEvent;
class EndOfEvent;
class CMSSteppingVerbose;
 
class EventAction: public G4UserEventAction
{
public:
    
    //TFile*   m_WeightsFile;
    //TH1F*    m_MuonWeights;
    explicit EventAction(const edm::ParameterSet& ps,
			 SimRunInterface*, SimTrackManager*,
			 CMSSteppingVerbose*);
    ~EventAction() override;

    void BeginOfEventAction(const G4Event * evt) override;
    void SetWeight(double weight);
    double Weight();
    void EndOfEventAction(const G4Event * evt) override;

    void abortEvent();

    inline const TrackContainer * trackContainer() const { 
      return m_trackManager->trackContainer();
    }

    inline void addTrack(TrackWithHistory* iTrack, bool inHistory, bool withAncestor) {
      m_trackManager->addTrack(iTrack, inHistory, withAncestor);
    }

    void addTkCaloStateInfo(uint32_t t,
			    const std::pair<math::XYZVectorD,math::XYZTLorentzVectorD>& p);

    inline void prepareForNewPrimary() { m_trackManager->cleanTracksWithHistory(); }

    SimActivityRegistry::BeginOfEventSignal m_beginOfEventSignal;
    SimActivityRegistry::EndOfEventSignal m_endOfEventSignal;

    void SetDBremFlag(bool flag);
    int nevents;
private:

    SimRunInterface* m_runInterface;
    SimTrackManager* m_trackManager;
    CMSSteppingVerbose* m_SteppingVerbose;
    std::string m_stopFile;
    bool m_printRandom;
    bool m_debug;
    bool DBremFlag;
};

#endif


