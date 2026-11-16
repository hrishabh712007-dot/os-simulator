#include "Shell.h"

#include "Boot.h"
#include "cleanup.h"
void Shell() {
    Boot();
    cout << "Enter user name: ";
    string name;
    getline(cin, name);
    cout << "`````````````````````\n";
    cout << "    OS SIMULATOR\n";
    cout << "`````````````````````\n";
    cout << "[" << name << "@neon /]$ ";
    FileSystem fs;
    CommandParser commandparser(&fs);
    string input;
    while (getline(cin, input)) {
        if (!commandparser.execute(input)) break;
        cout << "[" << name << "@neon " << fs.current->name << "]$ ";
    }
    Cleanup(&fs);

    cout << "\n`````````````````````\n";
    cout << "  Goodbye, " << name << "!\n";
    cout << "`````````````````````\n";
    cout << "\n";
}
