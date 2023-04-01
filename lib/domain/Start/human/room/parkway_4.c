#include "human.h"

inherit STD_ROOM;

void create () {
    ::create();
    set_short("a wide village street");
    set_long("A wide street travels southeast with green spaces instead of buildings. A large marble building with columns surrounding the entrance blocks further passage northwest. Birch trees branch over the street and open green spaces. Flower beds are prepared near street intersections. An obelisk can be seen to the southeast. A framework of hexagons glimmer far overhead.");
    set_listen("default", "Birds chirp from the trees.");
    set_smell("default", "Fresh air smelling of grass.");
    set_exits(([
        "enter northwest": HUMAN_ROOM + "museum_1.c",
        "southeast": HUMAN_ROOM + "park_nw.c",
    ]));
    set_looks(([
        "street": "A street sign is labeled Parkway.",
        ({ "building", "columns", }): "A large marble building that takes spans the width of the street block. It looks to be a couple stories tall with an ornate crowning around the roof line. Some windows are spaced out along the side of the building. Columns span the entranceway.",
    ]));
    set_reset(([
        HUMAN_ITEM + "artwork_4.c": 1,
        HUMAN_ITEM + "bench.c": 2,
        HUMAN_NPC + "ant.c": !random(3),
        HUMAN_NPC + "bee.c": !random(3),
        HUMAN_NPC + "beetle.c": !random(3),
        HUMAN_NPC + "squirrel.c": !random(3),
        HUMAN_NPC + "wasp.c": !random(3),
        HUMAN_NPC + "pigeon.c": !random(2),
        HUMAN_NPC + "sparrow.c": !random(2),
    ]));
}