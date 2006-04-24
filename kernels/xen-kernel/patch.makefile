--- Makefile.org	2005-12-26 11:32:13.000000000 +0100
+++ Makefile	2005-12-26 11:33:45.000000000 +0100
@@ -43,7 +43,7 @@ test:
 
 # build and install everything into local dist directory
 dist: DESTDIR=$(DISTDIR)/install
-dist: dist-xen dist-kernels dist-tools dist-docs
+dist: dist-xen dist-kbuild dist-tools dist-docs
 	$(INSTALL_DIR) $(DISTDIR)/check
 	$(INSTALL_DATA) ./COPYING $(DISTDIR)
 	$(INSTALL_DATA) ./README $(DISTDIR)
@@ -68,6 +68,9 @@ install-tools:
 install-kernels:
 	for i in $(XKERNELS) ; do $(MAKE) $$i-install || exit 1; done
 
+patchkrn:
+	for i in $(KERNELS) ; do $(MAKE) -f buildconfigs/mk.$$i xenify ; done
+
 install-docs:
 	sh ./docs/check_pkgs && $(MAKE) -C docs install || true
 
@@ -75,7 +78,7 @@ dev-docs:
 	$(MAKE) -C docs dev-docs
 
 # Build all the various kernels and modules
-kbuild: kernels
+kbuild: patchkrn kernels
 
 # Delete the kernel build trees entirely
 kdelete:
