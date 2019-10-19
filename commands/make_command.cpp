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

    std::string name = input->getOption("name");
    // @todo write the implemention
    
    std::string cppFile =
"#include \"xxx_command.h\"\n\n\n"
"class " + name + " {\n\n"
"/**\n"
" * Retrieve the name of the command.\n"
" *\n"
" * @return std::string\n"
" */\n"
"std::string " + name + "::getName()\n"
"{\n"
"    return \"default\";\n"
"}\n\n"
"/**\n"
" * Retrieve the description of the command.\n"
" *\n"
" * @return std::string\n"
" */\n"
"std::string " + name + "::getDescription()\n"
"{\n"
"    return \"Default Description\";\n"
"}\n\n"
"/**\n"
" * Retrieve the command options.\n"
" *\n"
" * @return Types::AvailableOptions\n"
" */\n"
"Types::AvailableOptions " + name + "::getOptions()\n"
"{\n"
"    Types::AvailableOptions options;\n"
"    \n"
"    return options\n"
"}\n\n"
"/**\n"
" * Handle the command.\n"
" *\n"
" * @param InputInterface * input\n"
" * @param OutputInterface * output\n"
" * @return ExitCode\n"
" */\n"
"ExitCode " + name + "::handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output)\n"
"{\n"
"    if (input->wantsHelp()) {\n"
"        output->printCommandHelp(this);\n"
"        return ExitCode::NeedHelp;\n"
"    }\n\n"
"    \\\\ Implemention goes here.. \n\n"
"    return ExitCode::Ok;\n"
"}\n";


    output->info(cppFile);
    // create a cpp file and header file in commands directory with the rendered output.

    return ExitCode::Ok;
}
