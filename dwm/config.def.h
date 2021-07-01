/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 3;
static const int gappx = 40;
static const unsigned int snap = 2;
static const int swallowfloating = 0;
static const int showbar = 1;
static const int topbar = 1;
static const char buttonbar[] = "  ";
static const int user_bh = 28;
static const int horizpadbar = 0;
static const int vertpadbar = 0;
static const unsigned int systraypinning = 2;
static const unsigned int systrayspacing = 2;
static const int systraypinningfailfirst = 1;
static const int showsystray = 1;

static const char *fonts[] = { "Roboto:style=Bold:size=13" };

static const char col_gray1[] = "#2E3440";
static const char col_gray2[] = "#555E70";
static const char col_gray3[] = "#929AAD";
static const char col_gray4[] = "#AAC0F0";
static const char col_cyan[]  = "#5294E2";

static const char col1[]	  = "#AAC0F0";
static const char col2[]	  = "#C1B54E";
static const char col3[]	  = "#C1514E";
static const char col4[]	  = "#4EC150";
static const char col5[]	  = "#ffffff";
static const char col6[]	  = "#ffffff";
static const char col7[]	  = "#ffffff";
static const char col8[]	  = "#ffffff";
static const char col9[]	  = "#ffffff";
static const char col10[]	  = "#ffffff";
static const char col11[]	  = "#ffffff";
static const char col12[]	  = "#3D4352";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm]  = { col_gray3, col_gray1, col_gray2 },
	[SchemeCol1]  = { col1,      col_gray1, col_gray2 },
	[SchemeCol2]  = { col2,      col_gray1, col_gray2 },
	[SchemeCol3]  = { col3,      col_gray1, col_gray2 },
	[SchemeCol4]  = { col4,      col_gray1, col_gray2 },
	[SchemeCol5]  = { col5,      col_gray1, col_gray2 },
	[SchemeCol6]  = { col6,      col_gray1, col_gray2 },
	[SchemeCol7]  = { col7,      col_gray1, col_gray2 },
	[SchemeCol8]  = { col8,      col_gray1, col_gray2 },
	[SchemeCol9]  = { col_gray4, col12,  col_gray2  },
	[SchemeHid]   = { col_gray2, col_gray1, col_gray1 },
	[SchemeTagNorm] = { col_gray2, col_gray1, col_gray2 },
	[SchemeTagFill] = { col_gray3, col_gray1, col_gray2 },
	[SchemeTagSel] = { col_gray4, col_gray1, col_gray2 },
	[SchemeSel]   = { col_gray4, col_gray1,  col_cyan  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"gnome-calculator", NULL };
const char *spcmd2[] = {"termite", "-e", "bashtop", NULL };
const char *spcmd3[] = {"gcolor2", NULL };
const char *spcmd4[] = {"termite", "-e", "donut", NULL };
static Sp scratchpads[] = {
	/* name          		cmd  */
	{"gnome-calculator",	spcmd1},
	{"bashtop",	        	spcmd2},
	{"gcolor2",		        spcmd3},
	{"donut",		        spcmd4},
};



/* tagging */
static const char *tags[] = { "⭘","⭘","⭘", "⭘", "⭘", "⭘", "⭘", "⭘", "⭘" };
static const char *alttags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* class, instance, title,	tags mask    	isnotcentered	isfloating	isterminal	noswallow	monitor		float x,y,w,h   	floatborderpx*/
	{ "Blueman-manager", NULL, NULL,	0,    	0,      		1,  		0,  		0,  		-1, 		0,0,534,405,    	3 },
	{ "Pavucontrol", NULL, NULL,		0,    	0,      		1,  		0,  		0,  		-1, 		0,0,968,581,    	3 },
	{ "Pamac-manager", NULL, NULL,		0,    	0,      		1,  		0,  		0,  		-1, 		374,147,1172,786,   3 },
	{ "Lxpolkit", NULL, NULL,		    0,    	0,      		1,  		0,  		0,  		-1, 		0,0,276,21, 		3 },
	{ "Termite", NULL, NULL, 	    	0,    	0,      		0,  		1,  		0,  		-1, 		0,0,0,0,    		3 },
	{ NULL, NULL, "Event Tester",		0,    	0,      		0,  		0,  		1,  		-1, 		0,0,0,0,    		3 },
	{ "Gsimplecal", NULL, NULL,	    	0,    	1,      		1,  		0,  		0,  		-1, 		1590,32,250,205,    0 },
	{ "Unity", NULL, NULL,		    	1 << 5,	0,      		0,  		0,  		0,  		 1, 		0,0,1200,800,   	3 },
	{ "Godot", NULL, NULL,		    	1 << 5,	0,      		0,  		0,  		0,  		 0, 		0,0,1200,800,   	3 },
	{ "jetbrains-studio", NULL, NULL,	1 << 5,	0,      		1,  		0,  		0,  		 1, 		0,0,1200,800,   	3 },

	{ "Gnome-calculator", NULL, NULL,	SPTAG(0),0,     		1,  		1,  		0,  		-1, 		0,0,612,500,    	3 },
	{ NULL, NULL, "bashtop",	    	SPTAG(1),0,     		1,  		1,  		0,  		-1, 		0,0,1118,668,	    3 },
	{ NULL, NULL, "gcolor2", 	    	SPTAG(2),0,     		1,  		0,  		0,  		-1, 		50,50,534,305,		3 },
    { NULL, NULL, "donut",  	    	SPTAG(3),1,      		1,  		0,  		0,  		-1, 		1009,562,825,472,   3 },
};

