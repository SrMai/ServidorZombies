//
// Created:     05.09.06
// Aurthor:    Iain Gilbert
//


#if defined _weapons_included
  #endinput
#endif

#define _weapons_included
#pragma library weapons
#include "base"
#define MAX_WEAPONS 50
#define MAX_BULLETS 999

enum WeaponInfo {
	Weapon_ID,              // id number of weapon
	Weapon_Name[MAX_NAME], // weapon name
	Weapon_Allowed, 		// is weapon allowed
	Weapon_MaxBullets,      // max bullets
	Weapon_Cost,           // cost per bullet
	Weapon_Level          // player level required to buy this weapon
}
#define WeaponsSize 46
new Weapons[WeaponsSize][WeaponInfo] = {

//id,	"Name"           	,Allowed,bullets,   cost    , level
{0,		"Unarmed"			,   1   ,   1   ,   0   	,   0},
{22,	"Pistol"   			,   1   ,   999 ,   25		,   0},
{25,	"Shotgun"   		,   1   ,   999 ,   100		,   1},
{23,	"Silenced Pistol"  	,   1   , 	999 , 	25		,   2},
{24,	"Desert Eagle"   	,   1   ,   999 ,   200		,   3},
{26,	"Sawn Off Shotgun" 	,   1   ,   999 ,   300		,   4},
{28,	"Micro Uzi"			,   1   ,   999 ,   100		,   5},
{9,		"Chainsaw"   		,   1   ,   1   ,   5000	,   6},
{32,	"Tec9"   			,   1   ,   999 ,   150		,   7},
{33,	"Rifle"  			,   1   ,   999 ,   500		,   8},
{10,	"Purple Dildo"   	,   1   ,   1   ,   1000	,   8},
{29,	"MP5"   			,   1   ,   999 ,   200		,   9},
{4,		"Knife"   			,   1   ,   1   ,   10000	,   10},
{46,	"Parachute"   		,   1   ,   1   ,   20000	,   11},
{27,	"Combat Shotgun"   	,   1   ,   999 ,   750		,   12},
{3,		"Night Stick"   	,   1   ,   1   ,   5000	,   13},
{31,	"M4"   				,   1   ,   999 ,   300		,   14},
{12,	"Long White Dildo" 	,   1   ,   1   ,   5000	,   15},
{37,	"Flame Thrower"   	,   1   ,   999 ,   1000	,   16},
{8,		"Katana"   			,   1   ,   1   ,   20000	,   17},
{30,	"AK47"   			,   1   ,   999 ,   1500	,   18},
{38,	"Minigun"   		,   1   ,   999 ,   5000	,   19},
{42,	"Fire Extinguisher"	,   1   ,   999 ,   1000	,   20},

{39,	"Sachel Charges"   	,   0   ,   9 ,   	10000	,   20},
{40,	"Detonator"   		,   0   ,   1   ,   100		,   20},

{1,		"Brass Knuckles"   	,   0   ,   1   ,   1000	,   0},
{2,		"Golf Club"   		,   0   ,   1   ,   1000	,   0},
{3,		"Night Stick"   	,   0   ,   1   ,   1000	,   0},
{5,		"Baseball Bat"   	,   0   ,   1   ,   1000	,   0},
{6,		"Shovel"   			,   0   ,   1   ,   1000	,   0},
{7,		"Pool cue"  		,   0   ,   1   ,   1000	,   0},
{11,	"White Dildo"   	,   0   ,   1   ,   1000	,   0},
{12,	"Long White Dildo" 	,   0   ,   1   ,   1000	,   0},
{13,	"White Dildo 2"   	,   0   ,   1   ,   1000	,   0},
{14,	"Flowers"   		,   0   ,   1   ,   1000	,   0},
{15,	"Cane"   			,   0   ,   1   ,   1000	,   0},
{16,	"Grenades"   		,   0   ,   1   ,   1000	,   0},
{17,	"Tear Gas"   		,   0   ,   1   ,   1000	,   0},
{18,	"Molotovs"   		,   0   ,   1   ,   1000	,   0},
{34,	"Sniper Rifle"   	,   0   ,   1   ,   1000	,   0},
{35,	"RPG"   			,   0   ,   1   ,   1000	,   0},
{36,	"Missile Launcher" 	,   0   ,   1   ,   1000	,   0},
{41,	"Spray Paint"   	,   0   ,   1   ,   1000	,   0},
{43,	"Camera"   			,   0   ,   1   ,   1000	,   0},
{44,	"Nightvision Goggles",  0   ,   1   ,   1000	,   0},
{45,	"Thermal Goggles"	,   0   ,   1   ,   1000	,   0}
};

