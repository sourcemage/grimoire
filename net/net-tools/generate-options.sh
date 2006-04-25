#!/bin/bash
# Small utility script in case net-tools' config.in changes
# Usage: cd ~/p4/grimoire/devel/net/net-tools
# ./generate-options </usr/src/net-tools-1.60/config.in

mkdir -p options

grep '^bool' |
while read -r LINE ;do
  OPTNAME=${LINE##*\' }
  OPTNAME=${OPTNAME% ?}
  echo "$LINE" |
  sed -r "s/^bool '([^']*)'.*(.)\$/STATUS=\\2\\
QUESTION=\"\\1\"/" >options/$OPTNAME
done
