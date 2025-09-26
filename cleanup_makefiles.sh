#!/bin/bash

cleanup_makefile() {
    local makefile="$1"
    echo "Cleaning up: $makefile"
    
    if [[ -f "$makefile" ]]; then
        # Remove duplicate DEP/DEPS lines
        sed -i '/^DEP = /h; /^DEP = /!b; $!n; /^DEP = /d; g' "$makefile"
        sed -i '/^DEPS = /h; /^DEPS = /!b; $!n; /^DEPS = /d; g' "$makefile"
        
        # Fix incorrect variable references in DEP lines
        # First check what object variable is actually used
        if grep -q "OBJS.*=" "$makefile"; then
            sed -i 's/DEP = \$(OBJ:/DEPS = $(OBJS:/g' "$makefile"
            sed -i 's/-include \$(DEP)/-include $(DEPS)/g' "$makefile"
        elif grep -q "OBJ.*=" "$makefile"; then
            sed -i 's/DEPS = \$(OBJS:/DEP = $(OBJ:/g' "$makefile"
            sed -i 's/-include \$(DEPS)/-include $(DEP)/g' "$makefile"
        fi
        
        # Remove duplicate .PHONY lines
        sed -i '$!N; /^\(.*\)\n\1$/!P; D' "$makefile"
        
        # Remove duplicate -include lines
        sed -i '/^-include/h; /^-include/!b; $!n; /^-include/d; g' "$makefile"
        
        echo "✓ Cleaned up $makefile"
    fi
}

export -f cleanup_makefile

# Clean up all Makefiles
find /sgoinfre/malja-fa/github/cpp_modules -name "Makefile" -exec bash -c 'cleanup_makefile "$0"' {} \;

echo "Done cleaning up all Makefiles!"
