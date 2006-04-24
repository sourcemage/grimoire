/* Simple OpenOBEX server for Bluez+OpenOBEX */
/* link with libmisc.a from OPENObex-apps and libopenobex from OpenOBEX */
/* venglin@freebsd.lublin.pl */


#include <stdio.h>
#include <stdlib.h>

#include <openobex/obex.h>

#define OBEX_PUSH_HANDLE	10

volatile int finished = 0;
obex_t *handle = NULL;

void obex_event(obex_t *handle, obex_object_t *object, int mode, int event, int obex_cmd, int obex_rsp);

int main(int argc, char **argv)
{
	obex_object_t *object;

	handle = OBEX_Init(OBEX_TRANS_BLUETOOTH, obex_event, 0);

	if (argc == 1)
	{
		BtOBEX_ServerRegister(handle, NULL, OBEX_PUSH_HANDLE);
		printf("Waiting for connection...\n");
		btobex_accept(handle);

		while (!finished)
			OBEX_HandleInput(handle, 1);
	}
}
