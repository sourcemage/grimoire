if [[ "${HYPRPAPER_BRANCH}" == "scm" ]]; then
  default_build
else
  ${MAKE:-make} -j $((${#DISTCC_HOSTS[*]} * JOBS_PER_HOST + MAKE_NJOBS)) all
fi
