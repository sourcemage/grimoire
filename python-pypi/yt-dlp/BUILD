if [[ "${YT_DLP_BRANCH}" == "scm" ]]; then
  ${MAKE:-make} -j $((${#DISTCC_HOSTS[*]} * JOBS_PER_HOST + MAKE_NJOBS)) \
                   "lazy-extractors" "completions" "${SPELL}"
else
  default_build
fi
