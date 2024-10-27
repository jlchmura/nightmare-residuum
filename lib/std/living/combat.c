nosave private object *__Hostiles;

void create () {
    __Hostiles = ({ });
}

/* ----- hostiles ----- */

int add_hostile (object ob) {
    if (!ob || !ob->is_living() || member_array(ob, __Hostiles) > -1) {
        return 0;
    }
    if (ob == this_object() || ob->query_defeated() || this_object()->query_defeated()) {
        return 0;
    }
    __Hostiles += ({ ob });
    return 1;
}
int remove_hostile (object ob) {
    if (!ob || !ob->is_living() || member_array(ob, __Hostiles) == -1) {
        return 0;
    }
    __Hostiles -= ({ ob });
    return 1;
}
int query_hostile (object ob) {
    return member_array(ob, __Hostiles) > -1;
}
object *query_hostiles () {
    __Hostiles = filter(__Hostiles, (: !undefinedp($1) :));
    return __Hostiles;
}

/* ----- combat ----- */

protected void handle_combat () {
    object to = this_object(), target, *weapons;
    int min, max, hits, crit, damage, d100, sum = 0;
    string limb;

    target = present_hostile(to);
    to->check_lifesigns(target);
    if (
        !to ||
        to->query_defeated() ||
        to->query_disable() ||
        !target ||
        environment() != environment(target)
    ) {
        return;
    }

    if (to->query_posture() == "meditating") {
        to->set_posture("sitting");
    }
    if (member_array(to->query_posture(), ({ "sitting", "laying" })) > -1) {
        message("combat info", "You cannot fight while " + to->query_posture() + " down!", to);
        return;
    }

    target->add_hostile(to);

    if (to->is_npc() && to->query_ability_chance()) {
        to->handle_ability_attack();
    }

    weapons = to->query_wielded_weapons() + to->query_wieldable_limbs();
    min = sizeof(weapons[0..2]) + to->query_stat("agility") / 100;
    max = sizeof(weapons[0..2]) + to->query_stat("agility") / 50;
    hits = min + random(max - min + 1);

    if (!hits) {
        message("combat miss", to->query_cap_name() + " " + element_of(({
            "flops about helplessly",
            "tries to look menacing",
            "uselessly flops around",
        })) + ".", environment(), to);
    }
    for (int h = 0; h < hits; h ++) {
        if (!target) {
            break;
        }
        if (to->query_sp() > 0) {
            d100 = roll_die(1, 100)[0];
        }
        sum = 0;
        foreach (mapping m in combat_table(to, target, h)) {
            if (!m["value"]) {
                continue;
            }
            damage = 0;
            crit = 0;
            sum = min(({ 100, sum + m["value"], }));
            if (d100 <= sum) {
                switch (m["id"]) {
                case "miss":
                    combat_miss_message(to, target, element_of(weapons));
                    break;
                // case "resist": // @TODO
                //     break;
                case "block":
                    combat_block_message(to, target);
                    break;
                case "parry":
                    combat_parry_message(to, target, element_of(weapons));
                    break;
                case "evade":
                    combat_evade_message(to, target);
                    break;
                case "critical hit":
                    crit = 1;
                case "regular hit":
                    limb = target->query_random_limb();
                    damage = combat_hit_damage(to, target, limb, element_of(weapons), crit);
                    combat_hit_message(to, target, limb, element_of(weapons), damage, crit, 0);
                    target->handle_damage(damage, limb);
                    break;
                }
                break;
            }
        }
    }
    to->add_sp(-(random(hits) + 1));
    if (target) {
        target->check_lifesigns(to);
    }
}

varargs void check_lifesigns (object source) {
    int dead = 0;

    if (this_object()->query_defeated()) {
        return;
    }

    if (this_object()->query_hp() < 0) {
        dead = 1;
    }
    if (!dead) {
        foreach (string limb in this_object()->query_severed_limbs()) {
            if (this_object()->query_limb(limb)["type"] == "FATAL") {
                dead = 1;
            }
        }
    }
    if (dead) {
        message("defeat", "\nYou have been %^I_RED%^BOLD%^defeated%^RESET%^!\n", this_object());
        message("defeat", "\n" + this_object()->query_cap_name() + " has been %^I_RED%^BOLD%^defeated%^RESET%^!\n", environment(), this_object());
        if (source) {
            source->handle_victory(this_object());
        }
        this_object()->handle_defeat(source);
    }
}

/* ----- parser applies ----- */

mixed direct_attack_liv (mixed args...) {
    object po = previous_object();
    return environment() == environment(po) && po != this_object() && !query_hostile(po);
}
mixed direct_aid_liv (mixed args...) {
    return direct_attack_liv(args);
}