#define AmmunationsCount 3
new Ammunations[AmmunationsCount][CoordInfo] = {
{291.0004,-84.5168,1001.5156}, // LVammunation1
{293.2710,-108.9645,1001.5156}, // LSAmmunation1
{290.3177,-38.7184,1001.5156} // LSAmmunation2
};

new WeaponDB[MAX_STRING] = "GTO\\Weapon\\";

WeaponLoadAll()
{
	if (ForceOverwrite) return;
	new temp[MAX_STRING];
	if (!dini_Exists(ConfigDB)) dini_Create(ConfigDB);
	set(temp,dini_Get(ConfigDB,"Weapon_DB"));
	if (strlen(temp) > 0) set(WeaponDB,temp);

	if (!dini_Exists(WeaponDB))
	{
		WeaponSaveAll();
		return;
	}
	for (new i=0;i<WeaponsSize;i++)
	{
 		new weapondbname[MAX_STRING];
 		format(weapondbname,sizeof(weapondbname),"%sGTO.Weapon.%s.txt",WeaponDB,Weapons[i][Weapon_Name]);
 		set(temp,dini_Get(weapondbname,"Name"));
 		if (strlen(temp) > 0) set(Weapons[i][Weapon_Name],temp);
 		set(temp,nullstr);
 		set(temp,dini_Get(weapondbname,"IsAllowed"));
 		if (strlen(temp) > 0) Weapons[i][Weapon_Allowed] = strval(temp);
 		set(temp,nullstr);
 		set(temp,dini_Get(weapondbname,"Level"));
 		if (strlen(temp) > 0) Weapons[i][Weapon_Level] = strval(temp);
 		set(temp,nullstr);
 		set(temp,dini_Get(weapondbname,"Price"));
 		if (strlen(temp) > 0) Weapons[i][Weapon_Cost] = strval(temp);
 		set(temp,nullstr);
	}
	return;
}
	
WeaponSaveAll()
{
	new temp[MAX_STRING];
	if (dini_Exists(ConfigDB))
	{
		dini_Set(ConfigDB,"Weapon_DB",WeaponDB);
	}
	
	for (new i=0;i<WeaponsSize;i++)
	{
 		new weapondbname[MAX_STRING];
 		format(weapondbname,sizeof(weapondbname),"%sGTO.Weapon.%s.txt",WeaponDB,Weapons[i][Weapon_Name]);
		if (!dini_Exists(weapondbname)) dini_Create(weapondbname);
		dini_Set(weapondbname,"Name",Weapons[i][Weapon_Name]);
		valstr(temp,Weapons[i][Weapon_Allowed]);
 		dini_Set(weapondbname,"IsAllowed",temp);
 		set(temp,nullstr);
 		valstr(temp,Weapons[i][Weapon_Level]);
 		dini_Set(weapondbname,"Level",temp);
 		set(temp,nullstr);
 		valstr(temp,Weapons[i][Weapon_Cost]);
 		dini_Set(weapondbname,"Price",temp);
 		set(temp,nullstr);
	}
	return;
}

public AmmunationInit()
{
	for (new id=0;id<AmmunationsCount;id++)
	{
		AddActiveCheckpoint(Ammunations[id][Coord_X],Ammunations[id][Coord_Y],Ammunations[id][Coord_Z],20,2);
	}
}

public IsPlayerAtAmmunation(playerid)
{
	for (new id=0;id<AmmunationsCount;id++)
	{
		if (oIsPlayerInCheckpoint(playerid,Ammunations[id][Coord_X],Ammunations[id][Coord_Y],Ammunations[id][Coord_Z],10))
		{
		    return 1;
		}
	}
 return 0;
}

public OnPlayerEnterAmmoCheckpoint(playerid)
{
	if (playerid == INVALID_PLAYER_ID) return;
	if (!IsPlayerConnected(playerid)) return;
	if (!IsPlayerAtAmmunation(playerid)) return;
	SendPlayerFormattedText(playerid, "You are at an Ammunation store. You can buy weapons and ammo here." , 0,COLOUR_GREEN);
	SendPlayerFormattedText(playerid, "For a list of weapons for sale use '/weapon list' (or /weapon buy, /wl, /weaponlist)." , 0,COLOUR_GREEN);
	SendPlayerFormattedText(playerid, "To buy a weapon use '/weapon buy <weaponid> <bullets>' (or /wb, /weaponbuy, /bw)." , 0,COLOUR_GREEN);
	SendPlayerFormattedText(playerid, "For a list of weapons you currently own use '/weapons'. For more help on weapons use '/weapon help'." , 0,COLOUR_GREEN);

}

oGetWeaponName(weaponid)
{
    new name[MAX_NAME];
	new lookupid=GetWeaponLookupID(weaponid);
	if (lookupid == -1) return name;
	set(name,Weapons[lookupid][Weapon_Name]);
 	return name;
}

