#!/usr/bin/tclsh
# This is user to generate template for new case.
set name [lindex $argv 0]
if {$name != ""} {
    set fileh [open ./$name.h w+]
    set filec [open ./$name.cxx w+]
    puts $fileh "#ifndef _${name}_HEADER\n#define _${name}_HEADER\n#include<iostream>\nusing namespace std;\nvoid test_$name\(\);\n\n#endif"
    puts $filec "#include \"${name}.h\"\n\nvoid test_${name}() {\n\n}"
}
