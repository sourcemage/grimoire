## Build jar
if [ -f /etc/profile.d/ant.sh ]; then
    source /etc/profile.d/ant.sh
fi &&
ant build &&

## Build docs

if [[ "${JEDIT_DOCS_HTML}" == "y" ]]
then ant docs-html
fi &&
if [[ "${JEDIT_DOCS_JAVA}" == "y" ]]
then ant docs-javadoc
fi
if [[ "${JEDIT_DOCS_PDF_A4}" == "y" ]]
then ant docs-pdf-a4
fi
if [[ "${JEDIT_DOCS_PDF_US}" == "y" ]]
then ant docs-pdf-USletter
fi