GetWeaponMaxAmmo(weaponid)
{
    new ammo;
	new lookupid=GetWeaponLookupID(weaponid);
	if (lookupid == -1) return ammo;
	ammo = Weapons[lookupid][Weapon_MaxBullets];
 	return ammo;
}

public IsPlayerAllowedWeapon(playerid,weaponid)
{
	new lookupid=GetWeaponLookupID(weaponid);
	if (lookupid == -1) return 0;
	if (Weapons[lookupid][Weapon_Allowed] == 0) return 0;
	if (Weapons[lookupid][Weapon_Level] > GetPlayerLevel(playerid)) return 0;
	return 1;
}

IsWeaponHandToHand(weaponid)
{
	new weaponlookupid=GetWeaponLookupID(weaponid);
	if (weaponlookupid == -1) return 0;
 	if (Weapons[weaponlookupid][Weapon_MaxBullets] == 1) return 1;
	return 0;
}

GetWeaponCost(weaponid)
{
	new weaponlookupid=GetWeaponLookupID(weaponid);
	if (weaponlookupid == -1) return 0;
 	return Weapons[weaponlookupid][Weapon_Cost];
}

GetWeaponLookupID(weaponid)
{
	new lookupid=-1;
	for (new i=0;i<WeaponsSize;i++)
	{
		if (weaponid == Weapons[i][Weapon_ID])
		{
		    lookupid = i;
		}
	}
	return lookupid;
}

IsWeapon(weaponid)
{
	if ((weaponid >= 0) && (weaponid <= 45)) return 1;
	return 0;
}

IsStoreWeapon(weaponid)
{

	if ((weaponid >= 22) && (weaponid <=32)) return 1;
	return 0;
/*
22   Pistol,            
23   Silenced Pistol,     
24   Desert Eagle,         
25   Shotgun,      
26   Sawn Off Shotgun,         
27   Combat Shotgun,        
28   Micro Uzi (Mac 10),    
29   MP5,        
30   AK47,    
31   M4,    
32   Tec9,
*/
}

SendPlayerVendorWeapons(playerid)
{
	new string[MAX_STRING];
	SendPlayerFormattedText(playerid, "Available weapons:" , 0,COLOUR_GREEN);
	for (new weaponid=1;weaponid<MAX_WEAPONS;weaponid++)
	{
	 	if (IsPlayerAllowedWeapon(playerid,weaponid))
		{
			format(string,sizeof(string),"Weapon: '%s'. Price: $%d. ID: %d.",oGetWeaponName(weaponid),GetWeaponCost(weaponid),weaponid);
			SendPlayerScrollingText(playerid, string);
		}
	}
}

public BuyWeapon(playerid,weaponid,bullets)
{
	new string[MAX_STRING];
	if ((weaponid < 1) || (weaponid > 45))
	{
		SendPlayerFormattedText(playerid, "Invalid weaponid." , 0,COLOUR_RED);
		return 0;
	}
	if ((bullets < 1) || (bullets > 999))
	{
		SendPlayerFormattedText(playerid, "Invalid bullets amount." , 0,COLOUR_RED);
		return 0;
	}
	if (!IsPlayerAtAmmunation(playerid))
	{
	   	SendPlayerFormattedText(playerid, "You must be at an Ammunation store to buy weapons." , 0,COLOUR_RED);
		return 0;
	}
	
	if (!IsPlayerAllowedWeapon(playerid,weaponid))
	{
	    format(string,sizeof(string),"You cannot buy that weapon: '%s'",oGetWeaponName(weaponid));
	   	SendPlayerFormattedText(playerid,string,0,COLOUR_RED);
		return 0;
	}
	new purchasecost;
	purchasecost = GetWeaponCost(weaponid) * bullets;
	if (purchasecost < 1)
	{
	    format(string,sizeof(string),"You cannot buy that weapon: '%s'",oGetWeaponName(weaponid));
	  	SendPlayerFormattedText(playerid, string,0,COLOUR_RED);
		return 0;
	}
	if (oGetPlayerMoney(playerid) < purchasecost)
	{
		format(string,sizeof(string),"You need $%d to make that purchase." , purchasecost);
	  	SendPlayerFormattedText(playerid, string,0,COLOUR_RED);
		return 0;
	}
	
	oGivePlayerMoney(playerid,0-purchasecost,1);
	oGivePlayerWeapon(playerid,weaponid,bullets);
	if (bullets > 1)
	{
		format(string,sizeof(string),"You bought %d ammo for weapon '%s'. Cost: $%d.",bullets,oGetWeaponName(weaponid),purchasecost);
	}
	else
	{
		format(string,sizeof(string),"You bought weapon '%s'. Cost: $%d.",oGetWeaponName(weaponid),purchasecost);
	}
	SendPlayerFormattedText(playerid, string, 0,COLOUR_GREEN);
	SendPlayerFormattedText(playerid, "Transaction Successful." , 0,COLOUR_GREEN);
	return 1;
}

