void command (string input) {
    if (!this_character()) {
        write("Quitting out...\n");
    } else {
        write("Quitting out of " + this_character()->query_name() + ".\n");
    }
    this_user()->quit_character();
}