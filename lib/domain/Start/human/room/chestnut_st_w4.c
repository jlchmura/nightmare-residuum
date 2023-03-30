#include "human.h"

inherit STD_ROOM;

void create () {
    ::create();
    set_short("a village street");
    set_long("A small street traveling west to east through brick dwellings covered in dark ivy. Several birch trees branch over the street and dwellings. An open grassy area is to the east. A large marble building is to the north. A framework of hexagons glimmer overhead.");
    set_exits(([
        "west": HUMAN_ROOM + "chestnut_st_w5.c",
        "east": HUMAN_ROOM + "park_nw.c",
    ]));
    set_looks(([
        "street": "A village street labeled W Chestnut St.",
    ]));
}