#!/bin/bash

update_makefile() {
    local makefile="$1"
    echo "Updating: $makefile"
    
    # Check if file exists and contains the compilation rule
    if [[ -f "$makefile" ]] && grep -q "%.o: %.cpp" "$makefile"; then
        
        # Add DEP variable after OBJ variable (various naming patterns)
        if grep -q "OBJ.*=" "$makefile" && ! grep -q "DEP.*=" "$makefile"; then
            sed -i '/OBJ.*=/a DEP = $(OBJ:%.o=%.d)' "$makefile" 2>/dev/null || \
            sed -i '/OBJS.*=/a DEPS = $(OBJS:%.o=%.d)' "$makefile" 2>/dev/null
        fi
        
        # Add -MMD -MP flags to compilation rule
        if grep -q "\$(CC).*-c.*\$<.*-o.*\$@" "$makefile" && ! grep -q "\-MMD" "$makefile"; then
            sed -i 's/\(\$(CC).*\) -c \(.*\$<.*-o.*\$@\)/\1 -MMD -MP -c \2/' "$makefile"
        elif grep -q "\$(CPP).*-c.*\$<.*-o.*\$@" "$makefile" && ! grep -q "\-MMD" "$makefile"; then
            sed -i 's/\(\$(CPP).*\) -c \(.*\$<.*-o.*\$@\)/\1 -MMD -MP -c \2/' "$makefile"
        fi
        
        # Add .PHONY if not present
        if ! grep -q "^\.PHONY:" "$makefile"; then
            echo "" >> "$makefile"
            echo ".PHONY: all clean fclean re" >> "$makefile"
        fi
        
        # Add include dependencies
        if ! grep -q "\-include.*DEP" "$makefile"; then
            echo "" >> "$makefile"
            if grep -q "DEPS.*=" "$makefile"; then
                echo "-include \$(DEPS)" >> "$makefile"
            else
                echo "-include \$(DEP)" >> "$makefile"  
            fi
        fi
        
        echo "✓ Updated $makefile"
    else
        echo "⚠ Skipped $makefile (not found or missing compilation rule)"
    fi
}

# Export function so it can be used with find
export -f update_makefile

# Update all remaining Makefiles in cpp_modules (excluding those already updated)
find /sgoinfre/malja-fa/github/cpp_modules -name "Makefile" -not -path "*/cpp00/*" -not -path "*/cpp01/ex00/*" -not -path "*/cpp04/ex00/*" -exec bash -c 'update_makefile "$0"' {} \;

echo "Done updating all remaining Makefiles!"
