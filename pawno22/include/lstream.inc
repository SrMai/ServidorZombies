/*==========================================================================================

Release Name: tAxI's Label Streamer
File Version: 1.0.0
File Date: May 7, 2013

============================================================================================

* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.

============================================================================================

native CreateStaticLabel(Text[], default_color, line_of_sight, Float:x, Float:y, Float:z, Float:draw_distance);
native CreateVehicleLabel(Text[], vehicleid, default_color, line_of_sight, Float:x_offset, Float:y_offset, Float:z_offset, Float:draw_distance);
native CreatePlayerLabel(Text[], playerid, default_color, line_of_sight, Float:x_offset, Float:y_offset, Float:z_offset, Float:draw_distance);
native DestroyLabel(labelid);
native SetLabelText(labelid, Text[]);
native SetLabelPos(labelid, Float:x, Float:y, Float:z);
native SetLabelOffset(labelid, Float:x_offset, Float:y_offset, Float:z_offset);
native SetLabelDrawDistance(labelid, Float:draw_distance);
native SetLabelLineOfSight(labelid, line_of_sight);

*/

#include <foreach>

#define LSTREAM_MAX_STRING_SIZE 256
#define LSTREAM_DEFAULT_VIEW_DISTANCE 30
#define LSTREAM_MAX_LABELS 8000
#define LSTREAM_MAX_ACTIVE_LABELS 1000
#define LSTREAM_TYPE_STATIC 0
#define LSTREAM_TYPE_VEHICLE 1
#define LSTREAM_TYPE_PLAYER 2
#define INVALID_LABEL_ID -9209

forward LabelStreamStatic();
forward LabelStreamVehicle();
forward LabelStreamPlayer();

new Iterator:LabelStreams<LSTREAM_MAX_LABELS>;

enum linfo
{
	type,
	att_id,
	labeltext[LSTREAM_MAX_STRING_SIZE],
	textcolor,
	Float:xpos,
	Float:ypos,
	Float:zpos,
	Float:xoff,
	Float:yoff,
	Float:zoff,
	Float:drawdist,
	valid,
	lineofsight,
};

new LabelInfo[LSTREAM_MAX_LABELS][linfo],
    LabelActive[MAX_PLAYERS][LSTREAM_MAX_LABELS],
    Labelstreamcount[MAX_PLAYERS],
    PlayerText3D:Labelidnum[MAX_PLAYERS][LSTREAM_MAX_LABELS],
	Called = 0,
	Float:label_pos[3];


