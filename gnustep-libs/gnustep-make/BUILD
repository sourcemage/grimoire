./configure            \
    $OPTS              &&

make                   &&

if [ "$DOCU" == "y" ]; 
then
    cd Documentation   &&
    make               &&
    cd ../
fi 

