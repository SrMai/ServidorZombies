/* CREDITS:
** Blabla93 A.K.A [TGG]Bill | Coding the include
** [HiC]TheKiller, Kwarde & RealCop228 for the suggestion of adding a race checkpoints
** Mauzen for having the idea to add OnPlayerMission(playerid) call back!
*/

/* CHANGE LOG
*** VERSION 2.0
** You can now cancel a players mission but using CancelPlayersCurrentMission(playerid);
** You can now add custom stuff to when the player finishs the mission using public OnPlayerFinishMission(playerid)
** If you un comment "#define USE_RACE_CHECKPOINT" the Include will use race checkpoints instead of regulare checkpoints!
** You can adjust the amount a player looses when they loose there trailer for 30 seconds if TrailerCheck is enabled using "#define COST_OF_LOST_GOODS"
** You can change the size of the checkpoints using "#define CHECKPOINT_SIZE"
*/

#include <a_samp>
#define COST_OF_LOST_GOODS 0
#define CHECKPOINT_SIZE 7
//#define USE_RACE_CHECKPOINT   // Un comment this line to enable Race Checkoints!

/* Only change this if USE_RACE_CHECKPOINT is enabled! */
#define RACE_CHECKPOINT_TYPE 0
/* KEY
** 0-Normal
** 1-Finish
** 2-Nothing(Only the checkpoint without anything on it)
** 3-Air normal
** 4-Air finish
*/
forward OnPlayerFinishMission(playerid);
enum missioninfo
{

//    MissionText[200],  For Future Versions
	Pay,
	Checkpoint,
	CheckpointID,
	Float:Lastx,
	Float:Lasty,
	Float:Lastz,
 	TrailerID,
 	bool:AllowTrailerCheck,
 	TrailerCheckCount
}
new minfo[MAX_PLAYERS][missioninfo];

new LTimer[MAX_PLAYERS];
new ULTimer[MAX_PLAYERS];
new TrailerCheckTimer[MAX_PLAYERS];
new s[250];

stock CreatePlayerMission(playerid, bool:TrailerCheck, MissionPay, Float:Startx, Float:Starty, Float:Startz, Float:Endx, Float:Endy, Float:Endz)
{
    if (TrailerCheck == true)
	{
		new pvehiclemodel = GetVehicleModel(GetPlayerVehicleID(playerid));
		if (pvehiclemodel == 403 || pvehiclemodel == 514 || pvehiclemodel == 515)
		{
		    minfo[playerid][AllowTrailerCheck] = true;
		}
		else return 1;
	}

/*	format(s, sizeof(s), "Dispatch: %s", Mission);
	SendClientMessage(playerid, 0x00FF00FF, s);*/
	minfo[playerid][Pay] = MissionPay;
	minfo[playerid][Lastx] = Endx;
	minfo[playerid][Lasty] = Endy;
	minfo[playerid][Lastz] = Endz;
	minfo[playerid][CheckpointID] = 1;
//	minfo[playerid][MissionText] = Mission;
	#if defined USE_RACE_CHECKPOINT
        minfo[playerid][Checkpoint] = SetPlayerRaceCheckpoint(playerid, RACE_CHECKPOINT_TYPE, Startx, Starty, Startz, Endx, Endy, Endz, CHECKPOINT_SIZE);
	#else
        minfo[playerid][Checkpoint] = SetPlayerCheckpoint(playerid, Startx, Starty, Startz, CHECKPOINT_SIZE);
	#endif
  	return 1;
}

stock CancelPlayersCurrentMission(playerid)
{
	if (minfo[playerid][AllowTrailerCheck] == true)
	{
        KillTimer(TrailerCheckTimer[playerid]);
	    minfo[playerid][TrailerCheckCount] = 0;
	    minfo[playerid][AllowTrailerCheck] = false;
	}
    format(s, sizeof(s), "Dejaste de trabajar y pagaste $%d a la empresa", COST_OF_LOST_GOODS);
    SendClientMessage(playerid, 0xFF0000AA, s);
    GivePlayerMoney(playerid, -COST_OF_LOST_GOODS);
    #if defined USE_RACE_CHECKPOINT
    	DisablePlayerRaceCheckpoint(playerid);
	#else
	    DisablePlayerCheckpoint(playerid);
	#endif
	return 1;
}

