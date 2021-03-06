// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
/////////////////////////////////////////////////////////////
// ComputeEngine.hh
//
// Mike Dixon, EOL, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// March 2012
//
///////////////////////////////////////////////////////////////
//
// ComputeEngine computation - for multi-threading
// There is one object per thread.
//
///////////////////////////////////////////////////////////////

#ifndef ComputeEngine_HH
#define ComputeEngine_HH

#include "Params.hh"
#include <radar/KdpFilt.hh>
#include <radar/NcarParticleId.hh>
#include <radar/TempProfile.hh>
#include <radar/AtmosAtten.hh>
#include <radar/IntfLocator.hh>
#include <radar/SeaClutter.hh>
#include <radar/PhidpProc.hh>
#include <Radx/RadxArray.hh>
#include <Radx/RadxTime.hh>
#include <radar/InterestMap.hh>

class RadxRay;
class RadxField;
#include <pthread.h>
using namespace std;

class ComputeEngine {
  
public:
  
  // constructor
  
  ComputeEngine(const Params &params, int id);

  // destructor
  
  ~ComputeEngine();

  // compute for given input ray
  // storing results in derived ray
  //
  // Creates derived ray and returns it.
  // It must be freed by caller.
  //
  // Returns NULL on error.
  
  RadxRay *compute(RadxRay *inputRay,
                   double radarHtKm,
                   double wavelengthM,
                   const TempProfile *tempProfile);

  bool OK;
  
protected:
private:

  static const double missingDbl;
  const Params &_params;
  int _id;

  // current ray properties
  
  time_t _timeSecs;
  double _nanoSecs;
  double _azimuth;
  double _elevation;

  // radar properties

  double _radarHtKm;
  double _wavelengthM;

  // moments field data
  
  int _nGates;
  double _startRangeKm, _gateSpacingKm;
  double _nyquist;
  
  // input arrays for moments and derived products

  RadxArray<double> _snrArray_;
  RadxArray<double> _dbzArray_;
  RadxArray<double> _velArray_;
  RadxArray<double> _widthArray_;
  RadxArray<double> _ncpArray_;
  RadxArray<double> _zdrArray_;
  RadxArray<double> _zdpArray_;
  RadxArray<double> _ldrArray_;
  RadxArray<double> _rhohvArray_;
  RadxArray<double> _phidpArray_;
  RadxArray<double> _kdpArray_;
  RadxArray<double> _dbzElevGradientArray_;

  double *_snrArray;
  double *_dbzArray;
  double *_velArray;
  double *_widthArray;
  double *_ncpArray;
  double *_zdrArray;
  double *_zdpArray;
  double *_ldrArray;
  double *_rhohvArray;
  double *_phidpArray;
  double *_kdpArray;
  double *_dbzElevGradientArray;

  RadxArray<int> _pidArray_;
  RadxArray<double> _pidInterest_;
  RadxArray<double> _tempForPid_;
  RadxArray<bool> _pidCensorFlag_;
  RadxArray<bool> _inputCensorFlag_;
  RadxArray<bool> _combinedCensorFlag_;

  int *_pidArray;
  double *_pidInterest;
  double *_tempForPid;
  bool *_pidCensorFlag;
  bool *_inputCensorFlag;
  bool *_combinedCensorFlag;
  int _nWarnCensorPrint;

  // atmospheric attenuation

  AtmosAtten _atmos;

  // kdp and phidp

  KdpFilt _kdp;
  PhidpProc _phidp;

  // temperature profile

  const TempProfile *_tempProfile;

  // RLAN interference

  IntfLocator _intf;
  vector<InterestMap::ImPoint> _rlanImapPhaseNoise;
  vector<InterestMap::ImPoint> _rlanImapNcpMean;
  vector<InterestMap::ImPoint> _rlanImapWidthMean;
  vector<InterestMap::ImPoint> _rlanImapSnrDMode;
  vector<InterestMap::ImPoint> _rlanImapZdrSdev;

  // sea clutter

  SeaClutter _seaclut;
  vector<InterestMap::ImPoint> _seaclutImapRhohvMean;
  vector<InterestMap::ImPoint> _seaclutImapPhidpSdev;
  vector<InterestMap::ImPoint> _seaclutImapZdrSdev;
  vector<InterestMap::ImPoint> _seaclutImapDbzElevGradient;
  bool _dbzElevGradientAvail;

  // pid

  NcarParticleId _pid;

  // debug printing
  
  static pthread_mutex_t _debugPrintMutex;

  // private methods
  
  const RadxField *_getField(const RadxRay *inputRay,
                             const string &fieldName);
  
  void _loadOutputFields(RadxRay *inputRay,
                         RadxRay *derivedRay);
    
  void _allocArrays();

  void _kdpInit();
  void _kdpCompute();

  int _rlanInit();
  void _locateRlan();

  int _seaclutInit();
  void _locateSeaClutter();
  
  int _pidInit();
  void _pidCompute();
  
  int _loadMomentsArrays(RadxRay *inputRay);
  int _loadFieldArray(RadxRay *inputRay,
                      const string &fieldName,
                      bool required,
                      double *array);

  void _computeZdpArray();

  void _computeSnrFromDbz();

  void _censorOnRlan();
  void _censorOnSeaClutter();
  void _censorOnPid();
  void _setInputCensoringFlag(RadxRay &inputRay);
  void _censorOnInputFields();
  void _censorOnCombinedFlag(RadxField &field);

  int _convertInterestParamsToVector(const string &label,
                                     const Params::interest_map_point_t *map,
                                     int nPoints,
                                     vector<InterestMap::ImPoint> &pts);

  void _fillInCensorGaps();
  void _ignoreShortCensorRuns();

};

#endif
