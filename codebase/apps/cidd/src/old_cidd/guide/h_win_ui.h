#ifndef	h_win_HEADER
#define	h_win_HEADER

/*
 * h_win_ui.h - User interface object and function declarations.
 * This file was generated by `gxv' from `h_win.G'.
 * DO NOT EDIT BY HAND.
 */

extern Attr_attribute	INSTANCE;


typedef struct {
	Xv_opaque	horiz_bw;
	Xv_opaque	cp;
	Xv_opaque	movie_start_st;
	Xv_opaque	field_st;
	Xv_opaque	zoom_st;
	Xv_opaque	movie_st;
	Xv_opaque	overlay_st;
	Xv_opaque	product_st;
	Xv_opaque	export_st;
	Xv_opaque	x_sect_st;
	Xv_opaque	field_sel_st;
	Xv_opaque	vector_st;
	Xv_opaque	movie_spd_sl;
	Xv_opaque	slice_sl;
	Xv_opaque	movie_frame_msg;
	Xv_opaque	cur_ht_msg;
	Xv_opaque	cur_time_msg;
	Xv_opaque	canvas1;
} h_win_horiz_bw_objects;

extern h_win_horiz_bw_objects	*h_win_horiz_bw_objects_initialize();

extern Xv_opaque	h_win_horiz_bw_horiz_bw_create();
extern Xv_opaque	h_win_horiz_bw_cp_create();
extern Xv_opaque	h_win_horiz_bw_movie_start_st_create();
extern Xv_opaque	h_win_horiz_bw_field_st_create();
extern Xv_opaque	h_win_horiz_bw_zoom_st_create();
extern Xv_opaque	h_win_horiz_bw_movie_st_create();
extern Xv_opaque	h_win_horiz_bw_overlay_st_create();
extern Xv_opaque	h_win_horiz_bw_product_st_create();
extern Xv_opaque	h_win_horiz_bw_export_st_create();
extern Xv_opaque	h_win_horiz_bw_x_sect_st_create();
extern Xv_opaque	h_win_horiz_bw_field_sel_st_create();
extern Xv_opaque	h_win_horiz_bw_vector_st_create();
extern Xv_opaque	h_win_horiz_bw_movie_spd_sl_create();
extern Xv_opaque	h_win_horiz_bw_slice_sl_create();
extern Xv_opaque	h_win_horiz_bw_movie_frame_msg_create();
extern Xv_opaque	h_win_horiz_bw_cur_ht_msg_create();
extern Xv_opaque	h_win_horiz_bw_cur_time_msg_create();
extern Xv_opaque	h_win_horiz_bw_canvas1_create();
#endif
