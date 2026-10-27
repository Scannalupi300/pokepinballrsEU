#!/bin/bash

OBJDUMP="$DEVKITARM/bin/arm-none-eabi-objdump -D -bbinary -marmv4t -Mforce-thumb"
OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
$OBJDUMP $OPTIONS baserom_eu.gba > baserom.dump
$OBJDUMP $OPTIONS pokepinballrs_eu.gba > pokepinballrs.dump
diff -u baserom.dump pokepinballrs.dump
