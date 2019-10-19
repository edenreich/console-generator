#include <console/application.h>

#include "commands/make_command.h"


int main(int argc, char ** argv)
{
    Console::Application app(argc, argv);

    app.setApplicationName("Console Generator Helper");
    app.setApplicationUsage("console-generator <command> [options]");
    app.setApplicationVersion("1.0.0");
    app.setAutoPrintHelp(true);

    app.setApplicationDescription("A code genrator for the console-component, it generate commands quickly, so you can be more productive and focus only on code.");

    app.addCommand(new MakeCommand);

    return app.run();
}
