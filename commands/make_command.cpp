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

    const std::string name = input->getOption("name");
    const std::string colonSeparatedName = makeColonCaseName(name);
    const std::string snakeCaseName = makeSnakeCaseName(name);

    const std::string cppFile =
"#include \"" + snakeCaseName + ".h\"\n\n\n"



"class " + name + " {\n\n"
"/**\n"
" * Retrieve the name of the command.\n"
" *\n"
" * @return std::string\n"
" */\n"
"std::string " + name + "::getName()\n"
"{\n"
"    return \"" + colonSeparatedName + "\";\n"
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

    const std::string headerFile = 
"#pragma once\n\n"

"#include <console/interfaces/command_interface.h>\n"
"#include <console/types/collections.h>\n\n"

"namespace Interfaces = Console::Interfaces;\n"
"namespace Types = Console::Types;\n\n\n"



"/**\n"
" * "+ colonSeparatedName +"\n"
" */\n"
"class " + name + " : public Interfaces::CommandInterface\n"
"{\n\n"

"public:\n\n"

"    /**\n"
"     * Retrieve the name of the command.\n"
"     *\n"
"     * @return std::string\n"
"     */\n"
"    std::string getName() override;\n\n"

"    /**\n"
"     * Retrieve the description of the command.\n"
"     *\n"
"     * @return std::string\n"
"     */"
"    std::string getDescription() override;\n\n"

"    /**\n"
"     * Retrieve the command options.\n"
"     *\n"
"     * @return Types::AvailableOptions\n"
"     */\n"
"    Types::AvailableOptions getOptions() override;\n\n"

"    /**\n"
"     * Handle the command.\n"
"     *\n"
"     * @param InputInterface * input\n"
"     * @param OutputInterface * output\n"
"     * @return ExitCode\n"
"     */\n"
"    ExitCode handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output) override;\n\n"

"};\n";


    // create a cpp file and header file in commands directory with the rendered output.

    return ExitCode::Ok;
}


/**
 * Create out of uppercase class name
 * a colon case name.
 * 
 * @param std::string name
 * @return const std::string &
 */
std::string MakeCommand::makeColonCaseName(const std::string & name)
{
    const std::string & colonCaseName = "default";


    return colonCaseName;
}

/**
 * Create out of uppercase class name
 * a snake case name.
 * 
 * @param std::string name
 * @return const std::string &
 */
std::string MakeCommand::makeSnakeCaseName(const std::string & name)
{
    std::string colonCaseName = "default";


    return colonCaseName;
}