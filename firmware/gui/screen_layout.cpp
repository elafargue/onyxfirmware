#include "screen_layout.h"
#include "safecast_wirish_types.h"


// All ITEM_TYPES are defined in screen_layout.h


// Note: all entries in screen_layout are stored in flash to avoid
// wasting precious RAM with static data.

/**
 *  All entries in screens_layout follow this pattern (see screen_layout.h)
 *
 * {
 *   item_count,
 *   {
 *     { item_type, val1, val2, text, kanji_image },
 *     ...
 *   },
 *   help_menu (255 for no help)
 * }
 *
 *  Text can also be a reference to a value sent by the controller. It starts with a $
 *  as a convention
 *
 */

__FLASH__ screen screens_layout[SCREEN_COUNT] = {

// Screen 0 - main screen
{
 7,
 {
   { ITEM_TYPE_HEAD       , 0, 0, "$CPMDEADINT"    , 255},
   { ITEM_TYPE_MENU       ,15, 1, "Accumulate/Avg" ,6   },
   { ITEM_TYPE_MENU       ,21, 2, "Becquerel"      ,31  },
   { ITEM_TYPE_MENU_ACTION, 0, 3, "QR Tweet"       ,32  },
   { ITEM_TYPE_MENU       , 3, 5, "Settings"       , 0  },
   { ITEM_TYPE_SOFTKEY	  , 0, 1, "CPM"			   , 255},
   { ITEM_TYPE_SOFTKEY	  , 2, 25, "Logs"	       , 255},
 }
 ,0
},

// Screen 1 - Current readings screen
{
  7,
  {
    { ITEM_TYPE_HEAD        , 0 ,  0, "$CPMDEADINT", 255},
    { ITEM_TYPE_BIGVARLABEL , 0 , 30, "$CPMDEAD"   , 255},
    { ITEM_TYPE_VARLABEL    ,104, 90, "$CPMSLABEL" , 255},
    { ITEM_TYPE_RED_VARLABEL,  5, 80, "$X1000"     , 255},
    { ITEM_TYPE_SOFTKEY	  	, 0 ,  0, "Menu"	   , 255},
    { ITEM_TYPE_SOFTKEY	  	, 1 ,  2, "$SVREMLABEL"	, 255},
    { ITEM_TYPE_SOFTKEY_ACTION ,2, 0, "Beep"	, 255},
}
  ,0
},

// Screen 2  Micro Sievert readings screen
{
  6,
  {
    { ITEM_TYPE_HEAD        , 0 ,  0, "$CPMDEADINT" , 255},
    { ITEM_TYPE_BIGVARLABEL , 0 , 30, "$SVREM"      , 255},
    { ITEM_TYPE_VARLABEL    , 80, 90, "$SVREMLABEL" , 255},
    { ITEM_TYPE_SOFTKEY	    ,  0,  0, "Menu"		, 255},
    { ITEM_TYPE_SOFTKEY	    ,  1,  4, "Graph"		, 255},
    { ITEM_TYPE_SOFTKEY_ACTION,2,  0, "Beep"	    , 255},
}
  ,0
},

// Screen 3 - Settings menu
{
  6,
  {
    { ITEM_TYPE_HEAD       , 0, 0, "$CPMDEADINT", 255 },
    { ITEM_TYPE_MENU       ,16, 1, "Interface" , 8 },
    { ITEM_TYPE_MENU       ,17, 2, "Geiger"    , 9 },
    { ITEM_TYPE_MENU       , 9, 3, "Time/Date" , 13 },
    { ITEM_TYPE_MENU       ,18, 4, "Version"   , 14 },
    { ITEM_TYPE_SOFTKEY	    ,  0,  0, "Home"   , 255}
  }
  ,0
},


// Screen 4 - Graph display
{
  5,
  {
    { ITEM_TYPE_HEAD    , 0 , 0  , "$CPMDEADINT"    , 255 },
    { ITEM_TYPE_GRAPH   , 4 , 108, "$RECENTDATA"    , 255 },
    { ITEM_TYPE_SOFTKEY	  , 0, 0, "Menu"			, 255},
    { ITEM_TYPE_SOFTKEY	  , 1, 1, "CPM"				, 255},
    { ITEM_TYPE_SOFTKEY_ACTION	  , 2, 0, "Beep"			, 255},
  }
  ,0
},

//Screen 5 - Calibration Confirmation
{
  4,
  {
    { ITEM_TYPE_HEAD , 0 , 0  , "$CPMDEADINT"       , 255},
    { ITEM_TYPE_MENU , 6 , 3  , "       OK       " , 255},
    { ITEM_TYPE_MENU , 3 , 4  , "     Cancel     " , 18 },
    { ITEM_TYPE_LABEL,255, 16 , "Are you sure?"    , 19 }
  }
  ,0
},

//Screen 6 - Calibration Wait 1
{
  4,
  {
    { ITEM_TYPE_LABEL,255, 32, "Waiting for 15s" , 20  },
    { ITEM_TYPE_LABEL,255, 64, "Please expose"   , 21  },
    { ITEM_TYPE_LABEL,255, 80, "to source."      , 22  },
    { ITEM_TYPE_DELAY, 60,100, "$DELAYA\0 16,7"    , 255 } // 16 second delay, then go to screen 7
  }
  ,0
},

//Screen 7 - Calibration Wait 2
{
  2,
  {
    { ITEM_TYPE_LABEL,255, 32, "Acquiring, 30s" , 23  },
    { ITEM_TYPE_DELAY, 60,100, "$DELAYB\0 31,8"   , 255 } // 31 second delay
  }
  ,0
},


//Screen 8 - Calibration
{
  8,
  {
    { ITEM_TYPE_ACTION     ,  0,   0, "CALIBRATE" , 255 },
    { ITEM_TYPE_VARNUM     , 20, 50 , "$CAL1"      , 255 },
    { ITEM_TYPE_VARNUM     , 56, 50 , "$CAL2"      , 255 },
    { ITEM_TYPE_VARNUM     , 74, 50 , "$CAL3"      , 255 },
    { ITEM_TYPE_VARNUM     , 92, 50 , "$CAL4"      , 255 },
    { ITEM_TYPE_SOFTKEY_ACTION,  0,   0, "Save:Calib", 2   },
    { ITEM_TYPE_ACTION     ,  0,   0, "CALIBRATE" , 255 },
    { ITEM_TYPE_VARLABEL   ,  0,   0, "$FIXEDSV"   , 255 }
  }
  ,0
},

//Screen 9 - Set time/date
{
  5,
  {
    { ITEM_TYPE_HEAD,             0, 0, "$CPMDEADINT"    , 255 },
    { ITEM_TYPE_MENU,            10, 1, "Set Time (UTC)", 15  },
    { ITEM_TYPE_MENU,            11, 2, "Set Date (UTC)", 16  },
    { ITEM_TYPE_MENU,            20, 3, "Set UTC Offset", 33  },
    { ITEM_TYPE_SOFTKEY	    ,  0,  3, "Back"   , 255}
  }
  ,0
},

//Screen 10 - Set time
{
  11,
  {
    { ITEM_TYPE_HEAD       , 0 , 0 , "$CPMDEADINT" , 255 },
    { ITEM_TYPE_VARNUM     , 10, 50, "$TIMEHOUR1"  , 255 },
    { ITEM_TYPE_VARNUM     , 32, 50, "$TIMEHOUR2"  , 255 },
    { ITEM_TYPE_VARNUM     , 54, 50, "$TIMEMIN1"   , 255 },
    { ITEM_TYPE_VARNUM     , 76, 50, "$TIMEMIN2"   , 255 },
    { ITEM_TYPE_VARNUM     , 98, 50, "$TIMESEC1"   , 255 },
    { ITEM_TYPE_VARNUM     ,118, 50, "$TIMESEC2"   , 255 },
    { ITEM_TYPE_SOFTKEY	    ,  0,  9, "Back"   , 255},
    { ITEM_TYPE_SOFTKEY_ACTION	, 2, 0, "Save:Time" , 2},
    { ITEM_TYPE_LABEL      ,  0, 20, "HH:MM:SS"   , 50  },
    { ITEM_TYPE_ACTION     ,  0,  0, "TIMESCREEN" , 255 }
  }
  ,0
},

//Screen 11 - Set date
{
  11,
  {
    { ITEM_TYPE_HEAD       , 0 , 0  , "$CPMDEADINT", 255 },
    { ITEM_TYPE_VARNUM     , 10, 50 , "$DATEMON1"  , 255 },
    { ITEM_TYPE_VARNUM     , 32, 50 , "$DATEMON2"  , 255 },
    { ITEM_TYPE_VARNUM     , 54, 50 , "$DATEDAY1"  , 255 },
    { ITEM_TYPE_VARNUM     , 76, 50 , "$DATEDAY2"  , 255 },
    { ITEM_TYPE_VARNUM     , 98, 50 , "$DATEYEAR1" , 255 },
    { ITEM_TYPE_VARNUM     ,118, 50 , "$DATEYEAR2" , 255 },
    { ITEM_TYPE_SOFTKEY	    ,  0,  9, "Back"   , 255},
    { ITEM_TYPE_SOFTKEY_ACTION	, 2, 0, "Save:Date" , 2},
    { ITEM_TYPE_LABEL      , 0 ,  20, "MM/DD/YY"  , 24  },
    { ITEM_TYPE_ACTION     ,  0,   0, "DATESCREEN", 255 }
  }
  ,0
},

//Screen 12 - Brightness control
{
  6,
  {
    { ITEM_TYPE_HEAD       , 0 , 0  , "$CPMDEADINT"    , 255 },
    { ITEM_TYPE_VARNUM     , 64, 64 , "$BRIGHTNESS"    , 255 },
    { ITEM_TYPE_SOFTKEY	    ,  0,  16, "Back"   , 255},
    { ITEM_TYPE_SOFTKEY_ACTION,  2,   0, "Save:Brightness", 2  },
    { ITEM_TYPE_ACTION     ,  0,   0, "BrightnessSCN" , 255 },
    { ITEM_TYPE_LEAVE_ACTION, 0,   0, "LeftBrightness", 255 }
  }
  ,0
},

//Screen 13 - Warning configuration
{
  10,
  {
    { ITEM_TYPE_HEAD       , 0 , 0  , "$CPMDEADINT"  , 255 },
    { ITEM_TYPE_VARNUM     , 10, 50 , "$WARNCPM1"    , 255 },
    { ITEM_TYPE_VARNUM     , 32, 50 , "$WARNCPM2"    , 255 },
    { ITEM_TYPE_VARNUM     , 54, 50 , "$WARNCPM3"    , 255 },
    { ITEM_TYPE_VARNUM     , 76, 50 , "$WARNCPM4"    , 255 },
    { ITEM_TYPE_VARNUM     , 98, 50 , "$WARNCPM5"    , 255 },
    { ITEM_TYPE_SOFTKEY	    ,  0,  17, "Back"   , 255},
    { ITEM_TYPE_SOFTKEY_ACTION	, 2, 0, "Save:WarnCPM" , 2},
    { ITEM_TYPE_LABEL      , 0 ,  20, "Warning CPM" , 47  },
    { ITEM_TYPE_ACTION     ,  0,   0, "WARNSCREEN"  , 255 }
  }
  ,7
},

//Screen 14 - Language Selection Screen
{
  4,
  {
    { ITEM_TYPE_HEAD       , 0, 0, "$CPMDEADINT", 255},
    { ITEM_TYPE_MENU_ACTION, 1, 1, "English"   , 255},
    { ITEM_TYPE_MENU_ACTION, 2, 2, "Japanese"  , 3  },
    { ITEM_TYPE_SOFTKEY	    ,  0,  16, "Back"   , 255}
  }
  ,7
},

//Screen 15 - Total/Timer mode
{
  13,
  {
	{ ITEM_TYPE_HEAD        ,  0,  0, "$CPMDEADINT", 255},
    { ITEM_TYPE_LABEL       ,  0, 32, "Count:", 255 },
    { ITEM_TYPE_LABEL       ,  0, 48, "Avg:", 255 },
    { ITEM_TYPE_LABEL       ,  0, 64, "Time:", 255 },
    { ITEM_TYPE_LABEL       ,  0, 90, "Duration:", 255 },
    { ITEM_TYPE_VARLABEL    , 56, 32, "$TTCOUNT"    , 255},
    { ITEM_TYPE_VARLABEL    , 40, 48, "$TTAVG"    , 255},
    { ITEM_TYPE_VARLABEL    , 48, 64, "$TTTIME"     , 255},
    { ITEM_TYPE_VARLABEL    , 80, 90, "$COUNTWIN",      255},
    { ITEM_TYPE_ACTION      ,  2, 2, "TOTALTIMER" , 255},
    { ITEM_TYPE_SOFTKEY	  	, 0 ,  0, "Back"	   , 255},
    { ITEM_TYPE_SOFTKEY	  	, 1 , 26, "Setup"	   , 255},
    { ITEM_TYPE_SOFTKEY	  	, 2 , 15, "Reset"	   , 255}
  }
  ,2
},

//Screen 16 - User interface settings
{
  6,
  {
    { ITEM_TYPE_HEAD       , 0, 0, "$CPMDEADINT"   , 255},
    { ITEM_TYPE_MENU       ,12, 1, "Brightness"   , 10 },
    { ITEM_TYPE_MENU_ACTION, 0, 2, "Beep"  , 11 },
    { ITEM_TYPE_MENU       ,14, 3, "Language"     , 12 },
    { ITEM_TYPE_MENU_ACTION, 0, 4, "Never Dim"    , 0  },
    { ITEM_TYPE_SOFTKEY	    ,  0,  3, "Back"   , 255}
  }
  ,0
},

//Screen 17 - Geiger settings
{
  7,
  {
    { ITEM_TYPE_HEAD       , 0, 0, "$CPMDEADINT"      , 255},
    { ITEM_TYPE_MENU       ,19, 1, "\x80Sv/\x80R"    , 255},
    { ITEM_TYPE_MENU       , 5, 2, "Calibration"     , 26 },
    { ITEM_TYPE_MENU       ,13, 3, "Warning Levels"  , 28 },
    { ITEM_TYPE_MENU       ,22, 4, "Bq. Eff. Value"  , 35 },
    { ITEM_TYPE_MENU_ACTION, 0, 5, "CPM/CPS Auto"    , 36 },
    { ITEM_TYPE_SOFTKEY	    ,  0,  3, "Back"   , 255}
  }
  ,0
},

//Screen 18 - Version information
{
  4,
  {
    { ITEM_TYPE_HEAD       , 0 , 0, "$CPMDEADINT"        , 255},
    { ITEM_TYPE_LABEL      , 0  ,32, "Firmware Release" , 37 },
    { ITEM_TYPE_LABEL      , 255,64, OS100VERSION       , 255},
    { ITEM_TYPE_SOFTKEY	    ,  0,  3, "Back"   , 255}
  }
  ,7
},

//Screen 19 - Sieverts or Rems
{
  4,
  {
    { ITEM_TYPE_HEAD       , 0, 0, "$CPMDEADINT", 255},
    { ITEM_TYPE_MENU_ACTION, 1, 1, " \x80Sv"    , 38 },
    { ITEM_TYPE_MENU_ACTION, 2, 2, " \x80R"     , 39 },
    { ITEM_TYPE_SOFTKEY	    ,  0,  17, "Back"   , 255}
  }
  ,7
},

//Screen 20 - Set UTC offset
{
  10,
  {
    { ITEM_TYPE_HEAD       , 0 , 0 , "$CPMDEADINT" , 255 },
    { ITEM_TYPE_VARNUM     , 10, 50, "SIGN:-,+,"  , 255 },
    { ITEM_TYPE_VARNUM     , 32, 50, "$OFFHOUR1"   , 255 },
    { ITEM_TYPE_VARNUM     , 54, 50, "$OFFHOUR2"   , 255 },
    { ITEM_TYPE_VARNUM     , 76, 50, "$OFFMIN1"    , 255 },
    { ITEM_TYPE_VARNUM     , 98, 50, "$OFFMIN2"    , 255 },
    { ITEM_TYPE_SOFTKEY	    ,  0,  9, "Back"   , 255},
    { ITEM_TYPE_SOFTKEY_ACTION	, 2, 0, "Save:UTCOff" , 2},
    { ITEM_TYPE_LABEL      , 0 , 20, "HH:MM"      , 40  },
    { ITEM_TYPE_ACTION     ,  0,  0, "UTCSCREEN"  , 255 }

  }
  ,7
},

//Screen 21 - Becquerel
{
  4,
  {
    { ITEM_TYPE_HEAD        , 0  ,  0, "$CPMDEADINT", 255},
    { ITEM_TYPE_VARLABEL    , 0  , 30, "$BECQINFO"  , 255},
    { ITEM_TYPE_BIGVARLABEL , 0  , 43, "$BECQ"      , 255},
    { ITEM_TYPE_LABEL        ,81 , 74, "Bq/m2"     , 255}
  }
  ,1
},

//Screen 22 - Set Becquerel conversion value
{
  8,
  {
    { ITEM_TYPE_HEAD       , 0 ,  0 , "$CPMDEADINT", 255 },
    { ITEM_TYPE_VARNUM     , 38, 50 , "$BECQ1"     , 255 },
    { ITEM_TYPE_VARNUM     , 56, 50 , "$BECQ2"     , 255 },
    { ITEM_TYPE_VARNUM     , 74, 50 , "$BECQ3"     , 255 },
    { ITEM_TYPE_VARNUM     , 92, 50 , "$BECQ4"     , 255 },
    { ITEM_TYPE_SOFTKEY	    ,  0,  17, "Back"   , 255},
    { ITEM_TYPE_SOFTKEY_ACTION	, 2, 0, "Save:Becq" , 2},
    { ITEM_TYPE_ACTION     ,  0,   0, "BECQSCREEN", 255 },
  }
  ,7
},

//Screen 23 - Set Logging Interval
{
  8,
  {
    { ITEM_TYPE_HEAD           ,  0,  0, "$CPMDEADINT"    , 255 },
    { ITEM_TYPE_VARNUM         , 38, 50, "$LOGINTER1"     , 255 },
    { ITEM_TYPE_VARNUM         , 56, 50, "$LOGINTER2"     , 255 },
    { ITEM_TYPE_VARNUM         , 74, 50, "$LOGINTER3"     , 255 },
    { ITEM_TYPE_SOFTKEY	  	   ,  0, 25, "Back"	   , 255},
    { ITEM_TYPE_SOFTKEY_ACTION ,  2,  0, "Save:LogInter" , 2},
    { ITEM_TYPE_LABEL          , 90, 61, "mins"          , 41  },
    { ITEM_TYPE_ACTION         ,  0,  0, "LOGINTERVAL" , 255 },
  }
  ,7
},

//Screen 24 - Geiger Pulse width
{
  3,
  {
    { ITEM_TYPE_HEAD       , 0 ,  0 , "$CPMDEADINT"      , 255 },
    { ITEM_TYPE_VARNUM     , 38, 50 , "$PULSEWIDTH1"     , 255 },
    { ITEM_TYPE_MENU_ACTION,  0,   7, "Save:PulseWidth" ,2    },
  }
  ,7
},


//Screen 25 - Log status
{
  9,
  {
    { ITEM_TYPE_HEAD       ,  0 ,  0 , "$CPMDEADINT"    , 255 },
    { ITEM_TYPE_LABEL      ,  0 , 20 , "Log storage"   , 255 },
    { ITEM_TYPE_VARLABEL   ,255 , 36, "$LOGPERCENT"     , 255 },
    { ITEM_TYPE_VARLABEL   ,  0 , 52, "$LOGREMAIN"      , 255 },
    { ITEM_TYPE_VARLABEL   ,255 , 68, "$LOGREMAIN2"     , 255 },
    { ITEM_TYPE_VARLABEL   ,  0 , 90, "$LOGREMAIN3"     , 255 },
    { ITEM_TYPE_SOFTKEY	  	, 0 ,  0, "Back"	   , 255},
    { ITEM_TYPE_SOFTKEY	  	, 1 ,  23, "Setup"	   , 255},
    { ITEM_TYPE_SOFTKEY_ACTION	  	, 2 ,  0, "Clear Log"	   , 255},
  }
  ,7
},

//Screen 26 - Counting window config
{
  11,
  {
    { ITEM_TYPE_HEAD       , 0 , 0  , "$CPMDEADINT"  , 255 },
    { ITEM_TYPE_VARNUM     , 10, 50 , "$COUNTWIN1"    , 255 },
    { ITEM_TYPE_VARNUM     , 32, 50 , "$COUNTWIN2"    , 255 },
    { ITEM_TYPE_VARNUM     , 54, 50 , "$COUNTWIN3"    , 255 },
    { ITEM_TYPE_VARNUM     , 76, 50 , "$COUNTWIN4"    , 255 },
    { ITEM_TYPE_VARNUM     , 98, 50 , "$COUNTWIN5"    , 255 },
    { ITEM_TYPE_SOFTKEY	  	, 0 ,  15, "Back"	   , 255},
    { ITEM_TYPE_SOFTKEY_ACTION	, 2, 0, "Save:CountWin" , 2},
    { ITEM_TYPE_LABEL      , 0 ,  20, "Max count window" , 47  },
    { ITEM_TYPE_LABEL      , 255 ,  85, "seconds" , 47  },
    { ITEM_TYPE_ACTION     ,  0,   0, "COUNTWINSCR"  , 255 }
  }
  ,7
}


};