public OnFilterScriptInit()
{
	Called = 1;
	SetTimer("LabelStreamStatic",500,1);
	SetTimer("LabelStreamVehicle",500,1);
	SetTimer("LabelStreamPlayer",500,1);
	return CallLocalFunction("LSTREAM_OnFilterScriptInit", "");
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit LSTREAM_OnFilterScriptInit

forward OnFilterScriptInit();

public OnGameModeInit()
{
    if(Called == 0) {
		SetTimer("LabelStreamStatic",500,1);
		SetTimer("LabelStreamVehicle",500,1);
		SetTimer("LabelStreamPlayer",500,1);
	}
	return CallLocalFunction("LSTREAM_OnGameModeInit", "");
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit LSTREAM_OnGameModeInit

forward OnGameModeInit();

public LabelStreamStatic()
{
	foreach(new j : Player) {
		foreach(new K : LabelStreams) {
			if(LabelInfo[K][type] == LSTREAM_TYPE_STATIC) {
				if(LabelActive[j][K] == 0) {
					if(Labelstreamcount[j] < LSTREAM_MAX_ACTIVE_LABELS) {
						if(IsPlayerInRangeOfPoint(j,LabelInfo[K][drawdist],LabelInfo[K][xpos],LabelInfo[K][ypos],LabelInfo[K][zpos])) {
							ActivateLabelForPlayer(j,K);
							Labelstreamcount[j]++;
							LabelActive[j][K] = 1;
						}
					}
				}
				else if(LabelActive[j][K] == 1) {
					if(!IsPlayerInRangeOfPoint(j,LabelInfo[K][drawdist],LabelInfo[K][xpos],LabelInfo[K][ypos],LabelInfo[K][zpos])) {
						DeletePlayer3DTextLabel(j,Labelidnum[j][K]);
						LabelActive[j][K] = 0;
						Labelstreamcount[j]--;
					}
				}
			}
		}
	}
}

public LabelStreamVehicle()
{
	foreach(new j : Player) {
		foreach(new K : LabelStreams) {
			if(LabelInfo[K][type] == LSTREAM_TYPE_VEHICLE) {
				if(LabelActive[j][K] == 0) {
					if(Labelstreamcount[j] < LSTREAM_MAX_ACTIVE_LABELS) {
					    GetVehiclePos(LabelInfo[K][att_id],label_pos[0],label_pos[1],label_pos[2]);
						if(IsPlayerInRangeOfPoint(j,LabelInfo[K][drawdist],label_pos[0],label_pos[1],label_pos[2])) {
							ActivateLabelForPlayer(j,K);
							Labelstreamcount[j]++;
							LabelActive[j][K] = 1;
						}
					}
				}
				else if(LabelActive[j][K] == 1) {
				    GetVehiclePos(LabelInfo[K][att_id],label_pos[0],label_pos[1],label_pos[2]);
					if(!IsPlayerInRangeOfPoint(j,LabelInfo[K][drawdist],label_pos[0],label_pos[1],label_pos[2])) {
						DeletePlayer3DTextLabel(j,Labelidnum[j][K]);
						LabelActive[j][K] = 0;
						Labelstreamcount[j]--;
					}
				}
			}
		}
	}
}

public LabelStreamPlayer()
{
	foreach(new j : Player) {
		foreach(new K : LabelStreams) {
			if(LabelInfo[K][type] == LSTREAM_TYPE_PLAYER) {
				if(LabelActive[j][K] == 0) {
					if(Labelstreamcount[j] < LSTREAM_MAX_ACTIVE_LABELS) {
					    GetPlayerPos(LabelInfo[K][att_id],label_pos[0],label_pos[1],label_pos[2]);
						if(IsPlayerInRangeOfPoint(j,LabelInfo[K][drawdist],label_pos[0],label_pos[1],label_pos[2])) {
							ActivateLabelForPlayer(j,K);
							Labelstreamcount[j]++;
							LabelActive[j][K] = 1;
						}
					}
				}
				else if(LabelActive[j][K] == 1) {
				    GetPlayerPos(LabelInfo[K][att_id],label_pos[0],label_pos[1],label_pos[2]);
					if(!IsPlayerInRangeOfPoint(j,LabelInfo[K][drawdist],label_pos[0],label_pos[1],label_pos[2])) {
						DeletePlayer3DTextLabel(j,Labelidnum[j][K]);
						LabelActive[j][K] = 0;
						Labelstreamcount[j]--;
					}
				}
			}
		}
	}
}

stock ActivateLabelForPlayer(playerid,labelid)
{
	if(LabelInfo[labelid][type] == LSTREAM_TYPE_STATIC) Labelidnum[playerid][labelid] = CreatePlayer3DTextLabel(playerid,LabelInfo[labelid][labeltext],LabelInfo[labelid][textcolor],LabelInfo[labelid][xpos],LabelInfo[labelid][ypos],LabelInfo[labelid][zpos],LabelInfo[labelid][drawdist],INVALID_PLAYER_ID,INVALID_VEHICLE_ID,LabelInfo[labelid][lineofsight]);
	else if(LabelInfo[labelid][type] == LSTREAM_TYPE_VEHICLE) Labelidnum[playerid][labelid] = CreatePlayer3DTextLabel(playerid,LabelInfo[labelid][labeltext],LabelInfo[labelid][textcolor],LabelInfo[labelid][xoff],LabelInfo[labelid][yoff],LabelInfo[labelid][zoff],LabelInfo[labelid][drawdist],INVALID_PLAYER_ID,LabelInfo[labelid][att_id],LabelInfo[labelid][lineofsight]);
	else if(LabelInfo[labelid][type] == LSTREAM_TYPE_PLAYER) Labelidnum[playerid][labelid] = CreatePlayer3DTextLabel(playerid,LabelInfo[labelid][labeltext],LabelInfo[labelid][textcolor],LabelInfo[labelid][xoff],LabelInfo[labelid][yoff],LabelInfo[labelid][zoff],LabelInfo[labelid][drawdist],LabelInfo[labelid][att_id],INVALID_VEHICLE_ID,LabelInfo[labelid][lineofsight]);
}

//=================================== NATIVE FUNCTIONS =============================================

stock CreateStaticLabel(Text[], default_color, line_of_sight, Float:x, Float:y, Float:z, Float:draw_distance)
{
	new i = Iter_Free(LabelStreams);
	LabelInfo[i][type] = LSTREAM_TYPE_STATIC;
	strmid(LabelInfo[i][labeltext], Text, 0, strlen(Text), LSTREAM_MAX_STRING_SIZE);
	LabelInfo[i][textcolor] = default_color;
	LabelInfo[i][lineofsight] = line_of_sight;
	LabelInfo[i][xpos] = x;
	LabelInfo[i][ypos] = y;
	LabelInfo[i][zpos] = z;
	LabelInfo[i][drawdist] = draw_distance;
	LabelInfo[i][valid] = 1;
	Iter_Add(LabelStreams, i);
	return i;
}

stock CreateVehicleLabel(Text[], vehicleid, default_color, line_of_sight, Float:x_offset, Float:y_offset, Float:z_offset, Float:draw_distance)
{
	new i = Iter_Free(LabelStreams);
	LabelInfo[i][type] = LSTREAM_TYPE_VEHICLE;
	LabelInfo[i][att_id] = vehicleid;
	strmid(LabelInfo[i][labeltext], Text, 0, strlen(Text), LSTREAM_MAX_STRING_SIZE);
	LabelInfo[i][textcolor] = default_color;
	LabelInfo[i][lineofsight] = line_of_sight;
	LabelInfo[i][xoff] = x_offset;
	LabelInfo[i][yoff] = y_offset;
	LabelInfo[i][zoff] = z_offset;
	LabelInfo[i][drawdist] = draw_distance;
	LabelInfo[i][valid] = 1;
	Iter_Add(LabelStreams, i);
	return i;
}

stock CreatePlayerLabel(Text[], playerid, default_color, line_of_sight, Float:x_offset, Float:y_offset, Float:z_offset, Float:draw_distance)
{
	new i = Iter_Free(LabelStreams);
	LabelInfo[i][type] = LSTREAM_TYPE_PLAYER;
	LabelInfo[i][att_id] = playerid;
	strmid(LabelInfo[i][labeltext], Text, 0, strlen(Text), LSTREAM_MAX_STRING_SIZE);
	LabelInfo[i][textcolor] = default_color;
	LabelInfo[i][lineofsight] = line_of_sight;
	LabelInfo[i][xoff] = x_offset;
	LabelInfo[i][yoff] = y_offset;
	LabelInfo[i][zoff] = z_offset;
	LabelInfo[i][drawdist] = draw_distance;
	LabelInfo[i][valid] = 1;
	Iter_Add(LabelStreams, i);
	return i;
}

stock DestroyLabel(labelid)
{
	if(LabelInfo[labelid][valid] == 0) return 0;
	LabelInfo[labelid][valid] = 0;
	Iter_Remove(LabelStreams, labelid);
	foreach(new playerid : Player) {
		if(LabelActive[playerid][labelid] == 1) {
			DeletePlayer3DTextLabel(playerid,Labelidnum[playerid][labelid]);
			LabelActive[playerid][labelid] = 0;
			Labelstreamcount[playerid]--;
		}
	}
	return 1;
}

stock SetLabelText(labelid, Text[])
{
	if(LabelInfo[labelid][valid] == 0) return 0;
	strmid(LabelInfo[labelid][labeltext], Text, 0, strlen(Text), LSTREAM_MAX_STRING_SIZE);
	foreach(new playerid : Player) {
		if(LabelActive[playerid][labelid] == 1) {
			DeletePlayer3DTextLabel(playerid,Labelidnum[playerid][labelid]);
			LabelActive[playerid][labelid] = 0;
			Labelstreamcount[playerid]--;
		}
	}
	return 1;
}

stock SetLabelPos(labelid, Float:x, Float:y, Float:z)
{
	if(LabelInfo[labelid][valid] == 0) return 0;
	if(LabelInfo[labelid][type] == LSTREAM_TYPE_STATIC) {
    	LabelInfo[labelid][xpos] = x;
		LabelInfo[labelid][ypos] = y;
		LabelInfo[labelid][zpos] = z;
    	foreach(new playerid : Player) {
			if(LabelActive[playerid][labelid] == 1) {
				DeletePlayer3DTextLabel(playerid,Labelidnum[playerid][labelid]);
				LabelActive[playerid][labelid] = 0;
				Labelstreamcount[playerid]--;
			}
		}
		return 1;
	}
	return 0;
}

stock SetLabelOffset(labelid, Float:x_offset, Float:y_offset, Float:z_offset)
{
	if(LabelInfo[labelid][valid] == 0) return 0;
    if(LabelInfo[labelid][type] != LSTREAM_TYPE_STATIC) {
    	LabelInfo[labelid][xpos] = x_offset;
		LabelInfo[labelid][ypos] = y_offset;
		LabelInfo[labelid][zpos] = z_offset;
    	foreach(new playerid : Player) {
			if(LabelActive[playerid][labelid] == 1) {
				DeletePlayer3DTextLabel(playerid,Labelidnum[playerid][labelid]);
				LabelActive[playerid][labelid] = 0;
				Labelstreamcount[playerid]--;
			}
		}
		return 1;
	}
	return 0;
}

stock SetLabelDrawDistance(labelid, Float:draw_distance)
{
	if(LabelInfo[labelid][valid] == 0) return 0;
   	LabelInfo[labelid][drawdist] = draw_distance;
	foreach(new playerid : Player) {
		if(LabelActive[playerid][labelid] == 1) {
			DeletePlayer3DTextLabel(playerid,Labelidnum[playerid][labelid]);
			LabelActive[playerid][labelid] = 0;
			Labelstreamcount[playerid]--;
		}
	}
	return 1;
}

stock SetLabelLineOfSight(labelid, line_of_sight)
{
	if(LabelInfo[labelid][valid] == 0) return 0;
	LabelInfo[labelid][lineofsight] = line_of_sight;
	foreach(new playerid : Player) {
		if(LabelActive[playerid][labelid] == 1) {
			DeletePlayer3DTextLabel(playerid,Labelidnum[playerid][labelid]);
			LabelActive[playerid][labelid] = 0;
			Labelstreamcount[playerid]--;
		}
	}
	return 1;
}
