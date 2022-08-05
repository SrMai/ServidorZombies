/*
	=========================================
	Anticheat de Vida, creado por Cesar_Biker
	=========================================
	Descripción:
		Permite detectar si un jugador se ha sumado vida con cualquier tipo de cheat
		y informar al servidor.
	Versión:
		2.0
	ChangeLog:
		07/08/2010 :
			Primer lanzamiento, con algunos bugs
		02/09/2010 :
			Segundo lanzamiento, arreglados algunos bugs que daban warnings al compilar
	Funciones:
		public UnJugadorHaHackeadoVida(playerid, Float:VidaExtra)
			playerid - jugador que se ha sumado la vida ilegalmente
			VidaExtra - Vida que se ha sumado ilegalmente
	Licencia:
		This program is free software: you can redistribute it and/or modify
		it under the terms of the GNU General Public License as published by
		the Free Software Foundation, either version 3 of the License, or
		(at your option) any later version.
	
		This program is distributed in the hope that it will be useful,
		but WITHOUT ANY WARRANTY; without even the implied warranty of
		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
		GNU General Public License for more details.
	
		You should have received a copy of the GNU General Public License
		along with this program.  If not, see <http://www.gnu.org/licenses/>.
	=========================================
*/
forward ComprovarHP();
forward GetPlayerHealthEx(playerid, &Float:health);
forward SetPlayerHealthEx(playerid, Float:health);
forward UnJugadorHaHackeadoVida(playerid, Float:VidaExtra);
//===============[forward Funciones públicas]==================
forward OnPlayerDeath2(playerid,killerid,reason);
//=============================================================
forward OnPlayerConnect2(playerid);
forward OnPlayerDisconnect2(playerid,reason);
//=============================================================
forward OnPlayerRequestClass2(playerid,classid);
forward OnPlayerSpawn2(playerid);
//===============[forward Funciones include]===================
new Float:VidaDelServer[MAX_PLAYERS];
new Float:Vida;
new Float:VidaH;
new ComprovarTimer;
new bool:Spawned[MAX_PLAYERS];
//===============[OnFilterScriptInit]===========================
public OnGameModeInit()
{
	VidaIniciar();
	return CallLocalFunction("OnGameModeInit2","");
}
//===============[OnFilterScriptExit]===========================
public OnGameModeExit()
{
	VidaApagar();
	return CallLocalFunction("OnGameModeExit2","");
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
//===============[forward FilterScript Int/Exit]===============
forward OnGameModeInit2();
forward OnGameModeExit2();
//===============[funcion Apagar Timer Vida]====================
VidaApagar()
{
	KillTimer(ComprovarTimer);
	return 1;
}
//===============[funcion Iniciar Timer Vida]===================
VidaIniciar()
{
	ComprovarTimer = SetTimer("ComprovarHP",1000,true);
	return 1;
}
//===============[OnPlayerConnect]==============================
public OnPlayerConnect(playerid)
{
	Spawned[playerid]=false;
	return CallLocalFunction("OnPlayerConnect2","i",playerid);
}
//===============[OnPlayerDisconnect]===========================
public OnPlayerDisconnect(playerid,reason)
{
	Spawned[playerid]=false;
	return CallLocalFunction("OnPlayerDisconnect2","ii",playerid,reason);
}
//===============[OnPlayerSpawn]================================
public OnPlayerSpawn(playerid)
{
	Spawned[playerid]=true;
	return CallLocalFunction("OnPlayerSpawn2","i",playerid);
}
//===============[OnPlayerRequestClass]=========================
public OnPlayerRequestClass(playerid,classid)
{
	Spawned[playerid]=false;
	return CallLocalFunction("OnPlayerRequestClass2","ii",playerid,classid);
}
//===============[OnPlayerDeath]================================
public OnPlayerDeath(playerid,killerid,reason)
{
	Spawned[playerid]=false;
	return CallLocalFunction("OnPlayerDeath2","iii",playerid,killerid,reason);
}
//===============[Obtener la Vida del jugador]==================
public GetPlayerHealthEx(playerid, &Float:health)
{
	health = VidaDelServer[playerid];
	return 1;
}
//===============[Cambiar la Vida del Jugador]==================
public SetPlayerHealthEx(playerid, Float:health)
{
	VidaDelServer[playerid] = health;
	SetPlayerHealth(playerid, health);
	return 1;
}
//===============[Timer Comprovar Vida]=========================
public ComprovarHP()
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
		    GetPlayerHealth(i, Vida);
			if(Vida > VidaDelServer[i] && Spawned[i] == true)
			{
			    VidaH = Vida - VidaDelServer[i];
			    UnJugadorHaHackeadoVida(i,VidaH);
			    SetPlayerHealth(i,VidaDelServer[i]);
			}
			else if(Vida < VidaDelServer[i] && Spawned[i] == true)
			{
			    VidaDelServer[i] = Vida;
			}
		}
	}
}
//===============[Convertir funciones normales en inc]========== 
#define SetPlayerHealth SetPlayerHealthEx
//==============================================================
#define OnGameModeInit OnGameModeInit2
#define OnGameModeExit OnGameModeExit2
//==============================================================
#define OnPlayerDeath OnPlayerDeath2
//==============================================================
#define OnPlayerConnect OnPlayerConnect2
#define OnPlayerDisconnect OnPlayerDisconnect2
//==============================================================
#define OnPlayerRequestClass OnPlayerRequestClass2
#define OnPlayerSpawn OnPlayerSpawn2