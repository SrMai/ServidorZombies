#include <a_samp>
#include <core>
#include <float>
//Librerias MySQL
#include <YSI_Data\y_iterate>
#include <a_mysql>

//Variables MySQL
#define mysql_host 	"localhost"
#define mysql_user 	"root"
#define mysql_pass 	""
#define mysql_database 	"gta"

new PogresnaLozinka[MAX_PLAYERS];

new MySQL:Database;

enum {
	d_reg,
	d_log
}

enum PlayerInfo{
    ID,
    Name[25],
    Password[65],
    Kills,
    Deaths,
    Cash,
    Score
}
new PI[MAX_PLAYERS][PlayerInfo];


main()
{
	print("\n----------------------------------");
	print("  Zombies\n");
	print("----------------------------------\n");
}

public OnPlayerConnect(playerid)
{
	GameTextForPlayer(playerid,"~w~SA-MP: ~r~Zombies",5000,5);new DB_Query[115];
	GetPlayerName(playerid, PI[playerid][Name], MAX_PLAYER_NAME);
	mysql_format(Database, DB_Query, sizeof(DB_Query), "SELECT * FROM `users` WHERE `Username` = '%e' LIMIT 1", PI[playerid][Name]);
	mysql_tquery(Database, DB_Query, "OnPlayerDataCheck", "i", playerid);
	//++
	PogresnaLozinka[playerid] = 0;
	return (true);
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
	switch(dialogid) {
		case d_reg: {
			if(strlen(inputtext) < 6 || strlen(inputtext) > 24) {
				SendClientMessage(playerid, -1, "La contraseña no puede tener menos de 6 ni más de 24 caracteres");
				ShowPlayerDialog(playerid, d_reg, DIALOG_STYLE_PASSWORD, "Registro del servidor","Ingrese su contraseña para registrarse en el servidor","Registro","Abandonar");
				return (false);
			}
			else {
				new DB_Query[256];
				SHA256_PassHash(inputtext, GetName(playerid), PI[playerid][Password], 65);
		    	mysql_format(Database, DB_Query, sizeof(DB_Query), "INSERT INTO `users` (`Username`, `Password`, `Score`, `Kills`, `Cash`, `Deaths`)\
		    	VALUES ('%e', '%s','0', '0', '0', '0')", PI[playerid][Name], PI[playerid][Password]);
		    	mysql_tquery(Database, DB_Query);
		    	SetSpawnInfo(playerid, 0, 26, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0);
		    	SpawnPlayer(playerid);
		    	SetPlayerScore(playerid, PI[playerid][Score]);
		    	GivePlayerMoney(playerid, PI[playerid][Cash]);
			}
		}
		case d_log: {
			if(strlen(inputtext) < 6 || strlen(inputtext) > 24) {
				SendClientMessage(playerid, -1, "La contraseña no puede ir por debajo de 6 y más de 24 caracteres");
				ShowPlayerDialog(playerid, d_reg, DIALOG_STYLE_PASSWORD, "Registro del servidor","Ingrese su contraseña para registrarse en el servidor","Registro","Abandonar");
				return (false);
			}
			else {
				new DB_Query[120], accpass[65];
				SHA256_PassHash(accpass, GetName(playerid), PI[playerid][Password], sizeof(accpass));
				if(strcmp(accpass, PI[playerid][Password]) != 0) {
					PogresnaLozinka[playerid]++;
					if(PogresnaLozinka[playerid] == 3) {
						Kick(playerid);
					}
					else {
						SendClientMessage(playerid, -1, "Esta contraseña no está asociada con esta cuenta");
						ShowPlayerDialog(playerid, d_log, DIALOG_STYLE_PASSWORD, "Iniciar sesión en el servidor","Ingrese su contraseña para registrarse en un servidor","Acceso","Abandonar");
						return (false);
					}
			    }
			    mysql_format(Database, DB_Query, sizeof(DB_Query),"SELECT * FROM `users` WHERE `Username` = '%e' LIMIT 1", PI[playerid][Name]);
		    	mysql_tquery(Database, DB_Query, "LoadAcc", "i", playerid);
		    	//++
		    	SetPlayerScore(playerid, PI[playerid][Score]);
		    	GivePlayerMoney(playerid, PI[playerid][Cash]);
		    	SetSpawnInfo(playerid, 0,26,1328.1277,-1558.4608,13.5469, 139.9262, 0,0,0,0,0,0);
				SpawnPlayer(playerid);
			}
		}
	}
	return (true);
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	new idx;
	new cmd[256];

	cmd = strtok(cmdtext, idx);

	if(strcmp(cmd, "/yadayada", true) == 0) {
    	return 1;
	}

	return 0;
}

