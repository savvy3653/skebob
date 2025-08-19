
/*
    /ping					  - test command
    /stats @user			  - get user's stats
    /set @user param: value:  - set a parameter in stats
*/

#include "commands.h"

void Commands::command_init() {
    bot->on_ready([this](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot->global_command_create(dpp::slashcommand("ping", "Ping pong", bot->me.id));
            bot->global_command_create(dpp::slashcommand("stats", "stats_cmd", bot->me.id)
            .add_option(
                dpp::command_option(dpp::co_string, "user", "User id.").set_auto_complete(true)
            )
            );
            bot->global_command_create(dpp::slashcommand("set", "set_cmd", bot->me.id)
            .add_option(
                dpp::command_option(dpp::co_string, "user", "User id.").set_auto_complete(true)
            )
            );
        }
    });
}

void Commands::command_handler() {
    bot->on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") event.reply("Pong!");
        if (event.command.get_command_name() == "stats") { event.reply("Stats"); }
        if (event.command.get_command_name() == "set") { event.reply("Set Stats"); }
    });
}