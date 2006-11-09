--- Makefile.orig	2006-11-09 09:59:55.000000000 +0100
+++ Makefile	2006-11-09 10:13:03.000000000 +0100
@@ -45,7 +45,7 @@ test:
 # build and install everything into local dist directory
 .PHONY: dist
 dist: DESTDIR=$(DISTDIR)/install
-dist: dist-xen dist-kernels dist-tools dist-docs
+dist: dist-xen dist-kbuild dist-tools dist-docs
 	$(INSTALL_DIR) $(DISTDIR)/check
 	$(INSTALL_DATA) ./COPYING $(DISTDIR)
 	$(INSTALL_DATA) ./README $(DISTDIR)
@@ -78,6 +78,10 @@ install-tools:
 install-kernels:
 	for i in $(XKERNELS) ; do $(MAKE) $$i-install || exit 1; done
 
+.PHONY: patchkrn
+patchkrn:
+	for i in $(KERNELS) ; do $(MAKE) -f buildconfigs/mk.$$i xenify ; done
+
 .PHONY: install-docs
 install-docs:
 	sh ./docs/check_pkgs && $(MAKE) -C docs install || true
@@ -88,7 +92,7 @@ dev-docs:
 
 # Build all the various kernels and modules
 .PHONY: kbuild
-kbuild: kernels
+kbuild: patchkrn kernels
 
 # Delete the kernel build trees entirely
 .PHONY: kdelete
