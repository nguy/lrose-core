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
 * precip_map_tdrp.c
 *
 * TDRP C code file 'precip_map' module.
 *
 * Code for program precip_map
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "precip_map_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[33];
static precip_map_tdrp_struct *Params;
static char *Module = "precip_map";

/*************************************************************
 * precip_map_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   precip_map_tdrp_struct *params: loads up this struct
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

int precip_map_tdrp_load_from_args(int argc, char **argv,
                         precip_map_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  precip_map_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * precip_map_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than precip_map_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   precip_map_tdrp_struct *params: loads up this struct
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

int precip_map_tdrp_load(char *param_file_path,
               precip_map_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  precip_map_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * precip_map_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See precip_map_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int precip_map_tdrp_load_defaults(precip_map_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  precip_map_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * precip_map_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void precip_map_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * precip_map_tdrp_print()
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

void precip_map_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * precip_map_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int precip_map_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * precip_map_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int precip_map_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * precip_map_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void precip_map_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * precip_map_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int precip_map_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * precip_map_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int precip_map_tdrp_array2D_realloc(char *param_name,
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
 * precip_map_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *precip_map_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * precip_map_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *precip_map_tdrp_init(precip_map_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  precip_map_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(precip_map_tdrp_struct));
  params->struct_size = sizeof(precip_map_tdrp_struct);

  /* Parameter 'debug' */
  /* ctype is 'precip_map_debug' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("Debug option");
  tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("debug");
  tt->enum_def.nfields = 4;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
    tt->enum_def.fields[0].val = DEBUG_OFF;
    tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_WARNINGS");
    tt->enum_def.fields[1].val = DEBUG_WARNINGS;
    tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_NORM");
    tt->enum_def.fields[2].val = DEBUG_NORM;
    tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_EXTRA");
    tt->enum_def.fields[3].val = DEBUG_EXTRA;
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
  /* ctype is 'precip_map_mode' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("mode");
  tt->descr = tdrpStrDup("Operation mode");
  tt->help = tdrpStrDup("Program may be run in two modes, archive and realtime. In realtime mode, the analysis is performed for each volume scan as it becomes available. In archiv mode, all of the scans in a track file are processed");
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
  
  /* Parameter 'map_type' */
  /* ctype is 'precip_map_map_type' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("map_type");
  tt->descr = tdrpStrDup("Map type");
  tt->help = tdrpStrDup("Map type may be 1) FORECAST - from advecting reflectivity using storm tracks, 2) PERSISTENCE - from current reflectivity for entire forecast period, 3) VERIFY  - from on the actual reflectivity data, 4) REFL_FORECAST - forecast of refl. at the forecast duration, 5) ACCUM_PERIOD - precip accumulation for specified duration (accum_duration), 6) ACCUM_FROM_START - precip accumulation from start.");
  tt->val_offset = (char *) &(pp.map_type) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("map_type");
  tt->enum_def.nfields = 6;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("FORECAST");
    tt->enum_def.fields[0].val = FORECAST;
    tt->enum_def.fields[1].name = tdrpStrDup("PERSISTENCE");
    tt->enum_def.fields[1].val = PERSISTENCE;
    tt->enum_def.fields[2].name = tdrpStrDup("VERIFY");
    tt->enum_def.fields[2].val = VERIFY;
    tt->enum_def.fields[3].name = tdrpStrDup("REFL_FORECAST");
    tt->enum_def.fields[3].val = REFL_FORECAST;
    tt->enum_def.fields[4].name = tdrpStrDup("ACCUM_PERIOD");
    tt->enum_def.fields[4].val = ACCUM_PERIOD;
    tt->enum_def.fields[5].name = tdrpStrDup("ACCUM_FROM_START");
    tt->enum_def.fields[5].val = ACCUM_FROM_START;
  tt->single_val.e = FORECAST;
  tt++;
  
  /* Parameter 'thresholded_forecast' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("thresholded_forecast");
  tt->descr = tdrpStrDup("Option to produce thresholded forecast");
  tt->help = tdrpStrDup("Thresholded forecast uses individual storm motion. Unthresholded forecast uses area-weighted mean storm motion");
  tt->val_offset = (char *) &(pp.thresholded_forecast) - (char *) &pp;
  tt->single_val.b = pTRUE;
  tt++;
  
  /* Parameter 'min_area_unthresholded' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("min_area_unthresholded");
  tt->descr = tdrpStrDup("Min area for unthresholded forecast");
  tt->help = tdrpStrDup("For unthresholded forecasts, the storms areas are summed. The sum must exceed the min area for a valid forecast. If not, forecast speed is set to 0");
  tt->val_offset = (char *) &(pp.min_area_unthresholded) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.d = 1;
  tt->single_val.d = 100;
  tt++;
  
  /* Parameter 'smoothing_radius' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("smoothing_radius");
  tt->descr = tdrpStrDup("Smoothing radius for unthresholded refl forecast");
  tt->help = tdrpStrDup("For unthresholded reflectivity forecasts, the motion for a storm is applied to the forecast grid in a manner which will move the individual storm elements, as well as the elements of the grid adjacent to the storm. All points within a distance of proj_area_major_radius from the storm centroid are given a velocity equal to storm speed. Points outside this radius but within a concentric radius given by (proj_area_major_radius + smoothing radius) are given a lesser velocity - the velocity decreases linearly from storm velocity at the inner radius to 0 at the outer radius.");
  tt->val_offset = (char *) &(pp.smoothing_radius) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.d = 1;
  tt->single_val.d = 50;
  tt++;
  
  /* Parameter 'write_motion_grid_files' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("write_motion_grid_files");
  tt->descr = tdrpStrDup("Option to write debug motion grids for precip forecast");
  tt->help = tdrpStrDup("If set, the motion grids are written to motion_grid_dir.");
  tt->val_offset = (char *) &(pp.write_motion_grid_files) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'motion_grid_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("motion_grid_dir");
  tt->descr = tdrpStrDup("Directory for motion grid files");
  tt->help = tdrpStrDup("The motion grid files reside in this directory.");
  tt->val_offset = (char *) &(pp.motion_grid_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup(".");
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
  
  /* Parameter 'composite_min_altitude' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("composite_min_altitude");
  tt->descr = tdrpStrDup("Min altitude CAPPI used in composite (km).");
  tt->help = tdrpStrDup("All maps are based on composite reflectivity. This altitude forms the base CAPPI for the composite. Only CAPPI's above this are used in making the composite.");
  tt->val_offset = (char *) &(pp.composite_min_altitude) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.d = 0;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'composite_max_altitude' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("composite_max_altitude");
  tt->descr = tdrpStrDup("Max altitude CAPPI used in composite (km).");
  tt->help = tdrpStrDup("All maps are based on composite reflectivity. This altitude forms the top CAPPI for the composite. Only CAPPI's below this are used in making the composite.");
  tt->val_offset = (char *) &(pp.composite_max_altitude) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.d = 0;
  tt->single_val.d = 25;
  tt++;
  
  /* Parameter 'rdata_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("rdata_dir");
  tt->descr = tdrpStrDup("Radar data directory");
  tt->help = tdrpStrDup("Upper level directory for dobson cartesian radar data files");
  tt->val_offset = (char *) &(pp.rdata_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("none");
  tt++;
  
  /* Parameter 'storms_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("storms_dir");
  tt->descr = tdrpStrDup("Storms data directory");
  tt->help = tdrpStrDup("Directory for storm and track data files");
  tt->val_offset = (char *) &(pp.storms_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("none");
  tt++;
  
  /* Parameter 'map_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("map_dir");
  tt->descr = tdrpStrDup("Precip map directory");
  tt->help = tdrpStrDup("Upper level directory for dobson precip map files");
  tt->val_offset = (char *) &(pp.map_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("none");
  tt++;
  
  /* Parameter 'output_file_ext' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("output_file_ext");
  tt->descr = tdrpStrDup("Output file extension");
  tt->help = tdrpStrDup("File name extension for dobson cartesian radar data files");
  tt->val_offset = (char *) &(pp.output_file_ext) - (char *) &pp;
  tt->is_private = TRUE;
  tt->single_val.s = tdrpStrDup("mdv");
  tt++;
  
  /* Parameter 'dbz_field' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("dbz_field");
  tt->descr = tdrpStrDup("Reflectivity field position");
  tt->help = tdrpStrDup("Position of reflectivity (dBZ) data in the radar volumes");
  tt->val_offset = (char *) &(pp.dbz_field) - (char *) &pp;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'min_dbz' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("min_dbz");
  tt->descr = tdrpStrDup("Min dbz value");
  tt->help = tdrpStrDup("For reflectivity forecasts, reflectivity values below this are not used.");
  tt->val_offset = (char *) &(pp.min_dbz) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = -50;
  tt->max_val.d = 100;
  tt->single_val.d = -30;
  tt++;
  
  /* Parameter 'low_refl_threshold' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("low_refl_threshold");
  tt->descr = tdrpStrDup("Low reflectivity threshold (dBZ).");
  tt->help = tdrpStrDup("Reflectivity below this threshold is ignored.");
  tt->val_offset = (char *) &(pp.low_refl_threshold) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = -40;
  tt->max_val.d = 70;
  tt->single_val.d = 10;
  tt++;
  
  /* Parameter 'hail_refl_threshold' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("hail_refl_threshold");
  tt->descr = tdrpStrDup("Hail reflectivity threshold (dBZ).");
  tt->help = tdrpStrDup("The threshold between rain and hail.");
  tt->val_offset = (char *) &(pp.hail_refl_threshold) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 40;
  tt->max_val.d = 70;
  tt->single_val.d = 55;
  tt++;
  
  /* Parameter 'get_zr_from_file' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("get_zr_from_file");
  tt->descr = tdrpStrDup("Option to use separate file for Z-R");
  tt->help = tdrpStrDup("If set, the Z-R parameters are obtained from a file residing in the zr_dir directory.");
  tt->val_offset = (char *) &(pp.get_zr_from_file) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'zr_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("zr_dir");
  tt->descr = tdrpStrDup("Directory for ZR files");
  tt->help = tdrpStrDup("The ZR files reside in this directory.");
  tt->val_offset = (char *) &(pp.zr_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup(".");
  tt++;
  
  /* Parameter 'ZR' */
  /* ctype is 'precip_map_ZR' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRUCT_TYPE;
  tt->param_name = tdrpStrDup("ZR");
  tt->descr = tdrpStrDup("Z-R parameters");
  tt->help = tdrpStrDup("Parameters in Z-R relationship");
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
    tt->struct_vals[0].d = 0;
    tt->struct_vals[1].d = 0;
  tt++;
  
  /* Parameter 'time_to_ground' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("time_to_ground");
  tt->descr = tdrpStrDup("Time delay for precip to hit ground (secs)");
  tt->help = tdrpStrDup("This delay is used to drift the reflectivity before computing the precipitation");
  tt->val_offset = (char *) &(pp.time_to_ground) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0;
  tt->max_val.d = 10800;
  tt->single_val.d = 120;
  tt++;
  
  /* Parameter 'forecast_durations' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("forecast_durations");
  tt->descr = tdrpStrDup("Forecast durations (secs)");
  tt->help = tdrpStrDup("Array of duration of precip forecast map. For REFL_FORECAST map_type and file_time_stamp FORECAST_TIME, all durations are used. For all other cases, only the first duration is used, the rest are ignored.");
  tt->val_offset = (char *) &(pp.forecast_durations.val) - (char *) &pp;
  tt->len_offset = (char *) &(pp.forecast_durations.len) - (char *) &pp;
  tt->array_offset = (char *) &(pp._forecast_durations) - (char *) &pp;
  tt->array_n_offset = (char *) &(pp.forecast_durations_n) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->is_array = TRUE;
  tt->array_len_fixed = FALSE;
  tt->array_elem_size = sizeof(double);
  tt->array_n = 1;
  tt->min_val.d = 0;
  tt->max_val.d = 10800;
  tt->array_vals = (tdrpVal_t *)
      tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
    tt->array_vals[0].d = 1800;
  tt++;
  
  /* Parameter 'accum_duration' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("accum_duration");
  tt->descr = tdrpStrDup("Accumulation duration (secs)");
  tt->help = tdrpStrDup("Duration of precip accumulation map. ACCUM_PERIOD map_type only.");
  tt->val_offset = (char *) &(pp.accum_duration) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0;
  tt->max_val.d = 10800;
  tt->single_val.d = 1800;
  tt++;
  
  /* Parameter 'scan_interval' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("scan_interval");
  tt->descr = tdrpStrDup("Radar vol scan interval (secs)");
  tt->help = tdrpStrDup("Interval between radar volume scans (secs)");
  tt->val_offset = (char *) &(pp.scan_interval) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0;
  tt->max_val.d = 1800;
  tt->single_val.d = 360;
  tt++;
  
  /* Parameter 'file_time_stamp' */
  /* ctype is 'precip_map_file_time_stamp' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("file_time_stamp");
  tt->descr = tdrpStrDup("File time stamp - REFL_FORECAST map_type only");
  tt->help = tdrpStrDup("If GENERATE_TIME, file names match generate data time. If FORECAST_TIME, file names match forecast time. This applies only to the REFL_FORECAST map_type.");
  tt->val_offset = (char *) &(pp.file_time_stamp) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("file_time_stamp");
  tt->enum_def.nfields = 2;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("GENERATE_TIME");
    tt->enum_def.fields[0].val = GENERATE_TIME;
    tt->enum_def.fields[1].name = tdrpStrDup("FORECAST_TIME");
    tt->enum_def.fields[1].val = FORECAST_TIME;
  tt->single_val.e = GENERATE_TIME;
  tt++;
  
  /* Parameter 'round_forecast_times' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("round_forecast_times");
  tt->descr = tdrpStrDup("Option to round the forecast times");
  tt->help = tdrpStrDup("Option to round the forecast times. The interval used is given by parameter rounding_interval");
  tt->val_offset = (char *) &(pp.round_forecast_times) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'rounding_interval' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("rounding_interval");
  tt->descr = tdrpStrDup("Rounding interval for forecast times (secs)");
  tt->help = tdrpStrDup("If round_forecast_times is TRUE, the forecast times are rounded to this interval");
  tt->val_offset = (char *) &(pp.rounding_interval) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 10;
  tt->max_val.d = 86400;
  tt->single_val.d = 600;
  tt++;
  
  /* Parameter 'overwrite' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("overwrite");
  tt->descr = tdrpStrDup("Option to force file overwrites.");
  tt->help = tdrpStrDup("If set, previously generated files will be overwritten whenever the program is rerun on the same date set in REALTIME mode. In ARCHIVE mode, overwrites always occur. IF file_time_stamp is set to FORECAST_TIME, overwrites always occur.");
  tt->val_offset = (char *) &(pp.overwrite) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}
