//
// Created:     10.09.06
// Aurthor:    Iain Gilbert
//


#if defined _vehicles_included
  #endinput
#endif

#define _vehicles_included
#pragma library vehicles
#include "base"
#include "player"

#define MAX_VEHICLE_MODELS 44
#define MAX_VEHICLE_SPAWNS 244

#define V_ADMIRAL 445
#define V_ALPHA 602
#define V_AMBULAN 416
#define V_ANDROM 592            // air
#define V_ARTICT1 435
#define V_ARTICT2 450
#define V_ARTICT3 591
#define V_AT400 577             // air
#define V_BAGBOXA 606
#define V_BAGBOXB 607
#define V_BAGGAGE 485
#define V_BANDITO 568
#define V_BANSHEE 429
#define V_BARRACKS 433
#define V_BEAGLE 511            // air
#define V_BENSON 499
#define V_BF400 581             // bike
#define V_BFINJECT 424
#define V_BIKE 509              // bike
#define V_BLADE 536
#define V_BLISTAC 496
#define V_BLOODRA 504
#define V_BMX 481               // bike
#define V_BOBCAT 422
#define V_BOXBURG 609
#define V_BOXVILLE 498
#define V_BRAVURA 401
#define V_BROADWAY 575
#define V_BUCCANEE 518
#define V_BUFFALO 402
#define V_BULLET 541
#define V_BURRITO 482
#define V_BUS 431
#define V_CABBIE 438
#define V_CADDY 457
#define V_CADRONA 527
#define V_CAMPER 483
#define V_CARGOBOB 548          // air
#define V_CEMENT 524
#define V_CHEETAH 415
#define V_CLOVER 542
#define V_CLUB 589
#define V_COACH 437
#define V_COASTG 472            // water
#define V_COMBINE 532
#define V_COMET 480
#define V_COPBIKE 523           // bike
#define V_COPCARLA 596
#define V_COPCARRU 599
#define V_COPCARSF 597
#define V_COPCARVG 598
#define V_CROPDUST 512          // air
#define V_DFT30 578
#define V_DINGHY 473            // water
#define V_DODO 593              // air
#define V_DOZER 486
#define V_DUMPER 406
#define V_DUNERIDE 573
#define V_ELEGANT 507
#define V_ELEGY 562
#define V_EMPEROR 585
#define V_ENFORCER 427
#define V_ESPERANT 419
#define V_EUROS 587
#define V_FAGGIO 462
#define V_FARMTR1 610
#define V_FBIRANCH 490
#define V_FBITRUCK 528
#define V_FCR900 521            // bike
#define V_FELTZER 533
#define V_FIRELA 544
#define V_FIRETRUK 407
#define V_FLASH 565
#define V_FLATBED 455
#define V_FORKLIFT 530
#define V_FORTUNE 526
#define V_FREEWAY 463           // bike
#define V_FREIBOX 590
#define V_FREIFLAT 569
#define V_FREIGHT 537
#define V_GLENDALE 466
#define V_GLENSHIT 604
#define V_GREENWOO 492
#define V_HERMES 474
#define V_HOTDOG 588
#define V_HOTKNIFE 434
#define V_HOTRINA 502
#define V_HOTRINB 503
#define V_HOTRING 494
#define V_HUNTER 425            // air
#define V_HUNTLEY 579
#define V_HUSTLER 545
#define V_HYDRA 520             // air
#define V_INFERNUS 411
#define V_INTRUDER 546
#define V_JESTER 559
#define V_JETMAX 493            // water
#define V_JOURNEY 508
#define V_KART 571
#define V_LANDSTAL 400
#define V_LAUNCH 595            // water
#define V_LEVIATHN 417          // air
#define V_LINERUN 403
#define V_MAJESTIC 517
#define V_MANANA 410
#define V_MARQUIS 484           // water
#define V_MAVERICK 487          // air
#define V_MERIT 551
#define V_MESA 500
#define V_MONSTER 444
#define V_MONSTERA 556
#define V_MONSTERB 557
#define V_MOONBEAM 418
#define V_MOWER 572
#define V_MRWHOOP 423
#define V_MTBIKE 510            // bike
#define V_MULE 414
#define V_NEBULA 516
#define V_NEVADA 553            // air
#define V_NEWSVAN 582
#define V_NRG500 522            // bike
#define V_OCEANIC 467
#define V_PACKER 443
#define V_PATRIOT 470
#define V_PCJ600 461            // bike
#define V_PEREN 404
#define V_PETRO 514
#define V_PETROTR 584
#define V_PHOENIX 603
#define V_PICADOR 600
#define V_PIZZABOY 448
#define V_POLMAV 497            // air
#define V_PONY 413
#define V_PREDATOR 430          // water
#define V_PREMIER 426
#define V_PREVION 436
#define V_PRIMO 547
#define V_QUAD 471              // bike
#define V_RAINDANC 563          // air
#define V_RANCHER 489
#define V_RCBANDIT 441
#define V_RCBARON 464           // air
#define V_RCCAM 594
#define V_RCGOBLIN 501          // air
#define V_RCRAIDER 465          // air
#define V_RCTIGER 564
#define V_RDTRAIN 515
#define V_REEFER 453            // water
#define V_REGINA 479
#define V_REMINGTN 534
#define V_RHINO 432
#define V_RNCHLURE 505
#define V_ROMERO 442
#define V_RUMPO 440
#define V_RUSTLER 476           // air
#define V_SABRE 475
#define V_SADLER 543
#define V_SADLSHIT 605
#define V_SANCHEZ 468           // bike
#define V_SANDKING 495
#define V_SAVANNA 567
#define V_SEASPAR 447           // air
#define V_SECURICA 428
#define V_SENTINEL 405
#define V_SHAMAL 519            // air
#define V_SKIMMER 460           // air
#define V_SLAMVAN 535
#define V_SOLAIR 458
#define V_SPARROW 469           // air
#define V_SPEEDER 452           // water
#define V_SQUALO 446            // water
#define V_STAFFORD 580
#define V_STALLION 439
#define V_STRATUM 561
#define V_STREAK 538
#define V_STREAKC 570
#define V_STRETCH 409
#define V_STUNT 513             // air
#define V_SULTAN 560
#define V_SUNRISE 550
#define V_SUPERGT 506
#define V_SWATVAN 601
#define V_SWEEPER 574
#define V_TAHOMA 566
#define V_TAMPA 549
#define V_TAXI 420
#define V_TOPFUN 459
#define V_TORNADO 576
#define V_TOWTRUCK 525
#define V_TRACTOR 531
#define V_TRAM 449
#define V_TRASH 408
#define V_TROPIC 454
#define V_TUG 583
#define V_TUGSTAIR 608
#define V_TURISMO 451
#define V_URANUS 558
#define V_UTILITY 552
#define V_UTILTR1 611
#define V_VCNMAV 488            // air
#define V_VINCENT 540
#define V_VIRGO 491
#define V_VOODOO 412
#define V_VORTEX 539            // hovercraft
#define V_WALTON 478
#define V_WASHING 421
#define V_WAYFARER 586          // bike
#define V_WILLARD 529
#define V_WINDSOR 555
#define V_YANKEE 456
#define V_YOSEMITE 554
#define V_ZR350 477


