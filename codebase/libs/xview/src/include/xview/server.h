/*      @(#)server.h 20.61 93/06/28 SMI      */

/*
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL_NOTICE 
 *	file for terms of the license.
 */

#ifndef xview_server_DEFINED
#define xview_server_DEFINED

/*
 ***********************************************************************
 *			Include Files
 ***********************************************************************
 */

#include <xview/generic.h>

/*
 ***********************************************************************
 *			Definitions and Macros
 ***********************************************************************
 */

/*
 * PUBLIC #defines 
 */

#ifndef XV_ATTRIBUTES_ONLY
#define	SERVER				&xv_server_pkg
#endif /* ~XV_ATTRIBUTES_ONLY */

/*
 * PRIVATE #defines 
 */

#define RECT_STRUCT_SIZE		4
#define	SERVER_ATTR(type, ordinal)	ATTR(ATTR_PKG_SERVER, type, ordinal)

/*
 ***********************************************************************
 *		Typedefs, Enumerations, and Structures
 ***********************************************************************
 */

typedef enum kbd_cmds_values {
    KBD_CMDS_SUNVIEW1 = 0,
    KBD_CMDS_BASIC = 1,
    KBD_CMDS_FULL = 2
} Kbd_cmds_value;

#ifndef XV_ATTRIBUTES_ONLY

typedef	Xv_opaque 	Xv_Server;
typedef	Xv_opaque 	Xv_server;

typedef struct {
    Xv_generic_struct	parent;
    Xv_opaque		private_data;
} Xv_server_struct;

#endif /* ~XV_ATTRIBUTES_ONLY */

