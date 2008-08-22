      function to () {
         if test "$2"; then
           cd "$(apparix "$1" "$2" || echo .)";
         else
           cd "$(apparix "$1" || echo .)";
         fi
         pwd
      }
      function bm () {
         if test "$2"; then
            apparix --add-mark "$1" "$2";
         elif test "$1"; then
            apparix --add-mark "$1";
         else
            apparix --add-mark;
         fi
      }
      function portal () {
         if test "$1"; then
            apparix --add-portal "$1";
         else
            apparix --add-portal;
         fi
      }
