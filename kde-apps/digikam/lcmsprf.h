--- trunk/extragear/graphics/digikam/libs/lprof/lcmsprf.h	2007/06/14 07:54:58	675400
+++ trunk/extragear/graphics/digikam/libs/lprof/lcmsprf.h	2007/08/22 06:12:41	703177
@@ -68,6 +68,10 @@
 
     } MATN,FAR* LPMATN;
 
+// See B.K.O #148930: compile with lcms v.1.17
+#if (LCMS_VERSION > 116)
+typedef LCMSBOOL BOOL;
+#endif
 
 LPMATN      cdecl MATNalloc(int Rows, int Cols);
 void        cdecl MATNfree (LPMATN mat);