enum VehicleInfo {
	vehicle_model,
    vehicle_name[MAX_NAME],
    vehicle_nameid[MAX_NAME],
    vehicle_speed,
    vehicle_level,
    vehicle_cost
}
#define VEHICLES_SIZE 212
#define VEHICLES_START 400
new Vehicles[VEHICLES_SIZE][VehicleInfo] = {
{509,	"Bike",		"bike",		120,	1,	0},
{510,	"MountainBike",		"mtbike",		140,	1,	0},
{492,	"Greenwood",		"greenwoo",		160,	1,	10000},
{410,	"Manana",		"manana",		160,	1,	10000},
{481,	"BMX",		"bmx",		120,	1,	0},
{482,	"Burrito",		"burrito",		150,	1,	10000},
{439,	"Stallion",		"stallion",		160,	1,	10000},
{413,	"Pony",		"pony",		160,	1,	20000},
{419,	"Esperanto",		"esperant",		160,	1,	10000},
{475,	"Sabre",		"sabre",		160,	2,	20000},
{505,	"Rancher",		"rnchlure",		170,	2,	20000},
{420,	"Taxi",		"taxi",		180,	2,	20000},
{412,	"Voodoo",		"voodoo",		160,	2,	20000},
{468,	"Sanchez",		"sanchez",		190,	4,	40000},
{489,	"Rancher",		"rancher",		170,	4,	40000},
{405,	"Sentinel",		"sentinel",		165,	5,	50000},
{400,	"Landstalker",		"landstal",		160,	5,	50000},
{440,	"Rumpo",		"rumpo",		160,	5,	50000},
{436,	"Previon",		"previon",		160,	6,	60000},
{496,	"BlistaCompact",		"blistac",		200,	6,	60000},
{422,	"Bobcat",		"bobcat",		165,	6,	60000},
{416,	"Ambulance",		"ambulan",		155,	7,	70000},
{461,	"PCJ-600",		"pcj600",		190,	7,	70000},
{477,	"ZR350",		"zr350",		200,	7,	70000},
{500,	"Mesa",		"mesa",		160,	8,	80000},
{424,	"BFInjection",		"bfinject",		170,	8,	80000},
{402,	"Buffalo",		"buffalo",		200,	9,	90000},
{411,	"Infernus",		"infernus",		240,	9,	90000},
{504,	"BloodringBanger",		"bloodra",		160,	10,	100000},
{478,	"Walton",		"walton",		150,	10,	100000},
{535,	"Slamvan",		"slamvan",		160,	11,	110000},
{463,	"Freeway",		"freeway",		190,	11,	110000},
{494,	"Hotring",		"hotring",		220,	11,	110000},
{506,	"SuperGT",		"supergt",		230,	12,	120000},
{429,	"Banshee",		"banshee",		200,	12,	120000},
{451,	"Turismo",		"turismo",		240,	13,	130000},
{495,	"Sandking",		"sandking",		170,	13,	130000},
{415,	"Cheetah",		"cheetah",		230,	17,	170000},
{470,	"Patriot",		"patriot",		170,	19,	190000},

{401,	"Bravura",		"bravura",		160,	0,	0},
{403,	"Linerunner",		"linerun",		120,	0,	0},
{404,	"Pereniel",		"peren",		150,	0,	0},
{406,	"Dumper",		"dumper",		110,	0,	0},
{407,	"Firetruck",		"firetruk",		170,	0,	0},
{408,	"Trashmaster",		"trash",		110,	0,	0},
{409,	"Stretch",		"stretch",		180,	0,	0},
{414,	"Mule",		"mule",		140,	0,	0},
{417,	"Leviathan",		"leviathn",		200,	0,	0},
{418,	"Moonbeam",		"moonbeam",		150,	0,	0},
{421,	"Washington",		"washing",		180,	0,	0},
{423,	"MrWhoopee",		"mrwhoop",		145,	0,	0},
{425,	"Hunter",		"hunter",		200,	0,	0},
{426,	"Premier",		"premier",		200,	0,	0},
{427,	"Enforcer",		"enforcer",		170,	0,	0},
{428,	"Securicar",		"securica",		170,	0,	0},
{430,	"Predator",		"predator",		190,	0,	0},
{431,	"Bus",		"bus",		130,	0,	0},
{432,	"Rhino",		"rhino",		80,	0,	0},
{433,	"Barracks",		"barracks",		180,	0,	0},
{434,	"Hotknife",		"hotknife",		200,	0,	0},
{435,	"Trailer",		"artict1",		120,	0,	0},
{437,	"Coach",		"coach",		160,	0,	0},
{438,	"Cabbie",		"cabbie",		160,	0,	0},
{441,	"RCBandit",		"rcbandit",		75,	0,	0},
{442,	"Romero",		"romero",		150,	0,	0},
{443,	"Packer",		"packer",		150,	0,	0},
{444,	"Monster",		"monster",		110,	0,	0},
{445,	"Admiral",		"admiral",		165,	0,	0},
{446,	"Squalo",		"squalo",		280,	0,	0},
{447,	"Seasparrow",		"seaspar",		200,	0,	0},
{448,	"Pizzaboy",		"pizzaboy",		190,	0,	0},
{449,	"Tram",		"tram",		150,	0,	0},
{450,	"Trailer",		"artict2",		120,	0,	0},
{452,	"Speeder",		"speeder",		190,	0,	0},
{453,	"Reefer",		"reefer",		190,	0,	0},
{454,	"Tropic",		"tropic",		190,	0,	0},
{455,	"Flatbed",		"flatbed",		140,	0,	0},
{456,	"Yankee",		"yankee",		160,	0,	0},
{457,	"Caddy",		"caddy",		160,	0,	0},
{458,	"Solair",		"solair",		165,	0,	0},
{459,	"Berkley'sRCVan",		"topfun",		160,	0,	0},
{460,	"Skimmer",		"skimmer",		200,	0,	0},
{462,	"Faggio",		"faggio",		190,	0,	0},
{464,	"RCBaron",		"rcbaron",		75,	0,	0},
{465,	"RCRaider",		"rcraider",		75,	0,	0},
{466,	"Glendale",		"glendale",		160,	0,	0},
{467,	"Oceanic",		"oceanic",		160,	0,	0},
{469,	"Sparrow",		"sparrow",		200,	0,	0},
{471,	"Quad",		"quad",		160,	0,	0},
{472,	"Coastguard",		"coastg",		190,	0,	0},
{473,	"Dinghy",		"dinghy",		190,	0,	0},
{474,	"Hermes",		"hermes",		160,	0,	0},
{476,	"Rustler",		"rustler",		200,	0,	0},
{479,	"Regina",		"regina",		165,	0,	0},
{480,	"Comet",		"comet",		200,	0,	0},
{483,	"Camper",		"camper",		120,	0,	0},
{484,	"Marquis",		"marquis",		190,	0,	0},
{485,	"Baggage",		"baggage",		160,	0,	0},
{486,	"Dozer",		"dozer",		100,	0,	0},
{487,	"Maverick",		"maverick",		200,	0,	0},
{488,	"NewsChopper",		"vcnmav",		200,	0,	0},
{490,	"FBIRancher",		"fbiranch",		170,	0,	0},
{491,	"Virgo",		"virgo",		160,	0,	0},
{493,	"Jetmax",		"jetmax",		190,	0,	0},
{497,	"PoliceMaverick",		"polmav",		200,	0,	0},
{498,	"Boxville",		"boxville",		140,	0,	0},
{499,	"Benson",		"benson",		140,	0,	0},
{501,	"RCGoblin",		"rcgoblin",		75,	0,	0},
{502,	"HotringRacer",		"hotrina",		220,	0,	0},
{503,	"HotringRacer",		"hotrinb",		220,	0,	0},
{507,	"Elegant",		"elegant",		165,	0,	0},
{508,	"Journey",		"journey",		140,	0,	0},
{511,	"Beagle",		"beagle",		200,	0,	0},
{512,	"Cropdust",		"cropdust",		200,	0,	0},
{513,	"Stunt",		"stunt",		200,	0,	0},
{514,	"Trailer",		"petro",		120,	0,	0},
{515,	"RoadTrain",		"rdtrain",		120,	0,	0},
{516,	"Nebula",		"nebula",		165,	0,	0},
{517,	"Majestic",		"majestic",		165,	0,	0},
{518,	"Buccaneer",		"buccanee",		160,	0,	0},
{519,	"Shamal",		"shamal",		330,	0,	0},
{520,	"Hydra",		"hydra",		330,	0,	0},
{521,	"FCR-900",		"fcr900",		190,	0,	0},
{522,	"NRG-500",		"nrg500",		190,	0,	0},
{523,	"HPV1000",		"copbike",		190,	0,	0},
{524,	"CementTruck",		"cement",		110,	0,	0},
{525,	"TowTruck",		"towtruck",		160,	0,	0},
{526,	"Fortune",		"fortune",		160,	0,	0},
{527,	"Cadrona",		"cadrona",		160,	0,	0},
{528,	"FBITruck",		"fbitruck",		170,	0,	0},
{529,	"Willard",		"willard",		160,	0,	0},
{530,	"Forklift",		"forklift",		60,	0,	0},
{531,	"Tractor",		"tractor",		70,	0,	0},
{532,	"Combine",		"combine",		140,	0,	0},
{533,	"Feltzer",		"feltzer",		200,	0,	0},
{534,	"Remington",		"remingtn",		160,	0,	0},
{536,	"Blade",		"blade",		160,	0,	0},
{537,	"Freight",		"freight",		110,	0,	0},
{538,	"Streak",		"streak",		110,	0,	0},
{539,	"Vortex",		"vortex",		150,	0,	0},
{540,	"Vincent",		"vincent",		160,	0,	0},
{541,	"Bullet",		"bullet",		230,	0,	0},
{542,	"Clover",		"clover",		160,	0,	0},
{543,	"Sadler",		"sadler",		165,	0,	0},
{544,	"Firetruck",		"firela",		170,	0,	0},
{545,	"Hustler",		"hustler",		160,	0,	0},
{546,	"Intruder",		"intruder",		160,	0,	0},
{547,	"Primo",		"primo",		160,	0,	0},
{548,	"Cargobob",		"cargobob",		200,	0,	0},
{549,	"Tampa",		"tampa",		160,	0,	0},
{550,	"Sunrise",		"sunrise",		160,	0,	0},
{551,	"Merit",		"merit",		165,	0,	0},
{552,	"Utility",		"utility",		160,	0,	0},
{553,	"Nevada",		"nevada",		200,	0,	0},
{554,	"Yosemite",		"yosemite",		170,	0,	0},
{555,	"Windsor",		"windsor",		180,	0,	0},
{556,	"Monster",		"monstera",		110,	0,	0},
{557,	"Monster",		"monsterb",		110,	0,	0},
{558,	"Uranus",		"uranus",		200,	0,	0},
{559,	"Jester",		"jester",		200,	0,	0},
{560,	"Sultan",		"sultan",		200,	0,	0},
{561,	"Stratum",		"stratum",		200,	0,	0},
{562,	"Elegy",		"elegy",		200,	0,	0},
{563,	"Raindance",		"raindanc",		200,	0,	0},
{564,	"RCTiger",		"rctiger",		75,	0,	0},
{565,	"Flash",		"flash",		200,	0,	0},
{566,	"Tahoma",		"tahoma",		160,	0,	0},
{567,	"Savanna",		"savanna",		160,	0,	0},
{568,	"Bandito",		"bandito",		170,	0,	0},
{569,	"Freight",		"freiflat",		110,	0,	0},
{570,	"Trailer",		"streakc",		110,	0,	0},
{571,	"Kart",		"kart",		90,	0,	0},
{572,	"Mower",		"mower",		60,	0,	0},
{573,	"Duneride",		"duneride",		110,	0,	0},
{574,	"Sweeper",		"sweeper",		60,	0,	0},
{575,	"Broadway",		"broadway",		160,	0,	0},
{576,	"Tornado",		"tornado",		160,	0,	0},
{577,	"AT-400",		"at400",		200,	0,	0},
{578,	"DFT-30",		"dft30",		110,	0,	0},
{579,	"Huntley",		"huntley",		160,	0,	0},
{580,	"Stafford",		"stafford",		165,	0,	0},
{581,	"BF-400",		"bf400",		190,	0,	0},
{582,	"Newsvan",		"newsvan",		160,	0,	0},
{583,	"Tug",		"tug",		170,	0,	0},
{584,	"Trailer",		"petrotr",		120,	0,	0},
{585,	"Emperor",		"emperor",		165,	0,	0},
{586,	"Wayfarer",		"wayfarer",		190,	0,	0},
{587,	"Euros",		"euros",		200,	0,	0},
{588,	"Hotdog",		"hotdog",		140,	0,	0},
{589,	"Club",		"club",		200,	0,	0},
{590,	"Trailer",		"freibox",		110,	0,	0},
{591,	"Trailer",		"artict3",		120,	0,	0},
{592,	"Andromada",		"androm",		200,	0,	0},
{593,	"Dodo",		"dodo",		200,	0,	0},
{594,	"RCCam",		"rccam",		60,	0,	0},
{595,	"Launch",		"launch",		190,	0,	0},
{596,	"PoliceCar(LSPD)",		"copcarla",		200,	0,	0},
{597,	"PoliceCar(SFPD)",		"copcarsf",		200,	0,	0},
{598,	"PoliceCar(LVPD)",		"copcarvg",		200,	0,	0},
{599,	"PoliceRanger",		"copcarru",		160,	0,	0},
{600,	"Picador",		"picador",		165,	0,	0},
{601,	"S.W.A.T.Van",		"swatvan",		110,	0,	0},
{602,	"Alpha",		"alpha",		200,	0,	0},
{603,	"Phoenix",		"phoenix",		200,	0,	0},
{604,	"Glendale",		"glenshit",		160,	0,	0},
{605,	"Sadler",		"sadlshit",		165,	0,	0},
{606,	"LuggageTrailer",		"bagboxa",		160,	0,	0},
{607,	"LuggageTrailer",		"bagboxb",		160,	0,	0},
{608,	"StairTrailer",		"tugstair",		160,	0,	0},
{609,	"Boxbville",		"boxburg",		140,	0,	0},
{610,	"FarmPlow",		"farmtr1",		160,	0,	0},
{611,	"UtilityTrailer",		"utiltr1",		160,	0,	0}
};


