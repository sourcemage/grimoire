if [[ "${BOGOFILTER_DB}" == sqlite ]]
then
BOGOFILTER_DB=sqlite3
fi                                               &&
OPTS="--with-database=${BOGOFILTER_DB} ${OPTS}"  &&
default_build                                    &&
if [[ "${BOGOFILTER_DB}" == sqlite3 ]]
then
BOGOFILTER_DB=sqlite
fi
