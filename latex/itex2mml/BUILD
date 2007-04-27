cd itex &&
rm *.o *~ *OLD &&
sedit 's|(char \*)||g' itex2MML.y &&
sedit 's|#include "y\.tab\.h"|typedef char* YYSTYPE;\n#define YYSTYPE_IS_DECLARED\n\0|g' itex2MML.l &&
make itex2MML
