[[ "x${DOCKER_CLIENT}" == "xy" ]]  &&  export DOCKER_CLIENTONLY=1

export DOCKER_GITCOMMIT  &&
export DOCKER_BUILDTAGS="${OPTS}"  &&

export  CGO_CFLAGS="-I${TRACK_ROOT}/usr/include"  &&
export CGO_LDFLAGS="-L${TRACK_ROOT}/usr/lib"      &&

# Find gccgo, but can't link in the end
#export AUTO_GOPATH=1  &&

# Use go in /opt/go
# Can't find docker libraries which were placed in the wrong location by docker team, but
# referred to by docker package path...
export  GOROOT="${TRACK_ROOT}"/opt/go        &&
export  GOPATH="${SOURCE_DIRECTORY}:${SOURCE_DIRECTORY}/vendor"  &&

./hack/make.sh dynbinary  &&
./man/md2man-all.sh       &&

if list_find "$LDFLAGS" "-s"; then
  strip -v "${SOURCE_DIRECTORY}"/bundles/${VERSION}/dynbinary/docker-${VERSION}
fi
