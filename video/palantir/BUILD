create_account palantir /usr/share/palantir /bin/false video,audio  &&
cd  $SOURCE_DIRECTORY/server                                        &&
sedit  "s:/usr/local:$INSTALL_ROOT/usr:"  Makefile                  &&
sedit  "s:/man$:/share/man:"              Makefile                  &&
make                          
