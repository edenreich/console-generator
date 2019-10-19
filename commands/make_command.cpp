#include "make_command.h"


/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string MakeCommand::getName()
{
    return "make:command";
}

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string MakeCommand::getDescription()
{
    return "Make a command";
}

/**
 * Retrieve the command options.
 *
 * @return Types::AvailableOptions
 */
Types::AvailableOptions MakeCommand::getOptions()
{
    Types::AvailableOptions options;

    return options;
}

/**
 * Handle the command.
 *
 * @param InputInterface * input
 * @param OutputInterface * output
 * @return ExitCode
 */
ExitCode MakeCommand::handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output)
{
    if (input->wantsHelp()) {
        output->printCommandHelp(this);
        return ExitCode::NeedHelp;
    }

    // @todo write the implemention

    // create a macro that contains a command strcture and one that contains a header structure that have placeholders (unique identifiers / tokens).
    // perform search and replace on this tokens
    // create a cpp file and header file in commands directory with the rendered output.

    return ExitCode::Ok;
}