//-------------------------------------------------------------------------------------------
// Vehicle Spawns

enum VehicleSpawnInfo {
	vspawn_model, 			 // Model
	Float:vspawn_x,         // X
	Float:vspawn_y,         // Y
	Float:vspawn_z,         // Z
	Float:vspawn_heading,   // Heading
    vspawn_colour1,         // Colour1
    vspawn_colour2          // Colour2

}

// these vehicles will be spawned first, so if you wish to reserve a vehicle model, add it here
new VehicleModelSpawns[][VehicleSpawnInfo] = {
	{V_BUFFALO,1586.4277,33.1434,23.0000,274.2331,-1,-1}, // race riversiderun car
	{V_PCJ600,1587.8152,25.9319,22.7000,270.2577,-1,-1}, // race riversiderun car
	{V_SABRE,1514.2000,11.2897,23.8677,283.6043,-1,-1}, // race riversiderun car
	{V_BANSHEE,1544.4312,14.6398,23.8626,283.2028,-1,-1}, // race riversiderun car
	{V_BUFFALO,1543.9025,18.2665,23.8678,278.0022,-1,-1}, // race riversiderun car
	{V_YOSEMITE,1423.4043,222.6558,19.2835,334.9312,-1,-1}, // town9
	{V_MONSTER,1446.4843,369.7041,18.6943,72.6925,-1,-1}, // monster
	{V_MONSTER,887.4303,-26.8991,63.2088,3.4624,-1,-1}, // monster2
	{V_BUFFALO,316.6555,-52.1035,1.5781,166.4684,-1,-1}, // town8

	{V_MONSTER,1932.2471,176.7578,37.4273,74.0802,-1,-1}, // monster
	{V_MONSTER,2528.1741,124.7207,26.8566,1.6184,-1,-1}, // monster
	{V_MONSTER,2391.2168,138.7615,26.8471,270.1832,-1,-1}, // monster
	{V_MONSTER,2815.6533,-78.7354,36.2218,3.0263,-1,-1}, // monster
	{V_MONSTER,2129.4233,-358.8318,68.1227,301.2070,-1,-1}, // monster
	{V_MONSTER,2468.5747,-44.8574,26.8557,354.7401,-1,-1}, // monster
	{V_MONSTER,2218.0007,-1166.0787,26.0979,269.7605,-1,-1}, // monsterspawn
	{V_SANCHEZ,322.3486,871.5268,20.7706,126.7716,-1,-1}, // dirtbike
	{V_MONSTER,471.0568,957.5352,5.1397,271.8694,-1,-1}, // monster

	{V_QUAD,2155.2903,-95.7832,3.1043,35.5131,-1,-1}, // quadbike
	{V_SPEEDER,2101.1611,-98.1321,-0.5383,110.4218,-1,-1}, // boat
	{V_BMX,1938.2843,-1362.9536,17.4298,92.1041,-1,-1}, // bycycle
	{V_BMX,1939.8877,-1369.8401,17.7332,92.8441,-1,-1}, // bycycle
	{V_BMX,1941.3163,-1381.0286,17.9802,89.8879,-1,-1}, // bycye
	{V_SANCHEZ,1961.0875,-1389.5693,17.2068,177.9442,-1,-1}, // pcj
	{V_SANCHEZ,1952.9114,-1383.5287,18.3597,192.1973,-1,-1}, // pcj
	{V_SANCHEZ,1970.8129,-1446.1788,13.2970,94.7133,-1,-1}, // dirtbike
	{V_BMX,1889.3635,-1448.5939,13.2699,89.4957,-1,-1}, // bycycle
	{V_RUSTLER,1860.7959,-2623.4519,13.3287,3.9905,-1,-1}, // planespit
	{V_RUSTLER,1798.6801,-2621.8892,13.3284,9.0699,-1,-1}, // plane
	{V_RUSTLER,1718.2184,-2625.3433,13.3286,352.5374,-1,-1}, // plane
	{V_AT400,1482.4989,-2620.6145,13.3287,266.7185,-1,-1}, // bigplane
	{V_RUSTLER,837.2863,-2045.1538,12.5468,2.2953,-1,-1}, // vplane
	{V_MONSTER,-81.9674,-1584.9633,2.2904,47.6283,-1,-1}, // vmonster
	{V_ARTICT1,-53.0237,-1578.8289,2.3452,138.5913,-1,-1}, // vtrailer
	{V_RDTRAIN,-84.4578,-1190.5831,1.4297,74.6822,-1,-1}, // vtruck
	{V_ARTICT1,-52.0264,-1149.1707,0.7578,67.5293,-1,-1}, // vtrailer
	{V_ARTICT1,-49.2942,-1139.7870,0.7578,65.6034,-1,-1}, // vtrailer
	{V_RDTRAIN,-76.5145,-1111.3696,0.7578,157.2079,-1,-1}, // vtruck
	{V_RDTRAIN,-68.3871,-1116.0537,0.7578,166.9989,-1,-1} // vtruck
};


