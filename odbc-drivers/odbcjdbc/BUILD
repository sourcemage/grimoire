
cd  $SOURCE_DIRECTORY/OdbcJdbc/Builds/Gcc.lin   &&
if spell_ok unixodbc;then
  make -f makefile.linux ODBCMANAGER=unixODBC
else
  make -f makefile.linux ODBCMANAGER=iODBC
fi