public AmmunationCommandHandler(playerid,text[]) // process player commands
{
	if (!IsPlayerRegistered(playerid))
	{
		return 0; // non registered players dont use weapon commands
	}

	new cmd[20];
	new idx;

	set(cmd,strcharsplit(text, idx,strchar(" ")));
	if (strlen(cmd) == 0) return 0;

    if(strcomp(cmd, "/weapons", true) == 1)
	{

		SendPlayerOwnedWeapons(playerid);
     	return 1;
	}

    if((strcomp(cmd, "/wl", true) == 1) || (strcomp(cmd, "/weaponlist", true) == 1))
	{
		if (!IsPlayerAtAmmunation(playerid))
	    {
	    	SendPlayerFormattedText(playerid, "You must be at an Ammunation store to buy weapons." , 0,COLOUR_RED);
			return 1;
	    }
	    SendPlayerVendorWeapons(playerid);
	    return 1;
	}
	    
	
    if((strcomp(cmd, "/wb", true) == 1) || (strcomp(cmd, "/weaponbuy", true) == 1))
	{
	 	if (!IsPlayerAtAmmunation(playerid))
	    {
	    	SendPlayerFormattedText(playerid, "You must be at an Ammunation store to buy weapons." , 0,COLOUR_RED);
			return 1;
	    }
	    
	    // get weaponid
	    new weaponid;
		set(cmd,strcharsplit(text, idx,strchar(" ")));
		if (strlen(cmd) == 0)
		{
			SendPlayerVendorWeapons(playerid);
			//SendPlayerFormattedText(playerid, "Command usage: '/weapon buy <weaponid> <bullets>'" , 0,COLOUR_RED);
			return 1;
		}
  		weaponid = strval(cmd);
  		if (weaponid <= 0)
  		{
  			SendPlayerFormattedText(playerid, "Command usage: '/weapon buy <weaponid> <bullets>'" , 0,COLOUR_RED);
  		    return 1;
		}
		
		// get bullets
		new bullets;
		set(cmd,strcharsplit(text, idx,strchar(" ")));
		if (strlen(cmd) == 0)
		{
			bullets=1;
		}
		else
		{
			bullets = strval(cmd);
		}
  		if (bullets < 0)
  		{
  			SendPlayerFormattedText(playerid, "Command usage: '/weapon buy <weaponid> <bullets>'" , 0,COLOUR_RED);
  		    return 1;
		}
		BuyWeapon(playerid,weaponid,bullets);
		return 1;
	}
	
	if(strcomp(cmd, "/weapon", true) == 1)
	{
		set(cmd,strcharsplit(text, idx,strchar(" ")));
		
		if(strcomp(cmd, "help", true) == 1)
		{
			SendPlayerFormattedText(playerid, "TODO: weapon help." , 0,COLOUR_RED);
			return 1;
		}
		
		if (strcomp(cmd, "list", true) == 1)
		{
			if (!IsPlayerAtAmmunation(playerid))
	    	{
	    		SendPlayerFormattedText(playerid, "You must be at an Ammunation store to buy weapons." , 0,COLOUR_RED);
				return 1;
	    	}
	    	SendPlayerVendorWeapons(playerid);
	    	return 1;
		}
	
		if(strcomp(cmd, "buy", true) == 1)
		{
	 		if (!IsPlayerAtAmmunation(playerid))
	    	{
	    		SendPlayerFormattedText(playerid, "You must be at an Ammunation store to buy weapons." , 0,COLOUR_RED);
				return 1;
	    	}

	    	// get weaponid
	    	new weaponid;
			set(cmd,strcharsplit(text, idx,strchar(" ")));
			if (strlen(cmd) == 0)
			{
			    SendPlayerVendorWeapons(playerid);
				//SendPlayerFormattedText(playerid, "Command usage: '/weapon buy <weaponid> <bullets>'" , 0,COLOUR_RED);
				return 1;
			}
  			weaponid = strval(cmd);
  			if (weaponid <= 0)
  			{
  				SendPlayerFormattedText(playerid, "Command usage: '/weapon buy <weaponid> <bullets>'" , 0,COLOUR_RED);
  		   	 	return 1;
			}

			// get bullets
			new bullets;
			set(cmd,strcharsplit(text, idx,strchar(" ")));
			if (strlen(cmd) == 0)
			{
				bullets=1;
			}
			else
			{
				bullets = strval(cmd);
			}
  			if (bullets < 0)
  			{
  				SendPlayerFormattedText(playerid, "Command usage: '/weapon buy <weaponid> <bullets>'" , 0,COLOUR_RED);
  		   		return 1;
			}
			BuyWeapon(playerid,weaponid,bullets);
			return 1;
		}
	}
	return 0;
}