// level based vehicle spawns, vehicle model will be randomly picked from all vehicles <= level
new VehicleLevelSpawns[][VehicleSpawnInfo] = {

	{1,2507.1194,-1672.0026,13.3752,151.7406,-1,-1}, // lvl1car
	{1,2473.1926,-1692.8074,13.5147,185.3466,-1,-1}, // lvl1car
	{1,2443.1753,-1643.4983,13.4635,179.8084,-1,-1}, // lvl1car
	{2,2494.8179,-1656.7545,13.1977,256.9987,-1,-1}, // lvl2Vehic
	{2,2509.4746,-1686.5259,13.3920,45.2052,-1,-1}, //  lvl2car
	{3,2061.8252,-1694.3264,13.5469,268.3677,-1,-1}, // lvl2car
	{3,2114.4954,-1777.3055,13.3908,0.8108,-1,-1}, // lvl2car
	{3,2095.4346,-1816.7876,13.3828,100.7804,-1,-1}, // lvl2car
	{4,2062.9409,-1783.5260,13.5526,170.9329,-1,-1}, // bycycle
	{4,1974.5032,-1577.1281,13.6000,236.0774,-1,-1}, // lvl2car
	{5,1936.1696,-1590.2274,13.5655,0.2501,-1,-1}, // lvl3car
	{5,1664.2101,-1608.9214,13.5469,99.7265,-1,-1}, // lvl3car
	{5,1544.7393,-1490.1561,13.5550,92.3693,-1,-1}, // lv3car
	{5,1530.8647,-1501.9451,13.5547,96.7727,-1,-1}, // lv3car
	{5,1585.7596,-1417.3674,13.5745,274.2409,-1,-1}, // lv3car
	{5,1566.4376,-1309.3285,17.1774,85.9056,-1,-1}, // lv3car
	{5,1763.2955,-1309.9579,13.6379,92.0329,-1,-1}, // lv3car
	{15,1798.8533,-1290.4866,13.4941,269.4398,-1,-1}, // lv15car
	{5,1619.1155,-1515.4388,13.5830,273.3464,-1,-1}, // lv3car
	{6,1968.7969,-1105.2159,25.4998,170.9778,-1,-1}, // lv4car
	{6,2045.7830,-1104.7937,24.4727,306.3415,-1,-1}, // lv4car
	{6,1978.2981,-1222.4176,20.0234,89.0798,-1,-1}, // lv4car
	{6,1852.4985,-1175.3591,23.8281,89.0952,-1,-1}, // lv4car
	{6,1856.6714,-1057.3165,23.9331,6.3496,-1,-1}, // lv4car
	{7,1763.1777,-1035.3685,23.9609,87.8300,-1,-1}, // lv5car
	{7,1695.6656,-1057.3094,23.9063,181.4175,-1,-1}, // lv5car
	{6,1661.5690,-1020.1589,23.8984,15.1686,-1,-1}, // lv4car
	{6,1551.9174,-1026.1078,23.9063,156.1736,-1,-1}, // lv4car
	{7,1332.9067,-1081.6321,25.1267,109.4965,-1,-1}, // lv5car
	{12,1396.2329,-954.4750,34.9181,265.1123,-1,-1}, // lv12car
	{6,1321.1194,-871.6872,39.5781,86.4294,-1,-1}, // lv6car
	{7,1329.8838,-836.3520,55.4324,261.6916,-1,-1}, // lv5car
	{7,1317.5902,-806.1083,78.2761,307.4813,-1,-1}, // lv5car
	{8,1252.2313,-807.8172,84.1406,338.8975,-1,-1}, // lv5car
	{7,1243.3571,-786.0731,90.2281,359.7236,-1,-1}, // lv5car
	{8,2818.1460,-1086.3120,31.1089,180.0379,-1,-1}, // lvl8car
	{5,1499.3032,-1286.6250,14.1323,84.4448,-1,-1}, // newvspawns
	{5,1362.6215,-1552.9481,13.2266,163.1715,-1,-1}, // vlvl5
	{7,1329.1322,-1434.5465,14.6345,178.1093,-1,-1}, // vlvl10
	{5,1167.5800,-1773.5697,13.2500,180.0618,-1,-1}, // vlv5
	{7,973.7094,-1832.7688,12.2906,77.1939,-1,-1}, // v7
	{7,931.7245,-1832.8137,12.2708,77.8647,-1,-1}, // vlvl7
	{7,816.4370,-1750.9691,13.2286,0.1984,-1,-1}, // vlv7
	{10,529.3150,-1722.2203,12.2327,83.2223,-1,-1}, // vlvl10
	{10,440.8567,-1749.0173,8.5379,174.0354,-1,-1}, // lvl10
	{10,473.0768,-1764.6591,5.2079,265.8541,-1,-1}, // vlv10
	{10,297.4179,-1716.7726,6.7378,72.8854,-1,-1}, // vlvl10
	{10,181.7001,-1535.5029,12.5564,332.5497,-1,-1}, // vlvl10
	{12,310.2231,-1688.3392,6.6519,257.4050,-1,-1}, // vlvl14
	{15,383.3008,-2074.1270,7.5156,181.0151,-1,-1}, // vlvl17
	{7,332.7628,-1521.7637,35.5395,323.0349,-1,-1}, // vlvl7
	{7,479.5381,-1497.6285,20.1238,177.7601,-1,-1}, // vlvl7
	{10,784.1212,-1623.2212,13.0664,90.8990,-1,-1}, // vlvl10
	{7,782.1212,-1605.4540,13.0625,82.0705,-1,-1}, // vlvl7
	{7,822.7065,-1493.8962,13.2571,271.1335,-1,-1}, // vlvl7
	{7,951.6801,-1355.8486,13.0234,263.0140,-1,-1}, // vlvl7
	{7,1121.6134,-1414.0759,13.2500,86.2094,-1,-1}, // vlvl7
	{8,1037.1713,-1125.4634,23.5787,0.6568,-1,-1}, // vlvl8
	{10,936.5328,-1121.8204,23.6882,184.5944,-1,-1}, // vlvl10
	{10,925.0693,-1121.4336,23.6964,178.5319,-1,-1}, // vlvl10
	{14,1006.1591,-932.9962,41.8594,274.9768,-1,-1}, // vlvl6
	{9,1054.6265,-881.6620,42.8737,11.2677,-1,-1}, // vlvl7
	{9,877.1146,-942.2459,41.2863,94.1803,-1,-1}, // vlvl7
	{8,831.8075,-858.0800,69.6046,17.5861,-1,-1}, // vlvl8
	{10,920.8649,-789.0234,114.0388,73.0905,-1,-1}, // vlvl10
	{8,838.0268,-756.6203,84.9675,41.8700,-1,-1}, // vlvl8
	{7,1060.0052,-1133.6038,23.6101,83.1905,-1,-1}, // lvvl7
	{5,1348.7952,-1439.1946,13.3288,172.8042,-1,-1}, // lvl5
	{5,1369.2942,-1889.2828,13.2979,183.5186,-1,-1}, // lvl5
	{7,1664.9742,-1891.6210,13.3287,181.3913,-1,-1}, // lvl7
	{5,1840.4922,-1863.5056,13.1679,265.1946,-1,-1}, // lvl5
	{5,1946.6034,-2108.5884,13.3300,84.1386,-1,-1}, // lvl5
	{5,1660.7640,-2448.4036,13.3365,264.7374,-1,-1}, // lvl5
	{17,1792.3103,-2408.3279,13.3365,352.9836,-1,-1}, // lvl20
	{5,2240.7935,-2133.2385,13.3286,311.9443,-1,-1}, // lvl5
	{5,2239.8882,-2018.3472,13.3287,64.6645,-1,-1}, // lvl5
	{5,2236.9026,-1739.3690,13.3293,271.7934,-1,-1}, // lvl5
	{7,2293.9290,-1744.4738,13.3287,270.3853,-1,-1}, // lvl5
	{7,2378.5596,-1890.8003,13.1678,93.1584,-1,-1}, // lvl5
	{5,2380.3411,-1926.8801,13.1647,0.7137,-1,-1}, // lvl5
	{5,2451.4756,-2024.0084,13.3287,355.1544,-1,-1}, // lvl5
	{5,2647.5940,-1850.2285,10.7891,207.1185,-1,-1}, // lvl5
	{11,2748.6089,-1944.3165,13.3286,89.3919,-1,-1}, // lvl11
	{5,2770.1711,-2031.3397,13.3420,94.5972,-1,-1}, // lvl5
	{15,2935.4053,-2051.1785,3.3296,90.9356,-1,-1}, // lvl15
	{5,2867.7668,-1747.9935,10.8271,358.2124,-1,-1}, // lvl5
	{9,2815.7358,-1540.8802,10.7036,3.1425,-1,-1}, // lvl5
	{9,2803.7961,-1542.1204,10.7062,182.6557,-1,-1}, // lvl5
	{5,2922.9241,-1258.0260,10.6473,9.0239,-1,-1}, // lvl5
	{9,2604.3477,-1144.9692,49.9987,93.6663,-1,-1}, // lvl9
	{6,2358.8176,-1372.5603,23.7998,167.2767,-1,-1}, // lvl6
	{5,2328.2671,-1525.1691,24.8938,5.5071,-1,-1}, // lvl5
	{8,2305.3328,-1536.7662,25.2533,177.5410,-1,-1}, // lvl8
	{8,1898.3131,-1267.0509,13.3388,268.4135,-1,-1}, // lvl8
	{5,2038.8135,-1221.1144,22.5157,129.4195,-1,-1}, // lvl5
	{8,2173.8013,-997.0818,62.7518,169.9280,-1,-1}, // lvl8
	{9,2457.8013,-959.5031,79.8665,359.3141,-1,-1}, // lvl9
	{8,1499.0817,-709.1434,95.1203,172.0317,-1,-1}, // lvl8
	{8,1285.9681,-618.7437,104.0724,43.4388,-1,-1}, // lvl8
	{7,913.8022,-666.8300,117.4427,235.6000,-1,-1}, // lvl7
	{9,192.8070,-1105.9463,64.3511,332.9678,-1,-1}, // lvl9
	{9,359.3071,-854.7225,11.4603,337.1469,-1,-1}, // lvl9
	{8,663.3029,-619.2434,16.7072,276.6303,-1,-1}, // lvl8
	{8,666.3506,-467.6815,16.7072,92.0845,-1,-1}, // lvl8
	{8,665.8613,-460.7023,16.7073,92.1626,-1,-1}, // lvl8
	{8,734.8677,-589.3069,17.0283,272.2606,-1,-1}, // lvl8
	{8,827.1958,-511.9892,17.1543,180.7998,-1,-1}, // lvl8
	{9,1029.7224,-308.0322,74.3626,180.7265,-1,-1}, // lvl9
	{9,1060.3031,-304.3328,74.3635,175.4635,-1,-1}, // lvl9
	{8,1096.4338,-346.7454,74.3636,5.0826,-1,-1}, // lvl8
	{9,251.7234,-268.0208,1.9519,85.9601,-1,-1}, // lvl9
	{9,314.9438,-195.6568,1.9494,0.7245,-1,-1}, // lvl9
	{9,314.8654,-31.3876,1.9490,98.7475,-1,-1}, // lvl9
	{9,219.1703,25.5450,2.9494,296.3790,-1,-1}, // lvl9
	{10,920.9443,75.0384,62.4291,41.5838,-1,-1}, // lvl10
	{10,753.3507,277.1113,27.7727,198.5655,-1,-1}, // lvl10
	{10,953.1068,191.2826,35.8748,251.9660,-1,-1}, // lvl10
	{10,621.3632,50.6374,1.4212,186.7549,-1,-1}, // lvl10
	{11,755.3005,383.4026,23.5433,281.1725,-1,-1}, // lvl11
	{11,750.5363,348.8127,20.7778,146.0320,-1,-1}, // lvl11
	{11,1021.5203,504.9634,20.6057,336.8246,-1,-1}, // lvl11
	{11,1231.2999,299.8349,19.9596,153.8852,-1,-1}, // lvl11
	{11,1294.4745,217.8103,19.9278,69.5802,-1,-1}, // lvl11
	{11,1289.2206,145.2008,20.8336,172.9028,-1,-1}, // lvl11
	{11,1373.2708,271.9889,19.9383,157.2122,-1,-1}, // lvl11
	{12,1861.3813,-273.6258,38.8418,186.6327,-1,-1}, // lvl12
	{11,2210.8157,112.0458,27.3675,88.5778,-1,-1}, // lvl11
	{12,2292.5669,155.2373,27.4330,183.2780,-1,-1}, // lvl12
	{12,2298.6357,-112.4046,27.1735,5.1040,-1,-1}, // lvl12
	{12,2511.1599,49.4021,26.8557,267.5125,-1,-1} // lvl12
};


