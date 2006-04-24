--- Makefile~	2005-03-10 11:52:16.000000000 -0800
+++ Makefile	2005-03-19 12:56:57.836469304 -0800
@@ -38,7 +38,7 @@
 install: install-xen install-tools install-kernels install-docs
 
 # build and install everything into local dist directory
-dist: xen tools kernels docs
+dist: xen tools kbuild docs
 	$(INSTALL_DIR) $(DISTDIR)/check
 	$(INSTALL_DATA) ./COPYING $(DISTDIR)
 	$(INSTALL_DATA) ./README $(DISTDIR)
@@ -54,11 +54,14 @@
 kernels:
 	for i in $(XKERNELS) ; do $(MAKE) $$i-build || exit 1; done
 
+patchkrn:
+	for i in $(KERNELS) ; do $(MAKE) -f buildconfigs/mk.$$i xenify ; done
+
 docs:
 	sh ./docs/check_pkgs && $(MAKE) -C docs install || true
 
 # Build all the various kernels and modules
-kbuild: kernels
+kbuild: patchkrn kernels
 
 # Delete the kernel build trees entirely
 kdelete:
