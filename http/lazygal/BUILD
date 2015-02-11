default_build_python &&
local DOCBOOK_XSL_VERSION=$(installed_version docbook-xsl|cut -f1,2 -d.) &&
xsltproc --nonet -o ./ /usr/share/xml/docbook/xsl-stylesheets-${DOCBOOK_XSL_VERSION}/manpages/docbook.xsl ./lazygal.1.xml &&
xsltproc --nonet -o ./ /usr/share/xml/docbook/xsl-stylesheets-${DOCBOOK_XSL_VERSION}/manpages/docbook.xsl ./lazygal.conf.5.xml
