#include <a_samp>
#include <YSI_Data\y_iterate>
#include <a_mysql>

#define mysql_host 	"localhost"
#define mysql_user 	"root"
#define mysql_pass 	""
#define mysql_database 	"test_database"

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

main() {
	print("Mod je uspjesno ucitan");
}

public OnGameModeInit() {
	Database = mysql_connect(mysql_host, mysql_user, mysql_pass, mysql_database);
	if(Database == MYSQL_INVALID_HANDLE || mysql_errno(Database) != 0) {
		print("Connecting to MySQL database failed");
		SendRconCommand("exit");
		return (false);
	}
	return (true);
}

public OnGameModeExit() {
	foreach(new a: Player) {
		SavePlayer(a);
	}
	mysql_close(Database);
	return (true);
}

public OnPlayerConnect(playerid) {
	new DB_Query[115];
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
				SendClientMessage(playerid, -1, "Lozinka ne moze ici ispod 6 i iznad 24 karaktera");
				ShowPlayerDialog(playerid, d_reg, DIALOG_STYLE_PASSWORD, "Registracija na server","Molimo vas unesite vasu lozinku kako bi ste se registrirali na server","Register","Quit");
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
				SendClientMessage(playerid, -1, "Lozinka ne moze ici ispod 6 i iznad 24 karaktera");
				ShowPlayerDialog(playerid, d_reg, DIALOG_STYLE_PASSWORD, "Registracija na server","Molimo vas unesite vasu lozinku kako bi ste se registrirali na server","Register","Quit");
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
						SendClientMessage(playerid, -1, "Ta lozinka nije povezana sa tim racunom");
						ShowPlayerDialog(playerid, d_log, DIALOG_STYLE_PASSWORD, "Prijava na server","Molimo vas unesite vasu lozinku kako bi ste se prijavili na server","Login","Quit");
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

public OnPlayerDeath(playerid, killerid, reason) {
	PI[killerid][Kills]++;
	PI[playerid][Deaths]++;
	SavePlayer(killerid); SavePlayer(playerid);
	return (true);
}

public OnPlayerDisconnect(playerid, reason) {
	SavePlayer(playerid);
	return (true);
}

forward OnPlayerDataCheck(playerid);
public OnPlayerDataCheck(playerid) {
	new rows;
	cache_get_row_count(rows);
	if(rows > 0) {
		cache_get_value(0, "Password", PI[playerid][Password], 65);
		ShowPlayerDialog(playerid, d_log, DIALOG_STYLE_PASSWORD, "Prijava na server","Molimo vas unesite vasu lozinku kako bi ste se prijavili na server","Login","Quit");	
	}
	else {
		ShowPlayerDialog(playerid, d_reg, DIALOG_STYLE_PASSWORD, "Registracija na server","Molimo vas unesite vasu lozinku kako bi ste se registrirali na server","Register","Quit");	
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