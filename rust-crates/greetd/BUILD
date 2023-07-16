create_group greeter &&
create_account greeter &&
if `! grep ^video:.*greeter /etc/group > /dev/null`;then
  message "${MESSAGE_COLOR}adding user greeter to video group${NORMAL_COLOR}" &&
  usermod --append --groups video greeter
fi &&

default_build &&
if is_depends_enabled $SPELL scdoc; then
  scdoc < ./man/agreety-1.scd > ./agreety.1
  scdoc < ./man/greetd-1.scd > ./greetd.1
  scdoc < ./man/greetd-5.scd > ./greetd.5
  scdoc < ./man/greetd-ipc-7.scd > ./greetd-ipc.7
fi
