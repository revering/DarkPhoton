#ifndef MCHistograms_h
#define MCHistograms_h

#include <vector>
#include <map>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/CSCRecHit/interface/CSCSegmentCollection.h"
#include "DataFormats/HcalRecHit/interface/HBHERecHit.h"
#include "DataFormats/HcalRecHit/interface/HBHEChannelInfo.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/Common/interface/SortedCollection.h"

class TH1F;
class TH2F;

class MCHistograms{
  public:
    MCHistograms();

    void book(edm::Service<TFileService> fs);
    void PlotTrackDisappearance(double TrackP, double TrackEta, double TrackPhi, double minDR, double minTotalImpactParameter, double TrackP_dR, double TrackEta_dR, double TrackPhi_dR);
    void PlotCSCHits(const edm::Event& iEvent, const edm::EventSetup& iSetup, edm::EDGetTokenT<CSCSegmentCollection> CSCSegment_Label);
    void PlotHCALHits(const edm::Event& iEvent, const edm::EventSetup& iSetup, edm::EDGetTokenT<edm::SortedCollection<HBHERecHit,edm::StrictWeakOrdering<HBHERecHit> >> HBHERecHit_Label);
    void Normalize();
    void IncCutFlow();
    void ResetCutFlow();
  public:
    TH1F* m_eventCount;
    TH1F* m_cutProgress;
    
    TH1F* m_MuonTrackMass;
    TH1F* m_MuonEtaDist;
    TH1F* m_TrackPt;
    TH1F* m_MissHitTrackPt;
    TH1F* m_ConeHits;
    TH1F* m_ConeEnergy;
    TH1F* m_HitsOverThresh;
    TH2F* m_DBremLocation;
    TH2F* m_WeightedDBremLocation;
    TH1F* m_DeflectingAngle;
    TH1F* m_initialMuE;
    TH1F* m_finalMuE;
    TH1F* m_initialMuPt;
    TH1F* m_finalMuPt;
    TH1F* m_dphoEnergy;
    TH1F* m_TrackMotherdE;
    TH1F* m_TrackMotherdR;
    TH1F* m_FractionalELost;
    TH2F* m_CSCHits_EtaPhi;
    TH1F* m_HitDepth_MuonHCAL;
    int cutProgress;
    TH1F* m_BremDepth;
    TH1F* m_WeightedBremDepth;
    TH1F* m_HitsOverThreshSplit[7];
    TH1F* m_Depth_Spectra[7];
    TH1F* m_BremSpectrum;
    TH1F* m_CSC_dR;
    TH1F* m_NThreshCut;
    TH1F* m_TrackerVGlobal;
    TH1F* m_MuonMotherdE;
    TH1F* m_MuonMotherdR;
    TH1F* m_CSCHitChiSq;
    TH1F* m_CSCHitAngleChange;
    TH1F* m_StandaloneMuonE;
    TH1F* m_GlobalMuonE;
    TH1F* m_StandalonedE;
    TH1F* m_NonMatchedE;
    TH2F* m_NonMatchedLocation;
    TH2F* m_MatchedLocation;
    TH2F* m_NonMatchedLocationEtaPhi;
    TH1F* m_NonMatchedHitsOverThresh;
    TH1F* m_NonMatchedHEDeposit;
    TH1F* m_NonMatchedCSC;
    TH1F* m_NHitStandalonedR;
    TH1F* m_NHitStandaloneMuonE;
    TH1F* m_NHitStandalonedE;
    TH2F* m_BigCSCLocations;
    TH1F* m_LowEHCAL;
    TH1F* m_NStandalone;
    TH1F* m_NMatchStandaloneDr;
    TH1F* m_NMatchStandaloneDE;
    TH1F* m_NMatchStandaloneE;
    TH1F* m_StandalonePlusHCALDE;
    TH2F* m_NMatchNHitLocation;
    TH1F* m_NMatchNHitEnergy;
    TH1F* m_NMatchNHitHCALEnergy;
    TH1F* m_NMatchVertexOffset;   
    TH1F* m_AllVertexOffset;
    TH1F* m_NStandaloneAdjacentHitEnergies;
    TH1F* m_AdjacentFailHitEnergy;
    TH1F* m_NStandaloneAdjacentFailHitEnergy;
    TH1F* m_EventWeights;
    TH1F* m_SignalSelectionCuts;
    TH1F* m_DBremR;
    TH1F* m_WeightedDBremR;
    TH1F* m_NMatchNStandaloneHitsOverThresh;
};

#endif