forward M_OnPlayerConnect(playerid);
public M_OnPlayerConnect(playerid)
{
	minfo[playerid][Pay] = 0;
	minfo[playerid][Lastx] = 0;
	minfo[playerid][Lasty] = 0;
	minfo[playerid][Lastz] = 0;
	minfo[playerid][Checkpoint] = 0;
	minfo[playerid][CheckpointID] = 0;
	minfo[playerid][AllowTrailerCheck] = false;
	minfo[playerid][TrailerCheckCount] = 0;
//	minfo[playerid][MissionText] = "";
}


forward M_OnPlayerDisconnect(playerid);
public M_OnPlayerDisconnect(playerid)
{
	if (minfo[playerid][CheckpointID] == 1)
	{
	    KillTimer(LTimer[playerid]);
	}
	if (minfo[playerid][CheckpointID] == 2)
	{
	    KillTimer(ULTimer[playerid]);
	    if (minfo[playerid][AllowTrailerCheck] == true)
		{
		    KillTimer(TrailerCheckTimer[playerid]);
		}
	}
	return 1;
}


forward M_OnPlayerEnterCheckpoint(playerid);
public M_OnPlayerEnterCheckpoint(playerid)
{
	if (minfo[playerid][CheckpointID] == 1)
	{
		if (minfo[playerid][AllowTrailerCheck] == true)
		{
			if (IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)))
			{
				minfo[playerid][TrailerID] = GetVehicleTrailer(GetPlayerVehicleID(playerid));
				TrailerCheckTimer[playerid] = SetTimerEx("TrailerCheck", 1000, true, "d" , playerid);
			}
			else return SendClientMessage(playerid, 0xFF0000AA, "Necesita tener un container para cargar!");

		}
        GameTextForPlayer(playerid, "~r~Cargando el camion... ~w~Por favor, espera", 5000, 5);
        TogglePlayerControllable(playerid, 0);
        LTimer[playerid] = SetTimerEx("Loading", 5000, false, "d" , playerid);
	}
	else if (minfo[playerid][CheckpointID] == 2)
	{
	    if (minfo[playerid][AllowTrailerCheck] == true)
		{
		    if (IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)))
			{
			    if (minfo[playerid][TrailerID] == GetVehicleTrailer(GetPlayerVehicleID(playerid)))
			    {
			        KillTimer(TrailerCheckTimer[playerid]);
			        minfo[playerid][AllowTrailerCheck] = false;
				}
				else
				{
				    SendClientMessage(playerid, 0xFF0000AA, "Usted necesita el trailer que llevaba para descargar!");
				}
	        }
			else return SendClientMessage(playerid, 0xFF0000AA, "Necesitas un trailer para descargar!");
		}
	    GameTextForPlayer(playerid, "~r~Descargando... ~w~Por favor, espera", 5000, 5);
        TogglePlayerControllable(playerid, 0);
        ULTimer[playerid] = SetTimerEx("UnLoading", 5000, false, "d" , playerid);
	}
	return 1;
}

forward M_OnPlayerEnterRaceCheckpoint(playerid);
public M_OnPlayerEnterRaceCheckpoint(playerid)
{
    if (minfo[playerid][CheckpointID] == 1)
	{
		if (minfo[playerid][AllowTrailerCheck] == true)
		{
			if (IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)))
			{
				minfo[playerid][TrailerID] = GetVehicleTrailer(GetPlayerVehicleID(playerid));
				TrailerCheckTimer[playerid] = SetTimerEx("TrailerCheck", 1000, true, "d" , playerid);
			}
			else return SendClientMessage(playerid, 0xFF0000AA, "Necesitas un trailer para cargar!");
		}
	    GameTextForPlayer(playerid, "~r~Cargando... ~w~Por favor, espera", 5000, 5);
	    TogglePlayerControllable(playerid, 0);
	    LTimer[playerid] = SetTimerEx("Loading", 5000, false, "d" , playerid);
	}
	else if (minfo[playerid][CheckpointID] == 2)
	{
	    if (minfo[playerid][AllowTrailerCheck] == true)
		{
		    if (IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)))
			{
			    if (minfo[playerid][TrailerID] == GetVehicleTrailer(GetPlayerVehicleID(playerid)))
			    {
			        KillTimer(TrailerCheckTimer[playerid]);
			        minfo[playerid][AllowTrailerCheck] = false;
				}
				else
				{
				    SendClientMessage(playerid, 0xFF0000AA, "Usted necesita el trailer que tenia cargado para descargar!");
				}
	        }
			else return SendClientMessage(playerid, 0xFF0000AA, "Necesita un trailer para descargar!");
		}
	    GameTextForPlayer(playerid, "~r~Descargando... ~w~Por Favor, Espere", 5000, 5);
        TogglePlayerControllable(playerid, 0);
        ULTimer[playerid] = SetTimerEx("UnLoading", 5000, false, "d" , playerid);
	}
    return 1;
}

