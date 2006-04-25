(require 'asdf)
;(in-package :asdf)
; might be useful to make this more generic so it can be used by other spells
; this ensures that the system "clx" is compiled in the source tree, not an
; already installed clx
;(defun mysfunc (system)
;  (let ((name (string system)))
;    (format t "sysname: ~a~%" name)
;    (if (string-equal name "clx")
;      (block nil (return "/usr/src/clx_0.7.3/clx.asd"))
;      (sysdef-central-registry-search system))))
;(setf *system-definition-search-functions* '(mysfunc))
;(in-package :common-lisp-user)
(asdf:operate 'asdf:compile-op 'clx)
(quit)
