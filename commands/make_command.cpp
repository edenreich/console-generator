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


    return ExitCode::Ok;
}
