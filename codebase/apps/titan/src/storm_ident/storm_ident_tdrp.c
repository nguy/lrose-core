/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR (c) 1990 - 2016                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/*******************************************
 * storm_ident_tdrp.c
 *
 * TDRP C code file 'storm_ident' module.
 *
 * Code for program storm_ident
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "storm_ident_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[53];
static storm_ident_tdrp_struct *Params;
static char *Module = "storm_ident";

/*************************************************************
 * storm_ident_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   storm_ident_tdrp_struct *params: loads up this struct
 * 
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *   char **params_path_p: if non-NULL, this is set to point to
 *                         the path of the params file used.
 *
 *  Returns 0 on success, -1 on failure.
 */

int storm_ident_tdrp_load_from_args(int argc, char **argv,
                         storm_ident_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  storm_ident_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * storm_ident_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than storm_ident_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   storm_ident_tdrp_struct *params: loads up this struct
 *
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *  expand_env: flag to control environment variable
 *                expansion during tokenization.
 *              If TRUE, environment expansion is set on.
 *              If FALSE, environment expansion is set off.
 *
 *  Returns 0 on success, -1 on failure.
 */

int storm_ident_tdrp_load(char *param_file_path,
               storm_ident_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  storm_ident_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * storm_ident_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See storm_ident_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int storm_ident_tdrp_load_defaults(storm_ident_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  storm_ident_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * storm_ident_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void storm_ident_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * storm_ident_tdrp_print()
 * 
 * Print params file
 *
 * The modes supported are:
 *
 *   PRINT_SHORT:   main comments only, no help or descriptions
 *                  structs and arrays on a single line
 *   PRINT_NORM:    short + descriptions and help
 *   PRINT_LONG:    norm  + arrays and structs expanded
 *   PRINT_VERBOSE: long  + private params included
 */

void storm_ident_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * storm_ident_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int storm_ident_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * storm_ident_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int storm_ident_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * storm_ident_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void storm_ident_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * storm_ident_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int storm_ident_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * storm_ident_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int storm_ident_tdrp_array2D_realloc(char *param_name,
                          int new_array_n1,
                          int new_array_n2)
{
  if (tdrpArray2DRealloc(Table, Params, param_name,
			 new_array_n1, new_array_n2)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * storm_ident_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *storm_ident_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * storm_ident_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *storm_ident_tdrp_init(storm_ident_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  storm_ident_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(storm_ident_tdrp_struct));
  params->struct_size = sizeof(storm_ident_tdrp_struct);

  /* Parameter 'debug' */
  /* ctype is 'storm_ident_debug' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("Debug option");
  tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("debug");
  tt->enum_def.nfields = 3;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
    tt->enum_def.fields[0].val = DEBUG_OFF;
    tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
    tt->enum_def.fields[1].val = DEBUG_NORM;
    tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
    tt->enum_def.fields[2].val = DEBUG_VERBOSE;
  tt->single_val.e = DEBUG_OFF;
  tt++;
  
  /* Parameter 'malloc_debug_level' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("malloc_debug_level");
  tt->descr = tdrpStrDup("Malloc debug level");
  tt->help = tdrpStrDup("0 - none, 1 - corruption checking, 2 - records all malloc blocks and checks, 3 - printout of all mallocs etc.");
  tt->val_offset = (char *) &(pp.malloc_debug_level) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 0;
  tt->max_val.l = 3;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'instance' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("instance");
  tt->descr = tdrpStrDup("Process instance");
  tt->help = tdrpStrDup("Used for registration with procmap.");
  tt->val_offset = (char *) &(pp.instance) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Test");
  tt++;
  
  /* Parameter 'mode' */
  /* ctype is 'storm_ident_mode' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("mode");
  tt->descr = tdrpStrDup("Operating mode");
  tt->help = tdrpStrDup("In realtime mode, storm_ident waits for a new input file. In archive mode, it moves through the files between the times set by the user.");
  tt->val_offset = (char *) &(pp.mode) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("mode");
  tt->enum_def.nfields = 2;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
    tt->enum_def.fields[0].val = ARCHIVE;
    tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
    tt->enum_def.fields[1].val = REALTIME;
  tt->single_val.e = ARCHIVE;
  tt++;
  
  /* Parameter 'tracking' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("tracking");
  tt->descr = tdrpStrDup("Option to run tracking");
  tt->help = tdrpStrDup("If this is set, storm_ident will communicate with storm_track.");
  tt->val_offset = (char *) &(pp.tracking) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'start_storm_track' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("start_storm_track");
  tt->descr = tdrpStrDup("Option to start storm_track automatically");
  tt->help = tdrpStrDup("If this is set, storm_track will be started from within storm_ident.");
  tt->val_offset = (char *) &(pp.start_storm_track) - (char *) &pp;
  tt->single_val.b = pTRUE;
  tt++;
  
  /* Parameter 'storm_track_command_line' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("storm_track_command_line");
  tt->descr = tdrpStrDup("Command line for starting storm_track");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.storm_track_command_line) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("null");
  tt++;
  
  /* Parameter 'shmem_key' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("shmem_key");
  tt->descr = tdrpStrDup("Shared mem key.");
  tt->help = tdrpStrDup("This key is used for shared memory communication with storm_track and the track_server");
  tt->val_offset = (char *) &(pp.shmem_key) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.l = 10000;
  tt->single_val.l = 44000;
  tt++;
  
  /* Parameter 'rdata_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("rdata_dir");
  tt->descr = tdrpStrDup("Radar data directory - input");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.rdata_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("null");
  tt++;
  
  /* Parameter 'rdata_file_ext' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("rdata_file_ext");
  tt->descr = tdrpStrDup("Radar data files extension");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.rdata_file_ext) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("dob");
  tt++;
  
  /* Parameter 'storm_data_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("storm_data_dir");
  tt->descr = tdrpStrDup("Storms data directory - output");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.storm_data_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("null");
  tt++;
  
  /* Parameter 'projection' */
  /* ctype is 'storm_ident_projection' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("projection");
  tt->descr = tdrpStrDup("Input grid projection");
  tt->help = tdrpStrDup("This is the projection of the input radar data.");
  tt->val_offset = (char *) &(pp.projection) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("projection");
  tt->enum_def.nfields = 2;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("PROJ_FLAT");
    tt->enum_def.fields[0].val = PROJ_FLAT;
    tt->enum_def.fields[1].name = tdrpStrDup("PROJ_LATLON");
    tt->enum_def.fields[1].val = PROJ_LATLON;
  tt->single_val.e = PROJ_FLAT;
  tt++;
  
  /* Parameter 'dbz_field' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("dbz_field");
  tt->descr = tdrpStrDup("dBZ field");
  tt->help = tdrpStrDup("Field number in radar data for dBZ values.");
  tt->val_offset = (char *) &(pp.dbz_field) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.l = 0;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'vel_field' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("vel_field");
  tt->descr = tdrpStrDup("Vel field");
  tt->help = tdrpStrDup("Field number in radar data for velocity values.");
  tt->val_offset = (char *) &(pp.vel_field) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.l = 0;
  tt->single_val.l = 1;
  tt++;
  
  /* Parameter 'vel_available' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("vel_available");
  tt->descr = tdrpStrDup("Flag to indicate if velocity data is available");
  tt->help = tdrpStrDup("If this is set, velocity data is available in the vel_field.");
  tt->val_offset = (char *) &(pp.vel_available) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'low_dbz_threshold' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("low_dbz_threshold");
  tt->descr = tdrpStrDup("Lower dBZ threshold.");
  tt->help = tdrpStrDup("Storms reflectivity must exceed this threshold.");
  tt->val_offset = (char *) &(pp.low_dbz_threshold) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = -30;
  tt->max_val.d = 180;
  tt->single_val.d = 35;
  tt++;
  
  /* Parameter 'high_dbz_threshold' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("high_dbz_threshold");
  tt->descr = tdrpStrDup("Upper dBZ threshold.");
  tt->help = tdrpStrDup("Storms reflectivity must not exceed this threshold.");
  tt->val_offset = (char *) &(pp.high_dbz_threshold) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = -30;
  tt->max_val.d = 180;
  tt->single_val.d = 80;
  tt++;
  
  /* Parameter 'base_threshold' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("base_threshold");
  tt->descr = tdrpStrDup("Storm base threshold (km).");
  tt->help = tdrpStrDup("Storms identification is only performed above this threshold.");
  tt->val_offset = (char *) &(pp.base_threshold) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0;
  tt->max_val.d = 25;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'top_threshold' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("top_threshold");
  tt->descr = tdrpStrDup("Storm top threshold (km).");
  tt->help = tdrpStrDup("Storms identification is only performed below this threshold.");
  tt->val_offset = (char *) &(pp.top_threshold) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0;
  tt->max_val.d = 25;
  tt->single_val.d = 25;
  tt++;
  
  /* Parameter 'min_storm_size' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("min_storm_size");
  tt->descr = tdrpStrDup("Minimum storm size (km2 or km3 depending on data).");
  tt->help = tdrpStrDup("Storms must exceed this size.  If the data is 2D, the size is in km2 units; if the data is 3D, the size is in km3.  This parameter used to be called volume_threshold.");
  tt->val_offset = (char *) &(pp.min_storm_size) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.d = 0;
  tt->single_val.d = 30;
  tt++;
  
  /* Parameter 'max_storm_size' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("max_storm_size");
  tt->descr = tdrpStrDup("Maximum storm size (km2 or km3 depending on data).");
  tt->help = tdrpStrDup("Storms must not exceed this size.  If the data is 2D, the size is in km2; if the data is 3D, the size is in km3.  This parameter used to be called volume_limit.");
  tt->val_offset = (char *) &(pp.max_storm_size) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.d = 1;
  tt->single_val.d = 1e+09;
  tt++;
  
  /* Parameter 'check_range_limits' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("check_range_limits");
  tt->descr = tdrpStrDup("Option to check for storm range limits.");
  tt->help = tdrpStrDup("If the storm is at the limit of radar range, a flag is set.");
  tt->val_offset = (char *) &(pp.check_range_limits) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'check_second_trip' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("check_second_trip");
  tt->descr = tdrpStrDup("Option to check for second trip");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.check_second_trip) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'sectrip_vert_aspect' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("sectrip_vert_aspect");
  tt->descr = tdrpStrDup("Second trip detection vertical aspect threshold.");
  tt->help = tdrpStrDup("If the vertical aspect ratio exceeds this value, the storm is flagged as second-trip, provided the orientation is aligned with the storm azimuth from the radar.");
  tt->val_offset = (char *) &(pp.sectrip_vert_aspect) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 1;
  tt->max_val.d = 20;
  tt->single_val.d = 4;
  tt++;
  
  /* Parameter 'sectrip_horiz_aspect' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("sectrip_horiz_aspect");
  tt->descr = tdrpStrDup("Second trip detection horizontal aspect threshold.");
  tt->help = tdrpStrDup("If the horizontal aspect ratio (based on the ellipse) exceeds this value, the storm is flagged as second-trip, provided the orientation is aligned with the storm azimuth from the radar.");
  tt->val_offset = (char *) &(pp.sectrip_horiz_aspect) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 1;
  tt->max_val.d = 20;
  tt->single_val.d = 4;
  tt++;
  
  /* Parameter 'sectrip_orientation_error' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("sectrip_orientation_error");
  tt->descr = tdrpStrDup("Allowable second trip orientation error.");
  tt->help = tdrpStrDup("For a storm to be flagged as second-trip, the orientation must be aligned with the storm azimuth from the radar, within this allowable error.");
  tt->val_offset = (char *) &(pp.sectrip_orientation_error) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 1;
  tt->max_val.d = 90;
  tt->single_val.d = 10;
  tt++;
  
  /* Parameter 'hail_dbz_threshold' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("hail_dbz_threshold");
  tt->descr = tdrpStrDup("Hail reflectivity threshold");
  tt->help = tdrpStrDup("The threshold between rain and hail (dBZ)");
  tt->val_offset = (char *) &(pp.hail_dbz_threshold) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 40;
  tt->max_val.d = 70;
  tt->single_val.d = 55;
  tt++;
  
  /* Parameter 'ZR' */
  /* ctype is 'storm_ident_ZR' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRUCT_TYPE;
  tt->param_name = tdrpStrDup("ZR");
  tt->descr = tdrpStrDup("Z-R parameters");
  tt->help = tdrpStrDup("Parameters in Z-R relationship. As defaults use 200.0, 1.6");
  tt->val_offset = (char *) &(pp.ZR) - (char *) &pp;
  tt->struct_def.name = tdrpStrDup("ZR");
  tt->struct_def.nfields = 2;
  tt->struct_def.fields = (struct_field_t *)
      tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
    tt->struct_def.fields[0].ftype = tdrpStrDup("double");
    tt->struct_def.fields[0].fname = tdrpStrDup("coeff");
    tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[0].rel_offset = 
      (char *) &(pp.ZR.coeff) - (char *) &(pp.ZR);
    tt->struct_def.fields[1].ftype = tdrpStrDup("double");
    tt->struct_def.fields[1].fname = tdrpStrDup("expon");
    tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[1].rel_offset = 
      (char *) &(pp.ZR.expon) - (char *) &(pp.ZR);
  tt->n_struct_vals = 2;
  tt->struct_vals = (tdrpVal_t *)
      tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt->struct_vals[0].d = 200;
    tt->struct_vals[1].d = 1.6;
  tt++;
  
  /* Parameter 'ZM' */
  /* ctype is 'storm_ident_ZM' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRUCT_TYPE;
  tt->param_name = tdrpStrDup("ZM");
  tt->descr = tdrpStrDup("Z-M parameters");
  tt->help = tdrpStrDup("Parameters in Z-M relationship. As defaults use 20465.0, 1.75");
  tt->val_offset = (char *) &(pp.ZM) - (char *) &pp;
  tt->struct_def.name = tdrpStrDup("ZM");
  tt->struct_def.nfields = 2;
  tt->struct_def.fields = (struct_field_t *)
      tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
    tt->struct_def.fields[0].ftype = tdrpStrDup("double");
    tt->struct_def.fields[0].fname = tdrpStrDup("coeff");
    tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[0].rel_offset = 
      (char *) &(pp.ZM.coeff) - (char *) &(pp.ZM);
    tt->struct_def.fields[1].ftype = tdrpStrDup("double");
    tt->struct_def.fields[1].fname = tdrpStrDup("expon");
    tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[1].rel_offset = 
      (char *) &(pp.ZM.expon) - (char *) &(pp.ZM);
  tt->n_struct_vals = 2;
  tt->struct_vals = (tdrpVal_t *)
      tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt->struct_vals[0].d = 20465;
    tt->struct_vals[1].d = 1.75;
  tt++;
  
  /* Parameter 'dbz_hist_interval' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("dbz_hist_interval");
  tt->descr = tdrpStrDup("Dbz histogram interval.");
  tt->help = tdrpStrDup("Reflectivity interval for histogram computations related to the reflectivity distribution.");
  tt->val_offset = (char *) &(pp.dbz_hist_interval) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 1;
  tt->max_val.d = 10;
  tt->single_val.d = 3;
  tt++;
  
  /* Parameter 'store_storm_runs' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("store_storm_runs");
  tt->descr = tdrpStrDup("Option to store runs in storm file");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.store_storm_runs) - (char *) &pp;
  tt->single_val.b = pTRUE;
  tt++;
  
  /* Parameter 'store_proj_runs' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("store_proj_runs");
  tt->descr = tdrpStrDup("Option to store projected area runs in storm file");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.store_proj_runs) - (char *) &pp;
  tt->single_val.b = pTRUE;
  tt++;
  
  /* Parameter 'create_verification_files' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("create_verification_files");
  tt->descr = tdrpStrDup("Option to create verification files");
  tt->help = tdrpStrDup("If this is set, verification files will be stored in verify_dir.");
  tt->val_offset = (char *) &(pp.create_verification_files) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'verify_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("verify_dir");
  tt->descr = tdrpStrDup("Verify data directory - output");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.verify_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("null");
  tt++;
  
  /* Parameter 'check_morphology' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("check_morphology");
  tt->descr = tdrpStrDup("Option to check morphology");
  tt->help = tdrpStrDup("If this is set, morphology will be used for storm definition. A check is performed on storm morphology to reduce apparent mergers. The technique is as follows: 1. Compute euclidean distance (ed) of each point from edge of storm clump 2. Compute reflectivity excess above threshold, and divide by morphology_refl_divisor (in dbz/km). 3. Add ed to refl excess, to get interest map 4. Threshold interest map using morphology_erosion_threshold (in km). 5. Erode points which do not exceed the threshold, and which are not adjacent to a point which exceeds the threshold.");
  tt->val_offset = (char *) &(pp.check_morphology) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'create_morphology_files' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("create_morphology_files");
  tt->descr = tdrpStrDup("Option to create morphology files");
  tt->help = tdrpStrDup("If this is set, morphology files will be stored in morphology_dir.");
  tt->val_offset = (char *) &(pp.create_morphology_files) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'morphology_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("morphology_dir");
  tt->descr = tdrpStrDup("Morphology data directory - debugging");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.morphology_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("null");
  tt++;
  
  /* Parameter 'morphology_erosion_threshold' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("morphology_erosion_threshold");
  tt->descr = tdrpStrDup("Erosion threshold for morphology check (km).");
  tt->help = tdrpStrDup("Threshold to which morphology erosion is performed.");
  tt->val_offset = (char *) &(pp.morphology_erosion_threshold) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0;
  tt->max_val.d = 100;
  tt->single_val.d = 5;
  tt++;
  
  /* Parameter 'morphology_refl_divisor' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("morphology_refl_divisor");
  tt->descr = tdrpStrDup("Erosion threshold for morphology check (dbz/km).");
  tt->help = tdrpStrDup("The morphology field is obtained by adding the euclidean distance to storm edge (km) to the reflectivity excess (above threshold) divided by this value (dbz/km).");
  tt->val_offset = (char *) &(pp.morphology_refl_divisor) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0.1;
  tt->max_val.d = 100;
  tt->single_val.d = 10;
  tt++;
  
  /* Parameter 'check_tops' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("check_tops");
  tt->descr = tdrpStrDup("Option to check tops");
  tt->help = tdrpStrDup("If this is active, areas with radar tops below the threshold will be removed from the data prior to storm identification. The margin allows you to account for tilted storms, leaving a  margin around the area to be removed.");
  tt->val_offset = (char *) &(pp.check_tops) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'create_tops_files' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("create_tops_files");
  tt->descr = tdrpStrDup("Option to create tops files");
  tt->help = tdrpStrDup("If this is set, tops files will be stored in tops_dir.");
  tt->val_offset = (char *) &(pp.create_tops_files) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'tops_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("tops_dir");
  tt->descr = tdrpStrDup("Radar tops data directory - debugging");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.tops_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("null");
  tt++;
  
  /* Parameter 'min_radar_tops' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("min_radar_tops");
  tt->descr = tdrpStrDup("Minimum radar tops (km).");
  tt->help = tdrpStrDup("Minimum radar tops for valid radar data.");
  tt->val_offset = (char *) &(pp.min_radar_tops) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0;
  tt->max_val.d = 25;
  tt->single_val.d = 4.5;
  tt++;
  
  /* Parameter 'tops_edge_margin' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("tops_edge_margin");
  tt->descr = tdrpStrDup("Margin placed on min_tops field (km).");
  tt->help = tdrpStrDup("This takes into account the fact that some storms may be tilted.");
  tt->val_offset = (char *) &(pp.tops_edge_margin) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0;
  tt->max_val.d = 10;
  tt->single_val.d = 1.5;
  tt++;
  
  /* Parameter 'vel_to_m_per_sec_scale' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("vel_to_m_per_sec_scale");
  tt->descr = tdrpStrDup("Factor to convert velocity field to m/s.");
  tt->help = tdrpStrDup("This is included in case the velocity is not in m/s.");
  tt->val_offset = (char *) &(pp.vel_to_m_per_sec_scale) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.d = 0;
  tt->single_val.d = 1;
  tt++;
  
  /* Parameter 'max_missing_data_gap' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("max_missing_data_gap");
  tt->descr = tdrpStrDup("Max missing data gap (secs)");
  tt->help = tdrpStrDup("In archive mode, if reftime is set on the command line, storm_ident searches backwards from the reftime for data files with no time gaps exceeding max_missing_data_gap (secs), to search for the files for analysis. If starttime and endtime are set, these are used instead. In realtime mode, if auto_restart is false, storm_ident looks back from latest data time for the first gap exceeding max_missing_data_gap. Files since this gap are processed.");
  tt->val_offset = (char *) &(pp.max_missing_data_gap) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.d = 1;
  tt->single_val.d = 3600;
  tt++;
  
  /* Parameter 'max_realtime_valid_age' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("max_realtime_valid_age");
  tt->descr = tdrpStrDup("Max valid age of input files in realtime mode (secs)");
  tt->help = tdrpStrDup("This the max valid age for an incoming file. The program will wait for a data file more recent than this.");
  tt->val_offset = (char *) &(pp.max_realtime_valid_age) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.d = 1;
  tt->single_val.d = 360;
  tt++;
  
  /* Parameter 'auto_restart' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("auto_restart");
  tt->descr = tdrpStrDup("Auto-restart option");
  tt->help = tdrpStrDup("If set, the program restarts at restart_time (GMT), copying rome data so that tracks will have some history. This ensures that the storm and track files will not grow too big.");
  tt->val_offset = (char *) &(pp.auto_restart) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'restart_time' */
  /* ctype is 'storm_ident_restart_time' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRUCT_TYPE;
  tt->param_name = tdrpStrDup("restart_time");
  tt->descr = tdrpStrDup("The time in the day (UCT/GMT) at which restart occurs.");
  tt->help = tdrpStrDup("The program will check for the passing of this time. Once data beyond this time is found, restart will occur.\n");
  tt->val_offset = (char *) &(pp.restart_time) - (char *) &pp;
  tt->struct_def.name = tdrpStrDup("restart_time");
  tt->struct_def.nfields = 2;
  tt->struct_def.fields = (struct_field_t *)
      tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
    tt->struct_def.fields[0].ftype = tdrpStrDup("long");
    tt->struct_def.fields[0].fname = tdrpStrDup("hour");
    tt->struct_def.fields[0].ptype = LONG_TYPE;
    tt->struct_def.fields[0].rel_offset = 
      (char *) &(pp.restart_time.hour) - (char *) &(pp.restart_time);
    tt->struct_def.fields[1].ftype = tdrpStrDup("long");
    tt->struct_def.fields[1].fname = tdrpStrDup("min");
    tt->struct_def.fields[1].ptype = LONG_TYPE;
    tt->struct_def.fields[1].rel_offset = 
      (char *) &(pp.restart_time.min) - (char *) &(pp.restart_time);
  tt->n_struct_vals = 2;
  tt->struct_vals = (tdrpVal_t *)
      tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt->struct_vals[0].l = 0;
    tt->struct_vals[1].l = 0;
  tt++;
  
  /* Parameter 'restart_overlap_period' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("restart_overlap_period");
  tt->descr = tdrpStrDup("The period copied to the new file on restart (secs).");
  tt->help = tdrpStrDup("On restart, the program copies some of the previous file, to provide history for storm_track. This is the duration of that data.");
  tt->val_offset = (char *) &(pp.restart_overlap_period) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.l = 1;
  tt->single_val.l = 3600;
  tt++;
  
  /* Parameter 'remove_old_files_on_restart' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("remove_old_files_on_restart");
  tt->descr = tdrpStrDup("Cleanup on restart option");
  tt->help = tdrpStrDup("If set, the program will delete old storm files on restart.");
  tt->val_offset = (char *) &(pp.remove_old_files_on_restart) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'restart_no_delay' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("restart_no_delay");
  tt->descr = tdrpStrDup("Flag to force restart at first opportunity.");
  tt->help = tdrpStrDup("Normally the restart time will be set so that at least one day elapses before the restart. This flag forces the restart at the first opportunity.");
  tt->val_offset = (char *) &(pp.restart_no_delay) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}
