(

  prepare_install &&
  mkdir -p /usr/share/$SPELL &&
  cp -r * /usr/share/$SPELL &&
  chmod -R u=rwX,og=rX /usr/share/$SPELL

) >$C_FIFO 2>&1 && (

  message $(cat <<EOF
Please map an URI on your Web server to /usr/share/$SPELL to enable
${SPELL_COLOR}TikiWiki${DEFAULT_COLOR}. Also make sure PHP is enabled.
In order to complete the installation of TikiWiki, create the
database and open http://localhost/<URI>/tiki-install.php in browser.
It will prompt you for values it needs to complete the installation.
EOF
  )

)