/* layout(s) */
static const float mfact     = 0.65;
static const int nmaster     = 1;
static const int resizehints = 1;

static const Layout layouts[] = {
	{ "[]=",      tile },
	{ "[M]",      monocle },
	{ NULL,       NULL },
};

/* definitions */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


/* commands */
static const char *roficmd[] = { "rofi", "-show", "combi", NULL };
static const char *termcmd[] = { "termite", NULL };
static const char *bravecmd[] = { "brave", NULL };
static const char *pcmanfmcmd[] = { "pcmanfm", NULL };
static const char *braveinccmd[] = { "brave", "--incognito", NULL };
static const char *rangercmd[] = { "termite", "-e", "ranger", NULL };
static const char *vimcmd[] = { "termite", "-e", "vim", NULL };
static const char *spotifycmd[] = { "spotify", NULL };
static const char *unitycmd[] = { "unityhub", NULL };
static const char *godotcmd[] = { "godot", NULL };
static const char *gimpcmd[] = { "gimp", NULL };
static const char *quitcmd[] = { "sudo", "killall", "lightdm", NULL };

/* spotify control commands */
static const char *spotifycmd_previous[] = { "dbus-send", "--print-reply", "--dest=org.mpris.MediaPlayer2.spotify", "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player.Previous", NULL };
static const char *spotifycmd_play[] = { "dbus-send", "--print-reply", "--dest=org.mpris.MediaPlayer2.spotify", "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player.PlayPause", NULL };
static const char *spotifycmd_next[] = { "dbus-send", "--print-reply", "--dest=org.mpris.MediaPlayer2.spotify", "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player.Next", NULL };

/* volume control commands */
static const char *mutecmd[] = { "amixer", "-q", "-D", "pulse", "sset", "Master", "toggle", NULL };
static const char *volumedowncmd[] = { "amixer", "-q", "-D", "pulse", "sset", "Master", "25%-", NULL };
static const char *volumeupcmd[] = { "amixer", "-q", "-D", "pulse", "sset", "Master", "25%+", NULL };

