#pragma once

#include <console/interfaces/command_interface.h>
#include <console/types/collections.h>

namespace Interfaces = Console::Interfaces;
namespace Types = Console::Types;

/**
 * make:command
 */
class MakeCommand : public Interfaces::CommandInterface
{

public:

    /**
     * Retrieve the name of the command.
     *
     * @return std::string
     */
    std::string getName() override;

    /**
     * Retrieve the description of the command.
     *
     * @return std::string
     */
    std::string getDescription() override;

    /**
     * Retrieve the command options.
     *
     * @return Types::AvailableOptions
     */
    Types::AvailableOptions getOptions() override;

    /**
     * Handle the command.
     *
     * @param InputInterface * input
     * @param OutputInterface * output
     * @return ExitCode
     */
    ExitCode handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output) override;

private: 

    /**
     * Create out of uppercase class name
     * a colon case name.
     * 
     * @param std::string name
     * @return const std::string &
     */
    std::string makeColonCaseName(const std::string & name);

    /**
     * Create out of uppercase class name
     * a snake case name.
     * 
     * @param std::string name
     * @return const std::string &
     */
    std::string makeSnakeCaseName(const std::string & name);

    /**
     * Retrieve the rendered definition file.
     *
     * @return std::string
     */
    std::string getRenderedDefinitionFile();

    /**
     * Retrieve the rendered implemention file.
     * 
     * @return std::string
     */
    std::string getRenderedImplementionFile();

    /**
     * Store the name of the command.
     * 
     * @var std::string
     */
    std::string m_name;

    /**
     * Store the colon case name of the command.
     * 
     * @var std::string
     */
    std::string m_colonCaseName;

    /**
     * Store the snake case name of the command.
     * 
     * @var std::string
     */
    std::string m_snakeCaseName;

};
