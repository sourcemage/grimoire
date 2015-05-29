[[ "x${DOCKER_CLIENT}" == "xy" ]]  &&  export DOCKER_CLIENTONLY=1

export DOCKER_GITCOMMIT  &&
export DOCKER_BUILDTAGS="${OPTS}"  &&

# Auto-discover Go
export AUTO_GOPATH=1  &&

./hack/make.sh dynbinary