forward Loading(playerid);
public Loading(playerid)
{
    minfo[playerid][CheckpointID] = 2;
	TogglePlayerControllable(playerid, 1);
	#if defined USE_RACE_CHECKPOINT
	    DisablePlayerRaceCheckpoint(playerid);
        minfo[playerid][Checkpoint] = SetPlayerRaceCheckpoint(playerid, RACE_CHECKPOINT_TYPE, minfo[playerid][Lastx], minfo[playerid][Lasty], minfo[playerid][Lastz], minfo[playerid][Lastx], minfo[playerid][Lasty], minfo[playerid][Lastz], CHECKPOINT_SIZE);
	#else
	    DisablePlayerCheckpoint(playerid);
        minfo[playerid][Checkpoint] = SetPlayerCheckpoint(playerid, minfo[playerid][Lastx], minfo[playerid][Lasty], minfo[playerid][Lastz], CHECKPOINT_SIZE);
	#endif
    return 1;
}

forward UnLoading(playerid);
public UnLoading(playerid)
{
    minfo[playerid][CheckpointID] = 0;
	TogglePlayerControllable(playerid, 1);
	format(s, sizeof(s), "Has ganado: $%d", minfo[playerid][Pay]);
	SendClientMessage(playerid, 0x33CCFFAA, s);
	GivePlayerMoney(playerid, minfo[playerid][Pay]);
    OnPlayerFinishMission(playerid);
	#if defined USE_RACE_CHECKPOINT
	    DisablePlayerRaceCheckpoint(playerid);
	#else
	    DisablePlayerCheckpoint(playerid);
	#endif
    return 1;
}

forward TrailerCheck(playerid);
public TrailerCheck(playerid)
{
    if (minfo[playerid][TrailerID] == GetVehicleTrailer(GetPlayerVehicleID(playerid)))
    {
        if (minfo[playerid][TrailerCheckCount] >= 1)
        {
	        new TimeRemaining;
	        TimeRemaining = 30 - minfo[playerid][TrailerCheckCount];
	        SendClientMessage(playerid, 0x00FF00FF, s);
	        format(s, sizeof(s), "Has recuperado la carga a %d segundos de desaparecer!", TimeRemaining);
		}
		minfo[playerid][TrailerCheckCount] = 0;
        return 1;
	}
	if (minfo[playerid][TrailerCheckCount] == 0)
	{
		SendClientMessage(playerid, 0xFF0000AA, "Has perdido la carga, tienes 30 segundos para recuperarla!");
    	minfo[playerid][TrailerCheckCount]++;
	}
	minfo[playerid][TrailerCheckCount]++;
	if (minfo[playerid][TrailerCheckCount] >= 30)
	{
	    format(s, sizeof(s), "Pagaste $%d por la mercancia perdida", COST_OF_LOST_GOODS);
	    SendClientMessage(playerid, 0xFF0000AA, s);
	    GivePlayerMoney(playerid, -COST_OF_LOST_GOODS);
        KillTimer(TrailerCheckTimer[playerid]);
	    minfo[playerid][TrailerCheckCount] = 0;
	    minfo[playerid][AllowTrailerCheck] = false;
	    #if defined USE_RACE_CHECKPOINT
	    	DisablePlayerRaceCheckpoint(playerid);
		#else
		    DisablePlayerCheckpoint(playerid);
		#endif
	}
	return 1;
}