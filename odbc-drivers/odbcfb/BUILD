cd  $SOURCE_DIRECTORY/Builds/Gcc.lin   &&
sed -i 's/lib64/lib/' makefile.linux &&
if spell_ok unixodbc;then
  make -f makefile.linux ODBCMANAGER=unixODBC
else
  make -f makefile.linux ODBCMANAGER=iODBC
fi
