# the hack with this is it has to be installed somewhere then built there, then kept around :/

unpack_file  &&
cd $SOURCE_DIRECTORY &&
# apply hax to the Rakefile
sed -i -e "s|-I/usr/local/include|-I/usr/local/include -I/usr/include/apr-1|" Rakefile &&
rake clean apache2