// vehicle spawns from lvdm
new VehicleLVDMSpawns[][VehicleSpawnInfo] = {

	{V_TURISMO,2040.0520,1319.2799,10.3779,183.2439,16,16},
	{V_BANSHEE,2040.5247,1359.2783,10.3516,177.1306,13,13},
	{V_WASHING,2110.4102,1398.3672,10.7552,359.5964,13,13},
	{V_INFERNUS,2074.9624,1479.2120,10.3990,359.6861,64,64},
	{V_ZR350,2075.6038,1666.9750,10.4252,359.7507,94,94},
	{V_BULLET,2119.5845,1938.5969,10.2967,181.9064,22,22},
	{V_BULLET,1843.7881,1216.0122,10.4556,270.8793,60,1},
	{V_BUFFALO,1944.1003,1344.7717,8.9411,0.8168,30,30},
	{V_BUFFALO,1679.2278,1316.6287,10.6520,180.4150,90,90},
	{V_CHEETAH,1685.4872,1751.9667,10.5990,268.1183,25,1},
	{V_INFERNUS,2034.5016,1912.5874,11.9048,0.2909,123,1},
	{V_INFERNUS,2172.1682,1988.8643,10.5474,89.9151,116,1},
	{V_BANSHEE,2245.5759,2042.4166,10.5000,270.7350,14,14},
	{V_ZR350,2361.1538,1993.9761,10.4260,178.3929,101,1},
	{V_UTILITY,2221.9946,1998.7787,9.6815,92.6188,53,53},
	{V_URANUS,2243.3833,1952.4221,14.9761,359.4796,116,1},
	{V_EUROS,2276.7085,1938.7263,31.5046,359.2321,40,1},
	{V_EUROS,2602.7769,1853.0667,10.5468,91.4813,43,1},
	{V_PHOENIX,2610.7600,1694.2588,10.6585,89.3303,69,1},
	{V_EUROS,2635.2419,1075.7726,10.5472,89.9571,53,1},
	{V_ELEGY,2577.2354,1038.8063,10.4777,181.7069,35,1},
	{V_ELEGY,2394.1021,989.4888,10.4806,89.5080,17,1},
	{V_ELEGY,1881.0510,957.2120,10.4789,270.4388,11,1},
	{V_SLAMVAN,2039.1257,1545.0879,10.3481,359.6690,123,1},
	{V_SLAMVAN,2009.8782,2411.7524,10.5828,178.9618,66,1},
	{V_BANSHEE,2010.0841,2489.5510,10.5003,268.7720,1,2},
	{V_CHEETAH,2076.4033,2468.7947,10.5923,359.9186,36,1},
	{V_MAVERICK,2093.2754,2414.9421,74.7556,89.0247,26,57},
	{V_SUPERGT,2352.9026,2577.9768,10.5201,0.4091,7,7},
	{V_SUPERGT,2166.6963,2741.0413,10.5245,89.7816,52,52},
	{V_INFERNUS,1960.9989,2754.9072,10.5473,200.4316,112,1},
	{V_BANSHEE,1919.5863,2760.7595,10.5079,100.0753,2,1},
	{V_CHEETAH,1673.8038,2693.8044,10.5912,359.7903,40,1},
	{V_BUFFALO,1591.0482,2746.3982,10.6519,172.5125,30,30},
	{V_PHOENIX,1580.4537,2838.2886,10.6614,181.4573,75,77},
	{V_UTILITY,1555.2734,2750.5261,10.6388,91.7773,62,62},
	{V_SLAMVAN,1455.9305,2878.5288,10.5837,181.0987,118,1},
	{V_ZR350,1537.8425,2578.0525,10.5662,0.0650,121,1},
	{V_TURISMO,1433.1594,2607.3762,10.3781,88.0013,16,16},
	{V_PHOENIX,2223.5898,1288.1464,10.5104,182.0297,18,1},
	{V_URANUS,2451.6707,1207.1179,10.4510,179.8960,24,1},
	{V_UTILITY,2461.7253,1357.9705,10.6389,180.2927,62,62},
	{V_URANUS,2461.8162,1629.2268,10.4496,181.4625,117,1},
	{V_ZR350,2395.7554,1658.9591,10.5740,359.7374,0,1},
	{V_PEREN,1553.3696,1020.2884,10.5532,270.6825,119,50},
	{V_LANDSTAL,1380.8304,1159.1782,10.9128,355.7117,123,1},
	{V_MOONBEAM,1383.4630,1035.0420,10.9131,91.2515,117,227},
	{V_PEREN,1445.4526,974.2831,10.5534,1.6213,109,100},
	{V_LANDSTAL,1704.2365,940.1490,10.9127,91.9048,113,1},
	{V_PEREN,1658.5463,1028.5432,10.5533,359.8419,101,101},
	{V_BF400,1677.6628,1040.1930,10.4136,178.7038,58,1},
	{V_BF400,1383.6959,1042.2114,10.4121,85.7269,66,1},
	{V_BF400,1064.2332,1215.4158,10.4157,177.2942,72,1},
	{V_BF400,1111.4536,1788.3893,10.4158,92.4627,72,1},
	{V_NRG500,953.2818,1806.1392,8.2188,235.0706,3,8},
	{V_NRG500,995.5328,1886.6055,10.5359,90.1048,3,8},
	{V_FCR900,993.7083,2267.4133,11.0315,1.5610,75,13},
	{V_SLAMVAN,1439.5662,1999.9822,10.5843,0.4194,66,1},
	{V_NRG500,1430.2354,1999.0144,10.3896,352.0951,6,25},
	{V_NRG500,2156.3540,2188.6572,10.2414,22.6504,6,25},
	{V_COPCARVG,2277.6846,2477.1096,10.5652,180.1090,0,1},
	{V_COPCARVG,2268.9888,2443.1697,10.5662,181.8062,0,1},
	{V_COPCARVG,2256.2891,2458.5110,10.5680,358.7335,0,1},
	{V_COPCARVG,2251.6921,2477.0205,10.5671,179.5244,0,1},
	{V_COPBIKE,2294.7305,2441.2651,10.3860,9.3764,0,0},
	{V_COPBIKE,2290.7268,2441.3323,10.3944,16.4594,0,0},
	{V_COPBIKE,2295.5503,2455.9656,2.8444,272.6913,0,0},
	{V_NRG500,2476.7900,2532.2222,21.4416,0.5081,8,82},
	{V_NRG500,2580.5320,2267.9595,10.3917,271.2372,8,82},
	{V_NRG500,2814.4331,2364.6641,10.3907,89.6752,36,105},
	{V_SLAMVAN,2827.4143,2345.6953,10.5768,270.0668,97,1},
	{V_FCR900,1670.1089,1297.8322,10.3864,359.4936,87,118},
	{V_MAVERICK,1614.7153,1548.7513,11.2749,347.1516,58,8},
	{V_MAVERICK,1647.7902,1538.9934,11.2433,51.8071,0,8},
	{V_MAVERICK,1608.3851,1630.7268,11.2840,174.5517,58,8},
	{V_RUSTLER,1283.0006,1324.8849,9.5332,275.0468,7,6}, //11.5332
	{V_RUSTLER,1283.5107,1361.3171,9.5382,271.1684,1,6}, //11.5382
	{V_RUSTLER,1283.6847,1386.5137,11.5300,272.1003,89,91},
	{V_RUSTLER,1288.0499,1403.6605,11.5295,243.5028,119,117},
	{V_CHEETAH,1319.1038,1279.1791,10.5931,0.9661,62,1},
	{V_FCR900,1710.5763,1805.9275,10.3911,176.5028,92,3},
	{V_FCR900,2805.1650,2027.0028,10.3920,357.5978,92,3},
	{V_SLAMVAN,2822.3628,2240.3594,10.5812,89.7540,123,1},
	{V_FCR900,2876.8013,2326.8418,10.3914,267.8946,115,118},
	{V_BANSHEE,2842.0554,2637.0105,10.5000,182.2949,1,3},
	{V_TAMPA,2494.4214,2813.9348,10.5172,316.9462,72,39},
	{V_TAMPA,2327.6484,2787.7327,10.5174,179.5639,75,39},
	{V_TAMPA,2142.6970,2806.6758,10.5176,89.8970,79,39},
	{V_FCR900,2139.7012,2799.2114,10.3917,229.6327,25,118},
	{V_FCR900,2104.9446,2658.1331,10.3834,82.2700,36,0},
	{V_FCR900,1914.2322,2148.2590,10.3906,267.7297,36,0},
	{V_TAMPA,1904.7527,2157.4312,10.5175,183.7728,83,36},
	{V_TAMPA,1532.6139,2258.0173,10.5176,359.1516,84,36},
	{V_FCR900,1534.3204,2202.8970,10.3644,4.9108,118,118},
	{V_TAMPA,1613.1553,2200.2664,10.5176,89.6204,89,35},
	{V_LANDSTAL,1552.1292,2341.7854,10.9126,274.0815,101,1},
	{V_PEREN,1637.6285,2329.8774,10.5538,89.6408,101,101},
	{V_LANDSTAL,1357.4165,2259.7158,10.9126,269.5567,62,1},
	{V_INFERNUS,1281.7458,2571.6719,10.5472,270.6128,106,1},
	{V_NRG500,1305.5295,2528.3076,10.3955,88.7249,3,8},
	{V_FCR900,993.9020,2159.4194,10.3905,88.8805,74,74},
	{V_CHEETAH,1512.7134,787.6931,10.5921,359.5796,75,1},
	{V_NRG500,2299.5872,1469.7910,10.3815,258.4984,3,8},
	{V_NRG500,2133.6428,1012.8537,10.3789,87.1290,3,8},
	{V_CHEETAH,2266.7336,648.4756,11.0053,177.8517,0,1}, //
	{V_PCJ600,2404.6636,647.9255,10.7919,183.7688,53,1}, //
	{V_SUPERGT,2628.1047,746.8704,10.5246,352.7574,3,3}, //
	{V_TAMPA,2817.6445,928.3469,10.4470,359.5235,72,39}, //
	{V_ELEGY,1919.8829,947.1886,10.4715,359.4453,11,1}, //
	{V_ELEGY,1881.6346,1006.7653,10.4783,86.9967,11,1}, //
	{V_ELEGY,2038.1044,1006.4022,10.4040,179.2641,11,1}, //
	{V_ELEGY,2038.1614,1014.8566,10.4057,179.8665,11,1}, //
	{V_ELEGY,2038.0966,1026.7987,10.4040,180.6107,11,1}, //
	{V_BOBCAT,9.1065,1165.5066,19.5855,2.1281,101,25}, //
	{V_FREEWAY,19.8059,1163.7103,19.1504,346.3326,11,11}, //
	{V_FREEWAY,12.5740,1232.2848,18.8822,121.8670,22,22}, //
	{V_WAYFARER,69.4633,1217.0189,18.3304,158.9345,10,1}, //
	{V_WAYFARER,-199.4185,1223.0405,19.2624,176.7001,25,1}, //
	{V_RUSTLER,325.4121,2538.5999,17.5184,181.2964,71,77}, //
	{V_RUSTLER,291.0975,2540.0410,17.5276,182.7206,7,6}, //
	{V_TORNADO,384.2365,2602.1763,16.0926,192.4858,72,1}, //
	{V_WAYFARER,423.8012,2541.6870,15.9708,338.2426,10,1}, //
	{V_WAYFARER,-244.0047,2724.5439,62.2077,51.5825,10,1}, //
	{V_WAYFARER,-311.1414,2659.4329,62.4513,310.9601,27,1}, //
	{V_SADLER,596.8064,866.2578,-43.2617,186.8359,67,8}, //
	{V_SADLER,835.0838,836.8370,11.8739,14.8920,8,90}, //
	{V_TAMPA,843.1893,838.8093,12.5177,18.2348,79,39}, //
	{V_LANDSTAL,-235.9767,1045.8623,19.8158,180.0806,75,1}, //
	{V_COPCARRU,-211.5940,998.9857,19.8437,265.4935,0,1}, //
	{V_BOBCAT,-304.0620,1024.1111,19.5714,94.1812,96,25}, //
	{V_HOTDOG,-290.2229,1317.0276,54.1871,81.7529,1,1}, //
	{V_TURISMO,-290.3145,1567.1534,75.0654,133.1694,61,61}, //
	{V_PATRIOT,280.4914,1945.6143,17.6317,310.3278,43,0}, //
	{V_PATRIOT,272.2862,1949.4713,17.6367,285.9714,43,0}, //
	{V_PATRIOT,271.6122,1961.2386,17.6373,251.9081,43,0}, //
	{V_PATRIOT,279.8705,1966.2362,17.6436,228.4709,43,0}, //
	{V_BARRACKS,277.6437,1985.7559,18.0772,270.4079,43,0}, //
	{V_BARRACKS,277.4477,1994.8329,18.0773,267.7378,43,0}, //
	{V_BANDITO,-441.3438,2215.7026,42.2489,191.7953,41,29}, //
	{V_BANDITO,-422.2956,2225.2612,42.2465,0.0616,41,29}, //
	{V_BANDITO,-371.7973,2234.5527,42.3497,285.9481,41,29}, //
	{V_BANDITO,-360.1159,2203.4272,42.3039,113.6446,41,29}, //
	{V_SANCHEZ,-660.7385,2315.2642,138.3866,358.7643,6,6}, //
	{V_SKIMMER,-1029.2648,2237.2217,42.2679,260.5732,1,3}, //
	{V_ESPERANT,95.0568,1056.5530,13.4068,192.1461,13,76}, //
	{V_BANSHEE,114.7416,1048.3517,13.2890,174.9752,1,2}, //
	{V_INFERNUS,-290.0065,1759.4958,42.4154,89.7571,116,1}, //
	{V_NRG500,-302.5649,1777.7349,42.2514,238.5039,6,25}, //
	{V_NRG500,-302.9650,1776.1152,42.2588,239.9874,8,82}, //
	{V_FELTZER,-301.0404,1750.8517,42.3966,268.7585,75,1}, //
	{V_SLAMVAN,-866.1774,1557.2700,23.8319,269.3263,31,1}, //
	{V_UTILITY,-799.3062,1518.1556,26.7488,88.5295,53,53}, //
	{V_FCR900,-749.9730,1589.8435,26.5311,125.6508,92,3}, //
	{V_NRG500,-867.8612,1544.5282,22.5419,296.0923,3,3}, //
	{V_YOSEMITE,-904.2978,1553.8269,25.9229,266.6985,34,30}, //
	{V_FCR900,-944.2642,1424.1603,29.6783,148.5582,92,3}, //
	{V_BANSHEE,-237.7157,2594.8804,62.3828,178.6802,1,2}, //
	{V_FREEWAY,-196.3012,2774.4395,61.4775,303.8402,22,22}, //
	{V_SHAMAL,-1341.1079,-254.3787,15.0701,321.6338,1,1}, //
	{V_SHAMAL,-1371.1775,-232.3967,15.0676,315.6091,1,1}, //
	{V_SHAMAL,1642.9850,-2425.2063,14.4744,159.8745,1,1}, //
	{V_SHAMAL,1734.1311,-2426.7563,14.4734,172.2036,1,1}, //
	{V_CHEETAH,-680.9882,955.4495,11.9032,84.2754,36,1}, //
	{V_SKIMMER,-816.3951,2222.7375,43.0045,268.1861,1,3}, //
	{V_SKIMMER,-94.6885,455.4018,1.5719,250.5473,1,3}, //
	{V_SKIMMER,1624.5901,565.8568,1.7817,200.5292,1,3}, //
	{V_SKIMMER,1639.3567,572.2720,1.5311,206.6160,1,3}, //
	{V_SKIMMER,2293.4219,517.5514,1.7537,270.7889,1,3}, //
	{V_SKIMMER,2354.4690,518.5284,1.7450,270.2214,1,3}, //
	{V_SKIMMER,772.4293,2912.5579,1.0753,69.6706,1,3}, //
	{V_SULTAN,2133.0769,1019.2366,10.5259,90.5265,9,39}, //
	{V_SULTAN,2142.4023,1408.5675,10.5258,0.3660,17,1}, //
	{V_SULTAN,2196.3340,1856.8469,10.5257,179.8070,21,1}, //
	{V_SULTAN,2103.4146,2069.1514,10.5249,270.1451,33,0}, //
	{V_SULTAN,2361.8042,2210.9951,10.3848,178.7366,37,0}, //
	{V_SULTAN,-1993.2465,241.5329,34.8774,310.0117,41,29}, //
	{V_JESTER,-1989.3235,270.1447,34.8321,88.6822,58,8}, //
	{V_JESTER,-1946.2416,273.2482,35.1302,126.4200,60,1}, //
	{V_URANUS,-1956.8257,271.4941,35.0984,71.7499,24,1}, //
	{V_ELEGY,-1952.8894,258.8604,40.7082,51.7172,17,1}, //
	{V_INFERNUS,-1949.8689,266.5759,40.7776,216.4882,112,1}, //
	{V_BANSHEE,-1988.0347,305.4242,34.8553,87.0725,2,1}, //
	{V_JESTER,-1657.6660,1213.6195,6.9062,282.6953,13,8}, //
	{V_SULTAN,-1658.3722,1213.2236,13.3806,37.9052,52,39}, //
	{V_URANUS,-1660.8994,1210.7589,20.7875,317.6098,36,1}, //
	{V_UTILITY,-1645.2401,1303.9883,6.8482,133.6013,7,7}, //
	{V_SKIMMER,-1333.1960,903.7660,1.5568,0.5095,46,32}, //
	{V_INFERNUS,113.8611,1068.6182,13.3395,177.1330,116,1}, //
	{V_BANSHEE,159.5199,1185.1160,14.7324,85.5769,1,2}, //
	{V_INFERNUS,612.4678,1694.4126,6.7192,302.5539,75,1}, //
	{V_NRG500,661.7609,1720.9894,6.5641,19.1231,6,25}, //
	{V_NRG500,660.0554,1719.1187,6.5642,12.7699,8,82}, //
	{V_SAVANNA,711.4207,1947.5208,5.4056,179.3810,90,96}, //
	{V_SAVANNA,1031.8435,1920.3726,11.3369,89.4978,97,96}, //
	{V_SAVANNA,1112.3754,1747.8737,10.6923,270.9278,102,114}, //
	{V_SAVANNA,1641.6802,1299.2113,10.6869,271.4891,97,96}, //
	{V_SAVANNA,2135.8757,1408.4512,10.6867,180.4562,90,96}, //
	{V_SAVANNA,2262.2639,1469.2202,14.9177,91.1919,99,81}, //
	{V_SAVANNA,2461.7380,1345.5385,10.6975,0.9317,114,1}, //
	{V_SAVANNA,2804.4365,1332.5348,10.6283,271.7682,88,64}, //
	{V_SULTAN,2805.1685,1361.4004,10.4548,270.2340,17,1}, //
	{V_SUPERGT,2853.5378,1361.4677,10.5149,269.6648,7,7}, //
	{V_SAVANNA,2633.9832,2205.7061,10.6868,180.0076,93,64}, //
	{V_SAVANNA,2119.9751,2049.3127,10.5423,180.1963,93,64}, //
	{V_SAVANNA,2785.0261,-1835.0374,9.6874,226.9852,93,64}, //
	{V_SAVANNA,2787.8975,-1876.2583,9.6966,0.5804,99,81}, //
	{V_INFERNUS,2771.2993,-1841.5620,9.4870,20.7678,116,1}, //
	{V_TAXI,1713.9319,1467.8354,10.5219,342.8006,6,1} // taxi
};

