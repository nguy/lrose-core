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
////////////////////////////////////////////////////////////
// MdvDist2NonMissing.hh
//
// MdvDist2NonMissing object
//
// Sue Dettling, RAP, NCAR
// P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// October 2008
//
///////////////////////////////////////////////////////////////
//
// MdvDist2NonMissing 
//
///////////////////////////////////////////////////////////////////////

#ifndef MDVDIST2NONMISSING_HH
#define MDVDIST2NONMISSING_HH

#include <string>
#include <math.h>
#include <Mdv/MdvxField.hh> 
#include <Mdv/DsMdvx.hh>
#include <Mdv/MdvxPjg.hh>
#include <dataport/port_types.h>
#include <toolsa/pmu.h>
#include <toolsa/DateTime.hh>
#include <dsdata/DsLdataTrigger.hh>
#include <dsdata/DsTimeListTrigger.hh>
#include <dsdata/DsFileListTrigger.hh>
#include <dsdata/DsSpecificFcstLdataTrigger.hh>
#include <dsdata/DsTrigger.hh>
#include <dsdata/TriggerInfo.hh>
#include "Args.hh"
#include "Params.hh"

using namespace std;

#define MDVDIST2NONMISSING_EPSILON .00000001

////////////////////////
// 
// This class
//

class MdvDist2NonMissing {
  
public:

  //
  // constructor
  //
  MdvDist2NonMissing (int argc, char **argv);

  //
  // destructor
  //
  ~MdvDist2NonMissing();

  
  int Run();

  //
  // public data member
  //
  bool isOK;

protected:
   
private:

  //
  // data members
  //
  string _progName;

  char *_paramsPath;

  Args _args;

  Params _params;

  DsTrigger *_trigger;
  
  MdvxProj _gridProjection;

  DsMdvx _mdv;

  DsMdvx::field_header_t _fieldHdr;

  DsMdvx::master_header_t _masterHdr;

  int _dataArraySize;

  int _nx;

  int _ny;

  float _grid_dx;
  
  float*_fieldData;

  float _missing;

  float _bad;

  float *_dist;
  
  //
  // methods
  //
  void _clear();
 
  int _processData(time_t input_time, int leadTime, const string filepath); 

  int _readMdv( time_t requestTime, int leadTime, const string filepath);
  
  int _getFieldData();

  int _findDistances();

  int _writeMdv();

  int _setMasterHeader(const DsMdvx::master_header_t &masterHdr);

  int _setFieldHeader(const DsMdvx::field_header_t &fieldHdr);
};

#endif

