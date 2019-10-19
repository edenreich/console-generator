#include <console/application.h>

#include "commands/make_command.h"


int main(int argc, char ** argv)
{
    Console::Application app(argc, argv);

    app.setApplicationName("Console CLI Helper");
    app.setApplicationUsage("console-cli <command> [options]");
    app.setApplicationVersion("1.0.0");
    app.setAutoPrintHelp(true);

    app.setApplicationDescription("An helper / util for the console-component, this cli help to generate commands quickly.");

    app.addCommand(new MakeCommand);

    return app.run();
}
