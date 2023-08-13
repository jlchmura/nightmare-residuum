#include "user.h"

#define QUERY_FIRST_IMMORTAL !sizeof(filter(get_dir("/realm/"), (: $1 && $1[0] != '.' :)))

nosave private string __Species;
nosave private object __Character;

// -----------------------------------------------------------------------------

private void set_character_name (string name) {
    if (!__Character) {
        __Character = clone_object(STD_CHARACTER);
        __Character->set_user(this_object());
    }
    if (name) {
        __Character->set_name(name);
    } else {
        destruct(__Character);
        __Character = clone_object(STD_CHARACTER);
    }
}
private void set_character_species (string species) {
    __Species = species;
    __Character->set_species(species);
}
string query_character_species () {
    return __Species;
}
object query_character () {
    return __Character;
}

// -----------------------------------------------------------------------------

nomask private void character_enter (int newbie) {
    remove_call_out();

    __Character->setup_character(); // this calls restore_data/save_data
    if (newbie) {
        if (__Character->query_species() == "human") {
            __Character->set_environment_path("/domain/Origin/room/enter.c");
        } else {
            __Character->set_environment_path("/domain/Nowhere/room/void.c");
        }
    }

    shell_start();
    __Character->enter_world();

    if (newbie) {
        if (QUERY_FIRST_IMMORTAL) {
            __Character->set_immortal(1);
            write("\n%^BOLD%^Since this appears to be the first connection, you have been set as immortal.%^RESET%^\n\n");
        }
        __Character->save_data();
    }
}

nomask private void character_reconnect (object char) {
    remove_call_out();

    if (!char) {
        error("Bad argument 1 to user/character->character_reconnect");
    }

    __Character = char;
    __Character->set_user(this_object());
    shell_start();
    write("\n\nReturning " + __Character->query_cap_name() + " from linkdeath...\n\n");
    __Character->exit_freezer();
}

nomask private void character_override (object char) {
    remove_call_out();

    if (!char) {
        error("Bad argument 1 to user/character->character_override");
    }

    // Swap character's user
    __Character = char;
    if (char->query_user())
    __Character->set_user(this_object());
    __Character->set_parent(this_object());

    shell_start();
    __Character->enter_world(1);
}

nomask void handle_character_override () {
    object po;
    if (base_name(po = previous_object()) == STD_USER[0..<3] && po->query_character() == __Character) {
        __Character = 0;
        handle_remove("\nYour connection has been overriden from " + query_ip_number(po) + ".\n\n");
    }
}

nomask protected void character_exit () {
    if (__Character) {
        __Character->set_last_action();
        this_object()->update_character_data(__Character);
        __Character->exit_world();
        __Species = 0;
    }
}

nomask protected void character_linkdead () {
    __Character->set_last_action();
    __Character->enter_freezer();
}