typedef enum {
	/* Public attributes */
	__SERVER_ATOM			= SERVER_ATTR(ATTR_LONG,	108),
	__SERVER_ATOM_NAME		= SERVER_ATTR(ATTR_OPAQUE,	109),
	__SERVER_ATOM_DATA		= SERVER_ATTR(ATTR_OPAQUE,	113),
	__SERVER_CHORDING_TIMEOUT	= SERVER_ATTR(ATTR_INT,		242),
	__SERVER_CHORD_MENU		= SERVER_ATTR(ATTR_INT,		244),
	__SERVER_EXTENSION_PROC		= SERVER_ATTR(ATTR_FUNCTION_PTR,4),
	__SERVER_NTH_SCREEN		= SERVER_ATTR(ATTR_INT_PAIR,	 2),
        __SERVER_RESOURCE_DB            = SERVER_ATTR(ATTR_OPAQUE,      246),
	__SERVER_SYNC			= SERVER_ATTR(ATTR_BOOLEAN,	32),
	__SERVER_SYNC_AND_PROCESS_EVENTS= SERVER_ATTR(ATTR_NO_VALUE,	33),
	__SERVER_EXTERNAL_XEVENT_PROC   = SERVER_ATTR(ATTR_OPAQUE_PAIR, 20),
	__SERVER_EXTERNAL_XEVENT_MASK   = SERVER_ATTR(ATTR_OPAQUE_TRIPLE, 22),

	/* Private attributes */
	__SERVER_ASCII_KEYSTATE		= SERVER_ATTR(ATTR_OPAQUE,	 7),
	__SERVER_ASCII_MAP		= SERVER_ATTR(ATTR_OPAQUE,	12),
	__SERVER_ASCII_TO_KEYCODE_MAP	= SERVER_ATTR(ATTR_OPAQUE,	 6),
	__SERVER_CUT_KEYSYM		= SERVER_ATTR(ATTR_INT,		10),
	__SERVER_FONT_WITH_NAME		= SERVER_ATTR(ATTR_STRING, 	 11),
	__SERVER_JOURNAL_SYNC_EVENT 	= SERVER_ATTR(ATTR_INT,		38),
	__SERVER_JOURNALLING		= SERVER_ATTR(ATTR_BOOLEAN,	36),
	__SERVER_KEY_EVENTS_MAP 	= SERVER_ATTR(ATTR_OPAQUE,	 5),
	__SERVER_NONASCII_KEYSTATE	= SERVER_ATTR(ATTR_OPAQUE,	 8),
	__SERVER_PASTE_KEYSYM		= SERVER_ATTR(ATTR_INT,		16),
	__SERVER_SEMANTIC_MAP		= SERVER_ATTR(ATTR_OPAQUE,	14),
	__SERVER_XV_MAP 		= SERVER_ATTR(ATTR_OPAQUE,	13),
	__SERVER_COMPOSE_STATUS         = SERVER_ATTR(ATTR_OPAQUE,      15),
	__SERVER_PRIVATE_XEVENT_PROC    = SERVER_ATTR(ATTR_OPAQUE_PAIR, 23),
	__SERVER_PRIVATE_XEVENT_MASK    = SERVER_ATTR(ATTR_OPAQUE_TRIPLE, 24),
	__SERVER_CLEAR_MODIFIERS     	= SERVER_ATTR(ATTR_INT,		50),
        /* ACC_XVIEW */
	__SERVER_ACCELERATOR_MAP	= SERVER_ATTR(ATTR_OPAQUE,	101),
	__SERVER_ADD_ACCELERATOR_MAP	= SERVER_ATTR(ATTR_OPAQUE_PAIR, 104),
	__SERVER_REMOVE_ACCELERATOR_MAP	= SERVER_ATTR(ATTR_OPAQUE_PAIR, 106),
        /* ACC_XVIEW */
	__SERVER_DISPLAY_CONTEXT	= SERVER_ATTR(ATTR_INT,		111),
#ifdef OW_I18N
	__SERVER_COMPOUND_TEXT           = SERVER_ATTR(ATTR_OPAQUE, 	249),
#endif /* OW_I18N */

	/* Private attributes that may be deleted in future revisions */
	__SERVER_WM_RESCALE		= SERVER_ATTR(ATTR_OPAQUE,	25),
	__SERVER_WM_RESCALE_STATE	= SERVER_ATTR(ATTR_OPAQUE,	17),
	__SERVER_WM_STATE		= SERVER_ATTR(ATTR_OPAQUE,	21),
	__SERVER_WM_TAKE_FOCUS		= SERVER_ATTR(ATTR_OPAQUE,	30),
	__SERVER_WM_WINDOW_MOVED	= SERVER_ATTR(ATTR_OPAQUE,	28),
	__SERVER_WM_WIN_ATTR		= SERVER_ATTR(ATTR_OPAQUE,	34),
	__SERVER_WM_ADD_DECOR		= SERVER_ATTR(ATTR_OPAQUE,	35),
	__SERVER_WM_DELETE_DECOR	= SERVER_ATTR(ATTR_OPAQUE,	40),
	__SERVER_WM_DECOR_CLOSE		= SERVER_ATTR(ATTR_OPAQUE,	45),
	__SERVER_WM_DECOR_FOOTER	= SERVER_ATTR(ATTR_OPAQUE,	55),
	__SERVER_WM_DECOR_RESIZE	= SERVER_ATTR(ATTR_OPAQUE,	60),
	__SERVER_WM_DECOR_HEADER	= SERVER_ATTR(ATTR_OPAQUE,	65),
	__SERVER_WM_DECOR_OK		= SERVER_ATTR(ATTR_OPAQUE,	70),
	__SERVER_WM_DECOR_PIN		= SERVER_ATTR(ATTR_OPAQUE,	75),
	__SERVER_WM_SCALE_SMALL		= SERVER_ATTR(ATTR_OPAQUE,	80),
	__SERVER_WM_SCALE_MEDIUM	= SERVER_ATTR(ATTR_OPAQUE,	85),
	__SERVER_WM_SCALE_LARGE		= SERVER_ATTR(ATTR_OPAQUE,	90),
	__SERVER_WM_SCALE_XLARGE	= SERVER_ATTR(ATTR_OPAQUE,	95),
	__SERVER_WM_PIN_STATE		= SERVER_ATTR(ATTR_OPAQUE,	100),
	__SERVER_WM_WIN_BUSY		= SERVER_ATTR(ATTR_OPAQUE,	105),
	__SERVER_DND_ACK_KEY		= SERVER_ATTR(ATTR_INT,		107),
	__SERVER_WM_WINMSG_STATE	= SERVER_ATTR(ATTR_OPAQUE,	110),
	__SERVER_WM_WINMSG_ERROR	= SERVER_ATTR(ATTR_OPAQUE,	115),
	__SERVER_WM_WT_BASE		= SERVER_ATTR(ATTR_OPAQUE,	121),
	__SERVER_WM_WT_CMD		= SERVER_ATTR(ATTR_OPAQUE,	125),
	__SERVER_WM_WT_PROP		= SERVER_ATTR(ATTR_OPAQUE,	130),
	__SERVER_WM_WT_HELP		= SERVER_ATTR(ATTR_OPAQUE,	135),
	__SERVER_WM_WT_NOTICE		= SERVER_ATTR(ATTR_OPAQUE,	140),
	__SERVER_WM_WT_OTHER		= SERVER_ATTR(ATTR_OPAQUE,	145),
	__SERVER_WM_MENU_FULL		= SERVER_ATTR(ATTR_OPAQUE,	150),
	__SERVER_WM_MENU_LIMITED	= SERVER_ATTR(ATTR_OPAQUE,	155),
	__SERVER_WM_NONE		= SERVER_ATTR(ATTR_OPAQUE,	160),
	__SERVER_WM_PIN_IN		= SERVER_ATTR(ATTR_OPAQUE,	165),
	__SERVER_WM_PIN_OUT		= SERVER_ATTR(ATTR_OPAQUE,	170),
	__SERVER_DO_DRAG_MOVE		= SERVER_ATTR(ATTR_OPAQUE,	120),
	__SERVER_DO_DRAG_COPY		= SERVER_ATTR(ATTR_OPAQUE,	122),
	__SERVER_DO_DRAG_LOAD		= SERVER_ATTR(ATTR_OPAQUE,	123),
	__SERVER_JOURNAL_SYNC_ATOM 	= SERVER_ATTR(ATTR_INT,		125),
	__SERVER_WM_DISMISS		= SERVER_ATTR(ATTR_OPAQUE,	200),
	__SERVER_WM_SAVE_YOURSELF	= SERVER_ATTR(ATTR_OPAQUE,	210),
	__SERVER_WM_DEFAULT_BUTTON      = SERVER_ATTR(ATTR_OPAQUE,      220),
	__SERVER_WM_PROTOCOLS		= SERVER_ATTR(ATTR_OPAQUE,	225),
	__SERVER_WM_DELETE_WINDOW	= SERVER_ATTR(ATTR_OPAQUE,	230),
	__SERVER_WM_COMMAND		= SERVER_ATTR(ATTR_OPAQUE,	235),
	__SERVER_WM_CHANGE_STATE	= SERVER_ATTR(ATTR_OPAQUE,	240),
	__SERVER_MOUSE_BUTTONS		= SERVER_ATTR(ATTR_SHORT,       250),
	__SERVER_BUTTON2_MOD		= SERVER_ATTR(ATTR_INT,		252),
	__SERVER_BUTTON3_MOD		= SERVER_ATTR(ATTR_INT,		254),
	__SERVER_META_MOD_MASK		= SERVER_ATTR(ATTR_INT,		  9),
	__SERVER_ALT_MOD_MASK		= SERVER_ATTR(ATTR_INT,		248),
	__SERVER_NUM_LOCK_MOD_MASK	= SERVER_ATTR(ATTR_INT,		247),
	__SERVER_SEL_MOD_MASK		= SERVER_ATTR(ATTR_INT,		251),
	__SERVER_FOCUS_TIMESTAMP   	= SERVER_ATTR(ATTR_INT,		203)
} Server_attr;

