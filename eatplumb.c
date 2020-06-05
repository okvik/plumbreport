#include <u.h>
#include <libc.h>
#include <plumb.h>

void
usage(void)
{
	fprint(2, "usage: %s port\n", argv0);
	exits("usage");
}

void
main(int argc, char *argv[])
{
	int fd;
	char *port;
	Plumbmsg *m;

	ARGBEGIN{
	default: usage();
	}ARGEND;
	if(argc != 1)
		usage();
	port = argv[0];
	
	if((fd = plumbopen(port, OREAD)) < 0)
		sysfatal("plumbopen: %r");
	for(;;){
		if((m = plumbrecv(fd)) == nil)
			sysfatal("plumbrecv: %r");
		print("%s %s\n", port, m->data);
		plumbfree(m);
	}
}
