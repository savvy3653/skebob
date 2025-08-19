#pragma once

#include "token.h"
#include <dpp/dpp.h>

class Commands {
	dpp::cluster* bot;
public:
	Commands(dpp::cluster* bot) : bot(bot) 
	{}
	~Commands() { delete bot; }

	void command_init(void);
	void command_handler(void);
};
