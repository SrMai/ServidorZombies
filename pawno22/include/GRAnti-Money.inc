/*
	---------------------------------------------------------
	|		  GR_Anti-Money				|
	|		Script by GROVE4L			|									---------------------------------------------------------
*/


#include <a_samp>

new DineroAntiGR[MAX_PLAYERS];
new TAntiG[MAX_PLAYERS];

forward AntiG(playerid);

forward ActivarAntiDineroGR (playerid);
public ActivarAntiDineroGR(playerid)
{
	TAntiG[playerid] = SetTimerEx("AntiG", 1000, 0,"d",playerid);
	return 1;
}

forward GR_OnPlayerSpawn(playerid);
public GR_OnPlayerSpawn(playerid)
{
	new CashAGR = GetPlayerMoney(playerid);
	DineroAntiGR[playerid] = CashAGR;
	return 1;
}

public AntiG(playerid)
{
	if(DineroAntiGR[playerid] <= GetPlayerMoney(playerid))
	{
	    if(DineroAntiGR[playerid] != GetPlayerMoney(playerid))
	    {
         	GivePlayerMoney(playerid,-GetPlayerMoney(playerid));
         	GivePlayerMoney(playerid,DineroAntiGR[playerid]);
         	SendClientMessage(playerid,0xAA3333AA,"Anti-Cheat CRP: Te Hemos Detectado Dinero Cheat Te hemos devuelto al que Tenias ");
         	SendClientMessage(playerid,0xFFFFFFAA,"Si Crees Que No Fue Asi Comunicate Con un Adm Mas Inf: www.colombiarolerplay.com");
         	TAntiG[playerid] = SetTimerEx("AntiG", 1000, 0,"d",playerid);
		}
		else
		{
		    TAntiG[playerid] = SetTimerEx("AntiG", 1000, 0,"d",playerid);
		}
	}
	else
	{
	    TAntiG[playerid] = SetTimerEx("AntiG", 1000, 0,"d",playerid);
	}
	return 1;
}

stock SetPlayerMoneyGR(playerid, Cantidad)
{
    DineroAntiGR[playerid] = 0;
	ResetPlayerMoney(playerid);
    DineroAntiGR[playerid] += Cantidad;
	GivePlayerMoney(playerid,Cantidad);
	return 1;
}

stock GivePlayerMoneyGR(playerid,Cantidad)
{
	if(Cantidad == 0)
	{
	    return 1;
	}
	else if(Cantidad >= 1)
	{
	    DineroAntiGR[playerid] += Cantidad;
	    GivePlayerMoney(playerid,Cantidad);
	    return 1;
	}
 	else if(Cantidad <= -1)
 	{
	    GivePlayerMoney(playerid, Cantidad);
	    DineroAntiGR[playerid] = GetPlayerMoney(playerid);
		return 1;
	}
	return 1;
}

stock ResetPlayerMoneyGR(playerid)
{
    DineroAntiGR[playerid] = 0;
	ResetPlayerMoney(playerid);
	return 1;
}

stock GetPlayerMoneyGR(playerid)
{
	return DineroAntiGR[playerid];
}

stock SetPlayerMoney_(playerid, Cantidad)
{
    DineroAntiGR[playerid] = 0;
	ResetPlayerMoney(playerid);
    DineroAntiGR[playerid] += Cantidad;
	GivePlayerMoney(playerid,Cantidad);
	return 1;
}

stock GivePlayerMoney_(playerid,Cantidad)
{
	if(Cantidad == 0)
	{
	    return 1;
	}
	else if(Cantidad >= 1)
	{
	    DineroAntiGR[playerid] += Cantidad;
	    GivePlayerMoney(playerid,Cantidad);
	    return 1;
	}
 	else if(Cantidad <= -1)
 	{
	    GivePlayerMoney(playerid, Cantidad);
	    DineroAntiGR[playerid] = GetPlayerMoney(playerid);
		return 1;
	}
	return 1;
}

stock ResetPlayerMoney_(playerid)
{
    DineroAntiGR[playerid] = 0;
	ResetPlayerMoney(playerid);
	return 1;
}

stock GetPlayerMoney_(playerid)
{
	return DineroAntiGR[playerid];
}

/*
	-------------------------------------------------------------------------
	|	     BY GROVE4L  || Visita: www.pawnoscripting.com		|
	-------------------------------------------------------------------------
*/