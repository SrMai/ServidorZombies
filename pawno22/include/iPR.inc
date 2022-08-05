/*==================[By irinel1996(Enrique_Navarro)]=======================*/
/*==================[By irinel1996(Enrique_Navarro)]=======================*/

//--------------[Prohibido TOTALMENTE el robo de Creditos]-------------------------//

//=====================[Includes]===================================//
#include <a_samp>
//=====================[Defines]====================================//
#define PINCHAR_MAX 185 //[Máximo de PinchaRuedas credos simultaneamente, puedes modificarlo como quieras.]
//=====================[NewS]=======================================//
enum pRuedas
{
	prCreado,
    Float:X,
    Float:Y,
    Float:Z,
    prObjeto,
};
new PinchaRuedas[PINCHAR_MAX][pRuedas];

//=====================[PublicS]====================================//
public OnPlayerUpdate(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;

    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        for(new i = 0; i < sizeof(PinchaRuedas); i++)
  	    {
  	        if(IsPlayerInRangeOfPoint(playerid, 3.0, PinchaRuedas[i][X], PinchaRuedas[i][Y], PinchaRuedas[i][Z]))
            {
  	            if(PinchaRuedas[i][prCreado] == 1)
  	            {
  	                new paneles, puertas, luces, neumaticos;
  	                new vehicleid = GetPlayerVehicleID(playerid);
		            GetVehicleDamageStatus(vehicleid, paneles, puertas, luces, neumaticos);
		            neumaticos = codificar_neumaticos(1, 1, 1, 1);
		            UpdateVehicleDamageStatus(vehicleid, paneles, puertas, luces, neumaticos);
  	                return 0;
  	            }
  	        }
  	    }
  	}

	return 1;
}

//=====================[Funciones]====================================//
stock CrearPR(Float:x,Float:y,Float:z,Float:Angulo)
{
    for(new i = 0; i < sizeof(PinchaRuedas); i++)
  	{
  	    if(PinchaRuedas[i][prCreado] == 0)
  	    {
            PinchaRuedas[i][prCreado]=1;
            PinchaRuedas[i][X]=x;
            PinchaRuedas[i][Y]=y;
            PinchaRuedas[i][Z]=z-0.7;
            PinchaRuedas[i][prObjeto] = CreateObject(2899, x, y, z-0.9, 0, 0, Angulo-90);
	        return 1;
  	    }
  	}
  	return 0;
}

stock BTPR()
{
    for(new i = 0; i < sizeof(PinchaRuedas); i++)
  	{
  	    if(PinchaRuedas[i][prCreado] == 1)
  	    {
  	        PinchaRuedas[i][prCreado]=0;
            PinchaRuedas[i][X]=0.0;
            PinchaRuedas[i][Y]=0.0;
            PinchaRuedas[i][Z]=0.0;
            DestroyObject(PinchaRuedas[i][prObjeto]);
  	    }
	}
    return 0;
}

stock BUPRC(playerid)
{
    for(new i = 0; i < sizeof(PinchaRuedas); i++)
  	{
  	    if(IsPlayerInRangeOfPoint(playerid, 2.0, PinchaRuedas[i][X], PinchaRuedas[i][Y], PinchaRuedas[i][Z]))
        {
  	        if(PinchaRuedas[i][prCreado] == 1)
            {
                PinchaRuedas[i][prCreado]=0;
                PinchaRuedas[i][X]=0.0;
                PinchaRuedas[i][Y]=0.0;
                PinchaRuedas[i][Z]=0.0;
                DestroyObject(PinchaRuedas[i][prObjeto]);
                return 1;
  	        }
  	    }
  	}
    return 0;
}

codificar_neumaticos(neumaticos1, neumaticos2, neumaticos3, neumaticos4) {

	return neumaticos1 | (neumaticos2 << 1) | (neumaticos3 << 2) | (neumaticos4 << 3);

}
/*==================[By irinel1996(Enrique_Navarro)]=======================*/
/*==================[By irinel1996(Enrique_Navarro)]=======================*/