//--------------------------------------------------------------

new VehicleDB[MAX_STRING] = "GTO\\Vehicle\\";

VehicleLoadAll()
{
    if (ForceOverwrite) return;
	new temp[MAX_STRING];
	if (!dini_Exists(ConfigDB))	dini_Create(ConfigDB);
	set(temp,dini_Get(ConfigDB,"Vehicle_DB"));
	if (strlen(temp) > 0) set(VehicleDB,temp);

	if (!dini_Exists(VehicleDB))
	{
		VehicleSaveAll();
		return;
	}
	for (new i=0;i<VEHICLES_SIZE;i++)
	{
 		new vdbname[MAX_STRING];
 		format(vdbname,sizeof(vdbname),"%sGTO.Vehicle.%s.txt",VehicleDB,Vehicles[i][vehicle_name]);
 		if (!dini_Exists(vdbname))
 		{
 		    continue;
 		}
 		set(temp,dini_Get(vdbname,"Name"));
 		if (strlen(temp) > 0) set(Vehicles[i][vehicle_name],temp);
 		set(temp,nullstr);
 		set(temp,dini_Get(vdbname,"Level"));
 		if (strlen(temp) > 0) Vehicles[i][vehicle_level] = strval(temp);
 		set(temp,nullstr);
 		set(temp,dini_Get(vdbname,"Price"));
 		if (strlen(temp) > 0) Vehicles[i][vehicle_cost] = strval(temp);
 		set(temp,nullstr);
	}
	return;
}

