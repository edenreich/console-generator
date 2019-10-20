#include "make_command.h"

#include <iostream>
#include <fstream>

#include <experimental/filesystem>
#include <ios>

namespace fs = std::experimental::filesystem;


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

    // Initialize class members
    m_name = input->getOption("name");
    m_colonCaseName = makeColonCaseName(m_name);
    m_snakeCaseName = makeSnakeCaseName(m_name);

    // Render the files output
    const std::string definitionFileString = getRenderedDefinitionFile();
    const std::string implementionFileString = getRenderedImplementionFile();

    fs::path path = fs::current_path();

    if (fs::exists(path.append("commands")) == false) {
        output->error("Commands directory does not exists!");
        // for now just treat it as an error, perhaps later I will create a directory
        return ExitCode::Error;
    }

    std::ofstream definitionFile;
    std::ofstream implementionFile;

    definitionFile.open("commands/" + m_snakeCaseName + ".h", std::ios::out);
    implementionFile.open("commands/" + m_snakeCaseName + ".cpp", std::ios::out);

    definitionFile << definitionFileString;
    implementionFile << implementionFileString;

    definitionFile.close();
    implementionFile.close();

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
    std::string colonCaseName;

    std::size_t length = name.length();

    colonCaseName.reserve(length);

    for (unsigned int i = 0; i < length; ++i)
    {
        colonCaseName += tolower(name[i]);

        if (i > 1 && isupper(name[i])) {
            colonCaseName.insert(i, ":");
        }
    }

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
    std::string snakeCaseName;

    std::size_t length = name.length();

    snakeCaseName.reserve(length);

    for (unsigned int i = 0; i < length; ++i)
    {
        snakeCaseName += tolower(name[i]);

        if (i > 1 && isupper(name[i])) {
            snakeCaseName.insert(i, "_");
        }
    }

    return snakeCaseName;
}

/**
 * Retrieve the rendered implemention file.
 * 
 * @return std::string
 */
std::string MakeCommand::getRenderedImplementionFile()
{
    std::string implementionFile = 
"#include \"" + m_snakeCaseName + ".h\"\n\n\n"


"/**\n"
" * Retrieve the name of the command.\n"
" *\n"
" * @return std::string\n"
" */\n"
"std::string " + m_name + "::getName()\n"
"{\n"
"    return \"" + m_colonCaseName + "\";\n"
"}\n\n"
"/**\n"
" * Retrieve the description of the command.\n"
" *\n"
" * @return std::string\n"
" */\n"
"std::string " + m_name + "::getDescription()\n"
"{\n"
"    return \"Default Description\";\n"
"}\n\n"
"/**\n"
" * Retrieve the command options.\n"
" *\n"
" * @return Types::AvailableOptions\n"
" */\n"
"Types::AvailableOptions " + m_name + "::getOptions()\n"
"{\n"
"    Types::AvailableOptions options;\n"
"    \n"
"    return options;\n"
"}\n\n"
"/**\n"
" * Handle the command.\n"
" *\n"
" * @param InputInterface * input\n"
" * @param OutputInterface * output\n"
" * @return ExitCode\n"
" */\n"
"ExitCode " + m_name + "::handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output)\n"
"{\n"
"    if (input->wantsHelp()) {\n"
"        output->printCommandHelp(this);\n"
"        return ExitCode::NeedHelp;\n"
"    }\n\n"
"    // Implemention goes here.. \n\n"
"    return ExitCode::Ok;\n"
"}\n";

    return implementionFile;
}

/**
 * Retrieve the rendered header file.
 *
 * @return std::string
 */
std::string MakeCommand::getRenderedDefinitionFile()
{
    std::string headerFile = 
"#pragma once\n\n"

"#include <console/interfaces/command_interface.h>\n"
"#include <console/types/collections.h>\n\n"

"namespace Interfaces = Console::Interfaces;\n"
"namespace Types = Console::Types;\n\n\n"


"/**\n"
" * "+ m_colonCaseName +"\n"
" */\n"
"class " + m_name + " : public Interfaces::CommandInterface\n"
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

    return headerFile;
}
