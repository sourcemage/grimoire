default_build                                                           &&

if [[ $VID_CFG == y ]]; then
  sedit "s/# SDL_VIDEODRIVER=.*/SDL_VIDEODRIVER=$SDL_VID/"              \
                                                  smgl/sdl
fi                                                                      &&

if [[ $AUD_CFG == y ]]; then
  sedit "s/# SDL_AUDIODRIVER=.*/SDL_AUDIODRIVER=$SDL_AUD/"              \
                                                  smgl/sdl
fi                                                                      &&

if [[ $CD_CFG == y ]]  &&
   [[ -n $SDL_CD ]]; then
  sedit "s/# SDL_CDROM=.*/SDL_CDROM=${SDL_CD//\//\\/}/"                 \
                                               smgl/sdl
fi                                                                      &&

if [[ $JOY_CFG == y ]]  &&
   [[ -n $SDL_JOY ]]; then
  sedit                                                                 \
  "s/# SDL_JOYSTICK_DEVICE=.*/SDL_JOYSTICK_DEVICE=${SDL_JOY//\//\\/}/"  \
                                                              smgl/sdl
fi
