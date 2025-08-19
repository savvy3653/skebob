#include "token.h"
#include "stats.h"
#include "commands.h"

#include <iostream>
#include <dpp/dpp.h>

int main(int argc, char* argv[]) {
    dpp::cluster bot(TOKEN);;
    Commands* cmd = new Commands(&bot);

    bot.on_log(dpp::utility::cout_logger());

    cmd->command_handler();
    cmd->command_init();
    cmd->autocomplete_init();

    bot.start(dpp::st_wait);

    delete cmd;
    return 0;
}
