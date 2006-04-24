(

    ./configure --prefix=/usr $OPTS &&
    make &&
    make install &&
    cd packages &&
    ./configure --prefix=/usr $OPTS &&
    make && 
    make install

) > $C_FIFO 2>&1
