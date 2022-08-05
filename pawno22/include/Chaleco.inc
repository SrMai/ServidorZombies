// Creado por GROVE4L
// www.pawnoscripting.com

#include <a_samp>

new ConM[MAX_PLAYERS];

stock CrearMaletinTodos()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        CrearMaletinEx(i);
	}
	return 1;
}

stock BorrarMaletinTodos()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        BorrarMaletinEx(i);
	}
	return 1;
}

stock BorrarMaletinEx(playerid)
{
    ConM[playerid] = 0;
	StopPlayerHoldingObject(playerid);
	return 1;
}

stock CrearMaletinEx(playerid)
{
    ConM[playerid] = 1;
    SetPlayerHoldingObject( playerid, 356, 1, 0.000000, -0.136615, -0.126834, 0.000000, 31.375703, 359.502288 );
	return 1;
}

stock TieneMaletin(playerid)
{
	return ConM[playerid];
}

// Creado por GROVE4L