static Key keys[] = {

	/* apps */
	{ MODKEY,				/*d*/ 40,		spawn,	    	{.v = roficmd } },
	{ MODKEY,				/*Return*/ 36,	spawn,	    	{.v = termcmd } },
	{ MODKEY,				/*w*/ 25,		spawn,	    	{.v = bravecmd } },
	{ MODKEY|ShiftMask,		/*w*/ 25,		spawn,	    	{.v = braveinccmd } },
	{ MODKEY,				/*e*/ 26,		spawn,	    	{.v = rangercmd } },
	{ MODKEY|ShiftMask,		/*e*/ 26,		spawn,	    	{.v = pcmanfmcmd } },
	{ MODKEY,				/*v*/ 55,		spawn,	    	{.v = vimcmd } },
	{ MODKEY,				/*s*/ 39,		spawn,	    	{.v = spotifycmd } },
	{ MODKEY,				/*u*/ 30,		spawn,	    	{.v = unitycmd } },
	{ MODKEY,				/*g*/ 42,		spawn,	    	{.v = godotcmd } },
	{ MODKEY|ShiftMask,		/*g*/ 42,		spawn,	    	{.v = gimpcmd } },

	{ MODKEY,				/*c*/ 54,  	   	togglescratch, 	{.ui = 0 } },
	{ MODKEY,				/*y*/ 29,	   	togglescratch, 	{.ui = 1 } },
	{ MODKEY,				/*p*/ 33,	   	togglescratch, 	{.ui = 2 } },
	{ MODKEY|ShiftMask,		/*Return*/ 36,	togglescratch, 	{.ui = 3 } },

	/* dwm  control */
	{ MODKEY,				/*q*/ 24,		killclient,	   	{0} },
	{ MODKEY|ShiftMask,		/*r*/ 27,		quit,		   	{0} },
	{ MODKEY|ShiftMask,		/*q*/ 24,		spawn,		   	{.v = quitcmd } },
	{ MODKEY,               /*b*/ 56,      	togglebar,     	{0} },
	{ MODKEY,				/*space*/ 65,	togglefloating,	{0} },
	{ MODKEY,				/*m*/ 58,		cyclelayout,	{.i = +1 } },

	/* navigation*/
	{ MODKEY,               /*j*/ 44,      	focusstackvis,  {.i = +1 } },
	{ MODKEY,               /*k*/ 45,      	focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,		/*j*/ 44,		movestack,  	{.i = +1 } },
	{ MODKEY|ShiftMask,		/*k*/ 45,		movestack,  	{.i = -1 } },
	{ MODKEY|ControlMask,	/*j*/ 44,		setcfact,   	{.f = +0.25} },
	{ MODKEY|ControlMask,	/*k*/ 45,		setcfact,   	{.f = -0.25} },
	{ MODKEY|Mod1Mask,		/*j*/ 44,		shiftview,  	{.i = -1 } },
	{ MODKEY|Mod1Mask,		/*k*/ 45,		shiftview,  	{.i = +1 } },

	{ MODKEY,				/*h*/ 43,		focusmaster,	{0} },
	{ MODKEY,				/*l*/ 46,		focusstackvis,	{.i = +1}  },
	{ MODKEY|ShiftMask,		/*h*/ 43,		zoom,	    	{0} },
	{ MODKEY|ShiftMask,		/*l*/ 46,		zoom,	    	{0} },
	{ MODKEY|ControlMask,	/*h*/ 43,		setmfact,   	{.f = -0.05} },
	{ MODKEY|ControlMask,	/*l*/ 46,		setmfact,   	{.f = +0.05} },

	{ MODKEY,				/*o*/ 32,		focusmon,   	{.i = +1 } },
	{ MODKEY|ShiftMask,		/*o*/ 32,		tagmon,	    	{.i = +1 } },

	/* spotify control */
	{ MODKEY,				/*F10*/ 76,		spawn,	    	{.v = spotifycmd_previous } },
	{ MODKEY,				/*F11*/ 95,		spawn,	    	{.v = spotifycmd_play } },
	{ MODKEY,				/*F12*/ 96,		spawn,	    	{.v = spotifycmd_next } },

	/* volumec ontrol */
	{ MODKEY,				/*F5*/ 71,		spawn,	    	{.v = mutecmd } },
	{ MODKEY,				/*F7*/ 73,		spawn,	    	{.v = volumedowncmd } },
	{ MODKEY,				/*F8*/ 74,		spawn,	    	{.v = volumeupcmd } },

	TAGKEYS(                /*1*/ 10,           0)
	TAGKEYS(                /*2*/ 11,           1)
	TAGKEYS(                /*3*/ 12,           2)
	TAGKEYS(                /*4*/ 13,           3)
	TAGKEYS(                /*5*/ 14,           4)
	TAGKEYS(                /*6*/ 15,           5)
	TAGKEYS(                /*7*/ 16,           6)
	TAGKEYS(                /*8*/ 17,           7)
	TAGKEYS(                /*9*/ 18,           8)

	TAGKEYS(                /*1*/ 87,           0)
	TAGKEYS(                /*2*/ 88,           1)
	TAGKEYS(                /*3*/ 89,           2)
	TAGKEYS(                /*4*/ 83,           3)
	TAGKEYS(                /*5*/ 84,           4)
	TAGKEYS(                /*6*/ 85,           5)
	TAGKEYS(                /*7*/ 79,           6)
	TAGKEYS(                /*8*/ 80,           7)
	TAGKEYS(                /*9*/ 81,           8)
};

/* button definitions */
static Button buttons[] = {
	/* click                event mask      button          function        argument */

	{ ClkButton,		    0,      		Button1,	    spawn,		    {.v = roficmd } },

	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            0,              Button4,        shiftview,	    {.i = -1 } },
	{ ClkTagBar,            0,              Button5,        shiftview,	    {.i = +1 } },

	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,         	0,		        Button2,        killclient, 	{0} },
	{ ClkWinTitle,          0,              Button4,        shiftview,	    {.i = -1 } },
	{ ClkWinTitle,          0,              Button5,        shiftview,	    {.i = +1 } },

	{ ClkStatusText,        0,              Button1,        sigdwmblocks,  	{.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,  	{.i = 2} },


	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};
