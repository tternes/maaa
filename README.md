# maaa: memory allocator and abuser

maaa is a trivial memory allocation utility for testing thresholds and system performance under memory-constrained conditions.

##Usage

	$ ./maaa 
	Usage: maaa <MB>


## Example
	./maaa 3
	Allocating 3 MB...
	Starting write cycle, press ctrl-c to stop
	Pass 0  MB block 2 done
	Pass 1  MB block 2 done
	Pass 2  MB block 2 done
	Pass 3  MB block 2 done
	[..]
	^C