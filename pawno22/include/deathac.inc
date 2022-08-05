#include <a_samp>
#include <globalvars>

#define COLOR_RED 0xAA3333AA

forward AC_OnInit();
forward ArmorDetection();
forward MoneyDetection();
forward WeaponDetection();
forward SendAdminMessage(color, stringe[]);
forward SafeGivePlayerMoney(plyid, amounttogive);
forward SafeGivePlayerWeapon(plyid, weaponid, ammo);
forward SafeGetPlayerMoney(plyid);
forward SafeResetPlayerMoney(plyid);
forward SafeResetPlayerWeaponsAC(plyid);

public AC_OnInit()
{
	SetTimer("MoneyDetection", 100, 1);
	SetTimer("WeaponDetection", 100, 1);
	SetTimer("ArmorDetection", 100, 1);
	return 1;
}

new ScriptMoney[MAX_PLAYERS];
new ScriptWeapons[MAX_PLAYERS][13];
new ScriptAmmo[MAX_PLAYERS][13];

public MoneyDetection()
{
	new pname[24];
	new string[256];
 	for(new playerid; playerid < 700; playerid++)
 	{
 	    GetPlayerName(playerid, pname, 24);
  		if(GetPlayerMoney(playerid) > SafeGetPlayerMoney(playerid))
   		{
			ResetPlayerMoney(playerid);
			GivePlayerMoney(playerid, SafeGetPlayerMoney(playerid));
			format(string, 128, "* %s (ID:%d) ha usado trampas para spawnear dinero.",pname, playerid);
  			//SendAdminMessage(COLOR_RED, string);
		}
	}
}

public WeaponDetection()
{
    new pname[24];
	new w[MAX_PLAYERS],a[MAX_PLAYERS];
	new string[256];
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
	    GetPlayerName(i, pname, 24);
	    if (IsPlayerConnected(i))
	    {
			if (GetPlayerSpecialAction(i) == SPECIAL_ACTION_USEJETPACK)
			{
				format(string, 128, "* %s (ID:%d) ha usado trampas para spawnear un JetPack. (Kickeado)",pname, i);
  				SendAdminMessage(COLOR_RED, string);
  				Kick(i);
				break;
			}
			w[i] = 0;
			a[i] = 0;
	        for(new s = 0; s < 13; s++)
	        {
         		GetPlayerWeaponData(i, s, w[i], a[i]);
           		if (ScriptWeapons[i][s] != w[i])
             	{
              		if (a[i] > ScriptAmmo[i][GetWeaponSlot(w[i])])
           			{
              			if ((a[i] - ScriptAmmo[i][GetWeaponSlot(w[i])]) >= 69)
              			{
							SafeResetPlayerWeaponsAC(i);
 							format(string, 128, "* %s (ID:%d) ha usado trampas para spawnear Armas/Ammo.",pname, i);
  							SendAdminMessage(COLOR_RED, string);
	                        break;
                    	}
                   	}
             	}
	        }
	    }
	}
}
/*
public SendAdminMessage(color, stringe[])
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
		    if(PlayerInfo[i][pAdmin] >= 1)
		    {
				SendClientMessage(i, color, stringe);
			}
		}
	}
}*/

public SafeGivePlayerMoney(plyid, amounttogive)
{
	if (amounttogive < 0)
	{
		ScriptMoney[plyid] = (ScriptMoney[plyid] + amounttogive);
		GivePlayerMoney(plyid, amounttogive);
	}
	else
	{
		ScriptMoney[plyid] = (ScriptMoney[plyid] + amounttogive);
		GivePlayerMoney(plyid, amounttogive);
	}
	return 1;
}

public SafeResetPlayerMoney(plyid)
{
   	ScriptMoney[plyid] = 0;
	ResetPlayerMoney(plyid);
	return 1;
}

public SafeGivePlayerWeapon(plyid, weaponid, ammo)
{
	new slot = GetWeaponSlot(weaponid);
	ScriptWeapons[plyid][slot] = weaponid;
	ScriptAmmo[plyid][slot] = ammo;
	GivePlayerWeapon(plyid, weaponid, ammo);
	return 1;
}

public SafeResetPlayerWeaponsAC(plyid)
{
	for(new slot; slot < 13; slot++)
	{
	    ScriptWeapons[plyid][slot] = 0;
   	 	ScriptAmmo[plyid][slot] = 0;
	}
	ResetPlayerWeapons(plyid);
	return 1;
}

public SafeGetPlayerMoney(plyid)
{
	return ScriptMoney[plyid];
}

forward GetWeaponSlot(weaponid);
public GetWeaponSlot(weaponid)
{
	new slot;
	switch(weaponid)
	{
		case 0, 1: slot = 0;
		case 2 .. 9: slot = 1;
		case 22 .. 24: slot = 2;
		case 25 .. 27: slot = 3;
		case 28, 29, 32: slot = 4;
		case 30, 31: slot = 5;
		case 33, 34: slot = 6;
		case 35 .. 38: slot = 7;
		case 16, 18, 39: slot = 8;
		case 42, 43: slot = 9;
		case 14: slot = 10;
		case 44 .. 46: slot = 11;
		case 40: slot = 12;
		default: slot = -1;
	}
	return slot;
}