#define SERVER_ATOM ((Attr_attribute) __SERVER_ATOM)
#define SERVER_ATOM_NAME ((Attr_attribute) __SERVER_ATOM_NAME)
#define SERVER_ATOM_DATA ((Attr_attribute) __SERVER_ATOM_DATA)
#define SERVER_CHORDING_TIMEOUT ((Attr_attribute) __SERVER_CHORDING_TIMEOUT)
#define SERVER_CHORD_MENU ((Attr_attribute) __SERVER_CHORD_MENU)
#define SERVER_EXTENSION_PROC ((Attr_attribute) __SERVER_EXTENSION_PROC)
#define SERVER_NTH_SCREEN ((Attr_attribute) __SERVER_NTH_SCREEN)
#define SERVER_RESOURCE_DB ((Attr_attribute) __SERVER_RESOURCE_DB)
#define SERVER_SYNC ((Attr_attribute) __SERVER_SYNC)
#define SERVER_SYNC_AND_PROCESS_EVENTS ((Attr_attribute) __SERVER_SYNC_AND_PROCESS_EVENTS)
#define SERVER_EXTERNAL_XEVENT_PROC ((Attr_attribute) __SERVER_EXTERNAL_XEVENT_PROC)
#define SERVER_EXTERNAL_XEVENT_MASK ((Attr_attribute) __SERVER_EXTERNAL_XEVENT_MASK)
#define SERVER_ASCII_KEYSTATE ((Attr_attribute) __SERVER_ASCII_KEYSTATE)
#define SERVER_ASCII_MAP ((Attr_attribute) __SERVER_ASCII_MAP)
#define SERVER_ASCII_TO_KEYCODE_MAP ((Attr_attribute) __SERVER_ASCII_TO_KEYCODE_MAP)
#define SERVER_CUT_KEYSYM ((Attr_attribute) __SERVER_CUT_KEYSYM)
#define SERVER_FONT_WITH_NAME ((Attr_attribute) __SERVER_FONT_WITH_NAME)
#define SERVER_JOURNAL_SYNC_EVENT ((Attr_attribute) __SERVER_JOURNAL_SYNC_EVENT)
#define SERVER_JOURNALLING ((Attr_attribute) __SERVER_JOURNALLING)
#define SERVER_KEY_EVENTS_MAP ((Attr_attribute) __SERVER_KEY_EVENTS_MAP)
#define SERVER_NONASCII_KEYSTATE ((Attr_attribute) __SERVER_NONASCII_KEYSTATE)
#define SERVER_PASTE_KEYSYM ((Attr_attribute) __SERVER_PASTE_KEYSYM)
#define SERVER_SEMANTIC_MAP ((Attr_attribute) __SERVER_SEMANTIC_MAP)
#define SERVER_XV_MAP ((Attr_attribute) __SERVER_XV_MAP)
#define SERVER_COMPOSE_STATUS ((Attr_attribute) __SERVER_COMPOSE_STATUS)
#define SERVER_PRIVATE_XEVENT_PROC ((Attr_attribute) __SERVER_PRIVATE_XEVENT_PROC)
#define SERVER_PRIVATE_XEVENT_MASK ((Attr_attribute) __SERVER_PRIVATE_XEVENT_MASK)
#define SERVER_CLEAR_MODIFIERS ((Attr_attribute) __SERVER_CLEAR_MODIFIERS)
#define SERVER_ACCELERATOR_MAP ((Attr_attribute) __SERVER_ACCELERATOR_MAP)
#define SERVER_ADD_ACCELERATOR_MAP ((Attr_attribute) __SERVER_ADD_ACCELERATOR_MAP)
#define SERVER_REMOVE_ACCELERATOR_MAP ((Attr_attribute) __SERVER_REMOVE_ACCELERATOR_MAP)
#define SERVER_DISPLAY_CONTEXT ((Attr_attribute) __SERVER_DISPLAY_CONTEXT)

