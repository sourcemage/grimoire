BEGIN{
  i=0
  n=split(user_locales,user_locale)
}

{
  locales[i]=$0
  i++
}

END{
for(x = 0; x <= NR; x++){ 
  for( j=1; j<=n; j++ ){
    if (locales[x] ~ user_locale[j])
      sub(/off$/,"on",locales[x])
  }
  print locales[x]
}
}
