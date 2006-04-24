#n    <- Makes sed quiet

/<textarea name="document"/, /<\/textarea>/ {
        s/[[:space:]]*<[^>]*>//
        s/^[[:space:]]*\*\*/    # /
        s/^[[:space:]]*\*/  * /
        s/^[[:space:]]*::/     /
        s/^[[:space:]]*:/   /
        s/{{\([^}]*\)}}/\1/g
        s/'''\([^']*\)'''/\1/g
        s/''\([^']*\)''/\1/g
        s/==*\([^=]*\)==*/\1/g
        s/&lt;/</g
        p
}

