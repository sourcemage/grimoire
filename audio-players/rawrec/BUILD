(

cd src                                  &&
sedit 's/\/usr\/local/\/usr/g' Makefile &&
make                                    && 
make man_install                        &&
install -m755 rawrec /usr/bin           &&
cd /usr/bin                             && 
ln -f rawrec rawplay

) > $C_FIFO 2>&1
