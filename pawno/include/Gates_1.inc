/*  [SP]Oxides's Gates .INC
 *
 *  (c) Copyright 2008, [SP]Oxide
 *
 */

#if defined _objects_included
	#endinput
#endif
#define _objects_included
#pragma library objects

// Gate [ 2 A:51 Gates ] [ ID's: 1 & 2 ]

 CreateObject(2929,211.849777,1875.585938,13.938993,0.0,0.0,0.0);
 CreateObject(2929,215.910263,1875.575317,13.938992,0.0,0.0,0.0); 

// Commands
 }
 if(strcmp(cmdtext, "/Open", true) == 0)
 {
 MoveObject(1,207.739532,1875.735474,13.938993,1.0);
 MoveObject(2,219.979919,1875.749756,13.938992,1.0);
 return 1;
 }
   
  if(strcmp(cmdtext, "/Close", true) == 0)
  {
  MoveObject(1,211.849777,1875.585938,13.938993,0.5); //
  MoveObject(2,215.910263,1875.575317,13.938992,0.5); //
  return 1;
  }


// Functions Used
/*
 *  CreateObject(OBJECT_ID, X, Y, Z, RX, RY, RZ);
 *  MoveObject(OBJECT_ID, X, Y, Z, SPEED);
 */

//EOF
