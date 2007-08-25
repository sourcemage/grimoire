--- branches/1.4/apps/app_voicemail.c	2007/08/24 15:49:37	80749
+++ branches/1.4/apps/app_voicemail.c	2007/08/24 15:51:03	80750
@@ -4421,7 +4421,7 @@
 	mail_fetchstructure (vms->mailstream,vms->msgArray[vms->curmsg],&body);
 	
 	/* We have the body, now we extract the file name of the first attachment. */
-	if (body->nested.part->next && body->nested.part->next->body.parameter->value) {
+	if (body->nested.part && body->nested.part->next && body->nested.part->next->body.parameter->value) {
 		attachedfilefmt = ast_strdupa(body->nested.part->next->body.parameter->value);
 	} else {
 		ast_log(LOG_ERROR, "There is no file attached to this IMAP message.\n");