VehicleSaveAll()
{
	new temp[MAX_STRING];
	if (dini_Exists(ConfigDB))
	{
		dini_Set(ConfigDB,"Vehicle_DB",VehicleDB);
 	}
	for (new i=0;i<VEHICLES_SIZE;i++)
	{
		new vdbname[MAX_STRING];
 		format(vdbname,sizeof(vdbname),"%sGTO.Vehicle.%s.txt",VehicleDB,Vehicles[i][vehicle_name]);
		if (!dini_Exists(vdbname)) dini_Create(vdbname);
 		dini_Set(vdbname,"Name",Vehicles[i][vehicle_name]);
		valstr(temp,Vehicles[i][vehicle_level]);
 		dini_Set(vdbname,"Level",temp);
 		set(temp,nullstr);
 		valstr(temp,Vehicles[i][vehicle_cost]);
 		dini_Set(vdbname,"Price",temp);
	}
	return;
}

//----------------------------------------------------------------
new ActiveVehicles[MAX_VEHICLE_SPAWNS];
new ActiveVehiclesCount;

AddVehicleSpawn(Model,Float:X,Float:Y,Float:Z,Float:Heading,Colour1,Colour2)
{
    #if OUTPUTLEVEL > 1
		new string[MAX_STRING];
	#endif
	
	if (ActiveVehiclesCount >= MAX_VEHICLE_SPAWNS)
	{// if we already have 250 vehicles spawned, we can spawn no more, return
		#if OUTPUTLEVEL > 2
     		format(string,sizeof(string),"Warning! Vehicle limit reached. '%s' failed to spawn.",GetVehicleName(Model));
	    	print(string);
		#endif
	    return;
	}
	
	if ((AvtiveVehicleModelCount(Model) == 0) && (ActiveVehicleModelsCount() >= MAX_VEHICLE_MODELS))
	{//if no vehicles of that model are already spawned && over 49 models already used
	// we will change the model to a random one we have already used
		new newmodel;
		new i;
		while ((i<5)&&(AvtiveVehicleModelCount(newmodel) == 0))
		{ // we will find a model we have already used
		    i++;
    		newmodel = GetRndVModelByLevel(20); 
		}
		if (AvtiveVehicleModelCount(newmodel)==0)
		{ // if we still failed to find a useable model, return
			#if OUTPUTLEVEL > 1
     			format(string,sizeof(string),"Error: '%s' failed to load.",GetVehicleName(Model));
	    		print(string);
			#endif
			return;
		}
		#if OUTPUTLEVEL > 2
     		format(string,sizeof(string),"Warning! Vehicle models limit reached. '%s' changed to '%s'.",GetVehicleName(Model),GetVehicleName(newmodel));
	    	print(string);
		#endif
		Model = newmodel;
	}

	ActiveVehicles[ActiveVehiclesCount]=Model;
	ActiveVehiclesCount++;
    AddStaticVehicle(Model,X,Y,Z,Heading,Colour1,Colour2);
    #if OUTPUTLEVEL > 2
    	format(string,sizeof(string),"Vehicle: '%s' added to static vehicles.",GetVehicleName(Model),Model);
		print(string);
	#endif
}

