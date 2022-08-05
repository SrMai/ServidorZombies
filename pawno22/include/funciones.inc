/*
		==== [Funciones por Sergio_Team] =======

	Lista de Funciones:


	native EncenderMotor(vehicleid);
	native CambiarEstadoMotor(vehicleid,estado);
	native ObtenerEstadoMotor(vehicleid);
	native ReiniciarVariables();
*/

#define MAXIMOS_JUGADORES (500)
#define MAXIMOS_VEHICULOS (2000)


#define ESTADO_APAGADO 0
#define ESTADO_ENCENDIDO 1
#define ESTADO_ROTO 2


new EstadoVehiculo[MAXIMOS_VEHICULOS];


stock ReiniciarVariables()
{
	for(new l=0; l<=MAXIMOS_VEHICULOS;l++)
	{
		EstadoVehiculo[l] = ESTADO_APAGADO;
	}
}


stock EncenderMotor(vehicleid)
{
	EstadoVehiculo[vehicleid] = ESTADO_ENCENDIDO;
}

stock RomperMotor(vehicleid)
{
    EstadoVehiculo[vehicleid] = ESTADO_ROTO;
    for(new o=0; o<=MAXIMOS_JUGADORES; o++)
    {
        if(GetPlayerVehicleID(o) == vehicleid)
        {
            SendClientMessage(playerid, 0xF5DEB3AA,"Se te rompio el motor");
        }
    }
}

stock CambiarEstadoMotor(vehicleid, estado)
{
	if(estado == 0 || estado == 1 || estado == 2)
	{
		EstadoVehiculo[vehicleid] = estado;
	}
}

stock ObtenerEstadoMotor(vehicleid)
{
	return EstadoVehiculo[vehicleid];
}
