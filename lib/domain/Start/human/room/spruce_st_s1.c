#include "human.h"

inherit STD_ROOM;

void create () {
    ::create();
    set_short("a village street");
    set_long("A small street traveling north and south through brick dwellings covered in dark ivy. Several birch trees branch over the street and dwellings. A framework of hexagons glimmer overhead.");
    set_exits(([
        "north": HUMAN_ROOM + "market_st_e3.c",
        "south": HUMAN_ROOM + "spruce_st_s2.c",
    ]));
    set_looks(([
        "street": "A village street labeled S Spruce St.",
    ]));
}