#include "human.h"

inherit STD_ROOM;

void create () {
    ::create();
    set_properties(([ "indoors": 1, ]));
    set_short("a historical building");
    set_long("The northern hallway of a building with high ceilings and polished floors. The walls are made of stone blocks and covered with tapestries, except for the western wall which is covered in a large painting. The end of the hallway comes to a staircase leading up to the second floor.");
    set_exits(([
        "south": HUMAN_ROOM + "museum_1_n1.c",
        "up": HUMAN_ROOM + "museum_2_n2.c",
    ]));
    set_looks(([
        ({ "building", "ceiling", "walls" }): "A building of large proportions. This hallway is a large room with high ceilings and distant walls.",
        "floor": "The floor is a polished white stone in large blocks.",
        "hallway": "It leads away from the lobby and turns.",
        ({ "painting", "wall" }): "A painting takes up most of the western wall of the hallway.",
    ]));
}