public OnPlayerSpawn(playerid)
{
	SetPlayerInterior(playerid,0);
	TogglePlayerClock(playerid,0);
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	PI[killerid][Kills]++;
	PI[playerid][Deaths]++;
	SavePlayer(killerid); SavePlayer(playerid);
	return (true);
}
public OnPlayerDisconnect(playerid, reason) {
	SavePlayer(playerid);
	return (true);
}
SetupPlayerForClassSelection(playerid)
{
 	SetPlayerInterior(playerid,14);
	SetPlayerPos(playerid,258.4893,-41.4008,1002.0234);
	SetPlayerFacingAngle(playerid, 270.0);
	SetPlayerCameraPos(playerid,256.0815,-43.0475,1004.0234);
	SetPlayerCameraLookAt(playerid,258.4893,-41.4008,1002.0234);
}

public OnPlayerRequestClass(playerid, classid)
{
	SetupPlayerForClassSelection(playerid);
	return 1;
}

public OnGameModeInit()
{
	SetGameModeText("Bare Script");
	ShowPlayerMarkers(1);
	ShowNameTags(1);
	AllowAdminTeleport(1);

	AddPlayerClass(265,1958.3783,1343.1572,15.3746,270.1425,0,0,0,0,-1,-1);

	Database = mysql_connect(mysql_host, mysql_user, mysql_pass, mysql_database);
	if(Database == MYSQL_INVALID_HANDLE || mysql_errno(Database) != 0) {
		print("Conexión a la base de datos MySQL falló");
		SendRconCommand("exit");
		return (false);
	}
	return (true);
//	return 1;
}

public OnGameModeExit() {
	foreach(new a: Player) {
		SavePlayer(a);
	}
	mysql_close(Database);
	return (true);
}

strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

forward OnPlayerDataCheck(playerid);
public OnPlayerDataCheck(playerid) {
	new rows;
	cache_get_row_count(rows);
	if(rows > 0) {
		cache_get_value(0, "Password", PI[playerid][Password], 65);
		ShowPlayerDialog(playerid, d_log, DIALOG_STYLE_PASSWORD, "Iniciar sesión en el servidor","Ingrese su contraseña para registrarse en un servidor","Acceso","Abandonar");
	}
	else {
		ShowPlayerDialog(playerid, d_reg, DIALOG_STYLE_PASSWORD, "Registro del servidor","Ingrese su contraseña para registrarse en el servidor","Registro","Abandonar");
	}
	return (true);
}

forward LoadAcc(playerid);
public LoadAcc(playerid){
	new rows;
	cache_get_row_count(rows);
	if(!rows) return (false);
	else {
		cache_get_value_int(0, "ID", PI[playerid][ID]);
		cache_get_value_int(0, "Kills", PI[playerid][Kills]);
		cache_get_value_int(0, "Deaths", PI[playerid][Deaths]);
		cache_get_value_int(0, "Score", PI[playerid][Score]);
		cache_get_value_int(0, "Cash", PI[playerid][Cash]);
	}
	return(true);
}

stock SavePlayer(playerid) {
	new DB_Query[256];
	mysql_format(Database, DB_Query, sizeof(DB_Query), "UPDATE `users` SET `Score` = %d, `Cash` = %d, `Kills` = %d, `Deaths` = %d WHERE `ID` = %d LIMIT 1",
	PI[playerid][Score], PI[playerid][Cash], PI[playerid][Kills], PI[playerid][Deaths], PI[playerid][ID]);
	mysql_tquery(Database, DB_Query);
	return (true);
}

stock GetName(playerid) {
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	return name;
}
