#define ICONSIZE 20
#define ICONSPACING 5
#define MODKEY Mod4Mask
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static const int topbar			  = 1;
static const int showbar            	  = 1;
static const int nmaster	    	  = 1;
static const int user_bh            	  = 24;
static const int showsystray        	  = 1;
static const int resizehints	    	  = 0;
static const int lockfullscreen	    	  = 1;
static const int systraypinningfailfirst  = 1;

static const unsigned int snap		  = 0;
static const unsigned int gappx		  = 7;
static const unsigned int borderpx	  = 3;
static const unsigned int systrayonleft	  = 0;
static const unsigned int systraypinning  = 0;
static const unsigned int systrayspacing  = 5;

static const float mfact		  = 0.55;

static const char col_cyan[]		  = "#d3d0c8";
static const char col_gray1[]       	  = "#15171c";
static const char col_gray2[]       	  = "#15171c";
static const char col_gray3[]       	  = "#d3d0c8";
static const char col_gray4[]       	  = "#15171c";
static const char *colors[][3] = {
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

static const XPoint stickyiconbb = {4,8};
static const XPoint stickyicon[] = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} };

static const char *fonts[] = {
	"Product Sans Medium:size=11:antialias=true:autohint=true",
	"Font Awesome 5 Brands:size=12:antialias=true:autohint=true",
	"Font Awesome 5 Free Solid:size=12:antialias=true:autohint=true",
	"FantasqueSansMono Nerd Font:size=12:antialias=true:autohint=true",
	"JoyPixels:size=12:antialias=true:autohint=true",
};

static const char *const autostart[] = {
	"lead", NULL,
	"dwmblocks", NULL,
	NULL
};

static const char *tags[] = { "", "", "", "", "", "","", "", "" };

static const Rule rules[] = {
	{ "qutebrowser",	  NULL,	  NULL,	  1 << 1,   0,  -1 },
	{ "Zathura",		  NULL,	  NULL,   1 << 2,   0,  -1 },
	{ "Master PDF Editor 5",  NULL,	  NULL,   1 << 2,   0,  -1 },
	{ "mpv",		  NULL,	  NULL,   1 << 3,   0,  -1 },
	{ "discord",		  NULL,	  NULL,   1 << 4,   0,  -1 },
	{ "TelegramDesktop",	  NULL,	  NULL,   1 << 5,   0,  -1 },
	{ "Minecraft* 1.18.2",	  NULL,	  NULL,   1 << 6,   0,  -1 },
	{ "Gimp",		  NULL,	  NULL,   1 << 7,   0,  -1 },
};

static const Layout layouts[] = {
	{ "[]=",      tile },
	{ "[M]",      monocle },
	{ NULL,       NULL },
};

static const char sxiv[] = "xsetroot -name fsignal:3; \
			    sxiv -A 60 -s F $(find /home/triplek/MEGA/WallHaven -type f -printf \"%T+\t%p\n\" \
			    | sort -r \
			    | awk '{print $2}') -t; \
			    xsetroot -name fsignal:3";

static const char vixs[] = "xsetroot -name fsignal:3; \
			    sxiv -A 60 -s F $(find /home/triplek/MEGA/wallhaven -type f -printf \"%T+\t%p\n\" \
			    | sort -r \
			    | awk '{print $2}') -t; \
			    xsetroot -name fsignal:3";