AvtiveVehicleModelCount(model)
{
	if (model < 400) return 0; // less than 400 is an invalid vehicle model
	new modelcount;
    for (new i=0;i<sizeof(ActiveVehicles);i++)
    {
    	if (ActiveVehicles[i] == model) modelcount++;
	}
	return modelcount;
}

ActiveVehicleModelsCount()
{
	new activemodels[VEHICLES_SIZE];
	new count;
	for (new i=0;i<ActiveVehiclesCount;i++)
 	{
 	    new model = ActiveVehicles[i];
 	    if (model < VEHICLES_START) continue;
 	    new luid=model-VEHICLES_START;
 		if (activemodels[luid] == 0)
 		{
			activemodels[luid]++;
			count++;
		}
 	}
 	return count;
}

GetSpawnVehicleModel(vehicleid)
{
	return ActiveVehicles[vehicleid];
}

GetVehicleName(vehiclemodel)
{
	new VehicleName[MAX_STRING];
	for (new vlookupid=0;vlookupid<VEHICLES_SIZE;vlookupid++)
	{
	    new lookupmodel = Vehicles[vlookupid][vehicle_model];
	    if (lookupmodel == vehiclemodel)
	    {
	        set(VehicleName,Vehicles[vlookupid][vehicle_name]);
	        return VehicleName;
	    }
	}
	return VehicleName;
}

GetVehicleSpeed(vehiclemodel)
{
	new vehiclespeed;
	for (new vlookupid=0;vlookupid<VEHICLES_SIZE;vlookupid++)
	{
	    new lookupmodel = Vehicles[vlookupid][vehicle_model];
	    if (lookupmodel == vehiclemodel)
	    {
	        vehiclespeed = Vehicles[vlookupid][vehicle_speed];
	        return vehiclespeed;
	    }
	}
	return vehiclespeed;
}

GetVehicleModelFromName(name[])
{
	for (new vlookupid=0;vlookupid<VEHICLES_SIZE;vlookupid++)
	{
	    if (strcomp(Vehicles[vlookupid][vehicle_name],name,0) == 1)
	    {
	        return Vehicles[vlookupid][vehicle_model];
	    }
	}
	return 0;
}

GetRndVModelByLevel(level)
{
	new leveledvehicles[VEHICLES_SIZE+1];
	new idx=0;
	for (new vlookupid=0;vlookupid<VEHICLES_SIZE;vlookupid++)
	{
		if (Vehicles[vlookupid][vehicle_level] == 0) continue;
	    if (Vehicles[vlookupid][vehicle_level] <= level)
	    {
	    	leveledvehicles[idx] = Vehicles[vlookupid][vehicle_model];
	    	idx++;
	    }
	}
	new rnd = random(idx);
	new vmodel;
	vmodel = leveledvehicles[rnd];
	return vmodel;
}

LoadVehicles()
{
	for (new i=1;i<sizeof(VehicleLevelSpawns);i++)
	{
		if ((VehicleLevelSpawns[i][vspawn_model] >= 0) && (VehicleLevelSpawns[i][vspawn_model] <= 20))
		{
			new vspawnlevel=VehicleLevelSpawns[i][vspawn_model];
		    new vehiclemodel = GetRndVModelByLevel(vspawnlevel);
		    if ((vehiclemodel >= VEHICLES_START) && (vehiclemodel <= (VEHICLES_START+VEHICLES_SIZE)))
		    {
				AddVehicleSpawn(vehiclemodel,VehicleLevelSpawns[i][vspawn_x],VehicleLevelSpawns[i][vspawn_y],VehicleLevelSpawns[i][vspawn_z],VehicleLevelSpawns[i][vspawn_heading],VehicleLevelSpawns[i][vspawn_colour1],VehicleLevelSpawns[i][vspawn_colour2]);
			}
		}
	}
	for (new i=0;i<sizeof(VehicleModelSpawns);i++)
	{
		if (VehicleModelSpawns[i][vspawn_model] != 0)
		{
			AddVehicleSpawn(VehicleModelSpawns[i][vspawn_model],VehicleModelSpawns[i][vspawn_x],VehicleModelSpawns[i][vspawn_y],VehicleModelSpawns[i][vspawn_z],VehicleModelSpawns[i][vspawn_heading],VehicleModelSpawns[i][vspawn_colour1],VehicleModelSpawns[i][vspawn_colour2]);
		}
	}
	for (new i=0;i<sizeof(VehicleLVDMSpawns);i++)
	{
		if (VehicleLVDMSpawns[i][vspawn_model] != 0)
		{
			AddVehicleSpawn(VehicleLVDMSpawns[i][vspawn_model],VehicleLVDMSpawns[i][vspawn_x],VehicleLVDMSpawns[i][vspawn_y],VehicleLVDMSpawns[i][vspawn_z],VehicleLVDMSpawns[i][vspawn_heading],VehicleLVDMSpawns[i][vspawn_colour1],VehicleLVDMSpawns[i][vspawn_colour2]);
		}
	}
}
