# Move this login session into a cgroup of its own.
#
# Processes start out in the root cgroup, which only root may write to, so an
# unprivileged tool that wants a cgroup - a rootless container runtime, or
# anything setting a limit on the session - has nowhere to put one. The
# cgconfig service delegates /sys/fs/cgroup/user.slice/user-<uid>.slice to each
# user; this puts the session in a scope below it, which becomes the root of
# the cgroup namespace of anything the session unshares.
#
# Everything here is best effort: a host without the delegated subtree just
# keeps the old behaviour.

if [ -d /sys/fs/cgroup/user.slice ]; then
	_cg_slice=/sys/fs/cgroup/user.slice/user-$(id -u).slice

	if [ -w "$_cg_slice/cgroup.procs" ]; then
		# Reap the scopes of sessions that have ended. rmdir fails on a
		# cgroup that still holds processes, so live ones are untouched.
		for _cg_old in "$_cg_slice"/session-*.scope; do
			rmdir "$_cg_old" 2>/dev/null
		done

		_cg_scope=$_cg_slice/session-$$.scope

		mkdir -p "$_cg_scope" 2>/dev/null &&
		echo $$ > "$_cg_scope/cgroup.procs" 2>/dev/null

		unset _cg_old _cg_scope
	fi

	unset _cg_slice
fi
