if list_find "$KCHMVIEW_OPTS" "--with-kde" ; then

   if [[ $QT3 == y ]]; then

     OPTS="$KCHMVIEW_OPTS $OPTS" &&
     default_kde3_build

   fi

else

  if [[ $QT3 == y ]]; then

    default_build

  else

    build_qt3_or_4

  fi
  
fi