#ifdef OW_I18N
#define SERVER_COMPOUND_TEXT ((Attr_attribute) __SERVER_COMPOUND_TEXT)
#endif /* OW_I18N */

#define SERVER_WM_RESCALE ((Attr_attribute) __SERVER_WM_RESCALE)
#define SERVER_WM_RESCALE_STATE ((Attr_attribute) __SERVER_WM_RESCALE_STATE)
#define SERVER_WM_STATE ((Attr_attribute) __SERVER_WM_STATE)
#define SERVER_WM_TAKE_FOCUS ((Attr_attribute) __SERVER_WM_TAKE_FOCUS)
#define SERVER_WM_WINDOW_MOVED ((Attr_attribute) __SERVER_WM_WINDOW_MOVED)
#define SERVER_WM_WIN_ATTR ((Attr_attribute) __SERVER_WM_WIN_ATTR)
#define SERVER_WM_ADD_DECOR ((Attr_attribute) __SERVER_WM_ADD_DECOR)
#define SERVER_WM_DELETE_DECOR ((Attr_attribute) __SERVER_WM_DELETE_DECOR)
#define SERVER_WM_DECOR_CLOSE ((Attr_attribute) __SERVER_WM_DECOR_CLOSE)
#define SERVER_WM_DECOR_FOOTER ((Attr_attribute) __SERVER_WM_DECOR_FOOTER)
#define SERVER_WM_DECOR_RESIZE ((Attr_attribute) __SERVER_WM_DECOR_RESIZE)
#define SERVER_WM_DECOR_HEADER ((Attr_attribute) __SERVER_WM_DECOR_HEADER)
#define SERVER_WM_DECOR_OK ((Attr_attribute) __SERVER_WM_DECOR_OK)
#define SERVER_WM_DECOR_PIN ((Attr_attribute) __SERVER_WM_DECOR_PIN)
#define SERVER_WM_SCALE_SMALL ((Attr_attribute) __SERVER_WM_SCALE_SMALL)
#define SERVER_WM_SCALE_MEDIUM ((Attr_attribute) __SERVER_WM_SCALE_MEDIUM)
#define SERVER_WM_SCALE_LARGE ((Attr_attribute) __SERVER_WM_SCALE_LARGE)
#define SERVER_WM_SCALE_XLARGE ((Attr_attribute) __SERVER_WM_SCALE_XLARGE)
#define SERVER_WM_PIN_STATE ((Attr_attribute) __SERVER_WM_PIN_STATE)
#define SERVER_WM_WIN_BUSY ((Attr_attribute) __SERVER_WM_WIN_BUSY)
#define SERVER_DND_ACK_KEY ((Attr_attribute) __SERVER_DND_ACK_KEY)
#define SERVER_WM_WINMSG_STATE ((Attr_attribute) __SERVER_WM_WINMSG_STATE)
#define SERVER_WM_WINMSG_ERROR ((Attr_attribute) __SERVER_WM_WINMSG_ERROR)
#define SERVER_WM_WT_BASE ((Attr_attribute) __SERVER_WM_WT_BASE)
#define SERVER_WM_WT_CMD ((Attr_attribute) __SERVER_WM_WT_CMD)
#define SERVER_WM_WT_PROP ((Attr_attribute) __SERVER_WM_WT_PROP)
#define SERVER_WM_WT_HELP ((Attr_attribute) __SERVER_WM_WT_HELP)
#define SERVER_WM_WT_NOTICE ((Attr_attribute) __SERVER_WM_WT_NOTICE)
#define SERVER_WM_WT_OTHER ((Attr_attribute) __SERVER_WM_WT_OTHER)
#define SERVER_WM_MENU_FULL ((Attr_attribute) __SERVER_WM_MENU_FULL)
#define SERVER_WM_MENU_LIMITED ((Attr_attribute) __SERVER_WM_MENU_LIMITED)
#define SERVER_WM_NONE ((Attr_attribute) __SERVER_WM_NONE)
#define SERVER_WM_PIN_IN ((Attr_attribute) __SERVER_WM_PIN_IN)
#define SERVER_WM_PIN_OUT ((Attr_attribute) __SERVER_WM_PIN_OUT)
#define SERVER_DO_DRAG_MOVE ((Attr_attribute) __SERVER_DO_DRAG_MOVE)
#define SERVER_DO_DRAG_COPY ((Attr_attribute) __SERVER_DO_DRAG_COPY)
#define SERVER_DO_DRAG_LOAD ((Attr_attribute) __SERVER_DO_DRAG_LOAD)
#define SERVER_JOURNAL_SYNC_ATOM ((Attr_attribute) __SERVER_JOURNAL_SYNC_ATOM)
#define SERVER_WM_DISMISS ((Attr_attribute) __SERVER_WM_DISMISS)
#define SERVER_WM_SAVE_YOURSELF ((Attr_attribute) __SERVER_WM_SAVE_YOURSELF)
#define SERVER_WM_DEFAULT_BUTTON ((Attr_attribute) __SERVER_WM_DEFAULT_BUTTON)
#define SERVER_WM_PROTOCOLS ((Attr_attribute) __SERVER_WM_PROTOCOLS)
#define SERVER_WM_DELETE_WINDOW ((Attr_attribute) __SERVER_WM_DELETE_WINDOW)
#define SERVER_WM_COMMAND ((Attr_attribute) __SERVER_WM_COMMAND)
#define SERVER_WM_CHANGE_STATE ((Attr_attribute) __SERVER_WM_CHANGE_STATE)
#define SERVER_MOUSE_BUTTONS ((Attr_attribute) __SERVER_MOUSE_BUTTONS)
#define SERVER_BUTTON2_MOD ((Attr_attribute) __SERVER_BUTTON2_MOD)
#define SERVER_BUTTON3_MOD ((Attr_attribute) __SERVER_BUTTON3_MOD)
#define SERVER_META_MOD_MASK ((Attr_attribute) __SERVER_META_MOD_MASK)
#define SERVER_ALT_MOD_MASK ((Attr_attribute) __SERVER_ALT_MOD_MASK)
#define SERVER_NUM_LOCK_MOD_MASK ((Attr_attribute) __SERVER_NUM_LOCK_MOD_MASK)
#define SERVER_SEL_MOD_MASK ((Attr_attribute) __SERVER_SEL_MOD_MASK)
#define SERVER_FOCUS_TIMESTAMP ((Attr_attribute) __SERVER_FOCUS_TIMESTAMP)


/*
 ***********************************************************************
 *				Globals
 ***********************************************************************
 */

/*
 * PUBLIC variables 
 */
extern Xv_Server	xv_default_server;

/*
 * PRIVATE variables 
 */
#ifndef XV_ATTRIBUTES_ONLY
extern Xv_pkg		xv_server_pkg;
#endif /* ~XV_ATTRIBUTES_ONLY */

#endif /* ~xview_server_DEFINED */
