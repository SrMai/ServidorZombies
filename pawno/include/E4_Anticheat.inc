/*
	* #########################################################################
	* #####                     E4 Anticheat v2.0                         #####
	* #####                     By: AlexPoison11                          #####
	* #########################################################################
	* ####              Copyrights (C) 2010 All rights Reserved.          #####
	* #########################################################################
 */

/* -- Includes -- */
#include <a_samp>

/* -- Enum -- */
enum Data
{
	Float:pCurHealth,
	Float:pCurArmour,
	pCurInterior,
	pSpectating,
	pMoney,
};

/* -- New -- */
new Info[MAX_PLAYERS][Data];

/* -- Define -- */

/* -- Forward -- */
forward AntiHealthHack(playerid);
forward AntiArmourHack(playerid);
forward AntiIntHack(playerid);
forward AntiSpecHack(playerid);
forward AntiJetpackHack(playerid);
forward AntiMoneyHack(playerid);
forward CheckPing(playerid);
forward CheckWeapon(playerid);

/* -- OnPlayerConnect -- */
public OnPlayerConnect(playerid)
{
	if(!IsPlayerNPC(playerid))
	{
		SetTimerEx("AntiHealthHack", 100, 1, "d", playerid);
		SetTimerEx("AntiArmourHack", 100, 1, "d", playerid);
		SetTimerEx("AntiIntHack", 100, 1, "d", playerid);
		SetTimerEx("AntiSpecHack", 100, 1, "d", playerid);
		SetTimerEx("AntiJetpackHack", 100, 1, "d", playerid);
		SetTimerEx("CheckPing", 100, 1, "d", playerid);
		SetTimerEx("CheckWeapon", 100, 1, "d", playerid);
		Info[playerid][pMoney] = GetPlayerMoney(playerid);
	}
	return 1;
}

/* -- OnPlayerDeath -- */
public OnPlayerDeath(playerid, killerid, reason)
{
	Info[playerid][pCurHealth] = 100.0;
	Info[playerid][pCurArmour] = 0.0;
	return 1;
}

/* -- E4_SetPlayerHealth -- */
stock E4_SetPlayerHealth(playerid, Float:Health)
{
	Info[playerid][pCurHealth] = Health;
	SetPlayerHealth(playerid, Health);
	return 1;
}

/* -- E4_SetPlayerArmour -- */
stock E4_SetPlayerArmour(playerid, Float:Armour)
{
	Info[playerid][pCurArmour] = Armour;
	SetPlayerArmour(playerid, Armour);
	return 1;
}

/* -- E4_SetPlayerInterior -- */
stock E4_SetPlayerInterior(playerid, interior)
{
	Info[playerid][pCurInterior] = interior;
	SetPlayerInterior(playerid, interior);
	return 1;
}

/* -- E4_TogglePlayerSpectating -- */
stock E4_TogglePlayerSpectating(playerid, toggle)
{
	if(toggle == 1)
	{
		Info[playerid][pSpectating] = 1;
	}
	else if(toggle == 0)
	{
	    Info[palyerid][pSpectating] = 0;
	}
	return 1;
}

/* -- E4_GivePlayerMoney -- */
stock E4_GivePlayerMoney(playerid, money)
{
	if(IsPlayerConnected(playerid))
	{
		Info[playerid][pMoney] += money;
		GivePlayerMoney(playerid, money);
		return 1;
	}
	return 1;
}

/* -- E4_ResetPlayerMoney -- */
stock E4_ResetPlayerMoney(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    Info[playerid][pMoney] = 0;
	    ResetPlayerMoney(playerid);
	    return 1;
	}
	return 1;
}

/* -- AntiHealthHack -- */
public AntiHealthHack(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    new Float:Health;
	    GetPlayerHealth(playerid, Health);
		if(Info[playerid][pCurHealth] < Health)
		{
		    printf("E4 Log: %s (%d) - HealthHack", playerName(playerid), playerid);
		    BanEx(playerid, "[E4]: HealthHack");
		    return 1;
		}
	}
	return 1;
}

/* -- AntiArmourHack -- */
public AntiArmourHack(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    new Float:Armour;
	    GetPlayerArmour(playerid, Armour);
	    if(Info[playerid][pCurArmour] < Armour)
	    {
	        printf("E4 Log: %s (%d) - ArmourHack", playerName(playerid), playerid);
			BanEx(playerid, "[E4]: ArmourHack");
			return 1;
		}
	}
	return 1;
}

/* -- AntiIntHack -- */
public AntiIntHack(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    new interior;
	    interior = GetPlayerInterior(playerid);
	    if(Info[playerid][pCurInterior] != interior)
	    {
	        printf("E4 Log: %s (%d) - InteriorHack (PosHack)", playerName(playerid), playerid);
	        BanEx(playerid, "[E4]: InteriorHack/PosHack");
	        return 1;
		}
	}
	return 1;
}

/* -- AntiSpecHack -- */
public AntiSpecHack(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    if(!IsPlayerAdmin(playerid))
	    {
	        if(Info[playerid][pSpectating] == 1)
	        {
	            printf("E4 Log: %s (%d) - SpecHack", playerName(playerid), playerid);
	            BanEx(playerid, "[E4]: SpecHack");
				return 1;
			}
		}
	}
	return 1;
}

/* -- AntiJetpackHack -- */
public AntiJetpackHack(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    if(!IsPlayerAdmin(playerid))
	    {
	        if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
	        {
	            printf("E4 Log: %s (%d) - JetpackHack", playerName(playerid), playerid);
				BanEx(playerid, "[E4]: JetpackHack");
				return 1;
			}
		}
	}
	return 1;
}

/* -- AntiMoneyHack -- */
public AntiMoneyHack(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    if(!IsPlayerAdmin(playerid))
	    {
	        if(Info[playerid][pMoney] < GetPlayerMoney(playerid))
	        {
	            printf("E4 Log: %s (%d) - MoneyHack (%d - %d)", playerName(playerid), playerid, Info[playerid][pMoney], GetPlayerMoney(playerid));
				BanEx(playerid, "[E4]: MoneyHack");
				return 1;
			}
		}
	}
	return 1;
}

/* -- CheckPing -- */
public CheckPing(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    if(!IsPlayerAdmin(playerid))
	    {
	        if(GetPlayerPing(playerid) > 400 && GetPlayerPing(playerid) != 65535)
	        {
	            printf("E4 Log: %s (%d) - Ping: %d", playerName(playerid), playerid);
				Kick(playerid);
				return 1;
			}
		}
	}
	return 1;
}

/* -- CheckWeapon -- */
public CheckWeapon(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		new Weapon = GetPlayerWeapon(playerid);
		if(Weapon == 38 || Weapon == 35 || Weapon == 36 || Weapon == 37 || Weapon == 39)
		{
		    printf("E4 Log: %s (%d) - WeaponHack", playerName(playerid), playerid);
		    BanEx(playerid, "[E4]: WeaponHack");
		    return 1;
		}
	}
	return 1;
}

/* -- playerName -- */
stock playerName(playerid)
{
	new prtn1[MAX_PLAYER_NAME];
	GetPlayerName(playerid, prtn1, sizeof(prtn1));
	return prtn1;
}