static Key keys[] = {
	{ 0,				XF86XK_AudioPrev,	    spawn,		SHCMD("playerctl prev") },
	{ 0,				XF86XK_AudioNext,           spawn,		SHCMD("playerctl next") },
	{ 0,				XF86XK_AudioPlay,           spawn,		SHCMD("playerctl play-pause") },
	{ 0,				XF86XK_MonBrightnessUp,     spawn,		SHCMD("xbacklight -inc 5") },
	{ 0,				XF86XK_MonBrightnessDown,   spawn,		SHCMD("xbacklight -dec 5") },
	{ 0,                       	XF86XK_AudioMute,	    spawn,	    	SHCMD("amixer set Master toggle; \
											  kill -36 $(pidof dwmblocks)") },
	{ 0,                       	XF86XK_AudioLowerVolume,    spawn,		SHCMD("amixer set Master 5%-; \
											  kill -36 $(pidof dwmblocks)") },
	{ 0,                       	XF86XK_AudioRaiseVolume,    spawn,		SHCMD("amixer set Master 5%+; \
											  kill -36 $(pidof dwmblocks)") },
	{ 0,			      	XK_Print,		    spawn,		SHCMD("maim -s | xclip -selection clipboard -t image/png") }, 

	{ MODKEY,                     	XK_Tab,			    view,		{0} },
	{ MODKEY,                     	XK_b,			    togglebar,		{0} },
	{ MODKEY,		      	XK_w,			    killclient,		{0} },
	{ MODKEY,			XK_c,                       togglecenter,       {0} },
	{ MODKEY,		      	XK_s,			    togglefloating,	{0} },
	{ MODKEY,                       XK_f,			    togglefullscreen,	{0} },
	{ MODKEY,                     	XK_j,			    focusstack,		{.i = +1 } },
	{ MODKEY,                     	XK_k,			    focusstack,		{.i = -1 } },
	{ MODKEY,                     	XK_i,			    incnmaster,		{.i = +1 } },
	{ MODKEY,                     	XK_d,			    incnmaster,		{.i = -1 } },
	{ MODKEY,			XK_Left,                    cyclelayout,        {.i = +1 } },
	{ MODKEY,			XK_Right,                   cyclelayout,        {.i = -1 } },
	{ MODKEY,                     	XK_0,			    view,		{.ui = ~0 } },
	{ MODKEY,                     	XK_h,			    setmfact,		{.f = -0.05} },
	{ MODKEY,                     	XK_l,			    setmfact,		{.f = +0.05} },
	{ MODKEY,			XK_Return,		    spawn,		SHCMD("st") },
	{ MODKEY,			XK_q,			    spawn,		SHCMD("skippy-xd") },
	{ MODKEY,			XK_space,		    spawn,		SHCMD("dmenu_run -h 24 -p \"debian  \"") },

	{ Mod1Mask,			XK_w,			    spawn,		SHCMD(sxiv) },
	{ Mod1Mask,			XK_a,			    spawn,		SHCMD(vixs) },

	{ MODKEY|ShiftMask,           	XK_Return,		    zoom,		{0} },
	{ MODKEY|ShiftMask,             XK_s,			    togglesticky,	{0} },
	{ MODKEY|ShiftMask,             XK_Up,			    togglealwaysontop,	{0} },
	{ MODKEY|ShiftMask,		XK_r,			    quit,		{1} },
	{ MODKEY|ShiftMask,           	XK_0,			    tag,		{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_l,			    spawn,		SHCMD("slock") },
	{ MODKEY|ShiftMask,		XK_q,			    spawn,		SHCMD("say logout") },
	{ MODKEY|ShiftMask,		XK_b,			    spawn,		SHCMD("qutebrowser") },
	{ MODKEY|ShiftMask,		XK_n,			    spawn,		SHCMD("jpg2ff < ~/MEGA/WallHaven/`ls ~/MEGA/WallHaven \
											      | shuf -n 1` > ~/.cache/st_bg.ff; \
											      say refstbg; pidof st | xargs kill -s USR1") },
	{ MODKEY|ShiftMask,		XK_m,			    spawn,		SHCMD("jpg2ff < ~/MEGA/wallhaven/`ls ~/MEGA/wallhaven \
											      | shuf -n 1` > ~/.cache/st_bg.ff; \
											      say refstbg; pidof st | xargs kill -s USR1") },
	{ MODKEY|ControlMask,		XK_Print,		    spawn,		SHCMD("flameshot gui") }, 
	{ MODKEY|ControlMask,	      	XK_Return,		    spawn,		SHCMD("say tmux; st -e tmux attach -t TMUX") },

	TAGKEYS(                      	XK_1,			    0)
	TAGKEYS(                      	XK_2,			    1)
	TAGKEYS(                      	XK_3,			    2)
	TAGKEYS(                      	XK_4,			    3)
	TAGKEYS(                      	XK_5,			    4)
	TAGKEYS(                      	XK_6,			    5)
	TAGKEYS(                      	XK_7,			    6)
	TAGKEYS(                      	XK_8,			    7)
	TAGKEYS(                      	XK_9,			    8)
};

static Button buttons[] = {
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,	{.i = -1 } },
	{ ClkLtSymbol,          0,              Button2,        killclient,	{0} },
	{ ClkLtSymbol,          0,              Button3,        focusstack,	{.i = +1 } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static Signal signals[] = {
  { 1,  quit,             {0} },
  { 2,  quit,		  {1} },
  { 3,  cyclelayout,      {.i = -1 } },
};
