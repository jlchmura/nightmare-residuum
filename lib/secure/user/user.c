inherit "/secure/user/account.c";
inherit "/secure/user/character.c";
inherit "/secure/user/input.c";
inherit "/secure/user/shell.c";

#include "user.h"

#define CONNECT_TIMEOUT 60 // @TODO should be higher

nosave private int calloutHandle;



/* --- interactive apply --- */

nomask void logon () {
    debug_message(ctime()+" connect() from "+query_ip_number()); // @TODO LOG_D

    call_out(function() {
        receive_message("system", D_WELCOME->query_banner() + "\n");
        account_input();
        if (this_user() && interactive(this_user())) telnet_ga();
    }, 0);
}

nomask void net_dead () {
    // @TODO

    if (query_account() && query_character()) {
        query_account()->update_character_data(query_character()->query_key_name(), query_character_summary());
    }
}

void receive_message (string type, string message) {
    if (type == "system") {
        receive(wrap(message, 0, 0));
    } else if (type == "say") {
        message = "%^CYAN%^" + replace_string(message, ":", ":%^RESET%^");
        receive(wrap(message));
    } else if (type == "go") {
        message = "%^GREEN%^BOLD%^" + message + "%^RESET%^";
        receive(wrap(message));
    } else {
        receive(wrap(message, 0, 0));
    }
}

/* --- interactive non-apply */

nomask void reconnect () {
    // @TODO
}

nomask void quit_character (int destructing) {
    write("Reality "+(random(2)?"explodes into an im":"implodes into an ex")+"plosion of irreality.\n");
    character_exit();
    shell_stop();
    flush_messages();
    if (!destructing) {
        account_input(STATE_ACCOUNT_MENU);
    }
}

nomask void quit_account () {
    quit_character(1);
    destruct(this_object());
}

nomask void reset_connect_timeout () {
    if (!undefinedp(calloutHandle)) remove_call_out(calloutHandle);
    calloutHandle = call_out((: handle_destruct, "\nTime exceeded. Connection terminated.\n" :), CONNECT_TIMEOUT);
}

protected nomask int handle_login_commands (string input) {
    // Handle any commands from the login prompt here
    // if (grepp(input, "MSSP-REQUEST")) { /* from Dead Souls */ }
    // @TODO
    return 0;
}

nomask varargs void handle_destruct (string message) {
    if (!undefinedp(calloutHandle)) remove_call_out(calloutHandle);
    if (message) write(message);
    destruct(this_object());
}

